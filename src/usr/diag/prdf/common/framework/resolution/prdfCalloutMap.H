/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCalloutMap.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __prdfCalloutMap_H
#define __prdfCalloutMap_H

/** @file prdfCalloutMap.H */

#include <prdfEnums.H>

//------------------------------------------------------------------------------

namespace PRDF
{

//------------------------------------------------------------------------------

#ifdef PRDF_RULE_COMPILER_ENUMS

    // Used only in the rule compiler. Sets up a map between string keywords in
    // the rule code to the enum name.

    #define PRDF_SYM_CALLOUT_MAP_BEGIN \
        struct SymCallout_t { const char * str; SymbolicFru val; }; \
        SymCallout_t symCalloutArray[] = \
        {

    #define PRDF_SYM_CALLOUT_ALIAS(name1, name2) \
            { #name1 , name1 },

    #define PRDF_SYM_CALLOUT_MAP_END \
            { NULL , (SymbolicFru) 0 } \
        };

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

PRDF_SYM_CALLOUT_ALIAS( AllProcessors,                EPUB_PRC_ALL_PROCS      )
PRDF_SYM_CALLOUT_ALIAS( PRD_Code_ENUM,                EPUB_PRC_SP_CODE        )
PRDF_SYM_CALLOUT_ALIAS( SP_CODE,                      EPUB_PRC_SP_CODE        )
PRDF_SYM_CALLOUT_ALIAS( SystemSW_Code_ENUM,           EPUB_PRC_PHYP_CODE      )
PRDF_SYM_CALLOUT_ALIAS( NextLevelSupport_ENUM,        EPUB_PRC_LVL_SUPP       )
PRDF_SYM_CALLOUT_ALIAS( MEMBUS_ERROR_ENUM,            EPUB_PRC_MEMBUS_ERROR   )
PRDF_SYM_CALLOUT_ALIAS( PassiveFabric_OnNode_ENUM,    EPUB_PRC_PROC_XYZ_BUS   )
PRDF_SYM_CALLOUT_ALIAS( PassiveFabric_OffNode_ENUM,   EPUB_PRC_PROC_AB_BUS    )

PRDF_SYM_CALLOUT_MAP_END

#undef PRDF_SYM_CALLOUT_MAP_BEGIN
#undef PRDF_SYM_CALLOUT_ALIAS
#undef PRDF_SYM_CALLOUT_MAP_END

//------------------------------------------------------------------------------

#ifdef PRDF_RULE_COMPILER_ENUMS

    // Used only in the rule compiler. Sets up a map between string keywords in
    // the rule code to the enum name.

    #define PRDF_CALLOUT_PRIORITY_MAP_BEGIN \
        struct CalloutPriority_t \
        { const char * str; CalloutPriorityEnum val; }; \
        CalloutPriority_t calloutPriorityArray[] = \
        {

    #define PRDF_CALLOUT_PRIORITY_ALIAS(name1, name2) \
            { #name1 , name1 },

    #define PRDF_CALLOUT_PRIORITY_MAP_END \
            { NULL , (CalloutPriorityEnum) 0 } \
        };

#else

    #define PRDF_CALLOUT_PRIORITY_MAP_BEGIN \
        enum CalloutPriorityEnum \
        {

    #define PRDF_CALLOUT_PRIORITY_ALIAS(n1,n2) \
            n1 = n2,

    #define PRDF_CALLOUT_PRIORITY_MAP_END \
        };

#endif

PRDF_CALLOUT_PRIORITY_MAP_BEGIN

PRDF_CALLOUT_PRIORITY_ALIAS( MRU_HIGH, SRCI_PRIORITY_HIGH )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_MED,  SRCI_PRIORITY_MED  )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_MEDA, SRCI_PRIORITY_MEDA )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_MEDB, SRCI_PRIORITY_MEDB )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_MEDC, SRCI_PRIORITY_MEDC )
PRDF_CALLOUT_PRIORITY_ALIAS( MRU_LOW,  SRCI_PRIORITY_LOW  )

PRDF_CALLOUT_PRIORITY_MAP_END

#undef PRDF_CALLOUT_PRIORITY_MAP_BEGIN
#undef PRDF_CALLOUT_PRIORITY_ALIAS
#undef PRDF_CALLOUT_PRIORITY_MAP_END

//------------------------------------------------------------------------------

} // end namespace PRDF

#endif // __prdfCalloutMap_H

