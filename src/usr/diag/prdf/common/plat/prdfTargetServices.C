/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfTargetServices.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
 * @brief PRD wrapper of targeting code
 */

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <prdfTargetServices.H>

// Framework includes
#include <iipServiceDataCollector.h>
#include <iipSystem.h>
#include <prdfAssert.h>
#include <prdfErrlUtil.H>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfTrace.H>
#include <xspprdService.h>

// External includes
#include <algorithm>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>

// Platform includes
#include <prdfMemAddress.H>

using namespace TARGETING;

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##
//##                     System Level Utility Functions
//##
//##############################################################################

// local utility function.
ATTR_PAYLOAD_KIND_type getPayloadType()
{
    return getSystemTarget()->getAttr<ATTR_PAYLOAD_KIND>();
}

//------------------------------------------------------------------------------

bool isHyprConfigPhyp()
{
    return PAYLOAD_KIND_PHYP == getPayloadType();
}

//------------------------------------------------------------------------------

bool isHyprConfigOpal()
{
    return PAYLOAD_KIND_SAPPHIRE == getPayloadType();
}

//------------------------------------------------------------------------------

bool isHyprRunning()
{
    bool rc = false;

    #ifdef __HOSTBOOT_MODULE

        // ATTR_PAYLOAD_STATE is not defined in Hostboot. We can assume that if
        // __HOSTBOOT_RUNTIME is defined then the hypervisor is running.

        #ifdef __HOSTBOOT_RUNTIME
        rc = true;
        #else
        rc = false;
        #endif

    #else

    TargetHandle_t sysTrgt = getSystemTarget();
    rc = (PAYLOAD_STATE_RUNNING == sysTrgt->getAttr<ATTR_PAYLOAD_STATE>());

    #endif

    return rc;
}

bool hasRedundantClocks()
{
    return ( 0 != getSystemTarget()->getAttr<ATTR_REDUNDANT_CLOCKS>() );
}

//##############################################################################
//##
//##                         General Utility Functions
//##
//##############################################################################

void hwpErrorIsolation( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #if defined (__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)

    TargetHandle_t trgt = i_chip->getTrgt();
    uint32_t plid = 0;

    // Check for non-zero value in PLID attribute.
    if ( trgt->tryGetAttr<ATTR_PRD_HWP_PLID>(plid) && (0 != plid) )
    {
        PRDF_INF( "ATTR_PRD_HWP_PLID found on 0x%08x with value 0x%08x",
                  getHuid(trgt), plid );

        // Link HWP PLID to PRD error log.
        ServiceGeneratorClass::ThisServiceGenerator().getErrl()->plid( plid );

        // Clear PRD_HWP_PLID attribute.
        trgt->setAttr<ATTR_PRD_HWP_PLID>( 0 );

        // Make the error log and callouts predictive.
        io_sc.service_data->setServiceCall();
    }

    #endif
}

//##############################################################################
//##
//##                 Target Manipulation Utility Functions
//##
//##############################################################################

// FIXME: RTC 62867
//        This function is using type PRDF::HUID. I think it should now be using
//        TARGETING::HUID_ATTR. Also, will need equivalent to
//        PRDF::INVALID_HUID. I think HWSV has HWSV_INVALID_HUID, but I don't
//        think that exists in Hostboot. Need a common interface before making
//        changes.
TARGETING::TargetHandle_t getTarget( HUID i_huid )
{
    TargetHandle_t o_target = NULL;

    // FIXME: RTC 62867
    //        This is an incredibly inefficient linear search. It is recommended
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

TARGETING::MODEL getChipModel( TARGETING::TargetHandle_t i_trgt )
{
    PRDF_ASSERT( NULL != i_trgt );

    TargetHandle_t parent = getParentChip( i_trgt );
    PRDF_ASSERT( NULL != parent );

    return parent->getAttr<ATTR_MODEL>();
}

//------------------------------------------------------------------------------

uint8_t getChipLevel( TARGETING::TargetHandle_t i_trgt )
{
    PRDF_ASSERT( NULL != i_trgt );

    TargetHandle_t parent = getParentChip( i_trgt );
    PRDF_ASSERT( NULL != parent );

    return parent->getAttr<ATTR_EC>();
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
            PRDF_ERR(PRDF_FUNC "invalid target type: 0x%08x", type);
        }
    }
    else
    {
        PRDF_ERR(PRDF_FUNC "i_target is null");
    }

    #undef PRDF_FUNC
}

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
            case TYPE_SYS:          order =  0; break;
            case TYPE_NODE:         order =  1; break;
            case TYPE_PROC:         order =  2; break;
            case TYPE_EQ:           order =  3; break;
            case TYPE_EX:           order =  4; break;
            case TYPE_CORE:         order =  5; break;
            case TYPE_CAPP:         order =  6; break;
            case TYPE_PEC:          order =  7; break;
            case TYPE_PHB:          order =  8; break;
            case TYPE_OBUS:         order =  9; break;
            case TYPE_XBUS:         order = 10; break;
            case TYPE_NX:           order = 11; break;
            case TYPE_OCC:          order = 12; break;
            case TYPE_PSI:          order = 13; break;
            case TYPE_MCBIST:       order = 14; break;
            case TYPE_MCS:          order = 15; break;
            case TYPE_MCA:          order = 16; break;
            case TYPE_MC:           order = 17; break;
            case TYPE_MI:           order = 18; break;
            case TYPE_DMI:          order = 19; break;
            case TYPE_MEMBUF:       order = 20; break;
            case TYPE_L4:           order = 21; break;
            case TYPE_MBA:          order = 22; break;
            case TYPE_DIMM:         order = 23; break;
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

