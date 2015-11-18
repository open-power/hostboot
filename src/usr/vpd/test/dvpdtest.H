/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/test/dvpdtest.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef __DVPDTEST_H
#define __DVPDTEST_H

/**
 *  @file dvpdtest.H
 *
 *  @brief Test cases for DVPD code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <targeting/common/predicates/predicatectm.H>

#include <vpd/dvpdenums.H>
#include <vpd/vpdreasoncodes.H>
#include "../dvpd.H"
#include "../ipvpd.H"

extern trace_desc_t* g_trac_vpd;

using namespace TARGETING;

/**
 * @brief Structure to define record/keyword pairs for DVPD tests.
 */
struct dvpdTestData
{
    VPD::vpdRecord record;
    VPD::vpdRecord keyword;
};

/**
 * @brief Data sample to be used for DVPD testing.
 */
dvpdTestData dvpdData[] =
{
    { DVPD::VEIR, DVPD::pdI },
    { DVPD::MER0, DVPD::pdI },
    { DVPD::VSPD, DVPD::pdI },
    { DVPD::VSPD, DVPD::MT },
    { DVPD::VSPD, DVPD::MR },
    { DVPD::VSPD, DVPD::pdA },
    { DVPD::VSPD, DVPD::EL },
    { DVPD::VSPD, DVPD::LM },
    { DVPD::VSPD, DVPD::MW },
    { DVPD::VSPD, DVPD::MV },
    { DVPD::VSPD, DVPD::AM },
    { DVPD::VINI, DVPD::VZ },
    { DVPD::VSPD, DVPD::MX },

};

TARGETING::Target* getFunctionalMcsTarget()
{
    TARGETING::Target * theTarget = NULL;
    TRACDCOMP( g_trac_vpd,
               "getFunctionalMcsTarget() - Finding a functional MCS" );

    // Get a list of functional MCS targets
    TargetHandleList mcsList;
    getAllChiplets(mcsList,TARGETING::TYPE_MCS);

    if( mcsList.size() )
    {
        theTarget = mcsList[0];
    }

    return theTarget;
}

class DVPDTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief This function will test DVPD reads.
         */
        void testDvpdRead ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint64_t theRecord = 0x0;
            uint64_t theKeyword = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testDvpdRead()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMcsTarget();
                if(theTarget == NULL)
                {
                    TRACFCOMP(g_trac_vpd,
                              "testDvpdRead() - No Functional Targets found!");
                    break;
                }

                uint8_t * theData = NULL;
                size_t theSize = 0;
                const uint32_t numCmds = sizeof(dvpdData)/sizeof(dvpdData[0]);
                for( uint32_t curCmd = 0; curCmd < numCmds; curCmd++ )
                {
                    cmds++;
                    theRecord = (uint64_t)dvpdData[curCmd].record;
                    theKeyword = (uint64_t)dvpdData[curCmd].keyword;
                    err = deviceRead( theTarget,
                                      NULL,
                                      theSize,
                                      DEVICE_DVPD_ADDRESS( theRecord,
                                                           theKeyword ) );

                    if( err )
                    {
                        fails++;
                        TRACFCOMP( g_trac_vpd,
                                   ERR_MRK"testDvpdRead() - failure reading "
                                   "keyword size!!  rec: 0x%04x, kwd: 0x%04x",
                                   theRecord,
                                   theKeyword );
                        TS_FAIL( "testDvpdRead() - "
                                 "Failure reading keyword size!" );
                        errlCommit( err,
                                    VPD_COMP_ID );
                        continue;
                    }

                    theData = static_cast<uint8_t*>(malloc( theSize ));

                    // Read record/keyword pair
                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_DVPD_ADDRESS( theRecord,
                                                           theKeyword ) );

                    if( err )
                    {
                        fails++;
                        TRACFCOMP( g_trac_vpd,
                                   ERR_MRK"testDvpdRead() - Failure on Record: "
                                   "0x%04x, keyword: 0x%04x, of size: 0x%04x "
                                   "- test %d",
                                   theRecord,
                                   theKeyword,
                                   theSize, curCmd );
                        TS_FAIL( "testDvpdRead() - Failure during DVPD read!" );
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
                               INFO_MRK"testDvpdRead Results:" );
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
                       "testDvpdRead - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test DVPD writes.
         */
        void testDvpdWrite ( void )
        {
#ifndef __HOSTBOOT_RUNTIME
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t* testData = NULL;
            uint8_t* origData = NULL;
            uint8_t* verifyData = NULL;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testDvpdWrite()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMcsTarget();
                if(theTarget == NULL)
                {
                    TRACFCOMP(g_trac_vpd,
                            "testDvpdWrite() - No Functional Targets found!");
                    break;
                }

                // first figure out how big the keyword is
                cmds++;
                size_t theSize = 0;
                err = deviceRead( theTarget,
                                  testData,
                                  theSize,
                                  DEVICE_DVPD_ADDRESS(DVPD::VEIR,DVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testDvpdWrite() - "
                                     "failure getting size of VEIR/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testDvpdWrite() - Failure calling deviceRead!" );
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
                                  DEVICE_DVPD_ADDRESS(DVPD::VEIR,DVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testDvpdWrite() - "
                                      "failure reading VEIR/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testDvpdWrite() - Failure calling deviceRead!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
                }
                TRACFBIN( g_trac_vpd, "testDvpdWrite() - orig=",
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
                                   DEVICE_DVPD_ADDRESS(DVPD::VEIR,DVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testDvpdWrite() - "
                                      "failure writing VEIR/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testDvpdWrite() - Failure calling deviceWrite!" );
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
                                  DEVICE_DVPD_ADDRESS(DVPD::VEIR,DVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testDvpdWrite() - "
                                   "failure reading VEIR/#I to verify, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testDvpdWrite() - Failure calling deviceRead!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
                }
                TRACFBIN( g_trac_vpd, "testDvpdWrite() - verif=",
                          verifyData, theSize );

                // compare what we read to what we wrote
                if( memcmp( testData, verifyData, theSize ) )
                {
                    fails++;
                    TRACFBIN( g_trac_vpd, "testDvpdWrite() - wrote=",
                              testData, theSize );
                    TRACFBIN( g_trac_vpd, "testDvpdWrite() - read=",
                              verifyData, theSize );
                    TS_FAIL( "testDvpdWrite - Data mismatch!" );
                }

                // put the original data back to be a good citizen
                cmds++;
                err = deviceWrite( theTarget,
                                   origData,
                                   theSize,
                                   DEVICE_DVPD_ADDRESS(DVPD::VEIR,DVPD::pdI) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testDvpdWrite() - "
                     "failure writing original data back into VEIR/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testDvpdWrite() - Failure calling deviceRead!" );
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
                TRACFCOMP(g_trac_vpd, "testDvpdWrite - No tests ran, something is wrong...");
            }

            TRACFCOMP( g_trac_vpd,
                       "testDvpdWrite - %d/%d fails",
                       fails, cmds );
#endif
        }

        /**
         * @brief This function will test that an error is generated when a
         *      record is passed in that cannot be found in the structure
         *      that defines the Records string representation.
         */
        void testDvpdInvalidRecord ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testDvpdInvalidRecord()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMcsTarget();
                if(theTarget == NULL)
                {
                    TRACFCOMP(g_trac_vpd, "testDvpdInvalidRecord() No Functional Targets found!");
                    break;
                }


                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_DVPD_ADDRESS( DVPD::DVPD_LAST_RECORD,
                                                       DVPD::pdI ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testDvpdInvalidRecord() - Error expected with "
                             "record of type DVPD_LAST_RECORD (0x%04x), but "
                             "no error returned!",
                             DVPD::DVPD_LAST_RECORD );
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
                       "testDvpdInvalidRecord - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test for a record which is not in the TOC
         *      of the DVPD area.
         */
        void testDvpdMissingRecord ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testDvpdMissingRecord()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMcsTarget();
                if(theTarget == NULL)
                {
                    TRACFCOMP(g_trac_vpd, "testDvpdMissingRecord() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_DVPD_ADDRESS( DVPD::DVPD_TEST_RECORD,
                                                       DVPD::pdI ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testDvpdMissingRecord() - ");
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
                       "testDvpdMissingRecord - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test for a keyword that cannot be found
         *      in the expected record
         */
        void testDvpdMissingKeyword ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testDvpdMissingKeyword()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMcsTarget();
                if(theTarget == NULL)
                {
                    TRACFCOMP(g_trac_vpd, "testDvpdMissingKeyword() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead(theTarget,
                                 theData,
                                 theSize,
                                 DEVICE_DVPD_ADDRESS(DVPD::DVPD_FIRST_RECORD,
                                                     DVPD::DVPD_TEST_KEYWORD));

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL("testDvpdMissingKeyword() - Expected error from "
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
                       "testDvpdMissingKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a
         *      keyword is passed in that cannot be found in the structure
         *      that defines the Keywords string representation.
         */
        void testDvpdInvalidKeyword ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testDvpdInvalidKeyword()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMcsTarget();
                if(theTarget == NULL)
                {
                    TRACFCOMP(g_trac_vpd, "testDvpdInvalidKeyword() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead(theTarget,
                                 theData,
                                 theSize,
                                 DEVICE_DVPD_ADDRESS(DVPD::VEIR,
                                                     DVPD::DVPD_LAST_KEYWORD));

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testDvpdInvalidKeyword() - Error expected with "
                             "keyword of type DVPD_LAST_KEYWORD (0x%04x), but "
                             "no error returned!",
                             DVPD::DVPD_LAST_KEYWORD );
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
                       "testDvpdInvalidKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a
         *      buffer that has an insufficient size is passed in to read a
         *      record/keyword.
         */
        void testDvpdInvalidBufferSize ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testDvpdInvalidBufferSize()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalMcsTarget();
                if(theTarget == NULL)
                {
                    TRACFCOMP(g_trac_vpd, "testDvpdInvalidBufferSize() - No Functional Targets found!");
                    break;
                }

                uint8_t * theData = new uint8_t[1];
                size_t theSize = 0;

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_DVPD_ADDRESS( DVPD::VEIR,
                                                       DVPD::pdI ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testDvpdInvalidBufferSize() - Error was expected "
                             "for an invalid size of 0x0 for a DVPD read!" );
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
                       "testDvpdInvalidBufferSize - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test the numerical order of the dvpdRecords
         *      and dvpdKeywords structures.
         */
        void testDvpdCheckStructOrder ( void )
        {
            uint64_t fails = 0x0;
            VPD::vpdRecord prevRecord = DVPD::DVPD_FIRST_RECORD;
            VPD::vpdKeyword prevKeyword = DVPD::DVPD_FIRST_KEYWORD;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testDvpdCheckStructOrder()" );

            // Check the dvpdRecords structure for proper order
            uint32_t entry = 0x0;
            for( entry = 0;
                 entry < (sizeof(DVPD::dvpdRecords)/
                          sizeof(DVPD::dvpdRecords[0]));
                 entry++ )
            {
                if( !(DVPD::dvpdRecords[entry].record >= prevRecord) )
                {
                    fails++;
                    TS_FAIL( "testDvpdCheckStructOrder() - Record table out of "
                             "order! Cur Record: 0x%04x, Prev Record: 0x%04x",
                             DVPD::dvpdRecords[entry].record,
                             prevRecord );
                }
                prevRecord = DVPD::dvpdRecords[entry].record;
            }

            // Check the dvpdKeywords structure for proper order
            for( entry = 0;
                 entry < (sizeof(DVPD::dvpdKeywords)/
                          sizeof(DVPD::dvpdKeywords[0]));
                 entry++ )
            {
                if( !(DVPD::dvpdKeywords[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testDvpdCheckStructOrder() - "
       "Keyword table out of order! Cur Keyword: 0x%04x, Prev Keyword: 0x%04x",
                             DVPD::dvpdKeywords[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = DVPD::dvpdKeywords[entry].keyword;
            }

            TRACFCOMP( g_trac_vpd,
                       "testDvpdCheckStructOrder - %d fails",
                       fails );
        }
};

#endif
