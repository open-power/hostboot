/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/ddr_phy.H $            */
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
/// @file ddr_phy.H
/// @brief Subroutines to manipulate the phy, or used during phy procedures
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_DDR_PHY_H_
#define _MSS_DDR_PHY_H_

#include <fapi2.H>
#include <mss_attribute_accessors.H>

// Helper macro to condense the checking for PLL lock
#define CHECK_PLL( __target, __register, __buffer, __mask )             \
    FAPI_TRY(mss::getScom( __target, __register, __buffer));          \
    if ((__buffer & __mask) != __mask)                                  \
    {                                                                   \
        FAPI_INF("PLL 0x%lx failed to lock 0x%lx", __register, __buffer); \
        done_polling = false;                                           \
        continue;                                                       \
    }

// Helper macro to condense the checking for PLL lock
#define FFDC_PLL( __target, __register, __buffer, __mask, __ffdc_object ) \
    FAPI_ASSERT( ((__buffer & __mask) == __mask),                       \
                 __ffdc_object.set_EXPECTED_STATUS(__mask)              \
                 .set_ACTUAL_STATUS(__buffer)                           \
                 .set_REGISTER(__register)                              \
                 .set_MCBIST_IN_ERROR(__target),                        \
                 "PLL 0x%llx failed to lock 0x%llx", __register, __buffer);

namespace mss
{

///
/// @brief Perform initializations for the PHY
/// @param[in] i_target, the MCBIST which has the PHYs to initialize
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode phy_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target);

///
/// @brief change resetn to the given state
/// @param[in] i_target, the mcbist
/// @param[in] the desired state
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_resetn( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target, states i_state );

///
/// @brief perform the zctl toggle process
/// @param[in] i_target, the mcbist for the reset recover
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode toggle_zctl( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

/// @brief Change mclk low
/// @param[in] mcbist target
/// @param[in] mss::HIGH or mss::LOW - desired state.
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_force_mclk_low (const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const mss::states i_state);
///
/// @brief Unset the PLL and check to see that the PLL's have started
/// @param[in] the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode deassert_pll_reset( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Setup the phase rotator control registers
/// @param[in] the mcbist target
/// @param[in] the value for the registers
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode setup_phase_rotator_control_registers( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const fapi2::buffer<uint64_t>& i_data );

///
/// @brief Deassetr the sys clk reset
/// @param[in] the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode deassert_sysclk_reset( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Flush the DDR PHY
/// @param[in] the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode ddr_phy_flush( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Reset the training delay configureation
/// @param[in] the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_delay_values( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Lock dphy_gckn and sysclk
/// @param[in] a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode bang_bang_lock( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Configure the DP16 sysclk
/// @param[in] a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode setup_dp16_sysclk( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief check and process initial cal errors
/// @tparam T, the type of the target in question
/// @param[in] the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode process_initial_cal_errors( const fapi2::Target<T>& i_target );

///
/// @brief Setup all the cal config register
/// @tparam T, the target type of the MCA/MBA
/// @param[in] the target associated with this cal setup
/// @param[in] the vector of currently configured rank pairs
/// @param[in] fapi2::buffer<uint16_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode setup_cal_config( const fapi2::Target<T>& i_target,
                                    const std::vector<uint64_t> i_rank_pairs,
                                    const fapi2::buffer<uint16_t> i_cal_steps_enabled);

///
/// @brief Setup all the cal config register
/// @param[in] the target associated with this cal setup
/// @param[in] i_rank, one currently configured rank pairs
/// @param[in] fapi2::buffer<uint16_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode setup_cal_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rank,
                                    const fapi2::buffer<uint16_t> i_cal_steps_enabled);

///
/// @brief Setup wc_config0
/// @tparam T, the target type of the MCA/MBA
/// @param[in] the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode reset_wc_config0( const fapi2::Target<T>& i_target );

