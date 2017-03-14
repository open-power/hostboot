/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/xlate.H $    */
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
/// @file xmalte.H
/// @brief Definitions for translation registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_XLT_H_
#define _MSS_XLT_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/dimm/kind.H>

namespace mss
{

namespace mc
{

enum xlate_bit_maps
{
    PORT_ADDRESS_0 = 0b00000, ///< bitmap for PORT ADDRESS 0
    PORT_ADDRESS_1 = 0b00001, ///< bitmap for PORT ADDRESS 1
    PORT_ADDRESS_2 = 0b00010, ///< bitmap for PORT ADDRESS 2
    PORT_ADDRESS_3 = 0b00011, ///< bitmap for PORT ADDRESS 3
    PORT_ADDRESS_4 = 0b00100, ///< bitmap for PORT ADDRESS 4
    PORT_ADDRESS_5 = 0b00101, ///< bitmap for PORT ADDRESS 5
    PORT_ADDRESS_6 = 0b00110, ///< bitmap for PORT ADDRESS 6
    PORT_ADDRESS_7 = 0b00111, ///< bitmap for PORT ADDRESS 7

    PORT_ADDRESS_22 = 0b01000, ///< bitmap for PORT ADDRESS 22
    PORT_ADDRESS_23 = 0b01001, ///< bitmap for PORT ADDRESS 23
    PORT_ADDRESS_24 = 0b01010, ///< bitmap for PORT ADDRESS 24
    PORT_ADDRESS_25 = 0b01011, ///< bitmap for PORT ADDRESS 25
    PORT_ADDRESS_26 = 0b01100, ///< bitmap for PORT ADDRESS 26
    PORT_ADDRESS_27 = 0b01101, ///< bitmap for PORT ADDRESS 27
    PORT_ADDRESS_28 = 0b01110, ///< bitmap for PORT ADDRESS 28
    PORT_ADDRESS_29 = 0b01111, ///< bitmap for PORT ADDRESS 29
    PORT_ADDRESS_30 = 0b10000, ///< bitmap for PORT ADDRESS 30
    PORT_ADDRESS_31 = 0b10001, ///< bitmap for PORT ADDRESS 31
    PORT_ADDRESS_32 = 0b10010, ///< bitmap for PORT ADDRESS 32
};

enum rows
{
    ROW15, ///< represents xlate R15
    ROW16, ///< represents xlate R16
    ROW17, ///< represents xlate R17
};

enum xlate_ranks
{
    // Master ranks
    M0, ///< xlate Master rank 0
    M1, ///< xlate Master rank 1

    //  Slave ranks
    S0, ///< xlate Slave rank 0
    S1, ///< xlate Slave rank 1
    S2, ///< xlate Slave rank 2
};

///
/// @class rowTraits
/// @brief a collection of traits associated with the row xlate registers
/// @tparam T rows enumeration to represent xlate row bits
///
template< rows T >
class rowTraits;

///
/// @class rowTraits
/// @brief a collection of traits associated with the row xlate registers
///
template< >
class rowTraits<ROW15>
{
    public:
        static constexpr uint64_t ROW = 15;
        static constexpr uint64_t  MAX_MAP_VALUE = PORT_ADDRESS_7;

        enum
        {
            SLOT0_ROW_VALID = MCS_PORT02_MCP0XLT0_SLOT0_ROW15_VALID,
            ROW_BIT_MAP = MCS_PORT02_MCP0XLT0_R15_BIT_MAP,
            ROW_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_R15_BIT_MAP_LEN,
        };
};

///
/// @class rowTraits
/// @brief a collection of traits associated with the row xlate registers
///
template< >
class rowTraits<ROW16>
{
    public:
        static constexpr uint64_t ROW = 16;
        static constexpr uint64_t  MAX_MAP_VALUE = PORT_ADDRESS_7;

        enum
        {
            SLOT0_ROW_VALID = MCS_PORT02_MCP0XLT0_SLOT0_ROW16_VALID,
            ROW_BIT_MAP = MCS_PORT02_MCP0XLT0_R16_BIT_MAP,
            ROW_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_R16_BIT_MAP_LEN,
        };
};

///
/// @class rowTraits
/// @brief a collection of traits associated with the row xlate registers
///
template< >
class rowTraits<ROW17>
{
    public:
        static constexpr uint64_t ROW = 17;
        static constexpr uint64_t  MAX_MAP_VALUE = PORT_ADDRESS_7;

