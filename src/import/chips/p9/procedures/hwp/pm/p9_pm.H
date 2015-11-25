/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_pm.H
/// @brief Common header for Power Manangement procedures
///

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HS

#ifndef _P9_PM_H_
#define _P9_PM_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Macro Defintions
//------------------------------------------------------------------------------

// Create a multi-bit mask of @a n bits starting at bit @a b
#ifndef BITS
    #define BITS(b, n) ((0xffffffffffffffffull << (64 - (n))) >> (b))
#endif

// Create a single bit mask at bit @a b
#ifndef BIT
    #define BIT(b) BITS((b), 1)
#endif

extern const char* p9_PM_FLOW_MODE_NAME[];

#define PM_FLOW_MODE_NAME   \
    {                           \
        "PM_RESET",             \
        "PM_INIT",              \
        "PM_SETUP",             \
        "PM_SETUP_PIB",         \
        "PM_SETUP_ALL",         \
        "PM_RESET_SOFT",        \
        "PM_INIT_SOFT",         \
        "PM_INIT_SPECIAL"       \
    }

#define PM_MODE_NAME_VAR p9_PM_FLOW_MODE_NAME[] = PM_FLOW_MODE_NAME

#define PM_MODE_NAME(_mi_mode)(         \
                                        p9_PM_FLOW_MODE_NAME[_mi_mode-1]    \
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
namespace p9pm
{

enum PM_FLOW_MODE
{
    PM_RESET        = 0x1,
    PM_INIT         = 0x2,
    PM_SETUP        = 0x3,
    PM_SETUP_PIB    = 0x4,
    PM_SETUP_ALL    = 0x5,
    PM_RESET_SOFT   = 0x6,
    PM_INIT_SOFT    = 0x7,
    PM_INIT_SPECIAL = 0x8,
};

} // end of namespace p9pm


#endif // _P9_PM_H_
