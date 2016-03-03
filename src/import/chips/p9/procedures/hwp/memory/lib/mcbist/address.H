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
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MCBIST_ADDRESS_H_
#define _MSS_MCBIST_ADDRESS_H_

#include <fapi2.H>

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
    public:

        address() = default;

        ///
        /// @brief Construct an address from a uint64_t (scom'ed value)
        /// @param[in] i_value representing an address; say from a trap register
        ///
        /// @note This assumes input has the same bit layout as this address
        /// structure, and this is presently not the case for the trap registers (3/16).
        /// These are presently unused, however. There is an open defect against the
        /// design team to correct this.
        address( const uint64_t i_value ):
            iv_address(i_value)
        {
        }

        ///
        /// @brief Conversion operator to uint64_t
        ///
        inline operator uint64_t() const
        {
            return iv_address;
        }

        ///
        /// @brief Conversion operator to uint64_t reference
        ///
        inline operator uint64_t& ()
        {
            return iv_address;
        }

        ///
        /// @brief Set the port value for an address
        /// @param[in] i_value the value to set
        ///
        inline void set_port( const uint64_t i_value )
        {
            iv_address.insertFromRight<PORT, PORT_LEN>(i_value);
        }

        ///
        /// @brief Get the port value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_port()
        {
            uint64_t l_value = 0;
            iv_address.extractToRight<PORT, PORT_LEN>(l_value);
            return l_value;
        }

        ///
        /// @brief Set the DIMM value for an address
        /// @param[in] i_value the value to set
        /// @note 0 is the DIMM[0] != 0 is DIMM[1]
        ///
        inline void set_dimm( const uint64_t i_value )
        {
            iv_address.writeBit<DIMM>(i_value);
        }

        ///
        /// @brief Get the DIMM value for an address
        /// @return right-aligned uint64_t representing the vaule
        ///
        inline uint64_t get_dimm()
        {
            bool l_value = iv_address.getBit<DIMM>();
            return (l_value == true ? 1 : 0);
        }

        ///
        /// @brief Set the master rank value for an address
        /// @param[in] i_value the value to set
        ///
        inline void set_master_rank( const uint64_t i_value )
        {
            iv_address.insertFromRight<MRANK, MRANK_LEN>(i_value);
        }

        ///
        /// @brief Get the master rank value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_master_rank()
        {
            uint64_t l_value = 0;
            iv_address.extractToRight<MRANK, MRANK_LEN>(l_value);
            return l_value;
        }


        ///
        /// @brief Set the slave rank value for an address
        /// @param[in] i_value the value to set
        ///
        inline void set_slave_rank( const uint64_t i_value )
        {
            iv_address.insertFromRight<SRANK, SRANK_LEN>(i_value);
        }

        ///
        /// @brief Get the slave rank value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_slave_rank()
        {
            uint64_t l_value = 0;
            iv_address.extractToRight<SRANK, SRANK_LEN>(l_value);
            return l_value;
        }


        ///
        /// @brief Set the row value for an address
        /// @param[in] i_value the value to set
        ///
        inline void set_row( const uint64_t i_value )
        {
            iv_address.insertFromRight<ROW, ROW_LEN>(i_value);
        }

        ///
        /// @brief Get the row value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_row()
        {
            uint64_t l_value = 0;
            iv_address.extractToRight<ROW, ROW_LEN>(l_value);
            return l_value;
        }


        ///
        /// @brief Set the column value for an address
        /// @param[in] i_value the value to set
        ///
        inline void set_column( const uint64_t i_value )
        {
            iv_address.insertFromRight<COL, COL_LEN>(i_value);
        }

        ///
        /// @brief Get the column value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_column()
        {
            uint64_t l_value = 0;
            iv_address.extractToRight<COL, COL_LEN>(l_value);
            return l_value;
        }


        ///
        /// @brief Set the bank value for an address
        /// @param[in] i_value the value to set
        ///
        inline void set_bank( const uint64_t i_value )
        {
            iv_address.insertFromRight<BANK, BANK_LEN>(i_value);
        }

        ///
        /// @brief Get the bank value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_bank()
        {
            uint64_t l_value = 0;
            iv_address.extractToRight<BANK, BANK_LEN>(l_value);
            return l_value;
        }


        ///
        /// @brief Set the bank group value for an address
        /// @param[in] i_value the value to set
        ///
        inline void set_bank_group( const uint64_t i_value )
        {
            iv_address.insertFromRight<BANK_GROUP, BANK_GROUP_LEN>(i_value);
        }

        ///
        /// @brief Get the bank group value for an address
        /// @return right-aligned uint64_t representing the value
        ///
        inline uint64_t get_bank_group()
        {
            uint64_t l_value = 0;
            iv_address.extractToRight<BANK_GROUP, BANK_GROUP_LEN>(l_value);
            return l_value;
        }

    private:
        /// Start and length bits for address bit fields
        enum start_and_length
        {
            PORT = 0,        ///< 0:1   port select
            PORT_LEN = 2,
            DIMM = 2,        ///< 2     dimm select
            MRANK = 3,       ///< 3:4   mrank(0 to 1)
            MRANK_LEN = 2,
            SRANK = 5,       ///< 5:7   srank(0 to 2)
            SRANK_LEN = 3,
            ROW = 8,         ///< 8:25  row(0 to 17)
            ROW_LEN = 18,
            COL = 26,        ///< 26:32 col(3 to 9)
            COL_LEN = 7,
            BANK = 33,       ///< 33:35 bank(0 to 2)
            BANK_LEN = 3,
            BANK_GROUP = 36, ///< 36:37 bank_group(0 to 1)
            BANK_GROUP_LEN = 2,
        };

        // We use a fapi2 buffer as it has static compile-time support
        fapi2::buffer<uint64_t> iv_address;
};

} // namespace

} // namespace

#endif
