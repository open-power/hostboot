/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/port/port.H $              */
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
/// @file port.H
/// @brief Code to support ports
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_PORT_H_
#define _MSS_PORT_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>

// I have a dream that port code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

template< fapi2::TargetType T >
class portTraits;

// Centaur port traits
template<>
class portTraits<fapi2::TARGET_TYPE_MBA>
{
    public:
};

// Nimbus port traits
template<>
class portTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        static const uint64_t FARB5Q_REG = MCA_MBA_FARB5Q;
        static const uint64_t REFRESH_REG = MCA_MBAREF0Q;
        static const uint64_t ECC_REG = MCA_RECR;

        enum
        {
            CFG_DDR_DPHY_NCLK =     MCA_MBA_FARB5Q_CFG_DDR_DPHY_NCLK,
            CFG_DDR_DPHY_NCLK_LEN = MCA_MBA_FARB5Q_CFG_DDR_DPHY_NCLK_LEN,
            CFG_DDR_DPHY_PCLK =     MCA_MBA_FARB5Q_CFG_DDR_DPHY_PCLK,
            CFG_DDR_DPHY_PCLK_LEN = MCA_MBA_FARB5Q_CFG_DDR_DPHY_PCLK_LEN,
            CFG_CCS_INST_RESET_ENABLE = MCA_MBA_FARB5Q_CFG_CCS_INST_RESET_ENABLE,
            CFG_DDR_RESETN = MCA_MBA_FARB5Q_CFG_DDR_RESETN,
            CFG_CCS_ADDR_MUX_SEL = MCA_MBA_FARB5Q_CFG_CCS_ADDR_MUX_SEL,

            REFRESH_ENABLE = MCA_MBAREF0Q_CFG_REFRESH_ENABLE,

            ECC_CHECK_DISABLE = MCA_RECR_MBSECCQ_DISABLE_MEMORY_ECC_CHECK_CORRECT,
            ECC_CORRECT_DISABLE = MCA_RECR_MBSECCQ_DISABLE_MEMORY_ECC_CORRECT,
        };
};


