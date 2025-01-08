/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/targutilbase.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2025                        */
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
    // X represents where there must be digit
    // W represents where there could be digit
    char fmt[32];
    if (strUnit)
    {
        strcpy(fmt, "k0:nXW:s0:pXXWWW:cXWW");
    }
    else if (strPos)
    {
        strcpy(fmt, "k0:nXW:s0:pXXWWW");
    }
    else
    {
        strcpy(fmt, "k0:nXW:s0");
    }

    // we want second part of string without :
    skipType++;

    int fmtLen = strlen(fmt);
    int strLen = strlen(skipType);

    // since fmt can have more char than str
    // represent difference with w_diff
    int w_diff = 0;

    for (int i = 0; i < fmtLen; i++)
    {
        int str_i = i - w_diff;

        // X in format str corresponds with digit
        if (fmt[i] == 'X')
        {
            if (!isdigit(skipType[str_i]))
            {
                return false;
            }
        }
        else if (fmt[i] == 'W')
        {
            // digit is wildcard, could be digit or next part of string
            if (!isdigit(skipType[str_i]))
            {
                // if we arent digit but are next part of string,
                // mark that fmt has extra char, otherwise ret false
                if (skipType[str_i] == ':' ||
                    skipType[str_i] == '\0')
                {
                    w_diff++;
                }
                else
                {
                    return false;
                }
            }
        }
        else if (fmt[i] != skipType[str_i])
        {
            // if not digit fmt must equal string
            return false;
        }
    }

    if (strLen + w_diff != fmtLen)
    {
        return false;
    }

    uint64_t tmp_val;

    // get values from each part of string, check that they wont overflow integer
    tmp_val = strtoul(strNode + 1, NULL, 10);
    if (tmp_val > UINT8_MAX)
    {
        return false;
    }
    o_node = tmp_val;

    if (strPos)
    {
        tmp_val = strtoul(strPos + 1, NULL, 10);
        if (tmp_val > UINT16_MAX)
        {
            return false;
        }
        o_pos = tmp_val;
    }

    if (strUnit)
    {
        tmp_val = strtoul(strUnit + 1, NULL, 10);
        if (tmp_val > UINT8_MAX)
        {
            return false;
        }
        o_unitPos = tmp_val;
    }

    return true;
}

}; // namespace TARGETING
