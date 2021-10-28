/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ecc/modal_symbol_count.H $      */
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
/// @file modal_symbol_count.H
/// @brief Subroutines for the MC modal symbol count (MBSSYMEC*Q) registers
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MODAL_SYMBOL_COUNT_H_
#define _MSS_MODAL_SYMBOL_COUNT_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/ecc/ecc_traits.H>

namespace mss
{

namespace ecc
{

namespace modal_symbol_count
{

///
/// @brief Read modal symbol count (MBSSYMEC*Q) register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_index the register index (0-9)
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode read(
    const fapi2::Target<T>& i_target,
    const uint32_t i_index,
    fapi2::buffer<uint64_t>& o_data )
{

    FAPI_ASSERT(i_index < TT::NUM_MBSSYM_REGS,
                fapi2::MSS_INVALID_INDEX_PASSED()
                .set_INDEX(i_index)
                .set_TARGET(i_target)
                .set_FUNCTION(SYMBOL_COUNT_READ),
                "%s Invalid index passed to mss::ecc::modal_symbol_count::read (%d)",
                mss::c_str(i_target),
                i_index);

    FAPI_TRY(mss::getScom(i_target, (TT::MODAL_SYM_COUNT0_REG + i_index), o_data));
    FAPI_INF("%s read_index %lu: 0x%016lx", mss::c_str(i_target), i_index, o_data);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write modal symbol count (MBSSYMEC*Q) register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_index the register index (0-9)
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode write(
    const fapi2::Target<T>& i_target,
    const uint32_t i_index,
    const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_ASSERT(i_index < TT::NUM_MBSSYM_REGS,
                fapi2::MSS_INVALID_INDEX_PASSED()
                .set_INDEX(i_index)
                .set_TARGET(i_target)
                .set_FUNCTION(SYMBOL_COUNT_WRITE),
                "%s Invalid index passed to mss::ecc::modal_symbol_count::write (%d)",
                mss::c_str(i_target),
                i_index);

    FAPI_TRY( mss::putScom(i_target, (TT::MODAL_SYM_COUNT0_REG + i_index), i_data) );
    FAPI_INF("%s write_index %lu: 0x%016lx", mss::c_str(i_target), i_index, i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_index the counter index
/// @param[in] i_value the value of the field
/// @note MBSSYMEC*Q_MODAL_SYMBOL_COUNTER_XX: Functional mode determined by MBSTRQ_Symbol_counter_mode:
/// @note if 00, 0:7 = Maint NCE counter for Symbol XX if 01, 0:3 = MCBIST error counter for nibble (XX/4)
/// @note and rank (XX%4)*2 4:7 = MCBIST error counter for nibble (XX/4) and rank ((XX%4)*2)+1 if 10,
/// @note 0:3 = MCBIST error counter for port XX/18 and nibble XX%18 4:7 = MCBIST error rank map for
/// @note port XX/18 and nibble XX%18
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_index, const uint64_t i_value )
{
    static_assert ( TT::MODAL_SYMBOL_COUNTERS_PER_REG  <= 8,
                    "mss::ecc_count::modal_symbol_count: Modal symbol count field index failed range check" );
    const uint64_t l_field = i_index % TT::MODAL_SYMBOL_COUNTERS_PER_REG;

    switch (l_field)
    {
        case 0:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_00, TT::MODAL_SYMBOL_COUNTER_00_LEN>(i_value);
            break;

        case 1:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_01, TT::MODAL_SYMBOL_COUNTER_01_LEN>(i_value);
            break;

        case 2:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_02, TT::MODAL_SYMBOL_COUNTER_02_LEN>(i_value);
            break;

        case 3:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_03, TT::MODAL_SYMBOL_COUNTER_03_LEN>(i_value);
            break;

        case 4:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_04, TT::MODAL_SYMBOL_COUNTER_04_LEN>(i_value);
            break;

        case 5:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_05, TT::MODAL_SYMBOL_COUNTER_05_LEN>(i_value);
            break;

        case 6:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_06, TT::MODAL_SYMBOL_COUNTER_06_LEN>(i_value);
            break;

        case 7:
            io_data.insertFromRight<TT::MODAL_SYMBOL_COUNTER_07, TT::MODAL_SYMBOL_COUNTER_07_LEN>(i_value);
            break;

        default:
            // Shouldn't happen due to modulo above, but here just in case - JLH
            FAPI_ERR("Modal symbol count field index failed range check");
            fapi2::Assert(false);
            break;
    }

    FAPI_INF("set_count(%d): 0x%02lx", l_field, i_value);
}

///
/// @brief get_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[in] i_index the counter index
/// @param[out] o_value the value of the field
/// @note MBSSYMEC*Q_MODAL_SYMBOL_COUNTER_XX: Functional mode determined by MBSTRQ_Symbol_counter_mode:
/// @note if 00, 0:7 = Maint NCE counter for Symbol XX if 01, 0:3 = MCBIST error counter for nibble (XX/4)
/// @note and rank (XX%4)*2 4:7 = MCBIST error counter for nibble (XX/4) and rank ((XX%4)*2)+1 if 10,
/// @note 0:3 = MCBIST error counter for port XX/18 and nibble XX%18 4:7 = MCBIST error rank map for
/// @note port XX/18 and nibble XX%18
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_count( const fapi2::buffer<uint64_t>& i_data, const uint64_t i_index, uint64_t& o_value )
{
    const uint64_t l_field = i_index % TT::MODAL_SYMBOL_COUNTERS_PER_REG;
    static_assert ( TT::MODAL_SYMBOL_COUNTERS_PER_REG  <= 8,
                    "mss::ecc_count::get_count: Modal symbol count field index failed range check" );

    switch (l_field)
    {
        case 0:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_00, TT::MODAL_SYMBOL_COUNTER_00_LEN>(o_value);
            break;

        case 1:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_01, TT::MODAL_SYMBOL_COUNTER_01_LEN>(o_value);
            break;

        case 2:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_02, TT::MODAL_SYMBOL_COUNTER_02_LEN>(o_value);
            break;

        case 3:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_03, TT::MODAL_SYMBOL_COUNTER_03_LEN>(o_value);
            break;

        case 4:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_04, TT::MODAL_SYMBOL_COUNTER_04_LEN>(o_value);
            break;

        case 5:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_05, TT::MODAL_SYMBOL_COUNTER_05_LEN>(o_value);
            break;

        case 6:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_06, TT::MODAL_SYMBOL_COUNTER_06_LEN>(o_value);
            break;

        case 7:
            i_data.extractToRight<TT::MODAL_SYMBOL_COUNTER_07, TT::MODAL_SYMBOL_COUNTER_07_LEN>(o_value);
            break;

        default:
            // shouldn't happen due to modulo above, but here just in case
            FAPI_ERR("Modal symbol count field index failed range check");
            fapi2::Assert(false);
            break;
    }

    FAPI_INF("get_count(%d): 0x%02lx", l_field, o_value);
}

} // close namespace modal_symbol_count

} // close namespace ecc

} // close namespace mss

#endif
