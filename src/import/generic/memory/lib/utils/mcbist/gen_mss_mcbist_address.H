/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H $ */
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
/// @file gen_mss_mcbist_address.H
/// @brief Class for mcbist related addresses (addresses below the hash translation)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _GEN_MSS_MCBIST_ADDRESS_H_
#define _GEN_MSS_MCBIST_ADDRESS_H_

#include <fapi2.H>
#include <utility>


namespace mss
{

// Forward declaration

///
/// @class mcbistMCTraits
/// @tparam MC the mc type
/// @brief A MC to MC_TARGET_TYPE mapping
///
template< mss::mc_type MC >
class mcbistMCTraits;

///
/// @class mcbistTraits
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @brief a collection of traits associated with the MCBIST engine or hardware
///
template< mss::mc_type MC, fapi2::TargetType T >
class mcbistTraits;

namespace ecc
{

///
/// @class trap_address
/// @brief Converts trap address into mcbist::address
/// @tparam MC the mc type of the T
/// @tparam T fapi2 Target Type defaults to fapi2::TARGET_TYPE_MCA or TARGET_TYPE_MEM_PORT
/// @tparam TT traits type defaults to eccTraits<T>
///
// See declaration below
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T = mss::mcbistMCTraits<MC>::FWMS_ADDR_TARGET_TYPE, typename TT = mss::eccTraits<T> >
class trap_address;

namespace fwms
{

///
/// @class address
/// @brief Converts Firmware Mark Store ADDRESS field into mcbist::address
/// @tparam MC the mc type of the T
/// @tparam T fapi2 Target Type defaults to fapi2::TARGET_TYPE_MCA or TARGET_TYPE_MEM_PORT
/// @tparam TT traits type defaults to eccTraits<T>
/// @note template argument defaults are in forward declaration in lib/mcbist/address.H
/// @note 12 = dimm
/// @note 13:14 = mrank
/// @note 15:17 = srank
/// @note 18:19 = bank group
/// @note 20:22 = bank
///
// See declaration below
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T = mss::mcbistMCTraits<MC>::FWMS_ADDR_TARGET_TYPE, typename TT = mss::eccTraits<T> >
class address;

} // close namespace fwms
} // close namespace ecc

namespace mcbist
{

///
/// @class address
/// @brief Represents a physical address in memory
/// @note
/// 0:1   port select
/// 2     dimm select
/// 3:4   mrank(0 to 1)
/// 5:7   srank(0 to 2)
/// 8:25  row(0 to 17)
/// 26:32 col(3 to 9)
/// 33:35 bank(0 to 2)
/// 36:37 bank_group(0 to 1)
///
class address
{
    public:

        // How far over we shift to align the address in either the register or a buffer
        static constexpr uint64_t MAGIC_PAD = 26;

        // first is the start bit of the field, second is the length
        using field = std::pair<uint64_t, uint64_t>;

        constexpr static field PORT = {0, 2};
        constexpr static field DIMM = {2, 1};
        constexpr static field MRANK = {3, 2};
        constexpr static field SRANK = {5, 3};
        constexpr static field ROW = {8, 18};
        constexpr static field COL = {26, 7};
        constexpr static field BANK = {33, 3};
        constexpr static field BANK_GROUP = {36, 2};
        constexpr static field LAST_VALID = BANK_GROUP;

        ///
        /// @brief default ctor
        ///
        address() = default;

        // Used when accessing an integral value containing a port and DIMM combination
        static constexpr uint64_t DIMM_BIT = 63;
        static constexpr uint64_t PORT_START = 61;
        static constexpr uint64_t PORT_LEN = 2;

        ///
        /// @brief Construct an address from a uint64_t
        /// @param[in] i_value representing an address
        ///
        address( const uint64_t i_value ):
            iv_address(i_value << MAGIC_PAD)
        {
        }

        ///
        /// @brief Construct an address from an ecc::trap_address
        /// @tparam MC the mc type
        /// @param[in] i_address representing an address field from a trap address
        ///
        template< mss::mc_type MC = DEFAULT_MC_TYPE >
        address( const ecc::trap_address<MC>& i_address )
        {
            this->set_field<PORT      >(i_address.template get_field<ecc::trap_address<MC>::PORT>());
            this->set_field<DIMM      >(i_address.template get_field<ecc::trap_address<MC>::DIMM>());
            this->set_field<MRANK     >(i_address.template get_field<ecc::trap_address<MC>::MRANK>());
            this->set_field<SRANK     >(i_address.template get_field<ecc::trap_address<MC>::SRANK>());
            this->set_field<ROW       >(i_address.template get_field<ecc::trap_address<MC>::ROW>());
            this->set_field<COL       >(i_address.template get_field<ecc::trap_address<MC>::COL>());
            this->set_field<BANK      >(i_address.template get_field<ecc::trap_address<MC>::BANK>());
            this->set_field<BANK_GROUP>(i_address.template get_field<ecc::trap_address<MC>::BANK_GROUP>());
        }

