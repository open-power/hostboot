/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/eff_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file eff_config.C
/// @brief Determine effective config for mss settings
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

// fapi2
#include <fapi2.H>
#include <vpd_access.H>
#include <utility>

// mss lib
#include <lib/eff_config/eff_config.H>
#include <lib/utils/fake_vpd.H>
#include <lib/mss_vpd_decoder.H>
#include <lib/spd/spd_factory.H>
#include <lib/spd/common/spd_decoder.H>
#include <lib/spd/common/rcw_settings.H>
#include <lib/eff_config/timing.H>
#include <lib/dimm/rank.H>
#include <lib/utils/conversions.H>
#include <lib/utils/find.H>
#include <math.h>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCBIST;

namespace mss
{

enum rc10_encode : uint8_t
{
    DDR4_1866 = 0x01,
    DDR4_2133 = 0x02,
    DDR4_2400 = 0x03,
    DDR4_2666 = 0x04,
};

enum rc13_encode : uint8_t
{
    DIRECT_CS_MODE = 0,
    LRDIMM = 0,
    RDIMM = 1,
};

enum rc3x_encode : uint8_t
{
    MT1860_TO_MT1880 = 0x1F,
    MT2120_TO_MT2140 = 0x2C,
    MT2380_TO_MT2400 = 0x39,
    MT2660_TO_MT2680 = 0x47,
};

/////////////////////////
// Non-member function implementations
/////////////////////////

///
/// @brief IBT helper - maps from VPD definition of IBT to the RCD control word bit fields
/// @param[in] i_ibt the IBT from VPD (e.g., 10, 15, ...)
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

        // 100Ohm
        case 10:
            return 0b00;
            break;

        // 150Ohm
        case 15:
            return 0b01;
            break;

        // 300Ohm
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

/////////////////////////
// Member Method implementation
/////////////////////////

///
/// @brief Determines & sets effective config for DRAM generation from SPD
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_gen(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                       const std::vector<uint8_t>& i_spd_data )
{
    //TODO: RTC 159777: Change eff_config class to use iv's for mcs, port and dimm position
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_gen(l_mcs, &l_mcs_attrs[0][0]) );
    FAPI_TRY( spd::dram_device_type(i_target, i_spd_data, l_decoder_val) );

    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_GEN, l_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;

}// dram_gen

///
/// @brief Determines & sets effective config for DIMM type from SPD
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                        const std::vector<uint8_t>& i_spd_data )
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_dimm_type(l_mcs, &l_mcs_attrs[0][0]) );
    FAPI_TRY( spd::base_module_type(i_target, i_spd_data, l_decoder_val) );

    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_TYPE, l_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;

}// dimm_type

///
/// @brief Determines & sets effective config for eff_dram_mfg_id type from SPD
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_mfg_id(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint16_t l_decoder_val = 0;
    uint16_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_mfg_id(l_mcs, &l_mcs_attrs[0][0]) );
    FAPI_TRY( iv_pDecoder->dram_manufacturer_id_code(i_target, l_decoder_val) );

    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_MFG_ID, l_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;

}// dimm_type

///
/// @brief Determines & sets effective config for dram width
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_width(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( iv_pDecoder->device_width(i_target, l_decoder_val) );
    FAPI_TRY( eff_dram_width(l_mcs, &l_mcs_attrs[0][0]) );

    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_WIDTH, l_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Determines & sets effective config for dram density
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_density(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_decoder_val = 0;
    FAPI_TRY( iv_pDecoder->sdram_density(i_target, l_decoder_val) );

    // Get & update MCS attribute
    {
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
        const auto l_dimm_num = index(i_target);

        uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( eff_dram_density(l_mcs, &l_mcs_attrs[0][0]) );

        l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_DENSITY, l_mcs, l_mcs_attrs) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for number of ranks per dimm
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::ranks_per_dimm(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint8_t l_ranks_per_dimm = 0;
    uint8_t l_attrs_ranks_per_dimm[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_num_ranks_per_dimm(l_mcs, &l_attrs_ranks_per_dimm[0][0]) );
    FAPI_TRY( iv_pDecoder->logical_ranks_per_dimm(i_target, l_ranks_per_dimm) );

    l_attrs_ranks_per_dimm[l_port_num][l_dimm_num] = l_ranks_per_dimm;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_NUM_RANKS_PER_DIMM, l_mcs, l_attrs_ranks_per_dimm) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for stack type
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::primary_stack_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_decoder_val = 0;
    FAPI_TRY( iv_pDecoder->prim_sdram_signal_loading(i_target, l_decoder_val) );

    // Get & update MCS attribute
    {
        const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
        const auto l_dimm_num = index(i_target);

        uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( eff_prim_stack_type(l_mcs, &l_mcs_attrs[0][0]) );

        l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_PRIM_STACK_TYPE, l_mcs, l_mcs_attrs) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for dimm size
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @warn Dependent on the following attributes already set:
/// @warn eff_dram_density, eff_sdram_width, eff_ranks_per_dimm
///
fapi2::ReturnCode eff_config::dimm_size(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Retrieve values needed to calculate dimm size
    uint8_t l_bus_width = 0;
    uint8_t l_sdram_width = 0;
    uint8_t l_sdram_density = 0;
    uint8_t l_logical_rank_per_dimm = 0;

    FAPI_TRY( iv_pDecoder->device_width(i_target, l_sdram_width) );
    FAPI_TRY( iv_pDecoder->prim_bus_width(i_target, l_bus_width) );
    FAPI_TRY( iv_pDecoder->sdram_density(i_target, l_sdram_density) );
    FAPI_TRY( iv_pDecoder->logical_ranks_per_dimm(i_target, l_logical_rank_per_dimm) );

    {
        // Calculate dimm size
        // Formula from SPD Spec
        // Total = SDRAM Capacity 8 * Primary Bus Width SDRAM Width * Logical Ranks per DIMM
        uint32_t l_dimm_size = 0;
        l_dimm_size = (l_sdram_density / 8.0) * (l_bus_width / l_sdram_width) * l_logical_rank_per_dimm;

        // Get & update MCS attribute
        const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
        const auto l_dimm_num = index(i_target);

        uint32_t l_attrs_dimm_size[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( eff_dimm_size(l_mcs, &l_attrs_dimm_size[0][0]) );

        l_attrs_dimm_size[l_port_num][l_dimm_num] = l_dimm_size;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_SIZE, l_mcs, l_attrs_dimm_size) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Hybrid memory type from SPD
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::hybrid_memory_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Get & update MCS attribute
    FAPI_TRY( eff_hybrid_memory_type(l_mcs, &l_mcs_attrs[0][0]) );
    FAPI_TRY(iv_pDecoder->hybrid_media(i_target, l_decoder_val));

    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_HYBRID_MEMORY_TYPE, l_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for refresh interval time (tREFI)
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trefi(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint64_t l_trefi_in_ps = 0;

    // Calculates appropriate tREFI based on fine refresh mode
    switch(iv_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:

            FAPI_TRY( calc_trefi( mss::refresh_rate::REF1X,
                                  iv_temp_refresh_range,
                                  l_trefi_in_ps),
                      "Failed to calculate tREF1 for target %s", mss::c_str(i_target) );
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:

            FAPI_TRY( calc_trefi( mss::refresh_rate::REF2X,
                                  iv_temp_refresh_range,
                                  l_trefi_in_ps),
                      "Failed to calculate tREF2 for target %s", mss::c_str(i_target) );
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:

            FAPI_TRY( calc_trefi( mss::refresh_rate::REF4X,
                                  iv_temp_refresh_range,
                                  l_trefi_in_ps),
                      "Failed to calculate tREF4  for target %s", mss::c_str(i_target) );
            break;

        default:
            // Fine Refresh Mode will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_FINE_REFRESH_MODE().
                        set_FINE_REF_MODE(iv_refresh_mode),
                        "%s Incorrect Fine Refresh Mode received: %d ",
                        mss::c_str(i_target),
                        iv_refresh_mode);
            break;
    }

    {
        // Calculate refresh cycle time in nCK & set attribute
        const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

        std::vector<uint16_t> l_mcs_attrs_trefi(PORTS_PER_MCS, 0);
        uint64_t l_trefi_in_nck  = 0;

        // Retrieve MCS attribute data
        FAPI_TRY( eff_dram_trefi(l_mcs, l_mcs_attrs_trefi.data()) );

        // Calculate nck
        FAPI_TRY(  spd::calc_nck(l_trefi_in_ps, static_cast<uint64_t>(iv_tCK_in_ps), INVERSE_DDR4_CORRECTION_FACTOR,
                                 l_trefi_in_nck),
                   "Error in calculating tREFI for target %s, with value of l_trefi_in_ps: %d", mss::c_str(i_target), l_trefi_in_ps);

        FAPI_INF("tCK (ps): %d, tREFI (ps): %d, tREFI (nck): %d",
                 iv_tCK_in_ps, l_trefi_in_ps, l_trefi_in_nck);

        // Update MCS attribute
        l_mcs_attrs_trefi[l_port_num] = l_trefi_in_nck;

        // casts vector into the type FAPI_ATTR_SET is expecting by deduction
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TREFI,
                                l_mcs,
                                UINT16_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trefi, PORTS_PER_MCS)),
                  "Failed to set tREFI attribute");
    }

fapi_try_exit:
    return fapi2::current_err;

}// refresh_interval

