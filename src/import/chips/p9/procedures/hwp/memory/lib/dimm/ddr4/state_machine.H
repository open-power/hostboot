/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/state_machine.H $ */
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
/// @file state_machine.H
/// @brief state_machine delcaration
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_STATE_MACHINE_H_
#define _MSS_STATE_MACHINE_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/checker.H>

namespace mss
{

enum class transition
{
    RISING_EDGE, ///< Looking for 1st Low to High transition
    FALLING_EDGE, ///< Looking for 1st High to Low transition
};

enum class fsm_state
{
    UNINITIALIZED, ///< Initial state
    HIGH, ///< High state (logical 1)
    LOW, ///< Low state (logical 0)
    DONE, ///< Final state (First 1->0 or 0->1 transition)
};

namespace ddr4
{
namespace db
{

///
/// @class state_machine
/// @brief State machine for LRDIMM training
///
class state_machine
{
    public:
        fsm_state iv_state;
        uint64_t iv_delay;

        ///
        /// @brief Default ctor
        /// @param[in] i_target DIMM target
        ///
        state_machine(const fapi2::Target< fapi2::TARGET_TYPE_DIMM >& i_target):
            iv_state(fsm_state::UNINITIALIZED),
            iv_delay(0),
            iv_target(i_target)
        {}

        ///
        /// @brief Default dctor
        ///
        ~state_machine() = default;

        ///
        /// @brief Sets current state
        /// @tparam T first transition we are looking for
        /// @param[in] i_data DRAM DQ data
        /// @param[in] i_nibble current nibble
        /// @param[in] i_phase_timing current phase step
        ///
        template< transition T >
        fapi2::ReturnCode next_transition( const fapi2::variable_buffer& i_data,
                                           const uint64_t i_nibble,
                                           const uint64_t i_phase_timing)
        {
            switch(iv_state)
            {
                case fsm_state::UNINITIALIZED:
                    uninitialized(i_data, i_nibble, i_phase_timing);
                    break;

                case fsm_state::HIGH:
                    high<T>(i_data, i_nibble, i_phase_timing);
                    break;

                case fsm_state::LOW:
                    low<T>(i_data, i_nibble, i_phase_timing);
                    break;

                case fsm_state::DONE:
                    FAPI_INF("%s No state change. Already in DONE state.", mss::c_str(iv_target) );
                    break;

                default:
                    // By default we are unitialized, we switch state based on
                    // AADR & AAER register data that represents DRAM DQ data.
                    // If we got here something bad happened, iv_state was corrupted somehow.
                    // Lets tell someone with FFDC
                    FAPI_TRY( check::invalid_dq_data(iv_target, false, i_data, i_phase_timing, i_nibble) );
                    break;
            }// switch

        fapi_try_exit:
            return fapi2::current_err;
        }

    private:
        static constexpr size_t NIBBLE_OFFSET = 4;
        const fapi2::Target< fapi2::TARGET_TYPE_DIMM > iv_target;
        char iv_str_buffer[fapi2::MAX_ECMD_STRING_LEN];

        ///
        /// @brief Helper function to set uninitialized state transition
        /// @param[in] i_data DRAM DQ data
        /// @param[in] i_nibble current nibble
        /// @param[in] i_phase_timing current phase step
        ///
        void uninitialized( const fapi2::variable_buffer& i_data,
                            const uint64_t i_nibble,
                            const uint64_t i_phase_timing );

        ///
        /// @brief Helper function to set high state transition
        /// @tparam T first transition we are looking for
        /// @param[in] i_data DRAM DQ data
        /// @param[in] i_nibble current nibble
        /// @param[in] i_phase_timing current phase step
        ///
        template< transition T >
        void high( const fapi2::variable_buffer& i_data,
                   const uint64_t i_nibble,
                   const uint64_t i_phase_timing );

        ///
        /// @brief Helper function to set low state transition
        /// @tparam T first transition we are looking for
        /// @param[in] i_data DRAM DQ data
        /// @param[in] i_nibble current nibble
        /// @param[in] i_phase_timing current phase step
        ///
        template< transition T >
        void low( const fapi2::variable_buffer& i_data,
                  const uint64_t i_nibble,
                  const uint64_t i_phase_timing );

        ///
        /// @brief Helper function for trace boilerplate
        /// @param[in] i_data DRAM DQ data
        /// @param[in] i_nibble current nibble
        /// @param[in] i_phase_timing current phase step
        ///
        void print_debug( const fapi2::variable_buffer& i_data,
                          const uint64_t i_nibble,
                          const uint64_t i_phase_timing );
};

}// db
}// ddr4
}// mss

#endif
