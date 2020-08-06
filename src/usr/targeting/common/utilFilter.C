/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/utilFilter.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
//******************************************************************************
// Includes
//******************************************************************************
#include <targeting/common/commontargeting.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/trace.H>
#include <attributeenums.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicateisfunctional.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/common/predicates/predicateattrval.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/predicates/predicateisnonfunctional.H>
#include <algorithm>

/**
 * Miscellaneous Filter Utility Functions
 */

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"

#define TARG_CLASS ""

/**
 * @brief Populate the o_vector with target object pointers based on the
 *        requested class, type, and functional state.
 *
 * @parm[out] o_vector, reference of vector of target pointers.
 * @parm[in]  i_class,  the class of the targets to be obtained
 * @parm[in]  i_type,   the type of the targets to be obtained
 * @parm[in]  i_state,  Selection filter based on ResourceState enum,
 *                      designates all, present, or functional
 *
 * @return N/A
 */
void getClassResources( TARGETING::TargetHandleList & o_vector,
                     CLASS i_class, TYPE  i_type, ResourceState i_state )
{
    #define TARG_FN "getClassResources(...)"

    switch(i_state)
    {
        case UTIL_FILTER_ALL:
        {
            // Type predicate
            TARGETING::PredicateCTM l_CtmFilter(i_class, i_type);
            // Apply the filter through all targets
            TARGETING::TargetRangeFilter l_targetList(
                                    TARGETING::targetService().begin(),
                                    TARGETING::targetService().end(),
                                    &l_CtmFilter);
            o_vector.clear();
            for ( ; l_targetList; ++l_targetList)
            {
                o_vector.push_back(*l_targetList);
            }
            break;
        }
        case UTIL_FILTER_PRESENT:
        {
            // Get all present chips or chiplets
            // Present predicate
            PredicateHwas l_predPres;
            l_predPres.present(true);
            // Type predicate
            TARGETING::PredicateCTM l_CtmFilter(i_class, i_type);
            // Set up compound predicate
            TARGETING::PredicatePostfixExpr l_present;
            l_present.push(&l_CtmFilter).push(&l_predPres).And();
            // Apply the filter through all targets
            TARGETING::TargetRangeFilter l_presTargetList(
                                    TARGETING::targetService().begin(),
                                    TARGETING::targetService().end(),
                                    &l_present);
            o_vector.clear();
            for ( ; l_presTargetList; ++l_presTargetList)
            {
                o_vector.push_back(*l_presTargetList);
            }
            break;
        }
        case UTIL_FILTER_FUNCTIONAL:
        {
            // Get all functional chips or chiplets
            // Functional predicate
            TARGETING::PredicateIsFunctional l_isFunctional;
            // Type predicate
            TARGETING::PredicateCTM l_CtmFilter(i_class, i_type);
            // Set up compound predicate
            TARGETING::PredicatePostfixExpr l_functional;
            l_functional.push(&l_CtmFilter).push(&l_isFunctional).And();
            // Apply the filter through all targets
            TARGETING::TargetRangeFilter l_funcTargetList(
                                    TARGETING::targetService().begin(),
                                    TARGETING::targetService().end(),
                                    &l_functional);
            o_vector.clear();
            for ( ; l_funcTargetList; ++l_funcTargetList)
            {
                o_vector.push_back(*l_funcTargetList);
            }
            break;
        }
        case UTIL_FILTER_NON_FUNCTIONAL:
        {
            // Get all non-functional chips or chiplets
            // Non-functional predicate
            TARGETING::PredicateIsNonFunctional l_isNonFunctional(false);
            // Type predicate
            TARGETING::PredicateCTM l_CtmFilter(i_class, i_type);
            // Set up compound predicate
            TARGETING::PredicatePostfixExpr l_nonFunctional;
            l_nonFunctional.push(&l_CtmFilter).push(&l_isNonFunctional).And();
            // Apply the filter through all targets
            TARGETING::TargetRangeFilter l_nonFuncTargetList(
                                    TARGETING::targetService().begin(),
                                    TARGETING::targetService().end(),
                                    &l_nonFunctional);
            o_vector.clear();
            for ( ; l_nonFuncTargetList; ++l_nonFuncTargetList)
            {
                o_vector.push_back(*l_nonFuncTargetList);
            }
            break;
        }
        case UTIL_FILTER_PRESENT_NON_FUNCTIONAL:
        {
            // Get all present and non-functional chips or chiplets
            // Present and non-functional predicate
            TARGETING::PredicateIsNonFunctional l_isPresNonFunctional;
            // Type predicate
            TARGETING::PredicateCTM l_CtmFilter(i_class, i_type);
            // Set up compound predicate
            TARGETING::PredicatePostfixExpr l_presNonFunctional;
            l_presNonFunctional.push(&l_CtmFilter).
                push(&l_isPresNonFunctional).And();
            // Apply the filter through all targets
            TARGETING::TargetRangeFilter l_presNonFuncTargetList(
                                    TARGETING::targetService().begin(),
                                    TARGETING::targetService().end(),
                                    &l_presNonFunctional);
            o_vector.clear();
            for ( ; l_presNonFuncTargetList; ++l_presNonFuncTargetList)
            {
                o_vector.push_back(*l_presNonFuncTargetList);
            }
            break;
        }
        default:
            TARG_ASSERT(0, TARG_LOC "Invalid functional state used");
            break;
    }

    // If target vector contains more than one element, sorty by HUID
    if (o_vector.size() > 1)
    {
        std::sort(o_vector.begin(),o_vector.end(),compareTargetHuid);
    }

    #undef TARG_FN
}