        enum
        {
            SLOT0_ROW_VALID = MCS_PORT02_MCP0XLT0_SLOT0_ROW17_VALID,
            ROW_BIT_MAP = MCS_PORT02_MCP0XLT0_R17_BIT_MAP,
            ROW_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_R17_BIT_MAP_LEN,
        };
};

///
/// @brief Sets row bits on the xlate register
/// @tparam T row enumerations to represent xlate master row bits
/// @tparam TT traits type defaults to rowTraits<T>
/// @param[in] i_map value to set master rank bit map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
template< rows T, typename TT = rowTraits<T> >
inline fapi2::ReturnCode set_xlate_row(const uint64_t i_map,
                                       const uint64_t i_offset,
                                       fapi2::buffer<uint64_t>& io_xlate0)
{
    if( i_map > TT::MAX_MAP_VALUE)
    {
        FAPI_ERR("Received a map value (%d) greater than the max value allowed by MCP0XLT0_R%d_BIT_MAP (%d)",
                 i_map, TT::ROW, TT::MAX_MAP_VALUE);

        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    FAPI_TRY( io_xlate0.setBit( TT::SLOT0_ROW_VALID + i_offset ) );
    io_xlate0.insertFromRight<TT::ROW_BIT_MAP, TT::ROW_BIT_MAP_LEN>(i_map);

    FAPI_DBG( "Set MCP0XLT0_SLOT%d_ROW%d_VALID at bit %d. "
              "Set bits for MCP0XLT0_R%d_BIT_MAP with 0x%lx (start: %d, len: %d). "
              "MCP0XLT0: 0x%016lx.",
              (i_offset == 0 ? 0 : 1), TT::ROW, TT::SLOT0_ROW_VALID + i_offset, TT::ROW,
              i_map, TT::ROW_BIT_MAP, TT::ROW_BIT_MAP_LEN,
              uint64_t(io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @class mrankTraits
/// @brief a collection of traits associated with the master rank xlate registers
/// @tparam T rank enumerations to represent xlate master rank bits
///
template < xlate_ranks T >
class mrankTraits;

///
/// @class mrankTraits
/// @brief a collection of traits associated with the master rank xlate registers
///
template< >
class mrankTraits<M0>
{
    public:
        static constexpr uint64_t RANK = 0;
        static constexpr uint64_t CLEAR_MAP = PORT_ADDRESS_0;
        static constexpr uint64_t  MAX_MAP_VALUE = PORT_ADDRESS_7;
        enum
        {
            SLOT0_VALID = MCS_PORT13_MCP0XLT0_SLOT0_M0_VALID,
            BIT_MAP = MCS_PORT02_MCP0XLT0_M0_BIT_MAP,
            BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_M0_BIT_MAP_LEN,
        };
};

///
/// @class mrankTraits
/// @brief a collection of traits associated with the master rank xlate registers
///
template< >
class mrankTraits<M1>
{
    public:
        static constexpr uint64_t RANK = 1;
        static constexpr uint64_t CLEAR_MAP = PORT_ADDRESS_0;
        static constexpr uint64_t  MAX_MAP_VALUE = PORT_ADDRESS_32;

        enum
        {
            SLOT0_VALID = MCS_PORT13_MCP0XLT0_SLOT0_M1_VALID,
            BIT_MAP = MCS_PORT02_MCP0XLT0_M1_BIT_MAP,
            BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_M1_BIT_MAP_LEN,
        };
};

///
/// @brief Sets master rank bits on the xlate register
/// @tparam T rank enumerations to represent xlate master rank bits
/// @tparam TT traits type defaults to mrankTraits<T>
/// @param[in] i_map value to set master rank bit map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
template< xlate_ranks T, typename TT = mrankTraits<T> >
inline fapi2::ReturnCode set_xlate_mrank(const uint64_t i_map,
        const uint64_t i_offset,
        fapi2::buffer<uint64_t>& io_xlate0)
{
    if( i_map > TT::MAX_MAP_VALUE)
    {
        FAPI_ERR("Received a map value (%d) greater than the max value allowed by MCP0XLT0_M%d_BIT_MAP (%d)",
                 i_map, TT::RANK, TT::MAX_MAP_VALUE);

        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    FAPI_TRY( io_xlate0.setBit(TT::SLOT0_VALID + i_offset) );
    io_xlate0.insertFromRight<TT::BIT_MAP, TT::BIT_MAP_LEN>(i_map);

    FAPI_DBG("Set MCP0XLT0_SLOT%d_M%d_VALID at bit %d. Set MCP0XLT0_M%d_BIT_MAP with 0x%lx (start: %d, len: %d). "
             "MCP0XLT0: 0x%016lx.",
             (i_offset == 0 ? 0 : 1), TT::RANK, TT::SLOT0_VALID + i_offset,
             TT::RANK, uint64_t(i_map), TT::BIT_MAP, TT::BIT_MAP_LEN,
             uint64_t(io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clears master rank bits on the xlate register
/// @tparam T rank enumerations to represent xlate master rank bits
/// @tparam TT traits type defaults to mrankTraits<T>
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
template< xlate_ranks T, typename TT = mrankTraits<T> >
inline fapi2::ReturnCode clear_xlate_mrank(const uint64_t i_offset,
        fapi2::buffer<uint64_t>& io_xlate0)
{
    FAPI_TRY( io_xlate0.clearBit(TT::SLOT0_VALID + i_offset) );
    io_xlate0.insertFromRight<TT::BIT_MAP, TT::BIT_MAP_LEN>(TT::CLEAR_MAP);

    FAPI_DBG("Set MCP0XLT0_SLOT%d_M%d_VALID at bit %d. Set MCP0XLT0_M%d_BIT_MAP with 0x%lx (start: %d, len: %d). "
             "MCP0XLT0: 0x%016lx.",
             (i_offset == 0 ? 0 : 1), TT::RANK, TT::SLOT0_VALID + i_offset,
             TT::RANK, TT::CLEAR_MAP, TT::BIT_MAP, TT::BIT_MAP_LEN,
             uint64_t(io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @class srankTraits
/// @brief a collection of traits associated with the slave rank xlate registers
/// @tparam T rank enumerations to represent xlate slave rank bits
///
template < xlate_ranks T >
class srankTraits;

///
/// @class srankTraits
/// @brief a collection of traits associated with the slave rank xlate registers
/// for slave rank 0
///
template< >
class srankTraits<S0>
{
    public:
        static constexpr uint64_t RANK = 0;
        static constexpr uint64_t CLEAR_MAP = PORT_ADDRESS_0;
        static constexpr uint64_t  MAX_MAP_VALUE = PORT_ADDRESS_32;

        enum
        {
            SLOT0_VALID = MCS_PORT13_MCP0XLT0_SLOT0_S0_VALID,
            BIT_MAP = MCS_PORT02_MCP0XLT1_S0_BIT_MAP,
            BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_S0_BIT_MAP_LEN,
        };
};

///
/// @class srankTraits
/// @brief a collection of traits associated with the slave rank xlate registers
/// for slave rank 1
///
template< >
class srankTraits<S1>
{
    public:
        static constexpr uint64_t RANK = 1;
        static constexpr uint64_t CLEAR_MAP = PORT_ADDRESS_0;
        static constexpr uint64_t  MAX_MAP_VALUE = PORT_ADDRESS_32;

        enum
        {
            SLOT0_VALID = MCS_PORT13_MCP0XLT0_SLOT0_S1_VALID,
            BIT_MAP = MCS_PORT02_MCP0XLT1_S1_BIT_MAP,
            BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_S1_BIT_MAP_LEN,
        };
};

///
/// @class srankTraits
/// @brief a collection of traits associated with the slave rank xlate registers
/// for slave rank 2
///
template< >
class srankTraits<S2>
{
    public:
        static constexpr uint64_t RANK = 2;
        static constexpr uint64_t CLEAR_MAP = PORT_ADDRESS_0;
        static constexpr uint64_t  MAX_MAP_VALUE = PORT_ADDRESS_32;

        enum
        {
            SLOT0_VALID = MCS_PORT13_MCP0XLT0_SLOT0_S2_VALID,
            BIT_MAP = MCS_PORT02_MCP0XLT1_S2_BIT_MAP,
            BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_S2_BIT_MAP_LEN,
        };
};

///
/// @brief Sets slave rank bits on the xlate register
/// @tparam T rank enumerations to represent xlate slave rank bits
/// @tparam TT traits type defaults to srankTraits<T>
/// @param[in] i_map value to set slave rank bit map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
template< xlate_ranks T, typename TT = srankTraits<T> >
inline fapi2::ReturnCode set_xlate_srank(const uint64_t i_map,
        const uint64_t i_offset,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1)
{
    if( i_map > TT::MAX_MAP_VALUE)
    {
        FAPI_ERR("Received a map value (%d) greater than the max value allowed by MCP0XLT0_S%d_BIT_MAP (%d)",
                 i_map, TT::RANK, TT::MAX_MAP_VALUE);

        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    FAPI_TRY( io_xlate0.setBit(TT::SLOT0_VALID + i_offset) );
    io_xlate1.insertFromRight<TT::BIT_MAP, TT::BIT_MAP_LEN>(i_map);

    FAPI_DBG("Set MCP0XLT0_SLOT%d_S%d_VALID at bit %d. Set MCP0XLT0_S%d_BIT_MAP with 0x%lx (start: %d, len: %d). "
             "MCP0XLT0: 0x%016lx, MCP0XLT1: 0x%016lx.",
             (i_offset == 0 ? 0 : 1), TT::RANK, TT::SLOT0_VALID + i_offset,
             TT::RANK, uint64_t(i_map), TT::BIT_MAP, TT::BIT_MAP_LEN,
             uint64_t(io_xlate0), uint64_t(io_xlate1) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clears slave rank bits on the xlate register
/// @tparam T rank enumerations to represent xlate slave rank bits
/// @tparam TT traits type defaults to srankTraits<T>
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
template< xlate_ranks T, typename TT = srankTraits<T> >
inline fapi2::ReturnCode clear_xlate_srank(const uint64_t i_offset,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1)
{
    FAPI_TRY( io_xlate0.clearBit(TT::SLOT0_VALID + i_offset) );
    io_xlate1.insertFromRight<TT::BIT_MAP, TT::BIT_MAP_LEN>(TT::CLEAR_MAP);

    FAPI_DBG("Set MCP0XLT0_SLOT%d_S%d_VALID at bit %d. Set MCP0XLT0_S%d_BIT_MAP with 0x%lx (start: %d, len: %d). "
             "MCP0XLT0: 0x%016lx, MCP0XLT1: 0x%016lx.",
             (i_offset == 0 ? 0 : 1), TT::RANK, TT::SLOT0_VALID + i_offset,
             TT::RANK, TT::CLEAR_MAP, TT::BIT_MAP, TT::BIT_MAP_LEN,
             uint64_t(io_xlate0), uint64_t(io_xlate1) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set DIMM slot bits
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode set_xlate_dimm_slot(const uint64_t i_offset,
        fapi2::buffer<uint64_t>& io_xlate0)
{
    FAPI_TRY( io_xlate0.setBit(MCS_PORT02_MCP0XLT0_SLOT0_VALID + i_offset) );

    FAPI_DBG("Set MCP0XLT0_SLOT%d_VALID at bit %d. MCP0XLT0: 0x%016lx.",
             (i_offset == 0 ? 0 : 1), MCS_PORT02_MCP0XLT0_SLOT0_VALID + i_offset, uint64_t(io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief A small class to represent the setup of a translation register based on DIMM characteristics
///
struct xlate_setup
{
    ///
    /// @brief Constructor to make a translation register setup structure.
    /// @param[in] i_kind a DIMM kind structure representing the ... err... kind of DIMM
    /// @param[in] i_func a function pointer to a function which does the configuring
    ///
    xlate_setup( const dimm::kind i_kind,
                 fapi2::ReturnCode (*i_func)( const dimm::kind&, const uint64_t, const bool,
                         fapi2::buffer<uint64_t>&, fapi2::buffer<uint64_t>&, fapi2::buffer<uint64_t>& ) ):
        iv_kind(i_kind),
        iv_func(i_func)
    {
    }

    // Keep around the kind of DIMM this nugget represents
    dimm::kind iv_kind;

    // The function to call to setup the translation registers to setup for our DIMM kind.
    fapi2::ReturnCode (*iv_func)( const dimm::kind&, const uint64_t, const bool,
                                  fapi2::buffer<uint64_t>&, fapi2::buffer<uint64_t>&, fapi2::buffer<uint64_t>& );
};

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R2T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R2T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R2T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R4T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R4T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R4T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R8T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R8T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R8T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R16T4Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R16T8Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R16T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R1T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R1T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R1T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R2T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R2T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R2T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R4T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R4T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R4T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R8T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R8T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R8T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_4R4T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_4R4T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_4R4T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Helper to setup the translation map - useful for testing
/// @param[in] i_dimm_kinds std::vector of DIMM kind's representing the DIMM (Not const as we sort the vector)
/// @param[out] fapi2::buffer<uint64_t> o_xlate0  - xlt register 0's value
/// @param[out] fapi2::buffer<uint64_t> o_xlate1  - xlt register 1's value
/// @param[out] fapi2::buffer<uint64_t> o_xlate2  - xlt register 2's value
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_xlate_map_helper( std::vector<dimm::kind>& i_dimm_kinds,
        fapi2::buffer<uint64_t>& o_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R1T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2 total ranks 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R2T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R1T8Gbx8( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 16Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R1T16Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 8Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R2T8Gbx8( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 16Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R2T16Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 8Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R4T8Gbx8( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 16Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R4T16Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 8Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R8T8Gbx8( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 16Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R8T16Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R8Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R2T8Gbx8( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R16Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R2T16Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 8Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R4T8Gbx8( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 16Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R4T16Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 8Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R8T8Gbx8( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 16Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R8T16Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 8Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R16T8Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 16Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R16T16Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_4R4T8Gbx8( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 16Gbx8 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_4R4T16Gbx8( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );
} // ns mc
} // ns mss

#endif
