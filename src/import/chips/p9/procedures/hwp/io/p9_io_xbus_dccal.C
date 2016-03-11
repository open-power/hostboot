/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_dccal.C $               */
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
/// @file p9_io_xbus_dccal.C
/// @brief Train the Link.
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
/// Run Dccal
///
/// Dccal is completed on all thin/thick PHYs:
///     - XBUS(EDIP)
///
/// Procedure Prereq:
///     - System clocks are running.
///     - Scominit Procedure is completed.
///
/// @endverbatim
///----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_xbus_dccal.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

//-----------------------------------------------------------------------------
// Function Declarations
//-----------------------------------------------------------------------------

/**
 * @brief Tx Z Impedance Calibration
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @param[in] i_flags  Dccal Attribute Flags
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_z_cal(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    const uint8_t&                                   i_flags );

/**
 * @brief Tx Z Impedance Calibration State Machine
 * @param[in] i_target FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_z_cal_run_sm( const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target );

/**
 * @brief Tx Z Impedance Calibration Verify Results
 * @param[in] i_target FAPI2 Target
 * @param[in] io_pval  Tx Zcal P-value
 * @param[in] io_nval  Tx Zcal N-value
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_z_cal_get_results(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    uint32_t&                                        io_pval,
    uint32_t&                                        io_nval );

/**
 * @brief Tx Z Impedance Calibration Apply Segments
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @param[in] i_pval   Tx Zcal P-value
 * @param[in] i_nval   Tx Zcal N-value
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_z_cal_apply_segments(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    const uint32_t&                                  i_pval,
    const uint32_t&                                  i_nval );

/**
 * @brief Rx Dc Calibration
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_dc_cal(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group );

/**
 * @brief Rx Dc Calibration Poll
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_dc_cal_poll(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group );

/**
 * @brief Rx Dc Calibration Set Lanes Invalid
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @param[in] i_data   Data to Set Lanes Invalid
 * @retval ReturnCode
 */
fapi2::ReturnCode set_lanes_invalid(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
    const uint8_t&                                i_group,
    const uint8_t&                                i_data );
//-----------------------------------------------------------------------------
//  Function Definitions
//-----------------------------------------------------------------------------


