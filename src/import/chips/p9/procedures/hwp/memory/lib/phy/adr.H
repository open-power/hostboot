/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/adr.H $     */
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
/// @file adr.H
/// @brief Subroutines for the PHY ADR registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ADR_H_
#define _MSS_ADR_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/utils/mss_pair.H>

namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class adrTraits
/// @brief a collection of traits associated with the PHY ADR interface
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class adrTraits;

///
/// @class adrTraits
/// @brief a collection of traits associated with the Centaur PHY ADR interface
///
template<>
class adrTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class adrTraits
/// @brief a collection of traits associated with the Nimbus PHY ADR
///
template<>
class adrTraits<fapi2::TARGET_TYPE_MCA>
{
    public:

        enum
        {
            // Each register has two fields. One for the even lane and one for the odd lane.
            ADR_DELAY_EVEN = MCA_DDRPHY_ADR_DELAY0_P0_ADR0_01,
            ADR_DELAY_ODD = MCA_DDRPHY_ADR_DELAY0_P0_ADR0_01_DELAY1,
            ADR_DELAY_LEN = MCA_DDRPHY_ADR_DELAY0_P0_ADR0_01_DELAY1_LEN,

            ADR_IO_FET_SLICE_EN_MAP0_ADR0 = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0,
            ADR_IO_FET_SLICE_EN_MAP1_ADR0 = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0,
            ADR_IO_FET_SLICE_EN_MAP0_ADR1 = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1,
            ADR_IO_FET_SLICE_EN_MAP1_ADR1 = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1,
            ADR_IO_FET_SLICE_EN_MAP0_ADR2 = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2,
            ADR_IO_FET_SLICE_EN_MAP1_ADR2 = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2,
            ADR_IO_FET_SLICE_EN_MAP0_ADR3 = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3,
            ADR_IO_FET_SLICE_EN_MAP1_ADR3 = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR3,
            ADR_IO_FET_SLICE_EN_LANE0_POS = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0_01_SEL0,
            ADR_IO_FET_SLICE_EN_LANE1_POS = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0_01_SEL1,
            ADR_IO_FET_SLICE_EN_LANE2_POS = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0_01_SEL2,
            ADR_IO_FET_SLICE_EN_LANE3_POS = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0_01_SEL3,
            ADR_IO_FET_SLICE_EN_LANE4_POS = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0_01_SEL4,
            ADR_IO_FET_SLICE_EN_LANE5_POS = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0_01_SEL5,
            ADR_IO_FET_SLICE_EN_LANE6_POS = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0_01_SEL6,
            ADR_IO_FET_SLICE_EN_LANE7_POS = MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0_01_SEL7,
            NUM_CLK_LANES = 4,
            NUM_CMD_ADDR_LANES = 23,
            NUM_CNTL_LANES = 10,
            NUM_CSCID_LANES = 7,
        };

        //IO FET slice driver registers, broken up by attribute groupings:
        //  1) CLK
        //  2) ADR
        //  3) CNTL
        //  4) CS/CID
        // The vector contains a pair < register, bit position >
        static constexpr mss::pair<uint64_t, uint64_t> IO_TX_FET_SLICE_CLK_REG[NUM_CLK_LANES]  =
        {
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE3_POS }, //CLK00 P
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE2_POS }, //CLK00 N
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE7_POS }, //CLK01 P
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE6_POS }, //CLK01 N
        };
        static constexpr mss::pair<uint64_t, uint64_t> IO_TX_FET_SLICE_CMD_ADDR_REG[NUM_CMD_ADDR_LANES]  =
        {
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE0_POS }, //ADDR0
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE5_POS }, //ADDR1
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE2_POS }, //ADDR2
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE4_POS }, //ADDR3
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE6_POS }, //ADDR4
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE3_POS }, //ADDR5
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE1_POS }, //ADDR6
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE7_POS }, //ADDR7
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE2_POS }, //ADDR8
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE0_POS }, //ADDR9
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE5_POS }, //ADDR10
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, ADR_IO_FET_SLICE_EN_LANE1_POS }, //ADDR11
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE3_POS }, //ADDR12
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE0_POS }, //ADDR13
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE1_POS }, //ADDR14/WEN
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE3_POS }, //ADDR15/CAS
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE1_POS }, //ADDR16/RAS
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE4_POS }, //ADDR17/RAS
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE7_POS }, //BA0
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE4_POS }, //BA1
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, ADR_IO_FET_SLICE_EN_LANE2_POS }, //BG0
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, ADR_IO_FET_SLICE_EN_LANE5_POS }, //BG1
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, ADR_IO_FET_SLICE_EN_LANE0_POS }, //ACT_N

        };
        static constexpr mss::pair<uint64_t, uint64_t> IO_TX_FET_SLICE_CNTL_REG[NUM_CNTL_LANES] =
        {
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, ADR_IO_FET_SLICE_EN_LANE3_POS }, //CKE0
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE2_POS }, //CKE1
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, ADR_IO_FET_SLICE_EN_LANE6_POS }, //CKE2
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, ADR_IO_FET_SLICE_EN_LANE4_POS }, //CKE3
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE2_POS }, //ODT0
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE6_POS }, //ODT1
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE1_POS }, //ODT2
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE2_POS }, //ODT3
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE3_POS }, //PARITY
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, ADR_IO_FET_SLICE_EN_LANE7_POS }, //RESET_N
        };
        static constexpr mss::pair<uint64_t, uint64_t> IO_TX_FET_SLICE_CSCID_REG[NUM_CSCID_LANES] =
        {
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE0_POS }, //CS0
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE1_POS }, //CS1
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, ADR_IO_FET_SLICE_EN_LANE0_POS }, //CS2
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE1_POS }, //CS3
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, ADR_IO_FET_SLICE_EN_LANE3_POS }, //CID0
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE5_POS }, //CID1
            { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1, ADR_IO_FET_SLICE_EN_LANE0_POS }, //CID2
        };
};

