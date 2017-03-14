/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/adr32s.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
#include <lib/mss_attribute_accessors.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/utils/find.H>

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
        static const std::vector<uint64_t> DUTY_CYCLE_DISTORTION_REG;
        static const std::vector<uint64_t> PR_STATIC_OFFSET_REG;

        // This fellow is needed for the reset_dcd template, so he's more like a real trait.
        // Default starting place for duty cycle distortion algorithm
        static constexpr uint64_t DCD_ADJUST_DEFAULT = 0b1000000;

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

            DCD_CONTROL_DLL_ADJUST = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST,
            DCD_CONTROL_DLL_ADJUST_LEN = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST_LEN,
            DCD_CONTROL_DLL_CORRECT_EN = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CORRECT_EN,
            DCD_CONTROL_DLL_ITER_A = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ITER_A,
            DCD_CONTROL_DLL_COMPARE_OUT = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_COMPARE_OUT,

            TSYS_ADR = MCA_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0_ADR0_TSYS,
            TSYS_ADR_LEN = MCA_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0_ADR0_TSYS_LEN,
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
/// @brief Read DCD_CNTL
/// @tparam I ADR32S instance e.g., 0 or 1 for a 64 bit implementation of the PHY
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode read_dcd_cntl( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::ADR32S_COUNT, "adr32s instance out of range");
    FAPI_TRY( mss::getScom(i_target, TT::DUTY_CYCLE_DISTORTION_REG[I], o_data) );
    FAPI_INF("dcd_cntl adrs32%d: 0x%016lx", I, o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write DCD_CNTL
/// @tparam I ADR32S instance e.g., 0 or 1 for a 64 bit implementation of the PHY
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode write_dcd_cntl( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::ADR32S_COUNT, "adr32s instance out of range");

    // Per datasheet, bit 15 must always be written 0 or we'll get a parity error
    if (i_data.getBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>() != 0)
    {
        FAPI_ERR("DCD DLL Compare out is set - will cause a parity error 0x%016lx (0x%016lx)",
                 TT::DUTY_CYCLE_DISTORTION_REG[I], i_data);
        fapi2::Assert(false);
    }

    FAPI_INF("dcd_cntl adr32s%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::DUTY_CYCLE_DISTORTION_REG[I], i_data) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset DCD_CNTL
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode reset_dcd_cntl( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

    // All we need to write is the adjustment default, all the other bits are 0 (and
    // the adujtment default accounts for this)
    l_data.insertFromRight<TT::DCD_CONTROL_DLL_ADJUST, TT::DCD_CONTROL_DLL_ADJUST_LEN>(TT::DCD_ADJUST_DEFAULT);

    for (const auto r : TT::DUTY_CYCLE_DISTORTION_REG)
    {
        FAPI_INF("reset dcd_cntl 0x%016lx: 0x%016lx", r, l_data);
        FAPI_TRY( mss::putScom(i_target, r, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}


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

///
/// @brief Perform ADR DCD calibration - Nimbus Only
/// @param[in] i_target the MCBIST (controler) to perform calibration on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode duty_cycle_distortion_calibration( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Read tsys_adr
/// @tparam I ADR32S instance e.g., 0 or 1 for a 64 bit implementation of the PHY
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode read_tsys_adr( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::ADR32S_COUNT, "adr32s instance out of range");
    FAPI_TRY( mss::getScom(i_target, TT::PR_STATIC_OFFSET_REG[I], o_data) );
    FAPI_INF("tsys_adr adrs32%d: 0x%016lx", I, o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write tsys_adr
/// @tparam I ADR32S instance e.g., 0 or 1 for a 64 bit implementation of the PHY
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode write_tsys_adr( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::ADR32S_COUNT, "adr32s instance out of range");
    FAPI_INF("tsys_adr adr32s%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::PR_STATIC_OFFSET_REG[I], i_data) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset tsys_adr
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adr32sTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = adr32sTraits<T> >
inline fapi2::ReturnCode reset_tsys_adr( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_tsys_adr = 0;

    FAPI_TRY( mss::vpd_mr_tsys_adr(mss::find_target<fapi2::TARGET_TYPE_MCS>(i_target), l_tsys_adr) );
    l_data.insertFromRight<TT::TSYS_ADR, TT::TSYS_ADR_LEN>(l_tsys_adr);

    for (const auto r : TT::PR_STATIC_OFFSET_REG)
    {
        // TODO RTC:160358 Suspect duplicated scoms in ddr initfile
        FAPI_INF("reset tsys_adr 0x%016lx: 0x%016lx", r, l_data);
        FAPI_TRY( mss::putScom(i_target, r, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}


} // close namespace adr32s

} // close namespace mss

#endif
