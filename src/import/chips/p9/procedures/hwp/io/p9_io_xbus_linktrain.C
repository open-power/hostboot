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
 * @brief Checks if the Xbus target is set to Master Mode
 * @param[in] i_target  Fapi2 Target
 * @retval    ReturnCode
 */
fapi2::ReturnCode verify_master_mode( const fapi2::Target <fapi2::TARGET_TYPE_XBUS >& i_target );




/**
 * @brief A HWP that runs on every instance of the XBUS(EDI+)
 * @param[in] i_mtarget Reference to the Master Target
 * @param[in] i_mgroup  Master Target Clock Group
 * @param[in] i_starget Reference to the Slave Target
 * @param[in] i_sgroup  Slave Target Clock Group
 * @retval    ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_linktrain(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_mtarget,
    const uint8_t&                                   i_mgroup,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_starget,
    const uint8_t&                                   i_sgroup )
{
    FAPI_IMP( "p9_io_xbus_linktrain: P9 I/O EDI+ Xbus Entering" );

    char l_mstring[fapi2::MAX_ECMD_STRING_LEN];
    char l_sstring[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString( i_mtarget, l_mstring, fapi2::MAX_ECMD_STRING_LEN );
    fapi2::toString( i_starget, l_sstring, fapi2::MAX_ECMD_STRING_LEN );

    FAPI_DBG( "I/O Xbus Targets: Master(%s:g%d) Slave(%s:g%d)",
              l_mstring, i_mgroup,
              l_sstring, i_sgroup );

    // Check if master target is actually master.
    FAPI_TRY( verify_master_mode( i_mtarget ) );

    // Start Slave Target Link Training
    FAPI_TRY( linktrain_start( i_starget, i_sgroup, State::WDERF ), "Start Slave Training Failed" );

    // Start Master Target Link Training
    FAPI_TRY( linktrain_start( i_mtarget, i_mgroup, State::WDERF ), "Start Master Training Failed." );

    // Poll for Training to Complete on Master Target
    FAPI_TRY( linktrain_poll( i_mtarget, i_mgroup, i_starget, i_sgroup, State::WDERF ), "Polling Failed" );

fapi_try_exit:
    FAPI_IMP( "p9_io_xbus_linktrain: P9 I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Checks if the Xbus target is set to Master Mode
 * @param[in] i_target  Fapi2 Target
 * @retval    ReturnCode
 */
fapi2::ReturnCode verify_master_mode( const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target )
{
    uint8_t l_master_mode = 0;

    FAPI_IMP( "verify_master_mode: P9 I/O EDI+ Xbus Entering" );

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IO_XBUS_MASTER_MODE, i_target, l_master_mode) );

    FAPI_ASSERT( ( l_master_mode == fapi2::ENUM_ATTR_IO_XBUS_MASTER_MODE_TRUE ),
                 fapi2::IO_XBUS_NOT_MASTER().set_TARGET( i_target ),
                 "I/O Xbus Target is not Master" );

fapi_try_exit:
    FAPI_IMP( "verify_master_mode: P9 I/O EDI+ Xbus Exiting" );
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



