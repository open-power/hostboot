/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_linktrain.C $           */
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
/// @file p9_io_xbus_linktrain.C
/// @brief I/O Link Training on the Xbus Links.
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
/// Train the link through several steps (WDERF).
///     - (W) Wiretest
///     - (D) Deskew
///     - (E) Eye Optimization
///     - (R) Repair/Recal
///     - (F) Functional
///
/// Procedure Prereq:
///     - System clocks are running.
///     - Scominit Procedure is completed.
///     - Dccal Procedure is completed.
///
/// @endverbatim
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Defines
//------------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_xbus_linktrain.H>
#include <p9_io_xbus_clear_firs.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------

/**
 * @brief I/O EDI+ Training Substeps
 */
enum class State
{
    NONE       = 0x00000000,
    WIRETEST   = 0x00000001,
    DESKEW     = 0x00000002,
    EYEOPT     = 0x00000004,
    REPAIR     = 0x00000008,
    FUNCTIONAL = 0x00000010,
    WDERF      = 0x0000001F
};
inline State operator& (const State& a, const State& b )
{
    return static_cast<State>( static_cast<uint8_t>(a) & static_cast<uint8_t>(b) );
}

/**
 * @brief Starts I/O Training on Xbus (EDI Plus).  The slave target must start
 *   training before the master.  This function also assumes that dccal( tx
 *   impedance calibration and rx offset calibration) are complete.
 * @param[in]  i_target   Fapi2 Target
 * @param[in]  i_group    Reperesents the clock group
 * @param[in]  i_wderf    Represents which training substeps are run.
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode linktrain_start(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    const State&                                     i_wderf );

/**
 * @brief This function polls the EDI Plus training logic until the training
 *   is complete.  During the case of an error/timeout, the code will log
 *   FFDC data, which is added to the original error.
 * @param[in]  i_mtarget   Master Xbus Target
 * @param[in]  i_mgroup    Master Clock Group
 * @param[in]  i_starget   Slave Xbus Target
 * @param[in]  i_sgroup    Slave Clock Group
 * @param[in]  i_started   The started EDI Plus training substeps
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode linktrain_poll(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup,
    const State&                                     i_started );

/**
 * @brief Adds I/O FFDC Link data to the Error
 * @param[in]  i_mtarget   Master Target
 * @param[in]  i_mgroup    Master Group
 * @param[in]  i_starget   Slave Target
 * @param[in]  i_sgroup    Slave Group
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode add_linktrain_failed_ffdc(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup );

/**
 * @brief Adds I/O FFDC Link data to the Error
 * @param[in]  i_mtarget   Master Target
 * @param[in]  i_mgroup    Master Group
 * @param[in]  i_starget   Slave Target
 * @param[in]  i_sgroup    Slave Group
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode add_linktrain_timeout_ffdc(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup );

/**
 * @brief Find which target is the master target.  If neither target is the master,
 *   then we will throw an error.  The master / slave target will be set and passed
 *   by reference.
 * @param[in]  i_target            Fapi2 Target
 * @param[in]  i_group             Clock Group
 * @param[in]  i_connected_target  Connected Fapi2 Target
 * @param[in]  i_connected_group   Connected Clock Group
 * @param[out] o_mtarget           Master Fapi2 Target
 * @param[out] o_mgroup            Master Clock Group
 * @param[out] o_starget           Slave Fapi2 Target
 * @param[out] o_sgroup            Slave Clock Group
 * @retval     ReturnCode
 */
fapi2::ReturnCode find_master_endpoint(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_connected_target,
    const uint8_t&                                   i_connected_group,
    fapi2::Target < fapi2::TARGET_TYPE_XBUS >&       o_mtarget,
    uint8_t&                                         o_mgroup,
    fapi2::Target < fapi2::TARGET_TYPE_XBUS >&       o_starget,
    uint8_t&                                         o_sgroup );

/**
 * @brief Enables the Tx Serializer Sync on Xbus (EDI Plus).
 * @param[in]  i_mtarget   Master Fapi2 Target
 * @param[in]  i_mgroup    Master clock group
 * @param[in]  i_mtarget   Slave Fapi2 Target
 * @param[in]  i_mgroup    Slave clock group
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode tx_serializer_sync_power_on(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup );

/**
 * @brief Disables the Tx Serializer Sync on Xbus (EDI Plus).
 * @param[in]  i_mtarget   Master Fapi2 Target
 * @param[in]  i_mgroup    Master clock group
 * @param[in]  i_mtarget   Slave Fapi2 Target
 * @param[in]  i_mgroup    Slave clock group
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode tx_serializer_sync_power_off(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup );

/**
 * @brief Reads bad lane vector data from the
 *   passed target and stores the data in the vector.
 * @param[in]  i_target     Fapi2 Target
 * @param[in]  i_group      Clock Group
 * @param[out] o_data       Data Vector of bad lane vector data
 * @retval     ReturnCode
 */
fapi2::ReturnCode set_bad_lane_data(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    std::vector< uint8_t >&                          io_data );

/**
 * @brief Copmares the bad lane vector pre and post training.  If the data is
 *   the same, then we will want to clear the firs, since the firs have already
 *   been recorded.
 * @param[in]  i_target     Fapi2 Target
 * @param[in]  i_group      Clock Group
 * @param[out] o_data       Data Vector of bad lane vector data
 * @retval     ReturnCode
 */
fapi2::ReturnCode evaluate_bad_lane_data(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    std::vector< uint8_t >&                          io_data );


