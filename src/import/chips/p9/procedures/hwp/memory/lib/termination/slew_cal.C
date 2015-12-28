/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/termination/slew_cal.C $   */
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
/// @file slew_cal.C
/// @brief  * This function runs the slew calibration engine to configure MSS_SLEW_DATA/ADR
/// attributes and calls config_slew_rate to set the slew rate in the registers.
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include "../mss.H"
#include "slew_cal.H"

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_SYSTEM;

using fapi2::TARGET_STATE_FUNCTIONAL;

using fapi2::FAPI2_RC_SUCCESS;

// slew calibration control register

static const uint64_t slew_cal_cntl[] =
{
    MCA_0_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0,
    MCA_1_DDRPHY_ADR_SLEW_CAL_CNTL_P1_ADR32S0,
    MCA_2_DDRPHY_ADR_SLEW_CAL_CNTL_P2_ADR32S0,
    MCA_3_DDRPHY_ADR_SLEW_CAL_CNTL_P3_ADR32S0,
};
// slew calibration status registers
static const uint64_t ENABLE_BIT = 48;
static const uint64_t slew_cal_stat[] =
{
    MCA_0_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0,
    MCA_1_DDRPHY_ADR_SYSCLK_CNTL_PR_P1_ADR32S0,
    MCA_2_DDRPHY_ADR_SYSCLK_CNTL_PR_P2_ADR32S0,
    MCA_3_DDRPHY_ADR_SYSCLK_CNTL_PR_P3_ADR32S0,
};

// big bang lock bit register
static const uint64_t bb_lock_stat[] =
{
    MCA_0_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0,
    MCA_1_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P1_ADR32S0,
    MCA_2_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P2_ADR32S0,
    MCA_3_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P3_ADR32S0,
};

