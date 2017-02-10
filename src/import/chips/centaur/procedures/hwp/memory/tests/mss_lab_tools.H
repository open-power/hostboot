/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/mss_lab_tools.H $ */
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
/// @file mss_lab_tools.H
/// @brief primary lab tools include files
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI

#ifndef  _MSS_CEN_TOOLS_H_
#define  _MSS_CEN_TOOLS_H_

#include <memory>
#include <bitset>
#include <string>

#include <ecmdSharedUtils.H>
#include <fapi2.H>

#include <mss_log.H>

namespace mss
{
namespace lab
{

///
/// @class tool_init
/// @brief Handles many initilizations including maintaining lifetime of the ecmd library
///
class tool_init
{
    private:
        class impl; ///< Prototype for pimpl pattern
        std::unique_ptr<impl> iv_impl; ///< Holds instance of pimpl object
    public:
        ///
        /// @brief constructor for tool_init class
        /// @param[out]  o_rc will contain the ReturnCode SUCCESS if constructed ok
        /// @param[in] i_arg is passed through to the ecmd parser
        /// @param[in] i_argv is passed through to the ecmd parser
        ///
        tool_init(fapi2::ReturnCode& o_rc, int i_argc, char** i_argv);

        ///
        /// @brief destructor releases the pimpl instance
        ///
        ~tool_init();
};

///
/// @brief Evaluates the ReturnCode and if it has failed then logs the
///   i_fail_msg and aborts
/// @param[in] i_rc The ReturnCode to be evaluated.
/// @param[in] i_fail_msg The Failure message to be logged before aborting
///
void is_ok(const fapi2::ReturnCode& i_rc, const std::string& i_fail_msg);

///
/// @brief Evaluates the boolean expression and if it is false then logs the
///   i_fail_msg and aborts
/// @param[in] i_bool boolean result of an expression
/// @param[in] i_fail_msg The Failure message to be logged before aborting
///
void is_ok(const bool i_bool, const std::string& i_fail_msg);

///
/// @brief Retrieves the ecmd target based on the cronus string
/// @param[in] i_cronus_target The cronus target string to be evaluated
/// @param[out] o_ecmd_target Set the ecmdChipTarget pointer to proper target
/// @return FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode get_ecmd_target(const std::string& i_cronus_target,
                                  std::shared_ptr<ecmdChipTarget> o_ecmd_target);



///
/// @brief Retrieves a list of ecmd targets based on a configuration
/// @param[in] i_loop_type ecmd loop type. See Note below for suggested types
/// @param[in] i_chip_unit_type The cronus target string to be evaluated Ex. mcbist
/// @param[in] i_chip_type Optional Default="pu"
/// @return a list of ecmdChipTarget. Will be empty if not targets of that type found
/// @note i_loop_type suggestions (for descriptions, see enum ecmdLoopType_t in ecmd docs):
/// @note   ECMD_SELECTED_TARGETS_LOOP
/// @note   ECMD_SELECTED_TARGETS_LOOP_DEFALL
/// @note   ECMD_ALL_TARGETS_LOOP
///
std::vector<std::shared_ptr<ecmdChipTarget> > get_ecmd_targets(const ecmdLoopType_t& i_loop_type,
        const std::string& i_chip_unit_type, const std::string& i_chip_type = "pu");

///
/// @brief Retrieves the FAPI2 target based on the ecmdChipType
/// @warning must not let the ecmdChipTarget be deallocated while using the returned target
/// @tparm T Is a fapi2::TargetType
/// @param[in] i_ecmd_target The ecmdChipTarget object to be converted.
/// @param[out] o_fapi2_target The fapi2 target that will be set to the proper
/// target upon return
/// @return FAPI2_RC_SUCCESS if successful
///
template <fapi2::TargetType T>
fapi2::ReturnCode get_fapi2_target(std::shared_ptr<ecmdChipTarget> i_ecmd_target,
                                   fapi2::Target<T>& o_fapi2_target)
{
    //Instantiate a fapi2 target of this type using the ecmdChipTarget and assign
    // to the return target.
    o_fapi2_target = fapi2::Target<T>(i_ecmd_target.get());

    return fapi2::FAPI2_RC_SUCCESS;
}



} /* ns lab */
} /* ns mss */

#endif /* _MSS_LAB_TOOLS_H_ */
