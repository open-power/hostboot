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
#include <lib/dimm/rank.H>
#include <lib/utils/conversions.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCBIST;

namespace mss
{

///
/// @brief Determines & sets effective config for DRAM generation from SPD
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_gen(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                       const std::vector<uint8_t>& i_spd_data )
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_decoder_val = 0;
    FAPI_TRY( spd::dram_device_type(i_target, i_spd_data, l_decoder_val) );

    // Get & update MCS attribute
    {
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
        const auto l_dimm_num = index(i_target);

        uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( eff_dram_gen(l_mcs, &l_mcs_attrs[0][0]) );

        l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_GEN, l_mcs, l_mcs_attrs) );
    }

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

    uint8_t l_decoder_val = 0;
    FAPI_TRY( spd::base_module_type(i_target, i_spd_data, l_decoder_val) );

    // Get & update MCS attribute
    {
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
        const auto l_dimm_num = index(i_target);

        uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( eff_dimm_type(l_mcs, &l_mcs_attrs[0][0]) );

        l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_TYPE, l_mcs, l_mcs_attrs) );
    }

fapi_try_exit:
    return fapi2::current_err;

}// dimm_type

///
/// @brief Determines & sets effective config for dram width
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_width(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_decoder_val = 0;
    FAPI_TRY( iv_pDecoder->device_width(i_target, l_decoder_val) );

    // Get & update MCS attribute
    {
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
        const auto l_dimm_num = index(i_target);

        uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( eff_dram_width(l_mcs, &l_mcs_attrs[0][0]) );

        // TK - RIT skeleton. Need to finish - BRS
        l_mcs_attrs[l_port_num][l_dimm_num] = 0x04;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_WIDTH, l_mcs, l_mcs_attrs) );
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Determines & sets effective config for dram density
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_density(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
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

        // TK - RIT skeleton. Need to finish - BRS
        l_mcs_attrs[l_port_num][l_dimm_num] = 0x04;
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
fapi2::ReturnCode eff_config::ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_decoder_val = 0;
    FAPI_TRY( iv_pDecoder->num_package_ranks_per_dimm(i_target, l_decoder_val) );

    // Get & update MCS attribute
    {
        const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
        const auto l_dimm_num = index(i_target);

        uint8_t l_attrs_ranks_per_dimm[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY(eff_num_ranks_per_dimm(l_mcs, &l_attrs_ranks_per_dimm[0][0]));

        // TK - RIT skeleton. Need to finish - BRS
        l_attrs_ranks_per_dimm[l_port_num][l_dimm_num] = 0x2;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_NUM_RANKS_PER_DIMM, l_mcs, l_attrs_ranks_per_dimm) );
    }

fapi_try_exit:
    return fapi2::current_err;


}

