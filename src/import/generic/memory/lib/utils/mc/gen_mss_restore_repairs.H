/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mc/gen_mss_restore_repairs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP


#ifndef _GEN_MSS_RESTORE_REPAIRS_H_
#define _GEN_MSS_RESTORE_REPAIRS_H_

#include <fapi2.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/ecc/hw_mark_store.H>
#include <generic/memory/lib/ecc/fw_mark_store.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <generic/memory/lib/utils/mss_rank.H>

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

    uint64_t l_galois = 0;
    uint64_t l_symbol = 0;

    // For chip marks, we set the appropriate Hardware Mark Store reg, with the Galois code
    // of the first (smallest) symbol in the bad nibble, and both confirmed and exit1 bits set
    FAPI_TRY( mss::ecc::dq_to_symbol<MC>(i_dq, l_symbol) );

    // Round down to the nearest "nibble" to get the correct symbol, then get the Galois code for it
    l_symbol = (l_symbol / BITS_PER_NIBBLE) * BITS_PER_NIBBLE;
    FAPI_TRY( mss::ecc::symbol_to_galois<MC>(l_symbol, l_galois) );

    FAPI_INF("%s Setting hardware (chip) mark on rank:%d galois:0x%02x", mss::c_str(i_target), i_port_rank, l_galois);
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

    uint64_t l_galois = 0;
    mss::mcbist::address l_addr;

    // For symbol marks, we set the appropriate Firmware Mark Store reg, with the symbol's
    // Galois code, mark_type=SYMBOL, mark_region=MRANK, and the address of the DIMM+MRANK
    // TODO RTC:165133 Remove static_cast once Galois API is updated to accept uint64_t input
    FAPI_TRY( mss::ecc::dq_to_galois<MC>(i_dq, l_galois) );

    l_addr.set_dimm(l_dimm_idx).set_master_rank(l_rank_idx);

    FAPI_INF("%s Setting firmware symbol mark on rank:%d dq:%d galois:0x%02x",
             mss::c_str(i_target), i_port_rank, i_dq, l_galois);
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
            FAPI_INF("%s Repairs exceeded (chip mark and symbol mark exist, plus one bad DQ) on rank:%d DQ:%d",
                     mss::c_str(i_target), i_port_rank, i_dq);
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
            FAPI_INF("%s Repairs exceeded (chip mark and symbol mark exist, plus one bad nibble) on rank:%d DQ:%d",
                     mss::c_str(i_target), i_port_rank, i_dq);
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
            FAPI_INF("%s Repairs exceeded (symbol mark and unrepaired DQ exist, plus bad DQ) on rank:%d DQ:%d",
                     mss::c_str(i_target), i_port_rank, i_dq);
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
            FAPI_INF("%s Repairs exceeded (symbol mark and unrepaired DQ exist, plus bad nibble) on rank:%d DQ:%d",
                     mss::c_str(i_target), i_port_rank, i_dq);
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
            return fapi2::FAPI2_RC_SUCCESS;
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
            FAPI_INF("%s Repairs exceeded (chip mark exists, plus bad nibble) on rank:%d DQ:%d",
                     mss::c_str(i_target), i_port_rank, i_dq);
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
        /// @param[in,out] io_repai:rs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
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
/// @brief Get the number of bytes to check in restore_repairs
/// @tparam MC the memory controller type
/// @param[in] i_spare_support value of ATTR_DIMM_SPARE for this [DIMM][RANK] combo
/// @return total number of bytes
///
template< mss::mc_type MC >
uint64_t get_total_bytes(const uint8_t i_spare_support);

///
/// @brief Figure out if selected nibble is a non-existent spare in restore_repairs
/// @tparam MC the memory controller type
/// @param[in] i_spare_support value of ATTR_DIMM_SPARE for this [DIMM][RANK] combo
/// @param[in] i_byte logical byte index
/// @param[in] i_nibble logical nibble index
/// @return true if selected nibble is a non-existent spare and needs to be skipped
///
template< mss::mc_type MC >
bool skip_dne_spare_nibble(const uint8_t i_spare_support,
                           const uint64_t i_byte,
                           const size_t i_nibble);

