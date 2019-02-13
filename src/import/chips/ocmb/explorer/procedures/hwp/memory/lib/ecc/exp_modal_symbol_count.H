/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ecc/exp_modal_symbol_count.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file exp_modal_symbol_count.H
/// @brief Subroutines for the MC modal symbol count (MBSSYMEC*Q) registers
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _EXP_MSS_MODAL_SYMBOL_COUNT_H_
#define _EXP_MSS_MODAL_SYMBOL_COUNT_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/ecc/ecc_traits.H>
#include <generic/memory/lib/ecc/modal_symbol_count.H>

namespace mss
{

namespace ecc
{

namespace modal_symbol_count
{

///
/// @brief Read modal symbol count (MBSSYMEC*Q) register
/// @tparam N the register index (0-8)
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<DEFAULT_MC_TYPE, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t N, fapi2::TargetType T, typename TT = eccTraits<mc_type::EXPLORER, T> >
inline fapi2::ReturnCode read_index( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert((N < TT::NUM_MBSSYM_REGS), "Modal symbol count reg index failed range check");
    FAPI_TRY( mss::getScom(i_target, (TT::MODAL_SYM_COUNT0_REG + N), o_data) );
    FAPI_INF("read_index<%d>: 0x%016lx", N, o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 9 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index9( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<9>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_index the register index
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TARGET_TYPE_OCMB_CHIP >
inline fapi2::ReturnCode read( const fapi2::TARGET_TYPE_OCMB_CHIP i_target,
                               const uint64_t i_index,
                               fapi2::buffer<uint64_t>& o_data )
{
    switch (i_index)
    {
        case(0):
            return ( read_index0(i_target, o_data) );

        case(1):
            return ( read_index1(i_target, o_data) );

        case(2):
            return ( read_index2(i_target, o_data) );

        case(3):
            return ( read_index3(i_target, o_data) );

        case(4):
            return ( read_index4(i_target, o_data) );

        case(5):
            return ( read_index5(i_target, o_data) );

        case(6):
            return ( read_index6(i_target, o_data) );

        case(7):
            return ( read_index7(i_target, o_data) );

        case(8):
            return ( read_index8(i_target, o_data) );

        case(9):
            return ( read_index9(i_target, o_data) );

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_INDEX_PASSED()
                         .set_INDEX(i_index)
                         .set_FUNCTION(SYMBOL_COUNT_READ),
                         "%s Invalid index passed to fwms::ecc::modal_symbol_count::read (%d)",
                         mss::c_str(i_target),
                         i_index);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write  modal symbol count (MBSSYMEC*Q) register
/// @tparam N the register index (0-8)
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<EXPLORER, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t N, fapi2::TargetType T, typename TT = eccTraits<mc_type::EXPLORER, T> >
inline fapi2::ReturnCode write_index( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert((N < TT::NUM_MBSSYM_REGS), "Modal symbol count reg index failed range check");
    FAPI_TRY( mss::putScom(i_target, (TT::MODAL_SYM_COUNT0_REG + N), i_data) );
    FAPI_INF("write_index<%d>: 0x%016lx", N, i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 9 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index9( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<9>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_index the register index
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TARGET_TYPE_OCMB_CHIP >
inline fapi2::ReturnCode write( const fapi2::TARGET_TYPE_OCMB_CHIP i_target,
                                const uint64_t i_index,
                                const fapi2::buffer<uint64_t>& i_data )
{
    switch (i_index)
    {
        case(0):
            return ( write_index0(i_target, i_data) );

        case(1):
            return ( write_index1(i_target, i_data) );

        case(2):
            return ( write_index2(i_target, i_data) );

        case(3):
            return ( write_index3(i_target, i_data) );

        case(4):
            return ( write_index4(i_target, i_data) );

        case(5):
            return ( write_index5(i_target, i_data) );

        case(6):
            return ( write_index6(i_target, i_data) );

        case(7):
            return ( write_index7(i_target, i_data) );

        case(8):
            return ( write_index8(i_target, i_data) );

        case(9):
            return ( write_index9(i_target, i_data) );

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_INDEX_PASSED()
                         .set_INDEX(i_index)
                         .set_FUNCTION(SYMBOL_COUNT_WRITE),
                         "%s Invalid index passed to fwms::ecc::modal_symbol_count::write (%d)",
                         mss::c_str(i_target),
                         i_index);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}


} // close namespace modal_symbol_count

} // close namespace ecc

} // close namespace mss

#endif