///
/// @brief Determines & sets effective config for number of master ranks per dimm
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::master_ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    uint8_t l_attrs_master_ranks_per_dimm[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY(eff_num_master_ranks_per_dimm(l_mcs, &l_attrs_master_ranks_per_dimm[0][0]));

    l_attrs_master_ranks_per_dimm[index(l_mca)][index(i_target)] = 0x02;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, l_mcs, l_attrs_master_ranks_per_dimm) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for stack type
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::primary_stack_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
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
fapi2::ReturnCode eff_config::dimm_size(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    // Get & update MCS attribute
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    uint32_t l_attrs_dimm_size[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( eff_dimm_size(l_mcs, &l_attrs_dimm_size[0][0]) );

    l_attrs_dimm_size[l_port_num][l_dimm_num] = 0x10;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_SIZE, l_mcs, l_attrs_dimm_size) );

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
    FAPI_TRY(iv_pDecoder->hybrid_media(i_target, l_decoder_val));

    // Get & update MCS attribute
    {
        uint8_t l_mcs_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
        FAPI_TRY( eff_hybrid_memory_type(l_mcs, &l_mcs_attrs[0][0]) );

        l_mcs_attrs[l_port_num][l_dimm_num] = l_decoder_val;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_HYBRID_MEMORY_TYPE, l_mcs, l_mcs_attrs) );
    }

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

    // Calculates appropriate tREFI based on fine refresh mode
    switch(l_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_NORMAL:
            FAPI_TRY( calc_trefi1(i_target, l_trefi_in_ps),
                      "Failed to calculate tREFI1" );
            break;

        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FLY_2X:
            FAPI_TRY( calc_trefi2(i_target, l_trefi_in_ps),
                      "Failed to calculate tREFI2" );
            break;

        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FLY_4X:
            FAPI_TRY( calc_trefi4(i_target, l_trefi_in_ps),
                      "Failed to calculate tREFI4" );
            break;

        default:
            // Fine Refresh Mode will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_FINE_REFRESH_MODE().
                        set_FINE_REF_MODE(l_refresh_mode),
                        "%s Incorrect Fine Refresh Mode received: %d ",
                        mss::c_str(i_target),
                        l_refresh_mode);

            break;
    }

    {
        // Calculate clock period (tCK) from selected freq from mss_freq
        uint64_t l_tCK_in_ps = 0;
        FAPI_TRY( clock_period(i_target, l_tCK_in_ps),
                  "Failed to calclate clock period");

        FAPI_DBG("Calculated clock period (tCK): %d", l_tCK_in_ps);

        {
            // Calculate refresh cycle time in nCK & set attribute
            const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
            const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

            std::vector<uint16_t> l_mcs_attrs_trefi(PORTS_PER_MCS, 0);
            uint16_t l_trefi_in_nck ;

            // Retrieve MCS attribute data
            FAPI_TRY( eff_dram_trefi(l_mcs, l_mcs_attrs_trefi.data()) );

            // Calculate nck
            l_trefi_in_nck = calc_nck(l_trefi_in_ps, l_tCK_in_ps, uint64_t(INVERSE_DDR4_CORRECTION_FACTOR));
            FAPI_DBG("Calculated tREFI (nck): %d", l_trefi_in_ps);

            // Update MCS attribute
            l_mcs_attrs_trefi[l_port_num] = l_trefi_in_nck;

            // TK - RIT skeleton. Need to finish - BRS
            // (note old calc resulted in 0x01 which seems really wrong in any event
            l_mcs_attrs_trefi[l_port_num] = 0x1249;

            // casts vector into the type FAPI_ATTR_SET is expecting by deduction
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TREFI,
                                    l_mcs,
                                    UINT16_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trefi, PORTS_PER_MCS)),
                      "Failed to set tREFI attribute");
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}// refresh_interval

