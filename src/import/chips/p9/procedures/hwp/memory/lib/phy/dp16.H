/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/dp16.H $               */
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
/// @file dp16.H
/// @brief Subroutines to control the DP16 logic blocks
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_DP16_H_
#define _MSS_DP16_H_

#include <vector>
#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>


namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class dp16Traits
/// @brief a collection of traits associated with the PHY DP16 block
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class dp16Traits;

///
/// @class dp16Traits
/// @brief a collection of traits associated with the Centaur PHY
///
template<>
class dp16Traits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class dp16Traits
/// @brief a collection of traits associated with the Nimbus PHY DP16 block
///
template<>
class dp16Traits<fapi2::TARGET_TYPE_MCA>
{
};

///
/// @class mss::dp16
/// @brief PHY DP16 Block class
/// @tparam T fapi2 Target Type
/// @tparam TT traits type defaults to dp16Traits<T>
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
class dp16
{
    public:

        ///
        /// @brief Configure the DP16 sysclk
        /// @tparam K the fapi2 target type
        /// @param[in] i_target a target
        /// @return FAPI2_RC_SUCCESs iff ok
        ///
        template< fapi2::TargetType K >
        fapi2::ReturnCode setup_sysclk( const fapi2::Target<K>& i_target );

        ///
        /// @brief Reset the training delay configureation
        /// @tparam T the type of the port
        /// @param[in] i_target the port target
        /// @param[in] l_rank_pairs vector of rank pairs
        /// @return FAPI2_RC_SUCCES iff ok
        ///
        fapi2::ReturnCode reset_delay_values( const fapi2::Target<T>& i_target,
                                              const std::vector< uint64_t >& l_rank_pairs );

        ///
        /// @brief Write the read clock enable registers
        /// @tparam T the type of the port
        /// @param[in] i_target a port target
        /// @param[in] l_rank_pairs vector of rank pairs
        /// @return FAPI2_RC_SUCCES iff ok
        ///
        fapi2::ReturnCode read_clock_enable( const fapi2::Target<T>& i_target,
                                             const std::vector< uint64_t >& l_rank_pairs );

        ///
        /// @brief Write the clock enable registers
        /// @tparam T the type of the port
        /// @param[in] i_target  a port target
        /// @param[in] l_rank_pairs vector of rank pairs
        /// @return FAPI2_RC_SUCCES iff ok
        ///
        fapi2::ReturnCode write_clock_enable( const fapi2::Target<T>& i_target,
                                              const std::vector< uint64_t >& l_rank_pairs );

        ///
        /// @brief Write the data bit enable registers
        /// @tparam T the type of the port
        /// @param[in] i_target a port target
        /// @return FAPI2_RC_SUCCESs iff ok
        ///
        fapi2::ReturnCode write_data_bit_enable( const fapi2::Target<T>& i_target );


        ///
        /// @brief Setup the bad-bits masks for a port
        /// @tparam T the fapi2::TargetType
        /// @param[in] i_target the target (MCA or MBA?)
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        inline fapi2::ReturnCode set_bad_bits(const fapi2::Target<T>& i_target);

};

///
/// @brief Configure the DP16 sysclk
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
template<>
template<>
fapi2::ReturnCode dp16<fapi2::TARGET_TYPE_MCA>::setup_sysclk(
    const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Reset the training delay configureation
/// @param[in] i_target the port target
/// @param[in]  l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
template<>
fapi2::ReturnCode dp16<fapi2::TARGET_TYPE_MCA>::reset_delay_values(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    const std::vector< uint64_t >& l_rank_pairs );

///
/// @brief Write the clock enable registers
/// @param[in] i_target a port target
/// @param[in] l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
template<>
fapi2::ReturnCode dp16<fapi2::TARGET_TYPE_MCA>::read_clock_enable(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    const std::vector< uint64_t >& l_rank_pairs );

///
/// @brief Write the clock enable registers
/// @param[in] i_target a port target
/// @param[in] l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
template<>
fapi2::ReturnCode dp16<fapi2::TARGET_TYPE_MCA>::write_clock_enable(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    const std::vector< uint64_t >& l_rank_pairs );

///
/// @brief Write the data bit enable registers
/// @param[in] i_target a port target
/// @return FAPI2_RC_SUCCESs iff ok
///
template<>
fapi2::ReturnCode dp16<fapi2::TARGET_TYPE_MCA>::write_data_bit_enable(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Setup the bad-bits masks for a port
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
inline fapi2::ReturnCode dp16<fapi2::TARGET_TYPE_MCA>::set_bad_bits(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    // Note: We need to do this ... BRS
    return fapi2::FAPI2_RC_SUCCESS;
}


}

#endif
