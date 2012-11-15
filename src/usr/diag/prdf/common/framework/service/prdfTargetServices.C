/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfTargetServices.C $ */
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

/**
 * @file prdfTargetServices.C
 * @brief PRD wrapper of targetting code
 */

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <prdfTargetServices.H>

#include <algorithm>

#include <iipbits.h>
#include <iipsdbug.h>
#include <iipglobl.h>
#include <prdfTrace.H>

#include <errlentry.H>
#include <fapi.H>
#include <targeting/common/targetservice.H>

using namespace TARGETING;

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##
//##                 Target Manipulation Utility Functions
//##
//##############################################################################

// FIXME: This function is using type PRDF::HUID. I think it should now be using
//        TARGETING::HUID_ATTR. Also, will need equivalent to
//        PRDF::INVALID_HUID. I think HWSV has HWSV_INVALID_HUID, but I don't
//        think that exists in Hostboot. Need a common interface before making
//        changes.
TARGETING::TargetHandle_t getTarget( HUID i_huid )
{
    TargetHandle_t o_target = NULL;

    // FIXME: This is an incredibly inefficient linear search. It is recommended
    //        that the common targeting code provide an interface for us so that
    //        all users can call the potentially optimized function. There is a
    //        function available in HWSV (hwsvTargetUtil.H) but not in Hostboot.
    //        Sadly, the HWSV code does this exact linear search.
    TargetService & l_targetService = targetService();
    for ( TargetIterator l_targetPtr = l_targetService.begin();
          l_targetPtr != l_targetService.end(); ++l_targetPtr )
    {
        if ( i_huid == (l_targetPtr->getAttr<ATTR_HUID>()) )
        {
            o_target = (*l_targetPtr);
            break;
        }
    }

    if ( NULL == o_target )
    {
        PRDF_ERR( "[getTarget] i_huid: 0x%08x failed", i_huid );
    }

    return o_target;
}

//------------------------------------------------------------------------------

TARGETING::TargetHandle_t getTarget( const TARGETING::EntityPath & i_path )
{
    TargetHandle_t o_target = targetService().toTarget( i_path );
    if ( NULL == o_target )
    {
        PRDF_ERR( "[getTarget] Failed: i_path=" ); i_path.dump();
    }

    return o_target;
}

//------------------------------------------------------------------------------

int32_t getEntityPath( TARGETING::TargetHandle_t i_target,
                       TARGETING::EntityPath & o_path,
                       TARGETING::EntityPath::PATH_TYPE i_pathType )
{
    int32_t o_rc = FAIL;

    do
    {
        if ( NULL == i_target ) break;

        if ( EntityPath::PATH_NA != i_pathType )
            o_path.setType( i_pathType );

        ATTRIBUTE_ID attr = ATTR_NA;
        switch ( o_path.type() )
        {
            case EntityPath::PATH_AFFINITY: attr = ATTR_AFFINITY_PATH; break;
            case EntityPath::PATH_PHYSICAL: attr = ATTR_PHYS_PATH;     break;
            case EntityPath::PATH_POWER:    attr = ATTR_POWER_PATH;    break;
            default: ;
        }
        if ( ATTR_NA == attr )
        {
            PRDF_ERR( "[getEntityPath] Unsupported EntityPath type %d",
                      o_path.type() );
            break;
        }

        if ( !targetService().tryGetPath(attr, i_target, o_path) )
        {
            PRDF_ERR( "[getEntityPath] Failed to get path %d", attr );
            break;
        }

        o_rc = SUCCESS;

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "[getEntityPath] Failed: i_target=0x%08x",
                  getHuid(i_target) );
    }

    return o_rc;
}

//------------------------------------------------------------------------------

HUID getHuid( TARGETING::TargetHandle_t i_target )
{
    HUID o_huid = INVALID_HUID;

    do
    {
        if ( NULL == i_target ) break; // return INVALID_HUID

        // TODO: get_huid() (src/include/usr/targeting/common/util.H) can be
        //       called to fetch HUID however this feature is not yet available
        //       in FSP yet.
        if ( !i_target->tryGetAttr<ATTR_HUID>(o_huid) )
        {
            PRDF_ERR( "[getHuid] Failed to get ATTR_HUID" );
            o_huid = INVALID_HUID; // Just in case.
        }

    } while (0);

    return o_huid;
}

