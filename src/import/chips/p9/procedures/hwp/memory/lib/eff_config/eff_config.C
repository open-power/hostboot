
/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/eff_config/eff_config.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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

#include <fapi2.H>
#include <mss.H>
#include "../spd/spd_decoder.H"
#include "eff_config.H"
#include "timing.H"

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCBIST;

namespace mss
{

///
/// @brief Determines & sets effective config for DRAM generation from SPD
/// @param[in] i_target FAPI2 target
/// @param[in] i_spd_data SPD blob
/// @param[in] i_pDecoder shared pointer to decoder factory
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode eff_config::dram_gen(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                       const uint8_t* i_spd_data,
                                       std::shared_ptr<spd::decoder>& i_pDecoder)
{
    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_target_port);
    const auto l_dimm_num = index(i_target);

    // factory selects correct SPD method dependent on rev & dimm type
    FAPI_TRY( spd::decoder::factory(i_target, i_spd_data, i_pDecoder) );

    FAPI_TRY( i_pDecoder->dram_device_type(i_target, i_spd_data, l_decoder_val) );

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_gen(l_target_mcs, &l_mcs_attrs[0][0]) );
    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_GEN, l_target_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}// dram_gen


///
/// @brief Determines & sets effective config for DIMM type from SPD
/// @param[in] i_target FAPI2 target
/// @param[in] i_spd_data SPD blob
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode eff_config::dimm_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                        const uint8_t* i_spd_data)
{
    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_target_port);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( spd::decoder::base_module_type(i_target, i_spd_data, l_decoder_val) );

    // Get & update MCS attribute
    FAPI_TRY( eff_dimm_type(l_target_mcs, &l_mcs_attrs[0][0]) );
    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_TYPE, l_target_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}// dimm_type

///
/// @brief Determines & sets effective config for Hybrid memory type from SPD
/// @param[in] i_target FAPI2 target
/// @param[in] i_spd_data SPD blob
/// @param[in] i_pDecoder shared pointer to decoder factory
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode eff_config::hybrid_memory_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        const uint8_t* i_spd_data,
        std::shared_ptr<spd::decoder>& i_pDecoder)
{
    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_target_port);
    const auto l_dimm_num = index(i_target);

    // Factory selects correct SPD method dependent on rev & dimm type
    FAPI_TRY( spd::decoder::factory(i_target, i_spd_data, i_pDecoder) );

    FAPI_TRY(i_pDecoder->hybrid_media(i_target, i_spd_data, l_decoder_val));

    // Get & update MCS attribute
    FAPI_TRY( eff_hybrid_memory_type(l_target_mcs, &l_mcs_attrs[0][0]) );
    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_HYBRID_MEMORY_TYPE, l_target_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}// dimm_type

///
/// @brief Sets effective config for temperature controlled refresh mode
/// @param[in] i_target FAPI2 target
/// @return fapi2::ReturnCode
/// @note Proposed DDR4 Full spec update(79-4A)
/// @note  Committee: JC42.3C
/// @note  Committee Item Number: 1716.78C
/// @note  4.8.2  Extended temperature mode (pg. 44)
fapi2::ReturnCode eff_config::temp_ref_range(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_mcs_attrs[PORTS_PER_MCS] = {0};

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_target_port);

    FAPI_TRY( mss::eff_temp_ref_range(l_target_mcs, &l_mcs_attrs[0]) );

    // TK - I think this will become a platform attribute so this function
    // will eventuall get removed - AAM

    // This is defaulted to Extended temperature mode
    l_mcs_attrs[l_port_num] = fapi2::ENUM_ATTR_EFF_TEMP_REF_RANGE_EXTEND;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_TEMP_REF_RANGE, l_target_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}// temp_ref_range

///
/// @brief Determines & sets effective config for Refresh Mode
/// @param[in] i_target FAPI2 target
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode eff_config::fine_refresh_mode(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_mcs_attrs[PORTS_PER_MCS] = {0};
    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_target_port);

    // Per Warren - should be in Normal mode, might change based on lab test results -  AAM
    // Get & update MCS attribute
    FAPI_TRY( mss::eff_fine_refresh_mode(l_target_mcs, &l_mcs_attrs[0])) ;
    l_mcs_attrs[l_port_num] = fapi2::ENUM_ATTR_EFF_FINE_REFRESH_MODE_NORMAL;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_FINE_REFRESH_MODE, l_target_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}// refresh_mode


/// @brief Determines & sets effective config for refresh interval time (tREFI)
/// @param[in] i_target FAPI2 target
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode eff_config::refresh_interval_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_mcs_attrs_refresh[PORTS_PER_MCS] = {0};
    uint8_t l_refresh_mode = 0;

    uint8_t l_mcs_attrs_trefi[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    uint64_t l_trefi_in_ps = 0;
    uint8_t l_trefi_in_nck = 0;

    uint64_t l_mss_freq = 0;
    uint64_t l_tCK_in_ps = 0;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target);
    const auto l_target_mcbist = find_target<TARGET_TYPE_MCBIST>(i_target);

    // Current index
    const auto l_port_num = index(l_target_port);
    const auto l_dimm_num = index(i_target);

    // Retrieve attributes values
    FAPI_TRY( mss::freq(l_target_mcbist, l_mss_freq) );
    FAPI_TRY ( mss::eff_fine_refresh_mode(l_target_mcs, &l_mcs_attrs_refresh[0]) );

    l_refresh_mode = l_mcs_attrs_refresh[l_port_num];

    switch(l_refresh_mode)
    {
        case fapi2::ENUM_ATTR_EFF_FINE_REFRESH_MODE_NORMAL:
            calc_trefi1(i_target, l_trefi_in_ps);
            break;

        case fapi2::ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_2X:
            calc_trefi2(i_target, l_trefi_in_ps);
            break;

        case fapi2::ENUM_ATTR_EFF_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_EFF_FINE_REFRESH_MODE_FLY_4X:
            calc_trefi4(i_target, l_trefi_in_ps);
            break;
    }

    // Calculate clock period (tCK) from selected freq from mss_freq
    l_tCK_in_ps = freq_to_ps(l_mss_freq);

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_trefi(l_target_mcs, &l_mcs_attrs_trefi[0][0]) );

    l_trefi_in_nck = calc_nck(l_trefi_in_ps, l_tCK_in_ps, uint64_t(INVERSE_DDR4_CORRECTION_FACTOR));
    l_mcs_attrs_trefi[l_port_num][l_dimm_num] = uint8_t(l_trefi_in_nck);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TREFI, l_target_mcs, l_mcs_attrs_trefi) );

fapi_try_exit:
    return fapi2::current_err;
}// refresh_interval



}// mss
