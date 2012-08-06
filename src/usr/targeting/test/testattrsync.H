/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/targeting/test/testattrsync.H $
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
#ifndef __TARGETING_TESTATTRSYNC_H
#define __TARGETING_TESTATTRSYNC_H

/**
 *  @file targeting/test/testattrsync.H
 *
 *  @brief All unit tests which test attribute sync
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <sys/time.h>

// CXXTEST
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>

// This component
#include <targeting/common/attributes.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/attrsync.H>
#include <errl/errludtarget.H>
#include <targeting/common/trace.H>
#include <kernel/console.H>

class AttrSyncTestSuite : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test sync of targeting attributes to FSP
     */
    void testAttributeSync()
    {
        TS_TRACE(ENTER_MRK "testAttributeSync" );

        using namespace TARGETING;

        AttributeSync l_attrSync;

        TS_TRACE( "Sync PNOR RW" );

        errlHndl_t err = l_attrSync.syncSectionToFsp(
                                    TARGETING::SECTION_TYPE_PNOR_RW );

        if( err )
        {
            if( MBOX::mailbox_enabled() )
            {
                TS_FAIL(" Error returned when syncing SECTION_TYPE_PNOR_RW");
            }
            err = NULL;
        }

        TS_TRACE("Sync PNOR INIT " );

        err = l_attrSync.syncSectionToFsp(
                TARGETING::SECTION_TYPE_HEAP_PNOR_INIT );

        if( err )
        {
            if( MBOX::mailbox_enabled() )
            {
                TS_FAIL(" Error returned when syncing SECTION_TYPE_HEAP_PNOR_INIT"); 
            }
            err = NULL;
        }

        TS_TRACE( "Sync PNOR ZERO INIT" );

        err = l_attrSync.syncSectionToFsp(  
                TARGETING::SECTION_TYPE_HEAP_ZERO_INIT );

        if( err )
        {
           if( MBOX::mailbox_enabled() )
           {
               TS_FAIL(" Error returned when syncing SECTION_TYPE_HEAP_ZERO_INIT"); 
           }
           err = NULL;
        }

    }

};

#endif // End __TARGETING_TESTTARGETING_H
