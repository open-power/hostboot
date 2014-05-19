/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/test/dimmPrestest.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#include <targeting/common/predicates/predicates.H>

#include <vpd/vpdreasoncodes.H>
#include <vpd/spdenums.H>
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
#ifndef __HOSTBOOT_RUNTIME
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

                // Test only on first DIMM.
                cmds++;
                theTarget = dimmList[0];

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
                                VPD_COMP_ID );
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
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testDimmPres - %d/%d fails",
                       fails, cmds );
#endif
        }


        /**
         * @brief This test tests that invalid sizes for Presence detect
         *      return errors.
         */
        void testDimmPresInvalidSize ( void )
        {
#ifndef __HOSTBOOT_RUNTIME
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

                // Test on first DIMM only
                cmds++;
                theTarget = dimmList[0];

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
                                VPD_COMP_ID );
                    continue;
                }
                else
                {
                    // Delete the error and continue
                    delete err;
                    err = NULL;
                    continue;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testDimmPresInvalidSize() - %d/%d fails",
                       fails, cmds );
#endif
        }

};
#endif
