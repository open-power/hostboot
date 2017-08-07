/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/port.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/ecc/ecc.H>

namespace mss
{

// Bit position settings for ATTR_MSS_MRW_PERIODIC_MEMCAL_MODE_OPTIONS
// For each bit: OFF = 0, ON = 1
// Byte 0:
constexpr uint64_t BIT_ZCAL = 0;            //      0: ZCAL
constexpr uint64_t BIT_SYSCLK_ALIGN = 1;    //      1: SYSCK_ALIGN
constexpr uint64_t BIT_RDCENTERING = 2;     //      2: RDCENTERING
constexpr uint64_t BIT_RDLCK_ALIGN = 3;     //      3: RDLCK_ALIGN
constexpr uint64_t BIT_DQS_ALIGN = 4;       //      4: DQS_ALIGN
constexpr uint64_t BIT_RDCLK_UPDATE = 5;    //      5: RDCLK_UPDATE
constexpr uint64_t BIT_PER_DUTYCYCLE = 6;   //      6: PER_DUTYCYCLE
constexpr uint64_t BIT_PERCAL_PWR_DIS = 7;  //      7: PERCAL_PWR_DIS

// Byte 1:
constexpr uint64_t BIT_PERCAL_REPEAT_0 = 8; //       0: PERCAL_REPEAT
constexpr uint64_t BIT_PERCAL_REPEAT_1 = 9; //       1: PERCAL_REPEAT
constexpr uint64_t BIT_PERCAL_REPEAT = 10;  //       2: PERCAL_REPEAT
constexpr uint64_t BIT_SINGLE_BIT_MPR = 11; //       3: SINGLE_BIT_MPR
constexpr uint64_t BIT_MBA_CFG_0 = 12;      //       4: MBA_CFG_0
constexpr uint64_t BIT_MBA_CFG_1 = 13;      //       5: MBA_CFG_1
constexpr uint64_t BIT_SPARE_6 = 14;        //       6: SPARE
constexpr uint64_t BIT_SPARE_7 = 15;        //       7: SPARE

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
    fapi2::buffer<uint16_t> l_per_memcal_mode_options = 0;
    fapi2::buffer<uint16_t> l_per_zqcal_mode_options = 0;

    fapi2::buffer<uint64_t> l_periodic_cal_config;

    std::vector<uint64_t> l_pairs;

    FAPI_INF("Enable periodic cal");

    uint8_t l_sim = 0;
    FAPI_TRY( mss::is_simulation(l_sim) );

    // Even if we're in sim, do these so that we do the attribute work (even though the values aren't used.)
    FAPI_TRY( mss::eff_memcal_interval(i_target, l_memcal_interval) );
    FAPI_TRY( mss::eff_zqcal_interval(i_target, l_zqcal_interval) );

    // TODO RTC: 166433 Leave periodics off (0's) by default for the time being
#ifdef TODO_166433_PERIODICS
    FAPI_TRY( mss::mrw_periodic_memcal_mode_options(l_per_memcal_mode_options) );
    FAPI_INF("mrw_periodic_memcal_mode_options: 0x%02x", l_per_memcal_mode_options);

    FAPI_TRY( mss::mrw_periodic_zqcal_mode_options(l_per_zqcal_mode_options) );
    FAPI_INF("mrw_periodic_zqcal_mode_options: 0x%02x", l_per_memcal_mode_options);
#endif

