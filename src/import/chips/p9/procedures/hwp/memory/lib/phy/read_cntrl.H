/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/read_cntrl.H $         */
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
/// @file read_cntrl
/// @brief Subroutines for the PHY read control registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_READ_CNTRL_H_
#define _MSS_READ_CNTRL_H_

#include <fapi2.H>
#include "p9_mc_scom_addresses.H"

namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class rcTraits
/// @brief a collection of traits associated with the PHY read control
/// @tparam T, fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class rcTraits;

///
/// @class rcTraits<fapi2::TARGET_TYPE_MBA>
/// @brief a collection of traits associated with the Centaur PHY
///
template<>
class rcTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class rcTraits<fapi2::TARGET_TYPE_MCA>
/// @brief a collection of traits associated with the Nimbus PHY read control
///
template<>
class rcTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        // MCA read control registers
        static const uint64_t RC_CONFIG0_REG = MCA_DDRPHY_RC_CONFIG0_P0;
        static const uint64_t RC_CONFIG1_REG = MCA_DDRPHY_RC_CONFIG1_P0;
        static const uint64_t RC_CONFIG2_REG = MCA_DDRPHY_RC_CONFIG2_P0;
        static const uint64_t RC_CONFIG3_REG = MCA_DDRPHY_RC_CONFIG3_P0;

        static const uint64_t RC_VREF_CONFIG0_REG = MCA_DDRPHY_RC_RDVREF_CONFIG0_P0;
        static const uint64_t RC_VREF_CONFIG1_REG = MCA_DDRPHY_RC_RDVREF_CONFIG1_P0;

        static const uint64_t RC_ERROR_MASK0_REG = MCA_DDRPHY_RC_ERROR_MASK0_P0;
        static const uint64_t RC_ERROR_STATUS0_REG = MCA_DDRPHY_RC_ERROR_STATUS0_P0;

        enum
        {
            GLOBAL_PHY_OFFSET = MCA_DDRPHY_RC_CONFIG0_P0_GLOBAL_PHY_OFFSET,
            GLOBAL_PHY_OFFSET_LEN = MCA_DDRPHY_RC_CONFIG0_P0_GLOBAL_PHY_OFFSET_LEN,
            ADVANCE_RD_VALID = MCA_DDRPHY_RC_CONFIG0_P0_ADVANCE_RD_VALID,
            PER_DUTY_CYCLE_SW = MCA_DDRPHY_RC_CONFIG0_P0_PER_DUTY_CYCLE_SW,
            PER_REPEAT_COUNT = MCA_DDRPHY_RC_CONFIG0_P0_PER_REPEAT_COUNT,
            PER_REPEAT_COUNT_LEN = MCA_DDRPHY_RC_CONFIG0_P0_PER_REPEAT_COUNT_LEN,
            SINGLE_BIT_MPR_RP0 = MCA_DDRPHY_RC_CONFIG0_P0_SINGLE_BIT_MPR_RP0,
            SINGLE_BIT_MPR_RP1 = MCA_DDRPHY_RC_CONFIG0_P0_SINGLE_BIT_MPR_RP1,
            SINGLE_BIT_MPR_RP2 = MCA_DDRPHY_RC_CONFIG0_P0_SINGLE_BIT_MPR_RP2,
            SINGLE_BIT_MPR_RP3 = MCA_DDRPHY_RC_CONFIG0_P0_SINGLE_BIT_MPR_RP3,
            ALIGN_ON_EVEN_CYCLES = MCA_DDRPHY_RC_CONFIG0_P0_ALIGN_ON_EVEN_CYCLES,
            PERFORM_RDCLK_ALIGN = MCA_DDRPHY_RC_CONFIG0_P0_PERFORM_RDCLK_ALIGN,
            STAGGERED_PATTERN = MCA_DDRPHY_RC_CONFIG0_P0_STAGGERED_PATTERN,
            OUTER_LOOP_CNT = MCA_DDRPHY_RC_CONFIG1_P0_OUTER_LOOP_CNT,
            OUTER_LOOP_CNT_LEN = MCA_DDRPHY_RC_CONFIG1_P0_OUTER_LOOP_CNT_LEN,
            CONSEQ_PASS = MCA_DDRPHY_RC_CONFIG2_P0_CONSEQ_PASS,
            CONSEQ_PASS_LEN = MCA_DDRPHY_RC_CONFIG2_P0_CONSEQ_PASS_LEN,
            BURST_WINDOW = MCA_DDRPHY_RC_CONFIG2_P0_BURST_WINDOW,
            BURST_WINDOW_LEN = MCA_DDRPHY_RC_CONFIG2_P0_BURST_WINDOW_LEN,
            ALLOW_RD_FIFO_AUTO_RESET = MCA_DDRPHY_RC_CONFIG2_P0_ALLOW_RD_FIFO_AUTO_RESET,
            FINE_CAL_STEP_SIZE = MCA_DDRPHY_RC_CONFIG3_P0_FINE_CAL_STEP_SIZE,
            FINE_CAL_STEP_SIZE_LEN = MCA_DDRPHY_RC_CONFIG3_P0_FINE_CAL_STEP_SIZE_LEN,
            COARSE_CAL_STEP_SIZE = MCA_DDRPHY_RC_CONFIG3_P0_COARSE_CAL_STEP_SIZE,
            COARSE_CAL_STEP_SIZE_LEN = MCA_DDRPHY_RC_CONFIG3_P0_COARSE_CAL_STEP_SIZE_LEN,
            DQ_SEL_QUAD = MCA_DDRPHY_RC_CONFIG3_P0_DQ_SEL_QUAD,
            DQ_SEL_QUAD_LEN = MCA_DDRPHY_RC_CONFIG3_P0_DQ_SEL_QUAD_LEN,
            DQ_SEL_LANE = MCA_DDRPHY_RC_CONFIG3_P0_DQ_SEL_LANE,
            DQ_SEL_LANE_LEN = MCA_DDRPHY_RC_CONFIG3_P0_DQ_SEL_LANE_LEN,
            RD_CNTL_MASK = MCA_DDRPHY_RC_ERROR_MASK0_P0_RD_CNTL_MASK,
            RD_CNTL = MCA_DDRPHY_RC_ERROR_STATUS0_P0_RD_CNTL,
            GUESS_WAIT_TIME = MCA_DDRPHY_RC_RDVREF_CONFIG0_P0_GUESS_WAIT_TIME,
            GUESS_WAIT_TIME_LEN = MCA_DDRPHY_RC_RDVREF_CONFIG0_P0_GUESS_WAIT_TIME_LEN,
            CMD_PRECEDE_TIME = MCA_DDRPHY_RC_RDVREF_CONFIG1_P0_CMD_PRECEDE_TIME,
            CMD_PRECEDE_TIME_LEN = MCA_DDRPHY_RC_RDVREF_CONFIG1_P0_CMD_PRECEDE_TIME_LEN,
            MPR_PAGE = MCA_DDRPHY_RC_RDVREF_CONFIG1_P0_MPR_PAGE,
            MPR_PAGE_LEN = MCA_DDRPHY_RC_RDVREF_CONFIG1_P0_MPR_PAGE_LEN,
            CALIBRATION_ENABLE = MCA_DDRPHY_RC_RDVREF_CONFIG1_P0_CALIBRATION_ENABLE,
            SKIP_RDCENTERING = MCA_DDRPHY_RC_RDVREF_CONFIG1_P0_SKIP_RDCENTERING,
        };

};

