/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/seq.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file seq.H
/// @brief Subroutines for the PHY sequencer registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_SEQ_H_
#define _MSS_SEQ_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/utils/scom.H>

namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class seqTraits
/// @brief a collection of traits associated with the PHY SEQ interface
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class seqTraits;

///
/// @class seqTraits
/// @brief a collection of traits associated with the Centaur PHY SEQ interface
///
template<>
class seqTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class seqTraits
/// @brief a collection of traits associated with the Nimbus PHY SEQ
///
template<>
class seqTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        // MCA SEQ control registers - must be 64 bits.
        static const uint64_t SEQ_CONFIG0_REG = MCA_DDRPHY_SEQ_CONFIG0_P0;
        static const uint64_t SEQ_ERROR0_REG = MCA_DDRPHY_SEQ_ERROR_STATUS0_P0;
        static const uint64_t SEQ_TIMING0_REG = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM0_P0;
        static const uint64_t SEQ_TIMING1_REG = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM1_P0;
        static const uint64_t SEQ_TIMING2_REG = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0;
        static const uint64_t SEQ_RDWR_DATA0 = MCA_DDRPHY_SEQ_RD_WR_DATA0_P0;
        static const uint64_t SEQ_RDWR_DATA1 = MCA_DDRPHY_SEQ_RD_WR_DATA1_P0;

        // Fields, can be any size.
        enum
        {
            MPR_PATTERN = MCA_DDRPHY_SEQ_RD_WR_DATA0_P0_DATA_REG0,
            MPR_PATTERN_LEN = MCA_DDRPHY_SEQ_RD_WR_DATA0_P0_DATA_REG0_LEN,

            TMOD_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM0_P0_TMOD_CYCLES,
            TMOD_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM0_P0_TMOD_CYCLES_LEN,
            TRCD_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM0_P0_TRCD_CYCLES,
            TRCD_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM0_P0_TRCD_CYCLES_LEN,
            TRP_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM0_P0_TRP_CYCLES,
            TRP_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM0_P0_TRP_CYCLES_LEN,
            TRFC_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM0_P0_TRFC_CYCLES,
            TRFC_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM0_P0_TRFC_CYCLES_LEN,
            TZQINIT_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM1_P0_TZQINIT_CYCLES,
            TZQINIT_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM1_P0_TZQINIT_CYCLES_LEN,
            TZQCS_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM1_P0_TZQCS_CYCLES,
            TZQCS_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM1_P0_TZQCS_CYCLES_LEN,
            TWLDQSEN_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM1_P0_TWLDQSEN_CYCLES,
            TWLDQSEN_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM1_P0_TWLDQSEN_CYCLES_LEN,
            TWRMRD_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM1_P0_TWRMRD_CYCLES,
            TWRMRD_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM1_P0_TWRMRD_CYCLES_LEN,
            TODTLON_OFF_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_TODTLON_OFF_CYCLES,
            TODTLON_OFF_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_TODTLON_OFF_CYCLES_LEN,
            TRC_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_TRC_CYCLES,
            TRC_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_TRC_CYCLES_LEN,
            TMRSC_CYCLES = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_TMRSC_CYCLES,
            TMRSC_CYCLES_LEN = MCA_DDRPHY_SEQ_MEM_TIMING_PARAM2_P0_TMRSC_CYCLES_LEN,

            DELAYED_PARITY = MCA_DDRPHY_SEQ_CONFIG0_P0_DELAYED_PAR,
        };

};