    FAPI_INF("memcal interval %dck, zqcal interval %dck", l_memcal_interval, l_zqcal_interval);

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
    if (l_per_zqcal_mode_options != 0)
    {
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
            l_data.writeBit<TT::CAL0Q_CAL_INTERVAL_TMR0_ENABLE>(l_sim ? 0 : 1);

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
        FAPI_TRY( reset_zqcal_config(i_target) );

        // No ZQCAL in sim
        l_periodic_cal_config.writeBit<TT::PER_ENA_ZCAL>(l_sim ? 0 : 1);

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
                l_sim ? (l_zqcal_interval / TT::MAGIC_NUMBER_SIM) + 1 : (l_zqcal_interval / TT::MAGIC_NUMBER_NOT_SIM) + 1);
            FAPI_INF("zcal timer reload: 0x%016lx", l_zcal_timer_reload);
            FAPI_TRY( mss::putScom(i_target, TT::PHY_ZCAL_TIMER_RELOAD_REG, l_zcal_timer_reload) );
        }

    }

    // MEMCAL
    if (l_per_memcal_mode_options != 0)
    {
        // Setup the periodic enable rank pair field in the phy cal config and the mc. This used to be shared
        // between the MC and the PHY in Centaur but no longer is - so we write the same data in two registers.
        // Note: Why is this vastly different from the rank setup in the zqcal config and why do we
        // need to do it twice for the PHY? BRS
        fapi2::buffer<uint64_t> l_rank_config;

        FAPI_TRY( mss::rank::get_rank_pairs(i_target, l_pairs) );

        for (const auto pair : l_pairs)
        {
            l_rank_config.setBit(pair);
        }

        FAPI_INF("periodic ranks: 0x%016lx", l_rank_config);

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
        // #       48:63   ,       0x0000, (def_l_sim)                    ;# match dials
        //         48:63   ,       ((ATTR_EFF_MEMCAL_INTERVAL/196605)+1), (def_FAST_SIM_PC==0)    ;# FAST_SIM_PER_CNTR=0
        //         48:63   ,       ((ATTR_EFF_MEMCAL_INTERVAL/765)+1),    (def_FAST_SIM_PC==1)    ;# FAST_SIM_PER_CNTR=1
        // #       48:63   ,       0x01D1,       any                                             ;       # 464 = 114ms @ 1600MHz

        // Add the ranks to the phy config
        if (l_per_memcal_mode_options.getBit<BIT_ZCAL>())
        {
            l_periodic_cal_config.insert<TT::PER_ZCAL_ENA_RANK, TT::PER_ZCAL_ENA_RANK_LEN>(l_rank_config);
        }

        // If we're in sim, enable the fast-sim mode
        l_periodic_cal_config.writeBit<TT::PER_FAST_SIM_CNTR>(l_sim);

        l_periodic_cal_config.writeBit<TT::PER_ENA_SYSCLK_ALIGN>( l_per_memcal_mode_options.getBit<BIT_SYSCLK_ALIGN>() );

        // Per John Bialas 5/16:  "... periodic read centering does not work ... We are re-evaluating fixing it for DD2"
#ifdef PERIODIC_READ_CENTERING_FIX
        l_periodic_cal_config.writeBit<TT::PER_ENA_READ_CTR>( l_per_memcal_mode_options.getBit<BIT_RDCENTERING>() );
#endif
        l_periodic_cal_config.writeBit<TT::PER_ENA_RDCLK_ALIGN>(l_per_memcal_mode_options.getBit<BIT_RDLCK_ALIGN>() );
        l_periodic_cal_config.writeBit<TT::PER_ENA_DQS_ALIGN>( l_per_memcal_mode_options.getBit<BIT_DQS_ALIGN>() );

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
                l_sim ? (l_memcal_interval / TT::MAGIC_NUMBER_SIM) + 1 : (l_memcal_interval / TT::MAGIC_NUMBER_NOT_SIM) + 1);
            FAPI_INF("phy cal timer reload: 0x%016lx", l_cal_timer_reload);
            FAPI_TRY( mss::putScom(i_target, TT::PHY_CAL_TIMER_RELOAD_REG, l_cal_timer_reload ) );
        }

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Convert a bitmap from the BAD_DQ_BITMAP attribute to a vector of bad DQ indexes
/// @param[in] i_bad_bits an 8-bit bitmap of bad bits
/// @param[in] i_nibble which nibble of the bitmap to convert
/// @return std::vector of DQ bits marked as bad in the bitmap
///
std::vector<uint64_t> bad_bit_helper(const uint8_t i_bad_bits, const size_t i_nibble)
{
    std::vector<uint64_t> l_output;
    fapi2::buffer<uint8_t> l_bit_buffer(i_bad_bits);

    const size_t l_start = (i_nibble == 0) ? 0 : BITS_PER_NIBBLE;

    for (size_t l_offset = 0; l_offset < BITS_PER_NIBBLE; ++l_offset)
    {
        if (l_bit_buffer.getBit(l_start + l_offset))
        {
            l_output.push_back(l_start + l_offset);
        }
    }

    return l_output;
}