///
/// @brief Setup wc_config0
/// @param[in] the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
inline fapi2::ReturnCode reset_wc_config0( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim) );

    // This is a simplification - in sim we don't have DQS wire delays so we don't acccount for them BRS
    l_data.insertFromRight<MCA_DDRPHY_WC_CONFIG0_P0_TWLO_TWLOE,
                           MCA_DDRPHY_WC_CONFIG0_P0_TWLO_TWLOE_LEN>(mss::twlo_twloe(i_target));

    // WL_ONE_DQS_PULSE = enable (one pulse)
    l_data.setBit<MCA_DDRPHY_WC_CONFIG0_P0_WL_ONE_DQS_PULSE>();

    // FW_WR_RD [same formula as RD_WR? max(tWTR+11,AL+tRTP+3), ATTR_EFF_DRAM_AL(0,1,2)]
    // 57:62, 0b000000, (def_is_sim);   # is this max?
    // 57:62, 0b100000, any;   # dd0 = 17 clocks, now 32 from SWyatt
    {
        const uint64_t FW_WR_RD = l_is_sim ? 0b000000 : 0b100000;
        l_data.insertFromRight<MCA_DDRPHY_WC_CONFIG0_P0_FW_WR_RD,
                               MCA_DDRPHY_WC_CONFIG0_P0_FW_WR_RD_LEN>(FW_WR_RD);
    }

    // 63, 0b0, any;       # CUSTOM_INIT_WRITE
    l_data.clearBit<MCA_DDRPHY_WC_CONFIG0_P0_CUSTOM_INIT_WRITE>();

    FAPI_DBG("wc_config0 0x%llx (tWLO_tWLOE: %d)", l_data, mss::twlo_twloe(i_target));
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_WC_CONFIG0_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}





///
/// @brief Setup wc_config1
/// @tparam T, the target type of the MCA/MBA
/// @param[in] the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode reset_wc_config1( const fapi2::Target<T>& i_target );

///
/// @brief Setup wc_config1
/// @param[in] the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
inline fapi2::ReturnCode reset_wc_config1( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // Reset WC_CONFIG1 with the values directly from the PHY databook
    fapi2::buffer<uint64_t> l_data;

    l_data.insertFromRight<MCA_DDRPHY_WC_CONFIG1_P0_BIG_STEP, MCA_DDRPHY_WC_CONFIG1_P0_BIG_STEP_LEN>(WR_LVL_BIG_STEP);
    l_data.insertFromRight<MCA_DDRPHY_WC_CONFIG1_P0_SMALL_STEP, MCA_DDRPHY_WC_CONFIG1_P0_SMALL_STEP_LEN>(WR_LVL_SMALL_STEP);
    l_data.insertFromRight<MCA_DDRPHY_WC_CONFIG1_P0_WR_PRE_DLY,
                           MCA_DDRPHY_WC_CONFIG1_P0_WR_PRE_DLY_LEN>(WR_LVL_PRE_DLY);
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_WC_CONFIG1_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}



///
/// @brief Setup wc_config2
/// @tparam T, the target type of the MCA/MBA
/// @param[in] the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode reset_wc_config2( const fapi2::Target<T>& i_target );

///
/// @brief Setup wc_config2
/// @param[in] the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
inline fapi2::ReturnCode reset_wc_config2( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

    l_data.insertFromRight<MCA_DDRPHY_WC_CONFIG2_P0_NUM_VALID_SAMPLES,
                           MCA_DDRPHY_WC_CONFIG2_P0_NUM_VALID_SAMPLES_LEN>(WR_LVL_NUM_VALID_SAMPLES);

    l_data.insertFromRight<MCA_DDRPHY_WC_CONFIG2_P0_FW_RD_WR, MCA_DDRPHY_WC_CONFIG2_P0_FW_RD_WR_LEN>(WR_CNTR_FW_RD_WR);

    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_WC_CONFIG2_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}




///
/// @brief Setup wc_config3
/// @tparam T, the target type of the MCA/MBA
/// @param[in] the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode reset_wc_config3( const fapi2::Target<T>& i_target );

///
/// @brief Setup wc_config3
/// @param[in] the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
inline fapi2::ReturnCode reset_wc_config3( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim) );

    // MCA_DDRPHY_WC_CONFIG3_P0_MRS_CMD_DQ_ON is 0's

    // 55:60, 0b000000, (def_is_sim); # MRS_CMD_DQ_OFF        !!
    // 55:60, 0b111111, any   ;       # MRS_CMD_DQ_OFF        !!
    {
        const uint64_t CMD_DQ_OFF = l_is_sim ? 0b000000 : 0b111111;
        l_data.insertFromRight<MCA_DDRPHY_WC_CONFIG3_P0_MRS_CMD_DQ_OFF,
                               MCA_DDRPHY_WC_CONFIG3_P0_MRS_CMD_DQ_OFF_LEN>(CMD_DQ_OFF);
    }

    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_WC_CONFIG3_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Setup WC RTT Write Swap Enable Register
