/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H $ */
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
/// @file gen_mss_mcbist_address.H
/// @brief Class for mcbist related addresses (addresses below the hash translation)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _GEN_MSS_MCBIST_ADDRESS_H_
#define _GEN_MSS_MCBIST_ADDRESS_H_

#include <fapi2.H>
#include <generic/memory/lib/ecc/ecc_traits.H>
#include <generic/memory/lib/utils/mss_pair.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_traits.H>

namespace mss
{

namespace mcbist
{

///
/// @class address
/// @brief Represents a physical address in memory
/// @tparam MC the memory controller type
/// @tparam TT the MCBIST address traits for the controller
///
template <mss::mc_type MC, typename TT = mss::mcbistAddrTraits<MC>>
class address
{
        // first is the start bit of the field, second is the length
        using field = mss::pair<uint64_t, uint64_t>;

    public:
        ///
        /// @brief default ctor
        ///
        address() = default;

        ///
        /// @brief Construct an address from a uint64_t
        /// @param[in] i_value representing an address
        ///
        address( const uint64_t i_value ):
            iv_address(i_value << TT::MAGIC_PAD)
        {
        }

        ///
        /// @brief Construct an address from the provided buffer
        /// @param[in] i_address fapi2::buffer address
        ///
        address(const fapi2::buffer<uint64_t>& i_address):
            iv_address(i_address)
        {
        }

        ///
        /// @brief Conversion operator to uint64_t
        /// @warn Right-aligns the address
        ///
        inline operator uint64_t() const
        {
            return iv_address >> TT::MAGIC_PAD;
        }

        ///
        /// @brief Set a field for an address
        /// @tparam F the field to set
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        template< const field& F >
        inline address<MC>& set_field( const uint64_t i_value )
        {
            iv_address.insertFromRight<F.first, F.second>(i_value);
            return *this;
        }

        ///
        /// @brief Get a field from an address
        /// @tparam F the field to get
        /// @return right-aligned uint64_t representing the value
        ///
        template< const field& F >
        inline uint64_t get_field() const
        {
            uint64_t l_value = 0;
            iv_address.extractToRight<F.first, F.second>(l_value);
            return l_value;
        }

        ///
        /// @brief Get a range of addresses.
        /// @tparam[in] F the left-most valid field. So, if the address was for master rank,
        /// the left-most valid field would be MRANK
        /// @param[out] o_end representing an address to end at
        /// @note this pointer is the start address
        ///
        template< const field& F >
        inline void get_range( address<MC>& o_end ) const
        {
            constexpr uint64_t START = F.first + F.second;
            constexpr uint64_t LEN = (TT::LAST_VALID.first + TT::LAST_VALID.second) - START;

            // All we need to do is fill in the bits to the right of the last valid field
            o_end.iv_address = iv_address;
            o_end.iv_address.template setBit<START, LEN>();
        }


        ///
        /// @brief Get an end address for sim mode
        /// @param[out] o_end representing an address to end at
        /// @note this pointer is the start address
        ///
        inline void get_sim_end_address( address<MC>& o_end ) const
        {
            get_range<TT::COL>(o_end);
            o_end.set_column(TT::SIM_ECC_RANGE);
            return;
        }

        ///
        /// @brief Get a range of addresses given a master rank
        /// @param[in] i_start representing an address to start from
        /// @param[out] o_end representing an address to end at
        ///
        inline static void get_mrank_range( const address<MC>& i_start, address<MC>& o_end )
        {
            i_start.template get_range<TT::MRANK>(o_end);
        }

        ///
        /// @brief Get a range of addresses given a master rank
        /// @param[in] i_port representing the port for the starting address
        /// @param[in] i_dimm representing the dimm for the starting address
        /// @param[in] i_mrank representing the master rank for the starting address
        /// @param[out] o_start representing an address to start from
        /// @param[out] o_end representing an address to end at
        ///
        inline static void get_mrank_range( const uint64_t i_port,
                                            const uint64_t i_dimm,
                                            const uint64_t i_mrank,
                                            address<MC>& o_start,
                                            address<MC>& o_end )
        {
            o_start.set_port(i_port).set_dimm(i_dimm).set_master_rank(i_mrank);
            get_mrank_range(o_start, o_end);
        }