TargetService::ASSOCIATION_TYPE getAssociationType( TargetHandle_t i_target,
                                                    TYPE i_connType )
{
    #define PRDF_FUNC "[PlatServices::getAssociationType] "

    PRDF_ASSERT( nullptr != i_target );

    static conn_t lookups[] =
    {
        // This table must be sorted based on the < operator of struct conn_t.
        { TYPE_SYS,    TYPE_NODE,       TargetService::CHILD_BY_AFFINITY  },

        { TYPE_NODE,   TYPE_SYS,        TargetService::PARENT_BY_AFFINITY },
        { TYPE_NODE,   TYPE_PROC,       TargetService::CHILD_BY_AFFINITY  },
        { TYPE_NODE,   TYPE_MEMBUF,     TargetService::CHILD_BY_AFFINITY },

        { TYPE_PROC,   TYPE_NODE,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_PROC,   TYPE_EQ,         TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_EX,         TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_CORE,       TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_CAPP,       TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_PEC,        TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_PHB,        TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_OBUS,       TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_XBUS,       TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_NX,         TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_OCC,        TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_PSI,        TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_MCBIST,     TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_MCS,        TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_MCA,        TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_MC,         TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_MI,         TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_DMI,        TargetService::CHILD_BY_AFFINITY  },
        { TYPE_PROC,   TYPE_MEMBUF,     TargetService::CHILD_BY_AFFINITY  },

        { TYPE_EQ,     TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_EQ,     TYPE_EX,         TargetService::CHILD_BY_AFFINITY  },
        { TYPE_EQ,     TYPE_CORE,       TargetService::CHILD_BY_AFFINITY  },

        { TYPE_EX,     TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_EX,     TYPE_EQ,         TargetService::PARENT_BY_AFFINITY },
        { TYPE_EX,     TYPE_CORE,       TargetService::CHILD_BY_AFFINITY  },

        { TYPE_CORE,   TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_CORE,   TYPE_EQ,         TargetService::PARENT_BY_AFFINITY },
        { TYPE_CORE,   TYPE_EX,         TargetService::PARENT_BY_AFFINITY },

        { TYPE_CAPP,   TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },

        { TYPE_PEC,    TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_PEC,    TYPE_PHB,        TargetService::CHILD_BY_AFFINITY  },

        { TYPE_PHB,    TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },

        { TYPE_OBUS,   TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },

        { TYPE_XBUS,   TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },

        { TYPE_NX,     TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },

        { TYPE_OCC,    TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },

        { TYPE_PSI,    TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },

        { TYPE_MCBIST, TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCBIST, TYPE_MCS,        TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MCBIST, TYPE_MCA,        TargetService::CHILD_BY_AFFINITY  },

        { TYPE_MCS,    TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCS,    TYPE_MCBIST,     TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCS,    TYPE_MCA,        TargetService::CHILD_BY_AFFINITY  },

        { TYPE_MCA,    TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCA,    TYPE_MCBIST,     TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCA,    TYPE_MCS,        TargetService::PARENT_BY_AFFINITY },
        { TYPE_MCA,    TYPE_DIMM,       TargetService::CHILD_BY_AFFINITY  },

        { TYPE_MC,     TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_MC,     TYPE_MI,         TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MC,     TYPE_DMI,        TargetService::CHILD_BY_AFFINITY  },

        { TYPE_MI,     TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_MI,     TYPE_MC,         TargetService::PARENT_BY_AFFINITY },
        { TYPE_MI,     TYPE_DMI,        TargetService::CHILD_BY_AFFINITY  },

        { TYPE_DMI,    TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_DMI,    TYPE_MC,         TargetService::PARENT_BY_AFFINITY },
        { TYPE_DMI,    TYPE_MI,         TargetService::PARENT_BY_AFFINITY },
        { TYPE_DMI,    TYPE_MEMBUF,     TargetService::CHILD_BY_AFFINITY  },

        { TYPE_MEMBUF, TYPE_NODE,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_MEMBUF, TYPE_PROC,       TargetService::PARENT_BY_AFFINITY },
        { TYPE_MEMBUF, TYPE_DMI,        TargetService::PARENT_BY_AFFINITY },
        { TYPE_MEMBUF, TYPE_L4,         TargetService::CHILD_BY_AFFINITY  },
        { TYPE_MEMBUF, TYPE_MBA,        TargetService::CHILD_BY_AFFINITY  },

        { TYPE_L4,     TYPE_MEMBUF,     TargetService::PARENT_BY_AFFINITY },

        { TYPE_MBA,    TYPE_MEMBUF,     TargetService::PARENT_BY_AFFINITY },
        { TYPE_MBA,    TYPE_DIMM,       TargetService::CHILD_BY_AFFINITY  },

        { TYPE_DIMM,   TYPE_MCA,        TargetService::PARENT_BY_AFFINITY },
        { TYPE_DIMM,   TYPE_MBA,        TargetService::PARENT_BY_AFFINITY },

    };

    const size_t sz_lookups = sizeof(lookups) / sizeof(conn_t);

    TYPE type = getTargetType(i_target);

    conn_t match = { type, i_connType, TargetService::CHILD_BY_AFFINITY };

    conn_t * it = std::lower_bound( lookups, lookups + sz_lookups, match );

    if ( (it == lookups + sz_lookups) || // off the end
         (type != it->from) || (i_connType != it->to) ) // not equals
    {
        PRDF_ERR( PRDF_FUNC "Look-up failed: i_target=0x%08x i_connType=%d",
                  getHuid(i_target), i_connType );
        PRDF_ASSERT(false);
    }

    return it->type;

    #undef PRDF_FUNC
}