        ///
        /// @brief Construct an address from an ecc::fwms::address
        /// @tparam MC the mc type
        /// @param[in] i_address representing an address field from a firmware mark store register
        ///
        template< mss::mc_type MC = DEFAULT_MC_TYPE >
        address( const ecc::fwms::address<MC>& i_address )
        {
            this->set_field<DIMM      >(i_address.template get_field<ecc::fwms::address<MC>::DIMM>());
            this->set_field<MRANK     >(i_address.template get_field<ecc::fwms::address<MC>::MRANK>());
            this->set_field<SRANK     >(i_address.template get_field<ecc::fwms::address<MC>::SRANK>());
            this->set_field<BANK_GROUP>(i_address.template get_field<ecc::fwms::address<MC>::BANK_GROUP>());
            this->set_field<BANK      >(i_address.template get_field<ecc::fwms::address<MC>::BANK>());
        }

        ///
        /// @brief Conversion operator to uint64_t
        /// @warn Right-aligns the address
        ///
        inline operator uint64_t() const
        {
            return iv_address >> MAGIC_PAD;
        }

        ///
        /// @brief Set a field for an address
        /// @tparam F the field to set
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        template< const field& F >
        inline address& set_field( const uint64_t i_value )
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
        inline void get_range( address& o_end ) const
        {
            constexpr uint64_t START = F.first + F.second;
            constexpr uint64_t LEN = (LAST_VALID.first + LAST_VALID.second) - START;

            // All we need to do is fill in the bits to the right of the last valid field
            o_end.iv_address = iv_address;
            o_end.iv_address.setBit<START, LEN>();
        }


        ///
        /// @brief Get an end address for sim mode
        /// @param[out] o_end representing an address to end at
        /// @note this pointer is the start address
        ///
        inline void get_sim_end_address( address& o_end ) const
        {
            // This magic number represents a range of addresses which cover all
            // cache lines the training algorithms touch. By effecting 0 - this end
            // address you'll effect everything which has bad ECC in the sim.
            // TODO: this will have to change for explorer. it's algorithm dependent.
            //       we'll need to talk to the microchip about this
            constexpr uint64_t l_magic_sim_number = 0b1000000;

            get_range<COL>(o_end);
            o_end.set_column(l_magic_sim_number);
            return;
        }

        ///
        /// @brief Get a range of addresses given a master rank
        /// @param[in] i_start representing an address to start from
        /// @param[out] o_end representing an address to end at
        ///
        inline static void get_mrank_range( const address& i_start, address& o_end )
        {
            i_start.get_range<MRANK>(o_end);
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
                                            address& o_start,
                                            address& o_end )
        {
            o_start.set_port(i_port).set_dimm(i_dimm).set_master_rank(i_mrank);
            get_mrank_range(o_start, o_end);
        }

        ///
        /// @brief Get a range of addresses given a slave rank
        /// @param[in] i_start representing an address to start from
        /// @param[out] o_end representing an address to end at
        ///
        inline static void get_srank_range( const address& i_start, address& o_end )
        {
            i_start.get_range<SRANK>(o_end);
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
                                            address& o_start,
                                            address& o_end )
        {
            o_start.set_port(i_port).set_dimm(i_dimm).set_master_rank(i_mrank).set_slave_rank(i_srank);
            get_srank_range(o_start, o_end);
        }

        ///
        /// @brief Set the port value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address& set_port( const uint64_t i_value )
        {
            return set_field<PORT>(i_value);
        }

        ///
        /// @brief Get the port value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_port() const
        {
            return get_field<PORT>();
        }

        ///
        /// @brief Set the DIMM value for an address
        /// @param[in] i_value the value to set
        /// @note 0 is the DIMM[0] != 0 is DIMM[1]
        /// @return address& for method chaining
        ///
        inline address& set_dimm( const uint64_t i_value )
        {
            return set_field<DIMM>(i_value);
        }

        ///
        /// @brief Get the DIMM value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_dimm() const
        {
            return get_field<DIMM>();
        }

        ///
        /// @brief Set the port and DIMM value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        /// @note Useful for indexing all ports/DIMM on a controller
        ///
        inline address& set_port_dimm( const fapi2::buffer<uint64_t> i_value )
        {
            uint64_t l_read_port = 0;

            i_value.extractToRight<PORT_START, PORT_LEN>(l_read_port);
            return set_dimm(i_value.getBit<DIMM_BIT>()).set_port(l_read_port);
        }

