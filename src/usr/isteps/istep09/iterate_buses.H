/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/iterate_buses.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

/* @file This is an implementation file that defines the iterate_buses function,
 *       which is used in both fabric_dl_pre_trainadv and
 *       fabric_dl_post_trainadv. It should not be used anywhere else.
 */

/**
 * @brief Call invoke_hwp on each pair of buses in i_buses. If a bus is an
 *        SMPGROUP, use its parent IOHS instead.
 */
static void iterate_buses(const EDI_EI_INITIALIZATION::TargetPairs_t& i_buses, IStepError& i_stepError)
{
    // For SMPGROUP targets, we train their parent IOHS. Use this map to keep
    // track of which IOHSes have already been trained.
    std::map<const Target*, bool> l_alreadyTrained;

    // Iterate over every unique pair of IOHS targets and call the HWP on them.
    for (const auto l_pair : i_buses)
    {
        const Target* l_train_a = l_pair.first;
        const Target* l_train_b = l_pair.second;

        if (l_train_a->getAttr<ATTR_TYPE>() == TYPE_SMPGROUP)
        {
            l_train_a = getImmediateParentByAffinity(l_train_a);
            l_train_b = getImmediateParentByAffinity(l_train_b);
        }

        if (l_alreadyTrained.find(l_train_a) != end(l_alreadyTrained))
        {
            continue;
        }

        l_alreadyTrained[l_train_a] = true;

        invoke_hwp({ l_train_a }, { l_train_b }, i_stepError);

        // Continue even when an error occurs, so that we collect the errors and
        // report them all at the end.
    }
}
