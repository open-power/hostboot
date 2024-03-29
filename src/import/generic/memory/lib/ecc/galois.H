/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ecc/galois.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file galois.H
/// @brief Translate ECC mark Galois codes to symbol and DQ
///
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_ECC_GALOIS_H_
#define _MSS_ECC_GALOIS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/ecc/ecc_traits.H>

namespace mss
{

namespace ecc
{

///
/// @brief Return symbol value from a given Galois code
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_galois the Galois code
/// @param[out] o_symbol symbol value represented by given Galois code
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
fapi2::ReturnCode galois_to_symbol( const uint8_t i_galois, uint8_t& o_symbol )
{
    const auto& l_p = std::find(TT::symbol2galois, (TT::symbol2galois + TT::ECC_MAX_SYMBOLS), i_galois);

    FAPI_ASSERT( l_p != (TT::symbol2galois + TT::ECC_MAX_SYMBOLS),
                 fapi2::MSS_INVALID_GALOIS_TO_SYMBOL()
                 .set_GALOIS(i_galois),
                 "Invalid Galois code: 0x%02x",
                 i_galois);

    o_symbol = (l_p - TT::symbol2galois);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return Galois code from a given symbol value
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_symbol the symbol value
/// @param[out] o_galois Galois code represented by given symbol
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
fapi2::ReturnCode symbol_to_galois( const uint8_t i_symbol, uint8_t& o_galois )
{
    FAPI_ASSERT( i_symbol < TT::ECC_MAX_SYMBOLS,
                 fapi2::MSS_INVALID_SYMBOL_FOR_GALOIS()
                 .set_SYMBOL(i_symbol),
                 "Invalid symbol: %d",
                 i_symbol);

    o_galois = TT::symbol2galois[i_symbol];

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return symbol value from a given DQ index
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_dq the DQ index
/// @param[out] o_symbol symbol value represented by given DQ index
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
fapi2::ReturnCode dq_to_symbol( const uint8_t i_dq, uint8_t& o_symbol )
{
    const auto& l_p = std::find(TT::symbol2dq, (TT::symbol2dq + TT::ECC_MAX_SYMBOLS), i_dq);

    FAPI_ASSERT( l_p != (TT::symbol2dq + TT::ECC_MAX_SYMBOLS),
                 fapi2::MSS_INVALID_DQ_TO_SYMBOL()
                 .set_DQ(i_dq),
                 "Invalid DQ index: %d",
                 i_dq);

    o_symbol = (l_p - TT::symbol2dq);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return symbol value from a given DQ index
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_dq the DQ index
/// @param[out] o_symbol symbol value represented by given DQ index
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
fapi2::ReturnCode dq_to_symbol_x8( const uint8_t i_dq, uint8_t& o_symbol )
{
    // setting dq to its nearest higher odd number as there is 1 symbol for a pair of dq.
    // and only odd numbers are listed in array symbol2dq_x8
    uint8_t l_dq = i_dq;

    if(i_dq % 2 == 0)
    {
        l_dq += 1;
    }

    const auto& l_p = std::find(TT::symbol2dq_x8, (TT::symbol2dq_x8 + TT::ECC_MAX_SYMBOLS), l_dq);

    FAPI_ASSERT( l_p != (TT::symbol2dq_x8 + TT::ECC_MAX_SYMBOLS),
                 fapi2::MSS_INVALID_DQ_TO_SYMBOL()
                 .set_DQ(i_dq),
                 "Invalid DQ index: %d",
                 i_dq);

    o_symbol = (l_p - TT::symbol2dq_x8);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return DQ index from a given symbol value
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_symbol the symbol value
/// @param[out] o_dq DQ index represented by given symbol value
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
fapi2::ReturnCode symbol_to_dq( const uint8_t i_symbol, uint8_t& o_dq )
{
    FAPI_ASSERT( i_symbol < TT::ECC_MAX_SYMBOLS,
                 fapi2::MSS_INVALID_SYMBOL_TO_DQ()
                 .set_SYMBOL(i_symbol),
                 "symbol_to_dq: invalid symbol: %d",
                 i_symbol);

    o_dq = TT::symbol2dq[i_symbol];

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return DQ index from a given Galois code
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_galois the Galois code
/// @param[out] o_dq DQ index represented by given Galois code
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
fapi2::ReturnCode galois_to_dq( const uint8_t i_galois, uint8_t& o_dq  )
{
    uint8_t l_symbol = 0;

    FAPI_TRY( galois_to_symbol<MC>(i_galois, l_symbol), "Failed galois_to_symbol");
    FAPI_TRY( symbol_to_dq<MC>(l_symbol, o_dq), "Failed symbol_to_dq" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return Galois code from a given DQ index
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_dq the DQ index
/// @paran[in] i_width DRAM width x4 or x8
/// @param[out] o_galois Galois code represented by given symbol
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
fapi2::ReturnCode dq_to_galois( const uint8_t i_dq, const uint8_t i_width, uint8_t& o_galois )
{
    uint8_t l_symbol = 0;

    if(i_width == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4)
    {
        FAPI_TRY( dq_to_symbol<MC>(i_dq, l_symbol), "Failed dq_to_symbol");
    }
    else
    {
        FAPI_TRY( dq_to_symbol_x8<MC>(i_dq, l_symbol), "Failed dq_to_symbol");
    }

    FAPI_TRY( symbol_to_galois<MC>(l_symbol, o_galois) , "Failed symbol_to_galois" );

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace ecc

} // close namespace mss
#endif