void getChipResources( TARGETING::TargetHandleList & o_vector,
                       TYPE i_chipType, ResourceState i_state )
{
    getClassResources(o_vector, CLASS_CHIP, i_chipType, i_state);
}

void getEncResources( TARGETING::TargetHandleList & o_vector,
                      TYPE i_type, ResourceState i_state )
{
    getClassResources(o_vector, CLASS_ENC, i_type, i_state);
}

void getChipletResources( TARGETING::TargetHandleList & o_vector,
                          TYPE i_chipletType, ResourceState i_state )
{
    getClassResources(o_vector, CLASS_UNIT, i_chipletType, i_state);
}

// Retrofit functions to getChipOrChipletResources
void getAllChips( TARGETING::TargetHandleList & o_vector,
                  TYPE i_chipType, bool i_functional )
{
    if (i_functional)
    {
        getClassResources(o_vector, CLASS_CHIP, i_chipType,
                           UTIL_FILTER_FUNCTIONAL);
    }
    else
    {
        getClassResources(o_vector, CLASS_CHIP, i_chipType, UTIL_FILTER_ALL);
    }
}

void getAllAsics(
    TARGETING::TargetHandleList& o_asics,
    const TYPE i_asicType,
    const bool i_functional)
{
    if (i_functional)
    {
        getClassResources(o_asics, CLASS_ASIC, i_asicType,
                           UTIL_FILTER_FUNCTIONAL);
    }
    else
    {
        getClassResources(o_asics, CLASS_ASIC, i_asicType, UTIL_FILTER_ALL);
    }
}

void getAllLogicalCards( TARGETING::TargetHandleList & o_vector,
                         TYPE i_cardType,
                         bool i_functional )
{
    if (i_functional)
    {
        getClassResources( o_vector,
                                CLASS_LOGICAL_CARD,
                                i_cardType,
                                UTIL_FILTER_FUNCTIONAL );
    }
    else
    {
        getClassResources( o_vector,
                                CLASS_LOGICAL_CARD,
                                i_cardType,
                                UTIL_FILTER_ALL );
    }
}


void getAllCards( TARGETING::TargetHandleList & o_vector,
                  TYPE i_cardType,
                  bool i_functional )
{
    if (i_functional)
    {
        getClassResources( o_vector,
                                CLASS_CARD,
                                i_cardType,
                                UTIL_FILTER_FUNCTIONAL );
    }
    else
    {
        getClassResources( o_vector,
                                CLASS_CARD,
                                i_cardType,
                                UTIL_FILTER_ALL );
    }
}


void getAllChiplets( TARGETING::TargetHandleList & o_vector,
                     TYPE i_chipletType, bool i_functional )
{
    if (i_functional)
    {
        getClassResources(o_vector, CLASS_UNIT, i_chipletType,
                           UTIL_FILTER_FUNCTIONAL);
    }
    else
    {
        getClassResources(o_vector, CLASS_UNIT, i_chipletType,
                           UTIL_FILTER_ALL);
    }
}