///
/// @brief Determines & sets effective config for refresh cycle time (tRFC)
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trfc(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    int64_t l_trfc_mtb = 0;
    int64_t l_trfc_in_ps = 0;

    // Selects appropriate tRFC based on fine refresh mode
    switch(iv_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:
            FAPI_TRY( iv_pDecoder->min_refresh_recovery_delay_time_1(i_target, l_trfc_mtb),
                      "Failed to decode SPD for tRFC1" );
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:
            FAPI_TRY( iv_pDecoder->min_refresh_recovery_delay_time_2(i_target, l_trfc_mtb),
                      "Failed to decode SPD for tRFC2" );
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:
            FAPI_TRY( iv_pDecoder->min_refresh_recovery_delay_time_4(i_target, l_trfc_mtb),
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
                        mss::c_str(i_target),
                        iv_refresh_mode);
            break;

    }// switch

    // Calculate trfc (in ps)
    {
        constexpr int64_t l_trfc_ftb = 0;
        int64_t l_ftb = 0;
        int64_t l_mtb = 0;

        FAPI_TRY( iv_pDecoder->medium_timebase(i_target, l_mtb) );
        FAPI_TRY( iv_pDecoder->fine_timebase(i_target, l_ftb) );

        FAPI_INF( "medium timebase (ps): %ld, fine timebase (ps): %ld, tRFC (MTB): %ld, tRFC(FTB): %ld",
                  l_mtb, l_ftb, l_trfc_mtb, l_trfc_ftb );

        l_trfc_in_ps = spd::calc_timing_from_timebase(l_trfc_mtb, l_mtb, l_trfc_ftb, l_ftb);
    }

    {
        // Calculate refresh cycle time in nCK & set attribute
        const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

        uint16_t l_trfc_in_nck = 0;
        std::vector<uint16_t> l_mcs_attrs_trfc(PORTS_PER_MCS, 0);

        // Retrieve MCS attribute data
        FAPI_TRY( eff_dram_trfc(l_mcs, l_mcs_attrs_trfc.data()),
                  "Failed to retrieve tRFC attribute" );

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_trfc_in_ps, iv_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_trfc_in_nck),
                  "Error in calculating l_tRFC for target %s, with value of l_trfc_in_ps: %d", mss::c_str(i_target), l_trfc_in_ps);

        FAPI_INF("tCK (ps): %d, tRFC (ps): %d, tRFC (nck): %d",
                 iv_tCK_in_ps, l_trfc_in_ps, l_trfc_in_nck);

        // Update MCS attribute
        l_mcs_attrs_trfc[l_port_num] = l_trfc_in_nck;

        // casts vector into the type FAPI_ATTR_SET is expecting by deduction
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRFC,
                                l_mcs,
                                UINT16_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trfc, PORTS_PER_MCS) ),
                  "Failed to set tRFC attribute" );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for refresh cycle time (different logical ranks - tRFC_DLR)
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trfc_dlr(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

    uint8_t l_density = 0;
    uint64_t l_tCK_in_ps = 0;
    uint64_t l_trfc_dlr_in_ps = 0;
    uint8_t l_trfc_dlr_in_nck = 0;
    std::vector<uint8_t> l_mcs_attrs_trfc_dlr(PORTS_PER_MCS, 0);

    // Retrieve map params
    FAPI_TRY( iv_pDecoder->sdram_density(i_target, l_density), "Failed to get sdram density");
    FAPI_TRY ( mss::mrw_fine_refresh_mode(iv_refresh_mode), "Failed to get MRW attribute for fine refresh mode" );

    FAPI_INF("Retrieved SDRAM density: %d, fine refresh mode: %d",
             l_density, iv_refresh_mode);

    // Calculate refresh cycle time in ps
    FAPI_TRY( calc_trfc_dlr(iv_refresh_mode, l_density, l_trfc_dlr_in_ps), "Failed calc_trfc_dlr()" );

    // Calculate clock period (tCK) from selected freq from mss_freq
    FAPI_TRY( clock_period(i_target, l_tCK_in_ps), "Failed to calculate clock period (tCK)");

    // Calculate refresh cycle time in nck
    FAPI_TRY( spd::calc_nck(l_trfc_dlr_in_ps, l_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_trfc_dlr_in_nck));

    FAPI_INF("tCK (ps): %d, tRFC_DLR (ps): %d, tRFC_DLR (nck): %d",
             l_tCK_in_ps, l_trfc_dlr_in_ps, l_trfc_dlr_in_nck);

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dram_trfc_dlr(l_mcs, l_mcs_attrs_trfc_dlr.data()), "Failed to retrieve tRFC_DLR attribute" );

    // Update MCS attribute
    l_mcs_attrs_trfc_dlr[l_port_num] = l_trfc_dlr_in_nck;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRFC_DLR,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trfc_dlr, PORTS_PER_MCS) ),
              "Failed to set tRFC_DLR attribute" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for dimm rcd mirror mode
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::rcd_mirror_mode(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_mirror_mode = 0;
    uint8_t l_attrs_mirror_mode[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dimm_rcd_mirror_mode(l_mcs, &l_attrs_mirror_mode[0][0]) );

    // Update MCS attribute
    FAPI_TRY( iv_pDecoder->iv_module_decoder->register_to_dram_addr_mapping(l_mirror_mode) );
    l_attrs_mirror_mode[l_port_num][l_dimm_num] = l_mirror_mode;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_RCD_MIRROR_MODE, l_mcs, l_attrs_mirror_mode) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for dram bank bits
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_bank_bits(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint8_t l_bank_bits = 0;
    uint8_t l_attrs_bank_bits[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_bank_bits(l_mcs, &l_attrs_bank_bits[0][0]) );
    FAPI_TRY( iv_pDecoder->bank_bits(i_target, l_bank_bits) );

    l_attrs_bank_bits[l_port_num][l_dimm_num] = l_bank_bits;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_BANK_BITS, l_mcs, l_attrs_bank_bits) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for dram row bits
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_row_bits(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint8_t l_row_bits = 0;
    uint8_t l_attrs_row_bits[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_row_bits(l_mcs, &l_attrs_row_bits[0][0]) );
    FAPI_TRY( iv_pDecoder->row_address_bits(i_target, l_row_bits) );

    l_attrs_row_bits[l_port_num][l_dimm_num] = l_row_bits;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_ROW_BITS, l_mcs, l_attrs_row_bits) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tDQS
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Sets TDQS to off for x4, sets to on for x8
///
fapi2::ReturnCode eff_config::dram_dqs_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_attrs_dqs_time[PORTS_PER_MCS] = {};
    uint8_t l_dram_width = 0;

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    //Get the DRAM width
    FAPI_TRY( iv_pDecoder->device_width(i_target, l_dram_width) );

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_tdqs(l_mcs, &l_attrs_dqs_time[0]) );
    FAPI_INF("SDRAM width: %d for target %s", l_dram_width, mss::c_str(i_target));

    //Only possible dram width are x4, x8. If x8, tdqs is available, else not available
    l_attrs_dqs_time[l_port_num] = (l_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ?
                                   fapi2::ENUM_ATTR_EFF_DRAM_TDQS_ENABLE : fapi2::ENUM_ATTR_EFF_DRAM_TDQS_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TDQS, l_mcs, l_attrs_dqs_time) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tCCD_L
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_tccd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    int64_t l_tccd_in_ps = 0;

    // Get the tCCD_L timing values
    // tCCD_L is speed bin independent and is
    // the same for all bins within a speed grade.
    // It is safe to read this from SPD because the correct nck
    // value will be calulated based on our dimm speed.

    // TODO: RTC 163150 Clean up eff_config timing boilerplate
    {
        int64_t l_ftb = 0;
        int64_t l_mtb = 0;
        int64_t l_tccd_mtb = 0;
        int64_t l_tccd_ftb = 0;

        FAPI_TRY( iv_pDecoder->medium_timebase(i_target, l_mtb),
                  "Failed medium_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->fine_timebase(i_target, l_ftb),
                  "Failed fine_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->min_tccd_l(i_target, l_tccd_mtb),
                  "Failed min_tccd_l() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->fine_offset_min_tccd_l(i_target, l_tccd_ftb),
                  "Failed fine_offset_min_tccd_l() for %s", mss::c_str(i_target) );

        FAPI_INF("medium timebase (ps): %ld, fine timebase (ps): %ld, tCCD_L (MTB): %ld, tCCD_L(FTB): %ld",
                 l_mtb, l_ftb, l_tccd_mtb, l_tccd_ftb );

        l_tccd_in_ps = spd::calc_timing_from_timebase(l_tccd_mtb, l_mtb, l_tccd_ftb, l_ftb);
    }

    {
        // Calculate refresh cycle time in nCK & set attribute
        const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

        uint8_t l_tccd_in_nck = 0;
        std::vector<uint8_t> l_mcs_attrs_tccd(PORTS_PER_MCS, 0);

        // Retrieve MCS attribute data
        FAPI_TRY( eff_dram_tccd_l(l_mcs, l_mcs_attrs_tccd.data()),
                  "Failed to retrieve tCCD attribute" );

        // Calculate nck
        FAPI_TRY ( spd::calc_nck(l_tccd_in_ps, iv_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_tccd_in_nck),
                   "Error in calculating tccd  for target %s, with value of l_tccd_in_ps: %d", mss::c_str(i_target), l_tccd_in_ps);

        FAPI_INF("tCK (ps): %d, tCCD_L (ps): %d, tCCD_L (nck): %d",
                 iv_tCK_in_ps, l_tccd_in_ps, l_tccd_in_nck);

        // Update MCS attribute
        l_mcs_attrs_tccd[l_port_num] = l_tccd_in_nck;

        // casts vector into the type FAPI_ATTR_SET is expecting by deduction
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TCCD_L,
                                l_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_mcs_attrs_tccd, PORTS_PER_MCS) ),
                  "Failed to set tCCD_L attribute" );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC00
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc00(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc00[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc00(l_mcs, &l_attrs_dimm_rc00[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc00[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc00;

    FAPI_INF("%s: RC00 settting: %d", mss::c_str(i_target), l_attrs_dimm_rc00[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC00, l_mcs, l_attrs_dimm_rc00) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC01
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc01(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc01[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc01(l_mcs, &l_attrs_dimm_rc01[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc01[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc01;

    FAPI_INF("%s: RC01 settting: %d", mss::c_str(i_target), l_attrs_dimm_rc01[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC01, l_mcs, l_attrs_dimm_rc01) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC02
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc02(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc02[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc02(l_mcs, &l_attrs_dimm_rc02[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc02[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc02;

    FAPI_INF("%s: RC02 settting: %d", mss::c_str(i_target), l_attrs_dimm_rc02[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC02, l_mcs, l_attrs_dimm_rc02) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC03
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc03(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    fapi2::buffer<uint8_t> l_buffer;

    uint8_t l_attrs_dimm_rc03[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_cs_output_drive = 0;
    uint8_t l_ca_output_drive = 0;

    FAPI_TRY( iv_pDecoder->iv_module_decoder->cs_signal_output_driver(l_cs_output_drive) );
    FAPI_TRY( iv_pDecoder->iv_module_decoder->ca_signal_output_driver(l_ca_output_drive) );

    FAPI_INF( "%s: Retrieved register output drive, for CA: %d, CS: %d",
              mss::c_str(i_target), l_ca_output_drive, l_cs_output_drive );

    // Lets construct encoding byte for RCD setting
    {
        // Buffer insert constants for CS and CA output drive
        constexpr size_t CS_START = 4;
        constexpr size_t CA_START = 6;
        constexpr size_t LEN = 2;

        l_buffer.insertFromRight<CA_START, LEN>(l_ca_output_drive)
        .insertFromRight<CS_START, LEN>(l_cs_output_drive);
    }
    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc03(l_mcs, &l_attrs_dimm_rc03[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc03[l_port_num][l_dimm_num] = l_buffer;

    FAPI_INF("%s: RC03 settting: %d", mss::c_str(i_target), l_attrs_dimm_rc03[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC03, l_mcs, l_attrs_dimm_rc03) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC04
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc04(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    uint8_t l_attrs_dimm_rc04[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_odt_output_drive = 0;
    uint8_t l_cke_output_drive = 0;

    fapi2::buffer<uint8_t> l_buffer;

    FAPI_TRY( iv_pDecoder->iv_module_decoder->odt_signal_output_driver(l_odt_output_drive) );
    FAPI_TRY( iv_pDecoder->iv_module_decoder->cke_signal_output_driver(l_cke_output_drive) );

    FAPI_INF( "%s: Retrieved signal driver output, for CKE: %d, ODT: %d",
              mss::c_str(i_target), l_cke_output_drive, l_odt_output_drive );

    // Lets construct encoding byte for RCD setting
    {
        // Buffer insert constants for ODT and CKE output drive
        constexpr size_t CKE_START = 6;
        constexpr size_t ODT_START = 4;
        constexpr size_t LEN = 2;

        l_buffer.insertFromRight<CKE_START, LEN>(l_cke_output_drive)
        .insertFromRight<ODT_START, LEN>(l_odt_output_drive);
    }

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc04(l_mcs, &l_attrs_dimm_rc04[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc04[l_port_num][l_dimm_num] = l_buffer;

    FAPI_INF("%s: RC04 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc04[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC04, l_mcs, l_attrs_dimm_rc04) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC05
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc05(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    uint8_t l_attrs_dimm_rc05[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_a_side_output_drive = 0;
    uint8_t l_b_side_output_drive = 0;

    fapi2::buffer<uint8_t> l_buffer;

    FAPI_TRY( iv_pDecoder->iv_module_decoder->a_side_clk_output_driver(l_a_side_output_drive) );
    FAPI_TRY( iv_pDecoder->iv_module_decoder->b_side_clk_output_driver(l_b_side_output_drive) );

    FAPI_INF( "%s: Retrieved register output drive for clock, b-side (Y0,Y2): %d, a-side (Y1,Y3): %d",
              mss::c_str(i_target), l_b_side_output_drive, l_a_side_output_drive );

    {
        // Buffer insert constants for ODT and CKE output drive
        constexpr size_t B_START = 6;
        constexpr size_t A_START = 4;
        constexpr size_t LEN = 2;

        // Lets construct encoding byte for RCD setting
        l_buffer.insertFromRight<B_START, LEN>(l_b_side_output_drive)
        .insertFromRight<A_START, LEN>(l_a_side_output_drive);
    }

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc05(l_mcs, &l_attrs_dimm_rc05[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc05[l_port_num][l_dimm_num] = l_buffer;

    FAPI_INF( "%s: RC05 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc05[l_port_num][l_dimm_num] )
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC05, l_mcs, l_attrs_dimm_rc05) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC06_07
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc06_07(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc06_07[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc06_07(l_mcs, &l_attrs_dimm_rc06_07[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc06_07[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc06_07;

    FAPI_INF( "%s: RC06_07 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc06_07[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC06_07, l_mcs, l_attrs_dimm_rc06_07) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC08
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc08(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc08[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc08(l_mcs, &l_attrs_dimm_rc08[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc08[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc08;

    FAPI_INF( "%s: RC08 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc08[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC08, l_mcs, l_attrs_dimm_rc08) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC09
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc09(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // TODO - RTC 160118: Clean up eff_config boiler plate that can moved into helper functions

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc09[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc09(l_mcs, &l_attrs_dimm_rc09[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc09[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc09;

    FAPI_INF( "%s: RC09 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc09[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC09, l_mcs, l_attrs_dimm_rc09) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC10
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc10(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    uint64_t l_freq = 0;

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc10[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc10(l_mcs, &l_attrs_dimm_rc10[0][0]) );

    // Update MCS attribute
    FAPI_TRY( mss::freq( mss::find_target<TARGET_TYPE_MCBIST>(i_target), l_freq ) );

    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            l_attrs_dimm_rc10[l_port_num][l_dimm_num] = rc10_encode::DDR4_1866;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            l_attrs_dimm_rc10[l_port_num][l_dimm_num] = rc10_encode::DDR4_2133;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            l_attrs_dimm_rc10[l_port_num][l_dimm_num] = rc10_encode::DDR4_2400;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            l_attrs_dimm_rc10[l_port_num][l_dimm_num] = rc10_encode::DDR4_2666;
            break;

        default:
            FAPI_ERR("Invalid frequency for rc10 encoding received: %d", l_freq);
            return fapi2::FAPI2_RC_FALSE;
            break;
    }

    FAPI_INF( "%s: RC10 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc10[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC10, l_mcs, l_attrs_dimm_rc10) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC11
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc11(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc11[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc11(l_mcs, &l_attrs_dimm_rc11[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc11[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc0b;

    FAPI_INF( "%s: RC11 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc11[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC11, l_mcs, l_attrs_dimm_rc11) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC12
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc12(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc12[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc12(l_mcs, &l_attrs_dimm_rc12[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc12[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc0c;

    FAPI_INF( "%s: R12 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc12[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC12, l_mcs, l_attrs_dimm_rc12) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC13
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc13(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    uint8_t l_attrs_dimm_rc13[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    fapi2::buffer<uint8_t> l_buffer;

    // TODO - RTC 160116: Fix RC0D chip select setting for LRDIMMs
    constexpr uint8_t l_cs_mode = rc13_encode::DIRECT_CS_MODE;
    uint8_t l_mirror_mode = 0;
    uint8_t l_dimm_type = 0;
    uint8_t l_module_type = 0;

    FAPI_TRY( spd::base_module_type(i_target, iv_pDecoder->iv_spd_data, l_module_type) );

    l_dimm_type = (l_module_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) ?
                  rc13_encode::RDIMM :
                  rc13_encode::LRDIMM;

    FAPI_TRY( iv_pDecoder->iv_module_decoder->register_to_dram_addr_mapping(l_mirror_mode) );

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

        l_buffer.insertFromRight<CS_START, CS_LEN>(l_cs_mode)
        .insertFromRight<DIMM_TYPE_START, DIMM_TYPE_LEN>(l_dimm_type)
        .insertFromRight<MIRROR_START, MIRROR_LEN>(l_mirror_mode);
    }

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc13(l_mcs, &l_attrs_dimm_rc13[0][0]) );

    // Update MCS attribute
    FAPI_TRY( spd::base_module_type(i_target, iv_pDecoder->iv_spd_data, l_dimm_type) );
    l_attrs_dimm_rc13[l_port_num][l_dimm_num] = l_buffer;

    FAPI_INF( "%s: RC13 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc13[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC13, l_mcs, l_attrs_dimm_rc13) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC14
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc14(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc14[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc14(l_mcs, &l_attrs_dimm_rc14[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc14[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc0e;

    FAPI_INF( "%s: RC14 setting: 0x%0x", mss::c_str(i_target), l_attrs_dimm_rc14[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC14, l_mcs, l_attrs_dimm_rc14) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC15
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc15(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc15[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc15(l_mcs, &l_attrs_dimm_rc15[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc15[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc0f;

    FAPI_INF( "%s: RC15 setting: %d", mss::c_str(i_target), l_attrs_dimm_rc15[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC15, l_mcs, l_attrs_dimm_rc15) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_1x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc1x(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_1x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_1x(l_mcs, &l_attrs_dimm_rc_1x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_1x[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc1x;

    FAPI_INF( "%s: RC1X setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_1x[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_1x, l_mcs, l_attrs_dimm_rc_1x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_2x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc2x(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_2x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_2x(l_mcs, &l_attrs_dimm_rc_2x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_2x[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc2x;

    FAPI_INF( "%s: RC2X setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_2x[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_2x, l_mcs, l_attrs_dimm_rc_2x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_3x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc3x(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    uint64_t l_freq = 0;
    uint8_t l_attrs_dimm_rc_3x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dimm_ddr4_rc_3x(l_mcs, &l_attrs_dimm_rc_3x[0][0]) );

    // Update MCS attribute
    FAPI_TRY( freq(find_target<TARGET_TYPE_MCBIST>(l_mcs), l_freq) );

    switch(l_freq)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            l_attrs_dimm_rc_3x[l_port_num][l_dimm_num] = rc3x_encode::MT1860_TO_MT1880;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            l_attrs_dimm_rc_3x[l_port_num][l_dimm_num] = rc3x_encode::MT2120_TO_MT2140;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            l_attrs_dimm_rc_3x[l_port_num][l_dimm_num] = rc3x_encode::MT2380_TO_MT2400;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            l_attrs_dimm_rc_3x[l_port_num][l_dimm_num] = rc3x_encode::MT2660_TO_MT2680;
            break;

        default:
            FAPI_ERR("Invalid frequency for rc_3x encoding received: %d", l_freq);
            return fapi2::FAPI2_RC_FALSE;
            break;
    }

    FAPI_INF( "%s: RC3X setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_3x[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_3x, l_mcs, l_attrs_dimm_rc_3x) );


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_4x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc4x(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_4x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_4x(l_mcs, &l_attrs_dimm_rc_4x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_4x[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc4x;

    FAPI_INF( "%s: RC4X setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_4x[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_4x, l_mcs, l_attrs_dimm_rc_4x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_5x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc5x(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_5x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_5x(l_mcs, &l_attrs_dimm_rc_5x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_5x[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc5x;

    FAPI_INF( "%s: RC5X setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_5x[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_5x, l_mcs, l_attrs_dimm_rc_5x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_6x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc6x(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_6x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_6x(l_mcs, &l_attrs_dimm_rc_6x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_6x[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc6x;

    FAPI_INF( "%s: RC6X setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_6x[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_6x, l_mcs, l_attrs_dimm_rc_6x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_7x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc7x(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_attrs_dimm_rc_7x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

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
    FAPI_TRY( mss::vpd_mt_dimm_rcd_ibt_ca(i_target, l_ibt_ca) );
    FAPI_TRY( mss::vpd_mt_dimm_rcd_ibt_cke(i_target, l_ibt_cke) );
    FAPI_TRY( mss::vpd_mt_dimm_rcd_ibt_cs(i_target, l_ibt_cs) );
    FAPI_TRY( mss::vpd_mt_dimm_rcd_ibt_odt(i_target, l_ibt_odt) );

    l_rcd7x.insertFromRight<CA_START, LEN>( ibt_helper(l_ibt_ca) );
    l_rcd7x.insertFromRight<CKE_START, LEN>( ibt_helper(l_ibt_cke) );
    l_rcd7x.insertFromRight<CS_START, LEN>( ibt_helper(l_ibt_cs) );
    l_rcd7x.insertFromRight<ODT_START, LEN>( ibt_helper(l_ibt_odt) );

    // Now write RCD7x out to the effective attribute
    FAPI_TRY( eff_dimm_ddr4_rc_7x(l_mcs, &l_attrs_dimm_rc_7x[0][0]) );
    l_attrs_dimm_rc_7x[l_port_num][l_dimm_num] = l_rcd7x;

    FAPI_INF( "%s: RC7X setting is 0x%x", mss::c_str(i_target), l_attrs_dimm_rc_7x[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_7x, l_mcs, l_attrs_dimm_rc_7x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_8x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc8x(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_8x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_8x(l_mcs, &l_attrs_dimm_rc_8x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_8x[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc8x;

    FAPI_INF( "%s: RC8X setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_8x[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_8x, l_mcs, l_attrs_dimm_rc_8x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_9x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc9x(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_9x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_9x(l_mcs, &l_attrs_dimm_rc_9x[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_9x[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rc9x;

    FAPI_INF( "%s: RC9X setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_9x[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_9x, l_mcs, l_attrs_dimm_rc_9x) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_AX
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rcax(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_ax[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_ax(l_mcs, &l_attrs_dimm_rc_ax[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_ax[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rcax;

    FAPI_INF( "%s: RCAX setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_ax[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_Ax, l_mcs, l_attrs_dimm_rc_ax) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC_BX
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rcbx(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Retrieve MCS attribute data
    uint8_t l_attrs_dimm_rc_bx[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_ddr4_rc_bx(l_mcs, &l_attrs_dimm_rc_bx[0][0]) );

    // Update MCS attribute
    l_attrs_dimm_rc_bx[l_port_num][l_dimm_num] = iv_pDecoder->iv_raw_card.iv_rcbx;

    FAPI_INF( "%s: RCBX setting: %d", mss::c_str(i_target), l_attrs_dimm_rc_bx[l_port_num][l_dimm_num] );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_Bx, l_mcs, l_attrs_dimm_rc_bx) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tWR
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_twr(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));
    int64_t l_twr_in_ps = 0;

    // Get the tWR timing values
    // tWR is speed bin independent and is
    // the same for all bins within a speed grade.
    // It is safe to read this from SPD because the correct nck
    // value will be calulated based on our dimm speed.
    {
        constexpr int64_t l_twr_ftb = 0;
        int64_t l_twr_mtb = 0;
        int64_t l_ftb = 0;
        int64_t l_mtb = 0;

        FAPI_TRY( iv_pDecoder->medium_timebase(i_target, l_mtb),
                  "Failed medium_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->fine_timebase(i_target, l_ftb),
                  "Failed fine_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->min_write_recovery_time(i_target, l_twr_mtb),
                  "Failed min_write_recovery_time() for %s", mss::c_str(i_target) );

        FAPI_INF("medium timebase (ps): %ld, fine timebase (ps): %ld, tWR (MTB): %ld, tWR(FTB): %ld",
                 l_mtb, l_ftb, l_twr_mtb, l_twr_ftb);

        // Calculate twr (in ps)
        l_twr_in_ps = spd::calc_timing_from_timebase(l_twr_mtb, l_mtb, l_twr_ftb, l_ftb);
    }

    {
        std::vector<uint8_t> l_attrs_dram_twr(PORTS_PER_MCS, 0);
        uint8_t l_twr_in_nck = 0;

        // Calculate tNCK
        FAPI_TRY( spd::calc_nck(l_twr_in_ps, iv_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR,  l_twr_in_nck),
                  "Error in calculating l_twr_in_nck for target %s, with value of l_twr_in_ps: %d", mss::c_str(i_target), l_twr_in_ps);

        FAPI_INF( "tCK (ps): %d, tWR (ps): %d, tWR (nck): %d  for target: %s",
                  iv_tCK_in_ps, l_twr_in_ps, l_twr_in_nck, mss::c_str(i_target) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_twr(l_mcs, l_attrs_dram_twr.data()) );

        l_attrs_dram_twr[l_port_num] = l_twr_in_nck;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWR,
                                l_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_twr, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TWR");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for RBT
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::read_burst_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_attrs_rbt[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_rbt(l_mcs, &l_attrs_rbt[0][0]) );

    l_attrs_rbt[l_port_num][l_dimm_num] = fapi2::ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RBT, l_mcs, l_attrs_rbt),
              "Failed setting attribute for RTB");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for TM
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note dram testing mode
/// @note always disabled
///
fapi2::ReturnCode eff_config::dram_tm(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_attrs_tm[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_tm(l_mcs, &l_attrs_tm[0][0]) );

    l_attrs_tm[l_port_num][l_dimm_num] = fapi2::ENUM_ATTR_EFF_DRAM_TM_NORMAL;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TM, l_mcs, l_attrs_tm),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for cwl
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Sets CAS Write Latency, depending on frequency and ATTR_MSS_MT_PREAMBLE
///
fapi2::ReturnCode eff_config::dram_cwl(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{

    // Taken from DDR4 JEDEC spec 1716.78C
    // Proposed DDR4 Full spec update(79-4A)
    // Page 26, Table 7
    static std::pair<uint64_t, uint8_t> CWL_TABLE_1 [6] =
    {
        {1600, 9},
        {1866, 10},
        {2133, 11},
        {2400, 12},
        {2666, 14},
        {3200, 16},
    };
    static std::pair<uint64_t, uint8_t> CWL_TABLE_2 [3] =
    {
        {2400, 14},
        {2666, 16},
        {3200, 18},
    };

    std::vector<uint8_t> l_attrs_cwl(PORTS_PER_MCS, 0);
    uint8_t l_cwl = 0;
    uint64_t l_freq;
    uint8_t l_preamble = 0;

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);
    const auto l_mcbist = find_target <TARGET_TYPE_MCBIST>(i_target);
    // Current index
    const auto l_port_num = index(l_mca);


    FAPI_TRY (vpd_mt_preamble (l_mca, l_preamble) );

    //get the first nibble as according to vpd. 4-7 is read, 0-3 for write
    l_preamble = l_preamble & 0x0F;

    FAPI_ASSERT( ((l_preamble == 0) || (l_preamble == 1)),
                 fapi2::MSS_INVALID_VPD_MT_PREAMBLE()
                 .set_VALUE(l_preamble)
                 .set_DIMM_TARGET(i_target),
                 "Target %s VPD_MT_PREAMBLE is invalid (not 1 or 0), value is %d",
                 mss::c_str(i_target),
                 l_preamble );

    FAPI_TRY( mss::freq(l_mcbist, l_freq) );

    // Using an if branch because a ternary conditional wasn't working with params for find_value_from_key
    if (l_preamble == 0)
    {
        FAPI_TRY( mss::find_value_from_key( CWL_TABLE_1,
                                            l_freq, l_cwl),
                  "Failed finding CAS Write Latency (cwl), freq: %d, preamble %d",
                  l_freq,
                  l_preamble);
    }
    else
    {
        FAPI_TRY( mss::find_value_from_key( CWL_TABLE_2,
                                            l_freq, l_cwl),
                  "Failed finding CAS Write Latency (cwl), freq: %d, preamble %d",
                  l_freq,
                  l_preamble);

    }

    FAPI_TRY( eff_dram_cwl(l_mcs, l_attrs_cwl.data()) );
    l_attrs_cwl[l_port_num] = l_cwl;

    FAPI_INF("Calculated CAS Write Latency is %d", l_cwl);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_CWL,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_cwl, PORTS_PER_MCS)),
              "Failed setting attribute for cwl");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for lpasr
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note from JEDEC DDR4 DRAM MR2 page 26
/// @note All DDR4 supports auto refresh, setting to default
///
fapi2::ReturnCode eff_config::dram_lpasr(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_lpasr(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_lpasr(l_mcs, l_attrs_lpasr.data()) );

    l_attrs_lpasr[l_port_num] =  fapi2::ENUM_ATTR_EFF_DRAM_LPASR_MANUAL_EXTENDED;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_LPASR,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_lpasr, PORTS_PER_MCS)),
              "Failed setting attribute for LPASR");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for additive latency
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::additive_latency(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_dram_al(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_al(l_mcs, l_attrs_dram_al.data()) );

    l_attrs_dram_al[l_port_num] = fapi2::ENUM_ATTR_EFF_DRAM_AL_DISABLE;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_AL,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_al, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_AL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DLL Reset
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dll_reset(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_attrs_dll_reset[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_dll_reset(l_mcs, &l_attrs_dll_reset[0][0]) );

    // Default is to reset DLLs during IPL.
    l_attrs_dll_reset[l_port_num][l_dimm_num] = fapi2::ENUM_ATTR_EFF_DRAM_DLL_RESET_YES;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_DLL_RESET, l_mcs, l_attrs_dll_reset),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DLL Enable
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dll_enable(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_attrs_dll_enable[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_dll_enable(l_mcs, &l_attrs_dll_enable[0][0]) );

    // Enable DLLs by default.
    l_attrs_dll_enable[l_port_num][l_dimm_num] = fapi2::ENUM_ATTR_EFF_DRAM_DLL_ENABLE_YES;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_DLL_ENABLE, l_mcs, l_attrs_dll_enable),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Write Level Enable
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::write_level_enable(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_wr_lvl_enable(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_wr_lvl_enable(l_mcs, l_attrs_wr_lvl_enable.data()) );

    l_attrs_wr_lvl_enable[l_port_num] = fapi2::ENUM_ATTR_EFF_DRAM_WR_LVL_ENABLE_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_WR_LVL_ENABLE,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_wr_lvl_enable, PORTS_PER_MCS)),
              "Failed setting attribute for WR_LVL_ENABLE");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Output Buffer
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::output_buffer(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_output_buffer(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_output_buffer(l_mcs, l_attrs_output_buffer.data()) );

    l_attrs_output_buffer[l_port_num] = fapi2::ENUM_ATTR_EFF_DRAM_OUTPUT_BUFFER_ENABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_OUTPUT_BUFFER,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_output_buffer, PORTS_PER_MCS)),
              "Failed setting attribute for OUTPUT_BUFFER");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Vref DQ Train Value
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::vref_dq_train_value(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_attrs_vref_dq_train_val[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    //value to set.
    fapi2::buffer<uint8_t> l_vpd_value;
    fapi2::buffer<uint8_t> l_train_value;
    constexpr uint64_t VPD_TRAIN_VALUE_START = 2;
    constexpr uint64_t VPD_TRAIN_VALUE_LEN   = 6;
    //Taken from DDR4 (this attribute is DDR4 only) spec MRS6 section VrefDQ training: values table
    constexpr uint8_t JEDEC_MAX_TRAIN_VALUE   = 0b00110010;

    FAPI_TRY(mss::vpd_mt_vref_dram_wr(i_target, l_vpd_value));
    l_vpd_value.extractToRight<VPD_TRAIN_VALUE_START, VPD_TRAIN_VALUE_LEN>(l_train_value);

    FAPI_ASSERT(l_train_value <= JEDEC_MAX_TRAIN_VALUE,
                fapi2::MSS_INVALID_VPD_VREF_DRAM_WR_RANGE()
                .set_MAX(JEDEC_MAX_TRAIN_VALUE)
                .set_VALUE(l_train_value)
                .set_DIMM_TARGET(i_target),
                "%s VPD DRAM VREF value out of range max 0x%02x value 0x%02x", mss::c_str(i_target),
                JEDEC_MAX_TRAIN_VALUE, l_train_value );

    // Attribute to set num dimm ranks is a pre-requisite
    FAPI_TRY( eff_vref_dq_train_value(l_mcs, &l_attrs_vref_dq_train_val[0][0][0]) );
    FAPI_TRY( mss::rank::ranks(i_target, l_ranks) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_vref_dq_train_val[l_port_num][l_dimm_num][index(l_rank)] = l_train_value;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_VREF_DQ_TRAIN_VALUE, l_mcs, l_attrs_vref_dq_train_val),
              "Failed setting attribute for ATTR_EFF_VREF_DQ_TRAIN_VALUE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Vref DQ Train Enable
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::vref_dq_train_enable(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    //Default mode for train enable should be normal operation mode - 0x00
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_attrs_vref_dq_train_enable[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    // Attribute to set num dimm ranks is a pre-requisite
    FAPI_TRY( eff_vref_dq_train_enable(l_mcs, &l_attrs_vref_dq_train_enable[0][0][0]) );
    FAPI_TRY( mss::rank::ranks(i_target, l_ranks) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_vref_dq_train_enable[l_port_num][l_dimm_num][index(l_rank)] = 0x00;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_VREF_DQ_TRAIN_ENABLE, l_mcs, l_attrs_vref_dq_train_enable),
              "Failed setting attribute for ATTR_EFF_VREF_DQ_TRAIN_ENABLE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Vref DQ Train Range
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::vref_dq_train_range(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    // Attribute to set num dimm ranks is a pre-requisite
    uint8_t l_attrs_vref_dq_train_range[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    //value to set.
    fapi2::buffer<uint8_t> l_vpd_value;
    fapi2::buffer<uint8_t> l_train_range;
    constexpr uint64_t VPD_TRAIN_RANGE_START = 1;
    FAPI_TRY(mss::vpd_mt_vref_dram_wr(i_target, l_vpd_value));
    l_train_range = l_vpd_value.getBit<VPD_TRAIN_RANGE_START>();

    //gets the current value of train_range
    FAPI_TRY( eff_vref_dq_train_range(l_mcs, &l_attrs_vref_dq_train_range[0][0][0]) );
    FAPI_TRY( mss::rank::ranks(i_target, l_ranks) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_vref_dq_train_range[l_port_num][l_dimm_num][index(l_rank)] = l_train_range;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_VREF_DQ_TRAIN_RANGE, l_mcs, l_attrs_vref_dq_train_range),
              "Failed setting attribute for ATTR_EFF_VREF_DQ_TRAIN_RANGE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CA Parity Latency
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::ca_parity_latency(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    //TODO: RTC 159554 Update RAS related attributes
    std::vector<uint8_t> l_attrs_ca_parity_latency(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_ca_parity_latency(l_mcs, l_attrs_ca_parity_latency.data()) );
    l_attrs_ca_parity_latency[l_port_num] = fapi2::ENUM_ATTR_EFF_CA_PARITY_LATENCY_DISABLE;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CA_PARITY_LATENCY,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_ca_parity_latency, PORTS_PER_MCS)),
              "Failed setting attribute for CA_PARITY_LATENCY");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CRC Error Clear
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::crc_error_clear(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    //TODO: RTC 159554 Update RAS related attributes
    std::vector<uint8_t> l_attrs_crc_error_clear(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_crc_error_clear(l_mcs, l_attrs_crc_error_clear.data()) );

    l_attrs_crc_error_clear[l_port_num] = fapi2::ENUM_ATTR_EFF_CRC_ERROR_CLEAR_CLEAR;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CRC_ERROR_CLEAR,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_crc_error_clear, PORTS_PER_MCS)),
              "Failed setting attribute for CRC_ERROR_CLEAR");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CA Parity Error Status
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::ca_parity_error_status(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    //TODO: RTC 159554 Update RAS related attributes
    std::vector<uint8_t> l_attrs_ca_parity_error_status(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_ca_parity_error_status(l_mcs, l_attrs_ca_parity_error_status.data()) );

    l_attrs_ca_parity_error_status[l_port_num] = fapi2::ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_CLEAR;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CA_PARITY_ERROR_STATUS,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_ca_parity_error_status, PORTS_PER_MCS)),
              "Failed setting attribute for CA_PARITY_ERROR_STATUS");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CA Parity
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::ca_parity(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    //TODO: RTC 159554 Update RAS related attributes
    std::vector<uint8_t> l_attrs_ca_parity(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_ca_parity(l_mcs, l_attrs_ca_parity.data()) );

    l_attrs_ca_parity[l_port_num] = fapi2::ENUM_ATTR_EFF_CA_PARITY_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CA_PARITY,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_ca_parity, PORTS_PER_MCS)),
              "Failed setting attribute for CA_PARITY");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for ODT Input Buffer
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::odt_input_buffer(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    // keeping this value as 0x01, given that we know that that works in sim
    constexpr uint8_t SIM_VALUE = 0x01;
    std::vector<uint8_t> l_attrs_odt_input_buffer(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    //keep simulation to values we know work
    uint8_t is_sim = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim) );


    FAPI_TRY( eff_odt_input_buff(l_mcs, l_attrs_odt_input_buffer.data()) );

    //sim vs actual hardware value
    l_attrs_odt_input_buffer[l_port_num] = is_sim ? SIM_VALUE : fapi2::ENUM_ATTR_EFF_ODT_INPUT_BUFF_ACTIVATED;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_ODT_INPUT_BUFF,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_odt_input_buffer, PORTS_PER_MCS)),
              "Failed setting attribute for ODT_INPUT_BUFF");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for data_mask
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Datamask is unnused and not needed because no DBI.
/// @note Defaulted to 0
///
fapi2::ReturnCode eff_config::data_mask(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_data_mask(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_data_mask(l_mcs, l_attrs_data_mask.data()) );

    l_attrs_data_mask[l_port_num] = fapi2::ENUM_ATTR_EFF_DATA_MASK_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DATA_MASK,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_data_mask, PORTS_PER_MCS)),
              "Failed setting attribute for DATA_MASK");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for write_dbi
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note DBI is not supported
///
fapi2::ReturnCode eff_config::write_dbi(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_write_dbi(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_write_dbi(l_mcs, l_attrs_write_dbi.data()) );

    l_attrs_write_dbi[l_port_num] = fapi2::ENUM_ATTR_EFF_WRITE_DBI_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_WRITE_DBI,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_write_dbi, PORTS_PER_MCS)),
              "Failed setting attribute for WRITE_DBI");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for read_dbi
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note read_dbi is not supported, so set to DISABLED (0)
/// @note No logic for DBI
///
fapi2::ReturnCode eff_config::read_dbi(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

    std::vector<uint8_t> l_attrs_read_dbi(PORTS_PER_MCS, 0);
    FAPI_TRY( eff_read_dbi(l_mcs, l_attrs_read_dbi.data()) );

    l_attrs_read_dbi[l_port_num] = fapi2::ENUM_ATTR_EFF_READ_DBI_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_READ_DBI,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_read_dbi, PORTS_PER_MCS)),
              "Failed setting attribute for READ_DBI");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Post Package Repair
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note write_dbi is not supported, so set to DISABLED (0)
/// @note no logic for DBI
///
fapi2::ReturnCode eff_config::post_package_repair(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint8_t l_decoder_val = 0;
    uint8_t l_attrs_dram_ppr[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( eff_dram_ppr(l_mcs, &l_attrs_dram_ppr[0][0]) );
    FAPI_TRY( iv_pDecoder->post_package_repair(i_target, l_decoder_val) );

    l_attrs_dram_ppr[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_PPR, l_mcs, l_attrs_dram_ppr),
              "Failed setting attribute for DRAM_PPR");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for rd_preamble_train
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::read_preamble_train(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

    std::vector<uint8_t> l_attrs_rd_preamble_train(PORTS_PER_MCS, 0);
    FAPI_TRY( eff_rd_preamble_train(l_mcs, l_attrs_rd_preamble_train.data()) );

    l_attrs_rd_preamble_train[l_port_num] = fapi2::ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_RD_PREAMBLE_TRAIN,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_rd_preamble_train, PORTS_PER_MCS)),
              "Failed setting attribute for RD_PREAMBLE_TRAIN");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for rd_preamble
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::read_preamble(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_rd_preamble(PORTS_PER_MCS, 0);
    uint8_t l_preamble = 0;

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY (vpd_mt_preamble (l_mca, l_preamble) ) ;
    l_preamble = l_preamble & 0xF0;
    l_preamble = l_preamble >> 4;


    FAPI_ASSERT( ((l_preamble == 0) || (l_preamble == 1)),
                 fapi2::MSS_INVALID_VPD_MT_PREAMBLE()
                 .set_VALUE(l_preamble)
                 .set_DIMM_TARGET(i_target),
                 "Target %s VPD_MT_PREAMBLE is invalid (not 1 or 0), value is %d",
                 mss::c_str(i_target),
                 l_preamble );

    FAPI_TRY( eff_rd_preamble(l_mcs, l_attrs_rd_preamble.data()) );

    l_attrs_rd_preamble[l_port_num] = l_preamble;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_RD_PREAMBLE,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_rd_preamble, PORTS_PER_MCS)),
              "Failed setting attribute for RD_PREAMBLE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for wr_preamble
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::write_preamble(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_wr_preamble(PORTS_PER_MCS, 0);
    uint8_t l_preamble = 0;
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY (vpd_mt_preamble (l_mca, l_preamble) ) ;
    l_preamble = l_preamble & 0x0F;
    FAPI_INF("WR preamble is %d", l_preamble);

    FAPI_ASSERT( ((l_preamble == 0) || (l_preamble == 1)),
                 fapi2::MSS_INVALID_VPD_MT_PREAMBLE()
                 .set_VALUE(l_preamble)
                 .set_DIMM_TARGET(i_target),
                 "Target %s VPD_MT_PREAMBLE is invalid (not 1 or 0), value is %d",
                 mss::c_str(i_target),
                 l_preamble );

    FAPI_TRY( eff_wr_preamble(l_mcs, l_attrs_wr_preamble.data()) );

    l_attrs_wr_preamble[l_port_num] = l_preamble;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_WR_PREAMBLE,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_wr_preamble, PORTS_PER_MCS)),
              "Failed setting attribute for RD_PREAMBLE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for self_ref_abort
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::self_refresh_abort(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_self_ref_abort(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_self_ref_abort(l_mcs, l_attrs_self_ref_abort.data()) );

    l_attrs_self_ref_abort[l_port_num] = fapi2::ENUM_ATTR_EFF_SELF_REF_ABORT_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_SELF_REF_ABORT,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_self_ref_abort, PORTS_PER_MCS)),
              "Failed setting attribute for SELF_REF_ABORT");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for cs_cmd_latency
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::cs_to_cmd_addr_latency(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_cs_cmd_latency(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_cs_cmd_latency(l_mcs, l_attrs_cs_cmd_latency.data()) );

    l_attrs_cs_cmd_latency[l_port_num] = fapi2::ENUM_ATTR_EFF_CS_CMD_LATENCY_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CS_CMD_LATENCY,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_cs_cmd_latency, PORTS_PER_MCS)),
              "Failed setting attribute for CS_CMD_LATENCY");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for int_vref_mon
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::internal_vref_monitor(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_int_vref_mon(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_internal_vref_monitor(l_mcs, l_attrs_int_vref_mon.data()) );

    l_attrs_int_vref_mon[l_port_num] = fapi2::ENUM_ATTR_EFF_INTERNAL_VREF_MONITOR_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_INTERNAL_VREF_MONITOR,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_int_vref_mon, PORTS_PER_MCS)),
              "Failed setting attribute for INT_VREF_MON");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for powerdown_mode
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::max_powerdown_mode(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_powerdown_mode(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_max_powerdown_mode(l_mcs, l_attrs_powerdown_mode.data()) );

    l_attrs_powerdown_mode[l_port_num] = fapi2::ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MAX_POWERDOWN_MODE,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_powerdown_mode, PORTS_PER_MCS)),
              "Failed setting attribute for POWERDOWN_MODE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for mpr_rd_format
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::mpr_read_format(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_mpr_rd_format(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_mpr_rd_format(l_mcs, l_attrs_mpr_rd_format.data()) );

    //Serial format is standard for Nimbus and needed for PHY calibration (draminit_training)
    l_attrs_mpr_rd_format[l_port_num] = fapi2::ENUM_ATTR_EFF_MPR_RD_FORMAT_SERIAL;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MPR_RD_FORMAT,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_mpr_rd_format, PORTS_PER_MCS)),
              "Failed setting attribute for MPR_RD_FORMAT");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for CRC write latency
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::crc_wr_latency(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_crc_wr_latency(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    //keep simulation to values we know work
    uint8_t is_sim = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim) );

    FAPI_TRY( eff_crc_wr_latency(l_mcs, l_attrs_crc_wr_latency.data()) );

    //keep simulation to values we know work
    if(is_sim)
    {
        l_attrs_crc_wr_latency[l_port_num] = 0x05;
    }
    //set the attribute according to frequency
    else
    {
        //TODO RTC:159481 - update CRC write latency to include 2667
        //currently, JEDEC defines the following
        //crc wr latency - freq
        //4              - 1600
        //5              - 1866, 2133, 2400
        //6              - TBD
        //Nimbus only supports 1866->2400 on the current list
        //2667 is not noted. We will set crc_wr_latency to 0x05 until JEDEC value is updated
        //When JEDEC defines the 2667 value we can change this, but leave the sim value as 0x05
        l_attrs_crc_wr_latency[l_port_num] = 0x05;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CRC_WR_LATENCY,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_crc_wr_latency, PORTS_PER_MCS)),
              "Failed setting attribute for CRC WRITE LATENCY");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for temperature readout
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::temp_readout(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_temp_readout(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_temp_readout(l_mcs, l_attrs_temp_readout.data()) );

    //Disabled for mainline mode
    l_attrs_temp_readout[l_port_num] = fapi2::ENUM_ATTR_EFF_TEMP_READOUT_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_TEMP_READOUT,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_temp_readout, PORTS_PER_MCS)),
              "Failed setting attribute for TEMP_READOUT");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for per DRAM addressability
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::per_dram_addressability(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_per_dram_access(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_per_dram_access(l_mcs, l_attrs_per_dram_access.data()) );

    //PDA is disabled in mainline functionality
    l_attrs_per_dram_access[l_port_num] = fapi2::ENUM_ATTR_EFF_PER_DRAM_ACCESS_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_PER_DRAM_ACCESS,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_per_dram_access, PORTS_PER_MCS)),
              "Failed setting attribute for PER_DRAM_ACCESS");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for geardown mode
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::geardown_mode(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_geardown_mode(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    // Geardown maps directly to autoset = 0 gets 1/2 rate, 1 get 1/4 rate.
    FAPI_TRY( eff_geardown_mode(l_mcs, l_attrs_geardown_mode.data()) );

    // If the MRW states 'auto' we use what's in VPD, otherwise we use what's in the MRW.
    // We remove 1 from the value as that matches the expectations in the MR perfectly.
    l_attrs_geardown_mode[l_port_num] = mss::two_n_mode_helper(i_target);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_GEARDOWN_MODE,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_geardown_mode, PORTS_PER_MCS)),
              "Failed setting attribute for GEARDOWN_MODE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for MPR page
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::mpr_page(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_mpr_page(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_mpr_page(l_mcs, l_attrs_mpr_page.data()) );

    //page0 is needed for PHY calibration algorithm (run in draminit_training)
    l_attrs_mpr_page[l_port_num] = fapi2::ENUM_ATTR_EFF_MPR_PAGE_PG0;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MPR_PAGE,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_mpr_page, PORTS_PER_MCS)),
              "Failed setting attribute for MPR_PAGE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for MPR mode
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::mpr_mode(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint8_t> l_attrs_mpr_mode(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_mpr_mode(l_mcs, l_attrs_mpr_mode.data()) );

    //MPR mode is disabled for mainline functionality
    l_attrs_mpr_mode[l_port_num] = fapi2::ENUM_ATTR_EFF_MPR_MODE_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MPR_MODE,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_mpr_mode, PORTS_PER_MCS)),
              "Failed setting attribute for MPR_MODE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for write CRC
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::write_crc(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    //TODO: RTC 159554 Update RAS related attributes
    std::vector<uint8_t> l_attrs_write_crc(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_write_crc(l_mcs, l_attrs_write_crc.data()) );

    l_attrs_write_crc[l_port_num] = fapi2::ENUM_ATTR_EFF_WRITE_CRC_DISABLE;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_WRITE_CRC,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_write_crc, PORTS_PER_MCS)),
              "Failed setting attribute for WRITE_CRC");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for ZQ Calibration
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::zqcal_interval(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint32_t> l_attrs_zqcal_interval(PORTS_PER_MCS, 0);
    uint64_t l_freq = 0;

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( mss::freq(find_target<fapi2::TARGET_TYPE_MCBIST>(l_mcs), l_freq));
    FAPI_TRY( eff_zqcal_interval(l_mcs, l_attrs_zqcal_interval.data()) );

    // Calculate ZQCAL Interval based on the following equation from Ken:
    //               0.5
    // ------------------------------ = 13.333ms
    //     (1.5 * 10) + (0.15 * 150)
    //  (13333 * ATTR_MSS_FREQ) / 2

    l_attrs_zqcal_interval[l_port_num] = 13333 * l_freq / 2;


    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_ZQCAL_INTERVAL,
                            l_mcs,
                            UINT32_VECTOR_TO_1D_ARRAY(l_attrs_zqcal_interval, PORTS_PER_MCS)),
              "Failed setting attribute for ZQCAL_INTERVAL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for MEMCAL Calibration
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::memcal_interval(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    std::vector<uint32_t> l_attrs_memcal_interval(PORTS_PER_MCS, 0);
    uint64_t l_freq = 0;

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( mss::freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq));

    FAPI_TRY( eff_memcal_interval(l_mcs, l_attrs_memcal_interval.data()) );

    // Calculate MEMCAL Interval based on 1sec interval across all bits per DP16
    // (62500 * ATTR_MSS_FREQ) / 2
    l_attrs_memcal_interval[l_port_num] = 62500 * l_freq / 2;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MEMCAL_INTERVAL,
                            l_mcs,
                            UINT32_VECTOR_TO_1D_ARRAY(l_attrs_memcal_interval, PORTS_PER_MCS)),
              "Failed setting attribute for MEMCAL_INTERVAL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRP
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trp(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));

    int64_t l_trp_in_ps = 0;

    // Calculate tRP (in ps)
    {
        int64_t l_trp_mtb = 0;
        int64_t l_trp_ftb = 0;
        int64_t l_ftb = 0;
        int64_t l_mtb = 0;

        FAPI_TRY( iv_pDecoder->medium_timebase(i_target, l_mtb),
                  "Failed medium_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->fine_timebase(i_target, l_ftb),
                  "Failed fine_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->min_row_precharge_delay_time(i_target, l_trp_mtb),
                  "Failed min_row_precharge_delay_time() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->fine_offset_min_trp(i_target, l_trp_ftb),
                  "Failed fine_offset_min_trp() for %s", mss::c_str(i_target) );

        FAPI_INF("medium timebase (ps): %ld, fine timebase (ps): %ld, tRP (MTB): %ld, tRP(FTB): %ld",
                 l_mtb, l_ftb, l_trp_mtb, l_trp_ftb);

        l_trp_in_ps = spd::calc_timing_from_timebase(l_trp_mtb, l_mtb, l_trp_ftb, l_ftb);
    }

    // SPD spec gives us the minimum... compute our worstcase (maximum) from JEDEC
    {
        // Declaring as int64_t to fix std::max compile
        const int64_t l_trp = mss::ps_to_cycles(i_target, mss::trtp());
        l_trp_in_ps = std::max( l_trp_in_ps , l_trp );
    }

    {
        std::vector<uint8_t> l_attrs_dram_trp(PORTS_PER_MCS, 0);
        uint8_t l_trp_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_trp_in_ps, iv_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_trp_in_nck),
                  "Error in calculating dram_tRP nck for target %s, with value of l_trp_in_ps: %d", mss::c_str(i_target), l_trp_in_ps);

        FAPI_INF( "tCK (ps): %d, tRP (ps): %d, tRP (nck): %d  for target: %s",
                  iv_tCK_in_ps, l_trp_in_ps, l_trp_in_nck, mss::c_str(i_target) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_trp(l_mcs, l_attrs_dram_trp.data()) );

        l_attrs_dram_trp[l_port_num] = l_trp_in_nck ;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRP,
                                l_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trp, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TRP");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRCD
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trcd(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));
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
        int64_t l_ftb = 0;
        int64_t l_mtb = 0;

        FAPI_TRY( iv_pDecoder->medium_timebase(i_target, l_mtb),
                  "Failed medium_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->fine_timebase(i_target, l_ftb),
                  "Failed fine_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->min_ras_to_cas_delay_time(i_target, l_trcd_mtb),
                  "Failed min_ras_to_cas_delay_time() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->fine_offset_min_trcd(i_target, l_trcd_ftb),
                  "Failed fine_offset_min_trcd() for %s", mss::c_str(i_target) );

        FAPI_INF("medium timebase MTB (ps): %ld, fine timebase FTB (ps): %ld, tRCD (MTB): %ld, tRCD (FTB): %ld",
                 l_mtb, l_ftb, l_trcd_mtb, l_trcd_ftb);

        l_trcd_in_ps = spd::calc_timing_from_timebase(l_trcd_mtb, l_mtb, l_trcd_ftb, l_ftb);
    }

    {
        std::vector<uint8_t> l_attrs_dram_trcd(PORTS_PER_MCS, 0);
        uint8_t l_trcd_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_trcd_in_ps, iv_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_trcd_in_nck),
                  "Error in calculating trcd for target %s, with value of l_trcd_in_ps: %d", mss::c_str(i_target), l_trcd_in_ps);

        FAPI_INF("tCK (ps): %d, tRCD (ps): %d, tRCD (nck): %d  for target: %s",
                 iv_tCK_in_ps, l_trcd_in_ps, l_trcd_in_nck, mss::c_str(i_target));

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_trcd(l_mcs, l_attrs_dram_trcd.data()) );

        l_attrs_dram_trcd[l_port_num] = l_trcd_in_nck;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRCD,
                                l_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trcd, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TRCD");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRC
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trc(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));
    int64_t l_trc_in_ps = 0;

    // Calculate trc (in ps)
    {
        int64_t l_trc_mtb = 0;
        int64_t l_trc_ftb = 0;
        int64_t l_ftb = 0;
        int64_t l_mtb = 0;

        FAPI_TRY( iv_pDecoder->medium_timebase(i_target, l_mtb),
                  "Failed medium_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->fine_timebase(i_target, l_ftb),
                  "Failed fine_timebase() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->min_active_to_active_refresh_delay_time(i_target, l_trc_mtb),
                  "Failed min_active_to_active_refresh_delay_time() for %s", mss::c_str(i_target) );
        FAPI_TRY( iv_pDecoder->fine_offset_min_trc(i_target, l_trc_ftb),
                  "Failed fine_offset_min_trc() for %s", mss::c_str(i_target) );

        FAPI_INF("medium timebase MTB (ps): %ld, fine timebase FTB (ps): %ld, tRCmin (MTB): %ld, tRCmin(FTB): %ld",
                 l_mtb, l_ftb, l_trc_mtb, l_trc_ftb);

        l_trc_in_ps = spd::calc_timing_from_timebase(l_trc_mtb, l_mtb, l_trc_ftb, l_ftb);
    }

    {
        std::vector<uint8_t> l_attrs_dram_trc(PORTS_PER_MCS, 0);
        uint8_t l_trc_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_trc_in_ps, iv_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_trc_in_nck),
                  "Error in calculating trc for target %s, with value of l_trc_in_ps: %d",
                  mss::c_str(i_target), l_trc_in_ps );

        FAPI_INF( "tCK (ps): %d, tRC (ps): %d, tRC (nck): %d  for target: %s",
                  iv_tCK_in_ps, l_trc_in_ps, l_trc_in_nck, mss::c_str(i_target) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_trc(l_mcs, l_attrs_dram_trc.data()) );

        l_attrs_dram_trc[l_port_num] = l_trc_in_nck;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRC,
                                l_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trc, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TRC");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tWTR_L
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_twtr_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));
    int64_t l_twtr_l_in_ps = 0;

    // Calculate twtr_l (in ps)
    {
        constexpr int64_t l_twtr_l_ftb = 0;
        int64_t l_twtr_l_mtb = 0;
        int64_t l_ftb = 0;
        int64_t l_mtb = 0;

        FAPI_TRY( iv_pDecoder->medium_timebase(i_target, l_mtb) );
        FAPI_TRY( iv_pDecoder->fine_timebase(i_target, l_ftb) );
        FAPI_TRY( iv_pDecoder->min_twtr_l(i_target, l_twtr_l_mtb) );

        FAPI_INF("medium timebase (ps): %ld, fine timebase (ps): %ld, tWTR_S (MTB): %ld, tWTR_S (FTB): %ld",
                 l_mtb, l_ftb, l_twtr_l_mtb, l_twtr_l_ftb );

        l_twtr_l_in_ps = spd::calc_timing_from_timebase(l_twtr_l_mtb, l_mtb, l_twtr_l_ftb, l_ftb);
    }


    {
        std::vector<uint8_t> l_attrs_dram_twtr_l(PORTS_PER_MCS, 0);
        int8_t l_twtr_l_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_twtr_l_in_ps, iv_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_twtr_l_in_nck),
                  "Error in calculating tWTR_L for target %s, with value of l_twtr_in_ps: %d", mss::c_str(i_target), l_twtr_l_in_ps );

        FAPI_INF( "tCK (ps): %d,  tWTR_L (ps): %d, tWTR_L (nck): %d  for target: %s",
                  iv_tCK_in_ps, l_twtr_l_in_ps, l_twtr_l_in_nck, mss::c_str(i_target) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_twtr_l(l_mcs, l_attrs_dram_twtr_l.data()) );

        l_attrs_dram_twtr_l[l_port_num] = l_twtr_l_in_nck;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWTR_L,
                                l_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_twtr_l, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TWTR_L");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tWTR_S
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_twtr_s(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));
    int64_t l_twtr_s_in_ps = 0;

    // Calculate twtr_s (in ps)
    {
        constexpr int64_t l_twtr_s_ftb = 0;
        int64_t l_twtr_s_mtb = 0;
        int64_t l_ftb = 0;
        int64_t l_mtb = 0;

        FAPI_TRY( iv_pDecoder->medium_timebase(i_target, l_mtb) );
        FAPI_TRY( iv_pDecoder->fine_timebase(i_target, l_ftb) );
        FAPI_TRY( iv_pDecoder->min_twtr_s(i_target, l_twtr_s_mtb) );

        FAPI_INF("medium timebase (ps): %ld, fine timebase (ps): %ld, tWTR_S (MTB): %ld, tWTR_S (FTB): %ld",
                 l_mtb, l_ftb, l_twtr_s_mtb, l_twtr_s_ftb );

        l_twtr_s_in_ps = spd::calc_timing_from_timebase(l_twtr_s_mtb, l_mtb, l_twtr_s_ftb, l_ftb);
    }

    {
        std::vector<uint8_t> l_attrs_dram_twtr_s(PORTS_PER_MCS, 0);
        uint8_t l_twtr_s_in_nck = 0;

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_twtr_s_in_ps, iv_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_twtr_s_in_nck),
                  "Error in calculating tWTR_S for target %s, with value of l_twtr_in_ps: %d", mss::c_str(i_target), l_twtr_s_in_ps);

        FAPI_INF("tCK (ps): %d, tWTR_S (ps): %d, tWTR_S (nck): %d  for target: %s",
                 iv_tCK_in_ps, l_twtr_s_in_ps, l_twtr_s_in_nck, mss::c_str(i_target) );

        // Get & update MCS attribute
        FAPI_TRY( eff_dram_twtr_s(l_mcs, l_attrs_dram_twtr_s.data()) );

        l_attrs_dram_twtr_s[l_port_num] = l_twtr_s_in_nck;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWTR_S,
                                l_mcs,
                                UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_twtr_s, PORTS_PER_MCS)),
                  "Failed setting attribute for DRAM_TWTR_S");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRRD_S
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trrd_s(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));

    std::vector<uint8_t> l_attrs_dram_trrd_s(PORTS_PER_MCS, 0);
    uint64_t l_trrd_s_in_nck = 0;
    uint8_t l_stack_type = 0;
    uint8_t l_dram_width = 0;

    FAPI_TRY( iv_pDecoder->prim_sdram_signal_loading(i_target, l_stack_type) );
    FAPI_TRY( iv_pDecoder->device_width(i_target, l_dram_width),
              "Failed to access device_width()");

    // From the SPD Spec:
    // At some frequencies, a minimum number of clocks may be required resulting
    // in a larger tRRD_Smin value than indicated in the SPD.
    // tRRD_S (3DS) is speed bin independent.
    // So we won't read this from SPD and choose the correct value based on mss_freq

    if( l_stack_type == fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS)
    {
        FAPI_TRY( trrd_s_slr(i_target, l_trrd_s_in_nck) );
    }
    else
    {
        // Non-3DS
        FAPI_TRY( mss::trrd_s(i_target, l_dram_width, l_trrd_s_in_nck) );
    }

    FAPI_INF("SDRAM width: %d, tRRD_S (nck): %d for target: %s",
             l_dram_width, l_trrd_s_in_nck, mss::c_str(i_target));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_trrd_s(l_mcs, l_attrs_dram_trrd_s.data()) );

    l_attrs_dram_trrd_s[l_port_num] = l_trrd_s_in_nck;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRRD_S,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trrd_s, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TRRD_S");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRRD_L
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trrd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));

    std::vector<uint8_t> l_attrs_dram_trrd_l(PORTS_PER_MCS, 0);
    uint64_t l_trrd_l_in_nck = 0;
    uint8_t l_stack_type = 0;
    uint8_t l_dram_width = 0;

    FAPI_TRY( iv_pDecoder->prim_sdram_signal_loading(i_target, l_stack_type),
              "Failed prim_sdram_signal_loading()" );
    FAPI_TRY( iv_pDecoder->device_width(i_target, l_dram_width),
              "Failed to access device_width()");

    // From the SPD Spec:
    // At some frequencies, a minimum number of clocks may be required resulting
    // in a larger tRRD_Smin value than indicated in the SPD.
    // tRRD_S (3DS) is speed bin independent.
    // So we won't read this from SPD and choose the correct value based on mss_freq

    if( l_stack_type == fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS)
    {
        FAPI_TRY( trrd_l_slr(i_target, l_trrd_l_in_nck) );
    }
    else
    {
        FAPI_TRY( mss::trrd_l(i_target, l_dram_width, l_trrd_l_in_nck), "Failed trrd_l()" );
    }

    FAPI_INF("SDRAM width: %d, tRRD_L (nck): %d for target: %s",
             l_dram_width, l_trrd_l_in_nck, mss::c_str(i_target));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_trrd_l(l_mcs, l_attrs_dram_trrd_l.data()) );

    l_attrs_dram_trrd_l[l_port_num] = l_trrd_l_in_nck;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRRD_L,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trrd_l, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TRRD_L");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRRD_dlr
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trrd_dlr(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));

    std::vector<uint8_t> l_attrs_dram_trrd_dlr(PORTS_PER_MCS, 0);
    constexpr uint64_t l_trrd_dlr_in_nck = trrd_dlr();

    FAPI_INF("tRRD_dlr (nck): %d  for target: %s", l_trrd_dlr_in_nck, mss::c_str(i_target));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_trrd_dlr(l_mcs, l_attrs_dram_trrd_dlr.data()) );

    l_attrs_dram_trrd_dlr[l_port_num] = l_trrd_dlr_in_nck;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRRD_DLR,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trrd_dlr, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TRRD_DLR");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tfaw
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_tfaw(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));

    std::vector<uint8_t> l_attrs_dram_tfaw(PORTS_PER_MCS, 0);
    uint64_t l_tfaw_in_nck = 0;
    uint8_t l_stack_type = 0;
    uint8_t l_dram_width = 0;

    FAPI_TRY( iv_pDecoder->prim_sdram_signal_loading(i_target, l_stack_type),
              "Failed prim_sdram_signal_loading()");
    FAPI_TRY( iv_pDecoder->device_width(i_target, l_dram_width),
              "Failed device_width()");

    if( l_stack_type == fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS)
    {
        FAPI_TRY( tfaw_slr(i_target, l_dram_width, l_tfaw_in_nck), "Failed tfaw_slr()");
    }
    else
    {
        FAPI_TRY( mss::tfaw(i_target, l_dram_width, l_tfaw_in_nck), "Failed tfaw()" );
    }

    FAPI_INF("SDRAM width: %d, tFAW (nck): %d  for target: %s",
             l_dram_width, l_tfaw_in_nck, mss::c_str(i_target));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_tfaw(l_mcs, l_attrs_dram_tfaw.data()) );

    l_attrs_dram_tfaw[l_port_num] = l_tfaw_in_nck;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TFAW,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_tfaw, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TFAW");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tFAW_DLR
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_tfaw_dlr(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));

    std::vector<uint8_t> l_attrs_dram_tfaw_dlr(PORTS_PER_MCS, 0);
    constexpr uint64_t l_tfaw_dlr_in_nck = tfaw_dlr();

    FAPI_INF("tFAW_dlr (nck): %d  for target: %s", l_tfaw_dlr_in_nck, mss::c_str(i_target));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_tfaw_dlr(l_mcs, l_attrs_dram_tfaw_dlr.data()) );

    l_attrs_dram_tfaw_dlr[l_port_num] = l_tfaw_dlr_in_nck;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TFAW_DLR,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_tfaw_dlr, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TFAW_DLR");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRAS
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_tras(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));

    // tRAS is bin independent so we don't read this from SPD
    // which will give the best timing value for the dimm
    // (like 2400 MT/s) which may be different than the system
    // speed (if we were being limited by VPD or MRW restrictions)
    const uint64_t l_tras_in_ps = mss::tras(i_target);

    // Calculate nck
    std::vector<uint8_t> l_attrs_dram_tras(PORTS_PER_MCS, 0);
    uint8_t l_tras_in_nck = 0;

    // Cast needed for calculations to be done on the same integral type
    // as required by template deduction. We have iv_tCK_in_ps as a signed
    // integer because we have other timing values that calculations do
    // addition with negative integers.
    FAPI_TRY( spd::calc_nck(l_tras_in_ps,
                            static_cast<uint64_t>(iv_tCK_in_ps),
                            INVERSE_DDR4_CORRECTION_FACTOR,
                            l_tras_in_nck),
              "Error in calculating tras_l for target %s, with value of l_twtr_in_ps: %d",
              mss::c_str(i_target), l_tras_in_ps);

    FAPI_INF("tCK (ps): %d, tRAS (ps): %d, tRAS (nck): %d  for target: %s",
             iv_tCK_in_ps, l_tras_in_ps, l_tras_in_nck, mss::c_str(i_target));

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_tras(l_mcs, l_attrs_dram_tras.data()) );

    l_attrs_dram_tras[l_port_num] = l_tras_in_nck;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRAS,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_tras, PORTS_PER_MCS)),
              "Failed setting attribute for tRAS");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tRTP
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_trtp(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index(find_target<TARGET_TYPE_MCA>(i_target));

    // Values from proposed DDR4 Full spec update(79-4A)
    // Item No. 1716.78C
    // Page 241 & 246
    int64_t constexpr l_max_trtp_in_ps = trtp();

    std::vector<uint8_t> l_attrs_dram_trtp(PORTS_PER_MCS, 0);
    uint8_t l_calc_trtp_in_nck = 0;

    // Calculate nck
    FAPI_TRY( spd::calc_nck(l_max_trtp_in_ps, iv_tCK_in_ps, INVERSE_DDR4_CORRECTION_FACTOR, l_calc_trtp_in_nck),
              "Error in calculating trtp  for target %s, with value of l_twtr_in_ps: %d",
              mss::c_str(i_target), l_max_trtp_in_ps);

    FAPI_INF("tCK (ps): %d, tRTP (ps): %d, tRTP (nck): %d",
             iv_tCK_in_ps, l_max_trtp_in_ps, l_calc_trtp_in_nck);

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_trtp(l_mcs, l_attrs_dram_trtp.data()) );

    l_attrs_dram_trtp[l_port_num] = l_calc_trtp_in_nck;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRTP,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_dram_trtp, PORTS_PER_MCS)),
              "Failed setting attribute for DRAM_TRTP");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Grab the VPD blobs and decode into attributes
/// @param[in] i_target FAPI2 target (MCS)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::decode_vpd(const fapi2::Target<TARGET_TYPE_MCS>& i_target)
{
    uint8_t l_mr_blob[mss::VPD_KEYWORD_MAX] = {0};
    uint8_t l_cke_blob[mss::VPD_KEYWORD_MAX] = {0};
    uint8_t l_dq_blob[mss::VPD_KEYWORD_MAX] = {0};

    std::vector<uint8_t*> l_mt_blobs(PORTS_PER_MCS, nullptr);
    fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_vpd_info(fapi2::MemVpdData::MT);

    // For sanity. Not sure this will break us, but we're certainly making assumptions below.
    static_assert(MAX_DIMM_PER_PORT == 2, "Max DIMM per port isn't 2");

    // We need to set up all VPD info before calling getVPD, the API assumes this
    // For MR we need to tell the VPDInfo the frequency (err ... mt/s - why is this mhz?)
    FAPI_TRY( mss::freq(find_target<TARGET_TYPE_MCBIST>(i_target), l_vpd_info.iv_freq_mhz) );
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
        // Find our blob in the vector of blob pointers
        uint8_t* l_mt_blob = l_mt_blobs[mss::index(p)];
        uint64_t l_rank_count_dimm[MAX_DIMM_PER_PORT] = {0};

        // If we don't have any DIMM, don't worry about it. This will just drop the blob full of 0's into our index.
        // This will fill the VPD attributes with 0's which is perfectly ok.
        for (const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(p))
        {
            uint8_t l_num_master_ranks = 0;
            FAPI_TRY( mss::eff_num_master_ranks_per_dimm(d, l_num_master_ranks) );
            l_rank_count_dimm[mss::index(d)] = l_num_master_ranks;
        }

        // This value will, of course, be 0 if there is no DIMM in the port.
        l_vpd_info.iv_rank_count_dimm_0 = l_rank_count_dimm[0];
        l_vpd_info.iv_rank_count_dimm_1 = l_rank_count_dimm[1];

        FAPI_INF("%s. VPD info - rank count for dimm_0: %d, dimm_1: %d",
                 mss::c_str(i_target), l_vpd_info.iv_rank_count_dimm_0, l_vpd_info.iv_rank_count_dimm_1);

        // Get the MCS blob for this specific rank combination *only if* we have DIMM. Remember,
        // Cronus can give us functional MCA which have no DIMM - and we'd puke getting the VPD.
        if ((l_vpd_info.iv_rank_count_dimm_0 != 0) || (l_vpd_info.iv_rank_count_dimm_1 != 0))
        {
            // If getVPD returns us an error, then we don't have VPD for the DIMM configuration.
            // This is the root of our plug-rules: if you want a configuration of DIMM to be
            // supported, it needs to have VPD defined. Likewise, if you don't want a configuration
            // of DIMM supported be sure to leave it out of the VPD. Note that we don't return a specific
            // plug-rule error as f/w (Dan) suggested this would duplicate errors leading to confusion.
            l_vpd_info.iv_vpd_type = fapi2::MemVpdData::MT;

            // Check the max for giggles. Programming bug so we should assert.
            FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, nullptr),
                      "Failed to retrieve MT size from VPD");

            if (l_vpd_info.iv_size > mss::VPD_KEYWORD_MAX)
            {
                FAPI_ERR("VPD MT keyword is too big for our array");
                fapi2::Assert(false);
            }

            FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, &(l_mt_blob[0])),
                      "Failed to retrieve MT VPD");
        }
    }// mca

    // Only get the MR blob if we have a freq. It's possible for Cronus to give us an MCS which
    // is connected to a controller which has 0 DIMM installed. In this case, we won't have
    // a frequency, and thus we'd fail getting the VPD. So we initiaized the VPD to 0's and if
    // there's no freq, we us a 0 filled VPD.
    if (l_vpd_info.iv_freq_mhz != 0)
    {
        l_vpd_info.iv_vpd_type = fapi2::MemVpdData::MR;

        // Check the max for giggles. Programming bug so we should assert.
        FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, nullptr),
                  "Failed to retrieve MR size from VPD");

        if (l_vpd_info.iv_size > mss::VPD_KEYWORD_MAX)
        {
            FAPI_ERR("VPD MR keyword is too big for our array");
            fapi2::Assert(false);
        }

        FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, &(l_mr_blob[0])),
                  "Failed to retrieve MR VPD");
    }

    // Until CK/DQ integration is working, we differentiate getting our fake_vpd for those ids.
    // This gives us an extended API we can use for testing which won't be seen by HB because we'd use this to limit it
#ifndef __HOSTBOOT_MODULE

    // Get CKE data
    l_vpd_info.iv_vpd_type = fapi2::MemVpdData::CK;

    // Check the max for giggles. Programming bug so we should assert.
    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, nullptr),
              "Failed to retrieve CK size from VPD");

    if (l_vpd_info.iv_size > mss::VPD_KEYWORD_MAX)
    {
        FAPI_ERR("VPD CK keyword is too big for our array");
        fapi2::Assert(false);
    }

    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, &(l_cke_blob[0])),
              "Failed to retrieve DQ VPD");

    // Get DQ data
    l_vpd_info.iv_vpd_type = fapi2::MemVpdData::DQ;

    // Check the max for giggles. Programming bug so we should assert.
    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, nullptr),
              "Failed to retrieve DQ size from VPD");

    if (l_vpd_info.iv_size > mss::VPD_KEYWORD_MAX)
    {
        FAPI_ERR("VPD DQ keyword is too big for our array");
        fapi2::Assert(false);
    }

    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, &(l_dq_blob[0])),
              "Failed to retrieve DQ VPD");

#endif

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

}// mss