/**
 * @brief A HWP that runs on every instance of the XBUS(EDI+)
 * @param[in] i_target Reference to the Master Target
 * @param[in] i_group  Master Target Clock Group
 * @param[in] i_ctarget Reference to the Slave Target
 * @param[in] i_cgroup  Slave Target Clock Group
 * @retval    ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_linktrain(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_ctarget,
    const uint8_t&                                   i_cgroup )
{
    FAPI_IMP( "p9_io_xbus_linktrain: P9 I/O EDI+ Xbus Entering" );
    fapi2::Target < fapi2::TARGET_TYPE_XBUS > l_mtarget;
    fapi2::Target < fapi2::TARGET_TYPE_XBUS > l_starget;
    uint8_t                                   l_mgroup                 = 0;
    uint8_t                                   l_sgroup                 = 0;
    std::vector < uint8_t >                   l_master_bad_lane_vector = { 0, 0, 0, 0 };
    std::vector < uint8_t >                   l_slave_bad_lane_vector  = { 0, 0, 0, 0 };
    char l_target_string[fapi2::MAX_ECMD_STRING_LEN];
    char l_ctarget_string[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString( i_target,  l_target_string,  fapi2::MAX_ECMD_STRING_LEN );
    fapi2::toString( i_ctarget, l_ctarget_string, fapi2::MAX_ECMD_STRING_LEN );

    FAPI_DBG( "I/O Xbus Targets: Target(%s:g%d) Connected(%s:g%d)",
              l_target_string, i_group,
              l_ctarget_string, i_cgroup );

    // Find which target is the master target.  If neither target is the master,
    //   then we will throw an error.  The master / slave target will be set
    //   and passed by reference.
    FAPI_TRY( find_master_endpoint(
                  i_target,  i_group,
                  i_ctarget, i_cgroup,
                  l_mtarget, l_mgroup,
                  l_starget, l_sgroup ),
              "Find Master Endpoint Failed" );

    FAPI_TRY( set_bad_lane_data( l_mtarget, l_mgroup, l_master_bad_lane_vector ),
              "Pre Training: Get Bad Lane Vector Failed on Master" );

    FAPI_TRY( set_bad_lane_data( l_starget, l_sgroup, l_slave_bad_lane_vector ),
              "Pre Training: Get Bad Lane Vector Failed on Slave" );

    // Clock Serializer Init -- isn't strictly necessary but does line up the
    //   clock serializer counter wit the data slices.
    FAPI_TRY( tx_serializer_sync_power_on( l_mtarget, l_mgroup, l_starget, l_sgroup ),
              "tx_serializer_sync_power_on Failed." );

    // Start Slave Target Link Training
    FAPI_TRY( linktrain_start( l_starget, l_sgroup, State::WDERF ),
              "P9 IO Xbus Linktrain Start Slave Training Failed" );

    // Start Master Target Link Training
    FAPI_TRY( linktrain_start( l_mtarget, l_mgroup, State::WDERF ),
              "P9 IO Xbus Linktrain Start Master Training Failed." );

    // Poll for Training to Complete on Master Target
    FAPI_TRY( linktrain_poll( l_mtarget, l_mgroup, l_starget, l_sgroup, State::WDERF ),
              "P9 IO Xbus Linktrain Polling Failed" );

    // Disable the Tx Serializer Sync
    FAPI_TRY( tx_serializer_sync_power_off( l_mtarget, l_mgroup, l_starget, l_sgroup ),
              "tx_serializer_sync_power_off Failed.");

    FAPI_TRY( set_bad_lane_data( l_mtarget, l_mgroup, l_master_bad_lane_vector ),
              "Post Training: Get Bad Lane Vector Failed on Master" );

    FAPI_TRY( set_bad_lane_data( l_starget, l_sgroup, l_slave_bad_lane_vector ),
              "Post Training: Get Bad Lane Vector Failed on Master" );

    FAPI_TRY( evaluate_bad_lane_data( l_mtarget, l_mgroup, l_master_bad_lane_vector ),
              "Post Training: Evaluate Firs Failed on Master" );

    FAPI_TRY( evaluate_bad_lane_data( l_starget, l_sgroup, l_slave_bad_lane_vector ),
              "Post Training: Evaluate Firs Failed on Slave" );


fapi_try_exit:
    FAPI_IMP( "p9_io_xbus_linktrain: P9 I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Find which target is the master target.  If neither target is the master,
 *   then we will throw an error.  The master / slave target will be set and passed
 *   by reference.
 * @param[in]  i_target            Fapi2 Target
 * @param[in]  i_group             Clock Group
 * @param[in]  i_connected_target  Connected Fapi2 Target
 * @param[in]  i_connected_group   Connected Clock Group
 * @param[out] o_mtarget           Master Fapi2 Target
 * @param[out] o_mgroup            Master Clock Group
 * @param[out] o_starget           Slave Fapi2 Target
 * @param[out] o_sgroup            Slave Clock Group
 * @retval     ReturnCode
 */
fapi2::ReturnCode find_master_endpoint(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_connected_target,
    const uint8_t&                                   i_connected_group,
    fapi2::Target < fapi2::TARGET_TYPE_XBUS >&       o_mtarget,
    uint8_t&                                         o_mgroup,
    fapi2::Target < fapi2::TARGET_TYPE_XBUS >&       o_starget,
    uint8_t&                                         o_sgroup )
{
    uint8_t l_master_mode = 0;
    uint8_t l_cmaster_mode = 0;

    FAPI_IMP( "find_master_endpoint: P9 I/O EDI+ Xbus Entering" );

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IO_XBUS_MASTER_MODE, i_target, l_master_mode) );

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IO_XBUS_MASTER_MODE, i_connected_target, l_cmaster_mode) );

    if( l_master_mode == fapi2::ENUM_ATTR_IO_XBUS_MASTER_MODE_TRUE )
    {
        FAPI_DBG( "find_master_endpoint: Target is Master" );
        o_mtarget = i_target;
        o_mgroup  = i_group;
        o_starget = i_connected_target;
        o_sgroup  = i_connected_group;
    }
    else if( l_cmaster_mode == fapi2::ENUM_ATTR_IO_XBUS_MASTER_MODE_TRUE )
    {
        FAPI_DBG( "find_master_endpoint: Connected target is Master" );
        o_mtarget = i_connected_target;
        o_mgroup  = i_connected_group;
        o_starget = i_target;
        o_sgroup  = i_group;
    }
    else
    {
        FAPI_ASSERT( false, fapi2::IO_XBUS_NOT_MASTER()
                     .set_TARGET( i_target )
                     .set_CTARGET( i_connected_target ),
                     "find_master_endpoint: Neither target or connected target is master." );
    }

