/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/common/runtime_utils.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include <vector>
#include <utility>
#include <pnor/pnorif.H>

namespace RUNTIME
{

// Pair indicating if a PNOR section is expected to have a secure header
// regardless of the compiler options
typedef std::pair<PNOR::SectionId, bool> PreVerifyPair;
// A vector of all PNOR sections that are pre-verified for runtime
typedef std::vector<PreVerifyPair> PreVerifyVector;

// PNOR sections that will be pre-verified and loaded into HB reserved memory
extern const PreVerifyVector preVerifiedPnorSections;

/**
 * @brief Determines whether the given section is pre-verified and loaded into
 *        hostboot reserved memory
 *
 * @param[in] i_section PNOR section to test.
 *
 * @return bool True if pre-verified section, false otherwise.
 */
bool isPreVerifiedSection(const PNOR::SectionId i_section);

/**
 * @brief Determines whether the given section is pre-verified and if so, if
 *        it's expected to be secure
 *
 * @param[in] i_section PNOR section to test.
 *
 * @return bool True if pre-verified section is expected to be secure,
*              false otherwise.
 */
bool isPreVerifiedSectionSecure(const PNOR::SectionId i_section);

}