        ///
        /// @brief Get the port and DIMM value for an address
        /// @return right-aligned uint64_t representing the value
        /// @note Useful for indexing all ports/DIMM on a controller
        ///
        inline uint64_t get_port_dimm() const
        {
            fapi2::buffer<uint64_t> l_value;

            l_value.insertFromRight<PORT_START, PORT_LEN>(get_port());
            l_value.writeBit<DIMM_BIT>(get_dimm());

            return l_value;
        }

        ///
        /// @brief Set the master rank value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address& set_master_rank( const uint64_t i_value )
        {
            return set_field<MRANK>(i_value);
        }

        ///
        /// @brief Get the master rank value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_master_rank() const
        {
            return get_field<MRANK>();
        }


        ///
        /// @brief Set the slave rank value for an address
        /// @param[in] i_value the value to set
        ///
        inline void set_slave_rank( const uint64_t i_value )
        {
            set_field<SRANK>(i_value);
        }

        ///
        /// @brief Get the slave rank value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_slave_rank() const
        {
            return get_field<SRANK>();
        }


        ///
        /// @brief Set the row value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address& set_row( const uint64_t i_value )
        {
            return set_field<ROW>(i_value);
        }

        ///
        /// @brief Get the row value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_row() const
        {
            return get_field<ROW>();
        }


        ///
        /// @brief Set the column value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address& set_column( const uint64_t i_value )
        {
            return set_field<COL>(i_value);
        }

        ///
        /// @brief Get the column value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_column() const
        {
            return get_field<COL>();
        }


        ///
        /// @brief Set the bank value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address& set_bank( const uint64_t i_value )
        {
            return set_field<BANK>(i_value);
        }

        ///
        /// @brief Get the bank value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_bank() const
        {
            return get_field<BANK>();
        }

        ///
        /// @brief Set the bank group value for an address
        /// @param[in] i_value the value to set
        /// @return address& for method chaining
        ///
        inline address& set_bank_group( const uint64_t i_value )
        {
            return set_field<BANK_GROUP>(i_value);
        }

        ///
        /// @brief Get the bank group value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_bank_group() const
        {
            return get_field<BANK_GROUP>();
        }

    private:
        // We use a fapi2 buffer as it has static compile-time support
        fapi2::buffer<uint64_t> iv_address;
};

} // close namespace mcbist

// Documented above in its declaration.
template< mss::mc_type MC, fapi2::TargetType T , typename TT >
class ecc::fwms::address
{
    public:
        // first is the start bit of the field, second is the length
        using field = std::pair<uint64_t, uint64_t>;

        constexpr static field DIMM = {TT::FIRMWARE_MS_ADDRESS, 1};
        constexpr static field MRANK = {TT::FIRMWARE_MS_ADDRESS + 1, 2};
        constexpr static field SRANK = {TT::FIRMWARE_MS_ADDRESS + 3, 3};
        constexpr static field BANK_GROUP = {TT::FIRMWARE_MS_ADDRESS + 6, 2};
        constexpr static field BANK = {TT::FIRMWARE_MS_ADDRESS + 8, 3};

        address() = default;

        ///
        /// @brief Construct an address from a uint64_t (scom'ed value)
        /// @param[in] i_value representing raw value from FWMS register
        ///
        address( const uint64_t& i_value ):
            iv_value(i_value)
        {
        }

        ///
        /// @brief Construct an address from an mcbist::address
        /// @param[in] i_mcbist_address mcbist formatted address
        /// @note Construction of mcbist::address from ecc::fwms::address
        /// @note located in mcbist::address class
        ///
        address( const mcbist::address& i_mcbist_address )
        {
            iv_value.insertFromRight<DIMM.first, DIMM.second>(i_mcbist_address.get_field<mcbist::address::DIMM>());
            iv_value.insertFromRight<MRANK.first, MRANK.second>(i_mcbist_address.get_field<mcbist::address::MRANK>());
            iv_value.insertFromRight<SRANK.first, SRANK.second>(i_mcbist_address.get_field<mcbist::address::SRANK>());
            iv_value.insertFromRight<BANK_GROUP.first, BANK_GROUP.second>
            (i_mcbist_address.get_field<mcbist::address::BANK_GROUP>());
            iv_value.insertFromRight<BANK.first, BANK.second>(i_mcbist_address.get_field<mcbist::address::BANK>());
        }

        ///
        /// @brief Conversion operator to uint64_t
        ///
        inline operator uint64_t() const
        {
            uint64_t l_temp = 0;
            iv_value.extract<TT::FIRMWARE_MS_ADDRESS, TT::FIRMWARE_MS_ADDRESS_LEN, TT::FIRMWARE_MS_ADDRESS>(l_temp);
            return l_temp;
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
            iv_value.extractToRight<F.first, F.second>(l_value);
            return l_value;
        }

