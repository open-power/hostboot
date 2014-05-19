/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/test/cvpdtest.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef __CVPDTEST_H
#define __CVPDTEST_H

/**
 *  @file cvpdtest.H
 *
 *  @brief Test cases for CVPD code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <targeting/common/predicates/predicatectm.H>

#include <vpd/cvpdenums.H>
#include <vpd/vpdreasoncodes.H>
#include "../cvpd.H"
#include "../ipvpd.H"


extern trace_desc_t* g_trac_vpd;

using namespace TARGETING;

/**
 * @brief Structure to define record/keyword pairs for CVPD tests.
 */
struct cvpdTestData
{
    IpVpdFacade::ipVpdRecord record;
    IpVpdFacade::ipVpdRecord keyword;
};

/**
 * @brief Data sample to be used for CVPD testing.
 *      NOTE: By reading this entire list, it also validates that the records
 *      and keywords that we expect to be there are actually there...
 */
cvpdTestData cvpdData[] =
{
    { CVPD::VEIR, CVPD::pdI },
    { CVPD::MER0, CVPD::pdI },
    { CVPD::VSPD, CVPD::pdI },
    { CVPD::VSPD, CVPD::MT },
    { CVPD::VSPD, CVPD::MR },
    { CVPD::VSPD, CVPD::pdA },
    { CVPD::VSPD, CVPD::EL },
    { CVPD::VSPD, CVPD::LM },
    { CVPD::VSPD, CVPD::MW },
    { CVPD::VSPD, CVPD::MV },
    { CVPD::VSPD, CVPD::AM },
    { CVPD::VINI, CVPD::VZ },
    { CVPD::VSPD, CVPD::MX },

};

void getMembufTargets( TargetHandleList & o_membufList )
{
    // Get top level system target
    TARGETING::TargetService & tS = TARGETING::targetService();
    TARGETING::Target * sysTarget = NULL;
    tS.getTopLevelTarget( sysTarget );
    assert( sysTarget != NULL );

    // Get a Membuf Target
    TARGETING::PredicateCTM predMemb( TARGETING::CLASS_CHIP,
                                      TARGETING::TYPE_MEMBUF );
    tS.getAssociated( o_membufList,
                      sysTarget,
                      TARGETING::TargetService::CHILD,
                      TARGETING::TargetService::ALL,
                      &predMemb );

    TRACDCOMP( g_trac_vpd,
               "getMembufTargets() - found %d Memory Buffers",
               o_membufList.size() );

    return;
}

