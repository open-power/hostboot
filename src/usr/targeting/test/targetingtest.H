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
            (void) l_targetService.getAssociated(l_pTopLevel,
                TARGETING::TargetService::CHILD,
                TARGETING::TargetService::IMMEDIATE, l_list);
            if (!l_list.size())
            {
                TS_FAIL("Should have found some child elements" );
            }

            // Verify child of given target has a parent that is the original
            // target

            TargetHandleList l_parentList;
            (void) l_targetService.getAssociated(l_list[0],
                TARGETING::TargetService::PARENT,
                TARGETING::TargetService::IMMEDIATE, l_parentList);

            if (l_parentList.size() != 1)
            {
                TS_FAIL("Should have found a parent element" );
            }

            if (l_parentList[0] != l_pTopLevel)
            {
                TS_FAIL("Parent handle should have matched original target "
                        "handle" );
            }

            (void) l_targetService.getAssociated(l_pTopLevel,
                TARGETING::TargetService::CHILD_BY_AFFINITY,
                TARGETING::TargetService::IMMEDIATE, l_list);

            if (!l_list.size())
            {
                TS_FAIL("Should have found some child elements" );
            }

            (void) l_targetService.getAssociated(l_pTopLevel,
                TARGETING::TargetService::CHILD_BY_AFFINITY,
                TARGETING::TargetService::ALL, l_list);

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
};

#endif // End __TESTTARGETING_H