    private:
        fapi2::buffer<uint64_t> iv_value;

};

using field = std::pair<uint64_t, uint64_t>;
template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::fwms::address<MC, T, TT>::DIMM;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::fwms::address<MC, T, TT>::MRANK;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::fwms::address<MC, T, TT>::SRANK;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::fwms::address<MC, T, TT>::BANK_GROUP;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::fwms::address<MC, T, TT>::BANK;

// Documented above in its declaration.
template< mss::mc_type MC, fapi2::TargetType T , typename TT >
class ecc::trap_address
{
    public:
        // first is the start bit of the field, second is the length
        using field = std::pair<uint64_t, uint64_t>;

        constexpr static field PORT = {TT::TRAP_ADDRESS_PORT, TT::TRAP_ADDRESS_PORT_LEN};
        constexpr static field DIMM = {TT::TRAP_ADDRESS_DIMM, TT::TRAP_ADDRESS_DIMM_LEN};
        constexpr static field MRANK = {TT::TRAP_ADDRESS_MRANK, TT::TRAP_ADDRESS_MRANK_LEN};
        constexpr static field SRANK = {TT::TRAP_ADDRESS_SRANK, TT::TRAP_ADDRESS_SRANK_LEN};
        constexpr static field ROW = {TT::TRAP_ADDRESS_ROW, TT::TRAP_ADDRESS_ROW_LEN};
        constexpr static field COL = {TT::TRAP_ADDRESS_COL, TT::TRAP_ADDRESS_COL_LEN};
        constexpr static field BANK = {TT::TRAP_ADDRESS_BANK, TT::TRAP_ADDRESS_BANK_LEN};
        constexpr static field BANK_GROUP = {TT::TRAP_ADDRESS_BANK_GROUP, TT::TRAP_ADDRESS_BANK_GROUP_LEN};

        trap_address() = default;

        ///
        /// @brief Construct an address from a uint64_t (scom'ed value)
        /// @param[in] i_value representing raw value from FWMS register
        ///
        trap_address( const uint64_t& i_value ):
            iv_value(i_value)
        {
        }

        ///
        /// @brief Construct an address from an mcbist::address
        /// @param[in] i_mcbist_address mcbist formatted address
        /// @note Construction of mcbist::address from ecc::trap_address
        /// @note located in mcbist::address class
        ///
        trap_address( const mcbist::address& i_mcbist_address )
        {
            iv_value.insertFromRight<PORT.first, PORT.second>(i_mcbist_address.get_field<mcbist::address::PORT>());
            iv_value.insertFromRight<DIMM.first, DIMM.second>(i_mcbist_address.get_field<mcbist::address::DIMM>());
            iv_value.insertFromRight<MRANK.first, MRANK.second>(i_mcbist_address.get_field<mcbist::address::MRANK>());
            iv_value.insertFromRight<SRANK.first, SRANK.second>(i_mcbist_address.get_field<mcbist::address::SRANK>());
            iv_value.insertFromRight<ROW.first, ROW.second>(i_mcbist_address.get_field<mcbist::address::ROW>());
            iv_value.insertFromRight<COL.first, COL.second>(i_mcbist_address.get_field<mcbist::address::COL>());
            iv_value.insertFromRight<BANK.first, BANK.second>(i_mcbist_address.get_field<mcbist::address::BANK>());
            iv_value.insertFromRight<BANK_GROUP.first, BANK_GROUP.second>
            (i_mcbist_address.get_field<mcbist::address::BANK_GROUP>());
        }

        ///
        /// @brief Conversion operator to uint64_t
        ///
        inline operator uint64_t() const
        {
            uint64_t l_temp = 0;
            iv_value.extract<TT::TRAP_ADDRESS, TT::TRAP_ADDRESS_LEN, TT::TRAP_ADDRESS>(l_temp);
            return l_temp;
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
            iv_value.extractToRight<F.first, F.second>(l_value);
            return l_value;
        }

    private:
        fapi2::buffer<uint64_t> iv_value;
};

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::trap_address<MC, T, TT>::PORT;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::trap_address<MC, T, TT>::DIMM;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::trap_address<MC, T, TT>::MRANK;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::trap_address<MC, T, TT>::SRANK;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::trap_address<MC, T, TT>::ROW;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::trap_address<MC, T, TT>::COL;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::trap_address<MC, T, TT>::BANK;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr field ecc::trap_address<MC, T, TT>::BANK_GROUP;

} // close namespace mss

#endif