//
/// @brief Restore symbol and chip marks according to BAD_DQ_BITMAP attribute, helper function for unit testing
/// @tparam MC the memory controller type
/// @tparam T, the fapi2 target type of the DIMM (derived)
/// @param[in] i_target A target representing a DIMM
/// @param[in] i_bad_bits the bad bits values from the VPD, for the specified DIMM
/// @param[in,out] io_repairs_applied 8-bit mask, where a bit set means that rank had repairs applied
/// @param[in,out] io_repairs_exceeded 2-bit mask, where a bit set means that DIMM had more bad bits than could be repaired
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode restore_repairs_helper( const fapi2::Target<T>& i_target,
        const uint8_t i_bad_bits[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        fapi2::buffer<uint8_t>& io_repairs_applied,
        fapi2::buffer<uint8_t>& io_repairs_exceeded)
{
    FAPI_INF("%s Restore repair marks from bad DQ data", mss::c_str(i_target));

    // The ranks are returned as port values for this specific DIMM
    // That way, we can callout each rank correctly with no additional encoding needed
    std::vector<uint64_t> l_port_ranks;
    const auto l_dimm_idx = index(i_target);
    uint8_t l_dimm_spare[MAX_RANK_PER_DIMM_ATTR] = {0};

    // gets spare availability
    FAPI_TRY( mss::dimm_spare<MC>(i_target, l_dimm_spare) );

    // gets all of the ranks to loop over
    // Yes, we get port rank values from this function (documented it in doxygen)
    FAPI_TRY( mss::rank::ranks_on_dimm_helper<MC>(i_target, l_port_ranks) );

    // loop through ranks
    for (const auto l_port_rank : l_port_ranks)
    {
        const auto l_rank_idx = index(l_port_rank);

        // don't process last byte if it's a non-existent spare. Non-existent spare bits are marked 'bad' in the attribute
        const auto l_total_bytes = get_total_bytes<MC>(l_dimm_spare[l_port_rank]);

        repair_state_machine<MC, fapi2::TARGET_TYPE_DIMM> l_machine;

        for (uint64_t l_byte = 0; l_byte < l_total_bytes; ++l_byte)
        {
            for (size_t l_nibble = 0; l_nibble < mss::conversions::NIBBLES_PER_BYTE; ++l_nibble)
            {
                // don't process non-existent spare nibble because all non-existent spare bits are marked 'bad' in the attribute
                if (skip_dne_spare_nibble<MC>(l_dimm_spare[l_port_rank], l_byte, l_nibble))
                {
                    FAPI_DBG("Skip processing bits on DIMM:%d rank:%d nibble%d because they are non-existent spares",
                             l_dimm_idx, l_port_rank, (l_byte * NIBBLES_PER_BYTE) + l_nibble);
                    continue;
                }

                const auto l_bad_dq_vector = mss::bad_dq_attr_to_vector(i_bad_bits[l_rank_idx][l_byte], l_nibble);
                FAPI_DBG("Total bad bits on DIMM:%d rank:%d nibble%d: %d",
                         l_dimm_idx, l_port_rank, (l_byte * NIBBLES_PER_BYTE) + l_nibble, l_bad_dq_vector.size());

                // apply repairs and update repair machine state
                // if there are no bad bits (l_bad_dq_vector.size() == 0) no action is necessary
                if (l_bad_dq_vector.size() == 1)
                {
                    // l_bad_dq_vector is per byte, so multiply up to get the bad dq's index
                    const uint64_t l_dq = l_bad_dq_vector[0] + (l_byte * BITS_PER_BYTE);
                    FAPI_TRY( l_machine.one_bad_dq(i_target, l_port_rank, l_dq, io_repairs_applied, io_repairs_exceeded) );
                }
                else if (l_bad_dq_vector.size() > 1)
                {
                    // l_bad_dq_vector is per byte, so multiply up to get the bad dq's index
                    const uint64_t l_dq = l_bad_dq_vector[0] + (l_byte * BITS_PER_BYTE);
                    FAPI_TRY( l_machine.multiple_bad_dq(i_target, l_port_rank, l_dq, io_repairs_applied, io_repairs_exceeded) );
                }

                // if repairs have been exceeded, we're done
                if (io_repairs_exceeded.getBit(l_dimm_idx))
                {
                    FAPI_INF("Repairs exceeded on DIMM %s", c_str(i_target));
                    return fapi2::FAPI2_RC_SUCCESS;
                }
            } // end loop through nibbles
        } // end loop through bytes
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
        FAPI_TRY( mss::get_bad_dq_bitmap<MC>(l_dimm, l_bad_bits) );

        FAPI_TRY( (restore_repairs_helper<MC, fapi2::TARGET_TYPE_DIMM>(
                       l_dimm, l_bad_bits, io_repairs_applied, io_repairs_exceeded)) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// ns mss

#endif
