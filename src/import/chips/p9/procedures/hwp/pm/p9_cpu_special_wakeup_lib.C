/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup_lib.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <p9_cpu_special_wakeup_lib.H>
#include <stdint.h>

namespace p9specialWakeup
{
/**
 * String names for the Entities.  These must match the PROC_SPCWKUP_ENTITY
 * enum.
 */

/**
 * Strings associated with special wake up.
 */
const char* SPWK_MSG_LIST[] =
{
    "Assert: ",
    "Deassert",
    "Clean-up Deassert"
};

/**
 * String names for the Entities.  These must match the PROC_SPCWKUP_ENTITY
 * enum.
 */

const char* PROC_SPCWKUP_ENTITY_NAMES[] =
{
    "OTHER",
    "FSP",
    "OCC",
    "HYP",
    "HOST",
    "SPW_ALL"
};

void blockWakeupRecurssion( const fapi2::Target <fapi2::TARGET_TYPE_EQ>&  i_quadTarget,
                            RecurssionOp i_spWakeUpInProg )
{
    FAPI_INF(">> blockWakeupRecurssion" );
    uint8_t attrVal = i_spWakeUpInProg;

    auto l_func_ex_vector =
        i_quadTarget.getChildren<fapi2::TARGET_TYPE_EX>( fapi2::TARGET_STATE_FUNCTIONAL );

    FAPI_ATTR_SET( fapi2::ATTR_EQ_INSIDE_SPECIAL_WAKEUP,
                   i_quadTarget,
                   attrVal );

    for( auto itEx : l_func_ex_vector )
    {
        auto l_func_core_vector =
            itEx.getChildren<fapi2::TARGET_TYPE_CORE>( fapi2::TARGET_STATE_FUNCTIONAL );

        FAPI_ATTR_SET( fapi2::ATTR_EX_INSIDE_SPECIAL_WAKEUP,
                       itEx,
                       attrVal );

        for( auto itCore : l_func_core_vector )
        {
            FAPI_ATTR_SET( fapi2::ATTR_CORE_INSIDE_SPECIAL_WAKEUP,
                           itCore,
                           attrVal );
        }
    }
}

}