//------------------------------------------------------------------------------

bool isFunctional( TARGETING::TargetHandle_t i_target )
{
    bool o_funcState = false;

    do
    {
        if ( NULL == i_target )
        {
            PRDF_ERR( "[isFunctional] i_target is NULL" );
            break;
        }

        HwasState l_funcState;
        if ( !i_target->tryGetAttr<ATTR_HWAS_STATE>(l_funcState) )
        {
            PRDF_ERR( "[isFunctional] Failed to get ATTR_HWAS_STATE" );
            break;
        }

        if ( l_funcState.functional ) o_funcState =true;
    } while (0);

    return o_funcState;
}

//------------------------------------------------------------------------------

TARGETING::TYPE getTargetType( TARGETING::TargetHandle_t i_target )
{
    TYPE o_type = TYPE_LAST_IN_RANGE;

    if ( NULL != i_target )
    {
        if ( !i_target->tryGetAttr<ATTR_TYPE>(o_type) )
        {
            PRDF_ERR( "[getTargetType] Failed to get ATTR_TYPE" );
            o_type = TYPE_LAST_IN_RANGE; // Just in case
        }
    }

    if ( TYPE_LAST_IN_RANGE == o_type )
    {
        PRDF_ERR( "[getTargetType] Failed: i_target=0x%08x",
                  getHuid(i_target) );
    }

    return o_type;
}

//------------------------------------------------------------------------------

TARGETING::CLASS getTargetClass( TARGETING::TargetHandle_t i_target )
{
    CLASS o_class = CLASS_NA;

    if ( NULL != i_target )
    {
        if ( !i_target->tryGetAttr<ATTR_CLASS>(o_class) )
        {
            PRDF_ERR( "[getTargetClass] Failed to get ATTR_CLASS" );
            o_class = CLASS_NA; // Just in case
        }
    }

    if ( CLASS_NA == o_class )
    {
        PRDF_ERR( "[getTargetClass] Failed: i_target=0x%08x",
                  getHuid(i_target) );
    }

    return o_class;
}

//------------------------------------------------------------------------------

void printTargetInfo( TARGETING::TargetHandle_t i_target )
{
    EntityPath l_path ( EntityPath::PATH_PHYSICAL );
    int32_t l_rc = getEntityPath( i_target, l_path );
    if ( SUCCESS == l_rc )
    {
        PRDF_DTRAC( "PRDCONFIG: HUID=0x%08x path=", getHuid(i_target) );
        l_path.dump();
    }
    else
    {
        PRDF_ERR( "[printTargetInfo] Failed: i_target=0x%08x",
                  getHuid(i_target) );
    }
}

//------------------------------------------------------------------------------

uint8_t getChipLevel( TARGETING::TargetHandle_t i_target )
{
    uint8_t o_chipLvl = 0;

    do
    {
        if ( NULL == i_target ) break;

        TargetHandle_t l_parentTarget = getParentChip( i_target );
        if ( NULL == l_parentTarget ) break;

        if ( !l_parentTarget->tryGetAttr<ATTR_EC>(o_chipLvl) )
        {
            PRDF_ERR( "[getChipLevel] Failed to get ATTR_EC" );
            o_chipLvl = 0xff; // Just in case
        }

    } while (0);

    if ( 0 == o_chipLvl )
    {
        PRDF_ERR( "[getChipLevel] Failed: i_target=0x%08x", getHuid(i_target) );
    }

    return o_chipLvl;
}

//------------------------------------------------------------------------------

