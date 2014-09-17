/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfTargetServices.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
 * @file prdfTargetServices.C
 * @brief PRD wrapper of targetting code
 */

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <prdfTargetServices.H>

#include <prdfGlobal.H>
#include <prdfErrlUtil.H>
#include <prdfTrace.H>
#include <algorithm>
#include <fapi.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>

// Pegasus includes
#include <prdfCenAddress.H>

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
        PRDF_ERR( "[getTarget] Failed: i_path = " ); i_path.dump();
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
            o_chipLvl = 0; // Just in case
        }

    } while (0);

    if ( 0 == o_chipLvl )
    {
        PRDF_ERR( "[getChipLevel] Failed: i_target=0x%08x", getHuid(i_target) );
    }

    return o_chipLvl;
}

//------------------------------------------------------------------------------

void setHWStateChanged(TARGETING::TargetHandle_t i_target)
{
    #define PRDF_FUNC "[PlatServices::setHWStateChanged] "
    if(NULL != i_target)
    {
        TYPE type = getTargetType(i_target);
        if( (TYPE_DIMM   == type) ||
            (TYPE_MEMBUF == type) ||
            (TYPE_MCS    == type) )
        {
            update_hwas_changed_mask(i_target, HWAS_CHANGED_BIT_MEMDIAG);
        }
        else
        {
            PRDF_ERR(PRDF_FUNC"invalid target type: 0x%08x", type);
        }
    }
    else
    {
        PRDF_ERR(PRDF_FUNC"i_target is null");
    }

    #undef PRDF_FUNC
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

    static uint32_t getSortOrder( TYPE type )
    {
        // Can't trust that the order of the TYPE enum does not change so create
        // our own sorting order.

        uint32_t order = 0;

        switch ( type )
        {
            case TYPE_SYS:    order =  0; break;
            case TYPE_NODE:   order =  1; break;
            case TYPE_OSC:    order =  2; break;
            case TYPE_PROC:   order =  3; break;
            case TYPE_PORE:   order =  4; break;
            case TYPE_NX:     order =  5; break;
            case TYPE_OCC:    order =  6; break;
            case TYPE_PSI:    order =  7; break;
            case TYPE_EX:     order =  8; break;
            case TYPE_XBUS:   order =  9; break;
            case TYPE_ABUS:   order = 10; break;
            case TYPE_PCI:    order = 11; break;
            case TYPE_MCS:    order = 12; break;
            case TYPE_MEMBUF: order = 13; break;
            case TYPE_L4:     order = 14; break;
            case TYPE_MBA:    order = 15; break;
            case TYPE_DIMM:   order = 16; break;
            default: ;
        }

        return order;
    }

    bool operator<( const conn_t & r )
    {
        uint32_t thisOrder = getSortOrder(this->from);
        uint32_t thatOrder = getSortOrder(r.from);

        if ( thisOrder == thatOrder )
            return ( getSortOrder(this->to) < getSortOrder(r.to) );
        else
            return ( thisOrder < thatOrder );
    }

};

