/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/targutilbase.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
#include <targeting/common/targetservice.H>

#ifdef __HOSTBOOT_MODULE
// Attribute ID to string name map
#include <targAttrIdToName.H>

// mutex
#include <sys/sync.h>
#endif

namespace TARGETING
{

#ifdef __HOSTBOOT_MODULE
mutex_t g_attrNamesMapMutex = MUTEX_INITIALIZER;
#endif

// master sentinel defined here to make available before targeting is up
Target* const MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    = (sizeof(void*) == 4) ?
        reinterpret_cast<TARGETING::Target* const>(0xFFFFFFFF)
      : reinterpret_cast<TARGETING::Target* const>(0xFFFFFFFFFFFFFFFFULL);

/**
 * @brief Safely fetch the HUID of a Target
 */

uint32_t get_huid( const Target* i_target )
{
    uint32_t huid = 0;
    if( i_target == NULL )
    {
        huid = 0x0;
    }
    else if( i_target == MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        huid = 0xFFFFFFFF;
    }
    else
    {
        i_target->tryGetAttr<ATTR_HUID>(huid);
    }
    return huid;
}

#ifdef __HOSTBOOT_MODULE
const char* getAttrName(const ATTRIBUTE_ID i_attrId, const bool i_rwOnly)
{
    const char* ret = nullptr;

    // The maps may be found in obj/genfiles/targAttrIdToName.H/C

    mutex_lock(&g_attrNamesMapMutex);
    // Check the RW first
    if(g_rwAttrIdToNameMap.count(i_attrId) > 0)
    {
        ret = g_rwAttrIdToNameMap.at(i_attrId);
    }
    // Didn't find the attr in RW-only; check the non-RW map
    if(!i_rwOnly &&
       (g_nonRwAttrIdToNameMap.count(i_attrId) > 0))
    {
        ret = g_nonRwAttrIdToNameMap.at(i_attrId);
    }
    mutex_unlock(&g_attrNamesMapMutex);

    return ret;
}
#endif

}; // namespace TARGETING
