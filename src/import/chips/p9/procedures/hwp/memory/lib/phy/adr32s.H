/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/adr32s.H $             */
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
/// @file adr32s.H
/// @brief Subroutines for the PHY ADR32S registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ADR32S_H_
#define _MSS_ADR32S_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/shared/mss_const.H>
#include <lib/utils/scom.H>

namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class adr32sTraits
/// @brief a collection of traits associated with the PHY ADR32S interface
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class adr32sTraits;

///
/// @class adr32sTraits
/// @brief a collection of traits associated with the Centaur PHY ADR32S interface
///
template<>
class adr32sTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class adr32sTraits
/// @brief a collection of traits associated with the Nimbus PHY ADR32S
///
template<>
class adr32sTraits<fapi2::TARGET_TYPE_MCA>
{
    public:

        // Number of ADR32S units
        static constexpr uint64_t ADR32S_COUNT = 2;

        // MCA ADR32S control registers all come in pairs.
        static const std::vector<uint64_t> DLL_CNFG_REG;
        static const std::vector<uint64_t> OUTPUT_DRIVER_REG;

        enum
        {
            DLL_CNTL_INIT_RXDLL_CAL_RESET = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_INIT_RXDLL_CAL_RESET,
            DLL_CNTL_INIT_RXDLL_CAL_UPDATE = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_INIT_RXDLL_CAL_UPDATE,
            DLL_CNTL_REGS_RXDLL_CAL_SKIP = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_REGS_RXDLL_CAL_SKIP,
            DLL_CNTL_REGS_RXDLL_CAL_SKIP_LEN = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_REGS_RXDLL_CAL_SKIP_LEN,
            DLL_CNTL_REGS_RXDLL_COARSE_ADJ_BY2 = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_REGS_RXDLL_COARSE_ADJ_BY2,
            DLL_CNTL_RXREG_FILTER_LENGTH_DC = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_RXREG_FILTER_LENGTH_DC,
            DLL_CNTL_RXREG_FILTER_LENGTH_DC_LEN = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_RXREG_FILTER_LENGTH_DC_LEN,
            DLL_CNTL_RXREG_LEAD_LAG_SEPARATION_DC = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_RXREG_LEAD_LAG_SEPARATION_DC,
            DLL_CNTL_RXREG_LEAD_LAG_SEPARATION_DC_LEN =
                MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_RXREG_LEAD_LAG_SEPARATION_DC_LEN,
            DLL_CNTL_EN_DRIVER_INVFB_DC = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_EN_DRIVER_INVFB_DC,
            DLL_CNTL_RXREG_FINECAL_2XILSB_DC = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_RXREG_FINECAL_2XILSB_DC,
            DLL_CNTL_CAL_GOOD = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_CAL_GOOD,
            DLL_CNTL_CAL_ERROR = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_CAL_ERROR,
            DLL_CNTL_CAL_ERROR_FINE = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_CAL_ERROR_FINE,

            FLUSH = MCA_DDRPHY_ADR_OUTPUT_FORCE_ATEST_CNTL_P0_ADR32S0_ADR0_FLUSH,
            INIT_IO = MCA_DDRPHY_ADR_OUTPUT_FORCE_ATEST_CNTL_P0_ADR32S0_ADR0_INIT_IO,

        };

};

namespace adr32s
{

///
/// @brief Read DLL_CNTL
/// @tparam I ADR32S instance e.g., 0 or 1 for a 64 bit implementation of the PHY
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode read_dll_cntl( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::ADR32S_COUNT, "adr32s instance out of range");
    FAPI_TRY( mss::getScom(i_target, TT::DLL_CNFG_REG[I], o_data) );
    FAPI_INF("dll_cntl adrs32%d: 0x%016lx", I, o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write DLL_CNTL_ADR32S0
/// @tparam I ADR32S instance e.g., 0 or 1 for a 64 bit implementation of the PHY
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode write_dll_cntl( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::ADR32S_COUNT, "adr32s instance out of range");
    FAPI_INF("dll_cntl adr32s%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::DLL_CNFG_REG[I], i_data) );
fapi_try_exit:
    return fapi2::current_err;
}

//
// Reseting the DLL registers TODO RTC:156518
//

///
/// @brief Set the DLL cal reset (begins DLL cal operations)
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
/// @note Default state is 'low' as writing a 0 forces the cal to begin.
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = adr32sTraits<T> >
inline void set_dll_cal_reset( fapi2::buffer<uint64_t>& o_data, const states i_state = mss::LOW )
{
    FAPI_INF("set_dll_cal_reset %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::DLL_CNTL_INIT_RXDLL_CAL_RESET>(i_state);
}

///
/// @brief Read OUTPUT_DRVIER register
/// @tparam I ADR32S instance e.g., 0 or 1 for a 64 bit implementation of the PHY
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode read_output_driver( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::ADR32S_COUNT, "adr32s instance out of range");
    FAPI_TRY( mss::getScom(i_target, TT::OUTPUT_DRIVER_REG[I], o_data) );
    FAPI_INF("output_driver adrs32%d: 0x%016lx", I, o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write OUTPUT_DRIVER
/// @tparam I ADR32S instance e.g., 0 or 1 for a 64 bit implementation of the PHY
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode write_output_driver( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::ADR32S_COUNT, "adr32s instance out of range");
    FAPI_INF("output_driver adr32s%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::OUTPUT_DRIVER_REG[I], i_data) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the output flush
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
/// @note Default state is 'low' as writing a 0 forces the cal to begin.
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = adr32sTraits<T> >
inline void set_output_flush( fapi2::buffer<uint64_t>& o_data, const states i_state )
{
    FAPI_INF("set_output_flush %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::FLUSH>(i_state);
}

///
/// @brief Set the init io state
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
/// @note Default state is 'low' as writing a 0 forces the cal to begin.
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = adr32sTraits<T> >
inline void set_init_io( fapi2::buffer<uint64_t>& o_data, const states i_state )
{
    FAPI_INF("set_init_io %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::INIT_IO>(i_state);
}

} // close namespace adr

} // close namespace mss

#endif
