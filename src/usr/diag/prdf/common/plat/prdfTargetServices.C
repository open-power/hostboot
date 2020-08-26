/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfTargetServices.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <targeting/common/mfgFlagAccessors.H>

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
    TargetHandle_t o_target = nullptr;

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

    if ( nullptr == o_target )
    {
        PRDF_ERR( "[getTarget] i_huid: 0x%08x failed", i_huid );
    }

    return o_target;
}

//------------------------------------------------------------------------------

TARGETING::TargetHandle_t getTarget( const TARGETING::EntityPath & i_path )
{
    TargetHandle_t o_target = targetService().toTarget( i_path );
    if ( nullptr == o_target )
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
        if ( nullptr == i_target ) break;

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
        if ( nullptr == i_target ) break; // return INVALID_HUID

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
        if ( nullptr == i_target )
        {
            PRDF_ERR( "[isFunctional] i_target is nullptr" );
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

    if ( nullptr != i_target )
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

    if ( nullptr != i_target )
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
    PRDF_ASSERT( nullptr != i_trgt );

    TargetHandle_t parent = getParentChip( i_trgt );
    PRDF_ASSERT( nullptr != parent );

    return parent->getAttr<ATTR_MODEL>();
}

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE
uint32_t getChipId( TARGETING::TargetHandle_t i_trgt )
{
    PRDF_ASSERT( nullptr != i_trgt );

    TargetHandle_t parent = getParentChip( i_trgt );
    PRDF_ASSERT( nullptr != parent );

    return parent->getAttr<ATTR_CHIP_ID>();
}
#endif

//------------------------------------------------------------------------------

uint8_t getChipLevel( TARGETING::TargetHandle_t i_trgt )
{
    PRDF_ASSERT( nullptr != i_trgt );

    TargetHandle_t parent = getParentChip( i_trgt );
    PRDF_ASSERT( nullptr != parent );

    return parent->getAttr<ATTR_EC>();
}

//##############################################################################
//##
//##                       getConnected() support functions
//##
//##############################################################################

// Helper function for the various getConnected() functions.
TargetHandleList getConnAssoc( TargetHandle_t i_target, TYPE i_connType,
                               TargetService::ASSOCIATION_TYPE i_assocType )
{
    PRDF_ASSERT( nullptr != i_target );

    TargetHandleList o_list; // Default empty list

    TYPE trgtType = getTargetType( i_target );

    // OMIC -> OMI and vice versa require special handling.
    if ( TYPE_OMIC == trgtType && TYPE_OMI == i_connType )
    {
        getChildOmiTargetsByState( o_list, i_target, CLASS_NA, TYPE_OMI,
                                   UTIL_FILTER_FUNCTIONAL );
    }
    else if ( TYPE_OMI == trgtType && TYPE_OMIC == i_connType )
    {
        getParentOmicTargetsByState( o_list, i_target, CLASS_NA, TYPE_OMIC,
                                     UTIL_FILTER_FUNCTIONAL );
    }
    else
    {
        // Match any class, specified type, and functional.
        PredicateCTM predType( CLASS_NA, i_connType );
        PredicateIsFunctional predFunc;
        PredicatePostfixExpr predAnd;
        predAnd.push(&predType).push(&predFunc).And();

        targetService().getAssociated( o_list, i_target, i_assocType,
                                       TargetService::ALL, &predAnd );
    }

    // Sort by target position.
    std::sort( o_list.begin(), o_list.end(),
               [](TargetHandle_t a, TargetHandle_t b)
               { return getTargetPosition(a) < getTargetPosition(b); } );

    return o_list;
}

//------------------------------------------------------------------------------

TargetHandleList getConnectedChildren(TargetHandle_t i_target, TYPE i_connType)
{
    PRDF_ASSERT( nullptr != i_target );

    TargetHandleList o_list = getConnAssoc( i_target, i_connType,
                                            TargetService::CHILD_BY_AFFINITY );

    return o_list;
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedParent( TargetHandle_t i_target, TYPE i_connType )
{
    #define PRDF_FUNC "[PlatServices::getConnectedParent] "

    PRDF_ASSERT( nullptr != i_target );

    // Get the connected parent, should be one and only one parent
    TargetHandleList list = getConnAssoc( i_target, i_connType,
                                          TargetService::PARENT_BY_AFFINITY );
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

TargetHandle_t getConnectedChild( TargetHandle_t i_parent, TYPE i_childType,
                                  uint32_t i_childPos )
{
    #define PRDF_FUNC "[PlatServices::getConnectedChild] "

    PRDF_ASSERT( nullptr != i_parent );

    TargetHandle_t o_child = nullptr;

    // Get the list.
    TargetHandleList list = getConnAssoc( i_parent, i_childType,
                                          TargetService::CHILD_BY_AFFINITY );
    if ( !list.empty() )
    {
        // There are some special cases where we need something other than to
        // match the unit position relative to the chip. So check those first.

        TYPE parentType  = getTargetType( i_parent );
        uint32_t parentPos = getTargetPosition( i_parent );

        // Many of our special cases can be handled in a similar way.
        // We can use this map to avoid copying code in those cases.
        std::map<std::pair<TYPE,TYPE>,uint8_t> connMap =
        {
            { {TYPE_EQ,   TYPE_CORE}, MAX_EC_PER_EQ    },
            { {TYPE_MC,   TYPE_MI  }, MAX_MI_PER_MC    },
            { {TYPE_MC,   TYPE_MCC }, MAX_MCC_PER_MC   },
            { {TYPE_MC,   TYPE_OMIC}, MAX_OMIC_PER_MC  },
            { {TYPE_MI,   TYPE_MCC }, MAX_MCC_PER_MI   },
            { {TYPE_MCC,  TYPE_OMI }, MAX_OMI_PER_MCC  },
            { {TYPE_OMIC, TYPE_OMI }, MAX_OMI_PER_OMIC },
            { {TYPE_PEC,  TYPE_PHB }, MAX_PHB_PER_PEC  },
        };

        // Connection found in connMap
        auto mapIter = connMap.find({parentType, i_childType});
        if ( connMap.end() != mapIter )
        {
            uint8_t max = mapIter->second;
            for ( const auto & child : list )
            {
                // Look for the child target who's target position matches
                // both with the parent's target position and i_childPos
                uint32_t pos = getTargetPosition(child);
                if ( (parentPos  == (pos / max)) &&
                     (i_childPos == (pos % max)) )
                {
                    o_child = child;
                    break;
                }
            }
        }
        // Other special cases
        else if ( TYPE_MEM_PORT == parentType && TYPE_DIMM == i_childType )
        {
            // i_connPos is the DIMM select (0-1). Note that we don't use
            // getTargetPosition() on the DIMM because that does not return a
            // value that is relative to the processor as we were expecting.
            // There really isn't a good position attribute that matches the
            // position in the affinity path. We can use ATTR_REL_POS, which
            // will always match the DIMM select. This does not let us match the
            // parent unit like all of the other checks in this function.
            // Fortunately, it will be very difficult to have a bug where the
            // getConnected code returns DIMMs on a different MEM_PORT
            // target. So this is an acceptable risk.
            for ( const auto & child : list )
            {
                if ( i_childPos == child->getAttr<ATTR_REL_POS>() )
                {
                    o_child = child;
                    break;
                }
            }
        }
        else if ( (TYPE_OMI == parentType && TYPE_OCMB_CHIP == i_childType) ||
                  (TYPE_OCMB_CHIP == parentType && TYPE_MEM_PORT == i_childType)
                )
        {
            // There should only be one in the list.
            PRDF_ASSERT( 1 == list.size() );
            o_child = list[0];
        }
        else if ( TYPE_MCC == parentType && TYPE_OCMB_CHIP == i_childType )
        {
            // getTargetPosition for OCMBs will return the position relative to
            // the node. This won't work for how we typically handle getting
            // the child target, so we instead just get the child OMI and then
            // get the OCMB from the OMI. This will work because the OMI and
            // OCMB have a 1-to-1 relationship (see above where we return the
            // only one in the list for OMI to OCMB connections).
            TargetHandle_t omi = getConnectedChild( i_parent, TYPE_OMI,
                                                    i_childPos );
            if ( nullptr != omi )
            {
                o_child = getConnectedChild( omi, TYPE_OCMB_CHIP, 0 );
            }
        }
        // Default case, i_connPos should match the unit pos within the chip
        else
        {
            for ( const auto & child : list )
            {
                if ( i_childPos == getTargetPosition(child) )
                {
                    o_child = child;
                    break;
                }
            }

        }

    }

    return o_child;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

ExtensibleChipList getConnectedChildren( ExtensibleChip * i_chip,
                                         TYPE i_connType )
{
    PRDF_ASSERT( nullptr != i_chip );

    ExtensibleChipList o_list; // Default empty list

    TargetHandleList list = getConnectedChildren(i_chip->getTrgt(), i_connType);
    for ( auto & trgt : list )
    {
        // Check to make sure that if we have a non-null Target, we also
        // get back a non-null ExtensibleChip.
        ExtensibleChip * chip = (ExtensibleChip *)systemPtr->GetChip(trgt);
        PRDF_ASSERT( nullptr != chip );

        o_list.push_back( chip );
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

    // Check to make sure that if we have a non-null Target, we also
    // get back a non-null ExtensibleChip.
    ExtensibleChip * chip = (ExtensibleChip *)systemPtr->GetChip( trgt );
    PRDF_ASSERT( nullptr != chip );

    return chip;
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

        // Check to make sure that if we have a non-null Target, we also
        // get back a non-null ExtensibleChip.
        PRDF_ASSERT( nullptr != o_child );
    }

    return o_child;
}

//------------------------------------------------------------------------------

ExtensibleChip * getNeighborCore( ExtensibleChip * i_core )
{
    PRDF_ASSERT( nullptr != i_core );

    TargetHandle_t thisCore = i_core->getTrgt();
    TargetHandle_t parentEx = getConnectedParent( thisCore, TYPE_EX );

    ExtensibleChip * neighborCore = nullptr;

    TargetHandleList coreList = getConnectedChildren( parentEx, TYPE_CORE );

    for ( auto & trgt : coreList )
    {
        if ( trgt != thisCore )
        {
            neighborCore = (ExtensibleChip *)systemPtr->GetChip(trgt);
            break;
        }
    }
    return neighborCore;
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedPeerTarget(TargetHandle_t i_target)
{
    PRDF_ASSERT(nullptr != i_target);
    PRDF_ASSERT(TYPE_IOHS == getTargetType(i_target));

    return i_target->getAttr<ATTR_PEER_TARGET>();
}

//------------------------------------------------------------------------------

TargetHandle_t getConnectedPeerProc(TargetHandle_t i_procTarget,
                                    TYPE i_busType, uint32_t i_busPos)
{
    PRDF_ASSERT(nullptr != i_procTarget);
    PRDF_ASSERT(TYPE_PROC == getTargetType(i_procTarget));
    PRDF_ASSERT((TYPE_IOHS == i_busType) && (MAX_IOHS_PER_PROC > i_busPos));

    TargetHandle_t o_target = nullptr;

    do
    {
        // Starting PROC -> starting IOHS.
        TargetHandle_t busTarget = getConnectedChild(i_procTarget, i_busType,
                                                     i_busPos);
        if (nullptr == busTarget) break;

        // Starting IOHS -> ATTR_PEER_TARGET -> destination IOHS.
        TargetHandle_t destTarget = getConnectedPeerTarget(busTarget);
        if (nullptr == destTarget) break;

        // Destination IOHS -> destination PROC.
        o_target = getConnectedParent(destTarget, TYPE_PROC);

    } while(0);

    return o_target;
}

//------------------------------------------------------------------------------

uint8_t getDimmPort( TARGETING::TargetHandle_t i_dimmTrgt )
{
    PRDF_ASSERT( nullptr != i_dimmTrgt );
    PRDF_ASSERT( TYPE_DIMM == getTargetType(i_dimmTrgt) );

    return i_dimmTrgt->getAttr<ATTR_MEM_PORT>();
}

//------------------------------------------------------------------------------

uint8_t getDimmSlct( TargetHandle_t i_trgt )
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_DIMM == getTargetType(i_trgt) );

    return i_trgt->getAttr<ATTR_POS_ON_MEM_PORT>();
}

//------------------------------------------------------------------------------

TARGETING::TargetHandleList getConnectedDimms( TARGETING::TargetHandle_t i_trgt,
                                               const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::getConnectedDimms] "

    TargetHandleList o_list;

    TargetHandleList l_dimmList = getConnectedChildren( i_trgt, TYPE_DIMM );
    for ( auto & dimm : l_dimmList )
    {
        uint8_t l_dimmSlct = getDimmSlct( dimm );
        if ( l_dimmSlct == i_rank.getDimmSlct() )
        {
            o_list.push_back( dimm );
        }
    }

    return o_list;

    #undef PRDF_FUNC
}

TARGETING::TargetHandle_t getConnectedDimm( TARGETING::TargetHandle_t i_trgt,
                                            const MemRank & i_rank,
                                            uint8_t i_port )
{
    #define PRDF_FUNC "[PlatServices::getConnectedDimm] "

    TargetHandle_t o_dimm = nullptr;

    TargetHandleList l_dimmList = getConnectedDimms( i_trgt, i_rank );
    for ( auto & dimm : l_dimmList )
    {
        uint8_t l_portSlct = getDimmPort( dimm );
        if ( l_portSlct == i_port )
        {
            o_dimm = dimm;
            break;
        }
    }

    return o_dimm;

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
    TargetHandle_t o_chipTarget = nullptr;

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

    if ( nullptr == o_chipTarget )
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

bool checkLastFuncCore( TARGETING::TargetHandle_t i_trgt )
{
    bool o_lastCore = false;

    // Default for non-fused cores.
    TARGETING::TYPE type = TYPE_CORE;
    TargetHandle_t  trgt = i_trgt;

    // Check for fused-core mode.
    if ( is_fused_mode() )
    {
        type = TYPE_EX;
        trgt = getConnectedParent( trgt, type );
    }

    TargetHandleList l_list = getFunctionalTargetList( type );
    if ( 1 == l_list.size() && l_list[0] == trgt )
        o_lastCore = true;

    return o_lastCore;
}

//------------------------------------------------------------------------------

TargetHandle_t getMasterProc()
{
    TargetHandle_t masterProc = nullptr;
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
                case TYPE_MFREFCLK:
                case TYPE_OCMB_CHIP:
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

bool isDramWidthX4( TargetHandle_t i_trgt )
{
   bool o_dramWidthX4 = false;

   PRDF_ASSERT( nullptr != i_trgt );
   uint8_t dramWidths[MAX_DIMM_PER_PORT];
   uint8_t dimmSlct = 0;
   TargetHandle_t memPort = nullptr;

   switch ( getTargetType(i_trgt) )
   {
        case TYPE_DIMM:
            memPort = getConnectedParent(i_trgt, TYPE_MEM_PORT);
            if ( !memPort->tryGetAttr<ATTR_MEM_EFF_DRAM_WIDTH>(dramWidths) )
            {
                PRDF_ERR( "isDramWidthX4: Unable to access "
                          "ATTR_MEM_EFF_DRAM_WIDTH i_trgt=0x%08x.",
                          getHuid(memPort) );
                PRDF_ASSERT( false );
            }
            dimmSlct = getDimmSlct( i_trgt );
            o_dramWidthX4 =
                (TARGETING::MEM_EFF_DRAM_WIDTH_X4 == dramWidths[dimmSlct]);
            break;

        default:
          PRDF_ASSERT(false); // code bug
   }

   return o_dramWidthX4;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __getMasterRanks( TargetHandle_t i_trgt, std::vector<MemRank> & o_ranks,
                       uint8_t i_ds )
{
    #define PRDF_FUNC "[__getMasterRanks] "

    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( T == getTargetType(i_trgt) );
    PRDF_ASSERT( i_ds <= MAX_DIMM_PER_PORT ); // can equal MAX_DIMM_PER_PORT

    o_ranks.clear();

    uint8_t info[2];

    if ( !i_trgt->tryGetAttr<ATTR_MEM_EFF_DIMM_RANKS_CONFIGED>(info) )
    {
        PRDF_ERR( PRDF_FUNC "tryGetAttr<ATTR_MEM_EFF_DIMM_RANKS_CONFIGED> "
                "failed: i_trgt=0x%08x", getHuid(i_trgt) );
        PRDF_ASSERT( false ); // attribute does not exist for target
    }

    for ( uint32_t ds = 0; ds < MAX_DIMM_PER_PORT; ds++ )
    {
        // Check if user gave a specific value for i_ds.
        if ( (MAX_DIMM_PER_PORT != i_ds) && (ds != i_ds) )
            continue;

        uint8_t rankMask = info[ds];

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
void getMasterRanks<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt,
                                     std::vector<MemRank> & o_ranks,
                                     uint8_t i_ds )
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_trgt) );

    // TODO RTC 210072 - Explorer only has one port, however, multiple ports
    // will be supported in the future. Updates will need to be made here so we
    // can get the relevant port.
    TargetHandle_t memPort = getConnectedChild( i_trgt, TYPE_MEM_PORT, 0 );
    __getMasterRanks<TYPE_MEM_PORT>( memPort, o_ranks, i_ds );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void getSlaveRanks( TargetHandle_t i_trgt, std::vector<MemRank> & o_ranks,
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

template
void getSlaveRanks<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt,
                                    std::vector<MemRank> & o_ranks,
                                    uint8_t i_ds );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint8_t __getNumMasterRanksPerDimm( TargetHandle_t i_trgt, uint8_t i_ds )
{
    #define PRDF_FUNC "[__getNumMasterRanksPerDimm] "

    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( T == getTargetType(i_trgt) );
    PRDF_ASSERT( i_ds < MAX_DIMM_PER_PORT );
    uint8_t num = 0;

    ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_type attr;
    if ( !i_trgt->tryGetAttr<ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM>(attr) )
    {
        PRDF_ERR( PRDF_FUNC "tryGetAttr<ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM>"
                  " failed: i_trgt=0x%08x", getHuid(i_trgt) );
        PRDF_ASSERT( false ); // attribute does not exist for target
    }

    num = attr[i_ds];

    PRDF_ASSERT( num <= MASTER_RANKS_PER_DIMM_SLCT );

    return num;

    #undef PRDF_FUNC
}

template<>
uint8_t getNumMasterRanksPerDimm<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt,
                                                  uint8_t i_ds )
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_trgt) );

    // TODO RTC 210072 - Explorer only has one port, however, multiple ports
    // will be supported in the future. Updates will need to be made here so we
    // can get the relevant port.
    TargetHandle_t memPort = getConnectedChild( i_trgt, TYPE_MEM_PORT, 0 );
    return __getNumMasterRanksPerDimm<TYPE_MEM_PORT>( memPort, i_ds );
}
//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint8_t __getNumRanksPerDimm( TargetHandle_t i_trgt, uint8_t i_ds )
{
    #define PRDF_FUNC "[__getNumRanksPerDimm] "

    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( T == getTargetType(i_trgt) );
    PRDF_ASSERT( i_ds < MAX_DIMM_PER_PORT );
    uint8_t num = 0;

    ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM_type attr;
    if ( !i_trgt->tryGetAttr<ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM>(attr) )
    {
        PRDF_ERR( PRDF_FUNC "tryGetAttr<ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM> "
                "failed: i_trgt=0x%08x", getHuid(i_trgt) );
        PRDF_ASSERT( false ); // attribute does not exist for target
    }

    num = attr[i_ds];

    PRDF_ASSERT( num < MASTER_RANKS_PER_DIMM_SLCT*SLAVE_RANKS_PER_MASTER_RANK );

    return num;

    #undef PRDF_FUNC
}

