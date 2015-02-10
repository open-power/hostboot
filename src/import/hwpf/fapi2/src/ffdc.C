/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: $                                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
 *  @file ffdc.C
 *  @brief Implements the FirstFailureData class
 */

#include <plat_trace.H>
#include <ffdc.H>
#include <error_info.H>

namespace fapi2
{

    ///
    /// @brief Add error information to this ffdc object
    /// @param[in] A pointer to a list of objects
    /// @param[in] A pointer to the list of entries
    /// @param[in] The count of how many entries there are
    /// @return void
    ///
    template<>
    void FirstFailureData<ReturnCode>::addErrorInfo(
        const void* const* i_pObjects,
        const ErrorInfoEntry* i_pEntries,
        const uint8_t i_count)
    {
        FAPI_DBG("%d entries", i_count);
        for (uint32_t i = 0; i < i_count; i++)
        {
            i_pEntries[i].addErrorInfo(iv_info, i_pObjects);
        }
    }



};