TARGETING::Target* getFunctionalMembufTarget()
{
    TARGETING::Target * theTarget = NULL;
    TRACDCOMP( g_trac_vpd,
               "getFunctionalMembufTarget() - Finding a membuf" );

    do {
        // Get the Memory Buffer targets
        TargetHandleList membufList;
        getMembufTargets( membufList );

        if( ( 0 == membufList.size() ) ||
            ( NULL == membufList[0] ) )
        {
            continue;  // add continue because have no Membuf targets
        }

        for(uint32_t i=0; i<membufList.size(); i++)
        {
            if(membufList[i]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
            {
                theTarget = membufList[i];
                break;
            }
        }
    }while(0);

    return theTarget;

}

class CVPDTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief This function will test CVPD reads.
         */
        void testCvpdRead ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint64_t theRecord = 0x0;
            uint64_t theKeyword = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testCvpdRead()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMembufTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testCvpdRead() - No Functional Targets found!");
                    break;
                }

                uint8_t * theData = NULL;
                size_t theSize = 0;
                const uint32_t numCmds = sizeof(cvpdData)/sizeof(cvpdData[0]);
                for( uint32_t curCmd = 0; curCmd < numCmds; curCmd++ )
                {
                    cmds++;
                    theRecord = (uint64_t)cvpdData[curCmd].record;
                    theKeyword = (uint64_t)cvpdData[curCmd].keyword;
                    err = deviceRead( theTarget,
                                      NULL,
                                      theSize,
                                      DEVICE_CVPD_ADDRESS( theRecord,
                                                           theKeyword ) );

                    if( err )
                    {
                        fails++;
                        TRACFCOMP( g_trac_vpd,
                                   ERR_MRK"testCvpdRead() - failure reading "
                                   "keyword size!!  rec: 0x%04x, kwd: 0x%04x",
                                   theRecord,
                                   theKeyword );
                        TS_FAIL( "testCvpdRead() - Failure reading keyword size!" );
                        errlCommit( err,
                                    VPD_COMP_ID );
                        continue;
                    }

                    theData = static_cast<uint8_t*>(malloc( theSize ));

                    // Read record/keyword pair
                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_CVPD_ADDRESS( theRecord,
                                                           theKeyword ) );

                    if( err )
                    {
                        fails++;
                        TRACFCOMP( g_trac_vpd,
                                   ERR_MRK"testCvpdRead() - Failure on Record: "
                                   "0x%04x, keyword: 0x%04x, of size: 0x%04x "
                                   "- test %d",
                                   theRecord,
                                   theKeyword,
                                   theSize, curCmd );
                        TS_FAIL( "testCvpdRead() - Failure during CVPD read!" );
                        errlCommit( err,
                                    VPD_COMP_ID );

                        // Free the data
                        if( NULL != theData )
                        {
                            free( theData );
                            theData = NULL;
                        }
                        continue;
                    }

                    TRACDCOMP( g_trac_vpd,
                               INFO_MRK"testCvpdRead Results:" );
                    for( uint32_t i = 0; i < theSize; i++ )
                    {
                        TRACDCOMP( g_trac_vpd,
                                   INFO_MRK"   Byte[%d]: 0x%02x",
                                   i, theData[i] );
                    }

                    // Free the data
                    if( NULL != theData )
                    {
                        free( theData );
                        theData = NULL;
                    }
                }
            } while( 0 );

            TRACFCOMP( g_trac_vpd,
                       "testCvpdRead - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test CVPD writes.
         */
        void testCvpdWrite ( void )
        {
#ifndef __HOSTBOOT_RUNTIME
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t* testData = NULL;
            uint8_t* origData = NULL;
            uint8_t* verifyData = NULL;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testCvpdWrite()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMembufTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testCvpdWrite() - No Functional Targets found!");
                    break;
                }

                // first figure out how big the keyword is
                cmds++;
                size_t theSize = 0;
                err = deviceRead( theTarget,
                                  testData,
                                  theSize,
                                  DEVICE_CVPD_ADDRESS(CVPD::VEIR,CVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testCvpdWrite() - failure getting size of VEIR/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testCvpdWrite() - Failure calling deviceRead!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
                }

                // save off the original data
                origData = new uint8_t[theSize];
                cmds++;
                err = deviceRead( theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_CVPD_ADDRESS(CVPD::VEIR,CVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testCvpdWrite() - failure reading VEIR/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testCvpdWrite() - Failure calling deviceRead!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
                }
                TRACFBIN( g_trac_vpd, "testCvpdWrite() - orig=",
                          origData, theSize );

                // fill it up with some dummy data
                testData = new uint8_t[theSize];
                for( size_t x=0; x<theSize; x++ )
                {
                    testData[x] = x;
                }

                // write the new data in
                cmds++;
                err = deviceWrite( theTarget,
                                   testData,
                                   theSize,
                                   DEVICE_CVPD_ADDRESS(CVPD::VEIR,CVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testCvpdWrite() - failure writing VEIR/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testCvpdWrite() - Failure calling deviceWrite!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
                }

                // verify the data got written
                cmds++;
                verifyData = new uint8_t[theSize];
                err = deviceRead( theTarget,
                                  verifyData,
                                  theSize,
                                  DEVICE_CVPD_ADDRESS(CVPD::VEIR,CVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testCvpdWrite() - failure reading VEIR/#I to verify, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testCvpdWrite() - Failure calling deviceRead!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
                }
                TRACFBIN( g_trac_vpd, "testCvpdWrite() - verif=",
                          verifyData, theSize );

                // compare what we read to what we wrote
                if( memcmp( testData, verifyData, theSize ) )
                {
                    fails++;
                    TRACFBIN( g_trac_vpd, "testCvpdWrite() - wrote=",
                              testData, theSize );
                    TRACFBIN( g_trac_vpd, "testCvpdWrite() - read=",
                              verifyData, theSize );
                    TS_FAIL( "testCvpdWrite - Data mismatch!" );
                }

                // put the original data back to be a good citizen
                cmds++;
                err = deviceWrite( theTarget,
                                   origData,
                                   theSize,
                                   DEVICE_CVPD_ADDRESS(CVPD::VEIR,CVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testCvpdWrite() - failure writing original data back into VEIR/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testCvpdWrite() - Failure calling deviceRead!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
                }

            } while( 0 );

            if( NULL != testData )
            {
                delete[] testData;
                testData = NULL;
            }

            if( NULL != origData )
            {
                delete[] origData;
                origData = NULL;
            }

            if( NULL != verifyData )
            {
                delete[] verifyData;
                verifyData = NULL;
            }

            if( cmds == 0 )
            {
                TS_FAIL("testCvpdWrite - No tests ran, something is wrong...");
            }

            TRACFCOMP( g_trac_vpd,
                       "testCvpdWrite - %d/%d fails",
                       fails, cmds );
#endif
        }

        /**
         * @brief This function will test that an error is generated when a
         *      record is passed in that cannot be found in the structure
         *      that defines the Records string representation.
         */
        void testCvpdInvalidRecord ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testCvpdInvalidRecord()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMembufTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testCvpdInvalidRecord() - No Functional Targets found!");
                    break;
                }


                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_CVPD_ADDRESS( CVPD::CVPD_LAST_RECORD,
                                                       CVPD::pdI ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testCvpdInvalidRecord() - Error expected with "
                             "record of type CVPD_LAST_RECORD (0x%04x), but "
                             "no error returned!",
                             CVPD::CVPD_LAST_RECORD );
                }
                else
                {
                    delete err;
                    err = NULL;
                }

                if( NULL != theData )
                {
                    delete theData;
                    theData = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_vpd,
                       "testCvpdInvalidRecord - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test for a record which is not in the TOC
         *      of the CVPD area.
         */
        void testCvpdMissingRecord ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testCvpdMissingRecord()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMembufTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testCvpdMissingRecord() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_CVPD_ADDRESS( CVPD::CVPD_TEST_RECORD,
                                                       CVPD::pdI ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testCvpdMissingRecord() - ");
                }
                else
                {
                    delete err;
                    err = NULL;
                }

                if( NULL != theData )
                {
                    delete theData;
                    theData = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_vpd,
                       "testCvpdMissingRecord - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test for a keyword that cannot be found
         *      in the expected record
         */
        void testCvpdMissingKeyword ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testCvpdMissingKeyword()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMembufTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testCvpdMissingKeyword() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead(theTarget,
                                 theData,
                                 theSize,
                                 DEVICE_CVPD_ADDRESS(CVPD::CVPD_FIRST_RECORD,
                                                     CVPD::CVPD_TEST_KEYWORD));

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL("testCvpdMissingKeyword() - Expected error from "
                            "invalid Keyword missing from associated record!");
                }
                else
                {
                    delete err;
                    err = NULL;
                }

                if( NULL != theData )
                {
                    delete theData;
                    theData = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_vpd,
                       "testCvpdMissingKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a
         *      keyword is passed in that cannot be found in the structure
         *      that defines the Keywords string representation.
         */
        void testCvpdInvalidKeyword ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testCvpdInvalidKeyword()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMembufTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testCvpdInvalidKeyword() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead(theTarget,
                                 theData,
                                 theSize,
                                 DEVICE_CVPD_ADDRESS(CVPD::VEIR,
                                                     CVPD::CVPD_LAST_KEYWORD));

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testCvpdInvalidKeyword() - Error expected with "
                             "keyword of type CVPD_LAST_KEYWORD (0x%04x), but "
                             "no error returned!",
                             CVPD::CVPD_LAST_KEYWORD );
                }
                else
                {
                    delete err;
                    err = NULL;
                }

                if( NULL != theData )
                {
                    delete theData;
                    theData = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_vpd,
                       "testCvpdInvalidKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a
         *      buffer that has an insufficient size is passed in to read a
         *      record/keyword.
         */
        void testCvpdInvalidBufferSize ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testCvpdInvalidBufferSize()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMembufTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testCvpdInvalidBufferSize() - No Functional Targets found!");
                    break;
                }

                uint8_t * theData = new uint8_t[1];
                size_t theSize = 0;

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_CVPD_ADDRESS( CVPD::VEIR,
                                                       CVPD::pdI ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testCvpdInvalidBufferSize() - Error was expected "
                             "for an invalid size of 0x0 for a CVPD read!" );
                }
                else
                {
                    delete err;
                    err = NULL;
                }

                if( NULL != theData )
                {
                    delete theData;
                    theData = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_vpd,
                       "testCvpdInvalidBufferSize - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test the numerical order of the cvpdRecords
         *      and cvpdKeywords structures.
         */
        void testCvpdCheckStructOrder ( void )
        {
            uint64_t fails = 0x0;
            IpVpdFacade::ipVpdRecord prevRecord = CVPD::CVPD_FIRST_RECORD;
            IpVpdFacade::ipVpdKeyword prevKeyword = CVPD::CVPD_FIRST_KEYWORD;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testCvpdCheckStructOrder()" );

            // Check the cvpdRecords structure for proper order
            uint32_t entry = 0x0;
            for( entry = 0;
                 entry < (sizeof(CVPD::cvpdRecords)/
                          sizeof(CVPD::cvpdRecords[0]));
                 entry++ )
            {
                if( !(CVPD::cvpdRecords[entry].record >= prevRecord) )
                {
                    fails++;
                    TS_FAIL( "testCvpdCheckStructOrder() - Record table out of "
                             "order! Cur Record: 0x%04x, Prev Record: 0x%04x",
                             CVPD::cvpdRecords[entry].record,
                             prevRecord );
                }
                prevRecord = CVPD::cvpdRecords[entry].record;
            }

            // Check the cvpdKeywords structure for proper order
            for( entry = 0;
                 entry < (sizeof(CVPD::cvpdKeywords)/
                          sizeof(CVPD::cvpdKeywords[0]));
                 entry++ )
            {
                if( !(CVPD::cvpdKeywords[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testCvpdCheckStructOrder() - Keyword table out of order! Cur Keyword: 0x%04x, Prev Keyword: 0x%04x",
                             CVPD::cvpdKeywords[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = CVPD::cvpdKeywords[entry].keyword;
            }

            TRACFCOMP( g_trac_vpd,
                       "testCvpdCheckStructOrder - %d fails",
                       fails );
        }
};

#endif