/// @tparam T, the target type of the MCA/MBA
/// @param[in] the target
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode reset_wc_rtt_wr_swap_enable( const fapi2::Target<T>& i_target );

///
/// @brief Setup WC RTT Write Swap Enable Register
/// @param[in] the MCA target
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
inline fapi2::ReturnCode reset_wc_rtt_wr_swap_enable( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(i_target, MCA_DDRPHY_WC_RTT_WR_SWAP_ENABLE_P0, l_data) );

    // Per John Bialas 1/16: The enable RTT_SWAP bit is causing problems in sim.
    l_data.clearBit<MCA_DDRPHY_WC_RTT_WL_SWAP_ENABLE_P0>();
    l_data.setBit<MCA_DDRPHY_WC_RTT_WR_CTL_SWAP_ENABLE_P0>();

    FAPI_DBG("wc_swap_enable 0x%llx", l_data);
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_WC_RTT_WR_SWAP_ENABLE_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}






///
/// @brief Setup seq_config0
/// @tparam T, the target type of the MCA/MBA
/// @param[in] the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode reset_seq_config0( const fapi2::Target<T>& i_target );

///
/// @brief Setup seq_config0
/// @param[in] the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
inline fapi2::ReturnCode reset_seq_config0( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

    // ATTR_VPD_DRAM_2N_MODE_ENABLED  49, 0b1, (def_2N_mode);       # enable 2 cycle addr mode BRS

    FAPI_DBG("seq_config0 0x%llx", l_data);
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_CONFIG0_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}




///
/// @brief Setup odt_wr/rd_config
/// @tparam T, the target type of the MCA/MBA
/// @param[in] the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode reset_odt_config( const fapi2::Target<T>& i_target );

