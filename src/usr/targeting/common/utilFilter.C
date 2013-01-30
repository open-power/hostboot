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

/**
 * Miscellaneous Filter Utility Functions
 */

namespace TARGETING
{

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

void getChildAffinityTargets ( TARGETING::TargetHandleList& o_vector,
		 const Target * i_target, CLASS i_class, TYPE i_type, 
		 bool i_functional )
{
    getAffinityTargets (o_vector, i_target, i_class, i_type,
			TARGETING::TargetService::CHILD_BY_AFFINITY, 
			i_functional); 
}


void getParentAffinityTargets ( TARGETING::TargetHandleList& o_vector,
		 const Target * i_target, CLASS i_class, TYPE i_type,
		 bool i_functional )
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


};  // end namespace
