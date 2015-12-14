/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_dccal.C $               */
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
///     - XBUS(EDIP), DMI(EDIP), OBUS(OPT), ABUS(OPT)
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
#include <p9_io_gcr.H>
#include <p9_io_regs.H>

//-----------------------------------------------------------------------------
// Function Declarations
//-----------------------------------------------------------------------------
fapi2::ReturnCode txZCal(const fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target);

fapi2::ReturnCode txZCalGetResults(const fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target,
                                   float& i_pval,
                                   float& i_nval);

fapi2::ReturnCode txZCalSetParms(const fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target,
                                 const uint8_t i_group,
                                 const float i_pval,
                                 const float i_nval);

fapi2::ReturnCode rxDccal(const fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target);

fapi2::ReturnCode rxDccalPoll(const fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target,
                              const uint8_t i_group);

fapi2::ReturnCode setLaneInvalid(fapi2::Target<fapi2::TARGET_TYPE_XBUS> i_target,
                                 uint8_t i_group,
                                 uint8_t data);

uint32_t round(const float input, const uint32_t width2r);

//-----------------------------------------------------------------------------
//  Function Definitions
//-----------------------------------------------------------------------------


/**
 * @brief A I/O EDI+ Procedure that runs Rx Dccal and Tx Z Impedance calibration
 * on every instance of the XBUS.
 * @param[in] i_target FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode
p9_io_xbus_dccal(const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target)
{
    FAPI_IMP("Entering...");


    // We cannot run tx impedance calibration while using broadside scoms.
    // The request pulse is not a physical latch and get optimized out when
    // using the broadside scoms.  Once the pie driver ready, we can run
    // realscoms and tx zcal will work.
#if 0
    FAPI_TRY(txZCal(i_target), "I/O Edi+ Xbus Tx Z Calibration Run Failed");
#endif

    FAPI_TRY(rxDccal(i_target), "I/O Edi+ Xbus Rx DC Calibration Run Failed");

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

/**
 * @brief Runs Tx Impedance Calibration.
 * @param[in] i_target FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode txZCal(fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target)
{
    FAPI_IMP("Entering...");
    const uint8_t TIMEOUT      = 255;
    const uint64_t POLL_NS     = 500;
    const uint64_t SIM_CYCLES = 50000000;
    Register<EDIP_TX_IMPCAL_PB> tx_impcal_pb;
    uint8_t l_poll_count = 0;
    uint8_t l_dccal_flags = 0x0;
    float l_zcalp = 25 * 2; // Nominal 2R Value
    float l_zcaln = 25 * 2; // Nominal 2R Value

    FAPI_INF("Checking I/O Xbus Dccal Flags.");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_XBUS_DCCAL_FLAGS, i_target, l_dccal_flags));

    if(l_dccal_flags & fapi2::ENUM_ATTR_IO_XBUS_DCCAL_FLAGS_TX)
    {
        FAPI_INF("I/O EDI+ Xbus Tx Impedance Calibration has been previously ran.");
    }
    else
    {
        FAPI_INF("I/O EDI+ Xbus Tx Impedance Calibration is Required.");
    }

    // Request to start Tx Impedance Calibration
    // The Done bit is read only
    FAPI_TRY( tx_impcal_pb.read(i_target), "Read tx_impcal_pb Failed.");
    tx_impcal_pb.set<EDIP_TX_ZCAL_REQ>(1);
    FAPI_TRY(tx_impcal_pb.write(i_target), "Starting Tx Zcal Failed.");

    // Poll Until Tx Impedance Calibration is done or errors out
    while( (l_poll_count < TIMEOUT) && !( tx_impcal_pb.get<EDIP_TX_ZCAL_DONE>() ||
                                          tx_impcal_pb.get<EDIP_TX_ZCAL_ERROR>() ) )
    {
        FAPI_DBG("I/O EDI+ Xbus Tx Zcal Poll, Count(%d/%d).", l_poll_count, TIMEOUT);

        FAPI_TRY(tx_impcal_pb.read(i_target), "Read tx_impcal_pb Failed.")

        FAPI_TRY( fapi2::delay(POLL_NS, SIM_CYCLES), "Fapi Delay Failed.");
        ++l_poll_count;
    }

    if( (tx_impcal_pb.get<EDIP_TX_ZCAL_DONE>() == 0) ||
        (tx_impcal_pb.get<EDIP_TX_ZCAL_ERROR>() == 1) )
    {
        FAPI_ERR("Tx Zcal Timeout/Error.  Attempting to use Nominal zCal values.");
        l_zcalp = 25 * 2; // Nominal 2R Value
        l_zcaln = 25 * 2; // Nominal 2R Value
    }
    else
    {
        FAPI_TRY( txZCalGetResults(i_target, l_zcalp, l_zcaln),
                  "Get Tx Zcal Results Failed" );
    }

#if 0 // Broadcast group scoms do not work with broadside scom loads
    //   We will now read the encoded values and do the floating
    //   point math to calculate the pre-cursor, margin, and total_en segments.
    FAPI_TRY(txZCalSetParms(i_target, BROADCAST_GROUP, l_zcalp, l_zcaln),
             "Calculate Tx FFE Parameters Failed");
#else

    for(uint8_t l_group = 0; l_group < 2; ++l_group)
    {
        FAPI_TRY(txZCalSetParms(i_target, l_group, l_zcalp, l_zcaln),
                 "Calculate Tx FFE Parameters Failed");
    }

#endif

    l_dccal_flags |= fapi2::ENUM_ATTR_IO_XBUS_DCCAL_FLAGS_TX;
    FAPI_ATTR_SET(fapi2::ATTR_IO_XBUS_DCCAL_FLAGS, i_target,
                  l_dccal_flags);

    FAPI_ASSERT( (tx_impcal_pb.get<EDIP_TX_ZCAL_DONE>() == 1),
                 fapi2::IO_XBUS_TX_ZCAL_TIMEOUT().set_TARGET(i_target),
                 "Tx zCal Timeout: Loops(%d) delay(%d ns, %d cycles)",
                 l_poll_count, POLL_NS, SIM_CYCLES);

    FAPI_ASSERT( (tx_impcal_pb.get<EDIP_TX_ZCAL_ERROR>() != 1),
                 fapi2::IO_XBUS_TX_ZCAL_ERROR().set_TARGET(i_target),
                 "I/O EDI+ Xbus Tx Impedance Calibration Error.");

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}


/**
 * @brief Calculate the total number of P segments and N segments (pre-cursor,
 * post-cursor, magin, and main slice) based on the Tx Impedance Calibration
 * results (tx_l_zcal_p and tx_l_zcal_n).
 * @param[in] i_target   Reference to the Current Target
 * @param[in] i_group    Clock Group
 * @retval fapi2::current_err
 */
