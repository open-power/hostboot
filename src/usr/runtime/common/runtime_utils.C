/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/common/runtime_utils.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#include <runtime/common/runtime_utils.H>

namespace RUNTIME
{

// -- Images expected to have secure headers
//   -- OCC
//   -- WOFDATA
//   -- HCODE
// -- Images that never have secure headers
///  -- RINGOVD
const PreVerifyVector preVerifiedPnorSections {
    {PNOR::OCC, true},
    {PNOR::WOFDATA, true},
    {PNOR::HCODE, true},
    {PNOR::RINGOVD, false},
};

bool isPreVerifiedSection(const PNOR::SectionId i_section)
{
    bool l_result = false;
    auto it = find_if(preVerifiedPnorSections.begin(),
                      preVerifiedPnorSections.end(),
                      [&i_section](const PreVerifyPair& p)
                      {
                          return p.first == i_section;
                      });

    if (it != preVerifiedPnorSections.end())
    {
        l_result = true;
    }

    return l_result;
}

bool isPreVerifiedSectionSecure(const PNOR::SectionId i_section)
{
    bool l_result = false;
    auto it = find_if(preVerifiedPnorSections.begin(),
                      preVerifiedPnorSections.end(),
                      [&i_section](const PreVerifyPair& p)
                      {
                          return p.first == i_section;
                      });

    if (it != preVerifiedPnorSections.end())
    {
        l_result = it->second;
    }

    return l_result;
}

}
