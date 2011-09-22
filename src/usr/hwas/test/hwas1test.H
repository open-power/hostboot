//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/test/targetingtest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __TESTTARGETING_H
#define __TESTTARGETING_H

/**
 *  @file testtargeting.H
 *
 *  @brief Unit tests for HWAS (ISTEP 4)
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <sys/time.h>

// CXXTEST
#include <cxxtest/TestSuite.H>
#include <hwpf/plat/fapiPlatAttributeService.H>
#include <fapiReturnCode.H>
#include <fapiAttributeIds.H>
#include <fapiAttributeService.H>
#include <errl/errlmanager.H>

// This component
#include <targeting/attributes.H>
#include <targeting/entitypath.H>
#include <targeting/target.H>
#include <targeting/targetservice.H>
#include <targeting/iterators/rangefilter.H>
#include <targeting/predicates/predicatectm.H>
#include <targeting/predicates/predicatepostfixexpr.H>

class HWAS1test: public CxxTest::TestSuite
{
public:

    /**
     *  @brief Walk all the targets and verify that HWAS_STATE is set
     *      correctly.
     *
     *  @note  Results of this test will change as more stuff gets added to
     *  HWAS - how to fix?
     */
    void testHWASdefaultPresence()
    {

        nanosleep(1,0);
        TS_TRACE(ENTER_MRK "testHWASdefaultPresence" );

        using namespace TARGETING;

        TargetService& l_targetService = targetService();

        l_targetService.init();


        // get top level
        // Post init
        // Test: void getTopLevelTarget(Target*& o_targetHandle) const;

        Target* l_pTopLevel = NULL;
        (void) l_targetService.getTopLevelTarget(l_pTopLevel);
        if (l_pTopLevel == NULL)
        {
            TS_FAIL("Top level handle was NULL when initialization complete");
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
                TARGETING::TargetService::ALL);

        TS_TRACE("Child list size is 0x%x", l_list.size() );
        for (uint64_t i=0; i<l_list.size(); i++ )
        {
            //  2011-10-19  all attribute fields should be 0 at this point.
            if (    ( l_list[i]->getAttr<ATTR_HWAS_STATE>().poweredOn)
                 || ( l_list[i]->getAttr<ATTR_HWAS_STATE>().present)
                 || ( l_list[i]->getAttr<ATTR_HWAS_STATE>().functional)
                 || ( l_list[i]->getAttr<ATTR_HWAS_STATE>().changedSinceLastIPL)
                 || ( l_list[i]->getAttr<ATTR_HWAS_STATE>().gardLevel)
            )
            {
                l_list[i]->getAttr<ATTR_PHYS_PATH>().dump();
                TS_TRACE( " poweredOn = 0x%x",
                        l_list[i]->getAttr<ATTR_HWAS_STATE>().poweredOn );
                TS_TRACE( " present   = 0x%x",
                        l_list[i]->getAttr<ATTR_HWAS_STATE>().present   );
                TS_TRACE( " l_functional = 0x%x",
                        l_list[i]->getAttr<ATTR_HWAS_STATE>().functional );
                TS_TRACE( " l_changedSinceLastIPL = 0x%x",
                        l_list[i]->getAttr<ATTR_HWAS_STATE>().changedSinceLastIPL );
                TS_TRACE( " l_gardLevel = 0x%x",
                        l_list[i]->getAttr<ATTR_HWAS_STATE>().gardLevel );

                TS_FAIL( "Attribute fields not correct: ");
            }
        }

        TS_TRACE(EXIT_MRK "testHWASdefaultPresence" );
    }

};

#endif //
