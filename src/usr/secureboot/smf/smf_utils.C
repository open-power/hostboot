/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/smf/smf_utils.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#include <secureboot/smf_utils.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/util.H>
#include <secureboot/secure_reasoncodes.H>
#include <assert.h>
#include <limits.h>

namespace SECUREBOOT
{

namespace SMF
{

const uint64_t MIN_SMF_MEMORY_AMT = 256 * MEGABYTE;
const uint64_t MIN_MEM_RESERVED_FOR_HB = 8 * GIGABYTE;

bool isSmfEnabled()
{
    uint8_t l_smfEnabled = true;

    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    crit_assert(l_sys != nullptr);
    l_smfEnabled = l_sys->getAttr<TARGETING::ATTR_SMF_CONFIG>();
    return l_smfEnabled;
}

} // namespace SMF

} // namespace SECUREBOOT
