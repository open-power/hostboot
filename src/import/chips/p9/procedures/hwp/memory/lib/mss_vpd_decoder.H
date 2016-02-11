/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mss_vpd_decoder.H $        */
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
// mss_vpd_decoder.H
#ifndef MSS_VPD_ACCESS_H_
#define MSS_VPD_ACCESS_H_

#include <fapi2.H>
#include <mss_utils.H>
#include <mss.H>

namespace mss
{
namespace decoder
{

// VPD Keyword Version Byte: 00
///
/// @brief ATTR_VPD_MT_0_VERSION_LAYOUT decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_0_version_layout(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 0, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_0_VERSION_LAYOUT, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_0_VERSION_LAYOUT start: 0, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_1_VERSION_DATA decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_1_version_data(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 1, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_1_VERSION_DATA, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_1_VERSION_DATA start: 1, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_2_SIGNATURE_DIMM0RANK_DIMM1RANK decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_2_signature_dimm0rank_dimm1rank(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>&
        i_target, const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 2, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_2_SIGNATURE_DIMM0RANK_DIMM1RANK, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_2_SIGNATURE_DIMM0RANK_DIMM1RANK start: 2, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_CKE_PRI_MAP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_cke_pri_map(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint16_t l_value[2];

    memcpy(&l_value, i_blob + 3, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_CKE_PRI_MAP, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_CKE_PRI_MAP start: 3, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_CKE_PWR_MAP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_cke_pwr_map(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint32_t l_value[2];

    memcpy(&l_value, i_blob + 7, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_CKE_PWR_MAP, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_CKE_PWR_MAP start: 7, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_DIMM_RCD_IBT decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_dimm_rcd_ibt(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2];

    memcpy(&l_value, i_blob + 15, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_DIMM_RCD_IBT, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_DIMM_RCD_IBT start: 15, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_DIMM_RCD_OUTPUT_TIMING decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_dimm_rcd_output_timing(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2];

    memcpy(&l_value, i_blob + 19, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_DIMM_RCD_OUTPUT_TIMING, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_DIMM_RCD_OUTPUT_TIMING start: 19, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_DRAM_DRV_IMP_DQ_DQS decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_dram_drv_imp_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 23, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_DRAM_DRV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_DRAM_DRV_IMP_DQ_DQS start: 23, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_DRAM_RTT_NOM decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_dram_rtt_nom(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 31, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_DRAM_RTT_NOM, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_DRAM_RTT_NOM start: 31, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_DRAM_RTT_PARK decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_dram_rtt_park(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 39, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_DRAM_RTT_PARK, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_DRAM_RTT_PARK start: 39, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_DRAM_RTT_WR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_dram_rtt_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 47, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_DRAM_RTT_WR, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_DRAM_RTT_WR start: 47, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_DRV_IMP_ADDR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_addr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 55, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_DRV_IMP_ADDR, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_DRV_IMP_ADDR start: 55, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_DRV_IMP_CLK decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_clk(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 57, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_DRV_IMP_CLK, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_DRV_IMP_CLK start: 57, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_DRV_IMP_CNTL decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_cntl(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 59, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_DRV_IMP_CNTL, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_DRV_IMP_CNTL start: 59, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_DRV_IMP_DQ_DQS decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 61, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_DRV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_DRV_IMP_DQ_DQS start: 61, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_DRV_IMP_SPCKE decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_spcke(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 63, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_DRV_IMP_SPCKE, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_DRV_IMP_SPCKE start: 63, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_RCV_IMP_DQ_DQS decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_rcv_imp_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 65, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_RCV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_RCV_IMP_DQ_DQS start: 65, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_SLEW_RATE_ADDR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_slew_rate_addr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 67, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_SLEW_RATE_ADDR, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_SLEW_RATE_ADDR start: 67, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_SLEW_RATE_CLK decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_slew_rate_clk(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 69, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_SLEW_RATE_CLK, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_SLEW_RATE_CLK start: 69, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_SLEW_RATE_CNTL decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_slew_rate_cntl(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 71, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_SLEW_RATE_CNTL, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_SLEW_RATE_CNTL start: 71, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_SLEW_RATE_DQ_DQS decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_slew_rate_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 73, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_SLEW_RATE_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_SLEW_RATE_DQ_DQS start: 73, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_MC_SLEW_RATE_SPCKE decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_mc_slew_rate_spcke(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 75, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_MC_SLEW_RATE_SPCKE, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_MC_SLEW_RATE_SPCKE start: 75, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_ODT_RD decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_odt_rd(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 77, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_ODT_RD, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_ODT_RD start: 77, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_ODT_WR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_odt_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 85, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_ODT_WR, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_ODT_WR start: 85, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_OFFSET_GPO decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_offset_gpo(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 93, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_OFFSET_GPO, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_OFFSET_GPO start: 93, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_OFFSET_RLO decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_offset_rlo(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 95, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_OFFSET_RLO, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_OFFSET_RLO start: 95, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_OFFSET_WLO decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_offset_wlo(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 97, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_OFFSET_WLO, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_OFFSET_WLO start: 97, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_VREF_DRAM_WR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_vref_dram_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 99, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_VREF_DRAM_WR, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_VREF_DRAM_WR start: 99, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_VREF_MC_RD decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_vref_mc_rd(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 101, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_VREF_MC_RD, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_VREF_MC_RD start: 101, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MT_WINDAGE_RD_CTR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mt_windage_rd_ctr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint16_t l_value[2];

    memcpy(&l_value, i_blob + 103, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MT_WINDAGE_RD_CTR, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MT_WINDAGE_RD_CTR start: 103, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}


// VPD Keyword Version Byte: 00
///
/// @brief ATTR_VPD_MR_0_VERSION_LAYOUT decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MR Keyword Layout Version Number.  Increases when attributes are added, removed,
/// or redefined.  Does not
/// reset.
///
inline fapi2::ReturnCode vpd_mr_0_version_layout(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 0, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_0_VERSION_LAYOUT, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_0_VERSION_LAYOUT start: 0, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_1_VERSION_DATA decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MR Keyword Data Version Number.  Increases when data changes with the above
/// layout version.  Resets when layout version number
/// increments.
///
inline fapi2::ReturnCode vpd_mr_1_version_data(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 1, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_1_VERSION_DATA, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_1_VERSION_DATA start: 1, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_2_SIGNATURE_FREQ_DROP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MR Keyword type, nibble 0 = freq bin (0 = 1600, 1 = 1866, 2 = 2133, 3 = 2400, 4
/// = 2667, 5 = 2933, 6 = 3200), nibble 1 = num dimms per port (1 = single drop, 2 =
/// dual
/// drop)
///
inline fapi2::ReturnCode vpd_mr_2_signature_freq_drop(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 2, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_2_SIGNATURE_FREQ_DROP, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_2_SIGNATURE_FREQ_DROP start: 2, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_DRAM_2N_MODE decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_dram_2n_mode(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 3, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_DRAM_2N_MODE, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_DRAM_2N_MODE start: 3, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A00 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a00(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 5, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A00, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A00 start: 5, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A01 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a01(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 7, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A01, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A01 start: 7, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A02 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a02(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 9, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A02, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A02 start: 9, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A03 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a03(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 11, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A03, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A03 start: 11, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A04 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a04(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 13, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A04, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A04 start: 13, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A05 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a05(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 15, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A05, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A05 start: 15, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A06 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a06(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 17, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A06, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A06 start: 17, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A07 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a07(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 19, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A07, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A07 start: 19, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A08 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a08(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 21, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A08, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A08 start: 21, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A09 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a09(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 23, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A09, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A09 start: 23, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A10 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a10(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 25, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A10, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A10 start: 25, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A11 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a11(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 27, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A11, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A11 start: 27, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A12 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a12(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 29, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A12, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A12 start: 29, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A13 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a13(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 31, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A13, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A13 start: 31, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A17 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a17(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 33, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A17, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_A17 start: 33, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BA0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_ba0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 35, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BA0, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BA0 start: 35, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BA1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_ba1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 37, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BA1, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BA1 start: 37, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BG0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_bg0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 39, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BG0, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BG0 start: 39, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BG1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_bg1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 41, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BG1, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_BG1 start: 41, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_C0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_c0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 43, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_C0, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_C0 start: 43, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_C1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_c1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 45, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_C1, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_C1 start: 45, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_ADDR_C2 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_c2(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 47, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_ADDR_C2, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_ADDR_C2 start: 47, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CLK_D0_P0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_clk_d0_p0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 49, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CLK_D0_P0, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CLK_D0_P0 start: 49, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CLK_D0_P1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_clk_d0_p1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 51, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CLK_D0_P1, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CLK_D0_P1 start: 51, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CLK_D1_P0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_clk_d1_p0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 53, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CLK_D1_P0, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CLK_D1_P0 start: 53, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CLK_D1_P1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_clk_d1_p1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 55, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CLK_D1_P1, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CLK_D1_P1 start: 55, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CMD_ACTN decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_actn(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 57, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CMD_ACTN, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CMD_ACTN start: 57, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_addr_casn_a15(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 59, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15 start: 59, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_addr_rasn_a16(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 61, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16 start: 61, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_addr_wen_a14(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 63, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14 start: 63, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CMD_PAR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_par(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 65, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CMD_PAR, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CMD_PAR start: 65, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_cke0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 67, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE0, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE0 start: 67, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_cke1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 69, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE1, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE1 start: 69, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE2 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_cke2(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 71, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE2, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE2 start: 71, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE3 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_cke3(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 73, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE3, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CKE3 start: 73, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_csn0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 75, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN0, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN0 start: 75, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_csn1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 77, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN1, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN1 start: 77, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN2 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_csn2(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 79, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN2, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN2 start: 79, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN3 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_csn3(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 81, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN3, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_CSN3 start: 81, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_odt0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 83, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT0, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT0 start: 83, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_odt1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 85, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT1, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT1 start: 85, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT2 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_odt2(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 87, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT2, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT2 start: 87, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT3 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_odt3(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 89, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT3, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_MC_PHASE_ROT_CNTL_ODT3 start: 89, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_PERIODIC_MEMCAL_MODE_OPTIONS decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_periodic_memcal_mode_options(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint16_t l_value[2];

    memcpy(&l_value, i_blob + 91, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_PERIODIC_MEMCAL_MODE_OPTIONS, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_PERIODIC_MEMCAL_MODE_OPTIONS start: 91, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_TSYS_ADR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_tsys_adr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 95, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_TSYS_ADR, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_TSYS_ADR start: 95, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_VPD_MR_TSYS_DATA decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
///
inline fapi2::ReturnCode vpd_mr_tsys_data(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 97, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_VPD_MR_TSYS_DATA, i_target, l_value),
              "Unable to decode and set ATTR_VPD_MR_TSYS_DATA start: 97, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

}; // close decoder ns

///
/// @brief eff_decode
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_mt_blob the MT VPD blob for this MCS
/// @param[in] i_mr_blob the MR VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note Decodes the blobs and sets all the attributes.
///
inline fapi2::ReturnCode eff_decode(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_mt_blob,
                                    const uint8_t* i_mr_blob)
{
    FAPI_TRY (decoder::vpd_mt_0_version_layout(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_1_version_data(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_2_signature_dimm0rank_dimm1rank(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_cke_pri_map(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_cke_pwr_map(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dimm_rcd_ibt(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dimm_rcd_output_timing(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dram_drv_imp_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dram_rtt_nom(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dram_rtt_park(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dram_rtt_wr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_addr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_clk(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_cntl(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_spcke(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_rcv_imp_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_slew_rate_addr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_slew_rate_clk(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_slew_rate_cntl(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_slew_rate_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_slew_rate_spcke(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_odt_rd(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_odt_wr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_offset_gpo(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_offset_rlo(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_offset_wlo(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_vref_dram_wr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_vref_mc_rd(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_windage_rd_ctr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mr_0_version_layout(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_1_version_data(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_2_signature_freq_drop(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_dram_2n_mode(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a00(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a01(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a02(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a03(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a04(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a05(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a06(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a07(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a08(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a09(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a10(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a11(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a12(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a13(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a17(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_ba0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_ba1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_bg0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_bg1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_c0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_c1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_c2(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_clk_d0_p0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_clk_d0_p1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_clk_d1_p0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_clk_d1_p1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_actn(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_addr_casn_a15(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_addr_rasn_a16(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_addr_wen_a14(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_par(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_cke0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_cke1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_cke2(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_cke3(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_csn0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_csn1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_csn2(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_csn3(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_odt0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_odt1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_odt2(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_odt3(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_periodic_memcal_mode_options(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_tsys_adr(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_tsys_data(i_target, i_mr_blob) );

fapi_try_exit:
    return fapi2::current_err;
}


} // close ns mss
#endif