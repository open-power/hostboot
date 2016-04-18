/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_clear_firs.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_io_xbus_clear_firs.C
/// @brief Clears I/O Firs
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// Clears I/O Xbus FIRs on the PHY Rx/Tx.
///
/// Clocks must be running.
///
/// @endverbatim
///----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_xbus_clear_firs.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------
fapi2::ReturnCode io_rx_fir_reset(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_clock_group );

fapi2::ReturnCode io_tx_fir_reset(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_clock_group );

/**
 * @brief Clears PHY Rx/Tx FIRs on the XBUS(EDI+) specified target.  The FIRs
 *   are cleared by toggling a rx & tx fir reset bit.
 * @param[in] i_target         FAPI2 Target
 * @param[in] i_clock_group    Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_clear_firs(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_clock_group )
{
    FAPI_IMP( "I/O Start Xbus Clear FIRs" );

    FAPI_TRY( io_tx_fir_reset( i_target, i_clock_group ), "Tx Reset Failed" );

    FAPI_TRY( io_rx_fir_reset( i_target, i_clock_group ), "Rx Reset Failed" );

fapi_try_exit:
    FAPI_IMP( "I/O End Xbus Clear FIRs" );
    return fapi2::current_err;
}

/**
 * @brief This function resets the Rx Firs on a EDI+ Xbus
 * @param[in] i_target       FAPI2 Target
 * @param[in] i_clock_group  Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode io_rx_fir_reset(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t& i_clock_group)
{
    const uint8_t LANE_00 = 0;
    uint64_t l_data = 0;

    FAPI_TRY( io::read( EDIP_RX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
              "Reading Rx Fir Reg Failed");

    io::set (EDIP_RX_FIR_RESET, 0, l_data);
    FAPI_TRY(io::write( EDIP_RX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Rx Fir Reg Failed");

    io::set (EDIP_RX_FIR_RESET, 1, l_data);
    FAPI_TRY(io::write( EDIP_RX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Rx Fir Reg Failed");

    io::set (EDIP_RX_FIR_RESET, 0, l_data);
    FAPI_TRY(io::write( EDIP_RX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Rx Fir Reg Failed");

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief This function resets the Tx Firs on a EDI+ Xbus
 * @param[in] i_target       FAPI2 Target
 * @param[in] i_clock_group  Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode io_tx_fir_reset(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t& i_clock_group)
{
    const uint8_t LANE_00 = 0;
    uint64_t l_data = 0;

    FAPI_TRY( io::read( EDIP_TX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
              "Reading Tx Fir Reg Failed");

    io::set (EDIP_TX_FIR_RESET, 0, l_data);
    FAPI_TRY(io::write( EDIP_TX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Tx Fir Reg Failed");

    io::set (EDIP_TX_FIR_RESET, 1, l_data);
    FAPI_TRY(io::write( EDIP_TX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Tx Fir Reg Failed");

    io::set (EDIP_TX_FIR_RESET, 0, l_data);
    FAPI_TRY(io::write( EDIP_TX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Tx Fir Reg Failed");

fapi_try_exit:
    return fapi2::current_err;
}
