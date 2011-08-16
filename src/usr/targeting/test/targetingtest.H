#ifndef __TESTTARGETING_H
#define __TESTTARGETING_H

/**
 *  @file testtargeting.H
 *
 *  @brief All unit tests for the targeting infrastructure
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <sys/time.h>

// CXXTEST
#include <cxxtest/TestSuite.H>

// This component
#include <targeting/attributes.H>
#include <targeting/entitypath.H>
#include <targeting/target.H>
#include <targeting/targetservice.H>
#include <targeting/iterators/rangefilter.H>
#include <targeting/predicates/predicatectm.H>
#include <targeting/predicates/predicatepostfixexpr.H>

class TargetingTestSuite: public CxxTest::TestSuite
{
    public:

        /**
         *  @brief Test the TargetService class (except debug cases)
         */
        void testTargetServiceClass()
        {
            nanosleep(1,0);
            TS_TRACE(ENTER_MRK "testTargetServiceClass" );

            using namespace TARGETING;

            TargetService& l_targetService = targetService();

            l_targetService.init();

            // Post init
            // Test: void masterProcChipTarget(
            //          TargetHandleList& o_masterProcChipTarget) const;

            Target* l_pMasterProcChipTargetHandle = NULL;
            (void) l_targetService.masterProcChipTargetHandle(
                l_pMasterProcChipTargetHandle);

            if (   l_pMasterProcChipTargetHandle
                == MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
            {
                TS_FAIL("Post init; master proc chip target handle should not "
                        "be the sentinel value");
            }

            if (l_pMasterProcChipTargetHandle == NULL)
            {
                TS_FAIL("Post init; master proc chip target handle should not "
                        "be the NULL value");
            }

            if (   l_pMasterProcChipTargetHandle->getAttr<ATTR_CLASS> ()
                != CLASS_CHIP)
            {
                TS_FAIL("Post init; master proc chip target handle was not of "
                        "chip class");
            }

            if (   l_pMasterProcChipTargetHandle->getAttr<ATTR_TYPE> ()
                != TYPE_PROC)
            {
                TS_FAIL("Post init; master proc chip target handle was not of "
                        "proc type");
            }

            // Post init
            // Test: void getTopLevelTarget(Target*& o_targetHandle) const;

            Target* l_pTopLevel = NULL;
            (void) l_targetService.getTopLevelTarget(l_pTopLevel);
            if (l_pTopLevel == NULL)
            {
                TS_FAIL("Top level handle was NULL when initialization "
                        "complete");
            }

            if (l_pTopLevel->getAttr<ATTR_CLASS> () != CLASS_SYS)
            {
                TS_FAIL("Post init; top level target class != CLASS_SYS");
            }

            // Post init
            // Test: void exists(
            //           const EntityPath& i_entityPath,
            //               bool&       o_exists) const;

            bool l_exists = false;
            (void) l_targetService.exists(
                l_pTopLevel->getAttr<ATTR_PHYS_PATH> (), l_exists);

            if (l_exists != true)
            {
                TS_FAIL("Expected top level target to exist");
            }

            // Post init
            // Test: Target* toTarget(
            //     const EntityPath& i_entityPath) const;

            Target* l_pInverseTarget = NULL;
            l_pInverseTarget = l_targetService.toTarget(
                l_pTopLevel->getAttr<ATTR_PHYS_PATH> ());

            if (l_pInverseTarget != l_pTopLevel)
            {
                TS_FAIL("Expected to get the original target");
            }

            // Post init
            // Test: void getAssociated(
            // const Target*           i_pTarget,
            //      ASSOCIATION_TYPE  i_type,
            //      RECURSION_LEVEL   i_recursionLevel,
            //      TargetHandleList& o_list) const;

            TargetHandleList l_list;
            (void) l_targetService.getAssociated(
                l_list,
                l_pTopLevel,
                TARGETING::TargetService::CHILD,
                TARGETING::TargetService::IMMEDIATE);
            if (!l_list.size())
            {
                TS_FAIL("Should have found some child elements" );
            }

            // Verify child of given target has a parent that is the original
            // target

            TargetHandleList l_parentList;
            (void) l_targetService.getAssociated(
                l_parentList,
                l_list[0],
                TARGETING::TargetService::PARENT,
                TARGETING::TargetService::IMMEDIATE);

            if (l_parentList.size() != 1)
            {
                TS_FAIL("Should have found a parent element" );
            }

            if (l_parentList[0] != l_pTopLevel)
            {
                TS_FAIL("Parent handle should have matched original target "
                        "handle" );
            }

            (void) l_targetService.getAssociated(
                l_list,
                l_pTopLevel,
                TARGETING::TargetService::CHILD_BY_AFFINITY,
                TARGETING::TargetService::IMMEDIATE);

            if (!l_list.size())
            {
                TS_FAIL("Should have found some child elements" );
            }

            (void) l_targetService.getAssociated(
                l_list,
                l_pTopLevel,
                TARGETING::TargetService::CHILD_BY_AFFINITY,
                TARGETING::TargetService::ALL);

            if (!l_list.size())
            {
                TS_FAIL("Should have found more child elements" );
            }

            l_targetService.dump();

            TS_TRACE(EXIT_MRK "testTargetServiceClass" );
        }

        /**
         *  @test Tests the EntityPath class (except debug cases)
         */
        void testEntityPathClass(void)
        {
            TS_TRACE(ENTER_MRK "testEntityPathClass" );

            using namespace TARGETING;

            EntityPath l_defaultPath;
            if(l_defaultPath.size() != 0)
            {
                TS_FAIL("Default entity path's size was not 0");
            }

            if(l_defaultPath.type() != EntityPath::PATH_NA)
            {
                TS_FAIL("Default entity path's type was not PATH_NA");
            }

            EntityPath l_nonDefaultPath(EntityPath::PATH_PHYSICAL);
            if(l_nonDefaultPath.size() != 0)
            {
                TS_FAIL("Non-default entity path's size was not 0");
            }

            if(l_nonDefaultPath.type() != EntityPath::PATH_PHYSICAL)
            {
                TS_FAIL("Non-default entity path's type was not "
                        "EntityPath::PATH_PHYSICAL");
            }

            l_defaultPath.setType(EntityPath::PATH_AFFINITY);
            if(l_defaultPath.type() != EntityPath::PATH_AFFINITY)
            {
                TS_FAIL("Default entity path's type was not "
                        "EntityPath::PATH_AFFINITY after setting");
            }

            l_defaultPath.setType(EntityPath::PATH_PHYSICAL);
            if(!(l_defaultPath == l_nonDefaultPath))
            {
                TS_FAIL("Default entity path should have been equal to "
                        "the non-default entity path");
            }

            if(!l_defaultPath.equals(l_nonDefaultPath,0))
            {
                TS_FAIL("Default entity path should have been equal to "
                        "the non-default entity path (equals API)");
            }

            l_defaultPath.addLast(TYPE_PROC,0);
            if(l_defaultPath == l_nonDefaultPath)
            {
                TS_FAIL("Default entity path should NOT have been equal to "
                        "the non-default entity path");
            }

            if(l_defaultPath.equals(l_nonDefaultPath,1))
            {
                TS_FAIL("Default entity path should NOT have been equal to "
                        "the non-default entity path (equals API, comparing 1 "
                        "element)");
            }

            if(l_defaultPath.size() != 1)
            {
                TS_FAIL("Default entity path should have had one path element"
                        "after adding PROC0");
            }

            l_nonDefaultPath.addLast(TYPE_PROC,0);
            if(! (l_defaultPath == l_nonDefaultPath) )
            {
                TS_FAIL("Default entity path should have been equal to "
                        "the non-default entity path since they now"
                        "both have the same 1 path element");
            }

            l_defaultPath.addLast(TYPE_MBA,1).addLast(TYPE_MBS,2);
            if(l_defaultPath.size() != 3)
            {
                TS_FAIL("Default entity path should have had two path elements"
                        "after adding MBA1 and MBS2");
            }

            if( (l_defaultPath[0].type != TYPE_PROC)
                || (l_defaultPath[0].instance != 0)
                || (l_defaultPath[1].type != TYPE_MBA)
                || (l_defaultPath[1].instance != 1)
                || (l_defaultPath[2].type != TYPE_MBS)
                || (l_defaultPath[2].instance != 2))
            {
                TS_FAIL("Default entity path should have had correct 3 path "
                        "elements");
            }

            l_defaultPath.removeLast();
            if(l_defaultPath.size() != 2)
            {
                TS_FAIL("Default entity path should have had two path elements"
                        "after removing MBS2");
            }

            if( (l_defaultPath[0].type != TYPE_PROC)
                || (l_defaultPath[0].instance != 0)
                || (l_defaultPath[1].type != TYPE_MBA)
                || (l_defaultPath[1].instance != 1))
            {
                TS_FAIL("Default entity path should have had correct 2 path "
                        "elements");
            }

            l_nonDefaultPath.addLast(TYPE_MBA,1).addLast(TYPE_MBS,2);

            // Default now has proc/mba/
            // Non-default now has proc/mba/mbs
            if(l_defaultPath == l_nonDefaultPath)
            {
                TS_FAIL("Default entity path should NOT have been equal to "
                        "the non-default entity path since they now"
                        "have different number of path elements");
            }

            if( !l_defaultPath.equals(l_nonDefaultPath,2) )
            {
                TS_FAIL("Default entity path should have been equal to "
                        "the non-default entity path since they have the same"
                        "first two path elements");
            }

            l_defaultPath.removeLast().removeLast();
            if(l_defaultPath.size() != 0)
            {
                TS_FAIL("Default entity path should have had no path element"
                        "after removing MBA1 and PROC0");
            }

            TargetService& l_targetService = targetService();
            l_targetService.init();

            EntityPath l_realPath(EntityPath::PATH_PHYSICAL);
            l_realPath.addLast(TYPE_SYS,0).addLast(TYPE_NODE,0)
                .addLast(TYPE_PROC,0);

            Target* l_pTarget = l_realPath.operator->();
            if(l_pTarget == NULL)
            {
                TS_FAIL("Real entity path should have mapped to an existing "
                        "target");
            }

            EntityPath l_path(EntityPath::PATH_PHYSICAL);
            l_path.addLast(TYPE_SYS,0);
            EntityPath l_changedPath = l_path.copyRemoveLast();
            if(   (l_changedPath.size() != 0)
               || (l_path.size() != 1))
            {
                TS_FAIL("Const entity path should not have been altered in "
                        "const add test");
            }

            l_changedPath = l_path.copyAddLast(TYPE_NODE,0);
            if(   (l_changedPath.size() != 2)
               || (l_path.size() != 1))
            {
                TS_FAIL("Const entity path should not have been altered "
                        "in const add test");
            }

            TS_TRACE(EXIT_MRK "testEntityPathClass" );
        }

        /**
         *  @test Tests the EntityPath class (except debug cases)
         */
        void testTargetClass(void)
        {
            TS_TRACE(ENTER_MRK "testTargetClass" );

            using namespace TARGETING;
            TargetService& l_targetService = targetService();
            l_targetService.init();

            EntityPath l_realPath(EntityPath::PATH_PHYSICAL);
            l_realPath.addLast(TYPE_SYS,0).addLast(TYPE_NODE,0)
                .addLast(TYPE_PROC,0);
            l_realPath.dump();

            Target* l_pTarget = l_realPath.operator->();
            if(l_pTarget == NULL)
            {
                TS_FAIL("Failed to convert entity path to initial target");
            }

            CLASS l_class = l_pTarget->getAttr<ATTR_CLASS>();
            if(l_class != CLASS_CHIP)
            {
                TS_FAIL("Failed to get the class attribute");
            }

            l_class = CLASS_NA;
            if( !l_pTarget->tryGetAttr<ATTR_CLASS>(l_class) )
            {
                TS_FAIL("Failed to get the class attribute");
            }

            if(l_class != CLASS_CHIP)
            {
                TS_FAIL("Failed to try/get the class attribute");
            }

            attrToString<ATTR_CLASS>(l_class);

            uint8_t l_scom = 0;
            if( l_pTarget->tryGetAttr<ATTR_DUMMY_RO>(l_scom) )
            {
                TS_FAIL("ATTR_DUMMY_RO attribute should not have been available "
                        "to read");
            }

            if(l_scom != 0)
            {
                TS_FAIL("Failed ! try/get should not have set the SCOM attribute");
            }

            l_scom = 5;
            if( l_pTarget->trySetAttr<ATTR_DUMMY_WO>(l_scom) )
            {
                TS_FAIL("ATTR_DUMMY_WO attribute should not have been available "
                        "to write");
            }

            if(l_scom != 5)
            {
                TS_FAIL("SCOM attribute should not have been altered in the failed "
                        "write");
            }

            uint8_t l_wo = 6;
            if( !l_pTarget->trySetAttr<ATTR_DUMMY_RW>(l_wo) )
            {
                TS_FAIL("ATTR_DUMMY_RW should have been available for write");
            }

            if(l_wo != 6)
            {
                TS_FAIL("ATTR_DUMMY_RW local attribute should not have been "
                        "altered in the successful write");
            }

            uint8_t l_read = l_pTarget->getAttr<ATTR_DUMMY_RW>();
            if(l_read != l_wo)
            {
                TS_FAIL("Failed to read back the correct ATTR_DUMMY_RW");
            }

            uint8_t l_setWo = 9;
            l_pTarget->setAttr<ATTR_DUMMY_RW>(l_setWo);
            if(l_setWo != 9)
            {
                TS_FAIL("ATTR_DUMMY_RW local attribute should not have been "
                        "altered in the successful setAttr");
            }

            uint8_t l_setWoVerify = l_pTarget->getAttr<ATTR_DUMMY_RW>();
            if(l_setWoVerify != l_setWo)
            {
                TS_FAIL("ATTR_DUMMY_RW read should have matched prior write");
            }

            TS_TRACE(EXIT_MRK "testTargetClass" );
        }

        void testPredicateCtm()
        {
            TS_TRACE(ENTER_MRK "testPredicateCtm" );

            using namespace TARGETING;
            TargetService& l_targetService = targetService();

            // Get top level (system) target
            Target* l_pTopLevel = NULL;
            (void) l_targetService.getTopLevelTarget(l_pTopLevel);
            if (l_pTopLevel == NULL)
            {
                TS_FAIL("Top level handle was NULL when initialization "
                        "complete");
            }

            PredicateCTM l_allWild;
            if( ! l_allWild(l_pTopLevel) )
            {
                TS_FAIL("CTM all wildcards filter should have matched system "
                        "target");
            }

            PredicateCTM l_typeModelWild(CLASS_SYS);
            if( ! l_typeModelWild(l_pTopLevel) )
            {
                TS_FAIL("CTM class sys, remaining wildcards filter should have "
                        "matched system ");
            }

            PredicateCTM l_modelWild(CLASS_SYS,TYPE_SYS);
            if( ! l_modelWild(l_pTopLevel) )
            {
                TS_FAIL("CTM class sys, type sys, remaining wildcards filter "
                        "should have matched system ");
            }

            PredicateCTM l_noWild(CLASS_SYS,TYPE_SYS,MODEL_POWER8);
            if( ! l_noWild(l_pTopLevel) )
            {
                TS_FAIL("CTM class sys, type sys, model power8 should have "
                        "matched system ");
            }

            PredicateCTM l_classWild(CLASS_NA,TYPE_SYS,MODEL_POWER8);
            if( ! l_classWild(l_pTopLevel) )
            {
                TS_FAIL("CTM class wild, type sys, model power8 should have "
                        "matched system ");
            }

            PredicateCTM l_typeWild(CLASS_SYS,TYPE_NA,MODEL_POWER8);
            if( ! l_typeWild(l_pTopLevel) )
            {
                TS_FAIL("CTM class sys, wild, model power8 should have "
                        "matched system ");
            }

            PredicateCTM l_classModelWild(CLASS_NA,TYPE_SYS,MODEL_NA);
            if( ! l_classModelWild(l_pTopLevel) )
            {
                TS_FAIL("CTM wild, type sys, wild should have "
                        "matched system ");
            }

            PredicateCTM l_classTypeWild(CLASS_NA,TYPE_NA,MODEL_NA);
            if( ! l_classTypeWild(l_pTopLevel) )
            {
                TS_FAIL("CTM wild, wild, model should have "
                        "matched system ");
            }

            PredicateCTM l_chipClass(CLASS_CHIP,TYPE_NA,MODEL_NA);
            if(  l_chipClass(l_pTopLevel) )
            {
                TS_FAIL("CTM of class chip, wild, wild should not have matched "
                        "matched system ");
            }

            #if 0 // Prove copy CTOR/assignment operator is disabled
            PredicateCTM l_ctmLhs;
            PredicateCTM l_ctmRhs;

            l_ctmLhs = l_ctmRhs;

            PredicateCTM l_ctmCtor(l_ctmRhs);
            #endif
            
            PredicateBase* l_pBase = new PredicateCTM(CLASS_SYS);
            delete l_pBase;
            l_pBase = NULL;

            TS_TRACE(EXIT_MRK "testPredicateCtm" );
                
        }

        void testPredicatePostfixExpr()
        {
            TS_TRACE(ENTER_MRK "testPredicatePostfixExpr" );

            using namespace TARGETING;
            TargetService& l_targetService = targetService();

            // Get top level (system) target
            Target* l_pTopLevel = NULL;
            (void) l_targetService.getTopLevelTarget(l_pTopLevel);
            if (l_pTopLevel == NULL)
            {
                TS_FAIL("Top level handle was NULL when initialization "
                        "complete");
            }

            PredicatePostfixExpr l_alwaysTrueExpr;
            if(!l_alwaysTrueExpr(l_pTopLevel) )
            {
                TS_FAIL("Always true filter should have matched system");
            }

            #if 0 
            // Triggers NULL assertion check on push 
            l_alwaysTrueExpr.push(NULL);
            #endif

            #if 0
            // Triggers not enough stack elements assertion when evaluating Not
            l_alwaysTrueExpr.Not();
            if(l_alwaysTrueExpr(l_pTopLevel) )
            {
                TS_FAIL("Negated always true filter should not have matched "
                        "system");
            }
            #endif

            #if 0
            // Triggers illegal target assertion
            l_alwaysTrueExpr(NULL);
            #endif

            #if 0
            // Triggers formatting assertion
            l_alwaysTrueExpr.And();
            l_alwaysTrueExpr(l_pTopLevel);
            #endif

            #if 0
            // Triggers formatting assertion
            l_alwaysTrueExpr.Or();
            l_alwaysTrueExpr(l_pTopLevel);
            #endif

            PredicateCTM l_sysClass(CLASS_SYS);

            #if 0
            // Triggers formatting assertion
            l_alwaysTrueExpr.push(&l_sysClass);
            l_alwaysTrueExpr.And();
            l_alwaysTrueExpr(l_pTopLevel);
            #endif

            #if 0
            // Triggers formatting assertion
            l_alwaysTrueExpr.push(&l_sysClass);
            l_alwaysTrueExpr.Or();
            l_alwaysTrueExpr(l_pTopLevel);
            #endif

            #if 0
            // Triggers illegal formatting exception
            // != 1 results on stack
            l_alwaysTrueExpr.push(&l_sysClass);
            l_alwaysTrueExpr.push(&l_sysClass);
            l_alwaysTrueExpr.Not();
            l_alwaysTrueExpr(l_pTopLevel);
            #endif

            PredicateCTM l_sysType(CLASS_NA,TYPE_SYS);
            PredicateCTM l_power8Model(CLASS_NA,TYPE_NA,MODEL_POWER8);
            PredicatePostfixExpr l_expr;
            l_expr.push(&l_sysClass).push(&l_sysType).And();
            l_expr.push(&l_power8Model).And();

            if(!l_expr(l_pTopLevel) )
            {
                TS_FAIL("CTM of class sys && type sys && model power8 should "
                        "have matched system");
            }

            l_expr.Not();

            if(l_expr(l_pTopLevel) )
            {
                TS_FAIL("CTM of class sys && type sys && model power8 should "
                        "npt have matched system after negation");
            }

            l_expr.push(&l_sysClass);
            l_expr.Or();

            if(!l_expr(l_pTopLevel) )
            {
                TS_FAIL("CTM of class sys && type sys && model power8 should "
                        "have matched system after negation then || sys class");
            }

            PredicatePostfixExpr* l_pExpr = new PredicatePostfixExpr;
            l_pExpr->push(&l_sysClass).push(&l_sysType).And();
            l_pExpr->push(&l_power8Model).And();
            delete (static_cast<PredicateBase*>(l_pExpr));
            
            #if 0
            PredicatePostfixExpr l_lhs;
            PredicatePostfixExpr l_rhs;

            l_lhs = l_rhs;

            PredicatePostfixExpr l_cpCtor(l_rhs);
            #endif


            TS_TRACE(EXIT_MRK "testPredicatePostfixExpr" );
        }

        void testTargetIterator()
        {
            TS_TRACE(ENTER_MRK "testTargetIterator");

            using namespace TARGETING;
            TargetService& l_targetService = targetService();


            TargetIterator l_pIt;
            if( l_pIt != l_targetService.end() )
            {
                TS_FAIL("Default TargetIterator should point to past the end "
                        "of container");
            }

            ++l_pIt;
            if( l_pIt != l_targetService.end() )
            {
                TS_FAIL("Default TargetIterator preincremented should point to "
                        "past the end of container");
            }

            TargetIterator* l_pItNew = new TargetIterator;
            delete l_pItNew;
            l_pItNew = NULL;

            if(*l_pIt != NULL)
            {
               TS_FAIL("Default TargetIterator dereference should return NULL");
            }

            // Get top level (system) target to verify at least 1 target
            Target* l_pTopLevel = NULL;
            (void) l_targetService.getTopLevelTarget(l_pTopLevel);
            if (l_pTopLevel == NULL)
            {
                TS_FAIL("Top level handle was NULL when initialization "
                        "complete");
            }
       
            l_pIt = l_targetService.begin();
            if((*l_pIt) == NULL)
            {
               TS_FAIL("TargetService begin() should return !NULL");
            }

            CLASS l_class = CLASS_NA;
            if( !l_pIt->tryGetAttr<ATTR_CLASS>(l_class) )
            {
               TS_FAIL("Failed to get expected class attribute");
            }

            TargetIterator l_rhs = l_targetService.begin();
            if( ! (l_pIt == l_rhs) )
            {
               TS_FAIL("Iterators should be equal, but aren't");
            }

            l_rhs = l_targetService.begin();
            if( l_pIt != l_rhs )
            {
               TS_FAIL("Iterators should be equal, but aren't");
            }

            TargetIterator l_rhs2 = l_targetService.begin();
            ++l_rhs2;
            ++l_pIt;
            if( l_pIt != l_rhs2 )
            {
               TS_FAIL("Iterators should be equal, but aren't");
            }

            l_rhs2++;
            l_pIt++;
            if( l_pIt != l_rhs2 )
            {
               TS_FAIL("Iterators should be equal, but aren't");
            }

            TargetIterator l_pItClone(l_rhs2);
            if( l_pIt != l_pItClone)
            {
               TS_FAIL("Iterators should be equal, but aren't");
            }
 
            if(l_pIt != l_pItClone++)
            {
               TS_FAIL("Iterators should be equal, but aren't");
            }

            if( (++l_pIt) != l_pItClone)
            {
               TS_FAIL("Iterators should be equal, but aren't");
            }

            const TargetService& l_constTargetService = targetService();

            ConstTargetIterator l_pConstIt;
            if( l_pConstIt != l_constTargetService.end() )
            {
                TS_FAIL("Default ConstTargetIterator should point to past the "
                        "end of container");
            }

            l_pConstIt = l_constTargetService.begin();
            if( (*l_pConstIt) == NULL)
            {
                TS_FAIL("Iterator does not point to valid Target as expected");
            }

            TS_TRACE(EXIT_MRK "testTargetIterator" );
        }

        void testRangeFilter(void)
        {
            TS_TRACE(ENTER_MRK "testRangeFilters" );

            using namespace TARGETING;

            TargetRangeFilter* l_pRangeFilter = new TargetRangeFilter(
                targetService().begin(),
                targetService().end(),
                NULL);
            delete l_pRangeFilter;
            l_pRangeFilter = NULL;

            
            TargetRangeFilter l_f1(
                targetService().begin(),
                targetService().end(),
                NULL);

            Target* l_pBegin = (*l_f1);
            ++l_f1;
            Target* l_pNext = (*l_f1);
            if(   (l_pBegin == NULL)
               || (l_pNext == NULL)
               || (l_pBegin == l_pNext)
               )
            {
                TS_FAIL("Target* pointed to by Begin/next NULL -or- begin =="
                        "next");
            }

            l_f1.reset();
            if( *l_f1 != l_pBegin )
            {
                TS_FAIL("Target* after reset should be equal to original");
            }

            l_f1.reset();
            TargetRangeFilter l_f2 = l_f1;
            PredicateCTM l_ctm(CLASS_SYS,TYPE_CORE); // Nonsense CTM
            l_f1.setPredicate(&l_ctm);
            if( *l_f1 == l_pBegin )
            {
                TS_FAIL("Target* after reset and change of predicate should be"
                        "different than the original");
            }

            PredicateCTM l_ctm1(CLASS_CHIP,TYPE_PROC); 

            TargetRangeFilter l_f3(
                targetService().begin(),
                targetService().end(),
                &l_ctm1);
            for(;l_f3;++l_f3)
            {
                if(l_f3->getAttr<ATTR_TYPE>() != TYPE_PROC)
                {
                    TS_FAIL("Should only have returned type proc");
                    break;
                }
            }
              
            TargetIterator l_pIt = targetService().begin();
            ++l_pIt;
            ++l_pIt;

            if(l_pIt == targetService().end())
            {
                TS_FAIL("Not enough elements for test");
            }

            TargetRangeFilter l_partial(
                targetService().begin(),
                l_pIt,
                NULL);
            int i=0;

            for(; l_partial; ++l_partial)
            {
                i++;
            }
                    
            if(i != 2)
            {
                TS_FAIL("Should have gotten 2 elements %d",i);
            }

            TS_TRACE(EXIT_MRK "testRangeFilter" );
        }

        void testComplexFilter(void)
        {
            TS_TRACE(ENTER_MRK "testComplexFilter" );

            using namespace TARGETING;

            TargetService& l_targetService = targetService();
            
            TargetRangeFilter f(l_targetService.begin(), 
                                l_targetService.end(), 
                                NULL);
            int l_count = 0;
            for(; f; ++f, l_count++)
            {
            }

            TS_TRACE(INF_MRK "Found %d total targets", l_count);
            
            PredicateCTM l_procs(CLASS_CHIP);
            PredicateCTM l_enclosures(CLASS_ENC);
            PredicatePostfixExpr l_query;
            l_query.push(&l_procs).push(&l_enclosures).Or();

            f.setPredicate(&l_query);
            f.reset();

            l_count = 0;
            for(; f; ++f, ++l_count)
            {
                EntityPath l_path = f->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
            }            

            TS_TRACE(INF_MRK "Found %d targets that are chips or enclosures ",
                      l_count);
    
            l_query.Not();
            f.reset();

            l_count = 0;
            for(; f; ++f, ++l_count)
            {
            }

            TS_TRACE(INF_MRK "Found %d targets that are not chips or "
                     "enclosures",l_count);

            Target* l_pMasterProcChipTargetHandle = NULL;
            (void) l_targetService.masterProcChipTargetHandle(
                l_pMasterProcChipTargetHandle);
            if(l_pMasterProcChipTargetHandle == NULL)
            {
                TS_FAIL("Master processor chip target not found");
            }

            PredicateCTM l_ex(CLASS_UNIT,TYPE_EX);
            PredicateCTM l_mba(CLASS_UNIT,TYPE_MBA);
            PredicatePostfixExpr l_procquery;
            l_procquery.push(&l_ex).push(&l_mba).Or();

            TargetHandleList l_list;
            (void) targetService().getAssociated(
                    l_list,
                    l_pMasterProcChipTargetHandle,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &l_procquery);

            l_count = 0;
            for(uint32_t i=0; i<l_list.size(); ++i, ++l_count)
            {
                 EntityPath l_path = l_list[i]->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
            }

            TS_TRACE(INF_MRK "Found %d targets that are ex/mba units off "
                     "master processor",l_count);

            TS_TRACE(EXIT_MRK "testComplexFilter" );
        }
};

#endif // End __TESTTARGETING_H
