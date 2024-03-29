/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ecc/hw_mark_store.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_HW_MARK_STORE_H_
#define _MSS_HW_MARK_STORE_H_

#include <fapi2.H>
#include <generic/memory/lib/ecc/ecc_traits.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/ecc/galois.H>

namespace mss
{

namespace ecc
{

namespace hwms
{

///
/// @brief Read Hardware Mark Store (HWMS) register
/// @tparam R master rank number
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t R, mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode read_rank( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert((R < TT::ECC_MAX_MRANK_PER_PORT), "Master rank index failed range check");
    FAPI_TRY( mss::getScom(i_target, (TT::HARDWARE_MS0_REG + R), o_data) );
    FAPI_INF_NO_SBE("read_rank<%d>: 0x%016lx", R, o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 0 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read_rank0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<0, MC>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 1 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read_rank1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<1, MC>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 2 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read_rank2( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<2, MC>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 3 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read_rank3( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<3, MC>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 4 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read_rank4( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<4, MC>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 5 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read_rank5( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<5, MC>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 6 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read_rank6( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<6, MC>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) rank 7 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read_rank7( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    return ( read_rank<7, MC>(i_target, o_data) );
}

///
/// @brief Read Hardware Mark Store (HWMS) register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_port_rank the master rank index
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target,
                               const uint64_t i_port_rank,
                               fapi2::buffer<uint64_t>& o_data )
{
    switch (i_port_rank)
    {
        case(0):
            return ( read_rank0<MC>(i_target, o_data) );

        case(1):
            return ( read_rank1<MC>(i_target, o_data) );

        case(2):
            return ( read_rank2<MC>(i_target, o_data) );

        case(3):
            return ( read_rank3<MC>(i_target, o_data) );

        case(4):
            return ( read_rank4<MC>(i_target, o_data) );

        case(5):
            return ( read_rank5<MC>(i_target, o_data) );

        case(6):
            return ( read_rank6<MC>(i_target, o_data) );

        case(7):
            return ( read_rank7<MC>(i_target, o_data) );

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RANK_PASSED()
                         .set_RANK(i_port_rank)
                         .set_TARGET(i_target)
                         .set_FUNCTION(HWMS_READ),
                         TARGTIDFORMAT " Invalid rank passed to hwms::ecc::hwms::read (%d)",
                         TARGTID,
                         i_port_rank);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write Hardware Mark Store (HWMS) register
/// @tparam R master rank number
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t R, mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode write_rank( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert((R < TT::ECC_MAX_MRANK_PER_PORT), "Master rank index failed range check");
    FAPI_TRY( mss::putScom(i_target, (TT::HARDWARE_MS0_REG + R), i_data) );
    FAPI_INF_NO_SBE("write_rank<%d>: 0x%016lx", R, i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 0 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write_rank0( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<0, MC>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 1 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write_rank1( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<1, MC>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 2 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write_rank2( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<2, MC>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 3 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write_rank3( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<3, MC>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 4 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write_rank4( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<4, MC>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 5 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write_rank5( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<5, MC>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 6 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write_rank6( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<6, MC>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) rank 7 register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write_rank7( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    return ( write_rank<7, MC>(i_target, i_data) );
}

///
/// @brief Write Hardware Mark Store (HWMS) register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_port_rank the master rank index
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target,
                                const uint64_t i_port_rank,
                                const fapi2::buffer<uint64_t>& i_data )
{
    switch (i_port_rank)
    {
        case(0):
            return ( write_rank0<MC>(i_target, i_data) );

        case(1):
            return ( write_rank1<MC>(i_target, i_data) );

        case(2):
            return ( write_rank2<MC>(i_target, i_data) );

        case(3):
            return ( write_rank3<MC>(i_target, i_data) );

        case(4):
            return ( write_rank4<MC>(i_target, i_data) );

        case(5):
            return ( write_rank5<MC>(i_target, i_data) );

        case(6):
            return ( write_rank6<MC>(i_target, i_data) );

        case(7):
            return ( write_rank7<MC>(i_target, i_data) );

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RANK_PASSED()
                         .set_RANK(i_port_rank)
                         .set_TARGET(i_target)
                         .set_FUNCTION(HWMS_WRITE),
                         TARGTIDFORMAT " Invalid rank passed to hwms::ecc::hwms::write(%d)",
                         TARGTID,
                         i_port_rank);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_chipmark
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note HWMS0_CHIPMARK: Hardware chipmark (Galois field code)
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_chipmark( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::HARDWARE_MS_CHIPMARK, TT::HARDWARE_MS_CHIPMARK_LEN>(i_value);
    FAPI_INF_NO_SBE("set_chipmark: 0x%02lx", i_value);
}

///
/// @brief get_chipmark
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note HWMS0_CHIPMARK: Hardware chipmark (Galois field code)
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_chipmark( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::HARDWARE_MS_CHIPMARK, TT::HARDWARE_MS_CHIPMARK_LEN>(o_value);
    FAPI_INF_NO_SBE("get_chipmark: 0x%02lx", o_value);
}

///
/// @brief set_confirmed
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_state mss::YES or mss::NO - desired state
/// @note HWMS0_CONFIRMED: chipmark confirmed
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_confirmed( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    io_data.writeBit<TT::HARDWARE_MS_CONFIRMED>(i_state);
    FAPI_INF_NO_SBE("set_confirmed: 0x%01lx", i_state);
}

///
/// @brief get_confirmed
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_state mss::YES or mss::NO - representing the state of the field
/// @note HWMS0_CONFIRMED: chipmark confirmed
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_confirmed( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    o_state = (i_data.getBit<TT::HARDWARE_MS_CONFIRMED>() == false) ? mss::NO : mss::YES;
    FAPI_INF_NO_SBE("get_confirmed: 0x%01lx", o_state);
}

///
/// @brief set_exit_1
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_state mss::YES or mss::NO - desired state
/// @note HWMS0_EXIT_1: When set, bypass-enabled reads using this mark will
/// @note use exit 1; otherwise exit 0
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_exit_1( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    io_data.writeBit<TT::HARDWARE_MS_EXIT1>(i_state);
    FAPI_INF_NO_SBE("set_exit_1: 0x%01lx", i_state);
}

///
/// @brief get_exit_1
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_state mss::YES or mss::NO - representing the state of the field
/// @note HWMS0_EXIT_1: When set, bypass-enabled reads using this mark will
/// @note use exit 1; otherwise exit 0
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_exit_1( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    o_state = (i_data.getBit<TT::HARDWARE_MS_EXIT1>() == false) ? mss::NO : mss::YES;
    FAPI_INF_NO_SBE("get_exit_1: 0x%01lx", o_state);
}

} // close namespace hwms

///
/// @brief Get Hardware Mark Store
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[in] i_port_rank the desired port rank
/// @param[out] o_galois the Galois code of the mark
/// @param[out] o_confirmed true if the mark is a chipmark
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode get_hwms( const fapi2::Target<T>& i_target,
                            const uint64_t i_port_rank,
                            uint64_t& o_galois,
                            mss::states& o_confirmed )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::hwms::read<MC>(i_target, i_port_rank, l_buffer) );
    mss::ecc::hwms::get_chipmark<MC>(l_buffer, o_galois);
    mss::ecc::hwms::get_confirmed<MC>(l_buffer, o_confirmed);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set Hardware Mark Store
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[in] i_port_rank the desired port rank
/// @param[in] i_galois the Galois code of the mark, or set to 0 to clear mark
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode set_hwms( const fapi2::Target<T>& i_target,
                            const uint64_t i_port_rank,
                            const uint64_t i_galois )
{
    fapi2::buffer<uint64_t> l_buffer;
    uint8_t l_symbol = 0;

    // galois value of 0 means to clear the mark so only fill in fields if non-zero
    if (i_galois != 0)
    {
        // check for valid Galois code
        FAPI_TRY( mss::ecc::galois_to_symbol<MC>( (uint8_t)i_galois, l_symbol) );

        mss::ecc::hwms::set_chipmark<MC>(l_buffer, i_galois);
        mss::ecc::hwms::set_confirmed<MC>(l_buffer, mss::YES);
        mss::ecc::hwms::set_exit_1<MC>(l_buffer, mss::YES);
    }

    FAPI_TRY( mss::ecc::hwms::write<MC>(i_target, i_port_rank, l_buffer) );

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace ecc

} // close namespace mss

#endif