///
/// @brief Determines & sets effective config for refresh cycle time (tRFC)
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::refresh_cycle_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    uint8_t l_refresh_mode = 0;
    int64_t l_trfc_in_ps = 0;

    FAPI_TRY ( mss::mrw_fine_refresh_mode(l_refresh_mode),
               "Failed to get MRW attribute for fine refresh mode" );

    // Selects appropriate tRFC based on fine refresh mode
    switch(l_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_NORMAL:
            FAPI_TRY( iv_pDecoder->min_refresh_recovery_delay_time_1(i_target, l_trfc_in_ps),
                      "Failed to decode SPD for tRFC1" );
            break;

        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FLY_2X:
            FAPI_TRY( iv_pDecoder->min_refresh_recovery_delay_time_2(i_target, l_trfc_in_ps),
                      "Failed to decode SPD for tRFC2" );
            break;

        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MRW_FINE_REFRESH_MODE_FLY_4X:
            FAPI_TRY( iv_pDecoder->min_refresh_recovery_delay_time_4(i_target, l_trfc_in_ps),
                      "Failed to decode SPD for tRFC4" );
            break;

        default:
            // Fine Refresh Mode will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_FINE_REFRESH_MODE().
                        set_FINE_REF_MODE(l_refresh_mode),
                        "%s Incorrect Fine Refresh Mode received: %d ",
                        mss::c_str(i_target),
                        l_refresh_mode);

            break;

    }// switch

    {
        // Calculate clock period (tCK) from selected freq from mss_freq
        int64_t l_tCK_in_ps = 0;
        FAPI_TRY( clock_period(i_target, l_tCK_in_ps),
                  "Failed to calculate clock period (tCK)");

        FAPI_DBG("Calculated clock period (tCK): %d", l_tCK_in_ps);
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
            l_trfc_in_nck = calc_nck(l_trfc_in_ps, l_tCK_in_ps, int64_t(INVERSE_DDR4_CORRECTION_FACTOR));
            FAPI_DBG("Calculated tRFC (nck): %d", l_trfc_in_nck);

            // Update MCS attribute
            l_mcs_attrs_trfc[l_port_num] = l_trfc_in_nck;

            // TK - RIT skeleton. Need to finish - BRS
            l_mcs_attrs_trfc[l_port_num] = 0x1A4;

            // casts vector into the type FAPI_ATTR_SET is expecting by deduction
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRFC,
                                    l_mcs,
                                    UINT16_VECTOR_TO_1D_ARRAY(l_mcs_attrs_trfc, PORTS_PER_MCS) ),
                      "Failed to set tRFC attribute" );
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Determines & sets effective config for refresh cycle time (logical ranks) (tRFC_DLR)
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::refresh_cycle_time_dlr(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );

    std::vector<uint8_t> l_mcs_attrs_trfc_dlr(PORTS_PER_MCS, 0);

    // Retrieve MCS attribute data
    FAPI_TRY( eff_dram_trfc_dlr(l_mcs, l_mcs_attrs_trfc_dlr.data()),
              "Failed to retrieve tRFC_DLR attribute" );

    // TK - RIT skeleton. Need to finish - BRS
    l_mcs_attrs_trfc_dlr[l_port_num] = 0x90;
    FAPI_DBG("Hardwired tRFC_DLR: %d", l_mcs_attrs_trfc_dlr[l_port_num]);

    // Update MCS attribute
    // casts vector into the type FAPI_ATTR_SET is expecting by deduction
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
fapi2::ReturnCode eff_config::rcd_mirror_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_mirror_mode[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_rcd_mirror_mode(l_mcs, &l_attrs_mirror_mode[0][0]) );
    l_attrs_mirror_mode[l_port_num][l_dimm_num] = 0x01;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_RCD_MIRROR_MODE, l_mcs, l_attrs_mirror_mode) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Determines & sets effective config for dram bank bits
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_bank_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_bank_bits[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_bank_bits(l_mcs, &l_attrs_bank_bits[0][0]) );
    l_attrs_bank_bits[l_port_num][l_dimm_num] = 0x04;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_BANK_BITS, l_mcs, l_attrs_bank_bits) );

fapi_try_exit:
    return fapi2::current_err;


}

///
/// @brief Determines & sets effective config for dram row bits
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_row_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_row_bits[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_row_bits(l_mcs, &l_attrs_row_bits[0][0]) );
    l_attrs_row_bits[l_port_num][l_dimm_num] = 0x10;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_ROW_BITS, l_mcs, l_attrs_row_bits) );
fapi_try_exit:
    return fapi2::current_err;


}