void getChildChiplets( TARGETING::TargetHandleList& o_vector,
                 const Target * i_chip, TYPE i_type, bool i_functional )
{
    //  get the chiplets associated with this cpu
    TARGETING::PredicateCTM l_chipletFilter(CLASS_UNIT, i_type);

    o_vector.clear();
    if (i_functional)
    {
        //  Use PredicateIsFunctional to filter only functional chiplets
        TARGETING::PredicateIsFunctional l_functional;
        TARGETING::PredicatePostfixExpr l_functionalChiplets;
        l_functionalChiplets.push(&l_chipletFilter).push(&l_functional).And();
        TARGETING::targetService().getAssociated(
                o_vector,
                i_chip,
                TARGETING::TargetService::CHILD,
                TARGETING::TargetService::ALL,
                &l_functionalChiplets );
    }
    else
    {
        TARGETING::targetService().getAssociated(
                o_vector,
                i_chip,
                TARGETING::TargetService::CHILD,
                TARGETING::TargetService::ALL,
                &l_chipletFilter );
    }
}

void getAffinityTargets (TargetHandleList& o_vector, const Target * i_target,
                         CLASS i_class, TYPE i_type,
                         ResourceState i_state,
                         TargetService::ASSOCIATION_TYPE i_association)
{
    #define TARG_FN "getAffinityTargets(...)"

    //  find all the targets that are affinity-associated with i_target
    TARGETING::PredicateCTM l_targetFilter(i_class, i_type);

    o_vector.clear();
    switch(i_state)
    {
        case UTIL_FILTER_ALL:
        {
            TARGETING::targetService().getAssociated(
                o_vector,
                i_target,
                i_association,
                TARGETING::TargetService::ALL,
                &l_targetFilter );

            break;
        }
        case UTIL_FILTER_PRESENT:
        {
            // Get all present chips or chiplets
            // Present predicate
            PredicateHwas l_predPres;
            l_predPres.present(true);
            // Type predicate
            // Set up compound predicate
            TARGETING::PredicatePostfixExpr l_presentTargets;
            l_presentTargets.push(&l_targetFilter).push(&l_predPres).And();
            // Apply the filter through all targets
            TARGETING::targetService().getAssociated(
                o_vector,
                i_target,
                i_association,
                TARGETING::TargetService::ALL,
                &l_presentTargets );

            break;
        }
        case UTIL_FILTER_FUNCTIONAL:
        {
            //  Use PredicateIsFunctional to filter only functional chips
            TARGETING::PredicateIsFunctional l_functional;
            TARGETING::PredicatePostfixExpr l_functionalTargets;
            l_functionalTargets.push(&l_targetFilter).push(&l_functional).And();
            TARGETING::targetService().getAssociated(
                    o_vector,
                    i_target,
                    i_association,
                    TARGETING::TargetService::ALL,
                    &l_functionalTargets );
            break;
        }
        default:
            TARG_ASSERT(0, TARG_LOC "Invalid functional state used");
            break;
    }
    #undef TARG_FN
}

void getChildAffinityTargetsByState(
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state )

{

    getAffinityTargets(o_vector, i_target, i_class, i_type, i_state,
                       TargetService::CHILD_BY_AFFINITY);
}

void getPervasiveChildTargetsByState(
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state )

{
    getAffinityTargets(o_vector, i_target, i_class, i_type, i_state,
                       TargetService::PERVASIVE_CHILD);
}

void getChildOmiTargetsByState(
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state )

{
    getAffinityTargets(o_vector, i_target, i_class, i_type, i_state,
                       TargetService::OMI_CHILD);
}

void getParentAffinityTargetsByState(
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state )
{

    getAffinityTargets(o_vector, i_target, i_class, i_type, i_state,
                       TargetService::PARENT_BY_AFFINITY);
}

void getParentPervasiveTargetsByState(
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state )
{
    getAffinityTargets(o_vector, i_target, i_class, i_type, i_state,
                       TargetService::PARENT_PERVASIVE);
}

void getParentOmicTargetsByState(
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target,
          CLASS                        i_class,
          TYPE                         i_type,
          ResourceState                i_state )
{
    getAffinityTargets(o_vector, i_target, i_class, i_type, i_state,
                       TargetService::OMIC_PARENT);
}

