/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/target_fixture.H $ */
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
/// @file $Source: chips/p9/procedures/hwp/memory/ $
/// @brief Unit tests for memory apis
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI
#ifndef MSS_CEN_TARGET_FIXTURE_H_
#define MSS_CEN_TARGET_FIXTURE_H_

#include <ecmd_config_looper.H>

namespace mss
{
namespace test
{

///
/// @class target_test_fixture
/// @brief Test Fixture that iterates through the FapiTargetType configured for a system
/// @tparam FapiTargetType is one of the fapi2 target type
/// @tparam EcmdTargetChipUnitType is the chip unit type as allowed by ecmd
/// @note the FapiTargetType and the EcmdTargetChipUnitType should be related I.E.
/// FapiTargetType == fapi2::Target<fapi2::TARGET_TYPE_MCBIST> means EcmdTargetChipUnitType=="mcbist"
///
template<typename FapiTargetType, char const* EcmdTargetChipUnitType>
class target_test_fixture
{
    private:
        ecmdChipTarget iv_target;
        std::unique_ptr<mss::ecmd::ecmd_config_looper> iv_looper;

    public:
        ///
        /// @brief Constructor set's up target and initializes looper functionality
        ///
        target_test_fixture()
        {
            iv_target.chipType      = "memb";     //Also could be "p9n";
            iv_target.chipTypeState = ECMD_TARGET_FIELD_VALID;
            iv_target.chipUnitType  = EcmdTargetChipUnitType;   // Examples: mca mcs mba mcbist;
            iv_target.chipUnitTypeState = ECMD_TARGET_FIELD_VALID;
            iv_target.cageState     = ECMD_TARGET_FIELD_WILDCARD;
            iv_target.nodeState     = ECMD_TARGET_FIELD_WILDCARD;
            iv_target.slotState     = ECMD_TARGET_FIELD_WILDCARD;
            iv_target.posState      = ECMD_TARGET_FIELD_WILDCARD;
            iv_target.threadState   = ECMD_TARGET_FIELD_UNUSED;
            iv_target.chipUnitNumState = ECMD_TARGET_FIELD_WILDCARD;

            iv_looper.reset(new mss::ecmd::ecmd_config_looper(iv_target));
            REQUIRE(!iv_looper->status());
        }

        ///
        /// @brief Loops through each MCBIST target assocaited with this config and call the supplied
        /// function with the current target of the loop
        ///
        /// @param[in] test_fn is called when a target is found.
        ///
        void for_each_target(std::function<uint32_t(FapiTargetType&)> i_test_fn)
        {
            REQUIRE(i_test_fn);

            bool l_are_valid_targets_found(false);

            //Loops through targets
            while(iv_looper->next(iv_target))
            {
                // setting up a fapi2::Target from an ecmdChipTarget
                FapiTargetType l_fapi_target(&iv_target);

                // calling test function
                REQUIRE(!i_test_fn(l_fapi_target));

                // mark that valid targets has been found
                l_are_valid_targets_found = true;

            }

            REQUIRE(l_are_valid_targets_found);
        }

};

static constexpr char  g_ECMD_TARGET_MBA[] = "mba"; ///< Defines mba target string

using mba_target_test_fixture =
    target_test_fixture<fapi2::Target<fapi2::TARGET_TYPE_MBA>, g_ECMD_TARGET_MBA>;

} /* ns test */
} /* ns mss */

#endif //MSS_CEN_TARGET_FIXTURE_H_