///
/// @brief Determines & sets effective config for custom dimm
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::custom_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    uint8_t l_attrs_custom_dimm[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY(eff_custom_dimm(l_mcs, &l_attrs_custom_dimm[0][0]));

    l_attrs_custom_dimm[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_CUSTOM_DIMM, l_mcs, l_attrs_custom_dimm) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Determines & sets effective config for tDQS
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_dqs_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dqs_time[PORTS_PER_MCS] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_tdqs(l_mcs, &l_attrs_dqs_time[0]) );
    l_attrs_dqs_time[l_port_num] = 0x01;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TDQS, l_mcs, l_attrs_dqs_time) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Determines & sets effective config for ODT RD
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::odt_read(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_attrs_odt_rd[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_odt_rd(l_mcs, &l_attrs_odt_rd[0][0][0]) );
    FAPI_TRY( mss::ranks(i_target, l_ranks) );
    FAPI_DBG("seeing %d ranks on %s", l_ranks.size(), mss::c_str(i_target));

    // Initialize all ranks on this DIMM to 0, then write values for ranks which exist.
    memset(&(l_attrs_odt_rd[l_port_num][l_dimm_num][0]), 0, MAX_RANK_PER_DIMM);

    // Replace with proper ODT calculation.
    for(const auto& l_rank : l_ranks)
    {
        FAPI_DBG("writing odt_rd[%d][%d][%d] for %s", l_port_num, l_dimm_num, index(l_rank), mss::c_str(i_target));
        l_attrs_odt_rd[l_port_num][l_dimm_num][index(l_rank)] = 0x00;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_ODT_RD, l_mcs, l_attrs_odt_rd) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for ODT WR
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::odt_write(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_attrs_odt_wr[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_odt_wr(l_mcs, &l_attrs_odt_wr[0][0][0]) );
    FAPI_TRY( mss::ranks(i_target, l_ranks) );
    FAPI_DBG("seeing %d ranks on %s", l_ranks.size(), mss::c_str(i_target));

    // Initialize all ranks on this DIMM to 0, then write values for ranks which exist.
    memset(&(l_attrs_odt_wr[l_port_num][l_dimm_num][0]), 0, MAX_RANK_PER_DIMM);

    for(const auto& l_rank : l_ranks)
    {
        uint8_t l_value = 0x0;

        // Complete hackery too keep in sync with the VBU attribute file - probably doesn't
        // matter at all for sim.
        if (l_dimm_num == 0)
        {
            l_value = (l_rank == 0) ? 0x40 : 0x80;
        }

        FAPI_DBG("writing odt_wr[%d][%d][%d] for %s", l_port_num, l_dimm_num, index(l_rank), mss::c_str(i_target));
        l_attrs_odt_wr[l_port_num][l_dimm_num][index(l_rank)] = l_value;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_ODT_WR, l_mcs, l_attrs_odt_wr) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tCCD_L
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_tccd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_tccd_l[PORTS_PER_MCS] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_tccd_l(l_mcs, &l_attrs_tccd_l[0]) );

    l_attrs_tccd_l[l_port_num] = 0x06;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TCCD_L, l_mcs, l_attrs_tccd_l) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for RTT Park
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::rtt_park(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    // Attribute to set num dimm ranks is a pre-requisite
    uint8_t l_attrs_rtt_park[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_rtt_park(l_mcs, &l_attrs_rtt_park[0][0][0]) );
    FAPI_TRY( mss::ranks(i_target, l_ranks) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_rtt_park[l_port_num][l_dimm_num][index(l_rank)] = 0x00;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_RTT_PARK, l_mcs, l_attrs_rtt_park) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC00
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc00[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc00(l_mcs, &l_attrs_dimm_rc00[0][0]) );
    l_attrs_dimm_rc00[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC00, l_mcs, l_attrs_dimm_rc00) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC01
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc01[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc01(l_mcs, &l_attrs_dimm_rc01[0][0]) );
    l_attrs_dimm_rc01[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC01, l_mcs, l_attrs_dimm_rc01) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC02
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc02[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc02(l_mcs, &l_attrs_dimm_rc02[0][0]) );
    l_attrs_dimm_rc02[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC02, l_mcs, l_attrs_dimm_rc02) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC03
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc03[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc03(l_mcs, &l_attrs_dimm_rc03[0][0]) );
    l_attrs_dimm_rc03[l_port_num][l_dimm_num] = 0x06;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC03, l_mcs, l_attrs_dimm_rc03) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC04
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc04[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc04(l_mcs, &l_attrs_dimm_rc04[0][0]) );
    l_attrs_dimm_rc04[l_port_num][l_dimm_num] = 0x05;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC04, l_mcs, l_attrs_dimm_rc04) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC05
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc05[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc05(l_mcs, &l_attrs_dimm_rc05[0][0]) );
    l_attrs_dimm_rc05[l_port_num][l_dimm_num] = 0x05;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC05, l_mcs, l_attrs_dimm_rc05) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC06_07
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc06_07(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc06_07[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc06_07(l_mcs, &l_attrs_dimm_rc06_07[0][0]) );
    l_attrs_dimm_rc06_07[l_port_num][l_dimm_num] = 0xf;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC06_07, l_mcs, l_attrs_dimm_rc06_07) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC08
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc08(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc08[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc08(l_mcs, &l_attrs_dimm_rc08[0][0]) );
    l_attrs_dimm_rc08[l_port_num][l_dimm_num] = 0x3;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC08, l_mcs, l_attrs_dimm_rc08) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC09
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc09(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc09[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc09(l_mcs, &l_attrs_dimm_rc09[0][0]) );
    l_attrs_dimm_rc09[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC09, l_mcs, l_attrs_dimm_rc09) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC10
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc10(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc10[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc10(l_mcs, &l_attrs_dimm_rc10[0][0]) );
    l_attrs_dimm_rc10[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC10, l_mcs, l_attrs_dimm_rc10) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC11
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc11(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc11[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc11(l_mcs, &l_attrs_dimm_rc11[0][0]) );
    l_attrs_dimm_rc11[l_port_num][l_dimm_num] = 0xe;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC11, l_mcs, l_attrs_dimm_rc11) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC12
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc12(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc12[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc12(l_mcs, &l_attrs_dimm_rc12[0][0]) );
    l_attrs_dimm_rc12[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC12, l_mcs, l_attrs_dimm_rc12) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC13
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc13(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc13[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc13(l_mcs, &l_attrs_dimm_rc13[0][0]) );
    l_attrs_dimm_rc13[l_port_num][l_dimm_num] = 0xC;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC13, l_mcs, l_attrs_dimm_rc13) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC14
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc14(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc14[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc14(l_mcs, &l_attrs_dimm_rc14[0][0]) );
    l_attrs_dimm_rc14[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC14, l_mcs, l_attrs_dimm_rc14) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for DIMM RC15
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc15(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc15[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc15(l_mcs, &l_attrs_dimm_rc15[0][0]) );
    l_attrs_dimm_rc15[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC15, l_mcs, l_attrs_dimm_rc15) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_1x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc1x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_1x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_1x(l_mcs, &l_attrs_dimm_rc_1x[0][0]) );
    l_attrs_dimm_rc_1x[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_1x, l_mcs, l_attrs_dimm_rc_1x) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_2x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc2x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_2x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_2x(l_mcs, &l_attrs_dimm_rc_2x[0][0]) );
    l_attrs_dimm_rc_2x[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_2x, l_mcs, l_attrs_dimm_rc_2x) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_3x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc3x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_3x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_3x(l_mcs, &l_attrs_dimm_rc_3x[0][0]) );
    l_attrs_dimm_rc_3x[l_port_num][l_dimm_num] = 0x39;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_3x, l_mcs, l_attrs_dimm_rc_3x) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_4x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc4x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_4x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_4x(l_mcs, &l_attrs_dimm_rc_4x[0][0]) );
    l_attrs_dimm_rc_4x[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_4x, l_mcs, l_attrs_dimm_rc_4x) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_5x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc5x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_5x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_5x(l_mcs, &l_attrs_dimm_rc_5x[0][0]) );
    l_attrs_dimm_rc_5x[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_5x, l_mcs, l_attrs_dimm_rc_5x) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_6x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc6x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_6x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_6x(l_mcs, &l_attrs_dimm_rc_6x[0][0]) );
    l_attrs_dimm_rc_6x[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_6x, l_mcs, l_attrs_dimm_rc_6x) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_7x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc7x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_7x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_7x(l_mcs, &l_attrs_dimm_rc_7x[0][0]) );
    l_attrs_dimm_rc_7x[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_7x, l_mcs, l_attrs_dimm_rc_7x) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_8x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc8x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_8x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_8x(l_mcs, &l_attrs_dimm_rc_8x[0][0]) );
    l_attrs_dimm_rc_8x[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_8x, l_mcs, l_attrs_dimm_rc_8x) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_9x
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rc9x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_9x[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_9x(l_mcs, &l_attrs_dimm_rc_9x[0][0]) );
    l_attrs_dimm_rc_9x[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_9x, l_mcs, l_attrs_dimm_rc_9x) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_AX
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rcax(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_ax[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_ax(l_mcs, &l_attrs_dimm_rc_ax[0][0]) );
    l_attrs_dimm_rc_ax[l_port_num][l_dimm_num] = 0x00;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_Ax, l_mcs, l_attrs_dimm_rc_ax) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for DIMM RC_BX
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dimm_rcbx(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dimm_rc_bx[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dimm_ddr4_rc_bx(l_mcs, &l_attrs_dimm_rc_bx[0][0]) );
    l_attrs_dimm_rc_bx[l_port_num][l_dimm_num] = 0x07;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_DDR4_RC_Bx, l_mcs, l_attrs_dimm_rc_bx) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for tWR
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_twr(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_twr(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_twr(l_mcs, l_attrs_twr.data()) );

    l_attrs_twr[l_port_num] = 0x12;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWR,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_twr, PORTS_PER_MCS)),
              "Failed setting attribute for tWR");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for burst length (BL)
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::burst_length(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_bl(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_bl(l_mcs, l_attrs_bl.data()) );

    l_attrs_bl[l_port_num] = 0x00;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_BL,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_bl, PORTS_PER_MCS)),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for RBT
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::read_burst_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_rbt[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_rbt(l_mcs, &l_attrs_rbt[0][0]) );

    l_attrs_rbt[l_port_num][l_dimm_num] = 0x00;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RBT, l_mcs, l_attrs_rbt),
              "Failed setting attribute for RTB");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for TM
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_tm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_tm[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_tm(l_mcs, &l_attrs_tm[0][0]) );

    l_attrs_tm[l_port_num][l_dimm_num] = 0x00;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TM, l_mcs, l_attrs_tm),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Determines & sets effective config for cwl
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_cwl(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_cwl(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_cwl(l_mcs, l_attrs_cwl.data()) );

    l_attrs_cwl[l_port_num] = 0x0C;
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
///
fapi2::ReturnCode eff_config::dram_lpasr(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_lpasr(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_lpasr(l_mcs, l_attrs_lpasr.data()) );

    l_attrs_lpasr[l_port_num] = 0x00;
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
fapi2::ReturnCode eff_config::additive_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_dram_al(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_al(l_mcs, l_attrs_dram_al.data()) );

    l_attrs_dram_al[l_port_num] = 0x00;
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
fapi2::ReturnCode eff_config::dll_reset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dll_reset[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_dll_reset(l_mcs, &l_attrs_dll_reset[0][0]) );

    l_attrs_dll_reset[l_port_num][l_dimm_num] = 0x01;

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
fapi2::ReturnCode eff_config::dll_enable(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dll_enable[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_dll_enable(l_mcs, &l_attrs_dll_enable[0][0]) );

    l_attrs_dll_enable[l_port_num][l_dimm_num] = 0x00;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_DLL_ENABLE, l_mcs, l_attrs_dll_enable),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for RON
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::dram_ron(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dram_ron[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_dram_ron(l_mcs, &l_attrs_dram_ron[0][0]) );

    l_attrs_dram_ron[l_port_num][l_dimm_num] = 0x22;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RON, l_mcs, l_attrs_dram_ron),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for RTT NOM
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::rtt_nom(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_attrs_rtt_nom[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( mss::ranks(i_target, l_ranks) );
    FAPI_TRY( eff_dram_rtt_nom(l_mcs, &l_attrs_rtt_nom[0][0][0]) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_rtt_nom[l_port_num][l_dimm_num][index(l_rank)] = 0x28;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RTT_NOM, l_mcs, l_attrs_rtt_nom),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for Write Level Enable
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::write_level_enable(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_wr_lvl_enable(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_wr_lvl_enable(l_mcs, l_attrs_wr_lvl_enable.data()) );

    l_attrs_wr_lvl_enable[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::output_buffer(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_output_buffer(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_dram_output_buffer(l_mcs, l_attrs_output_buffer.data()) );

    l_attrs_output_buffer[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::vref_dq_train_value(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_attrs_vref_dq_train_val[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    // Attribute to set num dimm ranks is a pre-requisite
    FAPI_TRY( eff_vref_dq_train_value(l_mcs, &l_attrs_vref_dq_train_val[0][0][0]) );
    FAPI_TRY( mss::ranks(i_target, l_ranks) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_vref_dq_train_val[l_port_num][l_dimm_num][index(l_rank)] = 0x10;
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
fapi2::ReturnCode eff_config::vref_dq_train_enable(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_attrs_vref_dq_train_enable[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    // Attribute to set num dimm ranks is a pre-requisite
    FAPI_TRY( eff_vref_dq_train_enable(l_mcs, &l_attrs_vref_dq_train_enable[0][0][0]) );
    FAPI_TRY( mss::ranks(i_target, l_ranks) );

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
fapi2::ReturnCode eff_config::vref_dq_train_range(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    // Attribute to set num dimm ranks is a pre-requisite
    uint8_t l_attrs_vref_dq_train_range[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    FAPI_TRY( eff_vref_dq_train_range(l_mcs, &l_attrs_vref_dq_train_range[0][0][0]) );
    FAPI_TRY( mss::ranks(i_target, l_ranks) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_vref_dq_train_range[l_port_num][l_dimm_num][index(l_rank)] = 0x00;
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
fapi2::ReturnCode eff_config::ca_parity_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_ca_parity_latency(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_ca_parity_latency(l_mcs, l_attrs_ca_parity_latency.data()) );

    l_attrs_ca_parity_latency[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::crc_error_clear(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_crc_error_clear(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_crc_error_clear(l_mcs, l_attrs_crc_error_clear.data()) );

    l_attrs_crc_error_clear[l_port_num] = 0x01;

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
fapi2::ReturnCode eff_config::ca_parity_error_status(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_ca_parity_error_status(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_ca_parity_error_status(l_mcs, l_attrs_ca_parity_error_status.data()) );

    l_attrs_ca_parity_error_status[l_port_num] = 0x01;

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
fapi2::ReturnCode eff_config::ca_parity(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_ca_parity(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_ca_parity(l_mcs, l_attrs_ca_parity.data()) );

    l_attrs_ca_parity[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::odt_input_buffer(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_odt_input_buffer(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_odt_input_buff(l_mcs, l_attrs_odt_input_buffer.data()) );

    l_attrs_odt_input_buffer[l_port_num] = 0x01;

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
///
fapi2::ReturnCode eff_config::data_mask(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_data_mask(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_data_mask(l_mcs, l_attrs_data_mask.data()) );

    l_attrs_data_mask[l_port_num] = 0x00;

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
///
fapi2::ReturnCode eff_config::write_dbi(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_write_dbi(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_write_dbi(l_mcs, l_attrs_write_dbi.data()) );

    l_attrs_write_dbi[l_port_num] = 0x00;

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
///
fapi2::ReturnCode eff_config::read_dbi(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_read_dbi(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_read_dbi(l_mcs, l_attrs_read_dbi.data()) );

    l_attrs_read_dbi[l_port_num] = 0x00;

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
///
fapi2::ReturnCode eff_config::post_package_repair(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    uint8_t l_attrs_dram_ppr[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);
    const auto l_dimm_num = index(i_target);

    // Port level?
    FAPI_TRY( eff_dram_ppr(l_mcs, &l_attrs_dram_ppr[0][0]) );

    l_attrs_dram_ppr[l_port_num][l_dimm_num] = 0x00;

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
fapi2::ReturnCode eff_config::read_preamble_train(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_rd_preamble_train(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_rd_preamble_train(l_mcs, l_attrs_rd_preamble_train.data()) );

    l_attrs_rd_preamble_train[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::read_preamble(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_rd_preamble(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_rd_preamble(l_mcs, l_attrs_rd_preamble.data()) );

    l_attrs_rd_preamble[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::write_preamble(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_wr_preamble(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_wr_preamble(l_mcs, l_attrs_wr_preamble.data()) );

    l_attrs_wr_preamble[l_port_num] = 0x00;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_WR_PREAMBLE,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_wr_preamble, PORTS_PER_MCS)),
              "Failed setting attribute for WR_PREAMBLE");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for self_ref_abort
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::self_refresh_abort(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_self_ref_abort(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_self_ref_abort(l_mcs, l_attrs_self_ref_abort.data()) );

    l_attrs_self_ref_abort[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::cs_to_cmd_addr_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_cs_cmd_latency(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_cs_cmd_latency(l_mcs, l_attrs_cs_cmd_latency.data()) );

    l_attrs_cs_cmd_latency[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::internal_vref_monitor(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_int_vref_mon(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_internal_vref_monitor(l_mcs, l_attrs_int_vref_mon.data()) );

    l_attrs_int_vref_mon[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::max_powerdown_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_powerdown_mode(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_max_powerdown_mode(l_mcs, l_attrs_powerdown_mode.data()) );

    l_attrs_powerdown_mode[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::mpr_read_format(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_mpr_rd_format(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_mpr_rd_format(l_mcs, l_attrs_mpr_rd_format.data()) );

    l_attrs_mpr_rd_format[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::crc_wr_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_crc_wr_latency(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_crc_wr_latency(l_mcs, l_attrs_crc_wr_latency.data()) );

    l_attrs_crc_wr_latency[l_port_num] = 0x04;

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
fapi2::ReturnCode eff_config::temp_readout(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_temp_readout(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_temp_readout(l_mcs, l_attrs_temp_readout.data()) );

    l_attrs_temp_readout[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::per_dram_addressability(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_per_dram_access(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_per_dram_access(l_mcs, l_attrs_per_dram_access.data()) );

    l_attrs_per_dram_access[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::geardown_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_geardown_mode(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_geardown_mode(l_mcs, l_attrs_geardown_mode.data()) );

    l_attrs_geardown_mode[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::mpr_page(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_mpr_page(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_mpr_page(l_mcs, l_attrs_mpr_page.data()) );

    l_attrs_mpr_page[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::mpr_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_mpr_mode(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_mpr_mode(l_mcs, l_attrs_mpr_mode.data()) );

    l_attrs_mpr_mode[l_port_num] = 0x00;

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
fapi2::ReturnCode eff_config::write_crc(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint8_t> l_attrs_write_crc(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_write_crc(l_mcs, l_attrs_write_crc.data()) );

    l_attrs_write_crc[l_port_num] = 0x00;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_WRITE_CRC,
                            l_mcs,
                            UINT8_VECTOR_TO_1D_ARRAY(l_attrs_write_crc, PORTS_PER_MCS)),
              "Failed setting attribute for WRITE_CRC");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for RTT Write
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::rtt_write(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);

    uint8_t l_attrs_rtt_wr[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    std::vector< uint64_t > l_ranks;

    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    // Attribute to set num dimm ranks is a pre-requisite
    FAPI_TRY( eff_dram_rtt_wr(l_mcs, &l_attrs_rtt_wr[0][0][0]) );
    FAPI_TRY( mss::ranks(i_target, l_ranks) );

    for(const auto& l_rank : l_ranks)
    {
        l_attrs_rtt_wr[l_port_num][l_dimm_num][index(l_rank)] = 0x00;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RTT_WR, l_mcs, l_attrs_rtt_wr),
              "Failed setting attribute for BL");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines & sets effective config for ZQ Calibration
/// @param[in] i_target FAPI2 target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode eff_config::zqcal_interval(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint32_t> l_attrs_zqcal_interval(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_zqcal_interval(l_mcs, l_attrs_zqcal_interval.data()) );


    // Calculate ZQCAL Interval based on the following equation from Ken:
    //               0.5
    // ------------------------------ = 13.333ms
    //     (1.5 * 10) + (0.15 * 150)
    //  (13333 * ATTR_MSS_FREQ) / 2
    l_attrs_zqcal_interval[l_port_num] = 0xF42270;

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
fapi2::ReturnCode eff_config::memcal_interval(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // TK - RIT skeleton. Need to finish - AAM
    std::vector<uint32_t> l_attrs_memcal_interval(PORTS_PER_MCS, 0);

    // Targets
    const auto l_mcs = find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_mca = find_target<TARGET_TYPE_MCA>(i_target);

    // Current index
    const auto l_port_num = index(l_mca);

    FAPI_TRY( eff_memcal_interval(l_mcs, l_attrs_memcal_interval.data()) );

    // Calculate MEMCAL Interval based on 1sec interval across all bits per DP16
    // (62500 * ATTR_MSS_FREQ) / 2
    l_attrs_memcal_interval[l_port_num] = 0x47868C0;

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_MEMCAL_INTERVAL,
                            l_mcs,
                            UINT32_VECTOR_TO_1D_ARRAY(l_attrs_memcal_interval, PORTS_PER_MCS)),
              "Failed setting attribute for MEMCAL_INTERVAL");
fapi_try_exit:
    return fapi2::current_err;
}

}// mss
