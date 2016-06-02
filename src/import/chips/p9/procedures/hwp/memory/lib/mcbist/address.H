/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/address.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file address.H
/// @brief Class for mcbist related addresses (addresses below the hash translation)
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MCBIST_ADDRESS_H_
#define _MSS_MCBIST_ADDRESS_H_

#include <fapi2.H>
#include <utility>

namespace mss
{
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
    private:
        // How far over we shift to align the address in either the register or a buffer
        enum { MAGIC_PAD = 26 };

    public:

        // first is the start bit of the field, second is the length
        typedef std::pair<uint64_t, uint64_t> field;

        constexpr static field PORT = {0, 2};
        constexpr static field DIMM = {2, 1};
        constexpr static field MRANK = {3, 2};
        constexpr static field SRANK = {5, 3};
        constexpr static field ROW = {8, 18};
        constexpr static field COL = {26, 7};
        constexpr static field BANK = {33, 3};
        constexpr static field BANK_GROUP = {36, 2};
        constexpr static field LAST_VALID = BANK_GROUP;

        address() = default;

        ///
        /// @brief Construct an address from a uint64_t (scom'ed value)
        /// @param[in] i_value representing an address; say from a trap register
        ///
        /// @note This assumes input has the same bit layout as this address
        /// structure, and this is presently not the case for the trap registers (3/16).
        /// These are presently unused, however. There is an open defect against the
        /// design team to correct this.
        /// @warn Assumes right-aligned value; bit 63 is shifted to represent the Bank Group
        address( const uint64_t i_value ):
            iv_address(i_value << MAGIC_PAD)
        {
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
        inline static void get_mrank_range( const uint64_t i_port, const uint64_t i_dimm, const uint64_t i_mrank,
                                            address& o_start, address& o_end )
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
                                            address& o_start, address& o_end )
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
        /// @return right-aligned uint64_t representing the vaule
        ///
        inline uint64_t get_dimm() const
        {
            return (get_field<DIMM>() == true ? 1 : 0);
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

} // namespace

} // namespace

#endif
