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
/// @param[in] i_target the MCBIST which has the PHYs to initialize
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode phy_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target);

///
/// @brief change resetn to the given state
/// @param[in] i_target the mcbist
/// @param[in] i_state the desired state
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_resetn( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target, states i_state );

///
/// @brief perform the zctl toggle process
/// @param[in] i_target the mcbist for the reset recover
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode toggle_zctl( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

/// @brief Change mclk low
/// @param[in] i_target mcbist target
/// @param[in] i_state mss::HIGH or mss::LOW - desired state.
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_force_mclk_low (const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const mss::states i_state);
///
/// @brief Unset the PLL and check to see that the PLL's have started
/// @param[in] i_target the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode deassert_pll_reset( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Setup the phase rotator control registers
/// @param[in] i_target the mcbist target
/// @param[in] i_data the value for the registers
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode setup_phase_rotator_control_registers( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const fapi2::buffer<uint64_t>& i_data );

///
/// @brief Deassetr the sys clk reset
/// @param[in] i_target the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode deassert_sysclk_reset( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Flush the DDR PHY
/// @param[in] i_target the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode ddr_phy_flush( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Reset the training delay configureation
/// @param[in] i_target the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_delay_values( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Lock dphy_gckn and sysclk
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode bang_bang_lock( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Configure the DP16 sysclk
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode setup_dp16_sysclk( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief check and process initial cal errors
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode process_initial_cal_errors( const fapi2::Target<T>& i_target );

///
/// @brief Setup all the cal config register
/// @tparam T, the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal setup
/// @param[in] i_rank_pairs the vector of currently configured rank pairs
/// @param[in] i_cal_steps_enabled fapi2::buffer<uint16_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode setup_cal_config( const fapi2::Target<T>& i_target,
                                    const std::vector<uint64_t> i_rank_pairs,
                                    const fapi2::buffer<uint16_t> i_cal_steps_enabled);

///
/// @brief Setup all the cal config register
/// @param[in] i_target the target associated with this cal setup
/// @param[in] i_rank one currently configured rank pairs
/// @param[in] i_cal_steps_enabled fapi2::buffer<uint16_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode setup_cal_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rank,
                                    const fapi2::buffer<uint16_t> i_cal_steps_enabled);


///
/// @brief Setup seq_config0
/// @tparam T the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_seq_config0( const fapi2::Target<T>& i_target );

///
/// @brief Setup seq_config0
/// @param[in] i_target the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode reset_seq_config0( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );


///
/// @brief Setup odt_wr/rd_config
/// @tparam T the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_odt_config( const fapi2::Target<T>& i_target );

///
/// @brief Setup odt_wr/rd_config
/// @param[in] i_target the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode reset_odt_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Setup seq_rd_wr_data
/// @tparam T the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_seq_rd_wr_data( const fapi2::Target<T>& i_target );

///
/// @brief Setup seq_rd_wr_data
/// @param[in] i_target the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode reset_seq_rd_wr_data( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Setup the PC CONFIG0 register
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T>
fapi2::ReturnCode set_pc_config0(const fapi2::Target<T>& i_target);

///
/// @brief Setup the PC CONFIG1 register
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T>
fapi2::ReturnCode set_pc_config1(const fapi2::Target<T>& i_target);

///
/// @brief Return the DIMM target for the primary rank in the specificed rank pair
/// @tparam T fapi2::TargetType of the port target
/// @param[in] i_target the target
/// @param[in] i_rp the rank pair
/// @param[out] fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @return FAPI2_RC_SUCCESS iff ok
///
template<fapi2::TargetType T>
fapi2::ReturnCode rank_pair_primary_to_dimm(const fapi2::Target<T>& i_target, const uint64_t i_rp,
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& o_dimm);

}
#endif