namespace mss
{

///
/// @brief perform the slew calibration, store the result.
/// @tparam T, the type of the slew table
/// @param[in] MCA (port) target
/// @param[in] a vector of the steps which came before me
/// @param[in] the slew table to be operated on
/// @param[out] the array holding the results
/// @return FAPI2_RC_SUCCESS, iff ok
///
template<typename T>
fapi2::ReturnCode perform_slew_cal(
    const fapi2::Target<TARGET_TYPE_MCA>& i_target,
    std::vector<tags_t>& i_where_am_i, T& l_table,
    uint8_t (&o_cal_slew)[2][PORTS_PER_MCS][MAX_NUM_IMP][MAX_NUM_CAL_SLEW_RATES])
{
    i_where_am_i.push_back(l_table.first);

    for (auto e : l_table.second)
    {
        FAPI_TRY( perform_slew_cal(i_target, i_where_am_i, e, o_cal_slew) );
    }

    i_where_am_i.pop_back();

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief perform the slew calibration, store the result.
/// @param[in] MCA (port) target
/// @param[in] a vector of the steps which came before me
/// @param[in] a slew_table_t
/// @param[out] the array holding the results
/// @bote Prunes recursion based on frequency.
/// @return FAPI2_RC_SUCCESS, iff ok
///
template<>
fapi2::ReturnCode perform_slew_cal(
    const fapi2::Target<TARGET_TYPE_MCA>& i_target,
    std::vector<tags_t>& i_where_am_i,
    std::pair<tags_t, slew_per_imp_t>& l_table,
    uint8_t (&o_cal_slew)[2][PORTS_PER_MCS][MAX_NUM_IMP][MAX_NUM_CAL_SLEW_RATES])
{
    uint64_t ddr_freq = 0;
    const char* l_type = i_where_am_i[0] == TAG_ADR ? "adr" : "data";

    // Check our speed. If this isn't our speed, we can get out of here.
    FAPI_TRY( mss::freq(i_target.getParent<TARGET_TYPE_MCBIST>(), ddr_freq),
              "Unable to get ddr freq for %s", mss::c_str(i_target) );

    if (ddr_freq != l_table.first)
    {
        FAPI_DBG("Skipping slew %s for %s: invalid speed %d(%d)",
                 l_type, mss::c_str(i_target), l_table.first, ddr_freq);
        return FAPI2_RC_SUCCESS;
    }

    i_where_am_i.push_back(l_table.first);

    for (auto e : l_table.second)
    {
        FAPI_TRY( perform_slew_cal(i_target, i_where_am_i, e, o_cal_slew) );
    }

    i_where_am_i.pop_back();

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief perform the slew calibration, store the result.
/// @param[in] MCA (port) target
/// @param[in] a vector of the steps which came before me
/// @param[in] the slew rate to be calculated
/// @param[out] the array holding the results
/// @return FAPI2_RC_SUCCESS, iff ok
///
template<>
fapi2::ReturnCode perform_slew_cal<slew_rate_t>(
    const fapi2::Target<TARGET_TYPE_MCA>& i_target,
    std::vector<tags_t>& i_where_am_i,
    slew_rate_t& l_slew_rate,
    uint8_t (&o_cal_slew)[2][PORTS_PER_MCS][MAX_NUM_IMP][MAX_NUM_CAL_SLEW_RATES])
{
    i_where_am_i.push_back(l_slew_rate.first);

    fapi2::buffer<uint64_t> l_data;

    // Some short-hand for this calibration
    const char* l_type = i_where_am_i[0] == TAG_ADR ? "adr" : "data";
    const uint64_t& l_speed = i_where_am_i[1];
    const uint64_t& l_ohm = i_where_am_i[2];
    const uint64_t& l_vns = i_where_am_i[3];

    uint64_t cal_status = 0;
    fapi2::buffer<uint64_t> status_register;
    uint64_t calculated_slew = 0;

    FAPI_INF("Processing slew %s, %dmhz %dohm %dV/ns: %d", l_type, l_speed, l_ohm, l_vns, l_slew_rate.second);

#ifdef NOT_TESTING_WITH_SUET
    // Get out of here if we're in the simulator. Calibration fails in sim since bb_lock not possible in cycle
    // simulator, putting initial to be cal'd value in output table
    uint8_t is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    if (is_sim)
    {
        FAPI_INF("In SIM setting input slew value in array");
        calculated_slew = l_slew_rate.second;
        goto perform_slew_cal_exit;
    }

#endif

    // This doesn't look right. There are 5 bits, but some of our values (134) are 8 bits. So, the
    // left-most bits are truncated. Note this is the same in P8, it seems - this needs to be looked at BRS
    l_data.insertFromRight<MCA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_ADR0_TARGET_PR_OFFSET,
                           MCA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_ADR0_TARGET_PR_OFFSET_LEN>(l_slew_rate.second);
    l_data.setBit<MCA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_ADR0_START>();

    FAPI_TRY( fapi2::putScom(i_target, MCA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0, l_data) );

    mss::poll( i_target, MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0, mss::poll_parameters(DELAY_100NS),
               [&](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        // Save off our claibration status
        status_register = stat_reg;
        stat_reg.extractToRight<MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_ADR0_SLEW_DONE_STATUS,
        MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_ADR0_SLEW_DONE_STATUS_LEN>(cal_status);
        FAPI_DBG("slew calibration status 0x%llx, remaining: %d", cal_status, poll_remaining);
        return cal_status != SLEW_CAL_NOT_DONE;
    });

    // This will kick us out if there's no further processing we can do.
    FAPI_TRY( slew_cal_status(i_target, i_where_am_i, l_slew_rate.second, cal_status, status_register) );

    // Get our calculated slew rate and process.
    FAPI_TRY( fapi2::getScom(i_target, MCA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0, l_data) );
    l_data.extractToRight<MCA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_ADR0_TARGET_PR_OFFSET,
                          MCA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_ADR0_TARGET_PR_OFFSET_LEN>(calculated_slew);

#ifdef NOT_TESTING_WITH_SUET
perform_slew_cal_exit:
#endif
    FAPI_DBG("MSS_SLEW_RATE %s port %d %dohm slew 0x%lx(0x%lx)",
             l_type, mss::pos(i_target), l_ohm, calculated_slew, uint64_t(status_register));

    o_cal_slew[i_where_am_i[0]]                        // adr/data
    [mss::index(i_target)]                         // port
    [mss::index(i_where_am_i[0], i_where_am_i[2])] // imp
    [mss::index(i_where_am_i[0], i_where_am_i[3])] = calculated_slew;

    i_where_am_i.pop_back();

    return FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Run the slew calibration engine
/// @param[in] i_target, the MCBIST
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode slew_cal(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target)
{
    // freq index into lookup table. Fixed at 3 right now as we don't support
    // dimm slower than 1866 - without more work below.
    static const uint8_t freq_idx = 3;

    // current ddr freq
    uint64_t ddr_freq = 0;

    // ddr type index into lookup table
    // We only have one entry in the table right now, so this is fixed.
    static const uint8_t ddr_idx = 0;

    // ATTR_EFF_DRAM_GEN{0=invalid, 1=ddr3, 2=ddr4}
    // p9n only supprts ddr4 right now. So, fixed
    static const uint8_t ddr_type = 2;

    fapi2::buffer<uint64_t> ctl_reg;
    fapi2::buffer<uint64_t> stat_reg;

    // DD level 1.0-1.1, Version 1.0
    // [ddr3/4][dq/adr][speed][impedance][slew_rate]
    // note: Assumes standard voltage for DDR3(1.35V), DDR4(1.2V),
    // little endian, if >=128, lab only debug.
    //
    // ddr_type(1), ddr4=0
    // data/adr(2)data(dq/dqs)=0, adr(cmd/cntl)=1
    // speed(4)1066=0, 1333=1, 1600=2, 1866=3
    // imped(4)24ohms=0, 30ohms=1, 34ohms=2, 40ohms=3 for DQ/DQS
    // imped(4)15ohms=0, 20ohms=1, 30ohms=2, 40ohms=3 for ADR driver
    // slew(3)3V/ns=0, 4V/ns=1, 5V/ns=2, 6V/ns=3

    // Too many in here for real-world. But this allows us to test out the
    // logic to make sure we're in good shape as we add to this table. We
    // can redice this table before flight BRS.
    std::vector< std::pair< tags_t, slew_table_t> > slew_table =
    {
        {
            TAG_ADR, {
                {
                    TAG_1066MHZ,
                    {
                        { TAG_15OHM, {{TAG_3VNS, 142}, {TAG_4VNS, 139}, {TAG_5VNS, 136}, {TAG_6VNS, 134}} },
                        { TAG_20OHM, {{TAG_3VNS, 140}, {TAG_4VNS, 136}, {TAG_5VNS, 134}, {TAG_6VNS, 133}} },
                        { TAG_30OHM, {{TAG_3VNS, 138}, {TAG_4VNS, 134}, {TAG_5VNS, 131}, {TAG_6VNS, 131}} },
                        { TAG_40OHM, {{TAG_3VNS, 133}, {TAG_4VNS, 131}, {TAG_5VNS, 131}, {TAG_6VNS, 131}} },
                    }
                },


                {
                    TAG_1333MHZ,
                    {
                        { TAG_15OHM, {{TAG_3VNS, 145}, {TAG_4VNS, 142}, {TAG_5VNS, 139}, {TAG_6VNS, 136}} },
                        { TAG_20OHM, {{TAG_3VNS, 143}, {TAG_4VNS, 138}, {TAG_5VNS, 135}, {TAG_6VNS, 134}} },
                        { TAG_30OHM, {{TAG_3VNS, 140}, {TAG_4VNS, 135}, {TAG_5VNS, 132}, {TAG_6VNS, 132}} },
                        { TAG_40OHM, {{TAG_3VNS, 134}, {TAG_4VNS, 132}, {TAG_5VNS, 132}, {TAG_6VNS, 132}} },
                    }
                },


                {
                    TAG_1600MHZ,
                    {
                        { TAG_15OHM, {{TAG_3VNS, 21}, {TAG_4VNS,  16}, {TAG_5VNS,  13}, {TAG_6VNS,  10}} },
                        { TAG_20OHM, {{TAG_3VNS, 18}, {TAG_4VNS,  12}, {TAG_5VNS,   9}, {TAG_6VNS, 135}} },
                        { TAG_30OHM, {{TAG_3VNS, 15}, {TAG_4VNS,   8}, {TAG_5VNS, 133}, {TAG_6VNS, 133}} },
                        { TAG_40OHM, {{TAG_3VNS,  7}, {TAG_4VNS, 133}, {TAG_5VNS, 133}, {TAG_6VNS, 133}} },
                    }
                },


                {
                    TAG_1866MHZ,
                    {
                        { TAG_15OHM, {{TAG_3VNS, 24}, {TAG_4VNS,  19}, {TAG_5VNS,  15}, {TAG_6VNS,  11}} },
                        { TAG_20OHM, {{TAG_3VNS, 21}, {TAG_4VNS,  14}, {TAG_5VNS,  10}, {TAG_6VNS, 136}} },
                        { TAG_30OHM, {{TAG_3VNS, 17}, {TAG_4VNS,  10}, {TAG_5VNS, 134}, {TAG_6VNS, 134}} },
                        { TAG_40OHM, {{TAG_3VNS,  9}, {TAG_4VNS, 134}, {TAG_5VNS, 134}, {TAG_6VNS, 134}} },
                    }
                },

                {
                    TAG_2400MHZ,
                    {
                        { TAG_15OHM, {{TAG_3VNS, 24}, {TAG_4VNS,  19}, {TAG_5VNS,  15}, {TAG_6VNS,  11}} },
                        { TAG_20OHM, {{TAG_3VNS, 21}, {TAG_4VNS,  14}, {TAG_5VNS,  10}, {TAG_6VNS, 136}} },
                        { TAG_30OHM, {{TAG_3VNS, 17}, {TAG_4VNS,  10}, {TAG_5VNS, 134}, {TAG_6VNS, 134}} },
                        { TAG_40OHM, {{TAG_3VNS,  9}, {TAG_4VNS, 134}, {TAG_5VNS, 134}, {TAG_6VNS, 134}} },
                    }
                },

            },
        },

        {
            TAG_DATA, {
                {
                    TAG_1066MHZ,
                    {
                        { TAG_24OHM, {{TAG_3VNS, 138}, {TAG_4VNS, 135}, {TAG_5VNS, 134}, {TAG_6VNS, 133}} },
                        { TAG_30OHM, {{TAG_3VNS, 139}, {TAG_4VNS, 136}, {TAG_5VNS, 134}, {TAG_6VNS, 132}} },
                        { TAG_34OHM, {{TAG_3VNS, 140}, {TAG_4VNS, 136}, {TAG_5VNS, 135}, {TAG_6VNS, 133}} },
                        { TAG_40OHM, {{TAG_3VNS, 140}, {TAG_4VNS, 136}, {TAG_5VNS, 132}, {TAG_6VNS, 132}} },
                    }
                },

                {
                    TAG_1333MHZ,
                    {
                        { TAG_24OHM, {{TAG_3VNS, 139}, {TAG_4VNS, 137}, {TAG_5VNS, 135}, {TAG_6VNS, 134}} },
                        { TAG_30OHM, {{TAG_3VNS, 142}, {TAG_4VNS, 138}, {TAG_5VNS, 135}, {TAG_6VNS, 133}} },
                        { TAG_34OHM, {{TAG_3VNS, 143}, {TAG_4VNS, 138}, {TAG_5VNS, 135}, {TAG_6VNS, 133}} },
                        { TAG_40OHM, {{TAG_3VNS, 143}, {TAG_4VNS, 138}, {TAG_5VNS, 133}, {TAG_6VNS, 132}} },
                    }
                },

                {
                    TAG_1600MHZ,
                    {
                        { TAG_24OHM, {{TAG_3VNS, 15}, {TAG_4VNS,  11}, {TAG_5VNS,   9}, {TAG_6VNS, 135}} },
                        { TAG_30OHM, {{TAG_3VNS, 17}, {TAG_4VNS,  11}, {TAG_5VNS,   9}, {TAG_6VNS, 135}} },
                        { TAG_34OHM, {{TAG_3VNS, 18}, {TAG_4VNS,  13}, {TAG_5VNS,   9}, {TAG_6VNS, 134}} },
                        { TAG_40OHM, {{TAG_3VNS, 18}, {TAG_4VNS,  11}, {TAG_5VNS,   6}, {TAG_6VNS, 133}} },
                    }
                },


                {
                    TAG_1866MHZ,
                    {
                        { TAG_24OHM, {{TAG_3VNS, 18}, {TAG_4VNS,  13}, {TAG_5VNS,  10}, {TAG_6VNS, 137}} },
                        { TAG_30OHM, {{TAG_3VNS, 19}, {TAG_4VNS,  13}, {TAG_5VNS,  10}, {TAG_6VNS, 136}} },
                        { TAG_34OHM, {{TAG_3VNS, 21}, {TAG_4VNS,  15}, {TAG_5VNS,  10}, {TAG_6VNS, 135}} },
                        { TAG_40OHM, {{TAG_3VNS, 21}, {TAG_4VNS,  13}, {TAG_5VNS,   8}, {TAG_6VNS, 134}} },
                    }
                },

                {
                    TAG_2400MHZ,
                    {
                        { TAG_24OHM, {{TAG_3VNS, 18}, {TAG_4VNS,  13}, {TAG_5VNS,  10}, {TAG_6VNS, 137}} },
                        { TAG_30OHM, {{TAG_3VNS, 19}, {TAG_4VNS,  13}, {TAG_5VNS,  10}, {TAG_6VNS, 136}} },
                        { TAG_34OHM, {{TAG_3VNS, 21}, {TAG_4VNS,  15}, {TAG_5VNS,  10}, {TAG_6VNS, 135}} },
                        { TAG_40OHM, {{TAG_3VNS, 21}, {TAG_4VNS,  13}, {TAG_5VNS,   8}, {TAG_6VNS, 134}} },
                    }
                },

            }
        }
    };

    // Get the vector of ports. Note that we presently think there's a bit in the CCS_MODE
    // register which needs to be twiddled during slew cal. That means our caller can't
    // put each port's slew cal on a thread and do them in parallel. So, we interleave.
    // If that requirement for that MCBIST register goes away, then these functions can turn
    // in to per-port functions and the caller can decide to loop or thread as appropriate.
    // Or maybe per MCS given the attribute work we need to do at the end ...
    auto l_ports = i_target.getChildren<TARGET_TYPE_MCA>(TARGET_STATE_FUNCTIONAL);

    // Cache the name of our target. We can't just keep the pointer from c_str as
    // it points to thread-local space and anything we call might change the string.
    char l_name[fapi2::MAX_ECMD_STRING_LEN];
    strncpy(l_name, mss::c_str(i_target), fapi2::MAX_ECMD_STRING_LEN);

    // p9n is ddr4 only for now, so skip checking the dimm generation (effective config
    // should have raised a rukus if this isn't a DDR4 dimm ...

    FAPI_TRY( mss::freq(i_target, ddr_freq),
              "Unable to get ddr freq for %s", l_name );

    // Note: this catches two cases. One where ddr_freq is 0 and the other
    // where we put something slow in we don't (yet?) support
    FAPI_ASSERT( ddr_freq > 1732,
                 fapi2::MSS_SLEW_CAL_INVALID_FREQ(),
                 "Invalid ATTR_MSS_FREQ (%d) on %s", ddr_freq, l_name );

    // Get a list of functional ports.
    // Note: If we need to use the functional vector to figure this out,
    // change this to an mss call, and bury the attribute manipluation
    // in that function so it can be shared and tests. BRS

    //
    // This doesn't match teh Centaur workbook algorithm, but it matches the P8 code so
    // I'm leaving it this way. The algorithm according to the Centaur book would be to
    // configure ADR/MCLK detect and then wait for BB_LOCK. Then, enable the cal engine and
    // wait 2K clocks. So to "fix" you'd move the polling for BB_LOCK above the putScom. BRS
    //

    // Sanity check the DRAM generation
    for (auto c : i_target.getChildren<TARGET_TYPE_MCS>())
    {
        FAPI_TRY( check::dram_type(c) );
    }

    // Step A: Configure ADR registers and MCLK detect (done in ddr_phy_reset)
    {
        for (auto p : l_ports)
        {
            FAPI_INF("Enabling slew calibration engine on port %i: DDR%i(%u) %u(%u) in %s",
                     mss::pos(p), (ddr_type + 2), ddr_idx, ddr_freq, freq_idx, l_name);

            // Note: This is wrong. Cant' find the SLEW_CAL enable bit in n10_e9024, so leaving this here for now BRS
            FAPI_TRY( fapi2::putScom(p, MCA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0,
                                     fapi2::buffer<uint64_t>().setBit<ENABLE_BIT>()),
                      "Error enabling slew calibration engine in DDRPHY_ADR_SLEW_CAL_CNTL register.");
        }
    }

    // Note: must be 2000 nclks+ after setting enable bit
    // normally 2000, but since cal doesn't work in SIM, setting to 1
    FAPI_TRY( fapi2::delay(cycles_to_ns(i_target, 2000), cycles_to_simcycles(1)) );

    // Create calibrated slew settings, per MCS. We do this as the attributes are written per MCS,
    // and this makes it easier to keep track of what's going where, etc.
    for (auto c : i_target.getChildren<TARGET_TYPE_MCS>())
    {
        // [adr or data][port on mcs][imp][slew]
        uint8_t calibrated_slew[2][PORTS_PER_MCS][MAX_NUM_IMP][MAX_NUM_CAL_SLEW_RATES] = {0};

        auto l_mcs_ports = c.getChildren<TARGET_TYPE_MCA>();

        for (auto p : l_mcs_ports)
        {
            for (auto e : slew_table)
            {
                FAPI_INF("Starting %s, port %d slew calibration", (e.first == TAG_ADR ? "adr" : "data"), mss::pos(p));

                for (auto this_table : e.second)
                {
                    std::vector<tags_t> l_where_am_i;
                    l_where_am_i.push_back(e.first);
                    FAPI_TRY( perform_slew_cal(p, l_where_am_i, this_table, calibrated_slew) );
                }
            }
        }

        // We have the calibrated slew settings, disable the calibration engine and do the
        // attribute dance.
        for (auto p : l_mcs_ports)
        {
            // Note: This is wrong. Cant' find the SLEW_CAL enable bit in n10_e9024, so leaving this here for now BRS
            FAPI_TRY( fapi2::putScom(p, MCA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0,
                                     fapi2::buffer<uint64_t>().clearBit<ENABLE_BIT>()),
                      "Error disabling slew calibration engine in DDRPHY_ADR_SLEW_CAL_CNTL register.");
        }

//    FAPI_TRY( slew_cal_attributes() );
    }

fapi_try_exit:
    return fapi2::current_err;
}
} // namespace