///
/// @brief A structure to represent an adr operation
///
struct adr_data
{
    // The register
    uint64_t iv_reg;

    // One function gets the even lanes attribute, the other gets the odd lanes
    fapi2::ReturnCode (*iv_even_func)(const fapi2::Target<fapi2::TARGET_TYPE_MCA>&, uint8_t&);
    fapi2::ReturnCode (*iv_odd_func)(const fapi2::Target<fapi2::TARGET_TYPE_MCA>&, uint8_t&);
};

namespace adr
{

///
/// @brief Reset the ADR Delay Lines
/// @param[in] i_target the fapi2 target of the MCA
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note reads VPD and resets the delay lines. This is very controller specific, so we have
/// a one function for each controller (er ... but just one now)
///
fapi2::ReturnCode reset_delay( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

//TODO RTC:161327 Change API to use or to have a function parameter version for ADR IO IMP

///
/// @brief sets up the clock driver impedances
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_imp_clk( const fapi2::Target<T>& i_target );

///
/// @brief Reads the clock output impedance register
/// @tparam I Clock lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of both of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline fapi2::ReturnCode read_imp_clk( const fapi2::Target<T>& i_target,
                                       fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::NUM_CLK_LANES, "lane instance out of range");

    //one register per CLK
    FAPI_TRY( mss::getScom(i_target, TT::IO_TX_FET_SLICE_CLK_REG[I].first, o_data) );
    FAPI_INF("imp_clk lane<%d>: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the clock output impedance register
/// @tparam I Clock lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of both of the the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline fapi2::ReturnCode write_imp_clk( const fapi2::Target<T>& i_target,
                                        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::NUM_CLK_LANES, "lane instance out of range");