fapi_try_exit:
    FAPI_IMP( "find_master_endpoint: P9 I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Reads bad lane vector data from the
 *   passed target and stores the data in the vector.
 * @param[in]  i_target     Fapi2 Target
 * @param[in]  i_group      Clock Group
 * @param[out] o_data       Data Vector of bad lane vector data
 * @retval     ReturnCode
 */
fapi2::ReturnCode set_bad_lane_data(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    std::vector< uint8_t >&                          io_data )
{
    FAPI_IMP( "set_bad_lane_data: P9 I/O EDI+ Xbus Entering" );
    const uint8_t LANE_00                = 0;
    const uint8_t LAST_BAD_LANE_0_15     = 0;
    const uint8_t LAST_BAD_LANE_16_23    = 1;
    const uint8_t CURRENT_BAD_LANE_0_15  = 2;
    const uint8_t CURRENT_BAD_LANE_16_23 = 3;
    uint64_t      l_data                 = 0;

    FAPI_TRY( io::read( EDIP_RX_LANE_BAD_VEC_0_15, i_target, i_group, LANE_00, l_data ),
              "rmw to edip_rx_lane_bad_vec_0_15 failed." );

    io_data[LAST_BAD_LANE_0_15]    = io_data[CURRENT_BAD_LANE_0_15];
    io_data[CURRENT_BAD_LANE_0_15] = io::get( EDIP_RX_LANE_BAD_VEC_0_15, l_data );

    FAPI_TRY( io::read( EDIP_RX_LANE_BAD_VEC_16_23, i_target, i_group, LANE_00, l_data ),
              "rmw to edip_rx_lane_bad_vec_16_23 failed." );

    io_data[LAST_BAD_LANE_16_23]    = io_data[CURRENT_BAD_LANE_16_23];
    io_data[CURRENT_BAD_LANE_16_23] = io::get( EDIP_RX_LANE_BAD_VEC_16_23, l_data );

fapi_try_exit:
    FAPI_IMP( "set_bad_lane_data: P9 I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}


/**
 * @brief Copmares the bad lane vector pre and post training.  If the data is
 *   the same, then we will want to clear the firs, since the firs have already
 *   been recorded.
 * @param[in]  i_target     Fapi2 Target
 * @param[in]  i_group      Clock Group
 * @param[out] o_data       Data Vector of bad lane vector data
 * @retval     ReturnCode
 */
fapi2::ReturnCode evaluate_bad_lane_data(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    std::vector< uint8_t >&                          io_data )
{
    FAPI_IMP( "evaluate_bad_lane_data: P9 I/O EDI+ Xbus Entering" );
    const uint8_t LANE_00         = 0;
    const uint8_t PRE_LANE_0_15   = 0;
    const uint8_t PRE_LANE_16_23  = 1;
    const uint8_t POST_LANE_0_15  = 2;
    const uint8_t POST_LANE_16_23 = 3;
    uint64_t      l_data          = 0;

    // If the bad lane vector matches pre to post training, then the same bad
    //   lanes that were previously found, were found again.  These bad lanes have
    //   already been reported.  So we will clear the first related to these bad
    //   lanes
    if( ( io_data[PRE_LANE_0_15] == io_data[POST_LANE_0_15] ) &&
        ( io_data[PRE_LANE_16_23] == io_data[POST_LANE_16_23] ) )
    {
        // If the entire bad lane vector equals 0, then we don't need to clear
        //   any firs.
        if(  io_data[POST_LANE_0_15] != 0 || io_data[POST_LANE_16_23] != 0 )
        {
            FAPI_TRY( p9_io_xbus_clear_firs( i_target, i_group ) );

            // Clear BUS0_SPARE_DEPLOYED ( Bit 9 ).
            FAPI_TRY( io::read( EDIP_SCOM_FIR_PB, i_target, i_group, LANE_00, l_data ) );
            l_data &= 0xFF7FFFFFFFFFFFFFull;
            FAPI_TRY( io::write( EDIP_SCOM_FIR_PB, i_target, i_group, LANE_00, l_data ) );
        }
    }

fapi_try_exit:
    FAPI_IMP( "evaluate_bad_lane_data: P9 I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}


/**
 * @brief Enables the Tx Serializer Sync on Xbus (EDI Plus).
 * @param[in]  i_mtarget   Master Fapi2 Target
 * @param[in]  i_mgroup    Master clock group
 * @param[in]  i_mtarget   Slave Fapi2 Target
 * @param[in]  i_mgroup    Slave clock group
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode tx_serializer_sync_power_on(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup )
{
    FAPI_IMP( "tx_serializer_sync_power_on: I/O EDI+ Xbus Entering" );
    const uint8_t XBUS_LANES = 17;
    const uint8_t LANE_00 = 0;

    FAPI_TRY( io::rmw( EDIP_TX_CLK_UNLOAD_CLK_DISABLE, i_mtarget, i_mgroup, LANE_00, 0 ),
              "master rmw to edip_tx_clk_unload_clk_disable failed." );
    FAPI_TRY( io::rmw( EDIP_TX_CLK_UNLOAD_CLK_DISABLE, i_starget, i_sgroup, LANE_00, 0 ),
              "slave rmw to edip_tx_clk_unload_clk_disable failed." );

    FAPI_TRY( io::rmw( EDIP_TX_CLK_RUN_COUNT, i_mtarget, i_mgroup, LANE_00, 0 ),
              "master rmw to edip_tx_clk_run_count failed." );
    FAPI_TRY( io::rmw( EDIP_TX_CLK_RUN_COUNT, i_starget, i_sgroup, LANE_00, 0 ),
              "slave rmw to edip_tx_clk_run_count failed." );

    FAPI_TRY( io::rmw( EDIP_TX_CLK_RUN_COUNT, i_mtarget, i_mgroup, LANE_00, 1 ),
              "master rmw to edip_tx_clk_run_count failed." );
    FAPI_TRY( io::rmw( EDIP_TX_CLK_RUN_COUNT, i_starget, i_sgroup, LANE_00, 1 ),
              "slave rmw to edip_tx_clk_run_count failed." );

    FAPI_TRY( io::rmw( EDIP_TX_CLK_UNLOAD_CLK_DISABLE, i_mtarget, i_mgroup, LANE_00, 1 ),
              "master rmw to edip_tx_clk_unload_clk_disable failed." );
    FAPI_TRY( io::rmw( EDIP_TX_CLK_UNLOAD_CLK_DISABLE, i_starget, i_sgroup, LANE_00, 1 ),
              "slave rmw to edip_tx_clk_unload_clk_disable failed." );

    for( uint8_t lane = 0; lane < XBUS_LANES; ++lane )
    {
        FAPI_TRY( io::rmw( EDIP_TX_UNLOAD_CLK_DISABLE, i_mtarget, i_mgroup, lane, 0x0 ),
                  "master rmw to edip_tx_unload_clk_disable Failed" );
        FAPI_TRY( io::rmw( EDIP_TX_UNLOAD_CLK_DISABLE, i_starget, i_sgroup, lane, 0x0 ),
                  "slave rmw to edip_tx_unload_clk_disable Failed" );
    }

fapi_try_exit:
    FAPI_IMP( "tx_serializer_sync_power_on: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Disables the Tx Serializer Sync on Xbus (EDI Plus).
 * @param[in]  i_mtarget   Master Fapi2 Target
 * @param[in]  i_mgroup    Master clock group
 * @param[in]  i_mtarget   Slave Fapi2 Target
 * @param[in]  i_mgroup    Slave clock group
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode tx_serializer_sync_power_off(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup )
{
    FAPI_IMP( "tx_serializer_sync_power_off: I/O EDI+ Xbus Entering" );
    const uint8_t XBUS_LANES = 17;

    for( uint8_t lane = 0; lane < XBUS_LANES; ++lane )
    {
        FAPI_TRY( io::rmw( EDIP_TX_UNLOAD_CLK_DISABLE, i_mtarget, i_mgroup, lane, 0x1 ),
                  "master rmw to edip_tx_unload_clk_disable Failed" );
        FAPI_TRY( io::rmw( EDIP_TX_UNLOAD_CLK_DISABLE, i_starget, i_sgroup, lane, 0x1 ),
                  "slave rmw to edip_tx_unload_clk_disable Failed" );
    }

fapi_try_exit:
    FAPI_IMP( "tx_serializer_sync_power_off: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}


/**
 * @brief Starts I/O Training on Xbus (EDI Plus).  The slave target must start
 *   training before the master.  This function also assumes that dccal( tx
 *   impedance calibration and rx offset calibration) are complete.
 * @param[in]  i_target   Fapi2 Target
 * @param[in]  i_group    Reperesents the clock group
 * @param[in]  i_wderf    Represents which training substeps are run.
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode linktrain_start(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    const State&                                     i_wderf )
{
    FAPI_IMP("linktrain_start: P9 I/O EDI+ Xbus Entering");
    const uint8_t LANE_00 = 0;

    FAPI_TRY( io::rmw(
                  EDIP_RX_START_WDERF_ALIAS,
                  i_target,
                  i_group,
                  LANE_00,
                  static_cast<uint64_t>(i_wderf ) ),
              "linktrain_start: rmw to start wderf failed." );

fapi_try_exit:
    FAPI_IMP("linktrain_start: P9 I/O EDI+ Xbus Exiting");
    return fapi2::current_err;
}

/**
 * @brief This function polls the EDI Plus training logic until the training
 *   is complete.  During the case of an error/timeout, the code will log
 *   FFDC data, which is added to the original error.
 * @param[in]  i_mtarget   Master Xbus Target
 * @param[in]  i_mgroup    Master Clock Group
 * @param[in]  i_starget   Slave Xbus Target
 * @param[in]  i_sgroup    Slave Clock Group
 * @param[in]  i_started   The started EDI Plus training substeps
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode linktrain_poll(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup,
    const State&                                     i_started )
{
    FAPI_IMP( "linktrain_poll: P9 I/O EDI+ Xbus Entering" );

    const uint8_t  MAXLOOPS         = 100;
    const uint64_t DELAY_NS         = 200;
    const uint64_t DELAY_SIM_CYCLES = 20000000;
    const uint8_t  LANE_00          = 0;
    uint8_t        l_loops          = 0;
    uint64_t       l_reg_data       = 0;
    State          l_done_state     = State::NONE;
    State          l_failed_state   = State::NONE;


    // In the P9 EDI+ Xbus unit model, polling finishes in
    //   17 loops @ 20 million cycles = 340 million cycles
    while( ++l_loops < MAXLOOPS )
    {
        // Get Done/Failed WDERF Status
        FAPI_TRY( io::read( EDIP_RX_CTL_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_reg_data ) );
        l_done_state   = static_cast<State>( io::get( EDIP_RX_WDERF_DONE_ALIAS,   l_reg_data ) );
        l_failed_state = static_cast<State>( io::get( EDIP_RX_WDERF_FAILED_ALIAS, l_reg_data ) );

        // Check if all substeps are complete
        if( i_started == ( i_started & l_done_state ) )
        {
            break;
        }

        // Check if any substeps have failed.
        if( l_failed_state != State::NONE )
        {
            break;
        }

        FAPI_TRY( fapi2::delay( DELAY_NS, DELAY_SIM_CYCLES ) );
    }

    // Check the error conditions.
    if( l_failed_state != State::NONE )
    {
        FAPI_ERR( "I/O EDI+ Xbus Link Training Failed." );
        FAPI_TRY( add_linktrain_failed_ffdc( i_mtarget, i_mgroup, i_starget, i_sgroup ) );
    }
    else if( i_started != ( i_started & l_done_state ) )
    {
        FAPI_ERR( "I/O EDI+ Xbus Link Training Timeout." );
        FAPI_TRY( add_linktrain_timeout_ffdc( i_mtarget, i_mgroup, i_starget, i_sgroup ) );
    }
    else
    {
        FAPI_INF( "linktrain_poll: P9 I/O EDI+ Xbus Training Successful in %d loops.", l_loops );
    }

fapi_try_exit:
    FAPI_IMP( "linktrain_poll: P9 I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}


/**
 * @brief Adds I/O FFDC Link data to the Error
 * @param[in]  i_mtarget   Master Target
 * @param[in]  i_mgroup    Master Group
 * @param[in]  i_starget   Slave Target
 * @param[in]  i_sgroup    Slave Group
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode add_linktrain_failed_ffdc(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup )
{
    const uint8_t     LANE_00      = 0;
    const uint32_t    INVALID_FFDC = 0xFFFFFFFF;
    uint64_t          l_data       = 0;
    fapi2::ReturnCode l_ffdc_rc    = 0;
    fapi2::ReturnCode l_rc         = 0;

    // Note the return code, the return code is passed by reference and this same return code will
    // be returned at the end of the function.  The return code used in the data collection will
    // not be passed back.
    fapi2::IO_XBUS_LINKTRAIN_FAIL ffdc( fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, l_ffdc_rc );

    ffdc.set_M_TARGET( i_mtarget );
    ffdc.set_M_GROUP ( i_mgroup  );
    ffdc.set_S_TARGET( i_starget );
    ffdc.set_S_GROUP ( i_sgroup  );

    ////////////////////////////////////////////////////////////////////////////
    // Master
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read( EDIP_RX_CTL_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_WDERF_START ( io::get( EDIP_RX_START_WDERF_ALIAS,  l_data ) );
        ffdc.set_M_WDERF_DONE  ( io::get( EDIP_RX_WDERF_DONE_ALIAS,   l_data ) );
        ffdc.set_M_WDERF_FAILED( io::get( EDIP_RX_WDERF_FAILED_ALIAS, l_data ) );
    }
    else
    {
        ffdc.set_M_WDERF_START ( INVALID_FFDC );
        ffdc.set_M_WDERF_DONE  ( INVALID_FFDC );
        ffdc.set_M_WDERF_FAILED( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_STAT2_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_LANE_BAD_0_15( io::get( EDIP_RX_LANE_BAD_VEC_0_15, l_data ) );
    }
    else
    {
        ffdc.set_M_LANE_BAD_0_15( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }


    l_rc = io::read( EDIP_RX_CTL_STAT4_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_LANE_BAD_16_23( io::get( EDIP_RX_LANE_BAD_VEC_16_23, l_data ) );
    }
    else
    {
        ffdc.set_M_LANE_BAD_16_23( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_MODE11_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_LANE_DISABLED_VEC_0_15( io::get( EDIP_RX_LANE_DISABLED_VEC_0_15, l_data ) );
    }
    else
    {
        ffdc.set_M_LANE_DISABLED_VEC_0_15( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_MODE12_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_LANE_DISABLED_VEC_16_23( io::get( EDIP_RX_LANE_DISABLED_VEC_16_23, l_data ) );
    }
    else
    {
        ffdc.set_M_LANE_DISABLED_VEC_16_23( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_MAIN_INIT_STATE( io::get( EDIP_RX_MAIN_INIT_STATE, l_data ) );
    }
    else
    {
        ffdc.set_M_MAIN_INIT_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Wiretest
    l_rc = io::read( EDIP_RX_GLBSM_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_WIRETEST_WTM_STATE( io::get( EDIP_RX_WTM_STATE, l_data ) );
        ffdc.set_M_WIRETEST_WTR_STATE( io::get( EDIP_RX_WTR_STATE, l_data ) );
    }
    else
    {
        ffdc.set_M_WIRETEST_WTM_STATE( INVALID_FFDC );
        ffdc.set_M_WIRETEST_WTR_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_STAT3_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_WIRETEST_WTL_SM_STATUS( io::get( EDIP_RX_WTL_SM_STATUS, l_data ) );
    }
    else
    {
        ffdc.set_M_WIRETEST_WTL_SM_STATUS( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT2_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_WTR_BAD_LANE_COUNT( io::get( EDIP_RX_WTR_BAD_LANE_COUNT, l_data ) );
    }
    else
    {
        ffdc.set_M_WTR_BAD_LANE_COUNT( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc =  io::read( EDIP_RX_CTL_STAT5_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_CLK_LANE_BAD_CODE   ( io::get( EDIP_RX_WT_CLK_LANE_BAD_CODE, l_data ) );
        ffdc.set_M_WT_CLK_LANE_INVERTED( io::get( EDIP_RX_WT_CLK_LANE_INVERTED, l_data ) );
    }
    else
    {
        ffdc.set_M_CLK_LANE_BAD_CODE   ( INVALID_FFDC );
        ffdc.set_M_WT_CLK_LANE_INVERTED( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Deskew

    // Eye Opt
    l_rc = io::read( EDIP_RX_GLBSM_STAT1_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_EYE_OPT_STATE( io::get( EDIP_RX_EYE_OPT_STATE, l_data ) );
    }
    else
    {
        ffdc.set_M_EYE_OPT_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_CNTL13_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_HIST_MIN_EYE_WIDTH(       io::get( EDIP_RX_HIST_MIN_EYE_WIDTH, l_data ) );
        ffdc.set_M_HIST_MIN_EYE_WIDTH_LANE(  io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_LANE, l_data ) );
        ffdc.set_M_HIST_MIN_EYE_WIDTH_VALID( io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_VALID, l_data ) );
    }
    else
    {
        ffdc.set_M_HIST_MIN_EYE_WIDTH      ( INVALID_FFDC );
        ffdc.set_M_HIST_MIN_EYE_WIDTH_LANE ( INVALID_FFDC );
        ffdc.set_M_HIST_MIN_EYE_WIDTH_VALID( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Repair
    l_rc =  io::read( EDIP_RX_GLBSM_STAT4_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_RPR_STATE( io::get( EDIP_RX_RPR_STATE, l_data ) );
    }
    else
    {
        ffdc.set_M_RPR_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT9_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_BAD_LANE1    ( io::get( EDIP_RX_BAD_LANE1,     l_data ) );
        ffdc.set_M_BAD_LANE2    ( io::get( EDIP_RX_BAD_LANE2,     l_data ) );
        ffdc.set_M_BAD_LANE_CODE( io::get( EDIP_RX_BAD_LANE_CODE, l_data ) );
    }
    else
    {
        ffdc.set_M_BAD_LANE1    ( INVALID_FFDC );
        ffdc.set_M_BAD_LANE2    ( INVALID_FFDC );
        ffdc.set_M_BAD_LANE_CODE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Deskew

    // Func Mode

    ///////////////////////////////////////////////////////////////////////////
    // Slave
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read( EDIP_RX_CTL_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_WDERF_START ( io::get( EDIP_RX_START_WDERF_ALIAS,  l_data ) );
        ffdc.set_S_WDERF_DONE  ( io::get( EDIP_RX_WDERF_DONE_ALIAS,   l_data ) );
        ffdc.set_S_WDERF_FAILED( io::get( EDIP_RX_WDERF_FAILED_ALIAS, l_data ) );
    }
    else
    {
        ffdc.set_S_WDERF_START ( INVALID_FFDC );
        ffdc.set_S_WDERF_DONE  ( INVALID_FFDC );
        ffdc.set_S_WDERF_FAILED( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_STAT2_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_LANE_BAD_0_15( io::get( EDIP_RX_LANE_BAD_VEC_0_15, l_data ) );
    }
    else
    {
        ffdc.set_S_LANE_BAD_0_15( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }


    l_rc = io::read( EDIP_RX_CTL_STAT4_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_LANE_BAD_16_23( io::get( EDIP_RX_LANE_BAD_VEC_16_23, l_data ) );
    }
    else
    {
        ffdc.set_S_LANE_BAD_16_23( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_MODE11_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_LANE_DISABLED_VEC_0_15( io::get( EDIP_RX_LANE_DISABLED_VEC_0_15, l_data ) );
    }
    else
    {
        ffdc.set_S_LANE_DISABLED_VEC_0_15( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_MODE12_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_LANE_DISABLED_VEC_16_23( io::get( EDIP_RX_LANE_DISABLED_VEC_16_23, l_data ) );
    }
    else
    {
        ffdc.set_S_LANE_DISABLED_VEC_16_23( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_MAIN_INIT_STATE( io::get( EDIP_RX_MAIN_INIT_STATE, l_data ) );
    }
    else
    {
        ffdc.set_S_MAIN_INIT_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Wiretest
    l_rc = io::read( EDIP_RX_GLBSM_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_WIRETEST_WTM_STATE( io::get( EDIP_RX_WTM_STATE, l_data ) );
        ffdc.set_S_WIRETEST_WTR_STATE( io::get( EDIP_RX_WTR_STATE, l_data ) );
    }
    else
    {
        ffdc.set_S_WIRETEST_WTM_STATE( INVALID_FFDC );
        ffdc.set_S_WIRETEST_WTR_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_STAT3_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_WIRETEST_WTL_SM_STATUS( io::get( EDIP_RX_WTL_SM_STATUS, l_data ) );
    }
    else
    {
        ffdc.set_S_WIRETEST_WTL_SM_STATUS( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT2_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_WTR_BAD_LANE_COUNT( io::get( EDIP_RX_WTR_BAD_LANE_COUNT, l_data ) );
    }
    else
    {
        ffdc.set_S_WTR_BAD_LANE_COUNT( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc =  io::read( EDIP_RX_CTL_STAT5_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_CLK_LANE_BAD_CODE   ( io::get( EDIP_RX_WT_CLK_LANE_BAD_CODE, l_data ) );
        ffdc.set_S_WT_CLK_LANE_INVERTED( io::get( EDIP_RX_WT_CLK_LANE_INVERTED, l_data ) );
    }
    else
    {
        ffdc.set_S_CLK_LANE_BAD_CODE   ( INVALID_FFDC );
        ffdc.set_S_WT_CLK_LANE_INVERTED( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Deskew

    // Eye Opt
    l_rc = io::read( EDIP_RX_GLBSM_STAT1_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_EYE_OPT_STATE( io::get( EDIP_RX_EYE_OPT_STATE, l_data ) );
    }
    else
    {
        ffdc.set_S_EYE_OPT_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_CNTL13_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_HIST_MIN_EYE_WIDTH(       io::get( EDIP_RX_HIST_MIN_EYE_WIDTH, l_data ) );
        ffdc.set_S_HIST_MIN_EYE_WIDTH_LANE(  io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_LANE, l_data ) );
        ffdc.set_S_HIST_MIN_EYE_WIDTH_VALID( io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_VALID, l_data ) );
    }
    else
    {
        ffdc.set_S_HIST_MIN_EYE_WIDTH      ( INVALID_FFDC );
        ffdc.set_S_HIST_MIN_EYE_WIDTH_LANE ( INVALID_FFDC );
        ffdc.set_S_HIST_MIN_EYE_WIDTH_VALID( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Repair
    l_rc =  io::read( EDIP_RX_GLBSM_STAT4_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_RPR_STATE( io::get( EDIP_RX_RPR_STATE, l_data ) );
    }
    else
    {
        ffdc.set_S_RPR_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT9_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_BAD_LANE1    ( io::get( EDIP_RX_BAD_LANE1,     l_data ) );
        ffdc.set_S_BAD_LANE2    ( io::get( EDIP_RX_BAD_LANE2,     l_data ) );
        ffdc.set_S_BAD_LANE_CODE( io::get( EDIP_RX_BAD_LANE_CODE, l_data ) );
    }
    else
    {
        ffdc.set_S_BAD_LANE1    ( INVALID_FFDC );
        ffdc.set_S_BAD_LANE2    ( INVALID_FFDC );
        ffdc.set_S_BAD_LANE_CODE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Deskew

    // Func Mode

    // Log FFDC
    ffdc.execute();

    return l_ffdc_rc;
}


/**
 * @brief Adds I/O FFDC Link data to the Timeout Error
 * @param[in]  i_mtarget   Master Target
 * @param[in]  i_mgroup    Master Group
 * @param[in]  i_starget   Slave Target
 * @param[in]  i_sgroup    Slave Group
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode add_linktrain_timeout_ffdc(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup )
{
    const uint8_t     LANE_00      = 0;
    const uint32_t    INVALID_FFDC = 0xFFFFFFFF;
    uint64_t          l_data       = 0;
    fapi2::ReturnCode l_ffdc_rc    = 0;
    fapi2::ReturnCode l_rc         = 0;

    // Note the return code, the return code is passed by reference and this same return code will
    // be returned at the end of the function.  The return code used in the data collection will
    // not be passed back.
    fapi2::IO_XBUS_LINKTRAIN_TIMEOUT ffdc( fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, l_ffdc_rc );

    ffdc.set_M_TARGET( i_mtarget );
    ffdc.set_M_GROUP ( i_mgroup  );
    ffdc.set_S_TARGET( i_starget );
    ffdc.set_S_GROUP ( i_sgroup  );

    ////////////////////////////////////////////////////////////////////////////
    // Master
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read( EDIP_RX_CTL_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_WDERF_START ( io::get( EDIP_RX_START_WDERF_ALIAS,  l_data ) );
        ffdc.set_M_WDERF_DONE  ( io::get( EDIP_RX_WDERF_DONE_ALIAS,   l_data ) );
        ffdc.set_M_WDERF_FAILED( io::get( EDIP_RX_WDERF_FAILED_ALIAS, l_data ) );
    }
    else
    {
        ffdc.set_M_WDERF_START ( INVALID_FFDC );
        ffdc.set_M_WDERF_DONE  ( INVALID_FFDC );
        ffdc.set_M_WDERF_FAILED( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_STAT2_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_LANE_BAD_0_15( io::get( EDIP_RX_LANE_BAD_VEC_0_15, l_data ) );
    }
    else
    {
        ffdc.set_M_LANE_BAD_0_15( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }


    l_rc = io::read( EDIP_RX_CTL_STAT4_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_LANE_BAD_16_23( io::get( EDIP_RX_LANE_BAD_VEC_16_23, l_data ) );
    }
    else
    {
        ffdc.set_M_LANE_BAD_16_23( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_MODE11_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_LANE_DISABLED_VEC_0_15( io::get( EDIP_RX_LANE_DISABLED_VEC_0_15, l_data ) );
    }
    else
    {
        ffdc.set_M_LANE_DISABLED_VEC_0_15( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_MODE12_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_LANE_DISABLED_VEC_16_23( io::get( EDIP_RX_LANE_DISABLED_VEC_16_23, l_data ) );
    }
    else
    {
        ffdc.set_M_LANE_DISABLED_VEC_16_23( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_MAIN_INIT_STATE( io::get( EDIP_RX_MAIN_INIT_STATE, l_data ) );
    }
    else
    {
        ffdc.set_M_MAIN_INIT_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Wiretest
    l_rc = io::read( EDIP_RX_GLBSM_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_WIRETEST_WTM_STATE( io::get( EDIP_RX_WTM_STATE, l_data ) );
        ffdc.set_M_WIRETEST_WTR_STATE( io::get( EDIP_RX_WTR_STATE, l_data ) );
    }
    else
    {
        ffdc.set_M_WIRETEST_WTM_STATE( INVALID_FFDC );
        ffdc.set_M_WIRETEST_WTR_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_STAT3_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_WIRETEST_WTL_SM_STATUS( io::get( EDIP_RX_WTL_SM_STATUS, l_data ) );
    }
    else
    {
        ffdc.set_M_WIRETEST_WTL_SM_STATUS( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT2_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_WTR_BAD_LANE_COUNT( io::get( EDIP_RX_WTR_BAD_LANE_COUNT, l_data ) );
    }
    else
    {
        ffdc.set_M_WTR_BAD_LANE_COUNT( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc =  io::read( EDIP_RX_CTL_STAT5_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_CLK_LANE_BAD_CODE   ( io::get( EDIP_RX_WT_CLK_LANE_BAD_CODE, l_data ) );
        ffdc.set_M_WT_CLK_LANE_INVERTED( io::get( EDIP_RX_WT_CLK_LANE_INVERTED, l_data ) );
    }
    else
    {
        ffdc.set_M_CLK_LANE_BAD_CODE   ( INVALID_FFDC );
        ffdc.set_M_WT_CLK_LANE_INVERTED( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Deskew

    // Eye Opt
    l_rc = io::read( EDIP_RX_GLBSM_STAT1_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_EYE_OPT_STATE( io::get( EDIP_RX_EYE_OPT_STATE, l_data ) );
    }
    else
    {
        ffdc.set_M_EYE_OPT_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_CNTL13_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_HIST_MIN_EYE_WIDTH(       io::get( EDIP_RX_HIST_MIN_EYE_WIDTH, l_data ) );
        ffdc.set_M_HIST_MIN_EYE_WIDTH_LANE(  io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_LANE, l_data ) );
        ffdc.set_M_HIST_MIN_EYE_WIDTH_VALID( io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_VALID, l_data ) );
    }
    else
    {
        ffdc.set_M_HIST_MIN_EYE_WIDTH      ( INVALID_FFDC );
        ffdc.set_M_HIST_MIN_EYE_WIDTH_LANE ( INVALID_FFDC );
        ffdc.set_M_HIST_MIN_EYE_WIDTH_VALID( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Repair
    l_rc =  io::read( EDIP_RX_GLBSM_STAT4_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_RPR_STATE( io::get( EDIP_RX_RPR_STATE, l_data ) );
    }
    else
    {
        ffdc.set_M_RPR_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT9_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_M_BAD_LANE1    ( io::get( EDIP_RX_BAD_LANE1,     l_data ) );
        ffdc.set_M_BAD_LANE2    ( io::get( EDIP_RX_BAD_LANE2,     l_data ) );
        ffdc.set_M_BAD_LANE_CODE( io::get( EDIP_RX_BAD_LANE_CODE, l_data ) );
    }
    else
    {
        ffdc.set_M_BAD_LANE1    ( INVALID_FFDC );
        ffdc.set_M_BAD_LANE2    ( INVALID_FFDC );
        ffdc.set_M_BAD_LANE_CODE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Deskew

    // Func Mode

    ///////////////////////////////////////////////////////////////////////////
    // Slave
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read( EDIP_RX_CTL_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_WDERF_START ( io::get( EDIP_RX_START_WDERF_ALIAS,  l_data ) );
        ffdc.set_S_WDERF_DONE  ( io::get( EDIP_RX_WDERF_DONE_ALIAS,   l_data ) );
        ffdc.set_S_WDERF_FAILED( io::get( EDIP_RX_WDERF_FAILED_ALIAS, l_data ) );
    }
    else
    {
        ffdc.set_S_WDERF_START ( INVALID_FFDC );
        ffdc.set_S_WDERF_DONE  ( INVALID_FFDC );
        ffdc.set_S_WDERF_FAILED( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_STAT2_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_LANE_BAD_0_15( io::get( EDIP_RX_LANE_BAD_VEC_0_15, l_data ) );
    }
    else
    {
        ffdc.set_S_LANE_BAD_0_15( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }


    l_rc = io::read( EDIP_RX_CTL_STAT4_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_LANE_BAD_16_23( io::get( EDIP_RX_LANE_BAD_VEC_16_23, l_data ) );
    }
    else
    {
        ffdc.set_S_LANE_BAD_16_23( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_MODE11_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_LANE_DISABLED_VEC_0_15( io::get( EDIP_RX_LANE_DISABLED_VEC_0_15, l_data ) );
    }
    else
    {
        ffdc.set_S_LANE_DISABLED_VEC_0_15( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_MODE12_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_LANE_DISABLED_VEC_16_23( io::get( EDIP_RX_LANE_DISABLED_VEC_16_23, l_data ) );
    }
    else
    {
        ffdc.set_S_LANE_DISABLED_VEC_16_23( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_MAIN_INIT_STATE( io::get( EDIP_RX_MAIN_INIT_STATE, l_data ) );
    }
    else
    {
        ffdc.set_S_MAIN_INIT_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Wiretest
    l_rc = io::read( EDIP_RX_GLBSM_STAT1_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_WIRETEST_WTM_STATE( io::get( EDIP_RX_WTM_STATE, l_data ) );
        ffdc.set_S_WIRETEST_WTR_STATE( io::get( EDIP_RX_WTR_STATE, l_data ) );
    }
    else
    {
        ffdc.set_S_WIRETEST_WTM_STATE( INVALID_FFDC );
        ffdc.set_S_WIRETEST_WTR_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_STAT3_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_WIRETEST_WTL_SM_STATUS( io::get( EDIP_RX_WTL_SM_STATUS, l_data ) );
    }
    else
    {
        ffdc.set_S_WIRETEST_WTL_SM_STATUS( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT2_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_WTR_BAD_LANE_COUNT( io::get( EDIP_RX_WTR_BAD_LANE_COUNT, l_data ) );
    }
    else
    {
        ffdc.set_S_WTR_BAD_LANE_COUNT( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc =  io::read( EDIP_RX_CTL_STAT5_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_CLK_LANE_BAD_CODE   ( io::get( EDIP_RX_WT_CLK_LANE_BAD_CODE, l_data ) );
        ffdc.set_S_WT_CLK_LANE_INVERTED( io::get( EDIP_RX_WT_CLK_LANE_INVERTED, l_data ) );
    }
    else
    {
        ffdc.set_S_CLK_LANE_BAD_CODE   ( INVALID_FFDC );
        ffdc.set_S_WT_CLK_LANE_INVERTED( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Deskew

    // Eye Opt
    l_rc = io::read( EDIP_RX_GLBSM_STAT1_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_EYE_OPT_STATE( io::get( EDIP_RX_EYE_OPT_STATE, l_data ) );
    }
    else
    {
        ffdc.set_S_EYE_OPT_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_CTL_CNTL13_EO_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_HIST_MIN_EYE_WIDTH(       io::get( EDIP_RX_HIST_MIN_EYE_WIDTH, l_data ) );
        ffdc.set_S_HIST_MIN_EYE_WIDTH_LANE(  io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_LANE, l_data ) );
        ffdc.set_S_HIST_MIN_EYE_WIDTH_VALID( io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_VALID, l_data ) );
    }
    else
    {
        ffdc.set_S_HIST_MIN_EYE_WIDTH      ( INVALID_FFDC );
        ffdc.set_S_HIST_MIN_EYE_WIDTH_LANE ( INVALID_FFDC );
        ffdc.set_S_HIST_MIN_EYE_WIDTH_VALID( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Repair
    l_rc =  io::read( EDIP_RX_GLBSM_STAT4_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_RPR_STATE( io::get( EDIP_RX_RPR_STATE, l_data ) );
    }
    else
    {
        ffdc.set_S_RPR_STATE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read( EDIP_RX_GLBSM_STAT9_E_PG, i_mtarget, i_mgroup, LANE_00, l_data );

    if( l_rc == fapi2::FAPI2_RC_SUCCESS )
    {
        ffdc.set_S_BAD_LANE1    ( io::get( EDIP_RX_BAD_LANE1,     l_data ) );
        ffdc.set_S_BAD_LANE2    ( io::get( EDIP_RX_BAD_LANE2,     l_data ) );
        ffdc.set_S_BAD_LANE_CODE( io::get( EDIP_RX_BAD_LANE_CODE, l_data ) );
    }
    else
    {
        ffdc.set_S_BAD_LANE1    ( INVALID_FFDC );
        ffdc.set_S_BAD_LANE2    ( INVALID_FFDC );
        ffdc.set_S_BAD_LANE_CODE( INVALID_FFDC );
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    // Deskew

    // Func Mode

    // Log FFDC Error
    ffdc.execute();

    return l_ffdc_rc;
}



