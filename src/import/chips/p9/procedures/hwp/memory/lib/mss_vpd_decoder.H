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
/// @brief ATTR_MSS_VPD_MR_0_VERSION_LAYOUT decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MR Keyword Layout Version Number.  Increases when attributes are added, removed,
/// or redefined.  Does not
/// reset.
///
inline fapi2::ReturnCode mss_vpd_mr_0_version_layout(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 0, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_0_VERSION_LAYOUT, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_0_VERSION_LAYOUT start: 0, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_1_VERSION_DATA decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MR Keyword Data Version Number.  Increases when data changes with the above
/// layout version.  Resets when layout version number
/// increments.
///
inline fapi2::ReturnCode mss_vpd_mr_1_version_data(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 1, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_1_VERSION_DATA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_1_VERSION_DATA start: 1, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_2_SIGNATURE_HASH decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Hash Signature for the MT Keyword. The hash signature is 32bits for 256 bytes of
/// data.
///
inline fapi2::ReturnCode mss_vpd_mr_2_signature_hash(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint32_t l_value;

    memcpy(&l_value, i_blob + 2, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_2_SIGNATURE_HASH, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_2_SIGNATURE_HASH start: 2, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a00(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 6, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00 start: 6, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A01 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a01(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 8, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A01, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A01 start: 8, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A02 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a02(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 10, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A02, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A02 start: 10, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A03 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a03(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 12, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A03, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A03 start: 12, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A04 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a04(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 14, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A04, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A04 start: 14, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A05 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a05(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 16, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A05, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A05 start: 16, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A06 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a06(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 18, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A06, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A06 start: 18, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A07 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a07(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 20, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A07, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A07 start: 20, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A08 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a08(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 22, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A08, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A08 start: 22, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A09 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a09(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 24, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A09, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A09 start: 24, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A10 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a10(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 26, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A10, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A10 start: 26, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A11 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a11(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 28, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A11, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A11 start: 28, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A12 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a12(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 30, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A12, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A12 start: 30, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A13 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a13(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 32, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A13, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A13 start: 32, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A17 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_a17(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 34, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A17, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A17 start: 34, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Bank Address of BA# in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_ba0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 36, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA0 start: 36, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Bank Address of BA# in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_ba1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 38, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA1 start: 38, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Bank Group of BG# in ticks. Ticks are 1/128 of one
/// cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_bg0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 40, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG0 start: 40, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Bank Group of BA# in ticks. Ticks are 1/128 of one
/// cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_bg1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 42, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG1 start: 42, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip ID of C# in ticks. Only used in TSV Dimms.
/// Ticks are 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_c0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 44, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C0 start: 44, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip ID of C# in ticks. Only used in TSV Dimms.
/// Ticks are 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_c1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 46, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C1 start: 46, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C2 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip ID of C# in ticks. Only used in TSV Dimms.
/// Ticks are 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_addr_c2(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 48, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C2, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C2 start: 48, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLK0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock for Dimm#_CLK# in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_d0_clk0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 50, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLK0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLK0 start: 50, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLK1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock for Dimm#_CLK# in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_d0_clk1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 52, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLK1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLK1 start: 52, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLK0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock for Dimm#_CLK# in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_d1_clk0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 54, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLK0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLK0 start: 54, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLK1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock for Dimm#_CLK# in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_d1_clk1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 56, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLK1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLK1 start: 56, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ACTN decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Activate for ACTN in ticks. Ticks are 1/128 of one
/// cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cmd_actn(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 58, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ACTN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ACTN start: 58, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Column Access Strobe for CASN in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cmd_addr_casn_a15(const fapi2::Target<fapi2::TARGET_TYPE_MCS>&
        i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 60, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15 start: 60, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Row Access Strobe for RASN in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cmd_addr_rasn_a16(const fapi2::Target<fapi2::TARGET_TYPE_MCS>&
        i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 62, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16 start: 62, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Write Enable for WEN in ticks. Ticks are 1/128 of
/// one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cmd_addr_wen_a14(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 64, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14 start: 64, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_PAR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of the Parity Input for PAR in ticks. Ticks are 1/128
/// of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cmd_par(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 66, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_PAR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_PAR start: 66, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock Enable for Dimm#_CKE# in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d0_cke0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 68, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE0 start: 68, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock Enable for Dimm#_CKE# in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d0_cke1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 70, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE1 start: 70, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock Enable for Dimm#_CKE# in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d1_cke0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 72, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE0 start: 72, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock Enable for Dimm#_CKE# in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d1_cke1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 74, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE1 start: 74, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip Select for Dimm#_CSN# in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d0_csn0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 76, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN0 start: 76, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip Select for Dimm#_CSN# in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d0_csn1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 78, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN1 start: 78, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip Select for Dimm#_CSN# in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d1_csn0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 80, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN0 start: 80, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip Select for Dimm#_CSN# in ticks. Ticks are
/// 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d1_csn1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 82, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN1 start: 82, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of On Die Termination for Dimm#_ODT# in ticks. Ticks
/// are 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d0_odt0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 84, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT0 start: 84, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of On Die Termination for Dimm#_ODT# in ticks. Ticks
/// are 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d0_odt1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 86, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT1 start: 86, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of On Die Termination for Dimm#_ODT# in ticks. Ticks
/// are 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d1_odt0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 88, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT0 start: 88, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of On Die Termination for Dimm#_ODT# in ticks. Ticks
/// are 1/128 of one cycle of
/// clock.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_phase_rot_cntl_d1_odt1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 90, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT1 start: 90, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Default value for 2N Mode from Signal
/// Integrity.
///
inline fapi2::ReturnCode mss_vpd_mr_mc_2n_mode_autoset(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 92, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET start: 92, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}


// VPD Keyword Version Byte: 00
///
/// @brief ATTR_MSS_VPD_MT_0_VERSION_LAYOUT decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MT Keyword Layout Version Number.  Increases when attributes are added, removed,
/// or redefined.  Does not
/// reset.
///
inline fapi2::ReturnCode mss_vpd_mt_0_version_layout(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 0, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_0_VERSION_LAYOUT, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_0_VERSION_LAYOUT start: 0, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_1_VERSION_DATA decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MT Keyword Data Version Number.  Increases when data changes with the above
/// layout version.  Resets when layout version number
/// increments.
///
inline fapi2::ReturnCode mss_vpd_mt_1_version_data(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value;

    memcpy(&l_value, i_blob + 1, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_1_VERSION_DATA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_1_VERSION_DATA start: 1, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_2_SIGNATURE_HASH decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Hash Signature for the MT Keyword. The hash signature is 32bits for 256 bytes of
/// data.
///
inline fapi2::ReturnCode mss_vpd_mt_2_signature_hash(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
        const uint8_t* i_blob)
{
    uint32_t l_value;

    memcpy(&l_value, i_blob + 2, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_2_SIGNATURE_HASH, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_2_SIGNATURE_HASH start: 2, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DIMM_RCD_IBT decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Register Clock Driver, Input Bus Termination in tens of
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_dimm_rcd_ibt(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2];

    memcpy(&l_value, i_blob + 6, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DIMM_RCD_IBT, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DIMM_RCD_IBT start: 6, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DQ and DQS Drive Impedance for
/// [Port][DIMM][RANK].
///
inline fapi2::ReturnCode mss_vpd_mt_dram_drv_imp_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 10, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS start: 10, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DRAM_RTT_NOM decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DRAM side Nominal Termination Resistance in
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_dram_rtt_nom(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 18, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_RTT_NOM, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_RTT_NOM start: 18, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DRAM_RTT_PARK decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DRAM side Park Termination Resistance in
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_dram_rtt_park(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 26, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_RTT_PARK, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_RTT_PARK start: 26, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DRAM_RTT_WR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DRAM side Write Termination Resistance in
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_dram_rtt_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 34, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_RTT_WR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_RTT_WR start: 34, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_RD_UP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Selects the number of enabled pullup branches during READ mode. ONLY set range
/// 0-7. Eg. 0x02 = b00000010 (1 branch selected), 0x06 = b00000110 (2 branches
/// selected)
///
inline fapi2::ReturnCode mss_vpd_mt_mc_dq_acboost_rd_up(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2];

    memcpy(&l_value, i_blob + 42, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_RD_UP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_RD_UP start: 42, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_DOWN decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Selects the number of enabled pulldown branches during WRITE mode. ONLY set
/// range 0-7. Eg. 0x02 = b00000010 (1 branch selected), 0x06 = b00000110 (2
/// branches
/// selected)
///
inline fapi2::ReturnCode mss_vpd_mt_mc_dq_acboost_wr_down(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2];

    memcpy(&l_value, i_blob + 46, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_DOWN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_DOWN start: 46, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_UP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Selects the number of enabled pullup branches during WRITE mode. ONLY set range
/// 0-7. Eg. 0x02 = b00000010 (1 branch selected), 0x06 = b00000110 (2 branches
/// selected)
///
inline fapi2::ReturnCode mss_vpd_mt_mc_dq_acboost_wr_up(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][2];

    memcpy(&l_value, i_blob + 50, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_UP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_UP start: 50, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_CTLE_CAP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Sets the capacitance value in the RC source degeneration for [PORT#][DP16
/// BLOCK#]. ONLY set range 0-3. (0x00 = No capacitor selected, 0x01 = more caps
/// selected, 0x02 = even more caps selected, 0x03 = maximum capacitors
/// selected)
///
inline fapi2::ReturnCode mss_vpd_mt_mc_dq_ctle_cap(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][5];

    memcpy(&l_value, i_blob + 54, 10);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_CTLE_CAP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_CTLE_CAP start: 54, len: 10");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_CTLE_RES decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Sets the resistance value in the RC source degeneration for [PORT#][DP16
/// BLOCK#]. Also defines the CTLE's DC Gain. ONLY set range 0-7. (0x00 = max
/// resistance, 0x01 to 0x06 = decreasing resistance, 0x07 = min
/// resistance)
///
inline fapi2::ReturnCode mss_vpd_mt_mc_dq_ctle_res(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2][5];

    memcpy(&l_value, i_blob + 64, 10);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_CTLE_RES, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_CTLE_RES start: 64, len: 10");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_ADDR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for Address Lines in
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_mc_drv_imp_addr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 74, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_ADDR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_ADDR start: 74, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for Clock in
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_mc_drv_imp_clk(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 76, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK start: 76, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for Control Lines in
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_mc_drv_imp_cntl(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 78, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL start: 78, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for Data and Data Strobe Lines in
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_mc_drv_imp_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 80, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS start: 80, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_SPCKE decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for Clock Enable Spare Line in
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_mc_drv_imp_spcke(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 82, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_SPCKE, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_SPCKE start: 82, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Receiver Impedance for Data and Data Strobe Lines in
/// Ohms.
///
inline fapi2::ReturnCode mss_vpd_mt_mc_rcv_imp_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 84, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS start: 84, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_ODT_RD decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  READ, On Die Termination triggering
/// bitmap.
///
inline fapi2::ReturnCode mss_vpd_mt_odt_rd(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 86, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_ODT_RD, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_ODT_RD start: 86, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_ODT_WR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  WRITE, On Die Termination triggering
/// bitmap.
///
inline fapi2::ReturnCode mss_vpd_mt_odt_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2][2][2];

    memcpy(&l_value, i_blob + 94, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_ODT_WR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_ODT_WR start: 94, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_VREF_DRAM_WR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DRAM side Write Vref setting for DDR4. Bit encode is 01234567. Bit 0 is unused.
/// Bit 1 is the Range. Bits 2-7 is the Value. Refer to the VrefDQ Training Table in
/// JEDEC.
///
inline fapi2::ReturnCode mss_vpd_mt_vref_dram_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 102, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_VREF_DRAM_WR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_VREF_DRAM_WR start: 102, len: 2");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_VREF_MC_RD decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Read Vref setting. Dividing by 1000 gives you percentage
/// of
/// Vdd
///
inline fapi2::ReturnCode mss_vpd_mt_vref_mc_rd(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint32_t l_value[2];

    memcpy(&l_value, i_blob + 104, 8);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_VREF_MC_RD, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_VREF_MC_RD start: 104, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_WINDAGE_RD_CTR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Derived from calibration/characterization of read centering. Number of windage
/// offset in units of pico-seconds[ps] with sign bit0 (0b0=positive, 0b1=negative)
/// and value in bits1..31, so 0x80000023 for example would mean "-35ps". If this is
/// enabled, disable periodic rd_ctr in draminit_mc.
/// Default
///
inline fapi2::ReturnCode mss_vpd_mt_windage_rd_ctr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint16_t l_value[2];

    memcpy(&l_value, i_blob + 112, 4);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_WINDAGE_RD_CTR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_WINDAGE_RD_CTR start: 112, len: 4");

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
    FAPI_TRY (decoder::mss_vpd_mr_0_version_layout(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_1_version_data(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_2_signature_hash(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a00(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a01(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a02(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a03(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a04(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a05(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a06(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a07(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a08(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a09(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a10(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a11(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a12(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a13(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_a17(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_ba0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_ba1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_bg0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_bg1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_c0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_c1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_addr_c2(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_d0_clk0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_d0_clk1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_d1_clk0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_d1_clk1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cmd_actn(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cmd_addr_casn_a15(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cmd_addr_rasn_a16(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cmd_addr_wen_a14(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cmd_par(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d0_cke0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d0_cke1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d1_cke0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d1_cke1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d0_csn0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d0_csn1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d1_csn0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d1_csn1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d0_odt0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d0_odt1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d1_odt0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_phase_rot_cntl_d1_odt1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mr_mc_2n_mode_autoset(i_target, i_mr_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_0_version_layout(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_1_version_data(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_2_signature_hash(fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_dimm_rcd_ibt(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_dram_drv_imp_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_dram_rtt_nom(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_dram_rtt_park(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_dram_rtt_wr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_dq_acboost_rd_up(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_dq_acboost_wr_down(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_dq_acboost_wr_up(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_dq_ctle_cap(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_dq_ctle_res(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_drv_imp_addr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_drv_imp_clk(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_drv_imp_cntl(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_drv_imp_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_drv_imp_spcke(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_mc_rcv_imp_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_odt_rd(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_odt_wr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_vref_dram_wr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_vref_mc_rd(i_target, i_mt_blob) );
    FAPI_TRY (decoder::mss_vpd_mt_windage_rd_ctr(i_target, i_mt_blob) );

fapi_try_exit:
    return fapi2::current_err;
}


} // close ns mss
#endif