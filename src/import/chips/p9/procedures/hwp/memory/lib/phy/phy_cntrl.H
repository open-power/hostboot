/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/phy_cntrl.H $          */
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
/// @file phy_cntrl.H
/// @brief Subroutines for the PHY phy control registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_PHY_CNTRL_H_
#define _MSS_PHY_CNTRL_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>

namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class pcTraits
/// @brief a collection of traits associated with the PHY phy control
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class pcTraits;

///
/// @class pcTraits
/// @brief a collection of traits associated with the Centaur PHY
///
template<>
class pcTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class pcTraits
/// @brief a collection of traits associated with the Nimbus PHY phy control
///
template<>
class pcTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        // MCA phy control registers
        static const uint64_t PC_ERROR_STATUS0_REG = MCA_DDRPHY_PC_ERROR_STATUS0_P0;
        static const uint64_t PC_INIT_CAL_ERROR_REG = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0;

        enum
        {
            INIT_CAL_ERROR_WR_LEVEL = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_WR_LEVEL,
            INIT_CAL_ERROR_INITIAL_PAT_WRITE = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_INITIAL_PAT_WRITE,
            INIT_CAL_ERROR_DQS_ALIGN = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_DQS_ALIGN,
            INIT_CAL_ERROR_RDCLK_ALIGN = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RDCLK_ALIGN,
            INIT_CAL_ERROR_READ_CTR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_READ_CTR,
            INIT_CAL_ERROR_WRITE_CTR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_WRITE_CTR,
            INIT_CAL_ERROR_INITIAL_COARSE_WR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_INITIAL_COARSE_WR,
            INIT_CAL_ERROR_COARSE_RD = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_COARSE_RD,
            INIT_CAL_ERROR_CUSTOM_RD = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_CUSTOM_RD,
            INIT_CAL_ERROR_CUSTOM_WR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_CUSTOM_WR,
            INIT_CAL_ERROR_DIGITAL_EYE = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_DIGITAL_EYE,
            INIT_CAL_ERROR_VREF = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_VREF,
            INIT_CAL_ERROR_RANK_PAIR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RANK_PAIR,
            INIT_CAL_ERROR_RANK_PAIR_LEN = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RANK_PAIR_LEN,
        };

};

///
/// @class mss::pc
/// @brief Phy Control Class
/// @tparam T fapi2 Target Type
/// @tparam TT traits type defaults to pcTraits<T>
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
class pc
{
    public:

        ///
        /// @brief read PC_ERROR_STATUS0
        /// @param[in] i_target the fapi2 target of the port
        /// @param[out] o_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode read_error_status0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::PC_ERROR_STATUS0_REG, o_data) );
            FAPI_DBG("pc_error_status0: 0x%016llx", o_data);
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write PC_ERROR_STATUS0
        /// @param[in] i_target the fapi2 target of the port
        /// @param[in] i_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode write_error_status0( const fapi2::Target<T>& i_target,
                const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("pc_error_status0: 0x%016llx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::PC_ERROR_STATUS0_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief reset pc_error_status0
        /// @param[in] i_target fapi2 target of the port
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode reset_error_status0( const fapi2::Target<T>& i_target )
        {
            FAPI_TRY( write_error_status0(i_target, 0) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief read PC_INIT_CAL_ERROR
        /// @param[in] i_target the fapi2 target of the port
        /// @param[out] o_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode read_init_cal_error( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::PC_INIT_CAL_ERROR_REG, o_data) );
            FAPI_DBG("pc_init_cal_error: 0x%016llx", o_data);
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write PC_INIT_CAL_ERROR
        /// @param[in] i_target the fapi2 target of the port
        /// @param[in] i_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode write_init_cal_error( const fapi2::Target<T>& i_target,
                const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("pc_init_cal_error: 0x%016llx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::PC_INIT_CAL_ERROR_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief reset pc_init_cal_error
        /// @param[in] i_target fapi2 target of the port
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode reset_init_cal_error( const fapi2::Target<T>& i_target )
        {
            FAPI_TRY( write_init_cal_error(i_target, 0) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief reset rc
        /// @param[in] i_target fapi2 target of the port
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode reset( const fapi2::Target<T>& i_target )
        {
            FAPI_TRY( reset_error_status0(i_target) );

        fapi_try_exit:
            return fapi2::current_err;
        }

};

}

#endif
