/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mc/port.C $                */
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
/// @file port.C
/// @brief Subroutines to manipulate ports (phy + mc for certain operations)
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/mc/port.H>
#include <lib/dimm/rank.H>
#include <lib/shared/mss_const.H>
#include <lib/utils/scom.H>

namespace mss
{

///
/// @brief Enable the MC Periodic calibration functionality - MCA specialization
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode enable_periodic_cal( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    typedef portTraits<fapi2::TARGET_TYPE_MCA> TT;

    uint32_t l_memcal_interval = 0;
    uint32_t l_zqcal_interval = 0;

    fapi2::buffer<uint64_t> l_periodic_cal_config;
    fapi2::buffer<uint64_t> l_phy_zqcal_config;

    std::vector<uint64_t> l_pairs;

    FAPI_INF("Enable periodic cal");

    uint8_t is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim) );

    // Even if we're in sim, do these so that we do the attribute work (even though the values aren't used.)
    FAPI_TRY( mss::eff_memcal_interval(i_target, l_memcal_interval) );
    FAPI_TRY( mss::eff_zqcal_interval(i_target, l_zqcal_interval) );

    // TODO RTC:155854 We haven't done the work for calculating init cal periods
    // in effective config yet, and the MC setup below is hard wired for sim

    FAPI_DBG("memcal interval %dck, zqcal interval %dck", l_memcal_interval, l_zqcal_interval);

    // I think we can do these in any event BRS
    {
        // From Steve Powell, 4/16
        // 0xFFFFFFFFFFFFFFF0
        fapi2::buffer<uint64_t> l_data;
        l_data.insertFromRight<TT::CAL3Q_INTERNAL_ZQ_TB, TT::CAL3Q_INTERNAL_ZQ_TB_LEN>(0b11);
        l_data.insertFromRight<TT::CAL3Q_INTERNAL_ZQ_LENGTH, TT::CAL3Q_INTERNAL_ZQ_LENGTH_LEN>(0b11111111);
        l_data.insertFromRight<TT::CAL3Q_EXTERNAL_ZQ_TB, TT::CAL3Q_EXTERNAL_ZQ_TB_LEN>(0b11);
        l_data.insertFromRight<TT::CAL3Q_EXTERNAL_ZQ_LENGTH, TT::CAL3Q_EXTERNAL_ZQ_LENGTH_LEN>(0b11111111);
        l_data.insertFromRight<TT::CAL3Q_RDCLK_SYSCLK_TB, TT::CAL3Q_RDCLK_SYSCLK_TB_LEN>(0b11);
        l_data.insertFromRight<TT::CAL3Q_RDCLK_SYSCLK_LENGTH, TT::CAL3Q_RDCLK_SYSCLK_LENGTH_LEN>(0b11111111);
        l_data.insertFromRight<TT::CAL3Q_DQS_ALIGNMENT_TB, TT::CAL3Q_DQS_ALIGNMENT_TB_LEN>(0b11);
        l_data.insertFromRight<TT::CAL3Q_DQS_ALIGNMENT_LENGTH, TT::CAL3Q_DQS_ALIGNMENT_LENGTH_LEN>(0b11111111);
        l_data.insertFromRight<TT::CAL3Q_MPR_READEYE_TB, TT::CAL3Q_MPR_READEYE_TB_LEN>(0b11);
        l_data.insertFromRight<TT::CAL3Q_MPR_READEYE_LENGTH, TT::CAL3Q_MPR_READEYE_LENGTH_LEN>(0b11111111);
        l_data.insertFromRight<TT::CAL3Q_ALL_PERIODIC_TB, TT::CAL3Q_ALL_PERIODIC_TB_LEN>(0b11);
        l_data.insertFromRight<TT::CAL3Q_ALL_PERIODIC_LENGTH, TT::CAL3Q_ALL_PERIODIC_LENGTH_LEN>(0b11111111);
        l_data.clearBit<TT::CAL3Q_FREEZE_ON_PARITY_ERROR_DIS>();

        FAPI_TRY( mss::putScom(i_target, TT::CAL3Q_REG, l_data) );
    }

    // ZQCAL
    if (l_zqcal_interval != 0)
    {
        std::vector<uint64_t> l_ranks;

        //
        // Configure the controller
        //

        {
            // Sim settings from Steve Powell, 4/16
            //             11 1111 1111 2222 2222 2233 3333 3333 4444 4444 4455 5555 5555 6666
            // 0123 4567 8901 2345 6789 0123 4567 8901 2345 6789 0123 4567 8901 2345 6789 0123
            // A    8    0    A    4    0    0    0    0    0    8    0    2    0    0    0
            // 1010 1000 0000 1010 0100 0000 0000 0000 0000 0000 1000 0000 0010 0000 0000 0000
            fapi2::buffer<uint64_t> l_data;

            // Don't enable zcal in sim as we don't enable it in the PHY
            l_data.writeBit<TT::CAL0Q_CAL_INTERVAL_TMR0_ENABLE>(is_sim ? 0 : 1);

            l_data.insertFromRight<TT::CAL0Q_TIME_BASE_TMR0, TT::CAL0Q_TIME_BASE_TMR0_LEN>(0b01);
            l_data.insertFromRight<TT::CAL0Q_INTERVAL_COUNTER_TMR0, TT::CAL0Q_INTERVAL_COUNTER_TMR0_LEN>(0b010000000);
            l_data.setBit<TT::CAL0Q_CAL_TMR0_CAL1_ENABLE>();
            l_data.insertFromRight<TT::CAL0Q_CAL_TMR0_CAL1_TYPE, TT::CAL0Q_CAL_TMR0_CAL1_TYPE_LEN>(0b0100);
            l_data.setBit<TT::CAL0Q_CAL_TMR0_CAL1_DDR_DONE>();
            l_data.insertFromRight<TT::CAL0Q_CAL_TMR0_DDR_RESET_TMR, TT::CAL0Q_CAL_TMR0_DDR_RESET_TMR_LEN>(0b01000000);
            l_data.setBit<TT::CAL0Q_CAL_TMR0_SINGLE_RANK>();

            FAPI_TRY( mss::putScom(i_target, TT::CAL0Q_REG, l_data) );
            FAPI_INF("Periodic ZQ cal: 0x%016lx", l_data);
        }

        //
        // Configure the PHY
        //

        // Setup PER_ZCAL_CONFIG based on the number of ranks on the DIMM in either slot.
        FAPI_TRY( mss::ranks(i_target, l_ranks) );

        for (auto r : l_ranks)
        {
            l_phy_zqcal_config.setBit(TT::PER_ZCAL_ENA_RANK + r);
        }

        // No ZQCAL in sim
        l_periodic_cal_config.writeBit<TT::PER_ENA_ZCAL>(is_sim ? 0 : 1);

        // Write the ZQCAL periodic config
        FAPI_DBG("zcal periodic config: 0x%016lx", l_phy_zqcal_config);
        FAPI_TRY( mss::putScom(i_target, TT::PHY_ZQCAL_REG, l_phy_zqcal_config) );

        // Write the ZQCAL timer reload register
        // # DPHY01_DDRPHY_PC_ZCAL_TIMER_RELOAD_VALUE_P0   0x00A   0x8000c0090301143f
        // # PHYW.PHYX.SYNTHX.D3SIDEA.PCX.REG09_L2
        // scom 0x8000c0090301143f {
        // bits    ,       scom_data ,       expr ;       # must be >= 2...
        // #       0:47    ,       0x000000000000,       any ;       # reserved
        // 48:63   ,       ((ATTR_EFF_ZQCAL_INTERVAL/196605)+1), (def_FAST_SIM_PC==0)    ;       # FAST_SIM_PER_CNTR=0
        // 48:63   ,       ((ATTR_EFF_ZQCAL_INTERVAL/765)+1)   , (def_FAST_SIM_PC==1)    ;       # FAST_SIM_PER_CNTR=1
        // # 48:63   ,       0x002E ,       any                                          ;       # 46 = 11ms @ 1600MHz
        {
            // TODO: 154170
            // There is something fishy going on here. The l_zcal_timer_reload math yields 17 bits, however the
            // insert (seen in the initfile snippet above) truncates it to 16 bits. We do the same here, and
            // have the story above opened to investigate
            fapi2::buffer<uint64_t> l_zcal_timer_reload;
            l_zcal_timer_reload.insertFromRight<TT::ZCAL_TIMER_RELOAD_VALUE, TT::ZCAL_TIMER_RELOAD_VALUE_LEN>(
                is_sim ? (l_zqcal_interval / TT::MAGIC_NUMBER_SIM) + 1 : (l_zqcal_interval / TT::MAGIC_NUMBER_NOT_SIM) + 1);
            FAPI_DBG("zcal timer reload: 0x%016lx", l_zcal_timer_reload);
            FAPI_TRY( mss::putScom(i_target, TT::PHY_ZCAL_TIMER_RELOAD_REG, l_zcal_timer_reload) );
        }

    }

    // MEMCAL
    if (l_memcal_interval != 0)
    {
        // Setup the periodic enable rank pair field in the phy cal config and the mc. This used to be shared
        // between the MC and the PHY in Centaur but no longer is - so we write the same data in two registers.
        // Note: Why is this vastly different from the rank setup in the zqcal config and why do we
        // need to do it twice for the PHY? BRS
        fapi2::buffer<uint64_t> l_rank_config;

        FAPI_TRY( mss::get_rank_pairs(i_target, l_pairs) );

        for (auto pair : l_pairs)
        {
            l_rank_config.setBit(pair);
        }

        FAPI_DBG("periodic ranks: 0x%016lx", l_rank_config);

        //
        // Configure the controller
        //

        {
            // From Steve Powell, 4/16
            //             11 1111 1111 2222 2222 2233 3333 3333 4444 4444 4455 5555 5555 6666
            // 0123 4567 8901 2345 6789 0123 4567 8901 2345 6789 0123 4567 8901 2345 6789 0123
            // A    4    0    9    C    0    0    0    0    0    0    0    0    0    0    0
            // 1010 0100 0000 1001 1100 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
            fapi2::buffer<uint64_t> l_data;

            l_data.setBit<TT::CAL1Q_CAL_INTERVAL_TMR1_ENABLE>();
            l_data.insertFromRight<TT::CAL1Q_TIME_BASE_TMR1, TT::CAL1Q_TIME_BASE_TMR1_LEN>(0b01);
            l_data.insertFromRight<TT::CAL1Q_INTERVAL_COUNTER_TMR1, TT::CAL1Q_INTERVAL_COUNTER_TMR1_LEN>(0b001000000);
            l_data.setBit<TT::CAL1Q_CAL_TMR1_CAL1_ENABLE>();
            l_data.insertFromRight<TT::CAL1Q_CAL_TMR1_CAL1_TYPE, TT::CAL1Q_CAL_TMR1_CAL1_TYPE_LEN>(0b0011);
            l_data.setBit<TT::CAL1Q_CAL_TMR1_CAL1_DDR_DONE>();
            l_data.insert<TT::CAL1Q_CAL_RANK_ENABLE, TT::CAL1Q_CAL_RANK_ENABLE_LEN>(l_rank_config);

            FAPI_TRY( mss::putScom(i_target, TT::CAL1Q_REG, l_data) );
            FAPI_INF("Periodic memcal enabled 0x%016lx", l_data);
        }

        {
            // From Steve Powell, 4/16. Notice bits are reserved in the scomdef, so re-reviewed
            // with Steve: "Sorry... ignore those.  They seem to have been getting set as part of a gfw scratch
            // space as they are reserved." SoCAL2Q is 0's
            //             11 1111 1111 2222 2222 2233 3333 3333 4444 4444 4455 5555 5555 6666
            // 0123 4567 8901 2345 6789 0123 4567 8901 2345 6789 0123 4567 8901 2345 6789 0123
            // 0    0    0    0    0    0    0    0    0    0    0    1    8    0    0    0
            // 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 1000 0000 0000 0000
            fapi2::buffer<uint64_t> l_data;
            FAPI_TRY( mss::putScom(i_target, TT::CAL2Q_REG, l_data) );
        }

        //
        // Configure the PHY
        //

        // Centaur init file
        // # DPHY01_DDRPHY_PC_CAL_TIMER_RELOAD_VALUE_P0    0x008   0x8000c0080301143f
        // # PHYE.PHYX.SYNTHX.D3SIDEA.PCX.REG08_L2
        // scom 0x800(0,1)c0080301143f {   # _P[0:1]
        // bits    ,       scom_data,       expr;       # must be >= 2...
        // #       0:47    ,       0x000000000000,       any                                             ;# reserved
        // #       48:63   ,       0x0000, (def_is_sim)                    ;# match dials
        //         48:63   ,       ((ATTR_EFF_MEMCAL_INTERVAL/196605)+1), (def_FAST_SIM_PC==0)    ;# FAST_SIM_PER_CNTR=0
        //         48:63   ,       ((ATTR_EFF_MEMCAL_INTERVAL/765)+1),    (def_FAST_SIM_PC==1)    ;# FAST_SIM_PER_CNTR=1
        // #       48:63   ,       0x01D1,       any                                             ;       # 464 = 114ms @ 1600MHz

        // Add the ranks to the phy config
        l_periodic_cal_config.insert<TT::PER_ZCAL_ENA_RANK, TT::PER_ZCAL_ENA_RANK_LEN>(l_rank_config);

        // If we're in sim, enable the fast-sim mode
        l_periodic_cal_config.writeBit<TT::PER_FAST_SIM_CNTR>(is_sim);

        l_periodic_cal_config.setBit<TT::PER_ENA_SYSCLK_ALIGN>();

        // Per John Bialas 5/16:  "... periodic read centering does not work ... We are re-evaluating fixing it for DD2"
#ifdef PERIODIC_READ_CENTERING_FIX
        l_periodic_cal_config.setBit<TT::PER_ENA_READ_CTR>();
#endif
        l_periodic_cal_config.setBit<TT::PER_ENA_RDCLK_ALIGN>();
        l_periodic_cal_config.setBit<TT::PER_ENA_DQS_ALIGN>();

        // Per John Bialas 5/16: "DD2_FIX_DIS should not be asserted, ie. we do want to use the centaur DD2 fixes"

        // Write the periodic cal config
        FAPI_TRY( mss::putScom(i_target, TT::PHY_PERIODIC_CAL_CONFIG_REG, l_periodic_cal_config) );

        // Write the periodic cal reload value
        FAPI_TRY( mss::putScom(i_target, TT::PHY_PERIODIC_CAL_RELOAD_REG, TT::PHY_PERIODIC_CAL_RELOAD_VALUE) );

        // Write the cal timer reload
        // 48:63   , ((ATTR_EFF_MEMCAL_INTERVAL/196605)+1)   ,       (def_FAST_SIM_PC==0)    ;       # FAST_SIM_PER_CNTR=0
        // 48:63   , ((ATTR_EFF_MEMCAL_INTERVAL/765)+1)      ,       (def_FAST_SIM_PC==1)    ;       # FAST_SIM_PER_CNTR=1
        {
            // TODO: 154170
            // There is something fishy going on here. The l_zcal_timer_reload math yields 17 bits, however the
            // insert (seen in the initfile snippet above) truncates it to 16 bits. We do the same here, and
            // have the story above opened to investigate
            fapi2::buffer<uint64_t> l_cal_timer_reload;
            l_cal_timer_reload.insertFromRight<TT::PC_CAL_TIMER_RELOAD_VALUE, TT::PC_CAL_TIMER_RELOAD_VALUE_LEN>(
                is_sim ? (l_memcal_interval / TT::MAGIC_NUMBER_SIM) + 1 : (l_memcal_interval / TT::MAGIC_NUMBER_NOT_SIM) + 1);
            FAPI_DBG("phy cal timer reload: 0x%016lx", l_cal_timer_reload);
            FAPI_TRY( mss::putScom(i_target, TT::PHY_CAL_TIMER_RELOAD_REG, l_cal_timer_reload ) );
        }

    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
