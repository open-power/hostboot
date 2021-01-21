/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCalloutMap.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

#ifndef __prdfCalloutMap_H
#define __prdfCalloutMap_H

/** @file prdfCalloutMap.H */

#include <prdfEnums.H>

//------------------------------------------------------------------------------

#if !defined(PRDF_RULE_COMPILER_ENUMS) && !defined(PRDF_SIM_ENUMS)
namespace PRDF
{
#endif

//------------------------------------------------------------------------------

#ifdef PRDF_RULE_COMPILER_ENUMS

    // Used only in the rule compiler. Sets up a map between string keywords in
    // the rule code to the enum name.

    #define PRDF_SYM_CALLOUT_MAP_BEGIN

    #define PRDF_SYM_CALLOUT_ALIAS(name1, name2) \
        g_ActionArgMap[ #name1 ] = name2;

    #define PRDF_SYM_CALLOUT_MAP_END


#elif defined PRDF_SIM_ENUMS

    #define PRDF_SYM_CALLOUT_MAP_BEGIN \
        { \
        ENUMNAMES * l_calloutEnum = new ENUMNAMES(); \
        ivEnumTypes["calloutNames"] = l_calloutEnum; \
        std::string s;

    #define PRDF_SYM_CALLOUT_ALIAS(n1,n2) \
        s = #n1; ToUpper(s); ivEnumValue[s] = n2; (*l_calloutEnum)[n2] = s;

    #define PRDF_SYM_CALLOUT_MAP_END \
        }

#else

    #define PRDF_SYM_CALLOUT_MAP_BEGIN \
        enum SymbolicFru \
        {

    #define PRDF_SYM_CALLOUT_ALIAS(n1,n2) \
            n1 = n2,

    #define PRDF_SYM_CALLOUT_MAP_END \
        };

#endif

PRDF_SYM_CALLOUT_MAP_BEGIN

PRDF_SYM_CALLOUT_ALIAS( SUE_PREV_ERR,       HWAS::EPUB_PRC_SUE_PREVERROR     )
PRDF_SYM_CALLOUT_ALIAS( SP_CODE,            HWAS::EPUB_PRC_SP_CODE           )
PRDF_SYM_CALLOUT_ALIAS( SYS_SW_CODE,        HWAS::EPUB_PRC_PHYP_CODE         )
PRDF_SYM_CALLOUT_ALIAS( LEVEL2_SUPPORT,     HWAS::EPUB_PRC_LVL_SUPP          )
PRDF_SYM_CALLOUT_ALIAS( FAB_BUS_OFF_NODE,   HWAS::EPUB_PRC_PROC_AB_BUS       )
PRDF_SYM_CALLOUT_ALIAS( ERR_ROOT_IS_MEM_UE, HWAS::EPUB_PRC_MEMORY_UE         )
PRDF_SYM_CALLOUT_ALIAS( TOD_CLOCK_ERR,      HWAS::EPUB_PRC_TOD_CLOCK_ERR     )
PRDF_SYM_CALLOUT_ALIAS( COOLING_SYSTEM_ERR, HWAS::EPUB_PRC_COOLING_SYSTEM_ERR)

PRDF_SYM_CALLOUT_MAP_END

#undef PRDF_SYM_CALLOUT_MAP_BEGIN
#undef PRDF_SYM_CALLOUT_ALIAS
#undef PRDF_SYM_CALLOUT_MAP_END

//------------------------------------------------------------------------------

#ifdef PRDF_RULE_COMPILER_ENUMS

    // Used only in the rule compiler. Sets up a map between string keywords in
    // the rule code to the enum name.

    #define PRDF_CALLOUT_PRIORITY_MAP_BEGIN

    #define PRDF_CALLOUT_PRIORITY_ALIAS(name1, name2) \
        g_ActionArgMap[ #name1 ] = name2;

    #define PRDF_CALLOUT_PRIORITY_MAP_END

#elif defined PRDF_SIM_ENUMS

    #define PRDF_CALLOUT_PRIORITY_MAP_BEGIN \
        { \
        ENUMNAMES * l_priorityEnum = new ENUMNAMES(); \
        ivEnumTypes["priorityNames"] = l_priorityEnum; \
        std::string s;

    #define PRDF_CALLOUT_PRIORITY_ALIAS(n1,n2) \
        s = #n1; ToUpper(s); ivEnumValue[s] = n2; (*l_priorityEnum)[n2] = s;

    #define PRDF_CALLOUT_PRIORITY_MAP_END \
        }

#else

    #define PRDF_CALLOUT_PRIORITY_MAP_BEGIN \
        enum PRDpriority \
        {

    #define PRDF_CALLOUT_PRIORITY_ALIAS(n1,n2) \
            n1 = n2,

    #define PRDF_CALLOUT_PRIORITY_MAP_END \
        };

#endif

PRDF_CALLOUT_PRIORITY_MAP_BEGIN

PRDF_CALLOUT_PRIORITY_ALIAS( MRU_HIGH, HWAS::SRCI_PRIORITY_HIGH )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_MED,  HWAS::SRCI_PRIORITY_MED  )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_MEDA, HWAS::SRCI_PRIORITY_MEDA )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_MEDB, HWAS::SRCI_PRIORITY_MEDB )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_MEDC, HWAS::SRCI_PRIORITY_MEDC )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_LOW,  HWAS::SRCI_PRIORITY_LOW  )