///
/// @brief Setup odt_wr/rd_config
/// @param[in] the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
inline fapi2::ReturnCode reset_odt_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    uint8_t l_odt_rd[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t l_odt_wr[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];

    FAPI_TRY( mss::eff_odt_rd(i_target, &(l_odt_rd[0][0])) );
    FAPI_TRY( mss::eff_odt_wr(i_target, &(l_odt_wr[0][0])) );

    // Nimbus PHY is more or less hard-wired for 2 DIMM/port 4R/DIMM
    // So there's not much point in looping over DIMM or ranks.

    //
    // ODT Read
    //
    {
        // DPHY01_DDRPHY_SEQ_ODT_RD_CONFIG0_P0
        // 48:55, ATTR_VPD_ODT_RD[0][0][0]; # when Read of Rank0
        // 56:63, ATTR_VPD_ODT_RD[0][0][1]; # when Read of Rank1
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0_VALUES0,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0_VALUES0_LEN>(l_odt_rd[0][0]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0_VALUES1,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0_VALUES1_LEN>(l_odt_rd[0][1]);
        FAPI_DBG("odt_rd_config0: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_RD_CONFIG1_P0
        // 48:55, ATTR_VPD_ODT_RD[0][0][2]; # when Read of Rank2
        // 56:63, ATTR_VPD_ODT_RD[0][0][3]; # when Read of Rank3
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0_VALUES2,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0_VALUES2_LEN>(l_odt_rd[0][2]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0_VALUES3,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0_VALUES3_LEN>(l_odt_rd[0][3]);
        FAPI_DBG("odt_rd_config1: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_RD_CONFIG2_P0
        // 48:55, ATTR_VPD_ODT_RD[0][1][0]; # when Read of Rank4
        // 56:63, ATTR_VPD_ODT_RD[0][1][1]; # when Read of Rank5
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0_VALUES4,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0_VALUES4_LEN>(l_odt_rd[1][0]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0_VALUES5,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0_VALUES5_LEN>(l_odt_rd[1][1]);
        FAPI_DBG("odt_rd_config2: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_RD_CONFIG3_P0
        // 48:55, ATTR_VPD_ODT_RD[0][1][2]; # when Read of Rank6
        // 56:63, ATTR_VPD_ODT_RD[0][1][3]; # when Read of Rank7
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0_VALUES6,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0_VALUES6_LEN>(l_odt_rd[1][2]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0_VALUES7,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0_VALUES7_LEN>(l_odt_rd[1][3]);
        FAPI_DBG("odt_rd_config3: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0, l_data) );
    }

    //
    // ODT Write
    //
    {
        // DPHY01_DDRPHY_SEQ_ODT_WR_CONFIG0_P0
        // 48:55, ATTR_VPD_ODT_WR[0][0][0]; # when Read of Rank0
        // 56:63, ATTR_VPD_ODT_WR[0][0][1]; # when Read of Rank1
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0_VALUES0,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0_VALUES0_LEN>(l_odt_wr[0][0]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0_VALUES1,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0_VALUES1_LEN>(l_odt_wr[0][1]);
        FAPI_DBG("odt_wr_config0: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_WR_CONFIG1_P0
        // 48:55, ATTR_VPD_ODT_WR[0][0][2]; # when Read of Rank2
        // 56:63, ATTR_VPD_ODT_WR[0][0][3]; # when Read of Rank3
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0_VALUES2,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0_VALUES2_LEN>(l_odt_wr[0][2]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0_VALUES3,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0_VALUES3_LEN>(l_odt_wr[0][3]);
        FAPI_DBG("odt_wr_config1: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_WR_CONFIG2_P0
        // 48:55, ATTR_VPD_ODT_WR[0][1][0]; # when Read of Rank4
        // 56:63, ATTR_VPD_ODT_WR[0][1][1]; # when Read of Rank5
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0_VALUES4,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0_VALUES4_LEN>(l_odt_wr[1][0]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0_VALUES5,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0_VALUES5_LEN>(l_odt_wr[1][1]);
        FAPI_DBG("odt_wr_config2: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_WR_CONFIG3_P0
        // 48:55, ATTR_VPD_ODT_WR[0][1][2]; # when Read of Rank6
        // 56:63, ATTR_VPD_ODT_WR[0][1][3]; # when Read of Rank7
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0_VALUES6,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0_VALUES6_LEN>(l_odt_wr[1][2]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0_VALUES7,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0_VALUES7_LEN>(l_odt_wr[1][3]);
        FAPI_DBG("odt_wr_config3: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}





///
/// @brief Setup seq_rd_wr_data
/// @tparam T, the target type of the MCA/MBA
/// @param[in] the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode reset_seq_rd_wr_data( const fapi2::Target<T>& i_target );

///
/// @brief Setup seq_rd_wr_data
/// @param[in] the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
inline fapi2::ReturnCode reset_seq_rd_wr_data( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // MPR_PATTERN_BIT of 0F0F0F0F pattern
    static const uint64_t MPR_PATTERN = 0x5555;
    fapi2::buffer<uint64_t> l_data;

    l_data.insertFromRight<MCA_DDRPHY_SEQ_RD_WR_DATA0_P0_DATA_REG0,
                           MCA_DDRPHY_SEQ_RD_WR_DATA0_P0_DATA_REG0_LEN>(MPR_PATTERN);

    FAPI_DBG("seq_rd_wr 0x%llx", l_data);
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_RD_WR_DATA0_P0, l_data) );
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_RD_WR_DATA1_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}






///
/// @brief Setup the PC CONFIG0 register
/// @tparam T the fapi2::TargetType
/// @param[in] the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T>
fapi2::ReturnCode set_pc_config0(const fapi2::Target<T>& i_target);

///
/// @brief Setup the PC CONFIG1 register
/// @tparam T the fapi2::TargetType
/// @param[in] the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T>
fapi2::ReturnCode set_pc_config1(const fapi2::Target<T>& i_target);

///
/// @brief Return the DIMM target for the primary rank in the specificed rank pair
/// @tparam T, fapi2::TargetType of the port target
/// @param[in] the arget
/// @param[in] the rank pair
/// @param[out] fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @return FAPI2_RC_SUCCESS iff ok
///
template<fapi2::TargetType T>
fapi2::ReturnCode rank_pair_primary_to_dimm(const fapi2::Target<T>& i_target, const uint64_t i_rp,
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& o_dimm);

}
#endif
