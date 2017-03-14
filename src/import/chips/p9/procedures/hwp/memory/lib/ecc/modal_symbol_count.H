/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ecc/modal_symbol_count.H $ */
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
/// @file modal_symbol_count.H
/// @brief Subroutines for the MC modal symbol count (MBSSYMEC*Q) registers
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MODAL_SYMBOL_COUNT_H_
#define _MSS_MODAL_SYMBOL_COUNT_H_

#include <fapi2.H>
#include <lib/ecc/ecc_traits.H>
#include <generic/memory/lib/utils/scom.H>

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
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t N, fapi2::TargetType T, typename TT = eccTraits<T> >
inline fapi2::ReturnCode read_index( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert((N < TT::NUM_MBSSYM_REGS), "Modal symbol count reg index failed range check");
    FAPI_TRY( mss::getScom(i_target, (TT::MODAL_SYM_COUNT0_REG + N), o_data) );
    FAPI_INF("read_index<%d>: 0x%016lx", N, o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 0 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<0>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 1 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<1>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 2 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index2( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<2>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 3 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index3( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<3>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 4 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index4( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<4>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 5 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index5( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<5>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 6 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index6( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<6>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 7 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index7( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<7>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) 8 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_index8( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_index<8>(i_target, o_data) );
}

///
/// @brief Read modal symbol count (MBSSYMEC*Q) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_index the register index
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target,
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

        default:
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }
}

///
/// @brief Write  modal symbol count (MBSSYMEC*Q) register
/// @tparam N the register index (0-8)
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t N, fapi2::TargetType T, typename TT = eccTraits<T> >
inline fapi2::ReturnCode write_index( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert((N < TT::NUM_MBSSYM_REGS), "Modal symbol count reg index failed range check");
    FAPI_TRY( mss::putScom(i_target, (TT::MODAL_SYM_COUNT0_REG + N), i_data) );
    FAPI_INF("write_index<%d>: 0x%016lx", N, i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 0 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index0( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<0>(i_target, i_data) );
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 1 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index1( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<1>(i_target, i_data) );
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 2 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index2( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<2>(i_target, i_data) );
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 3 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index3( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<3>(i_target, i_data) );
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 4 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index4( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<4>(i_target, i_data) );
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 5 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index5( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<5>(i_target, i_data) );
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 6 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index6( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<6>(i_target, i_data) );
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 7 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index7( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<7>(i_target, i_data) );
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) 8 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_index8( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_index<8>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_index the register index
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target,
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

        default:
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }
}

///
/// @brief set_count
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCBIST
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_index the counter index
/// @param[in] i_value the value of the field
/// @note MBSSYMEC*Q_MODAL_SYMBOL_COUNTER_XX: Functional mode determined by MBSTRQ_Symbol_counter_mode:
/// @note if 00, 0:7 = Maint NCE counter for Symbol XX if 01, 0:3 = MCBIST error counter for nibble (XX/4)
/// @note and rank (XX%4)*2 4:7 = MCBIST error counter for nibble (XX/4) and rank ((XX%4)*2)+1 if 10,
/// @note 0:3 = MCBIST error counter for port XX/18 and nibble XX%18 4:7 = MCBIST error rank map for
/// @note port XX/18 and nibble XX%18
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCBIST, typename TT = eccTraits<T> >
inline void set_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_index, const uint64_t i_value )
{
    const uint64_t l_field = i_index % TT::MODAL_SYMBOL_COUNTERS_PER_REG;

    switch (l_field)
    {
        case 0:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_00, TT::MODAL_SYMBOL_COUNTER_00_LEN>(i_value);
            break;

        case 1:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_01, TT::MODAL_SYMBOL_COUNTER_01_LEN>(i_value);
            break;

        case 2:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_02, TT::MODAL_SYMBOL_COUNTER_02_LEN>(i_value);
            break;

        case 3:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_03, TT::MODAL_SYMBOL_COUNTER_03_LEN>(i_value);
            break;

        case 4:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_04, TT::MODAL_SYMBOL_COUNTER_04_LEN>(i_value);
            break;

        case 5:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_05, TT::MODAL_SYMBOL_COUNTER_05_LEN>(i_value);
            break;

        case 6:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_06, TT::MODAL_SYMBOL_COUNTER_06_LEN>(i_value);
            break;

        case 7:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_07, TT::MODAL_SYMBOL_COUNTER_07_LEN>(i_value);
            break;

        default:
            // shouldn't happen due to modulo above, but here just in case
            FAPI_ERR("Modal symbol count field index failed range check");
            fapi2::Assert(false);
            break;
    }

    FAPI_INF("set_count(%d): 0x%02lx", l_field, i_value);
}

///
/// @brief get_count
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCBIST
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[in] i_index the counter index
/// @param[out] o_value the value of the field
/// @note MBSSYMEC*Q_MODAL_SYMBOL_COUNTER_XX: Functional mode determined by MBSTRQ_Symbol_counter_mode:
/// @note if 00, 0:7 = Maint NCE counter for Symbol XX if 01, 0:3 = MCBIST error counter for nibble (XX/4)
/// @note and rank (XX%4)*2 4:7 = MCBIST error counter for nibble (XX/4) and rank ((XX%4)*2)+1 if 10,
/// @note 0:3 = MCBIST error counter for port XX/18 and nibble XX%18 4:7 = MCBIST error rank map for
/// @note port XX/18 and nibble XX%18
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCBIST, typename TT = eccTraits<T> >
inline void get_count( const fapi2::buffer<uint64_t>& i_data, const uint64_t i_index, uint64_t& o_value )
{
    const uint64_t l_field = i_index % TT::MODAL_SYMBOL_COUNTERS_PER_REG;

    switch (l_field)
    {
        case 0:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_00, TT::MODAL_SYMBOL_COUNTER_00_LEN>(o_value);
            break;

        case 1:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_01, TT::MODAL_SYMBOL_COUNTER_01_LEN>(o_value);
            break;

        case 2:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_02, TT::MODAL_SYMBOL_COUNTER_02_LEN>(o_value);
            break;

        case 3:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_03, TT::MODAL_SYMBOL_COUNTER_03_LEN>(o_value);
            break;

        case 4:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_04, TT::MODAL_SYMBOL_COUNTER_04_LEN>(o_value);
            break;

        case 5:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_05, TT::MODAL_SYMBOL_COUNTER_05_LEN>(o_value);
            break;

        case 6:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_06, TT::MODAL_SYMBOL_COUNTER_06_LEN>(o_value);
            break;

        case 7:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_07, TT::MODAL_SYMBOL_COUNTER_07_LEN>(o_value);
            break;

        default:
            // shouldn't happen due to modulo above, but here just in case
            FAPI_ERR("Modal symbol count field index failed range check");
            fapi2::Assert(false);
            break;
    }

    FAPI_INF("get_count(%d): 0x%02lx", l_field, o_value);
}

} // close namespace modal_symbol_count

} // close namespace ecc

} // close namespace mss

#endif
