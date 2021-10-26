/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_mss_mcbist_ecc_trap_address.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file gen_mss_mcbist_ecc_trap_address.H
/// @brief Class for ECC trap addresses (addresses below the hash translation)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _GEN_MSS_MCBIST_ECC_TRAP_ADDRESS_H_
#define _GEN_MSS_MCBIST_ECC_TRAP_ADDRESS_H_

#include <fapi2.H>
#include <utility>
#include <generic/memory/lib/ecc/ecc_traits.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_traits.H>

namespace mss
{

namespace ecc
{

///
/// @class trap_address
/// @brief Converts trap address into mcbist::address
/// @tparam MC the mc type of the T
/// @tparam T fapi2 Target Type defaults to fapi2::TARGET_TYPE_MCA or TARGET_TYPE_MEM_PORT
/// @tparam TT traits type defaults to eccTraits<T>
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::FWMS_ADDR_TARGET_TYPE, typename TT = mss::eccTraits<MC, T> >
class trap_address
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
        /// @note Construction of mcbist::address from trap_address
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
        /// @brief Construct an mcbist::address from an ecc::trap_address
        /// @return the mcbist::address
        ///
        inline operator mss::mcbist::address() const
        {
            mss::mcbist::address l_mcbist_address;
            l_mcbist_address.set_port       (this->get_field<PORT>());
            l_mcbist_address.set_dimm       (this->get_field<DIMM>());
            l_mcbist_address.set_master_rank(this->get_field<MRANK>());
            l_mcbist_address.set_slave_rank (this->get_field<SRANK>());
            l_mcbist_address.set_row        (this->get_field<ROW>());
            l_mcbist_address.set_column     (this->get_field<COL>());
            l_mcbist_address.set_bank       (this->get_field<BANK>());
            l_mcbist_address.set_bank_group (this->get_field<BANK_GROUP>());
            return l_mcbist_address;
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
constexpr typename trap_address<MC, T, TT>::field trap_address<MC, T, TT>::PORT;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr typename trap_address<MC, T, TT>::field trap_address<MC, T, TT>::DIMM;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr typename trap_address<MC, T, TT>::field trap_address<MC, T, TT>::MRANK;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr typename trap_address<MC, T, TT>::field trap_address<MC, T, TT>::SRANK;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr typename trap_address<MC, T, TT>::field trap_address<MC, T, TT>::ROW;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr typename trap_address<MC, T, TT>::field trap_address<MC, T, TT>::COL;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr typename trap_address<MC, T, TT>::field trap_address<MC, T, TT>::BANK;

template< mss::mc_type MC, fapi2::TargetType T , typename TT >
constexpr typename trap_address<MC, T, TT>::field trap_address<MC, T, TT>::BANK_GROUP;


} // close namespace ecc
} // close namespace mss
#endif