    //one register per CLK
    FAPI_INF("imp_clk lane<%d>: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::IO_TX_FET_SLICE_CLK_REG[I].first, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the command/address driver impedances
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_imp_cmd_addr( const fapi2::Target<T>& i_target );

///
/// @brief Reads the command/address output impedance register
/// @tparam I Command/Address lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of both of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline fapi2::ReturnCode read_imp_cmd_addr( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::NUM_CMD_ADDR_LANES, "lane instance out of range");

    //one register per CMD/ADDR lane
    FAPI_TRY( mss::getScom(i_target, TT::IO_TX_FET_SLICE_CMD_ADDR_REG[I].first, o_data) );
    FAPI_INF("imp_cmd_addr lane<%d>: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the command/address output impedance register
/// @tparam I Command/Address lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of both of the the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline fapi2::ReturnCode write_imp_cmd_addr( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::NUM_CMD_ADDR_LANES, "lane instance out of range");

    //one register per CMD/ADDR lane
    FAPI_INF("imp_cmd_addr lane<%d>: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::IO_TX_FET_SLICE_CMD_ADDR_REG[I].first, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the control driver impedances
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_imp_cntl( const fapi2::Target<T>& i_target );

///
/// @brief Reads the control output impedance register
/// @tparam I Control lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of both of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline fapi2::ReturnCode read_imp_cntl( const fapi2::Target<T>& i_target,
                                        fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::NUM_CNTL_LANES, "lane instance out of range");

    //one register per CNTL
    FAPI_TRY( mss::getScom(i_target, TT::IO_TX_FET_SLICE_CNTL_REG[I].first, o_data) );
    FAPI_INF("imp_cntl lane<%d>: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the control output impedance register
/// @tparam I Control lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of both of the the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline fapi2::ReturnCode write_imp_cntl( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::NUM_CNTL_LANES, "lane instance out of range");

    //one register per CNTL
    FAPI_INF("imp_cntl lane<%d>: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::IO_TX_FET_SLICE_CNTL_REG[I].first, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the chip select/chip id driver impedances
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_imp_cscid( const fapi2::Target<T>& i_target );

///
/// @brief Reads the chip select/chip id output impedance register
/// @tparam I Chip Select/Chip ID lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of both of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline fapi2::ReturnCode read_imp_cscid( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::NUM_CSCID_LANES, "lane instance out of range");

    //one register per CS/CID
    FAPI_TRY( mss::getScom(i_target, TT::IO_TX_FET_SLICE_CSCID_REG[I].first, o_data) );
    FAPI_INF("imp_cscid lane<%d>: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the chip select/chip id output impedance register
/// @tparam I Chip Select/Chip ID lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of both of the the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline fapi2::ReturnCode write_imp_cscid( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::NUM_CSCID_LANES, "lane instance out of range");

    //one register per CS/CID
    FAPI_INF("imp_cscid lane<%d>: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::IO_TX_FET_SLICE_CSCID_REG[I].first, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

//////////////////////////////////////////
// ADR impedance field access functions //
//////////////////////////////////////////
///
/// @brief Writes the chip select's/chip id's output impedance field
/// @tparam I Chip Select/Chip ID lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in,out] io_data register data to modify
/// @param[in] i_field - field data to change
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline void set_imp_cscid( fapi2::buffer<uint64_t>& io_data,
                           const bool i_field )
{
    static_assert( I < TT::NUM_CSCID_LANES, "lane instance out of range");

    // modifies the data
    io_data.writeBit<TT::IO_TX_FET_SLICE_CSCID_REG[I].second>(i_field);
}

///
/// @brief Reads the chip select's/chip id's output impedance field
/// @tparam I Chip Select/Chip ID lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_data the field data
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline const bool get_imp_cscid( const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::NUM_CSCID_LANES, "lane instance out of range");

    // sends the output data
    return i_data.getBit<TT::IO_TX_FET_SLICE_CSCID_REG[I].second>();
}

///
/// @brief Writes the clocks's output impedance field
/// @tparam I Clock lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in,out] io_data register data to modify
/// @param[in] i_field - field data to change
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline void set_imp_clk( fapi2::buffer<uint64_t>& io_data,
                         const bool i_field )
{
    static_assert( I < TT::NUM_CLK_LANES, "lane instance out of range");

    // modifies the data
    io_data.writeBit<TT::IO_TX_FET_SLICE_CLK_REG[I].second>(i_field);
}

///
/// @brief Reads the clock's output impedance field
/// @tparam I Clock lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_data the field data
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline const bool get_imp_clk( const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::NUM_CLK_LANES, "lane instance out of range");

    // sends the output data
    return i_data.getBit<TT::IO_TX_FET_SLICE_CLK_REG[I].second>();
}

///
/// @brief Writes the command/address's output impedance field
/// @tparam I Command/Address lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in,out] io_data register data to modify
/// @param[in] i_field - field data to change
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline void set_imp_cmd_addr( fapi2::buffer<uint64_t>& io_data,
                              const bool i_field )
{
    static_assert( I < TT::NUM_CMD_ADDR_LANES, "lane instance out of range");

    // modifies the data
    io_data.writeBit<TT::IO_TX_FET_SLICE_CMD_ADDR_REG[I].second>(i_field);
}

///
/// @brief Reads the command/addresses's output impedance field
/// @tparam I Command/Address lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_data the field data
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline const bool get_imp_cmd_addr( const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::NUM_CMD_ADDR_LANES, "lane instance out of range");

    // sends the output data
    return i_data.getBit<TT::IO_TX_FET_SLICE_CMD_ADDR_REG[I].second>();
}

///
/// @brief Writes the control signal's output impedance field
/// @tparam I Control lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in,out] io_data register data to modify
/// @param[in] i_field - field data to change
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline void set_imp_cntl( fapi2::buffer<uint64_t>& io_data,
                          const bool i_field )
{
    static_assert( I < TT::NUM_CNTL_LANES, "lane instance out of range");

    // modifies the data
    io_data.writeBit<TT::IO_TX_FET_SLICE_CNTL_REG[I].second>(i_field);
}

///
/// @brief Reads the control signal's output impedance field
/// @tparam I Control lane instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to adrTraits<T>
/// @param[in] i_data the field data
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = adrTraits<T> >
inline const bool get_imp_cntl( const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::NUM_CNTL_LANES, "lane instance out of range");

    // sends the output data
    return i_data.getBit<TT::IO_TX_FET_SLICE_CNTL_REG[I].second>();
}

} // close namespace adr

} // close namespace mss

#endif
