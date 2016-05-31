/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_common.H $                   */
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
/// @file p9_io_common.H
/// @brief Register Access.
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------
///
/// @verbatim
/// IO Common Functions.
///
/// @endverbatim
///----------------------------------------------------------------------------

#ifndef P9_IO_COMMON_H_
#define P9_IO_COMMON_H_

//* *****************************
//* Defines
//* *****************************
//-----------------------------------------------------------------------------
//  FAPI Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

/**
 * @brief Shorten timers if we are running in simulation
 *        a right aligned value.
 * @param[in] i_target     FAPI2 Target
 * @param[in] i_groups     Clock groups
 * @return Field Data
 */
fapi2::ReturnCode p9_io_xbus_shorten_timers(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const std::vector < uint8_t >&                   i_groups )
{
    FAPI_IMP( "p9_io_xbus_shorten_timers: I/O EDI+ Xbus Entering" );
    const uint8_t LANE_00  = 0;
    uint64_t      reg_data = 0;
    uint8_t       l_is_sim = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim) );

    if( l_is_sim )
    {
        for( auto grp : i_groups )
        {
            FAPI_TRY( io::read( EDIP_RX_CTL_MODE7_EO_PG, i_target, grp, LANE_00, reg_data ),
                      "read edip_rx_ctl_mode7_eo_pg failed" );
            io::set( EDIP_RX_ABORT_CHECK_TIMEOUT_SEL, 0x0, reg_data );
            io::set( EDIP_RX_POLLING_TIMEOUT_SEL, 0x0, reg_data );
            FAPI_TRY( io::write( EDIP_RX_CTL_MODE7_EO_PG, i_target, grp, LANE_00, reg_data ),
                      "write edip_rx_ctl_mode7_eo_pg failed" );

            FAPI_TRY( io::rmw( EDIP_RX_SERVO_CHG_CFG, i_target, grp, LANE_00, 0x0 ),
                      "rmw edip_rx_rx_servo_chg_cfg failed" );


            FAPI_TRY( io::read( EDIP_RX_CTL_MODE14_EO_PG, i_target, grp, LANE_00, reg_data ),
                      "read edip_rx_ctl_mode14_eo_pg failed" );
            io::set( EDIP_RX_AMP_INIT_TIMEOUT, 0x0, reg_data );
            io::set( EDIP_RX_AMP_RECAL_TIMEOUT, 0x0, reg_data );
            io::set( EDIP_RX_PEAK_INIT_TIMEOUT, 0x0, reg_data );
            io::set( EDIP_RX_PEAK_RECAL_TIMEOUT, 0x0, reg_data );
            FAPI_TRY( io::write( EDIP_RX_CTL_MODE14_EO_PG, i_target, grp, LANE_00, reg_data ),
                      "write edip_rx_ctl_mode14_eo_pg failed" );

            FAPI_TRY( io::read( EDIP_RX_CTL_MODE15_EO_PG, i_target, grp, LANE_00, reg_data ),
                      "read edip_rx_ctl_mode15_eo_pg failed" );
            io::set( EDIP_RX_AMIN_TIMEOUT, 0x0, reg_data );
            io::set( EDIP_RX_CM_TIMEOUT, 0x0, reg_data );
            io::set( EDIP_RX_OFF_INIT_TIMEOUT, 0x0, reg_data );
            io::set( EDIP_RX_OFF_RECAL_TIMEOUT, 0x0, reg_data );
            FAPI_TRY( io::write( EDIP_RX_CTL_MODE15_EO_PG, i_target, grp, LANE_00, reg_data ),
                      "write edip_rx_ctl_mode15_eo_pg failed" );

            FAPI_TRY( io::read( EDIP_RX_CTL_MODE16_EO_PG, i_target, grp, LANE_00, reg_data ),
                      "read edip_rx_ctl_mode16_eo_pg failed" );
            io::set( EDIP_RX_AMP_TIMEOUT, 0x0, reg_data );
            io::set( EDIP_RX_BER_TIMEOUT, 0x0, reg_data );
            io::set( EDIP_RX_USERDEF_TIMEOUT, 0x0, reg_data );
            FAPI_TRY( io::write( EDIP_RX_CTL_MODE16_EO_PG, i_target, grp, LANE_00, reg_data ),
                      "write edip_rx_ctl_mode16_eo_pg failed" );
        }
    }

fapi_try_exit:
    FAPI_IMP( "p9_io_xbus_shorten_timers: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

#endif /* P9_IO_COMMON_H_ */