template<>
uint8_t getNumRanksPerDimm<TYPE_OCMB_CHIP>(TargetHandle_t i_trgt, uint8_t i_ds)
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_trgt) );

    // TODO RTC 210072 - Explorer only has one port, however, multiple ports
    // will be supported in the future. Updates will need to be made here so we
    // can get the relevant port.
    TargetHandle_t memPort = getConnectedChild( i_trgt, TYPE_MEM_PORT, 0 );
    return __getNumRanksPerDimm<TYPE_MEM_PORT>( memPort, i_ds );
}

//##############################################################################
//##
//##                        Clock specific functions
//##
//##############################################################################

TargetHandle_t getClockId(TargetHandle_t i_trgt, TARGETING::TYPE i_connType,
                            uint32_t i_oscPos)
{
    #define PRDF_FUNC "[PlatServices::getClockId] "

    // Check parameters.
    PRDF_ASSERT(nullptr != i_trgt);
    PRDF_ASSERT(i_oscPos < 2);

    // If memory buffer is given, use the connected processor target.
    if (TYPE_MEMBUF == getTargetType(i_trgt))
    {
        i_trgt = getConnectedParent(i_trgt, TYPE_PROC);
    }

    // Get the peer and oscillator types.
    TARGETING::TYPE peerType = TYPE_NA, oscType = TYPE_NA;
    switch (i_connType)
    {
        case TYPE_OSCREFCLK:
            peerType = TYPE_SYSREFCLKENDPT;
            oscType  = TYPE_OSCREFCLK;
            break;

        // TODO: The use of TYPE_OSCPCICLK appears to be carry-over from P8 and
        //       probably should be replaced when there is time to investigate.
        case TYPE_OSCPCICLK:
            peerType = TYPE_MFREFCLKENDPT;
            oscType  = (MODEL_NIMBUS == getChipModel(getMasterProc()))
                            ? TYPE_OSCREFCLK : TYPE_MFREFCLK;
            break;

        default:
            PRDF_ERR(PRDF_FUNC "Unsupported connection type: 0x%x", i_connType);
            PRDF_ASSERT(false);
    }

    // Functional filter
    PredicateIsFunctional funcFilter;

    // Peer filter
    PredicateCTM peerFilter(CLASS_UNIT, peerType);
    PredicatePostfixExpr funcAndPeerFilter;
    funcAndPeerFilter.push(&peerFilter).push(&funcFilter).And();

    // Result filter
    PredicateCTM resultFilter(CLASS_CHIP, oscType);
    PredicatePostfixExpr funcAndResultFilter;
    funcAndResultFilter.push(&resultFilter).push(&funcFilter).And();

    // PROC <---> CLKTYPE <---> PEER <---> CLKTYPE <---> OSC
    // Get the list of oscillators related to this processor via the peer clock
    // endpoint.
    TargetHandleList list;
    getPeerTargets(list, i_trgt, &funcAndPeerFilter, &funcAndResultFilter);

    // Return the clock card for this position, if it exists.
    auto itr = std::find_if(list.begin(), list.end(),
                            [&](const TargetHandle_t & t)
                            { return getTargetPosition(t) == i_oscPos; });

    return (list.end() != itr) ? *itr : nullptr;

    #undef PRDF_FUNC
}

//##############################################################################
//##                     MNFG Policy Flag Functions
//##############################################################################
bool mfgMode()
{ return TARGETING::areMfgThresholdsActive(); }

bool mnfgTerminate()
{ return TARGETING::areAllSrcsTerminating(); }

bool areDramRepairsDisabled()
{ return TARGETING::isDramRepairsDisabled(); }

bool enableFastBgScrub()
{ return TARGETING::isEnableFastBackgroundScrub(); }

bool mnfgSpareDramDeploy()
{ return TARGETING::isMfgSpareDramDeploy(); }

bool isMfgCeCheckingEnabled()
{ return TARGETING::isMfgCeCheckingEnabled(); }

bool isMfgAvpEnabled()
{ return TARGETING::isMfgAvpEnabled(); }

bool isMfgHdatAvpEnabled()
{ return TARGETING::isMfgHdatAvpEnabled(); }

} // end namespace PlatServices

} // end namespace PRDF