///
/// @class mss::rc
/// @brief Read Control reset config 0
/// @tparam T, fapi2 Target Type - derived
/// @tparam TT, traits type defaults to rcTraits<T>
///
template< fapi2::TargetType T, typename TT = rcTraits<T> >
class rc
{
    public:

        ///
        /// @brief Read RC_VREF_CONFIG0
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[out] o_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode read_vref_config0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::RC_VREF_CONFIG0_REG, o_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write RC_VREF_CONFIG0
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[in] i_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode write_vref_config0( const fapi2::Target<T>& i_target,
                const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("rc_vref_config0: 0x%016llx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::RC_VREF_CONFIG0_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Read RC_VREF_CONFIG1
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[out] o_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode read_vref_config1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::RC_VREF_CONFIG1_REG, o_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write RC_VREF_CONFIG1
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[in] i_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode write_vref_config1( const fapi2::Target<T>& i_target,
                const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("rc_vref_config1: 0x%016llx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::RC_VREF_CONFIG1_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Read RC_CONFIG0
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[out] o_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode read_config0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::RC_CONFIG0_REG, o_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write RC_CONFIG0
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[in] i_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode write_config0( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("rc_config0: 0x%016llx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::RC_CONFIG0_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Read RC_CONFIG1
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[out] o_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode read_config1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::RC_CONFIG1_REG, o_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write RC_CONFIG1
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[in] i_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode write_config1( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("rc_config1: 0x%016llx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::RC_CONFIG1_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Read RC_CONFIG2
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[out] o_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode read_config2( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::RC_CONFIG2_REG, o_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write RC_CONFIG2
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[in] i_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode write_config2( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("rc_config2: 0x%016llx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::RC_CONFIG2_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Read RC_CONFIG3
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[out] o_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode read_config3( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
        {
            FAPI_TRY( mss::getScom(i_target, TT::RC_CONFIG3_REG, o_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Write RC_CONFIG3
        /// @param[in] i_target, the fapi2 target of the port
        /// @param[in] i_data, the value of the register
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode write_config3( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
        {
            FAPI_DBG("rc_config3: 0x%016llx", i_data);
            FAPI_TRY( mss::putScom(i_target, TT::RC_CONFIG3_REG, i_data) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief reset rc_config0
        /// @param[in] i_target, fapi2 target of the port
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode reset_config0( const fapi2::Target<T>& i_target )
        {
            fapi2::buffer<uint64_t> l_data;
            uint8_t l_gpo = 0;

            FAPI_TRY( mss::vpd_gpo(i_target, l_gpo) );

            // 48:51, (ATTR_VPD_GPO[0]), any; # GLOBAL_PHY_OFFSET (GPO), based on attribute now
            l_data.insertFromRight<TT::GLOBAL_PHY_OFFSET, TT::GLOBAL_PHY_OFFSET_LEN>(l_gpo);

            l_data.setBit<TT::PERFORM_RDCLK_ALIGN>();

            FAPI_TRY( write_config0(i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief reset rc_config1
        /// @param[in] i_target, fapi2 target of the port
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode reset_config1( const fapi2::Target<T>& i_target )
        {
            fapi2::buffer<uint64_t> l_data;

            // Centaur was all 0's ...
            FAPI_TRY( write_config1(i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief reset rc_config2
        /// @param[in] i_target, fapi2 target of the port
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode reset_config2( const fapi2::Target<T>& i_target )
        {
            fapi2::buffer<uint64_t> l_data;
            uint8_t is_sim = 0;
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim) );

            // 48:52, 0b00000, (def_is_sim); # CONSEQ_PASS  sim value
            // 48:52, 0b01000, (def_is_bl8); # CONSEQ_PASS  8 from SWyatt
            // 48:52, 0b01111, any;          # CONSEQ_PASS»  16 min for BL4, or OTF
            if (is_sim)
            {
                l_data.insertFromRight<TT::CONSEQ_PASS, TT::CONSEQ_PASS_LEN>(0b00000);
            }
            else
            {
                uint8_t l_bl = 0;

                FAPI_TRY( mss::eff_dram_burst_length(i_target, l_bl) );
                l_data.insertFromRight<TT::CONSEQ_PASS, TT::CONSEQ_PASS_LEN>(
                    l_bl == fapi2::ENUM_ATTR_EFF_DRAM_BL_BL8 ? 0b01000 : 0b01111);
            }

            // 57:58, 0b11, any;  # BURST_WINDOW, compare all 8 beats (AS recommended)
            l_data.insertFromRight<TT::BURST_WINDOW, TT::BURST_WINDOW_LEN>(0b11);

            FAPI_TRY( write_config2(i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief reset rc_config3
        /// @param[in] i_target, fapi2 target of the port
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode reset_config3( const fapi2::Target<T>& i_target )
        {
            fapi2::buffer<uint64_t> l_data;
            uint8_t is_sim = 0;
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim) );

            // 51:54, 0b1010, (def_is_sim); # COARSE_CAL_STEP_SIZE» # old=4=5/128 (5/18)
            // 51:54, 0b0000, any; # COARSE_CAL_STEP_SIZE = 1/128
            l_data.insertFromRight<TT::COARSE_CAL_STEP_SIZE, TT::COARSE_CAL_STEP_SIZE_LEN>(is_sim ? 0b1010 : 0b0000);

            FAPI_TRY( write_config3(i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief reset rc_vref_config0
        /// @param[in] i_target, fapi2 target of the port
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode reset_vref_config0( const fapi2::Target<T>& i_target )
        {
            fapi2::buffer<uint64_t> l_data;
            uint16_t l_guess_time = 0;

            // This 16 bit integer denotes the number of memory clock cycles to wait for the analog
            // D/A converter to settle to a value. The digital value in the D/A converter can
            // change every 500 KHz, so the frequency of dphy_gckn divided by the number in
            // this register must be less than 500 KHz. Due to changing state machine states
            // happening during this period, it is recommended to ensure the value used slightly
            // exceeds the 500 KHz threshold.
            // For example, a 1333 MHz clock must have value be slight more than 1333 MHz /
            // 500 KHz = 2,666, rounded up to a final value of 2700.
            //
            // So this means we just add a smidge to MSS_FREQ, right? Round up to the nearest '00
            // and jump 100 if we're divisible by 100 (e.g., 2400. This should yield 2500.)
            uint64_t l_freq;
            FAPI_TRY( mss::freq(i_target.template getParent<fapi2::TARGET_TYPE_MCBIST>(), l_freq) );

            l_guess_time = (l_freq + 100) / 100 * 100;
            FAPI_INF("VREF guess wait time: %u (freq: %lu)", l_guess_time, l_freq);

            l_data.insertFromRight<TT::GUESS_WAIT_TIME, TT::GUESS_WAIT_TIME_LEN>((l_freq + 100) / 100 * 100);

            FAPI_TRY( write_vref_config0(i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief reset rc_vref_config1
        /// @param[in] i_target, fapi2 target of the port
        /// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
        ///
        static inline fapi2::ReturnCode reset_vref_config1( const fapi2::Target<T>& i_target )
        {
            fapi2::buffer<uint64_t> l_data;

            // TK: WAG at CMD_PRECEDE_TIME
            l_data.insertFromRight<TT::CMD_PRECEDE_TIME, TT::CMD_PRECEDE_TIME_LEN>(0 + 4 + 2);
            l_data.insertFromRight<TT::MPR_PAGE, TT::MPR_PAGE_LEN>(0); // TK: <shrug>

            // Note: when initial cal is setup, this register will change to accomodate the
            // initial cal read centering and read vref centering cal steps.

            FAPI_TRY( write_vref_config1(i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }

};

}

#endif
