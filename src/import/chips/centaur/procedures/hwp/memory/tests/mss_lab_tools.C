/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/mss_lab_tools.C $ */
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
/// @brief Implementation file for the Memory Labs Subsystem
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI

#include <mss_lab_tools.H>
#include <ecmd_facade.H>

namespace mss
{
namespace lab
{

///
/// @class tool_init::impl
/// @brief Impl part of Pimpl Pattern of the tool_init object
/// This class is responsible for holding an instance of the ecmd library
/// and for passing through command line arguments for ecmd.
///
class tool_init::impl
{
    private:
        /// iv_ecmd_facade holds an instance of the ecmd facade
        std::unique_ptr<mss::ecmd::ecmd_facade> iv_ecmd_facade;

    public:

        ///
        /// @brief Constructor
        /// @param[out] o_rc  will contain the ReturnCode SUCCESS if constructed ok
        /// @param[in] i_argc is passed through to the ecmd parser
        /// @param[in] i_argv is passed through to the ecmd parser
        ///
        impl(fapi2::ReturnCode& o_rc, int i_argc, char** i_argv)
        {
            uint64_t l_rc(0);
            iv_ecmd_facade.reset(
                new mss::ecmd::ecmd_facade(l_rc, i_argc, i_argv));
            o_rc = l_rc;
        }


        ///
        /// @brief destructor will release the ecmd facade instance
        ///
        ~impl()
        {
            iv_ecmd_facade.reset();
        }
};


///
/// @brief constructor for tool_init class
/// @param[out] o_rc will contain the ReturnCode SUCCESS if constructed ok
/// @param[in] i_argc passed through to the ecmd parser
/// @param[in] i_argv passed through to the ecmd parser
///
tool_init::tool_init(fapi2::ReturnCode& o_rc, int i_argc, char** i_argv)
    : iv_impl(new tool_init::impl(o_rc, i_argc, i_argv))
{
    if(!o_rc)
    {
        // Initializes the fapi2 library
        o_rc = fapi2InitExtension();

        if(o_rc)
        {
            mss::log(mss::ERROR, "Failed initializing fapi2");
        }

    }
}

///
/// @brief destructor releases the pimpl instance
///
tool_init::~tool_init()
{
    iv_impl.reset();
}

///
/// @brief Evaluates the ReturnCode and if it has failed then logs the
///   i_fail_msg and aborts
/// @param[in] i_rc The ReturnCode to be evaluated.
/// @param[in] i_fail_msg The Failure message to be logged before aborting
///
void is_ok(const fapi2::ReturnCode& i_rc, const std::string& i_fail_msg)
{
    if(i_rc)
    {
        log(FATAL, i_fail_msg);
    }
}

///
/// @brief Evaluates the boolean expression and if it is false then logs the
///   i_fail_msg and aborts
/// @param[in] i_rc The ReturnCode to be evaluated.
/// @param[in] i_fail_msg The Failure message to be logged before aborting
///
void is_ok(const bool i_bool, const std::string& i_fail_msg)
{
    if( ! i_bool)
    {
        log(FATAL, i_fail_msg);
    }
}

///
/// @brief Retrieves the ecmd target based on the cronus string
/// @param[in] i_cronus_target The cronus target string to be evaluated
/// @param[out] o_ecmd_target Sets the ecmdChipTarget pointer to proper target
/// @return FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode get_ecmd_target(const std::string& i_cronus_target,
                                  std::shared_ptr<ecmdChipTarget> o_ecmd_target)
{
    auto l_ecmd_rc = ecmdReadTarget(i_cronus_target, *o_ecmd_target);

    if(l_ecmd_rc)
    {
        log(ERROR, "Failed to find ecmd target");
        return l_ecmd_rc;
    }

    return fapi2::FAPI2_RC_SUCCESS;
}


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
        const std::string& i_chip_unit_type, const std::string& i_chip_type)
{
    //Initialize target type to an initial search state.
    ecmdChipTarget l_target;
    l_target.chipType      = i_chip_type;
    l_target.chipTypeState = ECMD_TARGET_FIELD_VALID;
    l_target.chipUnitType  = i_chip_unit_type;
    l_target.chipUnitTypeState = ECMD_TARGET_FIELD_VALID;
    l_target.cageState     = ECMD_TARGET_FIELD_WILDCARD;
    l_target.nodeState     = ECMD_TARGET_FIELD_WILDCARD;
    l_target.slotState     = ECMD_TARGET_FIELD_WILDCARD;
    l_target.posState      = ECMD_TARGET_FIELD_WILDCARD;
    l_target.threadState   = ECMD_TARGET_FIELD_UNUSED;
    l_target.chipUnitNumState = ECMD_TARGET_FIELD_WILDCARD;

    //Initialize the looper
    ecmdLooperData l_looper;
    uint32_t l_rc = ecmdConfigLooperInit(l_target,
                                         i_loop_type,
                                         l_looper);
    is_ok(fapi2::ReturnCode(l_rc), "Failed Initialization Chip Loop");

    //Loop through any searches and add them to the return list.
    std::vector<std::shared_ptr<ecmdChipTarget> > l_target_list;

    while(ecmdConfigLooperNext(l_target, l_looper))
    {
        //Using shared pointers because it is easier to pass around swig
        auto l_ecmd_target = std::make_shared<ecmdChipTarget>(l_target);

        //Push pointer target onto vector
        l_target_list.push_back(l_ecmd_target);

        logf(TRACE,
             "ECMD Target Found k%d:n%d:s%d:p%02d:c%d chip type = %s %s",
             l_ecmd_target->cage,
             l_ecmd_target->node,
             l_ecmd_target->slot,
             l_ecmd_target->pos,
             l_ecmd_target->core,
             l_ecmd_target->chipType.c_str(),
             l_ecmd_target->chipUnitType.c_str() );

    }

    return l_target_list;
}


} /* ns lab */
} /* ns mss */
