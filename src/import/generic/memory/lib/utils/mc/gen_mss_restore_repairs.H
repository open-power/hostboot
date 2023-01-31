/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mc/gen_mss_restore_repairs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file gen_mss_restore_repairs.H
/// @brief Code to support restore repairs
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP


#ifndef _GEN_MSS_RESTORE_REPAIRS_H_
#define _GEN_MSS_RESTORE_REPAIRS_H_

#ifndef __PPE__

#include <fapi2.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/ecc/hw_mark_store.H>
#include <generic/memory/lib/ecc/fw_mark_store.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/utils/mc/gen_mss_port_traits.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <generic/memory/lib/utils/mcbist/gen_maint_cmds.H>

namespace mss
{

///
/// @brief Place a chip mark in a Hardware Mark Store register
/// @tparam MC the memory controller type
/// @tparam TT the class traits for the port
/// @param[in] i_target the DIMM target
/// @param[in] i_port_rank the port rank
/// @param[in] i_dq one of the bad DQ bits in the bad nibble
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
fapi2::ReturnCode place_chip_mark(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint64_t i_port_rank,
                                  const uint64_t i_dq)
{
    const auto& l_port = mss::find_target<TT::PORT_TYPE>(i_target);

    uint8_t l_galois = 0;
    uint8_t l_symbol = 0;

    // For chip marks, we set the appropriate Hardware Mark Store reg, with the Galois code
    // of the first (smallest) symbol in the bad nibble, and both confirmed and exit1 bits set
    FAPI_TRY( mss::ecc::dq_to_symbol<MC>(static_cast<uint8_t>(i_dq), l_symbol) );

    // Round down to the nearest "nibble" to get the correct symbol, then get the Galois code for it
    l_symbol = (l_symbol / BITS_PER_NIBBLE) * BITS_PER_NIBBLE;
    FAPI_TRY( mss::ecc::symbol_to_galois<MC>(l_symbol, l_galois) );

    FAPI_INF(TARGTIDFORMAT " Setting hardware (chip) mark on rank:%d galois:0x%02x", TARGTID, i_port_rank, l_galois);
    FAPI_TRY( mss::ecc::set_hwms<MC>(l_port, i_port_rank, l_galois) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Place a symbol mark in a Firmware Mark Store register
/// @tparam MC the memory controller type
/// @tparam TT the class traits for the port
/// @param[in] i_target the DIMM target
/// @param[in] i_port_rank the port rank
/// @param[in] i_dq the bad DQ bit
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
fapi2::ReturnCode place_symbol_mark(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint64_t i_port_rank,
                                    const uint64_t i_dq)
{
    const auto& l_port = mss::find_target<TT::PORT_TYPE>(i_target);
    const auto l_dimm_idx = mss::index(i_target);
    const auto l_rank_idx = mss::index(i_port_rank);

    uint8_t l_galois = 0;
    mss::mcbist::address l_addr;

    // For symbol marks, we set the appropriate Firmware Mark Store reg, with the symbol's
    // Galois code, mark_type=SYMBOL, mark_region=MRANK, and the address of the DIMM+MRANK
    // TODO RTC:165133 Remove static_cast once Galois API is updated to accept uint64_t input
    FAPI_TRY( mss::ecc::dq_to_galois<MC>(static_cast<uint8_t>(i_dq), l_galois) );

    l_addr.set_dimm(l_dimm_idx).set_master_rank(l_rank_idx);

    FAPI_INF(TARGTIDFORMAT " Setting firmware symbol mark on rank:%d dq:%d galois:0x%02x",
             TARGTID, i_port_rank, i_dq, l_galois);
    FAPI_TRY( mss::ecc::set_fwms<MC>(l_port, i_port_rank, l_galois,
                                     mss::ecc::fwms::mark_type::SYMBOL,
                                     mss::ecc::fwms::mark_region::MRANK,
                                     l_addr) );

fapi_try_exit:
    return fapi2::current_err;
}

// Forward declaration for use in repair_state classes
template< mss::mc_type MC, fapi2::TargetType T >
class repair_state_machine;

/// TODO: Zenhub#597 Clean up state parameters and constructor
///
/// @class mss::repair_state
/// @brief A class for keeping track of bad bit repair states in a repair_state_machine
/// @tparam MC the memory controller type
/// @tparam T, the fapi2 target type of the DIMM
/// @note this is a base class
///
template< mss::mc_type MC, fapi2::TargetType T >
class repair_state
{
    public:
        ///
        /// @brief default contructor
        ///
        repair_state() = default;
        ///
        /// @brief default destructor
        ///
        virtual ~repair_state() = default;

        ///
        /// @brief Perform a repair for a single bad DQ bit in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq the DQ bit index
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        virtual fapi2::ReturnCode one_bad_dq(repair_state_machine<MC, T>& io_machine,
                                             const fapi2::Target<T>& i_target,
                                             const uint64_t i_port_rank,
                                             const uint64_t i_dq,
                                             fapi2::buffer<uint8_t>& io_repairs_applied,
                                             fapi2::buffer<uint8_t>& io_repairs_exceeded) = 0;

        ///
        /// @brief Perform a repair for multiple bad DQ bits in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq one of the bad DQ bit indexes
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        virtual fapi2::ReturnCode multiple_bad_dq(repair_state_machine<MC, T>& io_machine,
                const fapi2::Target<T>& i_target,
                const uint64_t i_port_rank,
                const uint64_t i_dq,
                fapi2::buffer<uint8_t>& io_repairs_applied,
                fapi2::buffer<uint8_t>& io_repairs_exceeded) = 0;

    protected:
        ///
        /// @brief Set a new state in the repair state machine
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_state pointer to the new state to set
        ///
        inline void set_state(repair_state_machine<MC, T>& io_machine, std::shared_ptr<repair_state<MC, T>> i_state)
        {
            io_machine.update_state(i_state);
        }
};

///
/// @class mss::chip_and_symbol_mark
/// @brief repair_state class for when both a chip mark and a symbol mark have been used
/// @tparam MC the memory controller type
/// @tparam T, the fapi2 target type of the DIMM
///
template< mss::mc_type MC, fapi2::TargetType T >
class chip_and_symbol_mark : public repair_state<MC, T>
{
    public:
        ///
        /// @brief default contructor
        ///
        chip_and_symbol_mark() = default;
        ///
        /// @brief default destructor
        ///
        ~chip_and_symbol_mark() = default;

        ///
        /// @brief Perform a repair for a single bad DQ bit in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq the DQ bit index
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode one_bad_dq(repair_state_machine<MC, T>& io_machine,
                                     const fapi2::Target<T>& i_target,
                                     const uint64_t i_port_rank,
                                     const uint64_t i_dq,
                                     fapi2::buffer<uint8_t>& io_repairs_applied,
                                     fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // repairs exceeded
            FAPI_TRY( io_repairs_exceeded.setBit(mss::index(i_target)) );
            FAPI_INF(TARGTIDFORMAT " Repairs exceeded (chip mark and symbol mark exist, plus one bad DQ) on rank:%d DQ:%d",
                     TARGTID, i_port_rank, i_dq);
            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Perform a repair for multiple bad DQ bits in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq one of the bad DQ bit indexes
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode multiple_bad_dq(repair_state_machine<MC, T>& io_machine,
                                          const fapi2::Target<T>& i_target,
                                          const uint64_t i_port_rank,
                                          const uint64_t i_dq,
                                          fapi2::buffer<uint8_t>& io_repairs_applied,
                                          fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // repairs exceeded
            FAPI_TRY( io_repairs_exceeded.setBit(mss::index(i_target)) );
            FAPI_INF(TARGTIDFORMAT " Repairs exceeded (chip mark and symbol mark exist, plus one bad nibble) on rank:%d DQ:%d",
                     TARGTID, i_port_rank, i_dq);
            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @class mss::symbol_mark_plus_unrepaired_dq
/// @brief repair_state class for when only a symbol mark has been used, and one DQ bit remains unrepaired
/// @tparam MC the memory controller type
/// @tparam T, the fapi2 target type of the DIMM
///
template< mss::mc_type MC, fapi2::TargetType T >
class symbol_mark_plus_unrepaired_dq : public repair_state<MC, T>
{
    public:
        ///
        /// @brief default contructor
        ///
        symbol_mark_plus_unrepaired_dq() = default;
        ///
        /// @brief default destructor
        ///
        ~symbol_mark_plus_unrepaired_dq() = default;

        ///
        /// @brief Perform a repair for a single bad DQ bit in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq the DQ bit index
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode one_bad_dq(repair_state_machine<MC, T>& io_machine,
                                     const fapi2::Target<T>& i_target,
                                     const uint64_t i_port_rank,
                                     const uint64_t i_dq,
                                     fapi2::buffer<uint8_t>& io_repairs_applied,
                                     fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // repairs exceeded
            FAPI_INF(TARGTIDFORMAT " Repairs exceeded (symbol mark and unrepaired DQ exist, plus bad DQ) on rank:%d DQ:%d",
                     TARGTID, i_port_rank, i_dq);
            FAPI_TRY( io_repairs_exceeded.setBit(mss::index(i_target)) );
            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Perform a repair for multiple bad DQ bits in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq one of the bad DQ bit indexes
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode multiple_bad_dq(repair_state_machine<MC, T>& io_machine,
                                          const fapi2::Target<T>& i_target,
                                          const uint64_t i_port_rank,
                                          const uint64_t i_dq,
                                          fapi2::buffer<uint8_t>& io_repairs_applied,
                                          fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // place a chip mark, but also repairs exceeded
            FAPI_TRY( place_chip_mark<MC>(i_target, i_port_rank, i_dq) );
            FAPI_TRY( io_repairs_applied.setBit(i_port_rank) );
            FAPI_TRY( io_repairs_exceeded.setBit(mss::index(i_target)) );
            FAPI_INF(TARGTIDFORMAT" Repairs exceeded (symbol mark and unrepaired DQ exist, plus bad nibble) on rank:%d DQ:%d",
                     TARGTID, i_port_rank, i_dq);
            {
                const auto new_state = std::make_shared<chip_and_symbol_mark<MC, T>>();
                mss::repair_state<MC, T>::set_state(io_machine, new_state);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

};

///
/// @class mss::symbol_mark_only
/// @brief repair_state class for when only a symbol mark has been used
/// @tparam MC the memory controller type
/// @tparam T, the fapi2 target type of the DIMM
///
template< mss::mc_type MC, fapi2::TargetType T >
class symbol_mark_only : public repair_state<MC, T>
{
    public:
        ///
        /// @brief default contructor
        ///
        symbol_mark_only() = default;
        ///
        /// @brief default destructor
        ///
        ~symbol_mark_only() = default;

        ///
        /// @brief Perform a repair for a single bad DQ bit in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq the DQ bit index
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode one_bad_dq(repair_state_machine<MC, T>& io_machine,
                                     const fapi2::Target<T>& i_target,
                                     const uint64_t i_port_rank,
                                     const uint64_t i_dq,
                                     fapi2::buffer<uint8_t>& io_repairs_applied,
                                     fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // leave an unrepaired DQ
            const auto new_state = std::make_shared< symbol_mark_plus_unrepaired_dq<MC, T> >();
            mss::repair_state<MC, T>::set_state(io_machine, new_state);

            uint8_t l_dimm_spare[MAX_RANK_PER_DIMM_ATTR] = {0};
            FAPI_TRY(mss::attr::get_dimm_spare(i_target, l_dimm_spare));

            // For 4U - we want to mark repairs exceeded
            // Spec was written such that "4U" = DDIMM with spares = DDIMM with
            // the best RAS. So to key off of "are we 4U", we will really key off
            // of "DDIMM with spares"
            if (l_dimm_spare[i_port_rank % MAX_RANK_PER_DIMM_ATTR] != fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_NO_SPARE)
            {
                FAPI_TRY( io_repairs_exceeded.setBit(mss::index(i_target)) );
                FAPI_INF(TARGTIDFORMAT" Repairs exceeded (chip mark exists, plus bad nibble) on port rank:%d DQ:%d",
                         TARGTID, i_port_rank, i_dq);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Perform a repair for multiple bad DQ bits in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq one of the bad DQ bit indexes
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode multiple_bad_dq(repair_state_machine<MC, T>& io_machine,
                                          const fapi2::Target<T>& i_target,
                                          const uint64_t i_port_rank,
                                          const uint64_t i_dq,
                                          fapi2::buffer<uint8_t>& io_repairs_applied,
                                          fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // place a chip mark
            FAPI_TRY( place_chip_mark<MC>(i_target, i_port_rank, i_dq) );
            FAPI_TRY( io_repairs_applied.setBit(i_port_rank) );
            {
                const auto new_state = std::make_shared< chip_and_symbol_mark<MC, T> >();
                mss::repair_state<MC, T>::set_state(io_machine, new_state);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @class mss::chip_mark_only
/// @brief repair_state class for when only a chip mark has been used
/// @tparam MC the memory controller type
/// @tparam T, the fapi2 target type of the DIMM
///
template< mss::mc_type MC, fapi2::TargetType T >
class chip_mark_only : public repair_state<MC, T>
{
    public:
        ///
        /// @brief default contructor
        ///
        chip_mark_only() = default;
        ///
        /// @brief default destructor
        ///
        ~chip_mark_only() = default;

        ///
        /// @brief Perform a repair for a single bad DQ bit in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq the DQ bit index
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode one_bad_dq(repair_state_machine<MC, T>& io_machine,
                                     const fapi2::Target<T>& i_target,
                                     const uint64_t i_port_rank,
                                     const uint64_t i_dq,
                                     fapi2::buffer<uint8_t>& io_repairs_applied,
                                     fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // place a symbol mark
            FAPI_TRY( place_symbol_mark<MC>(i_target, i_port_rank, i_dq) );
            FAPI_TRY( io_repairs_applied.setBit(i_port_rank) );
            {
                const auto new_state = std::make_shared<chip_and_symbol_mark<MC, T>>();
                mss::repair_state<MC, T>::set_state(io_machine, new_state);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Perform a repair for multiple bad DQ bits in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq one of the bad DQ bit indexes
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode multiple_bad_dq(repair_state_machine<MC, T>& io_machine,
                                          const fapi2::Target<T>& i_target,
                                          const uint64_t i_port_rank,
                                          const uint64_t i_dq,
                                          fapi2::buffer<uint8_t>& io_repairs_applied,
                                          fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // repairs exceeded
            FAPI_TRY( io_repairs_exceeded.setBit(mss::index(i_target)) );
            FAPI_INF(TARGTIDFORMAT " Repairs exceeded (chip mark exists, plus bad nibble) on rank:%d DQ:%d",
                     TARGTID, i_port_rank, i_dq);
            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @class mss::no_fails
/// @brief repair_state class for no fails (no marks applied)
/// @tparam MC the memory controller type
/// @tparam T, the fapi2 target type of the DIMM
///
template< mss::mc_type MC, fapi2::TargetType T >
class no_fails : public repair_state<MC, T>
{
    public:
        ///
        /// @brief default contructor
        ///
        no_fails() = default;
        ///
        /// @brief default destructor
        ///
        ~no_fails() = default;

        ///
        /// @brief Perform a repair for a single bad DQ bit in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq the DQ bit index
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode one_bad_dq(repair_state_machine<MC, T>& io_machine,
                                     const fapi2::Target<T>& i_target,
                                     const uint64_t i_port_rank,
                                     const uint64_t i_dq,
                                     fapi2::buffer<uint8_t>& io_repairs_applied,
                                     fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // place a symbol mark
            FAPI_TRY( place_symbol_mark<MC>(i_target, i_port_rank, i_dq) );
            FAPI_TRY( io_repairs_applied.setBit(i_port_rank) );
            {
                const auto new_state = std::make_shared<symbol_mark_only<MC, T>>();
                mss::repair_state<MC, T>::set_state(io_machine, new_state);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Perform a repair for multiple bad DQ bits in a nibble
        /// @param[in,out] io_machine the repair state machine
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq one of the bad DQ bit indexes
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode multiple_bad_dq(repair_state_machine<MC, T>& io_machine,
                                          const fapi2::Target<T>& i_target,
                                          const uint64_t i_port_rank,
                                          const uint64_t i_dq,
                                          fapi2::buffer<uint8_t>& io_repairs_applied,
                                          fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            // place a chip mark
            FAPI_TRY( place_chip_mark<MC>(i_target, i_port_rank, i_dq) );
            FAPI_TRY( io_repairs_applied.setBit(i_port_rank) );
            {
                const auto new_state = std::make_shared<chip_mark_only<MC, T>>();
                mss::repair_state<MC, T>::set_state(io_machine, new_state);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @class mss::repair_state_machine
/// @brief state machine class used in restore_repairs_helper
/// @tparam MC the memory controller type
/// @tparam T, the fapi2 target type of the DIMM
///
template< mss::mc_type MC, fapi2::TargetType T >
class repair_state_machine
{
    public:
        ///
        /// @brief constructor
        ///
        repair_state_machine()
            : iv_repair_state(std::make_shared<no_fails<MC, T>>()) {}
        ///
        /// @brief default destructor
        ///
        ~repair_state_machine() = default;

        ///
        /// @brief Perform a repair for a single bad DQ bit in a nibble
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq the DQ bit index
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode one_bad_dq(const fapi2::Target<T>& i_target,
                                     const uint64_t i_port_rank,
                                     const uint64_t i_dq,
                                     fapi2::buffer<uint8_t>& io_repairs_applied,
                                     fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            FAPI_TRY( iv_repair_state->one_bad_dq(*this, i_target, i_port_rank, i_dq, io_repairs_applied, io_repairs_exceeded) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Perform a repair for multiple bad DQ bits in a nibble
        /// @param[in] i_target the DIMM target
        /// @param[in] i_port_rank the port rank
        /// @param[in] i_dq one of the bad DQ bit indexes
        /// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
        /// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode multiple_bad_dq(const fapi2::Target<T>& i_target,
                                          const uint64_t i_port_rank,
                                          const uint64_t i_dq,
                                          fapi2::buffer<uint8_t>& io_repairs_applied,
                                          fapi2::buffer<uint8_t>& io_repairs_exceeded)
        {
            FAPI_TRY( iv_repair_state->multiple_bad_dq(*this, i_target, i_port_rank, i_dq, io_repairs_applied,
                      io_repairs_exceeded) );
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Update the state of the state machine
        /// @param[in] i_state shared pointer to the new state
        ///
        void update_state(std::shared_ptr<repair_state<MC, T>> i_state)
        {
            iv_repair_state = i_state;
        }

    private:
        std::shared_ptr<repair_state<MC, T>> iv_repair_state;
};

///
/// @brief Convert a bitmap from the BAD_DQ_BITMAP attribute to a vector of bad DQ indexes
/// @param[in] i_bad_bits an 8-bit bitmap of bad bits
/// @param[in] i_nibble which nibble of the bitmap to convert
/// @return std::vector of DQ bits marked as bad in the bitmap
///
inline std::vector<uint64_t> bad_dq_attr_to_vector(const uint8_t i_bad_bits, const size_t i_nibble)
{
    std::vector<uint64_t> l_output;
    const fapi2::buffer<uint8_t> l_bit_buffer(i_bad_bits);

    const size_t l_start = (i_nibble == 0) ? 0 : mss::conversions::BITS_PER_NIBBLE;

    for (size_t l_offset = 0; l_offset < mss::conversions::BITS_PER_NIBBLE; ++l_offset)
    {
        const size_t l_position_tmp = l_start + l_offset;

        if (l_bit_buffer.getBit(l_position_tmp))
        {
            l_output.push_back(l_position_tmp);
        }
    }

    return l_output;
}


///
/// @brief Helper function to get DQ index from a deployed spare
/// @param[in] i_spare_dq a DQ index relative to the spare nibble (0-7)
/// @param[in] i_deployed_nibble_index index of the nibble the spare is deployed to
/// @return original DQ index mapped to DIMM's perspective
///
inline uint64_t get_dq_for_deployed_spare(const uint64_t i_spare_dq,
        const uint64_t i_deployed_nibble_index)
{
    return (i_spare_dq % BITS_PER_NIBBLE) + i_deployed_nibble_index * BITS_PER_NIBBLE;
}

///
/// @brief Restore symbol and chip marks according to BAD_DQ_BITMAP attribute, helper function for unit testing
/// @tparam MC the memory controller type
/// @param[in] i_dimm A target representing a DIMM
/// @param[in] i_bad_bits the bad bits values from the VPD, for the specified DIMM
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC>
fapi2::ReturnCode restore_repairs_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        const uint8_t i_bad_bits[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        fapi2::buffer<uint8_t>& io_repairs_applied,
        fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    FAPI_INF(TARGTIDFORMAT " Restore repair marks from bad DQ data", GENTARGTID(i_dimm));

    constexpr bool IGNORE_BAD_BITS_ON_SPARES = true;

    std::vector<mss::rank::info<MC>> l_ranks;
    uint8_t l_dimm_spare[MAX_RANK_PER_DIMM_ATTR] = {0};
    std::vector<uint8_t> l_nonspare_nibbles;
    mss::steer::get_nonspare_nibbles<MC>(l_nonspare_nibbles);

    // gets spare availability
    FAPI_TRY(mss::attr::get_dimm_spare(i_dimm, l_dimm_spare));

    // gets all of the ranks to loop over
    FAPI_TRY(mss::rank::ranks_on_dimm<MC>(i_dimm, l_ranks));

    // loop through ranks
    for (const auto l_rank : l_ranks)
    {
        const auto l_dimm_rank = l_rank.get_dimm_rank();
        const auto l_port_rank = l_rank.get_port_rank();
        const auto l_dimm_idx = mss::rank::get_dimm_from_rank<MC>(l_port_rank);

        repair_state_machine<MC, fapi2::TARGET_TYPE_DIMM> l_machine;

        // List of byte, nibble pairs of available spares, and deployed spares
        std::vector<uint8_t> l_spare_nibbles;
        std::vector<uint8_t> l_deployed_spares;
        FAPI_TRY(mss::steer::get_spare_nibbles<MC>( i_dimm,
                 l_rank,
                 l_spare_nibbles));

        // Loop over nonspare nibbles
        for (const auto& l_nibble_idx : l_nonspare_nibbles)
        {
            const auto l_byte = l_nibble_idx / NIBBLES_PER_BYTE;
            const auto l_nibble = l_nibble_idx % NIBBLES_PER_BYTE;

            const auto l_bad_dq_vector = mss::bad_dq_attr_to_vector(i_bad_bits[l_dimm_rank][l_byte], l_nibble);
            FAPI_DBG(TARGTIDFORMAT " Total bad bits on DIMM:%d rank:%d nibble%d: %d",
                     GENTARGTID(i_dimm), l_dimm_idx, l_dimm_rank, (l_byte * NIBBLES_PER_BYTE) + l_nibble, l_bad_dq_vector.size());

            // If there is at least one bad bit and we have an undeployed spare, deploy the next spare we have available
            // For DIMM's that lack spares this becomes a no-op as the spare nibbles and deployed spares will be empty
            if((l_bad_dq_vector.size() >= 1) && (l_deployed_spares.size() < l_spare_nibbles.size()))
            {
                FAPI_TRY(mss::steer::deploy_spare_helper<MC>(i_dimm,
                         l_rank,
                         l_nibble_idx,
                         l_spare_nibbles,
                         l_deployed_spares,
                         IGNORE_BAD_BITS_ON_SPARES));
            }

            // apply repairs and update repair machine state
            // if there are no bad bits (l_bad_dq_vector.size() == 0) no action is necessary
            else if (l_bad_dq_vector.size() == 1)
            {
                // l_bad_dq_vector is per byte, so multiply up to get the bad dq's index
                const uint64_t l_dq = l_bad_dq_vector[0] + (l_byte * BITS_PER_BYTE);
                FAPI_TRY( l_machine.one_bad_dq(i_dimm, l_port_rank, l_dq, io_repairs_applied, io_repairs_exceeded) );
            }
            else if (l_bad_dq_vector.size() > 1)
            {
                // l_bad_dq_vector is per byte, so multiply up to get the bad dq's index
                const uint64_t l_dq = l_bad_dq_vector[0] + (l_byte * BITS_PER_BYTE);
                FAPI_TRY( l_machine.multiple_bad_dq(i_dimm, l_port_rank, l_dq, io_repairs_applied, io_repairs_exceeded) );
            }

            // if repairs have been exceeded, we're done
            if (io_repairs_exceeded.getBit(l_dimm_idx))
            {
                FAPI_INF("Repairs exceeded on DIMM " TARGTIDFORMAT, GENTARGTID(i_dimm));
                return fapi2::FAPI2_RC_SUCCESS;
            }
        } // end loop through non spares

        // Loops through and checks spares
        // We use an index based for loop to allow us to increment through both of the vectors as needed
        for (uint8_t l_spare = 0; l_spare < l_spare_nibbles.size(); ++l_spare )
        {
            const auto l_spare_idx = l_spare_nibbles[l_spare];
            const auto l_spare_byte = l_spare_idx / NIBBLES_PER_BYTE;
            const auto l_spare_nibble = l_spare_idx % NIBBLES_PER_BYTE;

            const auto l_bad_dq_vector = mss::bad_dq_attr_to_vector(i_bad_bits[l_dimm_rank][l_spare_byte], l_spare_nibble);
            FAPI_DBG(TARGTIDFORMAT " Total bad bits on spare%u DIMM:%d rank:%d nibble%d: %d",
                     GENTARGTID(i_dimm), l_spare, l_dimm_idx, l_port_rank, (l_spare_byte * NIBBLES_PER_BYTE) + l_spare_nibble,
                     l_bad_dq_vector.size());

            // If this spare is undeployed, we can exit out of this loop
            // No other spare will be deployed and we don't need to apply any repairs on a spare we're not using
            if (l_spare >= l_deployed_spares.size())
            {
                FAPI_DBG( TARGTIDFORMAT" Spare%u is undeployed. No further repairs needed on rank%u",
                          GENTARGTID(i_dimm), l_spare, l_port_rank);
                break;
            }

            // We want to apply repairs on the nibbles on which we deployed spares
            const auto l_nibble_idx = l_deployed_spares[l_spare];

            // Available spares
            uint8_t l_undeployed_spare_count = l_spare_nibbles.size() - l_deployed_spares.size();

            // If there is at least one bad bit and we have another undeployed spare, deploy the next spare we have available
            // We also undeploy our current spare
            if ((l_bad_dq_vector.size() >= 1) && l_undeployed_spare_count > 0)
            {
                // deploy_spare_helper will always pick the next available spare,
                // so it should skip over the currently deployed and correctly choose the next
                FAPI_TRY(mss::steer::deploy_spare_helper<MC>(i_dimm,
                         l_rank,
                         l_nibble_idx,
                         l_spare_nibbles,
                         l_deployed_spares,
                         IGNORE_BAD_BITS_ON_SPARES));

                // Undeploy the current spare
                FAPI_TRY(mss::steer::unspare<MC>(l_spare, l_rank));

                // We will leave the newly undeployed spare in l_deplored_spares,
                // to leave a record of what happened
            }

            // apply repairs and update repair machine state
            // if there are no bad bits (l_bad_dq_vector.size() == 0) no action is necessary
            else if (l_bad_dq_vector.size() == 1)
            {
                // map the spare's bad dq to get the dq index to mark
                const auto l_dq = get_dq_for_deployed_spare(l_bad_dq_vector[0], l_nibble_idx);
                FAPI_TRY( l_machine.one_bad_dq(i_dimm, l_port_rank, l_dq, io_repairs_applied, io_repairs_exceeded) );
            }
            else if (l_bad_dq_vector.size() > 1)
            {
                // map the spare's bad dq to get the dq index to mark
                const auto l_dq = get_dq_for_deployed_spare(l_bad_dq_vector[0], l_nibble_idx);
                FAPI_TRY( l_machine.multiple_bad_dq(i_dimm, l_port_rank, l_dq, io_repairs_applied, io_repairs_exceeded) );
            }

            // if repairs have been exceeded, we're done
            if (io_repairs_exceeded.getBit(l_dimm_idx))
            {
                FAPI_INF("Repairs exceeded on DIMM " TARGTIDFORMAT, GENTARGTID(i_dimm));
                return fapi2::FAPI2_RC_SUCCESS;
            }
        }
    } // end loop through ranks

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Restore symbol and chip marks according to BAD_DQ_BITMAP attribute
/// @tparam MC, the memory controller type
/// @tparam T, the fapi2 target type of the port (derived)
/// @param[in] i_target A target representing a port
/// @param[in,out] io_repairs_applied bit mask, where a bit set means a rank had repairs applied (bit0 = rank0, etc)
/// @param[in,out] io_repairs_exceeded bit mask, where a bit set means a DIMM had more bad bits than could be repaired (bit0 = DIMM0 etc)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode restore_repairs( const fapi2::Target<T>& i_target,
                                   fapi2::buffer<uint8_t>& io_repairs_applied,
                                   fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    uint8_t l_bad_bits[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT] = {};

    io_repairs_applied = 0;
    io_repairs_exceeded = 0;

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( mss::attr::get_bad_dq_bitmap(l_dimm, l_bad_bits) );

        FAPI_TRY( (restore_repairs_helper<MC>(
                       l_dimm, l_bad_bits, io_repairs_applied, io_repairs_exceeded)) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// ns mss
#endif
#endif
