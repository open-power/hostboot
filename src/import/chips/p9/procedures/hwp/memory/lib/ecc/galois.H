/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ecc/galois.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_ECC_GALOIS_H_
#define _MSS_ECC_GALOIS_H_

#include <lib/ecc/ecc_traits.H>

namespace mss
{

namespace ecc
{

///
/// @brief Return symbol value from a given Galois code
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_galois the Galois code
/// @param[out] o_symbol symbol value represented by given Galois code
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
fapi2::ReturnCode galois_to_symbol( const uint8_t i_galois, uint8_t& o_symbol )
{
    const auto& l_p = std::find(TT::symbol2galois, (TT::symbol2galois + MAX_DQ_BITS), i_galois);

    if (l_p == (TT::symbol2galois + MAX_DQ_BITS))
    {
        FAPI_ERR("galois_to_symbol: invalid Galois code: 0x%02x", i_galois);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    o_symbol = (l_p - TT::symbol2galois);
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Return Galois code from a given symbol value
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_symbol the symbol value
/// @param[out] o_galois Galois code represented by given symbol
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
fapi2::ReturnCode symbol_to_galois( const uint8_t i_symbol, uint8_t& o_galois )
{
    if (i_symbol >= MAX_DQ_BITS)
    {
        FAPI_ERR("symbol_to_galois: invalid symbol: %d", i_symbol);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    o_galois = TT::symbol2galois[i_symbol];
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Return symbol value from a given DQ index
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_dq the DQ index
/// @param[out] o_symbol symbol value represented by given DQ index
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
fapi2::ReturnCode dq_to_symbol( const uint8_t i_dq, uint8_t& o_symbol )
{
    const auto& l_p = std::find(TT::symbol2dq, (TT::symbol2dq + MAX_DQ_BITS), i_dq);

    if (l_p == (TT::symbol2dq + MAX_DQ_BITS))
    {
        FAPI_ERR("dq_to_symbol: invalid DQ index: %d", i_dq);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    o_symbol = (l_p - TT::symbol2dq);
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Return DQ index from a given symbol value
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_symbol the symbol value
/// @param[out] o_dq DQ index represented by given symbol value
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
fapi2::ReturnCode symbol_to_dq( const uint8_t i_symbol, uint8_t& o_dq )
{
    if (i_symbol >= MAX_DQ_BITS)
    {
        FAPI_ERR("symbol_to_dq: invalid symbol: %d", i_symbol);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    o_dq = TT::symbol2dq[i_symbol];
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Return DQ index from a given Galois code
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_galois the Galois code
/// @param[out] o_dq DQ index represented by given Galois code
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
fapi2::ReturnCode galois_to_dq( const uint8_t i_galois, uint8_t& o_dq  )
{
    uint8_t l_symbol = 0;

    FAPI_TRY( galois_to_symbol<T>(i_galois, l_symbol) );
    FAPI_TRY( symbol_to_dq<T>(l_symbol, o_dq) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return Galois code from a given DQ index
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_dq the DQ index
/// @param[out] o_galois Galois code represented by given symbol
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
fapi2::ReturnCode dq_to_galois( const uint8_t i_dq, uint8_t& o_galois )
{
    uint8_t l_symbol = 0;

    FAPI_TRY( mss::ecc::dq_to_symbol<T>(i_dq, l_symbol) );
    FAPI_TRY( mss::ecc::symbol_to_galois<T>(l_symbol, o_galois) );

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace ecc

} // close namespace mss
#endif
