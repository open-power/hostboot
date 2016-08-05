/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ecc/fw_mark_store.H $ */
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
/// @file fw_mark_store.H
/// @brief Subroutines for the MC firmware mark store registers
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_FW_MARK_STORE_H_
#define _MSS_FW_MARK_STORE_H_

#include <fapi2.H>
#include <lib/mcbist/address.H>
#include <lib/utils/scom.H>
#include <lib/ecc/ecc_traits.H>
#include <lib/shared/mss_const.H>

namespace mss
{

namespace ecc
{

namespace fwms
{

enum mark_type
{
    SYMBOL = 1,
    CHIP = 0
};

enum mark_region
{
    DISABLED = 0b000,
    RESERVED = 0b001,
    BANK = 0b010,
    BANKGROUP = 0b011,
    SRANK = 0b100,
    MRANK = 0b101,
    DIMM = 0b110,
    UNIVERSAL = 0b111
};

///
/// @brief Read Firmware Mark Store (FWMS) register
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
    FAPI_TRY( mss::getScom(i_target, (TT::FIRMWARE_MS0_REG + R), o_data) );
    FAPI_INF("read_rank<%d>: 0x%016lx", R, o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read Firmware Mark Store (FWMS) rank 0 register
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
/// @brief Read Firmware Mark Store (FWMS) rank 1 register
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
/// @brief Read Firmware Mark Store (FWMS) rank 2 register
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
/// @brief Read Firmware Mark Store (FWMS) rank 3 register
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
/// @brief Read Firmware Mark Store (FWMS) rank 4 register
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
/// @brief Read Firmware Mark Store (FWMS) rank 5 register
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
/// @brief Read Firmware Mark Store (FWMS) rank 6 register
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
/// @brief Read Firmware Mark Store (FWMS) rank 7 register
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
/// @brief Read Firmware Mark Store (FWMS) register
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
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }
}

///
/// @brief Write Firmware Mark Store (FWMS) register
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
    FAPI_TRY( mss::putScom(i_target, (TT::FIRMWARE_MS0_REG + R), i_data) );
    FAPI_INF("write_rank<%d>: 0x%016lx", R, i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write Firmware Mark Store (FWMS) rank 0 register
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
/// @brief Write Firmware Mark Store (FWMS) rank 1 register
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
/// @brief Write Firmware Mark Store (FWMS) rank 2 register
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
/// @brief Write Firmware Mark Store (FWMS) rank 3 register
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
/// @brief Write Firmware Mark Store (FWMS) rank 4 register
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
/// @brief Write Firmware Mark Store (FWMS) rank 5 register
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
/// @brief Write Firmware Mark Store (FWMS) rank 6 register
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
/// @brief Write Firmware Mark Store (FWMS) rank 7 register
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
/// @brief Write Firmware Mark Store (FWMS) register
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
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }
}

///
/// @brief set_mark
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note FWMS0_MARK: mark (Galois field code)
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_mark( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::FIRMWARE_MS_MARK, TT::FIRMWARE_MS_MARK_LEN>(i_value);
    FAPI_INF("set_mark: 0x%02lx", i_value);
}

///
/// @brief get_mark
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note FWMS0_MARK: mark (Galois field code)
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_mark( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::FIRMWARE_MS_MARK, TT::FIRMWARE_MS_MARK_LEN>(o_value);
    FAPI_INF("get_mark: 0x%02lx", o_value);
}

///
/// @brief set_type
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note FWMS0_TYPE: mark type
/// @note Dial enums:
/// @note SYMBOL=>0b1
/// @note CHIP=>0b0
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_type( fapi2::buffer<uint64_t>& io_data, const mark_type i_value )
{
    io_data.writeBit<TT::FIRMWARE_MS_TYPE>(i_value);
    FAPI_INF("set_type: 0x%01lx", i_value);
}

///
/// @brief get_type
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note FWMS0_TYPE: mark type
/// @note Dial enums:
/// @note SYMBOL=>0b1
/// @note CHIP=>0b0
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_type( const fapi2::buffer<uint64_t>& i_data, mark_type& o_value )
{
    o_value = mark_type(i_data.getBit<TT::FIRMWARE_MS_TYPE>());
    FAPI_INF("get_type: 0x%01lx", o_value);
}

///
/// @brief set_region
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note FWMS0_REGION: Selects mark region (address range to which mark applies)
/// @note Dial enums:
/// @note DISABLED=>0b000
/// @note RESERVED=>0b001
/// @note BANK=>0b010
/// @note BANKGROUP=>0b011
/// @note SRANK=>0b100
/// @note MRANK=>0b101
/// @note DIMM=>0b110
/// @note UNIVERSAL=>0b111
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_region( fapi2::buffer<uint64_t>& io_data, const mark_region i_value )
{
    io_data.insertFromRight<TT::FIRMWARE_MS_REGION, TT::FIRMWARE_MS_REGION_LEN>(i_value);
    FAPI_INF("set_region: 0x%02lx", i_value);
}

///
/// @brief get_region
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note FWMS0_REGION: Selects mark region (address range to which mark applies)
/// @note Dial enums:
/// @note DISABLED=>0b000
/// @note RESERVED=>0b001
/// @note BANK=>0b010
/// @note BANKGROUP=>0b011
/// @note SRANK=>0b100
/// @note MRANK=>0b101
/// @note DIMM=>0b110
/// @note UNIVERSAL=>0b111
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_region( const fapi2::buffer<uint64_t>& i_data, mark_region& o_value )
{
    uint64_t l_temp = 0;
    i_data.extractToRight<TT::FIRMWARE_MS_REGION, TT::FIRMWARE_MS_REGION_LEN>(l_temp);
    o_value = mark_region(l_temp);
    FAPI_INF("get_region: 0x%02lx", o_value);
}

///
/// @brief set_address
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_address mcbist::address form of address field
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_address( fapi2::buffer<uint64_t>& io_data, const mcbist::address& i_address)
{
    // construct fwms::address from mcbist::address
    const auto l_addr = address<T>(i_address);
    io_data.insert<TT::FIRMWARE_MS_ADDRESS, TT::FIRMWARE_MS_ADDRESS_LEN, TT::FIRMWARE_MS_ADDRESS>(l_addr);
    FAPI_INF("set_address: 0x%016lx", uint64_t(l_addr));
}

///
/// @brief get_address
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_address mcbist::address form of address field
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_address( const fapi2::buffer<uint64_t>& i_data, mcbist::address& o_address )
{
    // construct fwms::address from i_data
    const auto l_addr = address<T>(uint64_t(i_data));
    // construct mcbist::address from fwms::address
    o_address = mcbist::address(l_addr);
    FAPI_INF("get_address: 0x%016lx", uint64_t(l_addr));
}

///
/// @brief set_exit_1
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_state mss::YES or mss::NO - desired state
/// @note FWMS0_EXIT_1: When set, bypass-enabled reads using this mark will use exit 1
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_exit_1( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    io_data.writeBit<TT::FIRMWARE_MS_EXIT1>(i_state);
    FAPI_INF("set_exit_1: 0x%01lx", i_state);
}

///
/// @brief get_exit_1
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_state mss::YES or mss::NO - representing the state of the field
/// @note FWMS0_EXIT_1: When set, bypass-enabled reads using this mark will use exit 1
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_exit_1( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    o_state = (i_data.getBit<TT::FIRMWARE_MS_EXIT1>() == false) ? mss::NO : mss::YES;
    FAPI_INF("get_exit_1: 0x%01lx", o_state);
}

} // close namespace fwms

} // close namespace ecc

} // close namespace mss

#endif
