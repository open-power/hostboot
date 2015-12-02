/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_pdwn_lanes.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_io_xbus_pdwn_lanes.C
/// @brief P9 Xbus Power Down Lanes.
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// A HWP that powers down lanes.  This procedure should power down rx lanes,
///   tx lanes, or both rx & tx lanes.
///
/// Procedure Prereq:
///     - System clocks are running.
///
/// @endverbatim
///----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "p9_io_xbus_pdwn_lanes.H"
#include "p9_io_gcr.H"
#include "p9_io_regs.H"

// ----------------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------------
fapi2::ReturnCode rx_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t i_clock_group,
    const std::vector< uint8_t >& i_bad_lanes);
fapi2::ReturnCode tx_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t i_clock_group,
    const std::vector< uint8_t >& i_bad_lanes);


/**
 * @brief A HWP that powers down the specified lanes.
 * @param[in] i_rx_target        FAPI2 Rx Target
 * @param[in] i_rx_clock_group   Clock Group of Rx Target
 * @param[in] i_rx_bad_lanes     Vector of Rx Bad Lanes
 * @param[in] i_tx_target        FAPI2 Tx Target
 * @param[in] i_tx_clock_group   Clock Group of Tx Target
 * @param[in] i_tx_bad_lanes     Vector of Tx Bad Lanes
 * @retval ReturnCode
 */
fapi2::ReturnCode
p9_io_xbus_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_rx_target,
    const uint8_t& i_rx_clock_group,
    const std::vector< uint8_t >& i_rx_bad_lanes,
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_tx_target,
    const uint8_t& i_tx_clock_group,
    const std::vector< uint8_t >& i_tx_bad_lanes)
{
    FAPI_IMP("Entering...");
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_DBG("Rx Bad Lanes Size: %d", i_rx_bad_lanes.size());

    if( !i_rx_bad_lanes.empty() )
    {
        FAPI_TRY(rx_pdwn_lanes( i_rx_target, i_rx_clock_group, i_rx_bad_lanes),
                 "Rx Power Down Lanes Failed");
    }

    FAPI_DBG("Tx Bad Lanes Size: %d", i_tx_bad_lanes.size());

    if( !i_tx_bad_lanes.empty() )
    {
        FAPI_TRY(tx_pdwn_lanes( i_tx_target, i_tx_clock_group, i_tx_bad_lanes),
                 "Tx Power Down Lanes Failed");
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

/**
 * @brief Powers down Rx Lanes
 * @param[in] i_target           FAPI2 Rx Target
 * @param[in] i_clock_group      Clock Group of Target
 * @param[in] i_bad_lanes        Vector of Bad Lanes
 */
fapi2::ReturnCode rx_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t i_clock_group,
    const std::vector< uint8_t >& i_bad_lanes)
{
    FAPI_IMP("Entering...");
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    char target_string[fapi2::MAX_ECMD_STRING_LEN];
    Register < EDIP_RX_BIT_MODE1_EO_PL > rx_dig_pdwn_reg;
    Register < EDIP_RX_DAC_CNTL1_EO_PL > rx_ana_pdwn_reg;

    fapi2::toString(i_target, target_string, fapi2::MAX_ECMD_STRING_LEN);

    for(uint8_t index = 0; index < i_bad_lanes.size(); ++index)
    {
        FAPI_DBG("Powering Down Lane[%d/%d]: Target(%s:g%d:l%d)",
                 index,
                 i_bad_lanes.size() - 1,
                 target_string,
                 i_clock_group,
                 i_bad_lanes[index]);

        FAPI_TRY(rx_dig_pdwn_reg.read(i_target, i_clock_group, i_bad_lanes[index]),
                 "Failed reading rx dig pdwn reg");
        rx_dig_pdwn_reg.set<EDIP_RX_LANE_DIG_PDWN>(0x1);
        FAPI_TRY(rx_dig_pdwn_reg.write(i_target, i_clock_group, i_bad_lanes[index]),
                 "Failed writing rx dig pdwn reg");

        FAPI_TRY(rx_ana_pdwn_reg.read(i_target, i_clock_group, i_bad_lanes[index]),
                 "Failed reading rx ana pdwn reg");
        rx_ana_pdwn_reg.set<EDIP_RX_LANE_ANA_PDWN>(0x1);
        FAPI_TRY(rx_ana_pdwn_reg.write(i_target, i_clock_group, i_bad_lanes[index]),
                 "Failed writing rx ana pdwn reg");
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

/**
 * @brief Powers down Tx Lanes
 * @param[in] i_target           FAPI2 Rx Target
 * @param[in] i_clock_group      Clock Group of Target
 * @param[in] i_bad_lanes        Vector of Bad Lanes
 */
fapi2::ReturnCode tx_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t i_clock_group,
    const std::vector< uint8_t >& i_bad_lanes)
{
    FAPI_IMP("Entering...");
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    char target_string[fapi2::MAX_ECMD_STRING_LEN];
    Register < EDIP_TX_MODE1_PL > tx_pdwn_reg;

    fapi2::toString(i_target, target_string, fapi2::MAX_ECMD_STRING_LEN);

    for(uint8_t index = 0; index < i_bad_lanes.size(); ++index)
    {
        FAPI_DBG("Powering Down Lane[%d/%d]: Target(%s:g%d:l%d)",
                 index,
                 i_bad_lanes.size() - 1,
                 target_string,
                 i_clock_group,
                 i_bad_lanes[index]);

        FAPI_TRY(tx_pdwn_reg.read(i_target, i_clock_group, i_bad_lanes[index]), "Failed reading tx pdwn reg");
        tx_pdwn_reg.set<EDIP_TX_LANE_PDWN>(0x1);
        FAPI_TRY(tx_pdwn_reg.write(i_target, i_clock_group, i_bad_lanes[index]), "Failed writing tx pdwn reg");
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}
