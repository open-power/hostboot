/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/state_machine.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file state_machine.C
/// @brief Implementation of the state_machine
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <c_str.H>
#include <lib/dimm/ddr4/state_machine.H>

namespace mss
{

///
/// @brief non-target c_str general declaration
/// @tparam T - type you want the const char * for
/// @param[in] i_input a variable_buffer (expects a 72 bit buffer)
/// @return const char *
///
template< >
const char* c_str( const fapi2::variable_buffer& i_input )
{
    if( i_input.getBitLength() != MAX_DQ_BITS )
    {
        // User passed in a variable_buffer of invalid size
        FAPI_ERR("Expecting a %d bit variable buffer, %d bit buffer received.",
                 MAX_DQ_BITS,
                 i_input.getBitLength());

        fapi2::Assert(false);
    }

    constexpr uint64_t AADR_START = 0;
    constexpr uint64_t AADR_LEN = 64;

    constexpr uint64_t AAER_START = 64;
    constexpr uint64_t AAER_LEN = 8;

    uint64_t l_aaer = 0; // ecc
    uint64_t l_aadr = 0; // data

    FAPI_TRY( i_input.extractToRight(l_aadr, AADR_START, AADR_LEN),
              "Failed to extract AADR data, start: %d, len: %d", AADR_START, AADR_LEN);

    FAPI_TRY( i_input.extractToRight(l_aaer, AAER_START, AAER_LEN),
              "Failed to extract AAER data, start: %d, len: %d", AAER_START, AAER_LEN);

    // We are just printing out 18 nibbles worth of data
    sprintf(c_str_storage, "0x%016lx%02lx", l_aadr, l_aaer);
    return c_str_storage;

fapi_try_exit:
    // Best we can do? If we extracting data from the buffer fails,
    // we don't fail-out but we get a string that states "badness" - AAM
    FAPI_ERR("Failed to extract data from variable_buffer");
    sprintf(c_str_storage, "ERROR");
    return c_str_storage;
}

///
/// @brief Helper function for trace boilerplate
/// @param[in] i_data DRAM DQ data
/// @param[in] i_nibble current nibble
/// @param[in] i_phase_timing current phase step
///
inline void state_machine::print_debug( const fapi2::variable_buffer& i_data,
                                        const uint64_t i_nibble,
                                        const uint64_t i_phase_timing )
{
    // Can't use 2 mss::c_str functions inside a trace
    // because of sharing issues with c_str_storage
    // so we use a c_str buffer specifically for this class
    strcpy(iv_str_buffer, mss::c_str(i_data));

    FAPI_DBG( "%s phase timing: %d tck, nibble: %d, data: %s",
              mss::c_str(iv_target), i_phase_timing, i_nibble, iv_str_buffer);
}

///
/// @brief Helper function to set uninitialized state transition
/// @param[in] i_data DRAM DQ data
/// @param[in] i_nibble current nibble
/// @param[in] i_phase_timing current phase step
///
void state_machine::uninitialized( const fapi2::variable_buffer& i_data,
                                   const uint64_t i_nibble,
                                   const uint64_t i_phase_timing )
{
    print_debug(i_data, i_nibble, i_phase_timing);

    if( i_data.isBitSet(i_nibble * NIBBLE_OFFSET, BITS_PER_NIBBLE) )
    {
        FAPI_INF( "%s Going from UNINITIALIZED state to HIGH state", mss::c_str(iv_target) );
        iv_state = fsm_state::HIGH;
    }

    else
    {
        FAPI_INF( "%s Going from UNINITIALIZED state to LOW state", mss::c_str(iv_target) );
        iv_state = fsm_state::LOW;
    }

}

///
/// @brief Helper function to set high state transition
/// @param[in] i_data DRAM DQ data
/// @param[in] i_nibble current nibble
/// @param[in] i_phase_timing current phase step
///
template< >
void state_machine::high<transition::FALLING_EDGE>( const fapi2::variable_buffer& i_data,
        const uint64_t i_nibble,
        const uint64_t i_phase_timing )
{
    print_debug(i_data, i_nibble, i_phase_timing);

    if( i_data.isBitClear(i_nibble * NIBBLE_OFFSET, BITS_PER_NIBBLE) )
    {
        FAPI_INF( "%s Found first HIGH to LOW state transition. Setting state to DONE",
                  mss::c_str(iv_target) );

        iv_state = fsm_state::DONE;
        iv_delay = i_phase_timing;
        return;
    }

    // If we get here, do nothing, no state change
    FAPI_INF( "%s No state change. Already in HIGH state.", mss::c_str(iv_target) );
}

///
/// @brief Helper function to set high state transition
/// @param[in] i_data DRAM DQ data
/// @param[in] i_nibble current nibble
/// @param[in] i_phase_timing current phase step
///
template< >
void state_machine::high<transition::RISING_EDGE>( const fapi2::variable_buffer& i_data,
        const uint64_t i_nibble,
        const uint64_t i_phase_timing )
{
    print_debug(i_data, i_nibble, i_phase_timing);

    if( i_data.isBitClear(i_nibble * NIBBLE_OFFSET, BITS_PER_NIBBLE) )
    {
        FAPI_INF( "%s Going from HIGH state to LOW state", mss::c_str(iv_target) );
        iv_state = fsm_state::LOW;
        return;
    }

    // If we get here, do nothing, no state change
    FAPI_INF( "%s No state change. Already in HIGH state.", mss::c_str(iv_target) );
}

///
/// @brief Helper function to set low state transition
/// @param[in] i_data DRAM DQ data
/// @param[in] i_nibble current nibble
/// @param[in] i_phase_timing current phase step
///
template< >
void state_machine::low<transition::FALLING_EDGE>( const fapi2::variable_buffer& i_data,
        const uint64_t i_nibble,
        const uint64_t i_phase_timing  )
{
    print_debug(i_data, i_nibble, i_phase_timing);

    if( i_data.isBitSet(i_nibble * NIBBLE_OFFSET, BITS_PER_NIBBLE) )
    {
        FAPI_INF( "%s Going from LOW state to HIGH state",  mss::c_str(iv_target) );
        iv_state = fsm_state::HIGH;
        return;
    }

    // If we get here, do nothing, no state change
    FAPI_INF( "%s No state change. Already in LOW state.", mss::c_str(iv_target) );
}

///
/// @brief Helper function to set low state transition
/// @param[in] i_data DRAM DQ data
/// @param[in] i_nibble current nibble
/// @param[in] i_phase_timing current phase step
///
template< >
void state_machine::low<transition::RISING_EDGE>( const fapi2::variable_buffer& i_data,
        const uint64_t i_nibble,
        const uint64_t i_phase_timing  )
{
    print_debug(i_data, i_nibble, i_phase_timing);

    if( i_data.isBitSet(i_nibble * NIBBLE_OFFSET, BITS_PER_NIBBLE) )
    {
        FAPI_INF( "%s Found first LOW to HIGH state transition. Setting state to DONE",
                  mss::c_str(iv_target) );

        iv_state = fsm_state::DONE;
        iv_delay = i_phase_timing;
        return;
    }

    // If we get here, do nothing, no state change
    FAPI_INF( "%s No state change. Already in LOW state.",  mss::c_str(iv_target) );
}

}// mss
