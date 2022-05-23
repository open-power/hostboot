/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lab/sdk/phy/ody_ate_load_dmem_scoms.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

// Note: Synopsys, Inc. owns the original copyright of the code
// This file is ported into IBM's code stream with the permission of Synopsys, Inc.

// EKB-Mirror-To: hostboot
///
/// @file ody_ate_load_dmem_scoms.H
/// @brief Load the synopsys scoms for dmem
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_ATE_LOAD_DMEM_SCOMS_H
#define _ODY_ATE_LOAD_DMEM_SCOMS_H

#include <fapi2.H>
#include <generic/memory/lab/mss_lab_input_processing.H>

namespace mss
{
namespace lab
{
namespace ody
{
namespace load_ate_dmem_scoms
{
///
/// @brief Load the synopsys dmem scom registers
/// @param[in] i_target - the memory port on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode load_dmem_scoms( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Input helper class
///
class input_helper
{
    public:
        // Help screens
        static constexpr mss::lab::input::traits HELP1 = mss::lab::input::create_traits< mss::lab::input::process_type::FLAG,
                                                 mss::lab::input::required::OPTIONAL>(
                                                         "-h",
                                                         "help screen flag",
                                                         "false");
        static constexpr mss::lab::input::traits HELP2 = mss::lab::input::create_traits< mss::lab::input::process_type::FLAG,
                                                 mss::lab::input::required::OPTIONAL>(
                                                         "--help",
                                                         "help screen flag",
                                                         "false");

        static const std::vector<std::pair<mss::lab::input::traits, std::vector<std::string>>> FIELDS;
};

///
/// @class user_inputs
/// @brief User inputs for load dmem scoms tool
///
struct user_inputs
{
    ///
    /// @brief Default constructor
    ///
    user_inputs() = default;

    ///
    /// @brief Default destructor
    ///
    ~user_inputs() = default;

    ///
    /// @brief Equals comparison operator
    /// @param[in] i_rhs the structure to compare against
    /// @return true if the two structures compare
    ///
    bool operator==(const user_inputs& i_rhs) const
    {
        return true;
    }
};

///
/// @brief help screen for load dmem scoms tool
///
void help();

///
/// @brief Processes the input
/// @param[in,out] io_argc number of arguments to process
/// @param[in,out] io_argv arguments to process
/// @param[out] o_user_inputs user inputs
/// @return SUCCESS iff arguments were processed correctly
///
fapi2::ReturnCode process_inputs(int& io_argc,
                                 char* io_argv[],
                                 user_inputs& o_user_inputs);

} // ns load_ate_dmem_scoms
} // ns ody
} // ns lab
} // ns mss

#endif