/* TODO: getChipId() may be available in an attribute, but this design has not
 *       been solidified. Instead, we may need to query for 'reason' attributes
 *       to determine the reason we need to do the checks. Since we don't have
 *       any immediate need for these functions (no workarounds as of yet), we
 *       will leave them commented out in the code.
uint8_t getChipId( TARGETING::TargetHandle_t i_target )
{
    // Returns chip ID enum (i.e. P7, P7+, etc.)
    return 0;
}
*/

//##############################################################################
//##
//##                       getConnected() support functions
//##
//##############################################################################

// This is a helper function for getConnected(). It will return the association
// type (CHILD_BY_AFFINITY or PARENT_BY_AFFINITY) between a target and
// destination target type. The function only characterizes parent or child
// relationships. It does not do any peer-to-peer relationships. The function
// will return non-SUCCESS if a relationship is not supported.

struct conn_t
{
    TYPE from : 8;
    TYPE to : 8;
    TargetService::ASSOCIATION_TYPE type : 8;

    bool operator<( const conn_t & r )
    {
        if ( this->from == r.from )
            return ( this->to < r.to );
        else
            return ( this->from < r.from );
    }

} PACKED;

int32_t getAssociationType( TARGETING::TargetHandle_t i_target,
                            TARGETING::TYPE i_connType,
                            TARGETING::TargetService::ASSOCIATION_TYPE & o_type)
{
    int32_t o_rc = SUCCESS;

    static conn_t lookups[] =
    {
        // This table must be sorted based on the < operator of struct conn_t.
        // FIXME: Create a Cxx test case that will catch if the values of the
        //        TYPE enum changes.
        { TYPE_NODE, TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_MEMBUF, TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_PROC,   TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_EX,     TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_CORE,   TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_L2,     TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_L3,     TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_L4,     TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_MCS,    TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_MBS,    TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_MBA,    TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_XBUS,   TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_ABUS,   TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE, TYPE_PCI,    TargetService::CHILD_BY_AFFINITY },

        { TYPE_DIMM, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_DIMM, TYPE_MEMBUF, TargetService::PARENT_BY_AFFINITY },
        { TYPE_DIMM, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_DIMM, TYPE_MCS,    TargetService::PARENT_BY_AFFINITY },
        { TYPE_DIMM, TYPE_MBA,    TargetService::PARENT_BY_AFFINITY },

        { TYPE_MEMBUF, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MEMBUF, TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MEMBUF, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MEMBUF, TYPE_L4,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MEMBUF, TYPE_MCS,    TargetService::PARENT_BY_AFFINITY },
        { TYPE_MEMBUF, TYPE_MBS,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MEMBUF, TYPE_MBA,    TargetService::CHILD_BY_AFFINITY  },

        { TYPE_PROC, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_PROC, TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_MEMBUF, TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_EX,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_CORE,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_L2,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_L3,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_L4,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_MCS,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_MBS,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_MBA,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_XBUS,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_ABUS,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC, TYPE_PCI,    TargetService::CHILD_BY_AFFINITY  },

        { TYPE_EX, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_EX, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_EX, TYPE_CORE,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_EX, TYPE_L2,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_EX, TYPE_L3,     TargetService::CHILD_BY_AFFINITY  },

        { TYPE_CORE, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_CORE, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_CORE, TYPE_EX,     TargetService::PARENT_BY_AFFINITY },

        { TYPE_L2, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_L2, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_L2, TYPE_EX,     TargetService::PARENT_BY_AFFINITY },

        { TYPE_L3, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_L3, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_L3, TYPE_EX,     TargetService::PARENT_BY_AFFINITY },

        { TYPE_MBS, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBS, TYPE_MEMBUF, TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBS, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBS, TYPE_MCS,    TargetService::PARENT_BY_AFFINITY },

        { TYPE_MCS, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCS, TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MCS, TYPE_MEMBUF, TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MCS, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCS, TYPE_L4,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MCS, TYPE_MBS,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MCS, TYPE_MBA,    TargetService::CHILD_BY_AFFINITY  },

        { TYPE_MBS, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBS, TYPE_MEMBUF, TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBS, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBS, TYPE_MCS,    TargetService::PARENT_BY_AFFINITY },

        { TYPE_MBA, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBA, TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MBA, TYPE_MEMBUF, TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBA, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBA, TYPE_MCS,    TargetService::PARENT_BY_AFFINITY },

        { TYPE_XBUS, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_XBUS, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },

        { TYPE_ABUS, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_ABUS, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },

        { TYPE_PCI, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_PCI, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
    };

    const size_t sz_lookups = sizeof(lookups) / sizeof(conn_t);

    conn_t match = { getTargetType(i_target), i_connType,
                     TargetService::CHILD_BY_AFFINITY };

    conn_t * it = std::lower_bound( lookups, lookups + sz_lookups, match );

    if ( it != lookups + sz_lookups )
        o_type = it->type;
    else
    {
        PRDF_ERR( "[getAssociationType] Failed: i_target=0x%08x i_connType=%d",
                  getHuid(i_target), i_connType );
        o_rc = FAIL;
    }

    return o_rc;
}

//------------------------------------------------------------------------------

// Helper function to return a parent or container target of a specified type.
// For example, get EX target from CORE or PROC target from MEMBUF. Note, that
// the input target could be the parent. Will return NULL if the parent is not
// found. For example, a DIMM could not be a parent of a PROC.
TARGETING::TargetHandle_t getParent( TARGETING::TargetHandle_t i_target,
                                     TARGETING::TYPE i_connType )
{
    TARGETING::TargetHandle_t o_target = i_target; // Assume it is the parent.

    if ( i_connType != getTargetType(i_target) )
    {
        TargetHandleList list = getConnected( i_target, i_connType );
        o_target = ( 1 == list.size() ) ? list[0] : NULL;
    }

    if ( NULL == o_target )
    {
        PRDF_ERR( "[getParent] Failed: i_target=0x%08x i_connType=%d",
                  getHuid(i_target), i_connType );
    }

    return o_target;
}

//------------------------------------------------------------------------------

TARGETING::TargetHandleList getConnected( TARGETING::TargetHandle_t i_target,
                                          TARGETING::TYPE i_connType )
{
    TargetHandleList o_list; // Default empty list

    do
    {
        // Parameter checks. Error trace output is in NULL check below.
        if ( NULL == i_target ) break;

        TargetService::ASSOCIATION_TYPE l_assocType;
        int32_t l_rc = getAssociationType( i_target, i_connType, l_assocType );
        if ( SUCCESS != l_rc ) break;

        // Match any class, specified type, and functional.
        PredicateCTM predType( CLASS_NA, i_connType );
        PredicateIsFunctional predFunc;
        PredicatePostfixExpr predAnd;
        predAnd.push(&predType).push(&predFunc).And();

        targetService().getAssociated( o_list, i_target, l_assocType,
                                       TargetService::ALL, &predAnd );

    } while(0);

    if ( 0 == o_list.size() )
    {
        PRDF_ERR( "[getConnected] Failed: i_target=0x%08x i_connType=%d",
                  getHuid(i_target), i_connType );
    }

    return o_list;
}

//------------------------------------------------------------------------------

TARGETING::TargetHandle_t getConnectedPeerProc(
                                         TARGETING::TargetHandle_t i_procTarget,
                                         TARGETING::TYPE i_busType,
                                         uint32_t i_busPos )
{
    #define FUNC "[getConnectedPeerProc] "

    TargetHandle_t o_target = NULL;

    do
    {
        // Parameter checks. Error trace output is in NULL check below.
        if ( NULL == i_procTarget ) break;

        if ( TYPE_PROC != getTargetType(i_procTarget) )
        {
            PRDF_ERR( FUNC"Given target is not of TYPE_PROC" ); break;
        }

        if ( !( ((TYPE_XBUS == i_busType) && (MAX_XBUS_PER_PROC > i_busPos)) ||
                ((TYPE_ABUS == i_busType) && (MAX_ABUS_PER_PROC > i_busPos)) ) )
            break;

        // Starting PROC -> starting XBUS/ABUS.
        TargetHandleList list = getConnected( i_procTarget, i_busType );
        TargetHandle_t busTarget = NULL;
        for (TargetHandleList::iterator i = list.begin(); i != list.end(); ++i)
        {
            if ( i_busPos == getTargetPosition(*i) )
            {
                busTarget = *i;
                break; // for loop
            }
        }
        if ( NULL == busTarget )
        {
            PRDF_ERR( FUNC"Couldn't find connected bus" ); break;
        }

        // Starting XBUS/ABUS -> ATTR_PEER_TARGET -> destination XBUS/ABUS.
        TargetHandle_t destTarget = NULL;
// FIXME - ATTR_PEER_TARGET support has not been ported to FSP yet.
//        if ( !busTarget->tryGetAttr<ATTR_PEER_TARGET>(destTarget) )
        if ( true )
        {
            PRDF_ERR( FUNC"Couldn't find destination bus" ); break;
        }

        // Destination XBUS/ABUS <-> destination PROC.
        list = getConnected( destTarget, TYPE_PROC );
        if ( 1 != list.size() )
        {
            PRDF_ERR( FUNC"Couldn't find destination PROC" ); break;
        }
        o_target = list[0];

    } while(0);

    if ( NULL == o_target )
    {
        PRDF_ERR( FUNC"Failed: i_procTarget=0x%08x i_busType=%d i_busPos=%d",
                  getHuid(i_procTarget), i_busType, i_busPos );
    }

    #undef FUNC

    return o_target;
}

//------------------------------------------------------------------------------

TARGETING::TargetHandle_t getSystemTarget()
{
    TargetHandle_t sysTarget = NULL;
    targetService().getTopLevelTarget( sysTarget );

    if ( NULL == sysTarget )
    {
        PRDF_ERR( "[getSystemTarget] Failed" );
    }

    return sysTarget;
}

//------------------------------------------------------------------------------

TARGETING::TargetHandle_t getParentChip( TARGETING::TargetHandle_t i_target )
{
    TargetHandle_t o_chipTarget = NULL;

    CLASS l_class = getTargetClass( i_target );
    switch ( l_class )
    {
        case CLASS_CHIP:
            o_chipTarget = i_target;
            break;

        case CLASS_UNIT:
        {
            TargetHandleList l_list;
            PredicateCTM l_predClass( CLASS_CHIP );
            targetService().getAssociated( l_list, i_target,
                                           TargetService::PARENT,
                                           TargetService::IMMEDIATE,
                                           &l_predClass );
            if ( 1 == l_list.size() )
            {
                o_chipTarget = l_list[0];
            }
            else
            {
                PRDF_ERR( "[getParentChip] Could not find parent chip" );
            }
            break;
        }

        default:
            PRDF_ERR( "[getParentChip] Unsupported class: %d", l_class );
    }

    if ( NULL == o_chipTarget )
    {
        PRDF_ERR( "[getParentChip] Failed: i_target=0x%08x",
                  getHuid(i_target) );
    }

    return o_chipTarget;
}

//------------------------------------------------------------------------------

TARGETING::TargetHandleList getFunctionalTargetList( TARGETING::TYPE i_type )
{
    TargetHandleList o_list; // Default empty list.

    TargetService & l_targetService = targetService();

    // Match any class, specified type, and functional.
    PredicateCTM l_predType( CLASS_NA, i_type );
    PredicateIsFunctional l_predFunc;
    PredicatePostfixExpr l_predAnd;
    l_predAnd.push(&l_predType).push(&l_predFunc).And();

    // Defining a filter to get a list of all targets of i_type.
    TargetRangeFilter l_filter( l_targetService.begin(), l_targetService.end(),
                                &l_predAnd );
    for( ; l_filter; ++l_filter )
    {
        // Adding functional target to the vector.
        o_list.push_back( *l_filter );
    }

    if ( 0 == o_list.size() )
    {
        PRDF_ERR( "[getFunctionalTargetList] Failed: i_type=%d", i_type );
    }

    return o_list;
}

//------------------------------------------------------------------------------

// FIXME: In the past, this was a wrapper for a GARD interface. Need to make
//        sure that we have the equivelant functionality.
bool checkLastFuncCore( TARGETING::TargetHandle_t i_coreTarget )
{
    bool o_lastCore = false;

    // TODO: Possibly support TYPE_EX, TYPE_L2, and TYPE_L3 as target input.

    TargetHandleList l_list = getFunctionalTargetList( TYPE_CORE );
    if ( 1 == l_list.size() && l_list[0] == i_coreTarget )
        o_lastCore = true;

    return o_lastCore;
}

//##############################################################################
//##
//##                       Target position support code
//##
//##############################################################################

uint32_t getTargetPosition( TARGETING::TargetHandle_t i_target )
{
    #define FUNC "[getTargetPosition] "

    uint32_t o_pos = INVALID_POSITION_BOUND;

    CLASS l_class = getTargetClass( i_target );
    switch ( l_class )
    {
        case CLASS_CHIP:
        {
            TYPE l_type = getTargetType( i_target );
            switch ( l_type )
            {
                case TYPE_PROC:
                {
                    uint16_t tmpPos = 0;
                    if ( !i_target->tryGetAttr<ATTR_POSITION>(tmpPos) )
                        PRDF_ERR( FUNC"Failed to get ATTR_POSITION" );
                    else
                        o_pos = (uint32_t)tmpPos;
                    break;
                }

                case TYPE_MEMBUF:
                    o_pos = getMemChnl( i_target );
                    break;

                default:
                    PRDF_ERR( FUNC"Unsupported type: %d", l_type );
            }
            break;
        }

        case CLASS_UNIT:
        {
            uint8_t tmpPos = 0;
            if ( !i_target->tryGetAttr<ATTR_CHIP_UNIT>(tmpPos) )
                PRDF_ERR( FUNC"Failed to get ATTR_CHIP_UNIT" );
            else
                o_pos = (uint32_t)tmpPos;
            break;
        }

        case CLASS_ENC:
            o_pos = getNodePosition( i_target );
            break;

        default:
            PRDF_ERR( FUNC"Unsupported class: %d", l_class );
    }

    if ( INVALID_POSITION_BOUND == o_pos )
    {
        PRDF_ERR( FUNC"Failed: target=0x%08x", getHuid(i_target) );
    }

    #undef FUNC

    return o_pos;
}

//------------------------------------------------------------------------------

uint32_t getNodePosition( TARGETING::TargetHandle_t i_target )
{
    uint32_t o_pos = INVALID_POSITION_BOUND;

    do
    {
        // Get the node handle.
        TargetHandle_t l_node = NULL;
        TargetHandleList l_list = getConnected( i_target, TYPE_NODE );
        if ( 1 == l_list.size() )
            l_node = l_list[0];
        else
        {
            PRDF_ERR( "[getNodePosition] Failed to get node target" );
            break;
        }

        // FIXME: While this code works, it is preferred to use the POSITION
        //        attribute of the node. Currently, this attribute does not
        //        exist but it will, eventually. (RTC WI expected from Nick
        //        Bofferding)
        EntityPath l_path ( EntityPath::PATH_PHYSICAL );
        int32_t l_rc = getEntityPath( l_node, l_path );
        if ( SUCCESS != l_rc ) break;

        o_pos = l_path[l_path.size()-1].instance;

    } while (0);

    if ( INVALID_POSITION_BOUND == o_pos )
    {
        PRDF_ERR( "[getNodePosition] Failed: target=0x%08x",
                  getHuid(i_target) );
    }

    return o_pos;
}

//##############################################################################
//##
//##                       DUMP and Runtime Deconfig support code
//##
//##############################################################################

//------------------------------------------------------------------------------

errlHndl_t dumpHWURequest(errlHndl_t i_errl, HUID i_huid )
{
    // FIXME : need to implement this once P8 DUMP support is in
    PRDF_ERR( "[dumpHWURequest] i_huid=0x%08x - Function not implemented yet", i_huid );

    return NULL;
}

//------------------------------------------------------------------------------

errlHndl_t runtimeDeconfig( HUID i_huid )
{
    // FIXME : need to implement this once Story 42422
    //        in CEC HW Enablement is done
    PRDF_ERR( "[runtimeDeconfig] i_huid=0x%08x - Function not implemented yet", i_huid );

    return NULL;
}

//##############################################################################
//##
//##                        Memory specific functions
//##
//##############################################################################

int32_t getMasterRanks( TARGETING::TargetHandle_t i_memTarget,
                        uint32_t i_portSlct, uint32_t i_dimmSlct,
                        std::vector<uint32_t> & o_ranks )
{
    int32_t o_rc = FAIL;

    do
    {
        if ( NULL == i_memTarget ) break;

        if ( (MAX_PORT_PER_MBA  <= i_portSlct) ||
             (MAX_DIMM_PER_PORT <= i_dimmSlct) )
            break;

        TARGETING::TargetHandle_t mbaTarget = getParent(i_memTarget, TYPE_MBA);
        if ( NULL == mbaTarget ) break;

        uint8_t rankInfo[MAX_PORT_PER_MBA][MAX_DIMM_PER_PORT];
        if( !mbaTarget->tryGetAttr<ATTR_EFF_DIMM_RANKS_CONFIGED>(rankInfo) )
        {
            PRDF_ERR( "[getMasterRanks] Failed to get attribute" );
            break;
        }

        uint8_t rankMask = rankInfo[i_portSlct][i_dimmSlct];
        if ( 0 == (rankMask & 0xf0) )
        {
            PRDF_ERR( "[getMasterRanks] Attribute value invalid: 0x%02x",
                      rankMask );
            break;
        }

        for ( uint32_t rank = 0; rank < 4; rank++ )
        {
            if ( 0 != (rankMask & (0x80 >> rank)) )
            {
                o_ranks.push_back(rank);
            }
        }

        o_rc = SUCCESS;

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "[getMasterRanks] Failed: i_memTarget=0x%08x i_portSlct=%d "
                  "i_dimmSlct=%d",
                  getHuid(i_memTarget), i_portSlct, i_dimmSlct );
    }

    return o_rc;
}

