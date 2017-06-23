/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ecc/hw_mark_store.H $ */
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
/// @file hw_mark_store.H
/// @brief Subroutines for the MC hardware mark store registers
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_HW_MARK_STORE_H_
#define _MSS_HW_MARK_STORE_H_

#include <fapi2.H>
#include <lib/ecc/ecc_traits.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/shared/mss_const.H>

namespace mss
{

namespace ecc
{

namespace hwms
{

///
/// @brief Read Hardware Mark Store (HWMS) register
/// @tparam R master rank number
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t R, fapi2::TargetType T, typename TT = eccTraits<T> >
inline fapi2::ReturnCode read_rank( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert((R < MAX_MRANK_PER_PORT), "Master rank index failed range check");
    FAPI_TRY( mss::getScom(i_target, (TT::HARDWARE_MS0_REG + R), o_data) );
    FAPI_INF("read_rank<%d>: 0x%016lx", R, o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 0 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_rank0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<0>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 1 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_rank1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<1>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 2 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_rank2( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<2>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 3 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_rank3( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<3>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 4 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_rank4( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<4>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 5 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_rank5( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<5>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 6 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_rank6( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<6>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 7 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read_rank7( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<7>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_rank the master rank index
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target,
                               const uint64_t i_rank,
                               fapi2::buffer<uint64_t>& o_data )
{
    switch (i_rank)
    {
        case(0):
            return ( read_rank0(i_target, o_data) );

        case(1):
            return ( read_rank1(i_target, o_data) );

        case(2):
            return ( read_rank2(i_target, o_data) );

        case(3):
            return ( read_rank3(i_target, o_data) );

        case(4):
            return ( read_rank4(i_target, o_data) );

        case(5):
            return ( read_rank5(i_target, o_data) );

        case(6):
            return ( read_rank6(i_target, o_data) );

        case(7):
            return ( read_rank7(i_target, o_data) );

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RANK_PASSED()
                         .set_RANK(i_rank)
                         .set_TARGET(i_target)
                         .set_FUNCTION(HWMS_READ),
                         "%s Invalid rank passed to fwms::ecc::hwms::read (%d)",
                         mss::c_str(i_target),
                         i_rank);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write Hardware Mark Store (HWMS) register
/// @tparam R master rank number
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t R, fapi2::TargetType T, typename TT = eccTraits<T> >
inline fapi2::ReturnCode write_rank( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert((R < MAX_MRANK_PER_PORT), "Master rank index failed range check");
    FAPI_TRY( mss::putScom(i_target, (TT::HARDWARE_MS0_REG + R), i_data) );
    FAPI_INF("write_rank<%d>: 0x%016lx", R, i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 0 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_rank0( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<0>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 1 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_rank1( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<1>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 2 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_rank2( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<2>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 3 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_rank3( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<3>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 4 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_rank4( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<4>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 5 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_rank5( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<5>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 6 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_rank6( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<6>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 7 register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write_rank7( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<7>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_rank the master rank index
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target,
                                const uint64_t i_rank,
                                const fapi2::buffer<uint64_t>& i_data )
{
    switch (i_rank)
    {
        case(0):
            return ( write_rank0(i_target, i_data) );

        case(1):
            return ( write_rank1(i_target, i_data) );

        case(2):
            return ( write_rank2(i_target, i_data) );

        case(3):
            return ( write_rank3(i_target, i_data) );

        case(4):
            return ( write_rank4(i_target, i_data) );

        case(5):
            return ( write_rank5(i_target, i_data) );

        case(6):
            return ( write_rank6(i_target, i_data) );

        case(7):
            return ( write_rank7(i_target, i_data) );

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RANK_PASSED()
                         .set_RANK(i_rank)
                         .set_TARGET(i_target)
                         .set_FUNCTION(HWMS_WRITE),
                         "%s Invalid rank passed to fwms::ecc::hwms::write(%d)",
                         mss::c_str(i_target),
                         i_rank);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_chipmark
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note HWMS0_CHIPMARK: Hardware chipmark (Galois field code)
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_chipmark( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::HARDWARE_MS_CHIPMARK, TT::HARDWARE_MS_CHIPMARK_LEN>(i_value);
    FAPI_INF("set_chipmark: 0x%02lx", i_value);
}

///
/// @brief get_chipmark
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note HWMS0_CHIPMARK: Hardware chipmark (Galois field code)
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_chipmark( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::HARDWARE_MS_CHIPMARK, TT::HARDWARE_MS_CHIPMARK_LEN>(o_value);
    FAPI_INF("get_chipmark: 0x%02lx", o_value);
}

///
/// @brief set_confirmed
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_state mss::YES or mss::NO - desired state
/// @note HWMS0_CONFIRMED: chipmark confirmed
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_confirmed( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    io_data.writeBit<TT::HARDWARE_MS_CONFIRMED>(i_state);
    FAPI_INF("set_confirmed: 0x%01lx", i_state);
}

///
/// @brief get_confirmed
/// @tparam T fapi2 Target Type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_state mss::YES or mss::NO - representing the state of the field
/// @note HWMS0_CONFIRMED: chipmark confirmed
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_confirmed( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    o_state = (i_data.getBit<TT::HARDWARE_MS_CONFIRMED>() == false) ? mss::NO : mss::YES;
    FAPI_INF("get_confirmed: 0x%01lx", o_state);
}

///
/// @brief set_exit_1
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_state mss::YES or mss::NO - desired state
/// @note HWMS0_EXIT_1: When set, bypass-enabled reads using this mark will
/// @note use exit 1; otherwise exit 0
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_exit_1( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    io_data.writeBit<TT::HARDWARE_MS_EXIT1>(i_state);
    FAPI_INF("set_exit_1: 0x%01lx", i_state);
}

///
/// @brief get_exit_1
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_state mss::YES or mss::NO - representing the state of the field
/// @note HWMS0_EXIT_1: When set, bypass-enabled reads using this mark will
/// @note use exit 1; otherwise exit 0
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_exit_1( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    o_state = (i_data.getBit<TT::HARDWARE_MS_EXIT1>() == false) ? mss::NO : mss::YES;
    FAPI_INF("get_exit_1: 0x%01lx", o_state);
}

} // close namespace hwms

} // close namespace ecc

} // close namespace mss

#endif