///
/// @brief Place a symbol mark in a Firmware Mark Store register
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in] i_dq the bad DQ bit
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode place_symbol_mark(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint64_t i_rank,
                                    const uint64_t i_dq)
{
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    const auto l_dimm_idx = mss::index(i_target);
    const auto l_rank_idx = mss::index(i_rank);

    uint8_t l_galois = 0;
    mss::mcbist::address l_addr;

    // For symbol marks, we set the appropriate Firmware Mark Store reg, with the symbol's
    // Galois code, mark_type=SYMBOL, mark_region=MRANK, and the address of the DIMM+MRANK
    // TODO RTC:165133 Remove static_cast once Galois API is updated to accept uint64_t input
    FAPI_TRY( mss::ecc::dq_to_galois(static_cast<uint8_t>(i_dq), l_galois) );

    l_addr.set_dimm(l_dimm_idx).set_master_rank(l_rank_idx);

    FAPI_DBG("Setting firmware symbol mark on rank:%d dq:%d galois:0x%02x", i_rank, i_dq, l_galois);
    FAPI_TRY( mss::ecc::set_fwms(l_mca, i_rank, l_galois, mss::ecc::fwms::mark_type::SYMBOL,
                                 mss::ecc::fwms::mark_region::MRANK, l_addr) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Place a chip mark in a Hardware Mark Store register
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode place_chip_mark(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint64_t i_rank)
{
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    uint8_t l_galois = 0;

    // For chip marks, we set the appropriate Hardware Mark Store reg, with the DIMM's
    // symbol[0] Galois code, and both confirmed and exit1 bits set
    FAPI_TRY( mss::ecc::symbol_to_galois(0, l_galois) );

    FAPI_DBG("Setting hardware (chip) mark on rank:%d galois:0x%02x", i_rank, l_galois);
    FAPI_TRY( mss::ecc::set_hwms(l_mca, i_rank, l_galois) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restore symbol and chip marks according to BAD_DQ_BITMAP attribute, helper function for unit testing
/// Specialization for TARGET_TYPE_DIMM
/// @param[in] i_target the DIMM target
/// @param[in] i_bad_bits the bad bits values from the VPD, for the specified DIMM
/// @param[out] o_repairs_applied 8-bit mask, where a bit set means a rank had repairs applied (bit0-7 = rank0-7)
/// @param[out] o_repairs_exceeded 2-bit mask, where a bit set means a DIMM had more bad bits than could be repaired (bit0-1 = DIMM0-1)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
// TODO RTC:157753 Template parameters here are Nimbus specific. Convert to attribute/trait of TARGET_TYPE_MCA when traits are created.
template<>
fapi2::ReturnCode restore_repairs_helper<fapi2::TARGET_TYPE_DIMM, MAX_RANK_PER_DIMM, BAD_DQ_BYTE_COUNT>(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint8_t i_bad_bits[MAX_RANK_PER_DIMM][BAD_DQ_BYTE_COUNT],
    fapi2::buffer<uint8_t>& o_repairs_applied,
    fapi2::buffer<uint8_t>& o_repairs_exceeded)
{
    FAPI_INF("Restore repair marks from bad DQ data");

    std::vector<uint64_t> l_ranks;
    const auto l_dimm_idx = mss::index(i_target);

    FAPI_TRY( mss::rank::ranks(i_target, l_ranks) );

    // loop through ranks
    for (const auto l_rank : l_ranks)
    {
        const auto l_rank_idx = mss::index(l_rank);

        repair_state_machine<fapi2::TARGET_TYPE_DIMM> l_machine;

        // loop through bytes
        for (uint64_t l_byte = 0; l_byte < (MAX_DQ_NIBBLES_X4 / NIBBLES_PER_BYTE); ++l_byte)
        {
            for (size_t l_nibble = 0; l_nibble < NIBBLES_PER_BYTE; ++l_nibble)
            {
                const auto l_bad_dq_vector = bad_bit_helper(i_bad_bits[l_rank_idx][l_byte], l_nibble);
                FAPI_DBG("Total bad bits on DIMM:%d rank:%d nibble%d: %d", l_dimm_idx, l_rank, (l_byte * NIBBLES_PER_BYTE) + l_nibble,
                         l_bad_dq_vector.size());

                // apply repairs and update repair machine state
                // if there are no bad bits (l_bad_dq_vector.size() == 0) no action is necessary
                if (l_bad_dq_vector.size() == 1)
                {
                    FAPI_TRY( l_machine.one_bad_dq(i_target, l_rank, (l_bad_dq_vector[0] + (l_byte * BITS_PER_BYTE)),
                                                   o_repairs_applied, o_repairs_exceeded) );
                }
                else if (l_bad_dq_vector.size() > 1)
                {
                    FAPI_TRY( l_machine.multiple_bad_dq(i_target, l_rank, o_repairs_applied, o_repairs_exceeded) );
                }

                // if repairs have been exceeded, we're done
                if (o_repairs_exceeded.getBit(l_dimm_idx))
                {
                    FAPI_INF("Repairs exceeded on DIMM %s", mss::c_str(i_target));
                    return fapi2::FAPI2_RC_SUCCESS;
                }
            } // end loop through nibbles
        } // end loop through bytes
    } // end loop through ranks

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restore symbol and chip marks according to BAD_DQ_BITMAP attribute
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target A target representing a port
/// @param[out] o_repairs_applied 8-bit mask, where a bit set means a rank had repairs applied (bit0-7 = rank0-7)
/// @param[out] o_repairs_exceeded 2-bit mask, where a bit set means a DIMM had more bad bits than could be repaired (bit0-1 = DIMM0-1)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode restore_repairs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   fapi2::buffer<uint8_t>& o_repairs_applied,
                                   fapi2::buffer<uint8_t>& o_repairs_exceeded)
{
    uint8_t l_bad_bits[MAX_RANK_PER_DIMM][BAD_DQ_BYTE_COUNT] = {};

    o_repairs_applied = 0;
    o_repairs_exceeded = 0;

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( mss::bad_dq_bitmap(l_dimm, &(l_bad_bits[0][0])) );

        FAPI_TRY( (restore_repairs_helper<fapi2::TARGET_TYPE_DIMM, MAX_RANK_PER_DIMM, BAD_DQ_BYTE_COUNT>(
                       l_dimm, l_bad_bits, o_repairs_applied, o_repairs_exceeded)) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set a new state in the repair state machine
/// @tparam T, the fapi2 target type of the DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_state shared pointer to the new state to set
///
template< fapi2::TargetType T >
void repair_state<T>::set_state(repair_state_machine<T>& io_machine, std::shared_ptr<repair_state<T>> i_state)
{
    io_machine.update_state(i_state);
}

///
/// @brief Perform a repair for a single bad DQ bit in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in] i_dq the DQ bit index
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode no_fails<fapi2::TARGET_TYPE_DIMM>::one_bad_dq(repair_state_machine<fapi2::TARGET_TYPE_DIMM>&
        io_machine,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const uint64_t i_dq,
        fapi2::buffer<uint8_t>& io_repairs_applied,
        fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // place a symbol mark
    FAPI_TRY( place_symbol_mark(i_target, i_rank, i_dq) );
    io_repairs_applied.setBit(i_rank);
    {
        const auto new_state = std::make_shared<symbol_mark_only<fapi2::TARGET_TYPE_DIMM>>();
        set_state(io_machine, new_state);
    }
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a repair for multiple bad DQ bits in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode no_fails<fapi2::TARGET_TYPE_DIMM>::multiple_bad_dq(repair_state_machine<fapi2::TARGET_TYPE_DIMM>&
        io_machine,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        fapi2::buffer<uint8_t>& io_repairs_applied,
        fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // place a chip mark
    FAPI_TRY( place_chip_mark(i_target, i_rank) );
    io_repairs_applied.setBit(i_rank);
    {
        const auto new_state = std::make_shared<chip_mark_only<fapi2::TARGET_TYPE_DIMM>>();
        set_state(io_machine, new_state);
    }
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a repair for a single bad DQ bit in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in] i_dq the DQ bit index
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode symbol_mark_only<fapi2::TARGET_TYPE_DIMM>::one_bad_dq(repair_state_machine<fapi2::TARGET_TYPE_DIMM>&
        io_machine,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const uint64_t i_dq,
        fapi2::buffer<uint8_t>& io_repairs_applied,
        fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // leave an unrepaired DQ
    const auto new_state = std::make_shared<symbol_mark_plus_unrepaired_dq<fapi2::TARGET_TYPE_DIMM>>();
    set_state(io_machine, new_state);
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Perform a repair for multiple bad DQ bits in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode symbol_mark_only<fapi2::TARGET_TYPE_DIMM>::multiple_bad_dq(
    repair_state_machine<fapi2::TARGET_TYPE_DIMM>& io_machine,
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint64_t i_rank,
    fapi2::buffer<uint8_t>& io_repairs_applied,
    fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // place a chip mark
    FAPI_TRY( place_chip_mark(i_target, i_rank) );
    io_repairs_applied.setBit(i_rank);
    {
        const auto new_state = std::make_shared<chip_and_symbol_mark<fapi2::TARGET_TYPE_DIMM>>();
        set_state(io_machine, new_state);
    }
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a repair for a single bad DQ bit in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in] i_dq the DQ bit index
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode symbol_mark_plus_unrepaired_dq<fapi2::TARGET_TYPE_DIMM>::one_bad_dq(
    repair_state_machine<fapi2::TARGET_TYPE_DIMM>& io_machine,
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint64_t i_rank,
    const uint64_t i_dq,
    fapi2::buffer<uint8_t>& io_repairs_applied,
    fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // repairs exceeded
    io_repairs_exceeded.setBit(mss::index(i_target));
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Perform a repair for multiple bad DQ bits in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode symbol_mark_plus_unrepaired_dq<fapi2::TARGET_TYPE_DIMM>::multiple_bad_dq(
    repair_state_machine<fapi2::TARGET_TYPE_DIMM>& io_machine,
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint64_t i_rank,
    fapi2::buffer<uint8_t>& io_repairs_applied,
    fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // place a chip mark, but also repairs exceeded
    FAPI_TRY( place_chip_mark(i_target, i_rank) );
    io_repairs_applied.setBit(i_rank);
    io_repairs_exceeded.setBit(mss::index(i_target));
    {
        const auto new_state = std::make_shared<chip_and_symbol_mark<fapi2::TARGET_TYPE_DIMM>>();
        set_state(io_machine, new_state);
    }
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a repair for a single bad DQ bit in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in] i_dq the DQ bit index
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode chip_mark_only<fapi2::TARGET_TYPE_DIMM>::one_bad_dq(
    repair_state_machine<fapi2::TARGET_TYPE_DIMM>&
    io_machine,
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint64_t i_rank,
    const uint64_t i_dq,
    fapi2::buffer<uint8_t>& io_repairs_applied,
    fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // place a symbol mark
    FAPI_TRY( place_symbol_mark(i_target, i_rank, i_dq) );
    io_repairs_applied.setBit(i_rank);
    {
        const auto new_state = std::make_shared<chip_and_symbol_mark<fapi2::TARGET_TYPE_DIMM>>();
        set_state(io_machine, new_state);
    }
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a repair for multiple bad DQ bits in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode chip_mark_only<fapi2::TARGET_TYPE_DIMM>::multiple_bad_dq(
    repair_state_machine<fapi2::TARGET_TYPE_DIMM>& io_machine,
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint64_t i_rank,
    fapi2::buffer<uint8_t>& io_repairs_applied,
    fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // repairs exceeded
    io_repairs_exceeded.setBit(mss::index(i_target));
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Perform a repair for a single bad DQ bit in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in] i_dq the DQ bit index
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode chip_and_symbol_mark<fapi2::TARGET_TYPE_DIMM>::one_bad_dq(
    repair_state_machine<fapi2::TARGET_TYPE_DIMM>& io_machine,
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint64_t i_rank,
    const uint64_t i_dq,
    fapi2::buffer<uint8_t>& io_repairs_applied,
    fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // repairs exceeded
    io_repairs_exceeded.setBit(mss::index(i_target));
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Perform a repair for multiple bad DQ bits in a nibble
/// Specialization for TARGET_TYPE_DIMM
/// @param[in,out] io_machine the repair state machine
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode chip_and_symbol_mark<fapi2::TARGET_TYPE_DIMM>::multiple_bad_dq(
    repair_state_machine<fapi2::TARGET_TYPE_DIMM>& io_machine,
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint64_t i_rank,
    fapi2::buffer<uint8_t>& io_repairs_applied,
    fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    // repairs exceeded
    io_repairs_exceeded.setBit(mss::index(i_target));
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Perform a repair for a single bad DQ bit in a nibble
/// @tparam T, the fapi2 target type of the DIMM
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in] i_dq the DQ bit index
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode repair_state_machine<T>::one_bad_dq(const fapi2::Target<T>& i_target,
        const uint64_t i_rank,
        const uint64_t i_dq,
        fapi2::buffer<uint8_t>& io_repairs_applied,
        fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    FAPI_TRY( iv_repair_state->one_bad_dq(*this, i_target, i_rank, i_dq, io_repairs_applied, io_repairs_exceeded) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a repair for multiple bad DQ bits in a nibble
/// @tparam T, the fapi2 target type of the DIMM
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode repair_state_machine<T>::multiple_bad_dq(const fapi2::Target<T>& i_target,
        const uint64_t i_rank,
        fapi2::buffer<uint8_t>& io_repairs_applied,
        fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    FAPI_TRY( iv_repair_state->multiple_bad_dq(*this, i_target, i_rank, io_repairs_applied, io_repairs_exceeded) );
fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
