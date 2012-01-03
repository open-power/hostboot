//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/spd/test/dimmPrestest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __DIMMPRESTEST_H
#define __DIMMPRESTEST_H

/**
 *  @file dimmPrestest.H
 *
 *  @brief Test cases for DIMM Presence detect
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <targeting/predicates/predicatectm.H>

#include <spd/spdreasoncodes.H>
#include <spd/spdenums.H>
#include "spdtest.H"
#include "../spd.H"

extern trace_desc_t* g_trac_spd;

using namespace TARGETING;
using namespace SPD;

class DIMMPresTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief This test is for testing the DIMM Presence detect logic.
         */
        void testDimmPres ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            bool present = false;
            size_t presentSize = sizeof(present);

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testDimmPres()" );

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( NULL == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testDimmPres() - No DIMMs found!" );
                    break;
                }

                for( uint32_t dimm = 0; dimm < dimmList.size(); dimm++ )
                {
                    cmds++;
                    theTarget = dimmList[dimm];

                    // Check presence
                    err = deviceRead( theTarget,
                                      &present,
                                      presentSize,
                                      DEVICE_PRESENT_ADDRESS() );

                    if( err )
                    {
                        fails++;
                        TS_FAIL( "testDimmPres() - Error returned from DIMM Presence "
                                 "Detect call!" );
                        errlCommit( err,
                                    SPD_COMP_ID );
                        continue;
                    }
                    else if( presentSize != sizeof(present) )
                    {
                        fails++;
                        TS_FAIL( "testDimmPrs() - Size of Presence buffer is not size "
                                 "of boolean!" );
                        continue;
                    }
                    else
                    {
                        // Test was good.
                    }
                }

                if( err )
                {
                    break;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testDimmPres - %d/%d fails",
                       fails, cmds );
        }


        /**
         * @brief This test tests that invalid sizes for Presence detect
         *      return errors.
         */
        void testDimmPresInvalidSize ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            bool present = false;
            size_t presentSize = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testDimmPresInvalidSize()" );

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( NULL == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testDimmPresInvalidSize() - No DIMMs found!" );
                    break;
                }

                for( uint32_t dimm = 0; dimm < dimmList.size(); dimm++ )
                {
                    cmds++;
                    theTarget = dimmList[dimm];

                    // Check presence
                    err = deviceRead( theTarget,
                                      &present,
                                      presentSize,
                                      DEVICE_PRESENT_ADDRESS() );

                    if( !err )
                    {
                        fails++;
                        TS_FAIL( "testDimmPresInvalidSize() - Error not flagged for "
                                 "invalid size!" );
                        errlCommit( err,
                                    SPD_COMP_ID );
                        continue;
                    }
                    else
                    {
                        // Delete the error and continue
                        delete err;
                        err = NULL;
                        continue;
                    }
                }

                if( err )
                {
                    break;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testDimmPresInvalidSize() - %d/%d fails",
                       fails, cmds );
        }


};

#endif
