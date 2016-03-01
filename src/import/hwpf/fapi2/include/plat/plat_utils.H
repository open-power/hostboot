/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/plat/plat_utils.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/**
 * @file plat_utils.H
 * @brief platform definitions for fapi2 targets
 */

#ifndef __FAPI2_PLAT_UTILS__
#define __FAPI2_PLAT_UTILS__

#include <stdint.h>

namespace fapi2
{
template<TargetType T>
inline ReturnCode platSpecialWakeup( const Target<T>& i_target, bool i_enable)
{
    static_cast<void>(i_enable);
    static_cast<void>(i_target);

    if(is_same<T, TARGET_TYPE_PROC_CHIP>() )
    {
        FAPI_INF("do proc special wakeup stuff");
    }
    else if(is_same<T, TARGET_TYPE_CORE>() )
    {
        FAPI_INF("do core special wakeup stuff");
    }
    else if(is_same<T, TARGET_TYPE_EX>() )
    {
        FAPI_INF("do ex speical wakeup stuff");
    }
    else if(is_same<T, TARGET_TYPE_EQ>() )
    {
        FAPI_INF("do eq special wakeup stuff");
    }
    else
    {
        FAPI_INF("should never get here");
    }

    return FAPI2_RC_SUCCESS;
}

}

#endif