/**
 * @brief A I/O EDI+ Procedure that runs Rx Dccal and Tx Z Impedance calibration
 * on every instance of the XBUS.
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_dccal(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group )
{
    FAPI_IMP( "p9_io_xbus_dccal: I/O EDI+ Xbus Entering" );
    uint8_t l_dccal_flags = 0x0;

    // Check if Tx Impedance Calibration or Rx Dc Calibration has been run.
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_IO_XBUS_DCCAL_FLAGS, i_target, l_dccal_flags ) );

    FAPI_DBG( "p9_io_xbus_dccal: I/O EDI+ Xbus Dccal Flags Tx(%d) Rx(%d)",
              ( l_dccal_flags & fapi2::ENUM_ATTR_IO_XBUS_DCCAL_FLAGS_TX ) ? 1 : 0,
              ( l_dccal_flags & fapi2::ENUM_ATTR_IO_XBUS_DCCAL_FLAGS_RX ) ? 1 : 0 );

    ///////////////////////////////////////////////////////////////////////////
    // Tx Impedance Calibraiton
    ///////////////////////////////////////////////////////////////////////////
    FAPI_TRY( tx_z_cal( i_target, i_group, l_dccal_flags ),
              "p9_io_xbus_dccal: I/O Edi+ Xbus Tx Z Calibration Run Failed" );

    l_dccal_flags |= fapi2::ENUM_ATTR_IO_XBUS_DCCAL_FLAGS_TX;
    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_IO_XBUS_DCCAL_FLAGS, i_target, l_dccal_flags ) );

    ///////////////////////////////////////////////////////////////////////////
    // Rx DC Calibraiton
    ///////////////////////////////////////////////////////////////////////////
    FAPI_TRY( rx_dc_cal( i_target, i_group ),
              "p9_io_xbus_dccal: I/O Edi+ Xbus Rx DC Calibration Run Failed" );

    l_dccal_flags |= fapi2::ENUM_ATTR_IO_XBUS_DCCAL_FLAGS_RX;
    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_IO_XBUS_DCCAL_FLAGS, i_target, l_dccal_flags ) );


fapi_try_exit:
    FAPI_IMP( "p9_io_xbus_dccal: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @param[in] i_flags  Dccal Attribute Flags
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_z_cal(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    const uint8_t&                                   i_flags )
{
    uint32_t l_pval = 25 * 4; // Nominal 25 Segments 1R * 4 = 4R
    uint32_t l_nval = 25 * 4; // Nominal 25 Segments 1R * 4 = 4R

    FAPI_IMP( "tx_z_cal: I/O EDI+ Xbus Entering" );

    if( !( i_flags & fapi2::ENUM_ATTR_IO_XBUS_DCCAL_FLAGS_TX ) )
    {
        FAPI_INF( "tx_z_cal: I/O EDI+ Xbus Tx Impedance Calibration is Required." );

        FAPI_TRY( tx_z_cal_run_sm( i_target ), "tx_z_cal: Tx Z Cal Run Failed" );
    }

    // If zCal ran successfully use the found values, else we will use the nominal default values.
    // Also check to make sure the values are within the bounds of acceptable values.
    FAPI_TRY( tx_z_cal_get_results( i_target, l_pval, l_nval ),
              "tx_z_cal: Tx Z Cal Get Results Failed" );

    // Convert the results of the zCal to actual segments.
    FAPI_TRY( tx_z_cal_apply_segments( i_target, i_group, l_pval, l_nval ),
              "tx_z_cal: Tx Z Cal Apply Segments Failed" );

fapi_try_exit:
    FAPI_IMP( "tx_z_cal: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration State Machine
 * @param[in] i_target FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_z_cal_run_sm( const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target )
{
    const uint32_t TIMEOUT    = 200;
    const uint64_t POLL_NS    = 500;
    const uint64_t SIM_CYCLES = 1000000;
    const uint8_t GROUP_00    = 0;
    const uint8_t LANE_00     = 0;
    uint32_t l_count          = 0;
    uint64_t l_data           = 0;

    FAPI_IMP( "tx_z_cal_run_sm: I/O EDI+ Xbus Entering" );


#if 0 ////////////////////////////////////
    // To speed up simulation, xbus_unit model + pie driver
    //   without these settings: 50 million cycles
    //   with these settings: 13 million cycles
    io::set( EDIP_TX_ZCAL_SM_MIN_VAL, 50, l_data );
    io::set( EDIP_TX_ZCAL_SM_MAX_VAL, 52, l_data );
    FAPI_TRY( io::write( EDIP_TX_IMPCAL_SWO2_PB, i_target, GROUP_00, LANE_00, l_data ) );
#endif ///////////////////////////////////

    // Request to start Tx Impedance Calibration
    // The Done bit is read only pulse, must use pie driver or system model in sim
    FAPI_TRY( io::rmw( EDIP_TX_ZCAL_REQ, i_target, GROUP_00, LANE_00, 1 ),
              "tx_z_cal_run_sm: RMW Tx Zcal Req Failed");

    // Poll Until Tx Impedance Calibration is done or errors out
    FAPI_TRY( io::read( EDIP_TX_IMPCAL_PB, i_target, GROUP_00, LANE_00, l_data ),
              "tx_z_cal_run_sm: Reading Tx Impcal Pb Failed" );

    while( ( ++l_count < TIMEOUT ) &&
           !( io::get( EDIP_TX_ZCAL_DONE, l_data ) || io::get( EDIP_TX_ZCAL_ERROR, l_data ) ) )
    {
        FAPI_DBG( "tx_z_cal_run_sm: I/O EDI+ Xbus Tx Zcal Poll, Count(%d/%d).", l_count, TIMEOUT );

        FAPI_TRY( fapi2::delay( POLL_NS, SIM_CYCLES ),
                  "tx_z_cal_run_sm: Fapi Delay Failed." );

        FAPI_TRY( io::read( EDIP_TX_IMPCAL_PB, i_target, GROUP_00, LANE_00, l_data ),
                  "tx_z_cal_run_sm: Reading Tx Impcal Pb Failed" );
    }

    if( io::get( EDIP_TX_ZCAL_DONE, l_data ) == 0 )
    {
        FAPI_ERR( "tx_z_cal_run_sm: WARNING: Tx Z Calibration Timeout: Loops(%d)", l_count );
    }

    if( io::get( EDIP_TX_ZCAL_ERROR, l_data ) == 1 )
    {
        FAPI_ERR( "tx_z_cal_run_sm: WARNING: Tx Z Calibration Error" );
    }

fapi_try_exit:
    FAPI_IMP( "tx_z_cal-run_sm: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration Get Results
 * @param[in] i_target FAPI2 Target
 * @param[in] io_pval  Tx Zcal P-value
 * @param[in] io_nval  Tx Zcal N-value
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_z_cal_get_results(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    uint32_t&                                        io_pval,
    uint32_t&                                        io_nval )
{
    // l_zcal_p and l_zcal_n are 9 bit registers
    // These are also 4x of a 1R segment
    const uint32_t ZCAL_MIN = 16 * 4; // 16 segments * 4 = 64 (0x40)
    const uint32_t ZCAL_MAX = 33 * 4; // 33 segments * 4 = 132(0x84)
    const uint8_t  GROUP_00 = 0;
    const uint8_t  LANE_00  = 0;
    uint64_t       l_data   = 0;
    FAPI_IMP( "tx_z_cal_get_results: I/O EDI+ Xbus Entering" );

    // Read Tx Impedance Calibration Register to check if the zcal P & N values are valid
    FAPI_TRY( io::read( EDIP_TX_IMPCAL_PB, i_target, GROUP_00, LANE_00, l_data ),
              "tx_z_cal_get_results: Reading Tx Impcal Pb Failed" );

    if( io::get( EDIP_TX_ZCAL_DONE, l_data ) == 1 && io::get( EDIP_TX_ZCAL_ERROR, l_data ) == 0 )
    {
        FAPI_DBG( "tx_z_cal_get_results: Using zCal Results." );

        FAPI_TRY( io::read( EDIP_TX_ZCAL_P, i_target, GROUP_00, LANE_00, l_data ),
                  "tx_z_cal_get_results: tx_impcal_pval_pb read fail" );
        io_pval = io::get( EDIP_TX_ZCAL_P, l_data );

        FAPI_TRY( io::read( EDIP_TX_ZCAL_N, i_target, GROUP_00, LANE_00, l_data ),
                  "tx_z_cal_get_results: tx_impcal_nval_pb read fail" );
        io_nval = io::get( EDIP_TX_ZCAL_N, l_data );
    }
    else
    {
        FAPI_DBG( "tx_z_cal_get_results: Using Default Segments." );
        io_pval = 25 * 4; // Nominal 25 Segments 1R * 4 = 4R
        io_nval = 25 * 4; // Nominal 25 Segments 1R * 4 = 4R
    }

    FAPI_DBG( "tx_z_cal_get_results: Min/Max Allowed(0x%X,0x%X) Read Pval/Nval(0x%X,0x%X)",
              ZCAL_MIN,
              ZCAL_MAX,
              io_pval,
              io_nval );


    if( io_pval > ZCAL_MAX )
    {
        io_pval = ZCAL_MAX;
        FAPI_ERR( "tx_z_cal_get_results: Tx Zcal Pval(0x%X) > Max Allowed(0x%X)",
                  io_pval, ZCAL_MAX );
    }

    if( io_nval > ZCAL_MAX )
    {
        io_nval = ZCAL_MAX;
        FAPI_ERR( "tx_z_cal_get_results: Tx Zcal Nval(0x%X) > Max Allowed(0x%X)",
                  io_nval, ZCAL_MAX );
    }

    if( io_pval < ZCAL_MIN )
    {
        io_pval = ZCAL_MIN;
        FAPI_ERR( "tx_z_cal_get_results: Tx Zcal Pval(0x%X) < Min Allowed(0x%X)",
                  io_pval, ZCAL_MIN );
    }

    if( io_nval < ZCAL_MIN )
    {
        io_nval = ZCAL_MIN;
        FAPI_ERR( "tx_z_cal_get_results: Tx Zcal Nval(0x%X) < Min Allowed(0x%X)",
                  io_nval, ZCAL_MIN );
    }

fapi_try_exit:
    FAPI_IMP( "tx_z_cal_get_results: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration Apply Segments.  The results of the Tx Impedance
 *   calibrationMargining and FFE Precursor
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @param[in] i_pval   Tx Zcal P-value
 * @param[in] i_nval   Tx Zcal N-value
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_z_cal_apply_segments(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group,
    const uint32_t&                                  i_pval,
    const uint32_t&                                  i_nval )
{
    FAPI_IMP( "tx_z_cal_apply_segments: I/O EDI+ Xbus Entering" );

    //const uint32_t PRE_1R        = 4;
    //const uint32_t PRE_2R        = 1;
    const uint32_t MARGIN_1R       = 8;
    const uint32_t MARGIN_2R       = 0;
    const uint32_t MAIN_1R         = 12;
    const uint32_t MAIN_2R         = 1;
    //const uint32_t PRE_4R_TOTAL  = ( PRE_1R    * 4 ) + ( PRE_2R    * 2 );
    const uint32_t MARGIN_4R_TOTAL = ( MARGIN_1R * 4 ) + ( MARGIN_2R * 2 );
    const uint32_t MAIN_4R_TOTAL   = ( MAIN_1R   * 4 ) + ( MAIN_2R   * 2 );

    // During normal opertation we will not use margining, we will use this during
    //   High Speed I/O Characterization.
    const float    MARGIN_RATIO    = 0;  // 0(0%) 0.5(50%)

    // Based on worst case channel simulations for Witherspoon, we will use
    //   -4.8% FFE Precursor Tap Weight
    const float   PRECURSOR_COEF   = 0.048; // 0(0%) 0.115(11.5%)
    const uint8_t LANE_00          = 0;

    // :: Set the Selected Bank Segments
    // Apply Calcualted Segments to margin/pre/main banks accordingly
    // 1. Apply Segments to Margining first
    // 2. Apply Segments to Pre-Cursor second
    // 3. Apply Segments to Main last
    uint64_t l_data          = 0;

    // i_pval will be promoted to a float, then the decimal bits will be truncated as the value
    //   is returned as a uint32_t.  This is okay as we are already working in 4R steps.
    uint32_t sel_margin_pu   = (uint32_t)( i_pval * MARGIN_RATIO );

    // To protect against selecting too many margining segments
    if( sel_margin_pu > MARGIN_4R_TOTAL )
    {
        sel_margin_pu = MARGIN_4R_TOTAL;
    }

    uint32_t sel_margin_pd   = (uint32_t)( i_nval * MARGIN_RATIO );

    // To protect against selecting too many margining segments
    if( sel_margin_pd > MARGIN_4R_TOTAL )
    {
        sel_margin_pd = MARGIN_4R_TOTAL;
    }

    // For the selects to work, we need to enable at least the amount of selected segments.
    uint32_t p_en_margin_pu  = sel_margin_pu;
    uint32_t p_en_margin_pd  = sel_margin_pd;
    uint32_t n_en_margin_pu  = sel_margin_pu;
    uint32_t n_en_margin_pd  = sel_margin_pd;

    // The result of i_pval and sel_margin_* will be promoeted to a float, then the decimal bits
    //   will be truncated as the value will be returned as a uint32_t.  This is okay as we are
    //   working in 4R steps.
    uint32_t p_sel_pre = (uint32_t)( ( i_pval - sel_margin_pu - sel_margin_pd ) * PRECURSOR_COEF );
    uint32_t n_sel_pre = (uint32_t)( ( i_nval - sel_margin_pu - sel_margin_pd ) * PRECURSOR_COEF );
    uint32_t p_en_pre  = p_sel_pre;
    uint32_t n_en_pre  = n_sel_pre;

    // Apply the leftover segments that are not used fro the selects to the main segment bank
    uint32_t p_en_main = i_pval - sel_margin_pu - sel_margin_pd - p_sel_pre;
    uint32_t n_en_main = i_nval - sel_margin_pu - sel_margin_pd - n_sel_pre;

    // Apply the segments across the main, margin, and pre banks to ensure we have the appropriate
    //  number of segments applied.
    if( p_en_main > MAIN_4R_TOTAL)
    {
        p_en_margin_pu += ( p_en_main - MAIN_4R_TOTAL );
        p_en_main = MAIN_4R_TOTAL;

        if( p_en_margin_pu > MARGIN_4R_TOTAL )
        {
            p_en_margin_pd += ( p_en_margin_pu - MARGIN_4R_TOTAL );
            p_en_margin_pu = MARGIN_4R_TOTAL;

            if( p_en_margin_pd > MARGIN_4R_TOTAL )
            {
                // p_en_pre is garanteed to be in range as we have checked the range of the
                //   results in tx_z_cal_get_results
                p_en_pre += ( p_en_margin_pd - MARGIN_4R_TOTAL );
                p_en_margin_pd = MARGIN_4R_TOTAL;
            }
        }
    }

    // Apply the segments across the main, margin, and pre banks to ensure we have the appropriate
    //  number of segments applied.
    if( n_en_main > MAIN_4R_TOTAL )
    {
        n_en_margin_pd += ( n_en_main - MAIN_4R_TOTAL );
        n_en_main = MAIN_4R_TOTAL;

        if( n_en_margin_pd > MARGIN_4R_TOTAL )
        {
            n_en_margin_pu += ( n_en_margin_pd - MARGIN_4R_TOTAL );
            n_en_margin_pd = MARGIN_4R_TOTAL;

            if( n_en_margin_pu > MARGIN_4R_TOTAL )
            {
                // n_en_pre is garanteed to be in range as we have checked the range of the
                //   results in tx_z_cal_get_results
                n_en_pre += ( n_en_margin_pu - MARGIN_4R_TOTAL );
                n_en_margin_pu = MARGIN_4R_TOTAL;
            }
        }
    }

    // We can write these registers without reading, since we are writing
    //   the entire register.  To convert the 4R values to needed register values,
    //   we will  add the appropriate amount and shift to convert to 1R or
    //   1R + a 2R.
    l_data = 0;
    io::set( EDIP_TX_PSEG_PRE_SEL, ( p_sel_pre + 1 ) >> 1, l_data );
    io::set( EDIP_TX_PSEG_PRE_EN, ( p_en_pre + 1 ) >> 1, l_data );
    FAPI_TRY( io::write( EDIP_TX_CTLSM_CNTL1_EO_PG, i_target, i_group, LANE_00, l_data ),
              "tx_z_cal_apply_segments: Pseg Pre Write Fail" );

    l_data = 0;
    io::set( EDIP_TX_NSEG_PRE_SEL, ( n_sel_pre + 1 ) >> 1, l_data );
    io::set( EDIP_TX_NSEG_PRE_EN, ( n_en_pre + 1 ) >> 1, l_data );
    FAPI_TRY( io::write( EDIP_TX_CTLSM_CNTL2_EO_PG, i_target, i_group, LANE_00, l_data ),
              "tx_z_cal_apply_segments: Nseg Pre Write Fail" );

    l_data = 0;
    io::set( EDIP_TX_PSEG_MARGINPD_EN, ( p_en_margin_pd + 2 ) >> 2, l_data );
    io::set( EDIP_TX_PSEG_MARGINPU_EN, ( p_en_margin_pu + 2 ) >> 2, l_data );
    FAPI_TRY( io::write( EDIP_TX_CTLSM_CNTL3_EO_PG, i_target, i_group, LANE_00, l_data ),
              "tx_z_cal_apply_segments: Pseg Margin Write Fail" );

    l_data = 0;
    io::set( EDIP_TX_NSEG_MARGINPD_EN, ( n_en_margin_pd + 2 ) >> 2, l_data );
    io::set( EDIP_TX_NSEG_MARGINPU_EN, ( n_en_margin_pu + 2 ) >> 2, l_data );
    FAPI_TRY( io::write( EDIP_TX_CTLSM_CNTL4_EO_PG, i_target, i_group, LANE_00, l_data ),
              "tx_z_cal_apply_segments: Nseg Margin Write Fail" );

    l_data = 0;
    io::set( EDIP_TX_MARGINPD_SEL, ( sel_margin_pd + 2 ) >> 2, l_data );
    io::set( EDIP_TX_MARGINPU_SEL, ( sel_margin_pu + 2 ) >> 2, l_data );
    FAPI_TRY( io::write( EDIP_TX_CTLSM_CNTL5_EO_PG, i_target, i_group, LANE_00, l_data ),
              "tx_z_cal_apply_segments: Margin Write Fail" );

    l_data = 0;
    io::set( EDIP_TX_PSEG_MAIN_EN, ( p_en_main + 1 ) >> 1, l_data );
    FAPI_TRY( io::write( EDIP_TX_CTLSM_CNTL6_EO_PG, i_target, i_group, LANE_00, l_data ),
              "tx_z_cal_apply_segments: Pseg Main Write Fail" );

    l_data = 0;
    io::set( EDIP_TX_NSEG_MAIN_EN, ( n_en_main + 1 ) >> 1, l_data );
    FAPI_TRY( io::write( EDIP_TX_CTLSM_CNTL7_EO_PG, i_target, i_group, LANE_00, l_data ),
              "tx_z_cal_apply_segments: Nseg Main Write Fail" );

fapi_try_exit:
    FAPI_IMP( "tx_z_cal_apply_segments: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Rx Dc Calibration
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_dc_cal (
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group )
{
    FAPI_IMP( "rx_dc_cal: I/O EDI+ Xbus Entering" );
    const uint8_t LANE_00 = 0;

    // Must set lane invalid bit to 0 to run rx dccal
    FAPI_TRY( set_lanes_invalid( i_target, i_group, 0 ),
              "rx_dc_cal: Error Setting Lane Invalid to 0" );

    // Clear the rx dccal done bit in case rx dccal was previously run.
    FAPI_TRY( io::rmw( EDIP_RX_DC_CALIBRATE_DONE, i_target, i_group, LANE_00, 0),
              "rx_dc_cal: RMW Dccal Done Failed" );

    // Start DC Calibrate, this iniates the rx dccal state machine
    FAPI_TRY( io::rmw( EDIP_RX_START_DC_CALIBRATE, i_target, i_group, LANE_00, 1 ),
              "rx_dc_cal: RMW Start Dccal Failed" );

    // Poll to see if rx dccal is done on the specified target / group.
    FAPI_TRY( rx_dc_cal_poll( i_target, i_group ), "rx_dc_cal: Poll Rx DcCal Failed" );

    // Stop DC Calibrate
    FAPI_TRY( io::rmw( EDIP_RX_START_DC_CALIBRATE, i_target, i_group, LANE_00, 0 ),
              "rx_dc_cal: Stopping Dccal Failed" );

    // Restore the invalid bits, Wiretest will modify these as training is run.
    FAPI_TRY( set_lanes_invalid( i_target, i_group, 1 ),
              "rx_dc_cal: Error Setting Lane Invalid to 1" );

    FAPI_DBG( "rx_dc_cal: I/O EDI+ Xbus Rx Dccal Complete on Group(%d)", i_group );


fapi_try_exit:
    FAPI_IMP( "rx_dc_cal: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Rx Dc Calibration Poll
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_dc_cal_poll(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_group )
{
    FAPI_IMP( "rx_dc_cal_poll: I/O EDI+ Xbus Entering" );
    const uint8_t  TIMEOUT      = 200;
    const uint64_t POLL_NS      = 500;
    const uint64_t SIM_CYCLES   = 25000000;
    const uint8_t  LANE_00      = 0;
    uint8_t        l_poll_count = 0;
    uint64_t       l_data       = 0;

    do
    {
        FAPI_DBG( "rx_dc_cal_poll: I/O EDI+ Xbus Rx Dccal Polling Count(%d/%d).",
                  l_poll_count, TIMEOUT );

        FAPI_TRY( fapi2::delay( POLL_NS, SIM_CYCLES ), "rx_dc_cal_poll: Fapi Delay Failed." );

        FAPI_TRY( io::read( EDIP_RX_DC_CALIBRATE_DONE, i_target, i_group, LANE_00, l_data ),
                  "rx_dc_cal_poll: Read Dccal Done Failed" );
    }
    while( ( ++l_poll_count < TIMEOUT ) && !io::get( EDIP_RX_DC_CALIBRATE_DONE, l_data ) );

    FAPI_ASSERT( ( io::get( EDIP_RX_DC_CALIBRATE_DONE, l_data ) == 1 ),
                 fapi2::IO_XBUS_RX_DCCAL_TIMEOUT().set_TARGET( i_target ).set_GROUP( i_group ),
                 "rx_dc_cal_poll: Rx Dccal Timeout: Loops(%d) delay(%d ns, %d cycles)",
                 l_poll_count, POLL_NS, SIM_CYCLES );

fapi_try_exit:
    FAPI_IMP( "rx_dc_cal_poll: I/O EDI+ Xbus Exiting" );
    return fapi2::current_err;
}

/**
 * @brief Rx Dc Calibration Set Lanes Invalid
 * @param[in] i_target FAPI2 Target
 * @param[in] i_group  Clock Group
 * @param[in] i_data   Data to Set Lanes Invalid
 * @retval ReturnCode
 */
fapi2::ReturnCode set_lanes_invalid(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
    const uint8_t&                                i_group,
    const uint8_t&                                i_data )
{
    const uint8_t XBUS_LANES = 17;

    FAPI_IMP( "set_lanes_invalid: I/O EDI+ Xbus Entering" );

    for( uint8_t lane = 0; lane < XBUS_LANES; ++lane )
    {
        FAPI_TRY( io::rmw( EDIP_RX_LANE_INVALID, i_target, i_group, lane, i_data ),
                  "set_lanes_invalid: RMW Invalid Lane Failed" );
    }

fapi_try_exit:
    FAPI_IMP( "set_lanes_invalid: I/O EDI+ Xbus: Exiting" );
    return fapi2::current_err;
}