//------------------------------------------------------------------------------

uint32_t getMemChnl( TARGETING::TargetHandle_t i_memTarget )
{
    uint32_t o_chnl = INVALID_POSITION_BOUND; // Intentially set to
                                              // INVALID_POSITION_BOUND for call
                                              // from getTargetPosition().

    do
    {
        if ( NULL == i_memTarget ) break;

        TARGETING::TargetHandle_t mcsTarget = getParent(i_memTarget, TYPE_MCS);
        if ( NULL == mcsTarget ) break;

        o_chnl = getTargetPosition( mcsTarget );

    } while (0);

    if ( MAX_MCS_PER_PROC <= o_chnl ) // Real MCS position check.
    {
        PRDF_ERR( "[getMemChnl] Failed: i_memTarget=0x%08x",
                  getHuid(i_memTarget) );
    }

    return o_chnl;
}

//------------------------------------------------------------------------------

int32_t isMembufOnDimm( TARGETING::TargetHandle_t i_memTarget,
                        bool & o_isBuffered )
{
    int32_t o_rc = FAIL;

    o_isBuffered = false;

    do
    {
        // The DIMMs in an node should either all be buffered or all not. So we
        // can check the attribute from ANY MBA.
        TargetHandleList list = getConnected( i_memTarget, TYPE_MBA );
        if ( 0 == list.size() )
        {
            PRDF_ERR( "[isMembufOnDimm] Couldn't find an MBA target" );
            break;
        }

        // FIXME - Currently TARGETING::ATTR_EFF_DIMM_TYPE is mapped to
        //         fapi::ATTR_EFF_DIMM_TYPE, but there is no guarantee it will
        //         stay mapped. The values of this attribute is mapped in a fapi
        //         enum, but we are encouraged to use the TARGETING attribute.
        //         Either we need to use fapi::ATTR_EFF_DIMM_TYPE (no preferred)
        //         or get a TARGETING enum (preferred).
        // FIXME - dimmtype should be of an enum type.
        uint8_t dimmtype;
        if ( !list[0]->tryGetAttr<ATTR_EFF_DIMM_TYPE>(dimmtype) )
        {
            PRDF_ERR( "[isMembufOnDimm] Failed to get DIMM type" );
            break;
        }

        // FIXME - See note above.
        if ( fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM == dimmtype )
            o_isBuffered = true;

        o_rc = SUCCESS;

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "[isMembufOnDimm] Failed: i_memTarget=0x%08x",
                  getHuid(i_memTarget) );
    }

    return o_rc;
}

