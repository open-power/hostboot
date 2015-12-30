/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/dp16.C $               */
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
/// @file dp16.C
/// @brief Static data and subroutines to control the DP16 logic blocks
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <utility>
#include <vector>

#include "../utils/scom.H"
#include "dp16.H"

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include "../utils/pos.H"
#include "../utils/c_str.H"

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_SYSTEM;

namespace mss
{
namespace dp16
{

typedef   std::pair< uint64_t, uint64_t >  register_data_pair;
typedef std::vector< register_data_pair >  register_data_vector;

// Why the tables you ask? Because these bits need to be controlled
// depending on phy, packaging, board swizzling and it's just eaiser
// to see the bits like this than in a more compact algorithmic arrangement.

// Systems without Spare Bytes (or with deconfigured spares)
static std::vector< register_data_vector > data_bit_enable_no_spare =
{
    // DHPY01
    {
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_0, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_1, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_2, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_3, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_4, 0xFF00},

        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_4, 0x0},
    },
};

// Rank Pair will be added to the register address before writing
static std::vector< register_data_vector > wrclk_enable_no_spare_x4 =
{
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0x8400},
    },
};

// Rank Pair will be added to the register address before writing
static std::vector< register_data_vector > rdclk_enable_no_spare_x4 =
{
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0x8400},
    },
};

// Systems With Spare Bytes Enabled
static std::vector< register_data_vector > data_bit_enable_spare =
{
    // DHPY01
    {
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_0, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_1, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_2, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_3, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_4, 0xFFFF},

        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_4, 0x0},
    },
};

static std::vector< register_data_vector > wrclk_enable_spare_x4 =
{
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0x8640},
    },
};

static std::vector< register_data_vector > rdclk_enable_spare_x4 =
{
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0x8640},
    },
};

///
/// @brief Write the data bit enable registers
/// @param[in] a port target
/// @param[in] vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
template<>
fapi2::ReturnCode write_data_bit_enable( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // Determine if we're running with spares or not. Once we know that, we can find the right vector to iterate over.
    // Note: Is this ATTR_EFF_DIMM_SPARE? Because that's per DIMM, but this is a port-level statement, right? BRS
    // Assume Nimbus for now - no spares ever. BRS
    bool l_using_spares = false;

    // Since this code is the MCA specialization, we know we never deal with DPHY23 - Nimbus PHY are
    // 4 copies of the same PHY. So we can use the DPHY01 data for all position.
    auto l_reg_data = l_using_spares ? data_bit_enable_spare[0] : data_bit_enable_no_spare[0];

    FAPI_DBG("reg/data vector %d", l_reg_data.size());

    for (auto rdp : l_reg_data)
    {
        // This is probably important enough to be seen all the time, not just debug
        FAPI_INF( "Setting up DATA_BIT_ENABLE 0x%llx (0x%llx) %s", rdp.first, rdp.second, mss::c_str(i_target) );
        FAPI_TRY( mss::putScom(i_target, rdp.first, rdp.second) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write the clock enable registers
/// @param[in] a port target
/// @param[in] vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
template<>
fapi2::ReturnCode read_clock_enable( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                     const std::vector< uint64_t >& l_rank_pairs )
{
    // Just slam something in here for now - we know the 'RIT DIMM' is x4, lets assume no cross-coupling for now
    bool l_using_spares = false;
    auto l_reg_data = l_using_spares ? rdclk_enable_spare_x4[0] : rdclk_enable_no_spare_x4[0];

    for (auto rp : l_rank_pairs)
    {
        for (auto rdp : l_reg_data)
        {
            // Grab the register and add the rank pair in
            fapi2::buffer<uint64_t> l_address(rdp.first);
            l_address.insertFromRight<22, 2>(rp);

            fapi2::buffer<uint64_t> l_data;
            l_data.insertFromRight<MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0_01_QUAD0_CLK16, 16>(rdp.second);

            FAPI_INF( "Setting up RDCLK RP%d 0x%llx (0x%llx) %s", rp, l_address, l_data, mss::c_str(i_target) );
            FAPI_TRY( mss::putScom(i_target, l_address, l_data) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write the read clock enable registers
/// @param[in] a port target
/// @param[in] vector of rank pairs
/// @return FAPI2_RC_SUCCESs iff ok
///
template<>
fapi2::ReturnCode write_clock_enable( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                      const std::vector< uint64_t >& l_rank_pairs )
{
    // Just slam something in here for now - we know the 'RIT DIMM' is x4, lets assume no cross-coupling for now
    bool l_using_spares = false;
    auto l_reg_data = l_using_spares ? wrclk_enable_spare_x4[0] : wrclk_enable_no_spare_x4[0];

    for (auto rp : l_rank_pairs)
    {
        for (auto rdp : l_reg_data)
        {
            // Grab the register and add the rank pair in
            fapi2::buffer<uint64_t> l_address(rdp.first);
            l_address.insertFromRight<22, 2>(rp);

            fapi2::buffer<uint64_t> l_data;
            l_data.insertFromRight<MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0_01_QUAD0_CLK16, 16>(rdp.second);

            FAPI_INF( "Setting up WRCLK RP%d 0x%llx (0x%llx) %s", rp, l_address, l_data, mss::c_str(i_target) );
            FAPI_TRY( mss::putScom(i_target, l_address, l_data) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the training delay configureation
/// @param[in] the port target
/// @param[in] vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
template<>
fapi2::ReturnCode reset_delay_values( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                      const std::vector< uint64_t >& l_rank_pairs )
{
    std::vector<uint64_t> l_addrs(
    {
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_0,
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_1,
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_2,
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_3,
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_4,
    } );

    fapi2::buffer<uint64_t> l_data;

    // Reset the write level values
    FAPI_INF( "Resetting write level values %s", mss::c_str(i_target) );
    FAPI_TRY( mss::getScom(i_target, MCA_DDRPHY_WC_CONFIG2_P0, l_data) );
    l_data.setBit<MCA_DDRPHY_WC_CONFIG2_P0_EN_RESET_WR_DELAY_WL>();
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_WC_CONFIG2_P0, l_data) );

    for (auto rp : l_rank_pairs)
    {
        for (auto a : l_addrs)
        {
            // Add the rank pair into the register to get the actual address
            fapi2::buffer<uint64_t> l_address(a);
            l_address.insertFromRight<22, 2>(rp);

            FAPI_DBG( "Resetting DP16 gate delay 0x%llx %s", l_address, mss::c_str(i_target) );
            FAPI_TRY( mss::putScom(i_target, l_address, 0) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the DP16 sysclk
/// @param[in] a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
template<>
fapi2::ReturnCode setup_sysclk( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    std::vector< std::pair<uint64_t, uint64_t> > l_addrs(
    {
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_0},
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_1, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_1},
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_2, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_2},
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_3, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_3},
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_4, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_4},
    } );

    fapi2::buffer<uint64_t> l_data;
    uint8_t is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    l_data.setBit<MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0_01_ENABLE>();

    if (is_sim)
    {
        l_data.setBit<MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0_01_ROT_OVERRIDE_EN>();
    }

    for (auto p : i_target.getChildren<TARGET_TYPE_MCA>())
    {
        FAPI_DBG("set dp16_sysclk for %s", mss::c_str(p));

        for (auto a : l_addrs)
        {
            FAPI_TRY( mss::putScom(p, a.first, l_data) );
            FAPI_TRY( mss::putScom(p, a.second, l_data) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


}
}
