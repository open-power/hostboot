/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/translateTarget.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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

/**
 *  @file translateTarget.H
 *
 *  @brief API definition for translating host interface targets into
 *      targeting targets
 */

#ifndef __TRANSLATE_TARGET_H
#define __TRANSLATE_TARGET_H

#include <errl/errlentry.H>
#include <targeting/common/hbrt_target.H>

namespace TARGETING
{
    class Target;
}

namespace RT_TARG
{
    /**
     * @brief Convert a runtime target ID (target) into a TARGETING::Target
     *
     * @param[in] i_rtTargetId The runtime target ID
     * @param[out] o_pTarget The equivalent TARGETING::Target pointer
     *
     * @return error log handle on error else nullptr
     */
    errlHndl_t getHbTarget(
        TARGETING::rtChipId_t i_rtTargetId,
        TARGETING::Target *&  o_pTarget);
};

#endif // __TRANSLATE_TARGET_H