PRDF_CALLOUT_PRIORITY_MAP_END

#undef PRDF_CALLOUT_PRIORITY_MAP_BEGIN
#undef PRDF_CALLOUT_PRIORITY_ALIAS
#undef PRDF_CALLOUT_PRIORITY_MAP_END

//------------------------------------------------------------------------------

#ifdef PRDF_RULE_COMPILER_ENUMS

    #define PRDF_TARGET_TYPE_ALIAS(n1, n2) \
        g_ActionArgMap[ #n1 ] = n2;

#elif defined PRDF_SIM_ENUMS

    #define PRDF_TARGET_TYPE_ALIAS(n1, n2) \
        ivEnumValue[ #n1 ] = n2;

#else

    #define PRDF_TARGET_TYPE_ALIAS(n1, n2)

#endif

PRDF_TARGET_TYPE_ALIAS( TYPE_SYS,       TARGETING::TYPE_SYS       )
PRDF_TARGET_TYPE_ALIAS( TYPE_NODE,      TARGETING::TYPE_NODE      )
PRDF_TARGET_TYPE_ALIAS( TYPE_PROC,      TARGETING::TYPE_PROC      )
PRDF_TARGET_TYPE_ALIAS( TYPE_EQ,        TARGETING::TYPE_EQ        )
PRDF_TARGET_TYPE_ALIAS( TYPE_FC,        TARGETING::TYPE_FC        )
PRDF_TARGET_TYPE_ALIAS( TYPE_CORE,      TARGETING::TYPE_CORE      )
PRDF_TARGET_TYPE_ALIAS( TYPE_NMMU,      TARGETING::TYPE_NMMU      )
PRDF_TARGET_TYPE_ALIAS( TYPE_PEC,       TARGETING::TYPE_PEC       )
PRDF_TARGET_TYPE_ALIAS( TYPE_PHB,       TARGETING::TYPE_PHB       )
PRDF_TARGET_TYPE_ALIAS( TYPE_PAUC,      TARGETING::TYPE_PAUC      )
PRDF_TARGET_TYPE_ALIAS( TYPE_PAU,       TARGETING::TYPE_PAU       )
PRDF_TARGET_TYPE_ALIAS( TYPE_IOHS,      TARGETING::TYPE_IOHS      )
PRDF_TARGET_TYPE_ALIAS( TYPE_SMPGROUP,  TARGETING::TYPE_SMPGROUP  )
PRDF_TARGET_TYPE_ALIAS( TYPE_MC,        TARGETING::TYPE_MC        )
PRDF_TARGET_TYPE_ALIAS( TYPE_MI,        TARGETING::TYPE_MI        )
PRDF_TARGET_TYPE_ALIAS( TYPE_MCC,       TARGETING::TYPE_MCC       )
PRDF_TARGET_TYPE_ALIAS( TYPE_OMIC,      TARGETING::TYPE_OMIC      )
PRDF_TARGET_TYPE_ALIAS( TYPE_OMI,       TARGETING::TYPE_OMI       )
PRDF_TARGET_TYPE_ALIAS( TYPE_OCMB_CHIP, TARGETING::TYPE_OCMB_CHIP )
PRDF_TARGET_TYPE_ALIAS( TYPE_MEM_PORT,  TARGETING::TYPE_MEM_PORT  )
PRDF_TARGET_TYPE_ALIAS( TYPE_DIMM,      TARGETING::TYPE_DIMM      )
PRDF_TARGET_TYPE_ALIAS( TYPE_NX,        TARGETING::TYPE_NX        )
//PRDF_TARGET_TYPE_ALIAS( TYPE_OCC,       TARGETING::TYPE_OCC       )
PRDF_TARGET_TYPE_ALIAS( TYPE_OSCREFCLK, TARGETING::TYPE_OSCREFCLK )
PRDF_TARGET_TYPE_ALIAS( TYPE_NA,        TARGETING::TYPE_NA        )

#undef PRDF_TARGET_TYPE_ALIAS

//------------------------------------------------------------------------------

#if !defined(PRDF_RULE_COMPILER_ENUMS) && !defined(PRDF_SIM_ENUMS)
} // end namespace PRDF
#endif

#endif // __prdfCalloutMap_H