int32_t getAssociationType( TARGETING::TargetHandle_t i_target,
                            TARGETING::TYPE i_connType,
                            TARGETING::TargetService::ASSOCIATION_TYPE & o_type)
{
    #define PRDF_FUNC "[PlatServices::getAssociationType] "

    int32_t o_rc = SUCCESS;

    static conn_t lookups[] =
    {
        // This table must be sorted based on the < operator of struct conn_t.
        { TYPE_SYS,    TYPE_NODE,   TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_SYS,    TargetService::PARENT_BY_AFFINITY },
        { TYPE_NODE,   TYPE_OSC,    TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_PROC,   TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_OCC,    TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_PSI,    TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_EX,     TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_XBUS,   TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_ABUS,   TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_PCI,    TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_MCS,    TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_MEMBUF, TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_L4,     TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_MBA,    TargetService::CHILD_BY_AFFINITY },
        { TYPE_NODE,   TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY },

        { TYPE_OSC,    TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },

        { TYPE_PROC,   TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_PROC,   TYPE_PORE,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_NX,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_OCC,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_PSI,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_EX,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_XBUS,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_ABUS,   TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_PCI,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_MCS,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_MEMBUF, TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_L4,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_MBA,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY  },

        { TYPE_PORE,   TYPE_PROC,   TargetService::PARENT_BY_AFFINITY  },

        { TYPE_NX,     TYPE_PROC,   TargetService::PARENT_BY_AFFINITY  },

        { TYPE_OCC,    TYPE_NODE,   TargetService::PARENT_BY_AFFINITY  },
        { TYPE_OCC,    TYPE_PROC,   TargetService::PARENT_BY_AFFINITY  },

        { TYPE_PSI,    TYPE_NODE,   TargetService::PARENT_BY_AFFINITY  },
        { TYPE_PSI,    TYPE_PROC,   TargetService::PARENT_BY_AFFINITY  },

        { TYPE_EX,     TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_EX,     TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },

        { TYPE_XBUS,   TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_XBUS,   TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },

        { TYPE_ABUS,   TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_ABUS,   TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },

        { TYPE_PCI,    TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_PCI,    TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },

        { TYPE_MCS,    TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCS,    TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCS,    TYPE_MEMBUF, TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MCS,    TYPE_L4,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MCS,    TYPE_MBA,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MCS,    TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY  },

        { TYPE_MEMBUF, TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MEMBUF, TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MEMBUF, TYPE_MCS,    TargetService::PARENT_BY_AFFINITY },
        { TYPE_MEMBUF, TYPE_L4,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MEMBUF, TYPE_MBA,    TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MEMBUF, TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY  },

        { TYPE_L4,     TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_L4,     TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_L4,     TYPE_MCS,    TargetService::PARENT_BY_AFFINITY },
        { TYPE_L4,     TYPE_MEMBUF, TargetService::PARENT_BY_AFFINITY },

        { TYPE_MBA,    TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBA,    TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBA,    TYPE_MCS,    TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBA,    TYPE_MEMBUF, TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBA,    TYPE_DIMM,   TargetService::CHILD_BY_AFFINITY  },

        { TYPE_DIMM,   TYPE_NODE,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_DIMM,   TYPE_PROC,   TargetService::PARENT_BY_AFFINITY },
        { TYPE_DIMM,   TYPE_MCS,    TargetService::PARENT_BY_AFFINITY },
        { TYPE_DIMM,   TYPE_MEMBUF, TargetService::PARENT_BY_AFFINITY },
        { TYPE_DIMM,   TYPE_MBA,    TargetService::PARENT_BY_AFFINITY },
    };

    do
    {
        if ( NULL == i_target )
        {
            PRDF_ERR( PRDF_FUNC"Given target is null" );
            o_rc = FAIL; break;
        }

        const size_t sz_lookups = sizeof(lookups) / sizeof(conn_t);

        TYPE type = getTargetType(i_target);

        conn_t match = { type, i_connType, TargetService::CHILD_BY_AFFINITY };

        conn_t * it = std::lower_bound( lookups, lookups + sz_lookups, match );

        if ( (it == lookups + sz_lookups) || // off the end
             (type != it->from) || (i_connType != it->to) ) // not equals
        {
            PRDF_ERR( PRDF_FUNC"Look-up failed: i_target=0x%08x i_connType=%d",
                      getHuid(i_target), i_connType );
            o_rc = FAIL; break;
        }

        o_type = it->type;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

// Helper function for the various getConnected() functions.
TargetHandleList getConnAssoc( TargetHandle_t i_target, TYPE i_connType,
                               TargetService::ASSOCIATION_TYPE i_assocType )
{
    #define PRDF_FUNC "[PlatServices::getConnAssoc] "

    TargetHandleList o_list; // Default empty list

    do
    {
        if ( NULL == i_target )
        {
            PRDF_ERR( PRDF_FUNC"Given target is null" );
            break;
        }

        // Match any class, specified type, and functional.
        PredicateCTM predType( CLASS_NA, i_connType );
        PredicateIsFunctional predFunc;
        PredicatePostfixExpr predAnd;
        predAnd.push(&predType).push(&predFunc).And();

        targetService().getAssociated( o_list, i_target, i_assocType,
                                       TargetService::ALL, &predAnd );

    } while(0);

    return o_list;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TargetHandleList getConnected( TargetHandle_t i_target, TYPE i_connType )
{
    TargetHandleList o_list; // Default empty list

    do
    {
        if ( i_connType == getTargetType(i_target) )
        {
            o_list.push_back( i_target );
            break;
        }

        TargetService::ASSOCIATION_TYPE assocType;
        int32_t l_rc = getAssociationType( i_target, i_connType, assocType );
        if ( SUCCESS != l_rc ) break;

        o_list = getConnAssoc( i_target, i_connType, assocType );

    } while(0);

    return o_list;
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedParent( TargetHandle_t i_target, TYPE i_connType )
{
    #define PRDF_FUNC "[PlatServices::getConnectedParent] "

    TargetHandle_t o_parent = NULL;

    do
    {
        if ( i_connType == getTargetType(i_target) )
        {
            o_parent = i_target;
            break;
        }

        TargetService::ASSOCIATION_TYPE assocType;
        int32_t l_rc = getAssociationType( i_target, i_connType, assocType );
        if ( SUCCESS != l_rc ) break;

        if ( TargetService::PARENT_BY_AFFINITY != assocType )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported parent connection: i_target=0x%08x "
                      "i_connType=%d", getHuid(i_target), i_connType );
            break;
        }

        TargetHandleList list = getConnAssoc( i_target, i_connType, assocType );
        if ( 1 != list.size() ) // Should be one and only one parent
        {
            PRDF_ERR( PRDF_FUNC"Could not find parent: i_target=0x%08x "
                      "i_connType=%d", getHuid(i_target), i_connType );
            break;
        }

        o_parent = list[0];

    } while(0);

    return o_parent;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedChild( TargetHandle_t i_target, TYPE i_connType,
                                  uint32_t i_position )
{
    #define PRDF_FUNC "[PlatServices::getConnectedChild] "

    TargetHandle_t o_child = NULL;

    do
    {
        TargetService::ASSOCIATION_TYPE assocType;
        int32_t l_rc = getAssociationType( i_target, i_connType, assocType );
        if ( SUCCESS != l_rc ) break;

        if ( TargetService::CHILD_BY_AFFINITY != assocType )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported child connection: i_target=0x%08x "
                    "i_connType=%d", getHuid(i_target), i_connType );
            break;
        }

        // SPECIAL CASE: The MEMBUF position number is relative to the PROC,
        //      not the MCS. This means the MEMBUF position number is the same
        //      as the position number of the attached MCS. In many cases, we
        //      want to get the MEMBUF connected to the MCS, but don't have
        //      knowledge of the MCS's position number (espeically in the rule
        //      code. So the following will change the desired position number
        //      to the MCS position number for MCS->MEMBUF connections only.
        if ( TYPE_MCS == getTargetType(i_target) && TYPE_MEMBUF == i_connType )
            i_position = getTargetPosition(i_target);

        TargetHandleList list = getConnAssoc( i_target, i_connType, assocType );
        for ( TargetHandleList::iterator i = list.begin();
              i != list.end(); ++i )
        {
            if ( i_position == getTargetPosition(*i) )
            {
                o_child = *i;
                break;
            }
        }

    } while(0);

    return o_child;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedPeerTarget( TargetHandle_t i_target )
{
    #define PRDF_FUNC "[PlatServices::getConnectedPeerTarget] "

    TargetHandle_t o_target = NULL;

    do
    {
        if ( NULL == i_target )
        {
            PRDF_ERR( PRDF_FUNC"Given target is NULL" );
            break;
        }

        TYPE type = getTargetType( i_target );

        switch( type )
        {
            case TYPE_XBUS:
            case TYPE_ABUS:
            case TYPE_PSI:

                o_target = i_target->getAttr<ATTR_PEER_TARGET>();
                break;

            default:
                PRDF_ERR( PRDF_FUNC"Target type not supported: i_target=0x%08x "
                          "type=0x%x", getHuid(i_target), type );
        }


    } while(0);

    return o_target;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedPeerProc( TargetHandle_t i_procTarget,
                                     TYPE i_busType, uint32_t i_busPos )
{
    #define PRDF_FUNC "[PlatServices::getConnectedPeerProc] "

    TargetHandle_t o_target = NULL;

    do
    {
        if ( NULL == i_procTarget || TYPE_PROC != getTargetType(i_procTarget) )
        {
            PRDF_ERR( PRDF_FUNC"Given target is not of TYPE_PROC: "
                      "i_procTarget=0x%08x", getHuid(i_procTarget) );
            break;
        }

        if ( !( ((TYPE_XBUS == i_busType) && (MAX_XBUS_PER_PROC > i_busPos)) ||
                ((TYPE_ABUS == i_busType) && (MAX_ABUS_PER_PROC > i_busPos)) ) )
            break;

        // Starting PROC -> starting XBUS/ABUS.
        TargetHandle_t busTarget = getConnectedChild( i_procTarget, i_busType,
                                                      i_busPos );
        if ( NULL == busTarget ) break;

        // Starting XBUS/ABUS -> ATTR_PEER_TARGET -> destination XBUS/ABUS.
        TargetHandle_t destTarget = getConnectedPeerTarget( busTarget );
        if ( NULL == destTarget ) break;

        // Destination XBUS/ABUS -> destination PROC.
        o_target = getConnectedParent( destTarget, TYPE_PROC );

    } while(0);

    return o_target;

    #undef PRDF_FUNC
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
                                           TargetService::ALL,
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

    return o_list;
}

//------------------------------------------------------------------------------

bool checkLastFuncEx( TARGETING::TargetHandle_t i_exTarget )
{
    bool o_lastEx = false;

    TargetHandleList l_list = getFunctionalTargetList( TYPE_EX );
    if ( 1 == l_list.size() && l_list[0] == i_exTarget )
        o_lastEx = true;

    return o_lastEx;
}

//##############################################################################
//##
//##                       Target position support code
//##
//##############################################################################

uint32_t getTargetPosition( TARGETING::TargetHandle_t i_target )
{
    #define PRDF_FUNC "[PlatServices::getTargetPosition] "

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
                case TYPE_OSC:
                case TYPE_OSCPCICLK:
                case TYPE_OSCREFCLK:
                {
                    uint16_t tmpPos = 0;
                    if ( !i_target->tryGetAttr<ATTR_POSITION>(tmpPos) )
                    {
                        PRDF_ERR( PRDF_FUNC"Failed to get ATTR_POSITION" );
                    }
                    else
                        o_pos = (uint32_t)tmpPos;
                    break;
                }

                case TYPE_MEMBUF:
                    o_pos = getMemChnl( i_target );
                    break;

                default:
                    PRDF_ERR( PRDF_FUNC"Unsupported type: %d", l_type );
            }
            break;
        }

        case CLASS_UNIT:
        {
            uint8_t tmpPos = 0;
            if ( !i_target->tryGetAttr<ATTR_CHIP_UNIT>(tmpPos) )
            {
                PRDF_ERR( PRDF_FUNC"Failed to get ATTR_CHIP_UNIT" );
            }
            else
                o_pos = (uint32_t)tmpPos;
            break;
        }

        case CLASS_ENC:
            o_pos = getNodePosition( i_target );
            break;

        default:
            PRDF_ERR( PRDF_FUNC"Unsupported class: %d", l_class );
    }

    if ( INVALID_POSITION_BOUND == o_pos )
    {
        PRDF_ERR( PRDF_FUNC"Failed: target=0x%08x", getHuid(i_target) );
    }

    #undef PRDF_FUNC

    return o_pos;
}

