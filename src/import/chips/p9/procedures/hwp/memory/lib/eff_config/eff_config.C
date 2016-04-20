
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
#include <eff_config/eff_config.H>
#include <eff_config/timing.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCBIST;

namespace mss
{

///
/// @brief Determines & sets effective config for DRAM generation from SPD
/// @param[in] i_target FAPI2 target
/// @param[in] i_pDecoder shared pointer to decoder factory
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_gen(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                       const std::shared_ptr<spd::decoder>& i_pDecoder)
{
    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( i_pDecoder->dram_device_type(i_target, l_decoder_val) );

    // Get & update MCS attribute
    FAPI_TRY( eff_dram_gen(l_mcs, &l_mcs_attrs[0][0]) );
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
    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( spd::base_module_type(i_target, i_spd_data, l_decoder_val) );

    // Get & update MCS attribute
    FAPI_TRY( eff_dimm_type(l_mcs, &l_mcs_attrs[0][0]) );
    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_TYPE, l_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;
}// dimm_type

///
/// @brief Determines & sets effective config for Hybrid memory type from SPD
/// @param[in] i_target FAPI2 target
/// @param[in] i_pDecoder shared pointer to decoder factory
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::hybrid_memory_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<spd::decoder>& i_pDecoder)
{
    uint8_t l_decoder_val = 0;
    uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY(i_pDecoder->hybrid_media(i_target, l_decoder_val));

    // Get & update MCS attribute
    FAPI_TRY( eff_hybrid_memory_type(l_mcs, &l_mcs_attrs[0][0]) );
    l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_HYBRID_MEMORY_TYPE, l_mcs, l_mcs_attrs) );

fapi_try_exit:
    return fapi2::current_err;

}// dimm_type

///
/// @brief Determines & sets effective config for refresh interval time (tREFI)
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::refresh_interval_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_refresh_mode = 0;
    uint64_t l_trefi_in_ps = 0;

    FAPI_TRY ( mss::mrw_fine_refresh_mode(l_refresh_mode) );

    switch(l_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_NORMAL:
            calc_trefi1(i_target, l_trefi_in_ps);
            break;

        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FLY_2X:
            calc_trefi2(i_target, l_trefi_in_ps);
            break;

        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FLY_4X:
            calc_trefi4(i_target, l_trefi_in_ps);
            break;
    }

    {
        // Calculate clock period (tCK) from selected freq from mss_freq
        uint64_t l_tCK_in_ps = 0;
        FAPI_TRY( clock_period(i_target, l_tCK_in_ps) );

        {
            // Calculate refresh cycle time in nCK & set attribute
            const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
            const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

            std::vector<uint8_t> l_mcs_attrs_trefi(PORTS_PER_MCS, 0);
            uint8_t l_trefi_in_nck ;

            // Get & update MCS attribute
            FAPI_TRY( eff_dram_trefi(l_mcs, &l_mcs_attrs_trefi[0]) );

            l_trefi_in_nck = calc_nck(l_trefi_in_ps, l_tCK_in_ps, uint64_t(INVERSE_DDR4_CORRECTION_FACTOR));
            l_mcs_attrs_trefi[l_port_num] = uint8_t(l_trefi_in_nck);

            // casts vector into the type FAPI_ATTR_SET is expecting by deduction
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TREFI,
                                    l_mcs,
                                    UINT8_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trefi, PORTS_PER_MCS)),
                      "Failed to set tREFI attribute");
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}// refresh_interval

///
/// @brief Determines & sets effective config for refresh cycle time (tRFC)
/// @param[in] i_target FAPI2 target
/// @param[in] i_pDecoder shared pointer to decoder factory
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::refresh_cycle_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<spd::decoder>& i_pDecoder)
{
    uint8_t l_refresh_mode = 0;
    int64_t l_trfc_in_ps = 0;

    FAPI_TRY ( mss::mrw_fine_refresh_mode(l_refresh_mode) );

    switch(l_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_NORMAL:
            i_pDecoder->min_refresh_recovery_delay_time_1(i_target, l_trfc_in_ps);
            break;

        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FLY_2X:
            i_pDecoder->min_refresh_recovery_delay_time_2(i_target, l_trfc_in_ps);
            break;

        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FLY_4X:
            i_pDecoder->min_refresh_recovery_delay_time_4(i_target, l_trfc_in_ps);
            break;
    }

    {
        // Calculate clock period (tCK) from selected freq from mss_freq
        int64_t l_tCK_in_ps = 0;
        FAPI_TRY( clock_period(i_target, l_tCK_in_ps) );

        {
            // Calculate refresh cycle time in nCK & set attribute
            const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
            const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

            uint8_t l_trfc_in_nck = 0;
            std::vector<uint8_t> l_mcs_attrs_trfc(PORTS_PER_MCS, 0);

            // Retrieve MCS attribute data
            FAPI_TRY( eff_dram_trfc(l_mcs, l_mcs_attrs_trfc.data()) );

            // Calculate nck
            l_trfc_in_nck = calc_nck(l_trfc_in_ps, l_tCK_in_ps, int64_t(INVERSE_DDR4_CORRECTION_FACTOR));

            // Update MCS attribute
            l_mcs_attrs_trfc[l_port_num] = uint8_t(l_trfc_in_nck);

            // casts vector into the type FAPI_ATTR_SET is expecting by deduction
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRFC,
                                    l_mcs,
                                    UINT8_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trfc, PORTS_PER_MCS)),
                      "Failed to set tRFC attribute");
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}
}// mss
