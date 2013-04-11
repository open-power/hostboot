/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/utilFilter.C $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
 * @parm[in]  i_class, the class of the targets to be obtained
 * @parm[in]  i_type, the type of the targets to be obtained
 * @parm[in]  i_functional, set to true to return only functional targets
 *
 * @return N/A
 */
void _getAllChipsOrChiplets( TARGETING::TargetHandleList & o_vector,
                     CLASS i_class, TYPE  i_type, bool i_functional = true )
{
    // Get all chip/chiplet targets
    //  Use PredicateIsFunctional to filter only functional chips/chiplets
    TARGETING::PredicateIsFunctional l_isFunctional;
    //  filter for functional Chips/Chiplets
    TARGETING::PredicateCTM l_Filter(i_class, i_type);
    // declare a postfix expression widget
    TARGETING::PredicatePostfixExpr l_goodFilter;
    //  is-a--chip  is-functional   AND
    l_goodFilter.push(&l_Filter).push(&l_isFunctional).And();
    // apply the filter through all targets.
    TARGETING::TargetRangeFilter l_filter( TARGETING::targetService().begin(),
                            TARGETING::targetService().end(), &l_goodFilter );
    if (!i_functional)
    {
        l_filter.setPredicate(&l_Filter);
    }

    o_vector.clear();
    for ( ; l_filter; ++l_filter)
    {
        o_vector.push_back( *l_filter );
    }
}


void getAllChips( TARGETING::TargetHandleList & o_vector,
                  TYPE i_chipType, bool i_functional = true )
{
    _getAllChipsOrChiplets(o_vector, CLASS_CHIP, i_chipType, i_functional);
}


void getAllLogicalCards( TARGETING::TargetHandleList & o_vector,
                         TYPE i_cardType,
                         bool i_functional = true )
{
    _getAllChipsOrChiplets( o_vector,
                            CLASS_LOGICAL_CARD,
                            i_cardType,
                            i_functional );
}


void getAllCards( TARGETING::TargetHandleList & o_vector,
                  TYPE i_cardType,
                  bool i_functional = true )
{
    _getAllChipsOrChiplets( o_vector,
                            CLASS_CARD,
                            i_cardType,
                            i_functional );
}


void getAllChiplets( TARGETING::TargetHandleList & o_vector,
                     TYPE i_chipletType, bool i_functional = true )
{
    _getAllChipsOrChiplets(o_vector, CLASS_UNIT, i_chipletType, i_functional);
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

void getAffinityTargets ( TARGETING::TargetHandleList& o_vector,
                 const Target * i_target, CLASS i_class, TYPE i_type,
                 TARGETING::TargetService::ASSOCIATION_TYPE i_association,
                  bool i_functional )
{
    //  find all the targets that are affinity-associated with i_target
    TARGETING::PredicateCTM l_targetFilter(i_class, i_type);

    o_vector.clear();
    if (i_functional)
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
    }
    else
    {
        TARGETING::targetService().getAssociated(
                o_vector,
                i_target,
                i_association,
                TARGETING::TargetService::ALL,
                &l_targetFilter );
    }

}

void getChildAffinityTargets(
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target, 
          CLASS                        i_class, 
          TYPE                         i_type, 
          bool                         i_functional)
{
    getAffinityTargets (o_vector, i_target, i_class, i_type,
        TARGETING::TargetService::CHILD_BY_AFFINITY, 
        i_functional); 
}


void getParentAffinityTargets(
          TARGETING::TargetHandleList& o_vector,
    const Target*                      i_target, 
          CLASS                        i_class, 
          TYPE                         i_type,
          bool                         i_functional )
{

    getAffinityTargets (o_vector, i_target, i_class, i_type,
        TARGETING::TargetService::PARENT_BY_AFFINITY,
        i_functional); 
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
    else
    {
        TARG_ERR("Number of Parent chip is not 1, but %d",l_chipList.size());
    }

    return l_pChip;
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
    
    if(i_pSrcTarget == NULL)
    {
        TARG_ASSERT("User tried to call getPeerTargets using NULL Target"
                " Handle");
    }
    
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

    TARG_EXIT();
    #undef TARG_FN
}

#undef TARG_CLASS

#undef TARG_NAMESPACE

};  // end namespace