namespace mss
{
///
/// @brief Given a DIMM, return it's port number.
/// @param[in] the DIMM in question
/// @return the port number it's attached to
///
// Note: Make this a template and dispatch at runtime to determine if the parent of
// the DIMM is an MBA or an MCA BRS
//
inline uint64_t port( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target )
{
    // Our port is the position of our MCA
    return mss::pos( i_target.getParent<fapi2::TARGET_TYPE_MCA>() );
}

///
/// @brief Change the state of the addr_mux_sel bit
/// @param[in] the target
/// @param[in] the state
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T, typename TT = portTraits<T> >
fapi2::ReturnCode change_addr_mux_sel( const fapi2::Target<T>& i_target, states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Change addr_mux_sel to %s %s", (i_state == HIGH ? "high" : "low"), mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::FARB5Q_REG, l_data) );
    l_data.writeBit<TT::CFG_CCS_ADDR_MUX_SEL>(i_state);
    FAPI_TRY( mss::putScom(i_target, TT::FARB5Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Change the state of the MC Refresh enable bit
/// @param[in] the target
/// @param[in] the state
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T, typename TT = portTraits<T> >
fapi2::ReturnCode change_refresh_enable( const fapi2::Target<T>& i_target, states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Change refresh enable to %s %s", (i_state == HIGH ? "high" : "low"), mss::c_str(i_target));
    FAPI_TRY( mss::getScom(i_target, TT::REFRESH_REG, l_data) );
    l_data.writeBit<TT::REFRESH_ENABLE>(i_state);
    FAPI_TRY( mss::putScom(i_target, TT::REFRESH_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable the MC Periodic calibration functionality
/// @param[in] the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T, typename TT = portTraits<T> >
fapi2::ReturnCode enable_periodic_cal( const fapi2::Target<T>& i_target )
{
    FAPI_INF("Enable periodic cal NOOP");
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Enable Read ECC checking
/// @param[in] the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T, typename TT = portTraits<T> >
fapi2::ReturnCode enable_read_ecc( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Enable Read ECC %s", mss::c_str(i_target));

    FAPI_TRY( mss::getScom(i_target, TT::ECC_REG, l_data) );
    l_data.clearBit<TT::ECC_CHECK_DISABLE>();
    l_data.clearBit<TT::ECC_CORRECT_DISABLE>();

    // The preferred operating mode is 11 (INVERT_DATA_TOGGLE_CHECKS)   which stores data complemented
    // (because most bits are '0', and the dram bus pulls up, so transmitting 1s is least power)  but
    // still flips the inversion of check bits to aid RAS. Per Brad Michael 12/15
    l_data.insertFromRight<MCA_RECR_MBSECCQ_DATA_INVERSION, MCA_RECR_MBSECCQ_DATA_INVERSION_LEN>(0b11);

    // bits: 60 MBSTRQ_CFG_MAINT_RCE_WITH_CE
    // cfg_maint_rce_with_ce - not implemented. Need to investigate if needed for nimbus.

    FAPI_TRY( mss::putScom(i_target, TT::ECC_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

//
// We expect to come in to draminit with the following setup:
// 1. ENABLE_RESET_N (FARB5Q(6)) 0
// 2. RESET_N (FARB5Q(4)) 1 - out of reset (done in draminit as a separate step)
// 3. CCS_ADDR_MUX_SEL (FARB5Q(5)) - 1
// 4. CKE out of high impedence
// Note: Ignore resetn as it's taken care of as a separate step
//
///
/// @brief Secure the entry criteria for draminit
/// @param[in] A target representing a port
/// @return FAPI2_RC_SUCCESS if and only if ok
// This is in this header as it's hoped to be able to be shared. Seems to make more
// Might make more sense in p9_mss_draminit.C ... BRS
///
template< fapi2::TargetType T, typename TT = portTraits<T> >
inline fapi2::ReturnCode draminit_entry_invariant( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY( mss::getScom(i_target, TT::FARB5Q_REG, l_data) );

    if ((l_data.getBit<TT::CFG_CCS_ADDR_MUX_SEL>() != HIGH) || (l_data.getBit<TT::CFG_CCS_INST_RESET_ENABLE>() != LOW))
    {
        // We have some bits not set correctly. Lets try to reset the register.
        FAPI_INF("FARB5Q: 0x%llx, setting MUX_SEL, clearing RESET_ENABLE", uint64_t(l_data));
        l_data.setBit<TT::CFG_CCS_ADDR_MUX_SEL>();
        l_data.clearBit<TT::CFG_CCS_INST_RESET_ENABLE>();
        FAPI_TRY( mss::putScom(i_target, TT::FARB5Q_REG, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Drive memory clocks
/// @param[in] A target representing a port
/// @param[in] phy p clock - right most 2 bits
/// @param[in] phy n clock - right most 2 bits
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note this might need a port id added for Centaur/MBA controllers
///
template< fapi2::TargetType T, typename TT = portTraits<T> >
fapi2::ReturnCode drive_mem_clks( const fapi2::Target<T>& i_target, uint64_t i_pclk, uint64_t i_nclk )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("Drive mem clocks");
    FAPI_TRY( mss::getScom(i_target, TT::FARB5Q_REG, l_data) );

    l_data.insertFromRight<TT::CFG_DDR_DPHY_NCLK, TT::CFG_DDR_DPHY_NCLK_LEN>(i_nclk);
    l_data.insertFromRight<TT::CFG_DDR_DPHY_PCLK, TT::CFG_DDR_DPHY_PCLK_LEN>(i_pclk);

    FAPI_TRY( mss::putScom(i_target, TT::FARB5Q_REG, l_data) );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("Unable to drive mem clocks: %s", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief Set DDR resetn
/// @param[in] A target representing a port
/// @param[in] high or low
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note this might need a port id added for Centaur/MBA controllers
///
template< fapi2::TargetType T, typename TT = portTraits<T> >
fapi2::ReturnCode ddr_resetn( const fapi2::Target<T>& i_target, bool i_state )
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY( mss::getScom(i_target, TT::FARB5Q_REG, l_data) );

    if (l_data.getBit<TT::CFG_DDR_RESETN>() != i_state)
    {
        l_data.writeBit<TT::CFG_DDR_RESETN>(i_state);
        FAPI_DBG("ddr_resetn transitioning to %d (0x%llx)", i_state, l_data);
        FAPI_TRY( mss::putScom(i_target, TT::FARB5Q_REG, l_data) );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("Unable to change resetn: %s (%d)", mss::c_str(i_target), i_state);
    return fapi2::current_err;
}

}
#endif