        ///
        /// @brief Get a range of addresses given a slave rank
        /// @param[in] i_start representing an address to start from
        /// @param[out] o_end representing an address to end at
        ///
        inline static void get_srank_range( const address<MC>& i_start, address<MC>& o_end )
        {
            i_start.template get_range<TT::SRANK>(o_end);
        }

        ///
        /// @brief Get a range of addresses given a slave rank
        /// @param[in] i_port representing the port for the starting address
        /// @param[in] i_dimm representing the dimm for the starting address
        /// @param[in] i_mrank representing the master rank for the starting address
        /// @param[in] i_srank representing the slave rank for the starting address
        /// @param[out] o_start representing an address to start from
        /// @param[out] o_end representing an address to end at
        ///
        inline static void get_srank_range( const uint64_t i_port, const uint64_t i_dimm,
                                            const uint64_t i_mrank, const uint64_t i_srank,
                                            address<MC>& o_start,
                                            address<MC>& o_end )
        {
            o_start.set_port(i_port).set_dimm(i_dimm).set_master_rank(i_mrank).set_slave_rank(i_srank);
            get_srank_range(o_start, o_end);
        }

        ///
        /// @brief Set the port value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address<MC>& set_port( const uint64_t i_value )
        {
            return set_field<TT::PORT>(i_value);
        }

        ///
        /// @brief Get the port value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_port() const
        {
            return get_field<TT::PORT>();
        }

        ///
        /// @brief Set the DIMM value for an address
        /// @param[in] i_value the value to set
        /// @note 0 is the DIMM[0] != 0 is DIMM[1]
        /// @return address& for method chaining
        ///
        address<MC>& set_dimm( const uint64_t i_value );

        ///
        /// @brief Get the DIMM value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        uint64_t get_dimm() const;

        ///
        /// @brief Set the port and DIMM value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        /// @note Useful for indexing all ports/DIMM on a controller
        ///
        address<MC>& set_port_dimm( const fapi2::buffer<uint64_t> i_value );

        ///
        /// @brief Get the port and DIMM value for an address
        /// @return right-aligned uint64_t representing the value
        /// @note Useful for indexing all ports/DIMM on a controller
        ///
        uint64_t get_port_dimm() const;

        ///
        /// @brief Set the master rank value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address<MC>& set_master_rank( const uint64_t i_value )
        {
            return set_field<TT::MRANK>(i_value);
        }

        ///
        /// @brief Get the master rank value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_master_rank() const
        {
            return get_field<TT::MRANK>();
        }


        ///
        /// @brief Set the slave rank value for an address
        /// @param[in] i_value the value to set
        ///
        inline void set_slave_rank( const uint64_t i_value )
        {
            set_field<TT::SRANK>(i_value);
        }

        ///
        /// @brief Get the slave rank value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_slave_rank() const
        {
            return get_field<TT::SRANK>();
        }


        ///
        /// @brief Set the row value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address<MC>& set_row( const uint64_t i_value )
        {
            return set_field<TT::ROW>(i_value);
        }

        ///
        /// @brief Get the row value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_row() const
        {
            return get_field<TT::ROW>();
        }


        ///
        /// @brief Set the column value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address<MC>& set_column( const uint64_t i_value )
        {
            return set_field<TT::COL>(i_value);
        }

        ///
        /// @brief Get the column value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_column() const
        {
            return get_field<TT::COL>();
        }


        ///
        /// @brief Set the bank value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address<MC>& set_bank( const uint64_t i_value )
        {
            return set_field<TT::BANK>(i_value);
        }

        ///
        /// @brief Get the bank value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_bank() const
        {
            return get_field<TT::BANK>();
        }

        ///
        /// @brief Set the bank group value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address<MC>& set_bank_group( const uint64_t i_value )
        {
            return set_field<TT::BANK_GROUP>(i_value);
        }

        ///
        /// @brief Get the bank group value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_bank_group() const
        {
            return get_field<TT::BANK_GROUP>();
        }

        ///
        /// @brief Get the buffer object for bit operations
        /// @return fapi2::buffer<uint64_t>&
        ///
        inline fapi2::buffer<uint64_t> get_address_buffer() const
        {
            return iv_address;
        }

    private:
        // We use a fapi2 buffer as it has static compile-time support
        fapi2::buffer<uint64_t> iv_address;
};

} // close namespace mcbist
} // close namespace mss

#endif
