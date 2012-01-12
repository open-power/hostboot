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
     * @brief   Write to all the attributes and then read them back.
     */
    void    testHWASReadWrite()
    {
        using namespace TARGETING;

        TARGETING::HwasState    l_orgHwasState, l_hwasState;
        TARGETING::TargetIterator l_pTarget;

        TS_TRACE( "testHWASReadWrite entry" );

        //  write a pattern to all HWAS attributes and then read them back
        for(    l_pTarget = TARGETING::targetService().begin();
                l_pTarget != TARGETING::targetService().end();
                ++l_pTarget
                )
        {
            //  save original state
            l_orgHwasState  =   l_pTarget->getAttr<ATTR_HWAS_STATE>();

            //  modify state
            l_hwasState     =   l_pTarget->getAttr<ATTR_HWAS_STATE>();
            l_hwasState.poweredOn             =   true;
            l_hwasState.present               =   true;
            l_hwasState.functional            =   true;
            l_hwasState.changedSinceLastIPL   =   true;
            l_hwasState.gardLevel             =   3;

            //  Now write the modified value back to Targeting.
            l_pTarget->setAttr<ATTR_HWAS_STATE>( l_hwasState );

            // fetch and test new values
            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn != true )
            {
                TS_FAIL( "poweredOn = 0x%x, should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().present != true )
            {
                TS_FAIL( " present   = 0x%x should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().present   );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().functional != true )
            {
                TS_FAIL( " functional = 0x%x, should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().functional );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().changedSinceLastIPL != true )
            {
                TS_FAIL( " changedSinceLastIPL = 0x%x, should be true",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().changedSinceLastIPL );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().gardLevel != 3 )
            {
                TS_FAIL( " gardLevel = 0x%x, should be 3",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().gardLevel );
            }


            //
            //  Now write the original value back.
            //
            l_pTarget->setAttr<ATTR_HWAS_STATE>( l_orgHwasState );

            // check that it got written back correctly
            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn
                    != l_orgHwasState.poweredOn )
            {
                TS_FAIL( "poweredOn = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().poweredOn );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().present
                    != l_orgHwasState.present )
            {
                TS_FAIL( " present   = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().present   );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().functional
                    != l_orgHwasState.functional )
            {
                TS_FAIL( " functional = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().functional );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().changedSinceLastIPL
                    != l_orgHwasState.changedSinceLastIPL )
            {
                TS_FAIL( " changedSinceLastIPL = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().changedSinceLastIPL );
            }

            if ( l_pTarget->getAttr<ATTR_HWAS_STATE>().gardLevel
                    != l_orgHwasState.gardLevel )
            {
                TS_FAIL( " gardLevel = 0x%x, not restored",
                        l_pTarget->getAttr<ATTR_HWAS_STATE>().gardLevel );
            }
        }

        TS_TRACE( "testHWASReadWrite exit" );
    }

};

#endif //
