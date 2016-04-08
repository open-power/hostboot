/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/apb.H $                */
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
/// @file apb.H
/// @brief Subroutines for the PHY APB registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_APB_H_
#define _MSS_APB_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/utils/scom.H>

namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class apbTraits
/// @brief a collection of traits associated with the PHY APB interface
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class apbTraits;

///
/// @class apbTraits
/// @brief a collection of traits associated with the Centaur PHY APB interface
///
template<>
class apbTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class apbTraits
/// @brief a collection of traits associated with the Nimbus PHY APB
///
template<>
class apbTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        // MCA APB control registers - must be 64 bits.
        static const uint64_t APB_CONFIG0_REG = MCA_DDRPHY_APB_CONFIG0_P0;
        static const uint64_t APB_ERROR_STATUS0_REG = MCA_DDRPHY_APB_ERROR_STATUS0_P0;
        static const uint64_t APB_FIR_ERR0_REG = MCA_DDRPHY_APB_FIR_ERR0_P0;
        static const uint64_t APB_FIR_ERR1_REG = MCA_DDRPHY_APB_FIR_ERR1_P0;
        static const uint64_t APB_FIR_ERR2_REG = MCA_DDRPHY_APB_FIR_ERR2_P0;
        static const uint64_t APB_FIR_ERR3_REG = MCA_DDRPHY_APB_FIR_ERR3_P0;

        // Fields, can be any size.
        enum
        {
            RESET_ERR_RPT = MCA_DDRPHY_APB_CONFIG0_P0_RESET_ERR_RPT,

            INVALID_ADDRESS = MCA_DDRPHY_APB_ERROR_STATUS0_P0_INVALID_ADDRESS,
            WRITE_PARITY_ERR = MCA_DDRPHY_APB_ERROR_STATUS0_P0_WR_PAR_ERR,

            FATAL_FSM = MCA_DDRPHY_APB_FIR_ERR0_P0_ERR_SET0,
            FATAL_PARITY = MCA_DDRPHY_APB_FIR_ERR0_P0_ERR_SET1,
            FSM = MCA_DDRPHY_APB_FIR_ERR0_P0_ERR_SET2,
            PARITY = MCA_DDRPHY_APB_FIR_ERR0_P0_ERR_SET3,
            FATAL_ADR52_MASTER = MCA_DDRPHY_APB_FIR_ERR0_P0_ERR_SET4,
            FATAL_ADR52_SLAVE = MCA_DDRPHY_APB_FIR_ERR0_P0_ERR_SET5,
            FSM_DP16 = MCA_DDRPHY_APB_FIR_ERR0_P0_ERR_FSM_DP16,
            FSM_DP16_LEN = MCA_DDRPHY_APB_FIR_ERR0_P0_ERR_FSM_DP16_LEN,

        };

};

///
/// @class mss::apb
/// @brief APB class
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to apbTraits<T>
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = apbTraits<T> >
class apb
{
    public:

        ///
        /// @brief Read APB_CONFIG0
        /// @param[in] i_target the fapi2 target of the port
        /// @param[out] o_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode read_config0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::APB_CONFIG0_REG, o_data) );
            FAPI_DBG("apb_config0: 0x%016lx", o_data);
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write APB_CONFIG0
        /// @param[in] i_target the fapi2 target of the port
        /// @param[in] i_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode write_config0( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("apb_config0: 0x%016lx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::APB_CONFIG0_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Read APB_ERROR_STATUS0
        /// @param[in] i_target the fapi2 target of the port
        /// @param[out] o_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode read_error_status0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::APB_ERROR_STATUS0_REG, o_data) );
            FAPI_DBG("apb_error_status0: 0x%016lx", o_data);
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write APB_ERROR_STATUS0
        /// @param[in] i_target the fapi2 target of the port
        /// @param[in] i_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode write_error_status0( const fapi2::Target<T>& i_target,
                const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("apb_error_status0: 0x%016lx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::APB_ERROR_STATUS0_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Read APB_FIR_ERR0_REG
        /// @param[in] i_target the fapi2 target of the port
        /// @param[out] o_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode read_fir_err0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::APB_FIR_ERR0_REG, o_data) );
            FAPI_DBG("apb_fir_err0: 0x%016lx", o_data);
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Read APB_FIR_ERR1_REG
        /// @param[in] i_target the fapi2 target of the port
        /// @param[out] o_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode read_fir_err1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::APB_FIR_ERR1_REG, o_data) );
            FAPI_DBG("apb_fir_err1: 0x%016lx", o_data);
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Read APB_FIR_ERR2_REG
        /// @param[in] i_target the fapi2 target of the port
        /// @param[out] o_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode read_fir_err2( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::APB_FIR_ERR2_REG, o_data) );
            FAPI_DBG("apb_fir_err2: 0x%016lx", o_data);
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Read APB_FIR_ERR3_REG
        /// @param[in] i_target the fapi2 target of the port
        /// @param[out] o_data the value of the register
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode read_fir_err3( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::APB_FIR_ERR3_REG, o_data) );
            FAPI_DBG("apb_fir_err3: 0x%016lx", o_data);
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Reset the error state of the APB block
        /// @param[in] i_target the fapi2 target of the port
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode reset_err( const fapi2::Target<T>& i_target )
        {
            // DDRPHY_APB_CONFIG0_P0_RESET_ERR_RPT
            // Write this bit to '1'b then write this bit to '0'b (toggle) to reset the
            // APB error registers.
            // Does this cover all of them? BRS
            fapi2::buffer<uint64_t> l_data;
            FAPI_TRY( read_config0(i_target, l_data) );
            l_data.setBit<TT::RESET_ERR_RPT>();
            FAPI_TRY( write_config0(i_target, l_data) );
            l_data.clearBit<TT::RESET_ERR_RPT>();
            FAPI_TRY( write_config0(i_target, l_data) );

            // We have to read ERR_STATUS0. It resets when read.
            FAPI_TRY( read_error_status0(i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief reset apb_config0
        /// @param[in] i_target fapi2 target of the port
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
        ///
        inline fapi2::ReturnCode reset_config0( const fapi2::Target<T>& i_target )
        {
            FAPI_TRY( reset_err(i_target) );

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
            FAPI_TRY( reset_config0(i_target) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief APB block FIR check
        /// @param[in] i_target fapi2 target of the port
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if no FIR
        ///
        fapi2::ReturnCode fir_check( const fapi2::Target<T>& i_target );

};

}

#endif