// Helper function for the various getConnected() functions.
TargetHandleList getConnAssoc( TargetHandle_t i_target, TYPE i_connType,
                               TargetService::ASSOCIATION_TYPE i_assocType )
{
    PRDF_ASSERT( nullptr != i_target );

    TargetHandleList o_list; // Default empty list

    // Match any class, specified type, and functional.
    PredicateCTM predType( CLASS_NA, i_connType );
    PredicateIsFunctional predFunc;
    PredicatePostfixExpr predAnd;
    predAnd.push(&predType).push(&predFunc).And();

    targetService().getAssociated( o_list, i_target, i_assocType,
                                   TargetService::ALL, &predAnd );

    // Sort by target position.
    std::sort( o_list.begin(), o_list.end(),
               [](TargetHandle_t a, TargetHandle_t b)
               { return getTargetPosition(a) < getTargetPosition(b); } );

    return o_list;
}

//------------------------------------------------------------------------------

TargetHandleList getConnected( TargetHandle_t i_target, TYPE i_connType )
{
    PRDF_ASSERT( nullptr != i_target );

    TargetHandleList o_list; // Default empty list

    if ( getTargetType(i_target) == i_connType )
    {
        o_list.push_back( i_target );
    }
    else
    {
        o_list = getConnAssoc( i_target, i_connType,
                               getAssociationType(i_target, i_connType) );
    }

    return o_list;
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedParent( TargetHandle_t i_target, TYPE i_connType )
{
    #define PRDF_FUNC "[PlatServices::getConnectedParent] "

    PRDF_ASSERT( nullptr != i_target );

    // Get the association type, must be PARENT_BY_AFFINITY.
    TargetService::ASSOCIATION_TYPE assocType = getAssociationType( i_target,
                                                                    i_connType);
    if ( TargetService::PARENT_BY_AFFINITY != assocType )
    {
        PRDF_ERR( PRDF_FUNC "Unsupported parent connection: i_target=0x%08x "
                  "i_connType=%d", getHuid(i_target), i_connType );
        PRDF_ASSERT(false);
    }

    // Get the connected parent, should be one and only one parent
    TargetHandleList list = getConnAssoc( i_target, i_connType, assocType );
    if ( 1 != list.size() || nullptr == list[0] )
    {
        PRDF_ERR( PRDF_FUNC "Could not find parent: i_target=0x%08x "
                  "i_connType=%d", getHuid(i_target), i_connType );
        PRDF_ASSERT(false);
    }

    return list[0];

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedChild( TargetHandle_t i_target, TYPE i_connType,
                                  uint32_t i_connPos )
{
    #define PRDF_FUNC "[PlatServices::getConnectedChild] "

    PRDF_ASSERT( nullptr != i_target );

    TargetHandle_t o_child = nullptr;

    // Get the association type, must be CHILD_BY_AFFINITY.
    TargetService::ASSOCIATION_TYPE assocType = getAssociationType( i_target,
                                                                    i_connType);
    if ( TargetService::CHILD_BY_AFFINITY != assocType )
    {
        PRDF_ERR( PRDF_FUNC "Unsupported child connection: i_target=0x%08x "
                  "i_connType=%d", getHuid(i_target), i_connType );
        PRDF_ASSERT(false);
    }

    // Get the list.
    TargetHandleList list = getConnAssoc( i_target, i_connType, assocType );
    if ( !list.empty() )
    {
        // There are some special cases where we need something other than to
        // match the unit positions. So check those first.

        TargetHandleList::iterator itr = list.end();
        TYPE     trgtType = getTargetType(     i_target );
        uint32_t trgtPos  = getTargetPosition( i_target );

        if ( TYPE_EQ == trgtType && TYPE_EX == i_connType )
        {
            // i_connPos is position relative to EQ (0-1)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t exPos = getTargetPosition(t);
                        return (trgtPos   == (exPos / MAX_EX_PER_EQ)) &&
                               (i_connPos == (exPos % MAX_EX_PER_EQ));
                    } );
        }
        else if ( TYPE_EQ == trgtType && TYPE_CORE == i_connType )
        {
            // i_connPos is position relative to EQ (0-3)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t ecPos = getTargetPosition(t);
                        return (trgtPos   == (ecPos / MAX_EC_PER_EQ)) &&
                               (i_connPos == (ecPos % MAX_EC_PER_EQ));
                    } );
        }
        else if ( TYPE_EX == trgtType && TYPE_CORE == i_connType )
        {
            // i_connPos is position relative to EX (0-1)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t ecPos = getTargetPosition(t);
                        return (trgtPos   == (ecPos / MAX_EC_PER_EX)) &&
                               (i_connPos == (ecPos % MAX_EC_PER_EX));
                    } );
        }
        else if ( TYPE_PEC == trgtType && TYPE_PHB == i_connType )
        {
            // i_connPos is position relative to PEC (0, 0-1, or 0-2)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t relPec = 0;
                        uint32_t relPhb = 0;
                        switch ( getTargetPosition(t) )
                        {
                            case 0: relPec = 0; relPhb = 0; break;
                            case 1: relPec = 1; relPhb = 0; break;
                            case 2: relPec = 1; relPhb = 1; break;
                            case 3: relPec = 2; relPhb = 0; break;
                            case 4: relPec = 2; relPhb = 1; break;
                            case 5: relPec = 2; relPhb = 2; break;
                        }
                        return (trgtPos == relPec) && (i_connPos == relPhb);
                    } );
        }
        else if ( TYPE_MCBIST == trgtType && TYPE_MCS == i_connType )
        {
            // i_connPos is position relative to MCBIST (0-1)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t mcbPos = getTargetPosition(t);
                        return (trgtPos   == (mcbPos / MAX_MCS_PER_MCBIST)) &&
                               (i_connPos == (mcbPos % MAX_MCS_PER_MCBIST));
                    } );

        }
        else if ( TYPE_MCBIST == trgtType && TYPE_MCA == i_connType )
        {
            // i_connPos is position relative to MCBIST (0-3)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t mcbPos = getTargetPosition(t);
                        return (trgtPos   == (mcbPos / MAX_MCA_PER_MCBIST)) &&
                               (i_connPos == (mcbPos % MAX_MCA_PER_MCBIST));
                    } );

        }
        else if ( TYPE_MCS == trgtType && TYPE_MCA == i_connType )
        {
            // i_connPos is position relative to MCS (0-1)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t mcaPos = getTargetPosition(t);
                        return (trgtPos   == (mcaPos / MAX_MCA_PER_MCS)) &&
                               (i_connPos == (mcaPos % MAX_MCA_PER_MCS));
                    } );
        }
        else if ( TYPE_MCA == trgtType && TYPE_DIMM == i_connType )
        {
            // i_connPos is the DIMM select (0-1). Note that we don't use
            // getTargetPosition() on the DIMM because that does not return a
            // value that is relative to the processor as we were expecting.
            // There really isn't a good position attribute that matches the
            // position in the affinity path. We can use ATTR_REL_POS, which
            // will always match the DIMM select. This does not let us match the
            // parent unit like all of the other checks in this functions.
            // Fortunately, it will be very difficult to have a bug where the
            // getConnected code returns DIMMs on a different MCA target. So
            // this is an acceptible risk.
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    { return ( i_connPos == t->getAttr<ATTR_REL_POS>() ); } );
        }
        else if ( TYPE_MC == trgtType && TYPE_MI == i_connType )
        {
            // i_connPos is position relative to MC (0-1)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t mcPos = getTargetPosition(t);
                        return (trgtPos   == (mcPos / MAX_MI_PER_MC)) &&
                               (i_connPos == (mcPos % MAX_MI_PER_MC));
                    } );
        }
        else if ( TYPE_MC == trgtType && TYPE_DMI == i_connType )
        {
            // i_connPos is position relative to MC (0-3)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t mcPos = getTargetPosition(t);
                        return (trgtPos   == (mcPos / MAX_DMI_PER_MC)) &&
                               (i_connPos == (mcPos % MAX_DMI_PER_MC));
                    } );
        }
        else if ( TYPE_MI == trgtType && TYPE_DMI == i_connType )
        {
            // i_connPos is position relative to MI (0-1)
            itr = std::find_if( list.begin(), list.end(),
                    [&](const TargetHandle_t & t)
                    {
                        uint32_t miPos = getTargetPosition(t);
                        return (trgtPos   == (miPos / MAX_DMI_PER_MI)) &&
                               (i_connPos == (miPos % MAX_DMI_PER_MI));
                    } );
        }
        else if ( TYPE_DMI == trgtType && TYPE_MEMBUF == i_connType )
        {
            // There is only one MEMBUF per DMI in the list.
            PRDF_ASSERT( 1 == list.size() ); // just in case
            itr = list.begin();
        }
        else if ( TYPE_MBA == trgtType && TYPE_DIMM == i_connType )
        {
            // TODO: RTC180690 This really wasn't supported in P8 because there
            //       are two ports and two DIMM selects per port and there
            //       wasn't a clean way to get the correct DIMM. MCA doesn't
            //       have this issue, but it would be nice to get a clean
            //       interface for both MCA and MBA.
        }
        else
        {
            // default, i_connPos should match the unit position within the chip
            itr = std::find_if( list.begin(), list.end(),
                                [&](const TargetHandle_t & t)
                                { return i_connPos == getTargetPosition(t); } );
        }

        // Get the target if found.
        if ( list.end() != itr )
            o_child = *itr;
    }

    return o_child;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