//------------------------------------------------------------------------------

uint32_t getNodePosition( TARGETING::TargetHandle_t i_target )
{
    uint32_t o_pos = INVALID_POSITION_BOUND;

    do
    {
        // Get the node handle.
        TargetHandle_t node = getConnectedParent( i_target, TYPE_NODE );
        if ( NULL == node )
        {
            PRDF_ERR( "[getNodePosition] Failed to get node target" );
            break;
        }

        // FIXME: While this code works, it is preferred to use the POSITION
        //        attribute of the node. Currently, this attribute does not
        //        exist but it will, eventually. (RTC WI expected from Nick
        //        Bofferding)
        EntityPath l_path ( EntityPath::PATH_PHYSICAL );
        int32_t l_rc = getEntityPath( node, l_path );
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

//------------------------------------------------------------------------------

TARGETING::MODEL getProcModel( TARGETING::TargetHandle_t i_proc )
{
    #define PRDF_FUNC "[PlatServices::getProcModel] "

    MODEL l_model = MODEL_NA;
    if( TYPE_PROC == getTargetType( i_proc ) )
    {
        l_model = i_proc->getAttr<ATTR_MODEL>();
    }
    else
    {
        PRDF_ERR( PRDF_FUNC"Invalid Target Huid = 0x%08x", getHuid( i_proc ) );
    }

    return l_model;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t getPhbConfig( TARGETING::TargetHandle_t i_proc )
{
    #define PRDF_FUNC "[PlatServices::getPhbConfig] "

    uint32_t l_pciConfig = 0xffffffff;

    if ( TYPE_PROC == getTargetType(i_proc) )
    {
        l_pciConfig = i_proc->getAttr<ATTR_PROC_PCIE_IOP_CONFIG>();
    }
    else
    {
        PRDF_ERR( PRDF_FUNC"Invalid Target Huid = 0x%08x", getHuid(i_proc) );
    }

    return l_pciConfig;

    #undef PRDF_FUNC
}

//##############################################################################
//##
//##                        Memory specific functions
//##
//##############################################################################

int32_t getMasterRanks( TargetHandle_t i_memTrgt,
                        std::vector<CenRank> & o_ranks,
                        uint8_t i_ds )
{
    #define PRDF_FUNC "PlatServices::getMasterRanks] "

    int32_t o_rc = FAIL;

    o_ranks.clear();

    do
    {
        if ( NULL == i_memTrgt ) break;

        TargetHandle_t mbaTrgt = getConnectedParent( i_memTrgt, TYPE_MBA );
        if ( NULL == mbaTrgt )
        {
            PRDF_ERR( PRDF_FUNC"getConnectedParent() failed" );
            break;
        }

        if( MAX_DIMM_PER_PORT < i_ds )
        {
            PRDF_ERR( PRDF_FUNC"Invalid value for Dimm Slct:%u", i_ds );
            break;
        }

        uint8_t info[MAX_PORT_PER_MBA][MAX_DIMM_PER_PORT];
        if ( !mbaTrgt->tryGetAttr<ATTR_EFF_DIMM_RANKS_CONFIGED>(info) )
        {
            PRDF_ERR( PRDF_FUNC"Failed to get ATTR_EFF_DIMM_RANKS_CONFIGED" );
            break;
        }

        // NOTE: DIMMs must be plugged into pairs. So the values for each port
        //       select will be the same for each DIMM select. There is no need
        //       to interate on both port selects.

        for ( uint32_t ds = 0; ds < MAX_DIMM_PER_PORT; ds++ )
        {
            // if we are requested to get master ranks on a specific
            // DIMM, ignore if ds does not match the specific DIMM.
            // We have kept MAX_DIMM_PER_PORT as special value ( default )
            // for getting total ranks across both DIMMS.

            if( ( MAX_DIMM_PER_PORT != i_ds ) && ( ds != i_ds ) )
                continue;

            uint8_t rankMask = info[0][ds];

            if ( 0 == (rankMask & 0xf0) ) continue; // Nothing configured.

            for ( uint32_t rs = 0; rs < 4; rs++ )
            {
                if ( 0 != (rankMask & (0x80 >> rs)) )
                {
                    o_ranks.push_back( CenRank((ds << 2) | rs) );
                }
            }
        }

        o_rc = SUCCESS;

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_memTrgt=0x%08x", getHuid(i_memTrgt) );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t getMemChnl( TARGETING::TargetHandle_t i_memTarget )
{
    #define PRDF_FUNC "[PlatServices::getMemChnl] "

    uint32_t o_chnl = INVALID_POSITION_BOUND; // Intentially set to
                                              // INVALID_POSITION_BOUND for call
                                              // from getTargetPosition().

    do
    {
        if ( NULL == i_memTarget ) break;

        TargetHandle_t mcsTarget = getConnectedParent( i_memTarget, TYPE_MCS );
        if ( NULL == mcsTarget )
        {
            PRDF_ERR( PRDF_FUNC"getConnectedParent() failed" );
            break;
        }

        o_chnl = getTargetPosition( mcsTarget );

    } while (0);

    if ( MAX_MCS_PER_PROC <= o_chnl ) // Real MCS position check.
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_memTarget=0x%08x",
                  getHuid(i_memTarget) );
    }

    return o_chnl;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t isMembufOnDimm( TARGETING::TargetHandle_t i_memTarget,
                        bool & o_isBuffered )
{
    int32_t o_rc = FAIL;

    o_isBuffered = false;

    do
    {
        // The DIMMs in an node should either all be buffered or all not. So
        // we can check the attribute from ANY MBA.
        TargetHandleList list = getConnected( i_memTarget, TYPE_MBA );
        if ( 0 == list.size() )
        {
            PRDF_ERR( "[isMembufOnDimm] Couldn't find an MBA target" );
            break;
        }

        TargetHandle_t mbaTarget = list[0];

        o_isBuffered = mbaTarget->getAttr<ATTR_EFF_CUSTOM_DIMM>();

        o_rc = SUCCESS;

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "[isMembufOnDimm] Failed: i_memTarget=0x%08x",
                  getHuid(i_memTarget) );
    }

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t getMbaPort( TARGETING::TargetHandle_t i_dimmTarget, uint8_t & o_port )
{
    return i_dimmTarget->tryGetAttr<ATTR_MBA_PORT>(o_port) ? SUCCESS : FAIL;
}

//------------------------------------------------------------------------------

int32_t getMbaDimm( TARGETING::TargetHandle_t i_dimmTarget, uint8_t & o_dimm )
{
    return i_dimmTarget->tryGetAttr<ATTR_MBA_DIMM>(o_dimm) ? SUCCESS : FAIL;
}

//------------------------------------------------------------------------------

int32_t getDramGen( TARGETING::TargetHandle_t i_mba, uint8_t & o_dramGen )
{
    #define PRDF_FUNC "[PlatServices::getDramGen] "

    int32_t o_rc = FAIL;
    do
    {
        if ( TYPE_MBA != getTargetType( i_mba ) )
        {
            PRDF_ERR( PRDF_FUNC"Invalid Target. HUID:0X%08X",
                      getHuid( i_mba ) );
            break;
        }

        o_dramGen = i_mba->getAttr<ATTR_EFF_DRAM_GEN>( );

        o_rc = SUCCESS;

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t getDimmRowCol( TARGETING::TargetHandle_t i_mba, uint8_t & o_rowNum,
                       uint8_t & o_colNum )
{
    #define PRDF_FUNC "[PlatServices::getDimmRowCol] "

    int32_t o_rc = FAIL;
    do
    {
        if ( TYPE_MBA != getTargetType( i_mba ) )
        {
            PRDF_ERR( PRDF_FUNC"Invalid Target. HUID:0X%08X",
                      getHuid( i_mba ) );
            break;
        }

        o_rowNum = i_mba->getAttr<ATTR_EFF_DRAM_ROWS>();
        o_colNum = i_mba->getAttr<ATTR_EFF_DRAM_COLS>();

        o_rc = SUCCESS;

    }while(0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool isDramWidthX4( TargetHandle_t i_mba )
{
    return ( fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4 ==
             i_mba->getAttr<ATTR_EFF_DRAM_WIDTH>() );
}

//------------------------------------------------------------------------------

uint8_t getRanksPerDimm( TargetHandle_t i_mba, uint8_t i_ds )
{
    #define PRDF_FUNC "[PlatServices::getRanksPerDimm] "

    uint8_t rankCount = 0; // default if something fails

    do
    {
        if ( MAX_DIMM_PER_PORT <= i_ds )
        {
            PRDF_ERR( PRDF_FUNC"Invalid parameters i_ds:%u", i_ds );
            break;
        }

        // NOTE: Unable to use getAttr() because it is not able to return an
        //       array. Otherwise, all of the following would be able to fit in
        //       one line of code. The targeting may fix this later.

        ATTR_EFF_NUM_RANKS_PER_DIMM_type attr;
        if ( !i_mba->tryGetAttr<ATTR_EFF_NUM_RANKS_PER_DIMM>(attr) )
        {
            PRDF_ERR( PRDF_FUNC"failed to get ATTR_EFF_NUM_RANKS_PER_DIMM" );
            break;
        }

        // Note that DIMMs are plugged in pairs so the rank numbers should be
        // the same for each port.
        rankCount = attr[0][i_ds];

    } while(0);

    return rankCount;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

//##############################################################################
//##
//##                        Clock specific functions
//##
//##############################################################################

TARGETING::TargetHandle_t getClockId(TARGETING::TargetHandle_t
                            i_pGivenTarget,
                            TARGETING ::TYPE i_connType,
                            uint32_t i_oscPos)
{
    #define PRDF_FUNC "[PlatServices::getClockId] "

    TargetHandleList l_clockCardlist;
    TargetHandle_t l_target = i_pGivenTarget;
    TargetHandle_t o_pClockCardHandle = NULL;

    do
    {
        if ( i_oscPos >= MAX_PCIE_OSC_PER_NODE )
        {
            PRDF_ERR(PRDF_FUNC"target: 0x%.8X - invalid "
                "i_oscPos: %d", getHuid(i_pGivenTarget), i_oscPos);
            break;
        }

        // If membuf target, use the connected proc target
        if(TYPE_MEMBUF == getTargetType(i_pGivenTarget))
        {
            l_target = getConnectedParent(i_pGivenTarget, TYPE_PROC);
            if(NULL == l_target)
            {
                PRDF_ERR(PRDF_FUNC"failed to get proc target "
                         "connected to membuf 0x%.8X",
                         getHuid(l_target));
                break;
            }
        }

        PredicateIsFunctional l_funcFilter;
        PredicateCTM l_oscFilter(CLASS_CHIP, i_connType);
        PredicateCTM l_peerFilter(CLASS_UNIT,
                                  (i_connType == TYPE_OSCREFCLK ?
                                   TYPE_REFCLKENDPT: TYPE_PCICLKENDPT));
        PredicatePostfixExpr l_funcAndOscFilter, l_funcAndPeerFilter;
        l_funcAndOscFilter.push(&l_oscFilter).push(&l_funcFilter).And();
        l_funcAndPeerFilter.push(&l_peerFilter).push(&l_funcFilter).And();

        //PROC <---> CLKTYPE <---> PEER <---> CLKTYPE <---> OSC
        //Get the oscillators related to this proc
        getPeerTargets( l_clockCardlist,    // List of connected OSCs
                        l_target,           // to this proc
                        // filter to get to clock endpoints
                        &l_funcAndPeerFilter/*&l_peerFilter*/,
                        // filter to get the driving OSC
                        &l_funcAndOscFilter/*&l_oscFilter*/);

        for(TargetHandleList::iterator l_itr = l_clockCardlist.begin();
            l_itr != l_clockCardlist.end();
            ++l_itr)
        {
            PRDF_TRAC(PRDF_FUNC"OSC 0x%.8X, pos: %d is connected to "
             "proc 0x%.8X, inputOscPos: %d", getHuid(*l_itr),
             getTargetPosition(*l_itr), getHuid(l_target), i_oscPos);

            if ( i_oscPos == getTargetPosition(*l_itr) )
            {
                o_pClockCardHandle = *l_itr;
            }
        }

    } while(0);

    return o_pClockCardHandle;

    #undef PRDF_FUNC
}

//##############################################################################
//##                     MNFG Policy Flag Functions
//##############################################################################

// Helper function to access the state of manufacturing policy flags.
bool isMnfgFlagSet( uint32_t i_flag )
{
    bool o_rc = false;
    ATTR_MNFG_FLAGS_type l_attrValue = 0;
    TargetHandle_t l_pTopTarget= NULL;
    targetService().getTopLevelTarget(l_pTopTarget);
    if(l_pTopTarget)
    {
        l_attrValue = l_pTopTarget->getAttr<ATTR_MNFG_FLAGS>();
        o_rc = l_attrValue & i_flag;
    }
    else
    {
        PRDF_ERR("[isMnfgFlagSet] error finding l_pTopTarget");
    }

    //PRDF_TRAC("[isMnfgFlagSet] MNFG Flags: 0x%016llX, i_flag: "
    //          "0x%08X, o_rc: %d", l_attrValue, i_flag, o_rc);

    return o_rc;
}

//------------------------------------------------------------------------------

bool mfgMode()
{ return isMnfgFlagSet( MNFG_FLAG_THRESHOLDS      ); }

bool mnfgTerminate()
{ return isMnfgFlagSet( MNFG_FLAG_SRC_TERM        ); }

bool areDramRepairsDisabled()
{ return isMnfgFlagSet( MNFG_FLAG_DISABLE_DRAM_REPAIRS ); }

bool enableFastBgScrub()
{ return isMnfgFlagSet( MNFG_FLAG_FAST_BACKGROUND_SCRUB ); }

bool mnfgSpareDramDeploy()
{ return isMnfgFlagSet( MNFG_FLAG_TEST_DRAM_REPAIRS ); }

bool isMfgCeCheckingEnabled()
{ return isMnfgFlagSet( MNFG_FLAG_IPL_MEMORY_CE_CHECKING ); }

} // end namespace PlatServices

} // end namespace PRDF

