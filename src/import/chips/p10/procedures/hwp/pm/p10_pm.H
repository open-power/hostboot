/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
///
/// @file p10_pm.H
/// @brief Common header for Power Manangement procedures
///

// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HS

#ifndef _PM_H_
#define _PM_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Macro Defintions
//------------------------------------------------------------------------------

extern const char* PM_FLOW_MODE_NAME[];

#define PM_FLOW_MODE_NAME_STRINGS   \
    {                       \
        "PM_HALT",              \
        "PM_START",             \
        "PM_SETUP",             \
        "PM_SETUP_PIB",         \
        "PM_SETUP_ALL",         \
        "PM_RESET_SOFT",        \
        "PM_INIT_SOFT",         \
        "PM_INIT_SPECIAL"       \
        "PM_START_RUNTIME"      \
    }

#define PM_MODE_NAME_VAR PM_FLOW_MODE_NAME[] = PM_FLOW_MODE_NAME_STRINGS

#define PM_MODE_NAME(_mi_mode)(         \
                                        PM_FLOW_MODE_NAME[_mi_mode-1]    \
                              )




// Incase the attribute does not a have a value previously assigned,
// assign the user given default value
#define GETATTR_DEFAULT(_i_attr, _i_attr_name, _i_target, _i_value, _i_defVal){\
        FAPI_ATTR_GET(_i_attr, _i_target, _i_value); \
        if (!_i_value) \
        { \
            FAPI_DBG("Attribute %s set to default = 0x%x",_i_attr_name,_i_defVal); \
            _i_value = _i_defVal;\
        } \
        FAPI_INF("Value read from attribute %s = 0x%x", _i_attr_name,_i_value);\
    }

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
namespace pm
{

enum PM_FLOW_MODE
{
    PM_HALT           = 0x1,
    PM_START          = 0x2,
    PM_SETUP          = 0x3,
    PM_SETUP_PIB      = 0x4,
    PM_SETUP_ALL      = 0x5,
    PM_RESET_SOFT     = 0x6,
    PM_INIT_SOFT      = 0x7,
    PM_INIT_SPECIAL   = 0x8,
    PM_START_RUNTIME  = 0x9, //This enum is for internal purpose and is used to know we are in runtime ipl mode.
};

enum PM_DUMP_MODE
{
    PM_DUMP,
    PM_NO_DUMP,
};

} // end of namespace pm


#endif // _PM_H_