int32_t getMbaPort( TARGETING::TargetHandle_t i_dimmTarget, uint8_t & o_port )
{
    using namespace TARGETING;
    return i_dimmTarget->tryGetAttr<ATTR_MBA_PORT>(o_port) ? SUCCESS : FAIL;
}

int32_t getMbaDimm( TARGETING::TargetHandle_t i_dimmTarget, uint8_t & o_dimm )
{
    using namespace TARGETING;
    return i_dimmTarget->tryGetAttr<ATTR_MBA_DIMM>(o_dimm) ? SUCCESS : FAIL;
}

//##############################################################################
//##
//##                        Clock specific functions
//##
//##############################################################################

// FIXME: RTC: 51628 will address clock target issue
bool areClocksOn(TARGETING::TargetHandle_t i_pGivenTarget)
{
    bool o_clocksOn = false;

    #ifdef __HOSTBOOT_MODULE

    o_clocksOn = true;

    #else

    if ( NULL != i_pGivenTarget )
    {
        errlHndl_t errl = NULL;
        //errl =HWSV::hwsvClockQueryOn(i_pGivenTarget,
        //                  HWSV::NO_MODE, o_clocksOn);
        if ( NULL != errl )
        {
            PRDF_ERR( "[areClocksOn] In areClocksOn failed" );
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
        }
    }
    else
    {
        PRDF_ERR( "[areClocksOn] given target is null" );
    }

    #endif

    return o_clocksOn;
}

