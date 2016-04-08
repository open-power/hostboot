/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/write_cntrl.H $        */
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
/// @file write_cntrl.H
/// @brief Subroutines for the PHY write control registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WRITE_CNTRL_H_
#define _MSS_WRITE_CNTRL_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>

namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class wcTraits
/// @brief a collection of traits associated with the PHY write control
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class wcTraits;

///
/// @class wcTraits<fapi2::TARGET_TYPE_MBA>
/// @brief a collection of traits associated with the Centaur PHY
///
template<>
class wcTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class wcTraits<fapi2::TARGET_TYPE_MCA>
/// @brief a collection of traits associated with the Nimbus PHY write control
///
template<>
class wcTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        // MCA write control registers
        constexpr static uint64_t WC_CONFIG0_REG = MCA_DDRPHY_WC_CONFIG0_P0;
        constexpr static uint64_t WC_CONFIG1_REG = MCA_DDRPHY_WC_CONFIG1_P0;
        constexpr static uint64_t WC_CONFIG2_REG = MCA_DDRPHY_WC_CONFIG2_P0;
        constexpr static uint64_t WC_CONFIG3_REG = MCA_DDRPHY_WC_CONFIG3_P0;
        constexpr static uint64_t WC_RTT_WR_SWAP_ENABLE_REG = MCA_DDRPHY_WC_RTT_WR_SWAP_ENABLE_P0;

        constexpr static uint64_t WC_ERROR_MASK0_REG = MCA_DDRPHY_WC_ERROR_MASK0_P0;
        constexpr static uint64_t WC_ERROR_STATUS0_REG = MCA_DDRPHY_WC_ERROR_STATUS0_P0;


        // All the fields
        enum
        {
            TWLO_TWLOE = MCA_DDRPHY_WC_CONFIG0_P0_TWLO_TWLOE,
            TWLO_TWLOE_LEN = MCA_DDRPHY_WC_CONFIG0_P0_TWLO_TWLOE_LEN,
            WL_ONE_DQS_PULSE = MCA_DDRPHY_WC_CONFIG0_P0_WL_ONE_DQS_PULSE,
            FW_WR_RD = MCA_DDRPHY_WC_CONFIG0_P0_FW_WR_RD,
            FW_WR_RD_LEN = MCA_DDRPHY_WC_CONFIG0_P0_FW_WR_RD_LEN,
            CUSTOM_INIT_WRITE = MCA_DDRPHY_WC_CONFIG0_P0_CUSTOM_INIT_WRITE,

            BIG_STEP = MCA_DDRPHY_WC_CONFIG1_P0_BIG_STEP,
            BIG_STEP_LEN = MCA_DDRPHY_WC_CONFIG1_P0_BIG_STEP_LEN,
            SMALL_STEP = MCA_DDRPHY_WC_CONFIG1_P0_SMALL_STEP,
            SMALL_STEP_LEN = MCA_DDRPHY_WC_CONFIG1_P0_SMALL_STEP_LEN,
            WR_PRE_DLY = MCA_DDRPHY_WC_CONFIG1_P0_WR_PRE_DLY,
            WR_PRE_DLY_LEN = MCA_DDRPHY_WC_CONFIG1_P0_WR_PRE_DLY_LEN,

            NUM_VALID_SAMPLES = MCA_DDRPHY_WC_CONFIG2_P0_NUM_VALID_SAMPLES,
            NUM_VALID_SAMPLES_LEN = MCA_DDRPHY_WC_CONFIG2_P0_NUM_VALID_SAMPLES_LEN,
            FW_RD_WR = MCA_DDRPHY_WC_CONFIG2_P0_FW_RD_WR,
            FW_RD_WR_LEN = MCA_DDRPHY_WC_CONFIG2_P0_FW_RD_WR_LEN,
            IPW_WR_WR = MCA_DDRPHY_WC_CONFIG2_P0_IPW_WR_WR,
            IPW_WR_WR_LEN = MCA_DDRPHY_WC_CONFIG2_P0_IPW_WR_WR_LEN,
            EN_RESET_DD2_FIX_DIS = MCA_DDRPHY_WC_CONFIG2_P0_EN_RESET_DD2_FIX_DIS,
            EN_RESET_WR_DELAY_WL = MCA_DDRPHY_WC_CONFIG2_P0_EN_RESET_WR_DELAY_WL,

            MRS_CMD_DQ_ON = MCA_DDRPHY_WC_CONFIG3_P0_MRS_CMD_DQ_ON,
            MRS_CMD_DQ_ON_LEN = MCA_DDRPHY_WC_CONFIG3_P0_MRS_CMD_DQ_ON_LEN,
            MRS_CMD_DQ_OFF = MCA_DDRPHY_WC_CONFIG3_P0_MRS_CMD_DQ_OFF,
            MRS_CMD_DQ_OFF_LEN = MCA_DDRPHY_WC_CONFIG3_P0_MRS_CMD_DQ_OFF_LEN,

            ERR_WR_CNTL_MASK = MCA_DDRPHY_WC_ERROR_MASK0_P0_WR_CNTL_MASK,
            ERR_WR_CNTL = MCA_DDRPHY_WC_ERROR_STATUS0_P0_WR_CNTL,

            RTT_WR_SWAP_ENABLE_P0_WL = MCA_DDRPHY_WC_RTT_WR_SWAP_ENABLE_P0_WL,
            RTT_WR_SWAP_ENABLE_P0_CTR = MCA_DDRPHY_WC_RTT_WR_SWAP_ENABLE_P0_CTR,
        };

};

