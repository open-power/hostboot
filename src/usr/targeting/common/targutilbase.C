/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/targutilbase.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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
#include <ctype.h>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributeTank.H>

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

bool getPosFromFapiName(ATTR_FAPI_NAME_type & i_fapiname,
                        uint16_t & o_pos,
                        uint8_t & o_unitPos,
                        uint8_t & o_node)
{
    // valid string formats:
    // chip.unit:k0:nX:s0:pYY:cZ
    // chip:k0:nX:s0:pYY
    // node:k0:nX:s0
    // k0 (sys)
    // k0:s0 (sys)

    o_pos = AttributeTank::ATTR_POS_NA;
    o_unitPos = AttributeTank::ATTR_UNIT_POS_NA;
    o_node = AttributeTank::ATTR_NODE_NA;

    // check if we are sys
    if (strcmp(i_fapiname, "k0") == 0 ||
        strcmp(i_fapiname, "k0:s0") == 0)
    {
        return true;
    }

    // get the location of the first : which is after the type
    const char* skipType = strstr(i_fapiname, ":");

    // if skipType is null we have invalid string
    if (!skipType)
    {
        return false;
    }

    // make sure type that we skipped doesnt contain numbers
    // if it does we have invalid format
    for (char* p = i_fapiname; p < skipType; p++)
    {
        if (isdigit(*p))
        {
            return false;
        }
    }

    // get the location of each element of fapiname string
    const char* strNode = strstr(skipType, "n");
    const char* strPos = strstr(skipType, "p");
    const char* strUnit = strstr(skipType, "c");

    // must have node and cant have unitPos but not Pos
    if (!strNode || (strUnit && !strPos))
    {
        return false;
    }

    // verify string format is valid
    char fmt[16];
    if (strUnit)
    {
        strcpy(fmt, "k0:nX:s0:pXX:cX");
    }
    else if (strPos)
    {
        strcpy(fmt, "k0:nX:s0:pXX");
    }
    else
    {
        strcpy(fmt, "k0:nX:s0");
    }

    // we want second part of string without :
    skipType++;

    int fmtLen = strlen(fmt);
    int strLen = strlen(skipType);

    if (fmtLen != strLen)
    {
        return false;
    }

    for (int i = 0; i < fmtLen; i++)
    {
        // X in format str corresponds with digit
        if (fmt[i] == 'X')
        {
            if (!isdigit(skipType[i]))
            {
                return false;
            }
        }
        else if (fmt[i] != skipType[i])
        {
            // if not digit fmt must equal string
            return false;
        }
    }

    // get values from each part of string
    o_node = strtoul(strNode + 1, NULL, 10);

    if (strPos)
    {
        o_pos = strtoul(strPos + 1, NULL, 10);
    }

    if (strUnit)
    {
        o_unitPos = strtoul(strUnit + 1, NULL, 10);
    }

    return true;
}

}; // namespace TARGETING