//------------------------------------------------------------------------------

// FIXME: RTC: 51628 will address clock target issue
TARGETING::TargetHandle_t getClockId(TARGETING::TargetHandle_t
                            i_pGivenTarget,
                            TARGETING ::TYPE targetype)
{
    TargetHandleList l_clockCardlist;
    TargetHandle_t o_pClockCardHandle = NULL;

    return o_pClockCardHandle;
}

//------------------------------------------------------------------------------

// FIXME: RTC: 51628 will address clock target issue
TARGETING::TargetHandle_t getClockMux(TARGETING::TargetHandle_t
                            i_pGivenTarget)
{
    //Modeling info of card and Clock mux is required
    // PredicateCTM l_ClockMux(CLASS_UNIT,TYPE_CLOCK_MUX);
    //defined for compilation
    PredicateCTM l_ClockMux(CLASS_UNIT);
    TargetHandle_t o_ptargetClockMux = NULL;
    #if 0
    do
    {
        if(NULL != i_pGivenTarget)
        {
            TargetHandleList l_list;
            if(TYPE_PROC==(i_pGivenTarget->getAttr<ATTR_TYPE>()))
            {
                    targetService().getAssociated(l_list,
                                        i_pGivenTarget,
                                        TargetService::CHILD_BY_AFFINITY,
                                        TargetService::ALL,
                                        &l_ClockMux);
            }
            else
            {
                //TODO: If given target is not a proc  how to query all mux units
                //      which relation  to be used
            }

            if (l_list.size() > 0)
            {
                // Pick out first item
                o_ptargetClockMux = l_list[0];
            }
        }
        else
        {
            PRDF_ERR("[getClockMux] given target is NULL");
        }
    }while(0);
    #endif
    return o_ptargetClockMux;
}

} // end namespace PlatServices

} // end namespace PRDF