namespace wc
{
///
/// @brief Read WC_CONFIG0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode read_config0( const fapi2::Target<T>& i_target,
                                       fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::WC_CONFIG0_REG, o_data) );
    FAPI_DBG("wc_config0: 0x%016llx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write WC_CONFIG0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode write_config0( const fapi2::Target<T>& i_target,
                                        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("wc_config0: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::WC_CONFIG0_REG, i_data) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Read WC_CONFIG1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode read_config1( const fapi2::Target<T>& i_target,
                                       fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::WC_CONFIG1_REG, o_data) );
    FAPI_DBG("wc_config1: 0x%016llx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write WC_CONFIG1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode write_config1( const fapi2::Target<T>& i_target,
                                        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("wc_config1: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::WC_CONFIG1_REG, i_data) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WC_CONFIG2
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode read_config2( const fapi2::Target<T>& i_target,
                                       fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::WC_CONFIG2_REG, o_data) );
    FAPI_DBG("wc_config2: 0x%016llx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write WC_CONFIG2
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode write_config2( const fapi2::Target<T>& i_target,
                                        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("wc_config2: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::WC_CONFIG2_REG, i_data) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Read WC_CONFIG3
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode read_config3( const fapi2::Target<T>& i_target,
                                       fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::WC_CONFIG3_REG, o_data) );
    FAPI_DBG("wc_config3: 0x%016llx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write WC_CONFIG3
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode write_config3( const fapi2::Target<T>& i_target,
                                        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("wc_config3: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::WC_CONFIG3_REG, i_data) );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Read WC_RTT_WR_SWAP_ENABLE
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode read_rtt_wr_swap_enable( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::WC_RTT_WR_SWAP_ENABLE_REG, o_data) );
    FAPI_DBG("wc_rtt_wr_swap_enable: 0x%016llx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write WC_RTT_WR_SWAP_ENABLE
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode write_rtt_wr_swap_enable( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("wc_rtt_wr_swap_enable: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::WC_RTT_WR_SWAP_ENABLE_REG, i_data) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset wc_config0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode reset_config0( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim) );

    // This is a simplification - in sim we don't have DQS wire delays so we don't acccount for them BRS
    l_data.insertFromRight<TT::TWLO_TWLOE, TT::TWLO_TWLOE_LEN>(mss::twlo_twloe(i_target));

    // WL_ONE_DQS_PULSE = enable (one pulse)
    l_data.setBit<TT::WL_ONE_DQS_PULSE>();

    // FW_WR_RD [same formula as RD_WR? max(tWTR+11,AL+tRTP+3), ATTR_EFF_DRAM_AL(0,1,2)]
    // 57:62, 0b000000, (def_is_sim);   # is this max?
    // 57:62, 0b100000, any;   # dd0 = 17 clocks, now 32 from SWyatt
    {
        const uint64_t FW_WR_RD = l_is_sim ? 0b000000 : 0b100000;
        l_data.insertFromRight<TT::FW_WR_RD, TT::FW_WR_RD_LEN>(FW_WR_RD);
    }

    // 63, 0b0, any;       # CUSTOM_INIT_WRITE
    l_data.clearBit<TT::CUSTOM_INIT_WRITE>();

    FAPI_DBG("wc_config0 reset 0x%llx (tWLO_tWLOE: %d)", l_data, mss::twlo_twloe(i_target));
    FAPI_TRY( write_config0(i_target, l_data) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief reset wc_config1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode reset_config1( const fapi2::Target<T>& i_target )
{
    // Reset WC_CONFIG1 with the values directly from the PHY databook
    fapi2::buffer<uint64_t> l_data;

    l_data.insertFromRight<TT::BIG_STEP, TT::BIG_STEP_LEN>(WR_LVL_BIG_STEP);
    l_data.insertFromRight<TT::SMALL_STEP, TT::SMALL_STEP_LEN>(WR_LVL_SMALL_STEP);
    l_data.insertFromRight<TT::WR_PRE_DLY, TT::WR_PRE_DLY_LEN>(WR_LVL_PRE_DLY);

    FAPI_DBG("wc_config1 reset 0x%llx (big 0x%x small 0x%x wr_pre_dly 0x%x)",
             l_data, WR_LVL_BIG_STEP, WR_LVL_SMALL_STEP, WR_LVL_PRE_DLY);
    FAPI_TRY( write_config1(i_target, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset wc_config2
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode reset_config2( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

    l_data.insertFromRight<TT::NUM_VALID_SAMPLES, TT::NUM_VALID_SAMPLES_LEN>(WR_LVL_NUM_VALID_SAMPLES);
    l_data.insertFromRight<TT::FW_RD_WR, TT::FW_RD_WR_LEN>(WR_CNTR_FW_RD_WR);

    FAPI_DBG("wc_config2 reset 0x%llx", l_data);
    FAPI_TRY( write_config2(i_target, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset wc_config3
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode reset_config3( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim) );

    // MCA_DDRPHY_WC_CONFIG3_P0_MRS_CMD_DQ_ON is 0's

    // 55:60, 0b000000, (def_is_sim); # MRS_CMD_DQ_OFF        !!
    // 55:60, 0b111111, any   ;       # MRS_CMD_DQ_OFF        !!
    {
        const uint64_t CMD_DQ_OFF = l_is_sim ? 0b000000 : 0b111111;
        l_data.insertFromRight<TT::MRS_CMD_DQ_OFF, TT::MRS_CMD_DQ_OFF_LEN>(CMD_DQ_OFF);
    }

    FAPI_DBG("wc_config3 reset 0x%llx", l_data);
    FAPI_TRY( write_config3(i_target, l_data) );

fapi_try_exit:
    return fapi2::current_err;

}


///
/// @brief reset wc_rtt_wr_swap_enable
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode reset_rtt_wr_swap_enable( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( read_rtt_wr_swap_enable(i_target, l_data) );

    // Per John Bialas 1/16: The enable RTT_SWAP bit is causing problems.
    l_data.clearBit<TT::RTT_WR_SWAP_ENABLE_P0_WL>();
    l_data.setBit<TT::RTT_WR_SWAP_ENABLE_P0_CTR>();

    FAPI_DBG("wc_rtt_wr_swap_enable reset 0x%llx", l_data);
    FAPI_TRY( write_rtt_wr_swap_enable(i_target, l_data) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief reset wc
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to wcTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = wcTraits<T> >
inline fapi2::ReturnCode reset( const fapi2::Target<T>& i_target )
{
    FAPI_TRY( reset_config0(i_target) );
    FAPI_TRY( reset_config1(i_target) );
    FAPI_TRY( reset_config2(i_target) );
    FAPI_TRY( reset_config3(i_target) );

    FAPI_TRY( reset_rtt_wr_swap_enable(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}


}

}

#endif