const Target * getParentChip( const Target * i_pChiplet )
{

    const Target * l_pChip = NULL;

    // Create a Class/Type/Model predicate to look for chips
    TARGETING::PredicateCTM l_predicate(TARGETING::CLASS_CHIP);

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_chipList;

    // Get parent
    TARGETING::targetService().getAssociated(l_chipList, i_pChiplet,
                          TARGETING::TargetService::PARENT,
                          TARGETING::TargetService::ALL, &l_predicate);

    if (l_chipList.size() == 1)
    {
        l_pChip = l_chipList[0];
    }
    else if (l_chipList.size() == 0)
    {
        TARG_ERR("Failed to find a parent chip target for huid=%.8X", TARGETING::get_huid(i_pChiplet));
    }
    else
    {
        TARG_ERR("Found %d parent chip targets for huid=%.8X, expected to only find 1",l_chipList.size(), TARGETING::get_huid(i_pChiplet));
    }

    return l_pChip;
}

Target * getImmediateParentByAffinity(const Target * i_child )
{
    Target * l_parent = NULL;

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_chipList;

    // Get parent
    TARGETING::targetService().getAssociated(l_chipList, i_child,
                    TARGETING::TargetService::PARENT_BY_AFFINITY,
                    TARGETING::TargetService::IMMEDIATE, NULL);

    if (l_chipList.size() == 1)
    {
        l_parent = l_chipList[0];
    }
    else if (l_chipList.size() == 0)
    {
        TARG_ERR("Failed to find a parent target for huid=%.8X",
                TARGETING::get_huid(i_child));
    }
    else
    {
        TARG_ERR("Found %d parent targets for huid=%.8X, only expected to find 1",
                l_chipList.size(),
                TARGETING::get_huid(i_child));
    }

    return l_parent;
}


Target * getParent( const Target * i_unit , TARGETING::TYPE &i_pType)
{
    Target * l_parent = NULL;
    TARGETING::PredicateCTM l_predicate;

    l_predicate.setType(i_pType);

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_chipList;

    // Get parent
    TARGETING::targetService().getAssociated(l_chipList, i_unit,
                          TARGETING::TargetService::PARENT,
                          TARGETING::TargetService::ALL, &l_predicate);

    if (l_chipList.size() == 1)
    {
        l_parent = l_chipList[0];
    }
    else if (l_chipList.size() == 0)
    {
        TARG_ERR("Failed to find a parent target for huid=%.8X", TARGETING::get_huid(i_unit));
    }
    else
    {
        TARG_ERR("Found %d parent targets for huid=%.8X, only expected to find 1",
                 l_chipList.size(),
                 TARGETING::get_huid(i_unit));
    }

    return l_parent;
}


const Target * getExChiplet( const Target * i_pCoreChiplet )
{
    const Target * l_pExChiplet = NULL;

    // Create a Class/Type/Model predicate to look for EX chiplet of the input
    // core (i.e. the core's parent)
    TARGETING::PredicateCTM l_predicate(TARGETING::CLASS_UNIT,
            TARGETING::TYPE_EX);

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_exList;

    // Get parent
    TARGETING::targetService().getAssociated(l_exList, i_pCoreChiplet,
                          TARGETING::TargetService::PARENT,
                          TARGETING::TargetService::ALL, &l_predicate);

    if (l_exList.size() == 1)
    {
        l_pExChiplet = l_exList[0];
    }
    else
    {
        TARG_ERR("Number of EX chiplet is not 1, but %d", l_exList.size());
    }

    return l_pExChiplet;
}

const Target * getCoreChiplet( const Target * i_pExChiplet )
{
    const Target * l_pCoreChiplet = NULL;

    // Create a Class/Type/Model predicate to look for Core chiplet of the input
    // ex (i.e. the ex's child)
    TARGETING::PredicateCTM l_predicate(TARGETING::CLASS_UNIT);

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_coreList;

    // The core is an immediate child of the ex
    TARGETING::targetService().getAssociated(l_coreList, i_pExChiplet,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::IMMEDIATE, &l_predicate);

    if (l_coreList.size() == 1)
    {
        l_pCoreChiplet = l_coreList[0];
    }
    else
    {
        TARG_ERR("Number of Core chiplets is not 1, but %d", l_coreList.size());
    }

    return l_pCoreChiplet;
}



