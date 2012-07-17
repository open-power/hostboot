/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/targeting/common/utilFilter.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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

#include <sys/task.h>           // task_getcpuid()


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


void getAffinityChips( TARGETING::TargetHandleList& o_vector,
                 const Target * i_chiplet, TYPE i_type, bool i_functional )
{
    //  find all the chip that are affinity-associated with i_chiplet
    TARGETING::PredicateCTM l_chipFilter(CLASS_CHIP, i_type);

    o_vector.clear();
    if (i_functional)
    {
        //  Use PredicateIsFunctional to filter only functional chips
        TARGETING::PredicateIsFunctional l_functional;
        TARGETING::PredicatePostfixExpr l_functionalChips;
        l_functionalChips.push(&l_chipFilter).push(&l_functional).And();
        TARGETING::targetService().getAssociated(
                o_vector,
                i_chiplet,
                TARGETING::TargetService::CHILD_BY_AFFINITY,
                TARGETING::TargetService::ALL,
                &l_functionalChips );
    }
    else
    {
        TARGETING::targetService().getAssociated(
                o_vector,
                i_chiplet,
                TARGETING::TargetService::CHILD_BY_AFFINITY,
                TARGETING::TargetService::ALL,
                &l_chipFilter );
    }

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


const TARGETING::Target *   getMasterCore( )
{
    uint64_t l_masterCoreID                     =   task_getcpuid() & ~7;
    const   TARGETING::Target * l_masterCore    =   NULL;

    TARGETING::Target * l_processor =   NULL;
    (void)TARGETING::targetService().masterProcChipTargetHandle( l_processor );
    FABRIC_NODE_ID_ATTR l_logicalNodeId =
                l_processor->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();
    FABRIC_CHIP_ID_ATTR l_chipId =
                l_processor->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();

    TargetHandleList l_cores;
    getChildChiplets( l_cores,
                      l_processor,
                      TYPE_CORE,
                      true );

    TRACDCOMP( g_trac_targeting,
               "getMasterCore: found %d cores on master proc",
               l_cores.size()   );

    for ( uint8_t l_coreNum=0; l_coreNum < l_cores.size(); l_coreNum++ )
    {
        TARGETING::Target *    l_core  =   l_cores[ l_coreNum ] ;

        CHIP_UNIT_ATTR l_coreId =
                    l_core->getAttr<TARGETING::ATTR_CHIP_UNIT>();

        uint64_t pir = l_coreId << 3;
        pir |= l_chipId << 7;
        pir |= l_logicalNodeId << 10;

        if (pir == l_masterCoreID){
            TRACDCOMP( g_trac_targeting,
                       "found master core: 0x%x, PIR=0x%x :",
                       l_coreId,
                       pir  );
            EntityPath l_path;
            l_path  =   l_core->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            l_masterCore    =   l_core ;
            break;
        }

    }   // endfor

    return l_masterCore;
}

};  // end namespace