ExtensibleChipList getConnected( ExtensibleChip * i_chip, TYPE i_connType )
{
    PRDF_ASSERT( nullptr != i_chip );

    ExtensibleChipList o_list; // Default empty list

    TargetHandleList list = getConnected( i_chip->getTrgt(), i_connType );
    for ( auto & trgt : list )
    {
        o_list.push_back( (ExtensibleChip *)systemPtr->GetChip(trgt) );
    }

    return o_list;
}

//------------------------------------------------------------------------------

ExtensibleChip * getConnectedParent( ExtensibleChip * i_child,
                                     TYPE i_parentType )
{
    PRDF_ASSERT( nullptr != i_child );

    TargetHandle_t trgt = getConnectedParent( i_child->getTrgt(),
                                              i_parentType );

    return (ExtensibleChip *)systemPtr->GetChip( trgt );
}

//------------------------------------------------------------------------------

ExtensibleChip * getConnectedChild( ExtensibleChip * i_parent,
                                    TARGETING::TYPE i_childType,
                                    uint32_t i_childPos )
{
    PRDF_ASSERT( nullptr != i_parent );

    ExtensibleChip * o_child = nullptr;

    TargetHandle_t trgt = getConnectedChild( i_parent->getTrgt(),
                                             i_childType,
                                             i_childPos );
    if ( nullptr != trgt )
    {
        o_child = (ExtensibleChip *)systemPtr->GetChip( trgt );
    }

    return o_child;
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedPeerTarget( TargetHandle_t i_target )
{
    #define PRDF_FUNC "[PlatServices::getConnectedPeerTarget] "

    PRDF_ASSERT( NULL != i_target );

    TargetHandle_t o_target = NULL;

    do
    {
        TYPE type = getTargetType( i_target );

        switch( type )
        {
            case TYPE_XBUS:
            case TYPE_OBUS:
            case TYPE_PSI:

                o_target = i_target->getAttr<ATTR_PEER_TARGET>();
                break;

            default:
                PRDF_ERR( PRDF_FUNC "Target type not supported: i_target=0x%08x "
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

    PRDF_ASSERT( NULL != i_procTarget );
    PRDF_ASSERT( TYPE_PROC == getTargetType(i_procTarget) );
    PRDF_ASSERT( ((TYPE_XBUS == i_busType) && (MAX_XBUS_PER_PROC > i_busPos)) ||
                 ((TYPE_OBUS == i_busType) && (MAX_OBUS_PER_PROC > i_busPos)) );

    TargetHandle_t o_target = NULL;

    do
    {
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
    TargetHandle_t sysTarget = nullptr;
    targetService().getTopLevelTarget( sysTarget );

    PRDF_ASSERT( nullptr != sysTarget );

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

//------------------------------------------------------------------------------

TargetHandle_t getMasterProc()
{
    TargetHandle_t masterProc = NULL;
    targetService().masterProcChipTargetHandle( masterProc );
    return masterProc;
}

//##############################################################################
//##
//##                       Target position support code
//##
//##############################################################################

uint32_t getTargetPosition( TargetHandle_t i_trgt )
{
    #define PRDF_FUNC "[PlatServices::getTargetPosition] "

    PRDF_ASSERT( nullptr != i_trgt );

    uint32_t o_pos = 0;

    CLASS l_class = getTargetClass( i_trgt );
    TYPE  l_type  = getTargetType(  i_trgt );

    switch ( l_class )
    {
        case CLASS_CHIP: // chips
        {
            switch ( l_type )
            {
                case TYPE_PROC:
                case TYPE_OSC:
                case TYPE_OSCPCICLK:
                case TYPE_OSCREFCLK:
                case TYPE_MEMBUF:
                    o_pos = i_trgt->getAttr<ATTR_POSITION>();
                    break;

                default:
                    PRDF_ERR( PRDF_FUNC "Unsupported type %d for CLASS_CHIP: "
                              "i_trgt=0x%08x", l_type, getHuid(i_trgt) );
                    PRDF_ASSERT( false );
            }
            break;
        }

        case CLASS_UNIT: // units of a chip
            o_pos = i_trgt->getAttr<ATTR_CHIP_UNIT>();
            break;

        case CLASS_ENC: // nodes
            o_pos = i_trgt->getAttr<ATTR_ORDINAL_ID>();
            break;

        case CLASS_SYS: // system
            // The concept of a system position does not exist, however, we want
            // to allow generic code to get the target position for any target.
            // So we will add this special case.
            o_pos = 0;
            break;

        case CLASS_LOGICAL_CARD: // DIMMs
            o_pos = i_trgt->getAttr<ATTR_FAPI_POS>();
            break;

        default:
            PRDF_ERR( PRDF_FUNC "Unsupported class %d: i_trgt=0x%08x",
                      l_class, getHuid(i_trgt) );
            PRDF_ASSERT(false);
    }

    return o_pos;

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
        PRDF_ERR( PRDF_FUNC "Invalid Target Huid = 0x%08x", getHuid(i_proc) );
    }

    return l_pciConfig;

    #undef PRDF_FUNC
}

//##############################################################################
//##
//##                        Memory specific functions
//##
//##############################################################################

uint32_t getMemChnl( TargetHandle_t i_trgt )
{
    PRDF_ASSERT( nullptr != i_trgt );

    TargetHandle_t dmiTrgt = getConnectedParent( i_trgt, TYPE_DMI );

    return getTargetPosition( dmiTrgt );
}

//------------------------------------------------------------------------------

int32_t isMembufOnDimm( TARGETING::TargetHandle_t i_memTarget,
                        bool & o_isBuffered )
{
    int32_t o_rc = FAIL;

    o_isBuffered = false;

    do
    {
//         @TODO RTC: 153297 ATTR_EFF_CUSTOM_DIMM Type does not exist yet for P9
//                           and will change from how it was defined in P8
//
//        // The DIMMs in an node should either all be buffered or all not. So
//        // we can check the attribute from ANY MBA.
//        TargetHandleList list = getConnected( i_memTarget, TYPE_MBA );
//        if ( 0 == list.size() )
//        {
//            PRDF_ERR( "[isMembufOnDimm] Couldn't find an MBA target" );
//            break;
//        }
//
//
//         const TargetHandle_t mbaTarget = list[0];
//         o_isBuffered = mbaTarget->getAttr<ATTR_EFF_CUSTOM_DIMM>();

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

template<>
int32_t getDimmSlct<TYPE_MBA>( TARGETING::TargetHandle_t i_dimmTarget,
                               uint8_t & o_dimm )
{
    o_dimm = i_dimmTarget->getAttr<ATTR_MBA_DIMM>();
    return SUCCESS;
}

template<>
int32_t getDimmSlct<TYPE_MCA>( TARGETING::TargetHandle_t i_dimmTarget,
                               uint8_t & o_dimm )
{
    o_dimm = i_dimmTarget->getAttr<TARGETING::ATTR_FAPI_POS>() %
                                             MAX_DIMM_PER_PORT;
    return SUCCESS;
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
            PRDF_ERR( PRDF_FUNC "Invalid Target. HUID:0X%08X",
                      getHuid( i_mba ) );
            break;
        }
        //@TODO RTC: 153297 ATTR_EFF_CUSTOM_DIMM Type has changed
//         o_dramGen = i_mba->getAttr<ATTR_EFF_DRAM_GEN>( );

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
            PRDF_ERR( PRDF_FUNC "Invalid Target. HUID:0X%08X",
                      getHuid( i_mba ) );
            break;
        }

        ATTR_MODEL_type l_procModel = getChipModel( getMasterProc() );
        if ( MODEL_CUMULUS == l_procModel )
        {
            o_rowNum = i_mba->getAttr<ATTR_CEN_EFF_DRAM_ROWS>();
            o_colNum = i_mba->getAttr<ATTR_CEN_EFF_DRAM_COLS>();
        }
        else // NIMBUS or something without CENTAURs
        {
            o_rowNum = i_mba->getAttr<ATTR_EFF_DRAM_ROWS>();
            o_colNum = i_mba->getAttr<ATTR_EFF_DRAM_COLS>();
        }

        o_rc = SUCCESS;

    }while(0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool isDramWidthX4( TargetHandle_t i_trgt )
{
    // TODO RTC 161599
    // all drams for Nimbus will be treated as X4 - this will need to be
    // updated for Cumulus
    return true;
    //return ( fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4 ==
    //         i_trgt->getAttr<ATTR_EFF_DRAM_WIDTH>() );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __getMasterRanks( TargetHandle_t i_trgt, std::vector<MemRank> & o_ranks,
                       uint8_t i_pos, uint8_t i_ds )
{
    #define PRDF_FUNC "[__getMasterRanks] "

    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( T == getTargetType(i_trgt) );
    PRDF_ASSERT( i_pos < 2 );
    PRDF_ASSERT( i_ds <= MAX_DIMM_PER_PORT ); // can equal MAX_DIMM_PER_PORT

    o_ranks.clear();

    uint8_t info[2][2];

    ATTR_MODEL_type l_procModel = getChipModel( getMasterProc() );
    if ( MODEL_CUMULUS == l_procModel )
    {
        if ( !i_trgt->tryGetAttr<ATTR_CEN_EFF_DIMM_RANKS_CONFIGED>(info) )
        {
            PRDF_ERR( PRDF_FUNC "tryGetAttr<ATTR_CEN_EFF_DIMM_RANKS_CONFIGED> "
                      "failed: i_trgt=0x%08x", getHuid(i_trgt) );
            PRDF_ASSERT( false ); // attribute does not exist for target
        }
    }
    else if ( !i_trgt->tryGetAttr<ATTR_EFF_DIMM_RANKS_CONFIGED>(info) )
    {
        PRDF_ERR( PRDF_FUNC "tryGetAttr<ATTR_EFF_DIMM_RANKS_CONFIGED> "
                  "failed: i_trgt=0x%08x", getHuid(i_trgt) );
        PRDF_ASSERT( false ); // attribute does not exist for target
    }

    for ( uint32_t ds = 0; ds < MAX_DIMM_PER_PORT; ds++ )
    {
        // Check if user gave a specific value for i_ds.
        if ( (MAX_DIMM_PER_PORT != i_ds) && (ds != i_ds) )
            continue;

        uint8_t rankMask = info[i_pos][ds];

        // The configured rank selects are in the first nibble.
        for ( uint32_t rs = 0; rs < 4; rs++ )
        {
            if ( 0 != (rankMask & (0x80 >> rs)) )
            {
                // Note that the ranks are getting inserted in order so no need
                // to sort later.
                o_ranks.push_back( MemRank((ds << 2) | rs) );
            }
        }
    }

    #undef PRDF_FUNC
}

template<>
void getMasterRanks<TYPE_MCA>( TargetHandle_t i_trgt,
                               std::vector<MemRank> & o_ranks,
                               uint8_t i_ds )
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_MCA == getTargetType(i_trgt) );

    // NOTE: The attribute lives on the MCS. So need to get the MCS target and
    //       the position of the MCA relative to the MCS.
    TargetHandle_t mcsTrgt = getConnectedParent( i_trgt, TYPE_MCS );
    uint8_t relPos = getTargetPosition(i_trgt) % MAX_MCA_PER_MCS;

    __getMasterRanks<TYPE_MCS>( mcsTrgt, o_ranks, relPos, i_ds );
}

template<>
void getMasterRanks<TYPE_MBA>( TargetHandle_t i_trgt,
                               std::vector<MemRank> & o_ranks,
                               uint8_t i_ds )
{
    // NOTE: DIMMs must be plugged into pairs. So the values for each port
    //       select will be the same for each DIMM select. There is no need to
    //       iterate on both port selects.
    __getMasterRanks<TYPE_MBA>( i_trgt, o_ranks, 0, i_ds );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __getSlaveRanks( TargetHandle_t i_trgt, std::vector<MemRank> & o_ranks,
                      uint8_t i_ds )
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( T == getTargetType(i_trgt) );
    PRDF_ASSERT( i_ds <= MAX_DIMM_PER_PORT ); // can equal MAX_DIMM_PER_PORT

    o_ranks.clear();

    for ( uint32_t ds = 0; ds < MAX_DIMM_PER_PORT; ds++ )
    {
        // Check if user gave a specific value for i_ds.
        if ( (MAX_DIMM_PER_PORT != i_ds) && (ds != i_ds) )
            continue;

        // Get the number of slave ranks per master rank.
        uint8_t numRanks = getNumRanksPerDimm<T>( i_trgt, ds );
        if ( 0 == numRanks ) continue; // nothing to do

        uint8_t numMasterRanks = getNumMasterRanksPerDimm<T>( i_trgt, ds );
        PRDF_ASSERT( 0 < numMasterRanks ); // ATTR bug

        uint8_t numSlaveRanks = numRanks / numMasterRanks;

        // Get the current list of master ranks for this DIMM select
        std::vector<MemRank> tmpList;
        getMasterRanks<T>( i_trgt, tmpList, ds );

        // Start inserting the slave ranks into the list.
        for ( auto & mrank : tmpList )
        {
            for ( uint8_t s = 0; s < numSlaveRanks; s++ )
            {
                // Note that the ranks are getting inserted in order so no need
                // to sort later.
                o_ranks.push_back( MemRank(mrank.getMaster(), s) );
            }
        }
    }
}

template<>
void getSlaveRanks<TYPE_MCA>( TargetHandle_t i_trgt,
                              std::vector<MemRank> & o_ranks,
                              uint8_t i_ds )
{
    __getSlaveRanks<TYPE_MCA>( i_trgt, o_ranks, i_ds );
}

template<>
void getSlaveRanks<TYPE_MBA>( TargetHandle_t i_trgt,
                              std::vector<MemRank> & o_ranks,
                              uint8_t i_ds )
{
    __getSlaveRanks<TYPE_MBA>( i_trgt, o_ranks, i_ds );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint8_t __getNumMasterRanksPerDimm( TargetHandle_t i_trgt,
                                    uint8_t i_pos, uint8_t i_ds )
{
    #define PRDF_FUNC "[__getNumMasterRanksPerDimm] "

    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( T == getTargetType(i_trgt) );
    PRDF_ASSERT( i_pos < 2 );
    PRDF_ASSERT( i_ds < MAX_DIMM_PER_PORT );
    uint8_t num;


    ATTR_MODEL_type l_procModel = getChipModel( getMasterProc() );
    if ( MODEL_CUMULUS == l_procModel )
    {
        ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM_type attr;
        if ( !i_trgt->tryGetAttr<ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM>(attr) )
        {
            PRDF_ERR( PRDF_FUNC
                      "tryGetAttr<ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM> "
                      "failed: i_trgt=0x%08x", getHuid(i_trgt) );
            PRDF_ASSERT( false ); // attribute does not exist for target
        }

        num = attr[i_pos][i_ds];
    }
    else
    {
        ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_type attr;
        if ( !i_trgt->tryGetAttr<ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM>(attr) )
        {
            PRDF_ERR( PRDF_FUNC
                      "tryGetAttr<ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM> "
                      "failed: i_trgt=0x%08x", getHuid(i_trgt) );
            PRDF_ASSERT( false ); // attribute does not exist for target
        }

        num = attr[i_pos][i_ds];
    }

    PRDF_ASSERT( num < MASTER_RANKS_PER_DIMM_SLCT );

    return num;

    #undef PRDF_FUNC
}

template<>
uint8_t getNumMasterRanksPerDimm<TYPE_MCA>( TargetHandle_t i_trgt,
                                            uint8_t i_ds )
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_MCA == getTargetType(i_trgt) );

    // NOTE: The attribute lives on the MCS. So need to get the MCS target and
    //       the position of the MCA relative to the MCS.
    TargetHandle_t mcsTrgt = getConnectedParent( i_trgt, TYPE_MCS );
    uint8_t relPos = getTargetPosition(i_trgt) % MAX_MCA_PER_MCS;

    return __getNumMasterRanksPerDimm<TYPE_MCS>( mcsTrgt, relPos, i_ds );
}

template<>
uint8_t getNumMasterRanksPerDimm<TYPE_MBA>( TargetHandle_t i_trgt,
                                            uint8_t i_ds )
{
    // NOTE: DIMMs must be plugged into pairs. So the values for each port
    //       select will be the same for each DIMM select. There is no need to
    //       iterate on both port selects.
    return __getNumMasterRanksPerDimm<TYPE_MBA>( i_trgt, 0, i_ds );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint8_t __getNumRanksPerDimm( TargetHandle_t i_trgt,
                              uint8_t i_pos, uint8_t i_ds )
{
    #define PRDF_FUNC "[__getNumRanksPerDimm] "

    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( T == getTargetType(i_trgt) );
    PRDF_ASSERT( i_pos < 2 );
    PRDF_ASSERT( i_ds < MAX_DIMM_PER_PORT );
    uint8_t num;

    ATTR_MODEL_type l_procModel = getChipModel( getMasterProc() );
    if ( MODEL_CUMULUS == l_procModel )
    {
        ATTR_CEN_EFF_NUM_RANKS_PER_DIMM_type attr;
        if ( !i_trgt->tryGetAttr<ATTR_CEN_EFF_NUM_RANKS_PER_DIMM>(attr) )
        {
            PRDF_ERR( PRDF_FUNC
                      "tryGetAttr<ATTR_CEN_EFF_NUM_RANKS_PER_DIMM> "
                      "failed: i_trgt=0x%08x", getHuid(i_trgt) );
            PRDF_ASSERT( false ); // attribute does not exist for target
        }

        num = attr[i_pos][i_ds];
    }
    else
    {
        ATTR_EFF_NUM_RANKS_PER_DIMM_type attr;
        if ( !i_trgt->tryGetAttr<ATTR_EFF_NUM_RANKS_PER_DIMM>(attr) )
        {
            PRDF_ERR( PRDF_FUNC "tryGetAttr<ATTR_EFF_NUM_RANKS_PER_DIMM> "
                      "failed: i_trgt=0x%08x", getHuid(i_trgt) );
            PRDF_ASSERT( false ); // attribute does not exist for target
        }

        num = attr[i_pos][i_ds];
    }

    PRDF_ASSERT( num < MASTER_RANKS_PER_DIMM_SLCT*SLAVE_RANKS_PER_MASTER_RANK );

    return num;

    #undef PRDF_FUNC
}

template<>
uint8_t getNumRanksPerDimm<TYPE_MCA>( TargetHandle_t i_trgt, uint8_t i_ds )
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_MCA == getTargetType(i_trgt) );

    // NOTE: The attribute lives on the MCS. So need to get the MCS target and
    //       the position of the MCA relative to the MCS.
    TargetHandle_t mcsTrgt = getConnectedParent( i_trgt, TYPE_MCS );
    uint8_t relPos = getTargetPosition(i_trgt) % MAX_MCA_PER_MCS;

    return __getNumRanksPerDimm<TYPE_MCS>( mcsTrgt, relPos, i_ds );
}

template<>
uint8_t getNumRanksPerDimm<TYPE_MBA>( TargetHandle_t i_trgt, uint8_t i_ds )
{
    // NOTE: DIMMs must be plugged into pairs. So the values for each port
    //       select will be the same for each DIMM select. There is no need to
    //       iterate on both port selects.
    return __getNumRanksPerDimm<TYPE_MBA>( i_trgt, 0, i_ds );
}

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
        // If membuf target, use the connected proc target
        if(TYPE_MEMBUF == getTargetType(i_pGivenTarget))
        {
            l_target = getConnectedParent(i_pGivenTarget, TYPE_PROC);
        }

        PredicateIsFunctional l_funcFilter;
        PredicateCTM l_oscFilter(CLASS_CHIP, i_connType);
        PredicateCTM l_peerFilter(CLASS_UNIT, TYPE_MFREFCLKENDPT);
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
            PRDF_TRAC(PRDF_FUNC "OSC 0x%.8X, pos: %d is connected to "
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

bool isFabeRepairDisabled()
{ return isMnfgFlagSet( MNFG_FLAG_DISABLE_FABRIC_eREPAIR ); }

bool isMemeRepairDisabled()
{ return isMnfgFlagSet( MNFG_FLAG_DISABLE_MEMORY_eREPAIR ); }

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

bool isMfgAvpEnabled()
{ return isMnfgFlagSet( MNFG_FLAG_AVP_ENABLE ); }

bool isMfgHdatAvpEnabled()
{ return isMnfgFlagSet( MNFG_FLAG_HDAT_AVP_ENABLE ); }

} // end namespace PlatServices

} // end namespace PRDF