namespace seq
{

///
/// @brief PHY SEQ register exponent helper
/// PHY SEQ fields is used as exponent of 2, to calculate the number of MEMINTCLKO clock cycles.
/// For example, if TMOD_CYCLES[0:3] = 5, the internal timers use the value 2^5 = 32 MEMINTCLKO
/// clock cycles. The maximum value per nibble is ‘A’h. This helper takes a calculated value and returns
/// the 'best' exponent.
/// @param[in] i_value a value for which to make an exponent
/// @return uint64_t right-aligned value to stick in te field
///
uint64_t exp_helper( const uint64_t i_value );

///
/// @brief Read SEQ_CONFIG0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode read_config0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::SEQ_CONFIG0_REG, o_data) );
    FAPI_DBG("seq_config0: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write SEQ_CONFIG0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode write_config0( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("seq_config0: 0x%016lx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::SEQ_CONFIG0_REG, i_data) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read SEQ_ERROR_STATUS0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode read_error_status0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::SEQ_ERROR0_REG, o_data) );
    FAPI_DBG("seq_error_status0: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

// SEQ_ERROR_STATUS0 is read-only

///
/// @brief Read SEQ_MEM_TIMING_PARAM0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode read_timing0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::SEQ_TIMING0_REG, o_data) );
    FAPI_DBG("seq_timing0: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write SEQ_MEM_TIMING_PARAM0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode write_timing0( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("seq_timing0: 0x%016lx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::SEQ_TIMING0_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read SEQ_MEM_TIMING_PARAM1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode read_timing1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::SEQ_TIMING1_REG, o_data) );
    FAPI_DBG("seq_timing1: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write SEQ_MEM_TIMING_PARAM1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode write_timing1( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("seq_timing1: 0x%016lx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::SEQ_TIMING1_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read SEQ_MEM_TIMING_PARAM2
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode read_timing2( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::SEQ_TIMING2_REG, o_data) );
    FAPI_DBG("seq_timing2: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write SEQ_MEM_TIMING_PARAM2
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode write_timing2( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("seq_timing2: 0x%016lx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::SEQ_TIMING2_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

// TK read, write RD_WR_DATA

///
/// @brief Setup odt_wr/rd_config
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
fapi2::ReturnCode reset_rd_wr_data( const fapi2::Target<T>& i_target )
{
    // MPR_PATTERN_BIT of 0F0F0F0F pattern
    static const uint64_t MPR_PATTERN = 0x5555;
    fapi2::buffer<uint64_t> l_data;

    l_data.insertFromRight<TT::MPR_PATTERN, TT::MPR_PATTERN_LEN>(MPR_PATTERN);

    FAPI_INF("seq_rd_wr 0x%llx", l_data);
    FAPI_TRY( mss::putScom(i_target, TT::SEQ_RDWR_DATA0, l_data) );
    FAPI_TRY( mss::putScom(i_target, TT::SEQ_RDWR_DATA1, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset SEQ_CONFIG0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode reset_config0( const fapi2::Target<T>& i_target )
{
    // TK ATTR_VPD_DRAM_2N_MODE_ENABLED  49, 0b1, (def_2N_mode);       # enable 2 cycle addr mode BRS

    fapi2::buffer<uint64_t> l_data;

    // DDR4 needs delayed partiy TK for DDR5/DDR3 ...
    l_data.setBit<TT::DELAYED_PARITY>();
    FAPI_TRY( write_config0(i_target, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset SEQ_TIMING0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
fapi2::ReturnCode reset_timing0( const fapi2::Target<T>& i_target );


///
/// @brief reset SEQ_TIMING1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
fapi2::ReturnCode reset_timing1( const fapi2::Target<T>& i_target );


///
/// @brief reset SEQ_TIMING2
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
fapi2::ReturnCode reset_timing2( const fapi2::Target<T>& i_target );

///
/// @brief reset seq
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to seqTraits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = seqTraits<T> >
inline fapi2::ReturnCode reset( const fapi2::Target<T>& i_target )
{
    FAPI_TRY( reset_config0(i_target) );
    FAPI_TRY( reset_timing0(i_target) );
    FAPI_TRY( reset_timing1(i_target) );
    FAPI_TRY( reset_timing2(i_target) );
    FAPI_TRY( reset_rd_wr_data(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace seq

} // close namespace mss

#endif