void getPeerTargets(
          TARGETING::TargetHandleList& o_peerTargetList,
    const Target*                      i_pSrcTarget,
    const PredicateBase*               i_pPeerFilter,
    const PredicateBase*               i_pResultFilter)
{
    #define TARG_FN "getPeerTargets"
    TARG_ENTER();
    Target* l_pPeerTarget = NULL;

    TARG_ASSERT(NULL != i_pSrcTarget,
                "User tried to call getPeerTargets using NULL Target Handle");

    // Clear the list
    o_peerTargetList.clear();
    do
    {
        // List to maintain all child targets which are found by get associated
        // from the Src target with i_pPeerFilter predicate
        TARGETING::TargetHandleList l_pSrcTarget_list;

        // Create input master predicate here by taking in the i_pPeerFilter
        TARGETING::PredicatePostfixExpr l_superPredicate;
        TARGETING::PredicateAttrVal<TARGETING::ATTR_PEER_TARGET>
            l_notNullPeerExist(NULL, true);
        l_superPredicate.push(&l_notNullPeerExist);
        if(i_pPeerFilter)
        {
            l_superPredicate.push(i_pPeerFilter).And();
        }

        // Check if the i_srcTarget is the leaf node
        if(i_pSrcTarget->tryGetAttr<TARGETING::ATTR_PEER_TARGET>(l_pPeerTarget))
        {
            if(l_superPredicate(i_pSrcTarget))
            {
                // Exactly one Peer Target to Cross
                // Put this to input target list
                l_pSrcTarget_list.push_back(
                        const_cast<TARGETING::Target*>(i_pSrcTarget));
            }
            else
            {
                TARG_INF("Input Target provided doesn't have a valid Peer "
                    "Target Attribute, Returning Empty List");
                break;
            }
        }
        // Not a leaf node, find out all leaf node with valid PEER Target
        else
        {
            (void) TARGETING::targetService().getAssociated(
                    l_pSrcTarget_list,
                    i_pSrcTarget,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &l_superPredicate);
        }

        // Now we have a list of input targets on which we have to find the peer
        // Check if we have a result predicate filter to apply
        if(i_pResultFilter == NULL)
        {
            // Simply get the Peer Target for all Src target in the list and
            // return
            for(TARGETING::TargetHandleList::const_iterator pTargetIt
                    = l_pSrcTarget_list.begin();
                pTargetIt != l_pSrcTarget_list.end();
                ++pTargetIt)
            {
                TARGETING::Target* l_pPeerTgt =
                    (*pTargetIt)->getAttr<TARGETING::ATTR_PEER_TARGET>();
                o_peerTargetList.push_back(l_pPeerTgt);
            }
            break;
        }
        // Result predicate filter is not NULL, we need to apply this predicate
        // on each of the PEER Target found on the input target list
        else
        {
            for(TARGETING::TargetHandleList::const_iterator pTargetIt
                    = l_pSrcTarget_list.begin();
                pTargetIt != l_pSrcTarget_list.end();
                ++pTargetIt)
            {
                TARGETING::TargetHandleList l_peerTarget_list;
                TARGETING::Target* l_pPeerTgt =
                    (*pTargetIt)->getAttr<TARGETING::ATTR_PEER_TARGET>();

                // Check whether this target matches the filter criteria
                // or we have to look for ALL Parents matching the criteria.
                if((*i_pResultFilter)(l_pPeerTgt))
                {
                    o_peerTargetList.push_back(l_pPeerTgt);
                }
                else
                {
                    (void) TARGETING::targetService().getAssociated(
                            l_peerTarget_list,
                            l_pPeerTgt,
                            TARGETING::TargetService::PARENT,
                            TARGETING::TargetService::ALL,
                            i_pResultFilter);
                    if(!l_peerTarget_list.empty())
                    {
                        // Insert the first one only.
                        o_peerTargetList.push_back(
                                l_peerTarget_list.front());
                    }
                }
            }
        }
    } while(0);
    // If target vector contains more than one element, sorty by HUID
    if (o_peerTargetList.size() > 1)
    {
        std::sort(o_peerTargetList.begin(),o_peerTargetList.end(),
                    compareTargetHuid);
    }
    TARG_EXIT();
    #undef TARG_FN
}

#undef TARG_CLASS

#undef TARG_NAMESPACE

};  // end namespace