fapi2::ReturnCode txZCalGetResults(const fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target,
                                   float& o_pval,
                                   float& o_nval)
{
    FAPI_IMP("Entering...");

    // l_zcal_p and l_zcal_n are 9 bit registers
    // These are also 4x of a 1R segment
    const uint32_t ZCAL_MIN       = 0x40; // 16 segments * 4 = 64 (0x40)
    const uint32_t ZCAL_MAX       = 0x84; // 33 segments * 4 = 132(0x84)

    Register<EDIP_TX_IMPCAL_PVAL_PB> l_pval_reg;
    Register<EDIP_TX_IMPCAL_NVAL_PB> l_nval_reg;

    FAPI_TRY( l_pval_reg.read(i_target), "tx_impcal_pval_pb read fail");
    FAPI_TRY( l_nval_reg.read(i_target), "tx_impcal_nval_pb read fail");


    FAPI_DBG("I/O EDI+ zCal: Min/Max Allowed(0x%X,0x%X) Read Pval/Nval(0x%X,0x%X)",
             ZCAL_MIN,
             ZCAL_MAX,
             l_pval_reg.get<EDIP_TX_ZCAL_P>(),
             l_nval_reg.get<EDIP_TX_ZCAL_N>());

    o_pval = (float)l_pval_reg.get<EDIP_TX_ZCAL_P>() / 2;
    o_nval = (float)l_nval_reg.get<EDIP_TX_ZCAL_N>() / 2;

    if( l_pval_reg.get<EDIP_TX_ZCAL_P>() > ZCAL_MAX )
    {
        // Convert from 4R to 2R
        o_pval = (float)ZCAL_MAX / 2;
        FAPI_ERR("Tx Zcal Pval(0x%X) > Max Allowed(0x%X)",
                 l_pval_reg.get<EDIP_TX_ZCAL_P>(), ZCAL_MAX);
        fapi2::IO_XBUS_TX_ZCAL_OUT_OF_RANGE().set_TARGET(i_target)
        .set_ZCAL_P(l_pval_reg.get<EDIP_TX_ZCAL_P>())
        .set_ZCAL_N(l_nval_reg.get<EDIP_TX_ZCAL_N>())
        .execute();
    }

    if( l_nval_reg.get<EDIP_TX_ZCAL_N>() > ZCAL_MAX )
    {
        // Convert from 4R to 2R
        o_nval = (float)ZCAL_MAX / 2;
        FAPI_ERR("Tx Zcal Nval(0x%X) > Max Allowed(0x%X)",
                 l_nval_reg.get<EDIP_TX_ZCAL_N>(), ZCAL_MAX);
        fapi2::IO_XBUS_TX_ZCAL_OUT_OF_RANGE().set_TARGET(i_target)
        .set_ZCAL_P(l_pval_reg.get<EDIP_TX_ZCAL_P>())
        .set_ZCAL_N(l_nval_reg.get<EDIP_TX_ZCAL_N>())
        .execute();
    }

    if( l_pval_reg.get<EDIP_TX_ZCAL_P>() < ZCAL_MIN )
    {
        // Convert from 4R to 2R
        o_pval = (float)ZCAL_MIN / 2;
        FAPI_ERR("Tx Zcal Pval(0x%X) < Min Allowed(0x%X)",
                 l_pval_reg.get<EDIP_TX_ZCAL_P>(), ZCAL_MIN);
        fapi2::IO_XBUS_TX_ZCAL_OUT_OF_RANGE().set_TARGET(i_target)
        .set_ZCAL_P(l_pval_reg.get<EDIP_TX_ZCAL_P>())
        .set_ZCAL_N(l_nval_reg.get<EDIP_TX_ZCAL_N>())
        .execute();
    }

    if( l_nval_reg.get<EDIP_TX_ZCAL_N>() < ZCAL_MIN )
    {
        // Convert from 4R to 2R
        o_nval = (float)ZCAL_MIN / 2;
        FAPI_ERR("Tx Zcal Nval(0x%X) < Min Allowed(0x%X)",
                 l_nval_reg.get<EDIP_TX_ZCAL_N>(), ZCAL_MIN);
        fapi2::IO_XBUS_TX_ZCAL_OUT_OF_RANGE().set_TARGET(i_target)
        .set_ZCAL_P(l_pval_reg.get<EDIP_TX_ZCAL_P>())
        .set_ZCAL_N(l_nval_reg.get<EDIP_TX_ZCAL_N>())
        .execute();
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

/**
 * @brief Calculate the total number of P segments and N segments (pre-cursor,
 * post-cursor, magin, and main slice) based on the Tx Impedance Calibration
 * results (tx_l_zcal_p and tx_l_zcal_n).
 * @param[in] i_target   Reference to the Current Target
 * @param[in] i_group    Clock Group
 * @retval fapi2::current_err
 */
fapi2::ReturnCode txZCalSetParms(const fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target,
                                 const uint8_t i_group,
                                 const float i_pval,
                                 const float i_nval)
{
    FAPI_IMP("Entering...");

    // BANK              EDI+    OPT
    // ----              1R  2R  1R  2R
    // PRE-BANK          4   1   4   1
    // POST-BANK         0   0   6   1
    // MARGIN PULL-UP    8   0   8   0
    // MARGIN PULL-DOWN  8   0   8   0
    // MAIN BANK         12  1   6   1

    // 2R equivalent values.
    const uint32_t PRE_1R         = 4;
    const uint32_t PRE_2R         = 1;
    const uint32_t PRE_BANK       = ( PRE_1R * 2 ) + PRE_2R;
    const uint32_t MARGIN_1R      = 8;
    const uint32_t MARGIN_2R      = 0;
    const uint32_t MARGIN_PD_BANK = (MARGIN_1R * 2) + MARGIN_2R;
    const uint32_t MARGIN_PU_BANK = (MARGIN_1R * 2) + MARGIN_2R;
    const uint32_t MAIN_1R        = 12;
    const uint32_t MAIN_2R        = 1;
    const uint32_t MAIN_BANK      = ( MAIN_1R * 2 ) + MAIN_2R;

    // M = MARGIN RATIO, Range 0.5 - 1
    // M = 1   :: 0% Margining
    // M = 0.5 :: 50% Margining
    const float M                 = 1;

    // K0 = PRE-CURSOR COEFFICIENT, Range 0 - 0.115
    // K0 = 0     :: 0% Pre-Cursor
    // K0 = 0.115 :: 11.5% Pre-Cursor
    const float K0                = 0.115;

    Register<EDIP_TX_CTLSM_CNTL1_EO_PG> l_pseg_pre_reg;
    Register<EDIP_TX_CTLSM_CNTL2_EO_PG> l_nseg_pre_reg;
    Register<EDIP_TX_CTLSM_CNTL3_EO_PG> l_pseg_margin_reg;
    Register<EDIP_TX_CTLSM_CNTL4_EO_PG> l_nseg_margin_reg;
    Register<EDIP_TX_CTLSM_CNTL5_EO_PG> l_margin_reg;
    Register<EDIP_TX_CTLSM_CNTL6_EO_PG> l_pseg_main_reg;
    Register<EDIP_TX_CTLSM_CNTL7_EO_PG> l_nseg_main_reg;

    // :: Set the Selected Bank Segments
    // Apply Calcualted Segments to margin/pre/main banks accordingly
    // 1. Apply Segments to Margining first
    // 2. Apply Segments to Pre-Cursor second
    // 3. Apply Segments to Main last
    float l_margin_pu_sel = i_pval * ( 1 - M );
    float l_margin_pd_sel = i_nval * ( 1 - M );
    float l_pre_p_sel     = ( i_pval - l_margin_pu_sel ) * K0;
    float l_pre_n_sel     = ( i_nval - l_margin_pd_sel ) * K0;
    float l_main_p_en     = i_pval - l_margin_pu_sel - l_pre_p_sel;
    float l_main_n_en     = i_nval - l_margin_pd_sel - l_pre_n_sel;


    // :: Set the Enabled P Bank Segments
    float l_pre_p_en       = l_pre_p_sel;
    float l_margin_p_pu_en = l_margin_pu_sel;
    float l_margin_p_pd_en = l_margin_pd_sel;

    // Check if the main bank is over the max segments.
    if( l_main_p_en > MAIN_BANK)
    {
        l_pre_p_en += (l_main_p_en - MAIN_BANK);
        l_main_p_en = MAIN_BANK;

        if( l_pre_p_en > PRE_BANK )
        {
            l_margin_p_pu_en += (l_pre_p_en - PRE_BANK);
            l_pre_p_en = PRE_BANK;

            if( l_margin_p_pu_en > MARGIN_PU_BANK )
            {
                l_margin_p_pd_en += (l_margin_p_pu_en - MARGIN_PU_BANK);
                l_margin_p_pu_en = MARGIN_PU_BANK;
            }
        }
    }

    // :: Set the Enabled N Bank Segments
    float l_pre_n_en       = l_pre_n_sel;
    float l_margin_n_pu_en = l_margin_pu_sel;
    float l_margin_n_pd_en = l_margin_pd_sel;

    // Check if the main bank is over the max segments.
    if( l_main_n_en > MAIN_BANK)
    {
        l_pre_n_en += (l_main_n_en - MAIN_BANK);
        l_main_n_en = MAIN_BANK;

        if( l_pre_n_en > PRE_BANK )
        {
            l_margin_n_pd_en += (l_pre_n_en - PRE_BANK);
            l_pre_n_en = PRE_BANK;

            if( l_margin_n_pd_en > MARGIN_PD_BANK )
            {
                l_margin_n_pu_en += (l_margin_n_pd_en - MARGIN_PU_BANK);
                l_margin_n_pd_en = MARGIN_PU_BANK;
            }
        }
    }

    // We can write these registers without reading, since we are writing
    //   the entire register.
    l_pseg_pre_reg.set<EDIP_TX_PSEG_PRE_SEL>(round(l_pre_p_sel, PRE_2R));
    l_pseg_pre_reg.set<EDIP_TX_PSEG_PRE_EN>(round(l_pre_p_en, PRE_2R));
    FAPI_TRY(l_pseg_pre_reg.write(i_target, i_group), "Pseg Pre Write Fail");

    l_nseg_pre_reg.set<EDIP_TX_NSEG_PRE_SEL>(round(l_pre_n_sel, PRE_2R));
    l_nseg_pre_reg.set<EDIP_TX_NSEG_PRE_EN>(round(l_pre_n_en, PRE_2R));
    FAPI_TRY(l_nseg_pre_reg.write(i_target, i_group), "Nseg Pre Write Fail");

    l_pseg_margin_reg.set<EDIP_TX_PSEG_MARGINPD_EN>(round(l_margin_p_pd_en, MARGIN_2R));
    l_pseg_margin_reg.set<EDIP_TX_PSEG_MARGINPU_EN>(round(l_margin_p_pu_en, MARGIN_2R));
    FAPI_TRY(l_pseg_margin_reg.write(i_target, i_group), "Pseg Margin Write Fail");

    l_nseg_margin_reg.set<EDIP_TX_NSEG_MARGINPD_EN>(round(l_margin_n_pd_en, MARGIN_2R));
    l_nseg_margin_reg.set<EDIP_TX_NSEG_MARGINPU_EN>(round(l_margin_n_pu_en, MARGIN_2R));
    FAPI_TRY(l_nseg_margin_reg.write(i_target, i_group), "Nseg Margin Write Fail");

    l_margin_reg.set<EDIP_TX_MARGINPD_SEL>(round(l_margin_pd_sel, MARGIN_2R));
    l_margin_reg.set<EDIP_TX_MARGINPU_SEL>(round(l_margin_pu_sel, MARGIN_2R));
    FAPI_TRY(l_margin_reg.write(i_target, i_group), "Margin Write Fail");

    l_pseg_main_reg.set<EDIP_TX_PSEG_MAIN_EN>(round(l_main_p_en, MAIN_2R));
    FAPI_TRY(l_pseg_main_reg.write(i_target, i_group), "Pseg Main Write Fail");

    l_nseg_main_reg.set<EDIP_TX_NSEG_MAIN_EN>(round(l_main_n_en, MAIN_2R));
    FAPI_TRY(l_nseg_main_reg.write(i_target, i_group), "Nseg Main Write Fail");

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}


/**
 * @brief Runs Rx Dccal on an EDI+ Xbus Target
 * @param[in] i_target FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode rxDccal (const fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target )
{
    FAPI_IMP("Entering...");
    Register<EDIP_RX_CTL_CNTL1_E_PG> l_dccal_reg;
    Register<EDIP_RX_CTL_STAT1_E_PG> l_cal_done_reg;
    const uint8_t XBUS_GROUPS = 2;
    uint8_t l_dccal_flags = 0x0;

    FAPI_INF("Checking I/O Xbus Dccal Flags.");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_XBUS_DCCAL_FLAGS, i_target, l_dccal_flags));

    if(l_dccal_flags & fapi2::ENUM_ATTR_IO_XBUS_DCCAL_FLAGS_RX)
    {
        FAPI_INF("I/O EDI+ Xbus Rx DC Calibration has been previously ran.");
    }
    else
    {
        FAPI_INF("I/O EDI+ Xbus Rx DC Calibration is Required.");
    }

    for(uint8_t group = 0; group < XBUS_GROUPS; ++group)
    {
        FAPI_INF("I/O EDI+ Xbus Rx Dccal Group(%d).", group);

        // Must set lane invalid bit to 0 to run rx dccal
        FAPI_TRY(setLaneInvalid(i_target, group, 0), "Error Setting Lane Invalid to 0");

        // Clearing the Rx Dccal Done bit.
        FAPI_TRY( l_cal_done_reg.read(i_target, group), "Read Dccal Done Failed");
        l_cal_done_reg.set<EDIP_RX_DC_CALIBRATE_DONE>(0);
        FAPI_TRY( l_cal_done_reg.write(i_target, group), "Write Dccal Done Failed");

        // Start DC Calibrate
        FAPI_TRY(l_dccal_reg.read(i_target, group), "Reading Start Dccal Failed");
        l_dccal_reg.set<EDIP_RX_START_DC_CALIBRATE>(1);
        FAPI_TRY(l_dccal_reg.write(i_target, group), "Starting Dccal Failed");

        // Check each lane in the group.
        FAPI_TRY(rxDccalPoll(i_target, group), "Poll Rx DcCal Failed");

        // Stop DC Calibrate
        l_dccal_reg.set<EDIP_RX_START_DC_CALIBRATE>(0);
        FAPI_TRY(l_dccal_reg.write(i_target, group), "Stopping Dccal Failed");

        // Restore the invalid bits, Wiretest will modify these as training is run.
        FAPI_TRY(setLaneInvalid(i_target, group, 1), "Error Setting Lane Invalid to 1");

        FAPI_DBG("I/O EDI+ Xbus Rx Dccal Complete on Group(%d)", group);
    }

    l_dccal_flags |= fapi2::ENUM_ATTR_IO_XBUS_DCCAL_FLAGS_RX;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_XBUS_DCCAL_FLAGS, i_target,
                           l_dccal_flags));

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}


/**
 * @brief Polls Rx Dccal status on an EDI+ Xbus Target
 * @param[in] i_target  FAPI2 Target
 * @param[in] i_group   Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode
rxDccalPoll(const fapi2::Target < fapi2::TARGET_TYPE_XBUS > i_target, const uint8_t i_group)
{
    FAPI_IMP("Entering...");
    const uint8_t TIMEOUT  = 200;
    const uint64_t POLL_NS = 500;
    const uint64_t SIM_CYCLES = 25000000;
    Register<EDIP_RX_CTL_STAT1_E_PG> l_cal_done_reg;
    uint8_t l_poll_count = 0;

    FAPI_TRY( l_cal_done_reg.read(i_target, i_group), "Read Dccal Done Failed");

    while( (l_poll_count < TIMEOUT) && !l_cal_done_reg.get<EDIP_RX_DC_CALIBRATE_DONE>() )
    {
        FAPI_DBG("I/O EDI+ Xbus Rx Dccal Polling Count(%d/%d).", l_poll_count, TIMEOUT);

        FAPI_TRY( l_cal_done_reg.read(i_target, i_group), "Read Dccal Done Failed");

        FAPI_TRY( fapi2::delay(POLL_NS, SIM_CYCLES), "Fapi Delay Failed.");
        ++l_poll_count;
    }

    FAPI_ASSERT( (l_cal_done_reg.get<EDIP_RX_DC_CALIBRATE_DONE>() == 1),
                 fapi2::IO_XBUS_RX_DCCAL_TIMEOUT().set_TARGET(i_target).set_GROUP(i_group),
                 "Rx Dccal Timeout: Loops(%d) delay(%d ns, %d cycles)",
                 l_poll_count, POLL_NS, SIM_CYCLES);

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

/**
 * @brief This function sets the lane invalid field to the value of the data passed in
 * @param[in] i_target  FAPI2 Target
 * @param[in] i_group   Clock Group
 * @param[in] i_data    Value to set rx lane invalid field to.
 * @return fapi2::ReturnCode
 */
fapi2::ReturnCode
setLaneInvalid(const fapi2::Target<fapi2::TARGET_TYPE_XBUS> i_target,
               const uint8_t i_group,
               const uint8_t i_data)
{
    FAPI_IMP("Entering...");
    fapi2::ReturnCode rc;
    Register<EDIP_RX_BIT_CNTLX1_EO_PL> l_lane_invalid_reg;
    const uint8_t XBUS_LANES = 17;

    for(uint8_t lane = 0; lane < XBUS_LANES; ++lane)
    {
        FAPI_TRY(l_lane_invalid_reg.read(i_target, i_group, lane), "Reading Invalid Lane Failed")
        l_lane_invalid_reg.set<EDIP_RX_LANE_INVALID>(i_data);
        FAPI_TRY(l_lane_invalid_reg.write(i_target, i_group, lane), "Reading Invalid Lane Failed")
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return rc;
}


/**
 * @brief The function assumes that the Tx ZCal FFE 2r width will be between 0-1
 * @param[in] i_data      data in 2r format
 * @param[in] i_width2r   If the segment contains a 2r field, Range of 0-1
 * @return data in 1r format
 */
uint32_t round(const float i_data, const uint32_t i_width2r)
{
    return (i_width2r == 1) ? uint32_t( i_data ) : (uint32_t(i_data + 0.5) >> 1);
}
