/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/mvpd/test/mvpdtest.H $
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
#ifndef __MVPDTEST_H
#define __MVPDTEST_H

/**
 *  @file mvpdtest.H
 *
 *  @brief Test cases for MVPD code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <targeting/common/predicates/predicatectm.H>

#include <mvpd/mvpdenums.H>
#include <mvpd/mvpdreasoncodes.H>
#include "../mvpd.H"


extern trace_desc_t* g_trac_mvpd;

using namespace TARGETING;
using namespace MVPD;

/**
 * @brief Structure to define record/keyword pairs for MVPD tests.
 */
struct mvpdTestData
{
    mvpdRecord record;
    mvpdKeyword keyword;
};

/**
 * @brief Data sample to be used for MVPD testing.
 *      NOTE: By reading this entire list, it also validates that the records
 *      and keywords that we expect to be there are actually there...
 */
mvpdTestData mvpdData[] =
{
    { CRP0, VD },
    { CRP0, ED },
    { CRP0, TE },
    { CRP0, DD },
//    { CRP0, pdP }, // TODO - no #P in test data, pull for now RTC 51716
    { CRP0, ST },
//    { CRP0, DN,     0x03 }, // TODO - This doesn't match documentation,
//                                      pulling out for now
    { CP00, VD },
    { CP00, PG },
//    { CP00, PK }, // TODO - no PK in test data. pull for now RTC 51716
    { CP00, pdR },
    { CP00, pdG },
    { CP00, pdV },
    { CP00, pdH },
//    { CP00, pdP }, // TODO - no #P in test data, pull for now RTC 51716
    { CP00, SB },
/*                   // TODO no LRP0,LRP1,LRP2,LRP3 in test data, pull for now RTC 51716
    { LRP0, VD },
    { LRP0, pdV },
    { LRP0, pdP },
    { LRP0, pdM },
    { LRP1, VD },
    { LRP1, pdV },
    { LRP1, pdP },
    { LRP1, pdM },
    { LRP2, VD },
    { LRP2, pdV },
    { LRP2, pdP },
    { LRP2, pdM },
    { LRP3, VD },
    { LRP3, pdV },
    { LRP3, pdP },
    { LRP3, pdM },
*/
    { LRP4, VD },
    { LRP4, pdV },
    { LRP4, pdP },
    { LRP4, pdM },
    { LRP5, VD },
    { LRP5, pdV },
    { LRP5, pdP },
    { LRP5, pdM },
    { LRP6, VD },
    { LRP6, pdV },
    { LRP6, pdP },
    { LRP6, pdM },
/*                   // TODO no LRP7,LRP8,LRP9,LRPA,LRPB,LWPO,LWP1,LWP2,LWP3 in test data, pull for now RTC 51716
    { LRP7, VD },
    { LRP7, pdV },
    { LRP7, pdP },
    { LRP7, pdM },
    { LRP8, VD },
    { LRP8, pdV },
    { LRP8, pdP },
    { LRP8, pdM },
    { LRP9, VD },
    { LRP9, pdV },
    { LRP9, pdP },
    { LRP9, pdM },
    { LRPA, VD },
    { LRPA, pdV },
    { LRPA, pdP },
    { LRPA, pdM },
    { LRPB, VD },
    { LRPB, pdV },
    { LRPB, pdP },
    { LRPB, pdM },
    { LWP0, VD },
    { LWP0, pd2 },
    { LWP0, pd3 },
    { LWP0, IN },
    { LWP1, VD },
    { LWP1, pd2 },
    { LWP1, pd3 },
    { LWP1, IN },
    { LWP2, VD },
    { LWP2, pd2 },
    { LWP2, pd3 },
    { LWP2, IN },
    { LWP3, VD },
    { LWP3, pd2 },
    { LWP3, pd3 },
    { LWP3, IN },
*/
    { LWP4, VD },
    { LWP4, pd2 },
    { LWP4, pd3 },
    { LWP4, IN },
    { LWP5, VD },
    { LWP5, pd2 },
    { LWP5, pd3 },
    { LWP5, IN },
    { LWP6, VD },
    { LWP6, pd2 },
    { LWP6, pd3 },
    { LWP6, IN },
/*                 // TODO no LWP7,LWP8,LWP9,LWPA,LWPB in test data, pull for now RTC 51716
    { LWP7, VD },
    { LWP7, pd2 },
    { LWP7, pd3 },
    { LWP7, IN },
    { LWP8, VD },
    { LWP8, pd2 },
    { LWP8, pd3 },
    { LWP8, IN },
    { LWP9, VD },
    { LWP9, pd2 },
    { LWP9, pd3 },
    { LWP9, IN },
    { LWPA, VD },
    { LWPA, pd2 },
    { LWPA, pd3 },
    { LWPA, IN },
    { LWPB, VD },
    { LWPB, pd2 },
    { LWPB, pd3 },
    { LWPB, IN },
*/
    { VINI, DR },
    { VINI, VZ },
    { VINI, CC },
    { VINI, CE },
    { VINI, FN },
    { VINI, PN },
    { VINI, SN },
    { VINI, PR },
    { VINI, HE },
    { VINI, CT },
    { VINI, HW },
    // TODO - Add VWML when available.
};

void getProcTargets( TargetHandleList & o_procList )
{
    // Get top level system target
    TARGETING::TargetService & tS = TARGETING::targetService();
    TARGETING::Target * sysTarget = NULL;
    tS.getTopLevelTarget( sysTarget );
    assert( sysTarget != NULL );

    // Get a Proc Target
    TARGETING::PredicateCTM predProc( TARGETING::CLASS_CHIP,
                                      TARGETING::TYPE_PROC );
    tS.getAssociated( o_procList,
                      sysTarget,
                      TARGETING::TargetService::CHILD,
                      TARGETING::TargetService::ALL,
                      &predProc );

    TRACDCOMP( g_trac_mvpd,
               "getProcTargets() - found %d Processors",
               o_procList.size() );

    return;
}

class MVPDTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief This function will test MVPD reads.
         */
        void testMvpdRead ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint64_t theRecord = 0x0;
            uint64_t theKeyword = 0x0;

            TRACFCOMP( g_trac_mvpd,
                       ENTER_MRK"testMvpdRead()" );

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get the processor targets
                TargetHandleList procList;
                getProcTargets( procList );

                if( ( 0 == procList.size() ) ||
                    ( NULL == procList[0] ) )
                {
                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdRead() - No Proc Targets found!" );

                    continue;  // add continue because have no proc targets
                }

                // Use the first Proc in the list
                theTarget = procList[0];

                // check to see if the target is functional
                if
                    (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {

                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdRead() - Proc Target [0] non functional!" );

                    continue;  // add continue because target is non functional
                }

                uint8_t * theData = NULL;
                size_t theSize = 0;
                const uint32_t numCmds = sizeof(mvpdData)/sizeof(mvpdData[0]);
                for( uint32_t curCmd = 0; curCmd < numCmds; curCmd++ )
                {
                    cmds++;
                    theRecord = (uint64_t)mvpdData[curCmd].record;
                    theKeyword = (uint64_t)mvpdData[curCmd].keyword;
                    err = deviceRead( theTarget,
                                      NULL,
                                      theSize,
                                      DEVICE_MVPD_ADDRESS( theRecord,
                                                           theKeyword ) );

                    if( err )
                    {
                        fails++;
                        TRACFCOMP( g_trac_mvpd,
                                   ERR_MRK"testMvpdRead() - failure reading "
                                   "keyword size!!  rec: 0x%04x, kwd: 0x%04x",
                                   theRecord,
                                   theKeyword );
                        TS_FAIL( "testMvpdRead() - Failure reading keyword size!" );
                        errlCommit( err,
                                    MVPD_COMP_ID );
                        continue;
                    }

                    theData = static_cast<uint8_t*>(malloc( theSize ));

                    // Read record/keyword pair
                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_MVPD_ADDRESS( theRecord,
                                                           theKeyword ) );

                    if( err )
                    {
                        fails++;
                        TRACFCOMP( g_trac_mvpd,
                                   ERR_MRK"testMvpdRead() - Failure on Record: "
                                   "0x%04x, keyword: 0x%04x, of size: 0x%04x "
                                   "- test %d",
                                   theRecord,
                                   theKeyword,
                                   theSize, curCmd );
                        TS_FAIL( "testMvpdRead() - Failure during MVPD read!" );
                        errlCommit( err,
                                    MVPD_COMP_ID );

                        // Free the data
                        if( NULL != theData )
                        {
                            free( theData );
                            theData = NULL;
                        }
                        continue;
                    }

                    TRACDCOMP( g_trac_mvpd,
                               INFO_MRK"testMvpdRead Results:" );
                    for( uint32_t i = 0; i < theSize; i++ )
                    {
                        TRACDCOMP( g_trac_mvpd,
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

            TRACFCOMP( g_trac_mvpd,
                       "testMvpdRead - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test MVPD writes.
         */
        void testMvpdWrite ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_mvpd,
                       ENTER_MRK"testMvpdWrite()" );

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get the processor targets
                TargetHandleList procList;
                getProcTargets( procList );

                if( ( 0 == procList.size() ) ||
                    ( NULL == procList[0] ) )
                {
                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdWrite() - No Proc Targets found!" );

                    continue; // no proc targets.
                }

                // Use the first Proc in the list
                theTarget = procList[0];

                // check to see if the target is functional
                if
                    (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {

                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdWrite() - Proc Target [0] non functional!" );

                    continue;  // add continue because target is non functional
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceWrite( theTarget,
                                   theData,
                                   theSize,
                                   DEVICE_MVPD_ADDRESS( CRP0,
                                                        pdP ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testMvpdWrite - Expected error from write "
                             "attempt since its not supported!" );
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

            TRACFCOMP( g_trac_mvpd,
                       "testMvpdWrite - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a record
         *      is passed in that cannot be found in the structure that defines the
         *      Records string representation.
         */
        void testMvpdInvalidRecord ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_mvpd,
                       ENTER_MRK"testMvpdInvalidRecord()" );

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get the processor targets
                TargetHandleList procList;
                getProcTargets( procList );

                if( ( 0 == procList.size() ) ||
                    ( NULL == procList[0] ) )
                {
                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdInvalidRecord() - No Proc Targets "
                               "found!" );

                    continue;
                }

                // Use the first Proc in the list
                theTarget = procList[0];

                // check to see if the target is functional
                if
                    (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {

                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdInvalidRecord() - Proc Target [0] non "
                               "functional!" );

                    continue;  // add continue because target is non functional
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS( MVPD_LAST_RECORD,
                                                       pdP ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testMvpdInvalidRecord() - Error expected with "
                             "record of type MVPD_LAST_RECORD (0x%04x), but "
                             "no error returned!",
                             MVPD_LAST_RECORD );
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

            TRACFCOMP( g_trac_mvpd,
                       "testMvpdInvalidRecord - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test for a record which is not in the TOC of
         *      the MVPD area.
         */
        void testMvpdMissingRecord ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_mvpd,
                       ENTER_MRK"testMvpdMissingRecord()" );

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get the processor targets
                TargetHandleList procList;
                getProcTargets( procList );

                if( ( 0 == procList.size() ) ||
                    ( NULL == procList[0] ) )
                {
                    TRACFCOMP( g_trac_mvpd,

                               "testMvpdMissingRecord() - No Proc Targets found!" );

                     continue;
                }

                // Use the first Proc in the list
                theTarget = procList[0];

                // check to see if the target is functional
                if
                    (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {

                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdMissingRecord() - Proc Target [0] "
                               "non functional!" );

                    continue;  // add continue because target is non functional
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS( MVPD_TEST_RECORD,
                                                       pdP ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testMvpdMissingRecord() - ");
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

            TRACFCOMP( g_trac_mvpd,
                       "testMvpdMissingRecord - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test for a keyword that cannot be found
         *      in the expected record
         */
        void testMvpdMissingKeyword ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_mvpd,
                       ENTER_MRK"testMvpdMissingKeyword()" );

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get the processor targets
                TargetHandleList procList;
                getProcTargets( procList );

                if( ( 0 == procList.size() ) ||
                    ( NULL == procList[0] ) )
                {
                    TRACFCOMP( g_trac_mvpd,

                               "testMvpdMissingKeyword() - No Proc Targets found!" );

                    continue;
                }

                // Use the first Proc in the list
                theTarget = procList[0];

                // check to see if the target is functional
                if
                    (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {

                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdMissingKeyword() - Proc Target [0] "
                               "non functional!" );

                    continue;  // add continue because target is non functional
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS( MVPD_FIRST_RECORD,
                                                       MVPD_TEST_KEYWORD ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testMvpdMissingKeyword() - Expected error from "
                             "invalid Keyword missing from associated record!" );
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

            TRACFCOMP( g_trac_mvpd,
                       "testMvpdMissingKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a keyword
         *      is passed in that cannot be found in the structure that defines the
         *      Keywords string representation.
         */
        void testMvpdInvalidKeyword ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_mvpd,
                       ENTER_MRK"testMvpdInvalidKeyword()" );

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get the processor targets
                TargetHandleList procList;
                getProcTargets( procList );

                if( ( 0 == procList.size() ) ||
                    ( NULL == procList[0] ) )
                {
                    TRACFCOMP( g_trac_mvpd,

                               "testMvpdInvalidKeyword() - No Proc Targets found!" );

                    continue;
                }

                // Use the first Proc in the list
                theTarget = procList[0];

                // check to see if the target is functional
                if
                    (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {

                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdInvalidKeyword() - Proc Target [0] "
                               "non functional!" );

                    continue;  // add continue because target is non functional
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS( CRP0,
                                                       MVPD_LAST_KEYWORD ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testMvpdInvalidKeyword() - Error expected with "
                             "keyword of type MVPD_LAST_KEYWORD (0x%04x), but "
                             "no error returned!",
                             MVPD_LAST_KEYWORD );
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

            TRACFCOMP( g_trac_mvpd,
                       "testMvpdInvalidKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a buffer
         *      that has an insufficient size is passed in to read a record/keyword.
         */
        void testMvpdInvalidBufferSize ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_mvpd,
                       ENTER_MRK"testMvpdInvalidBufferSize()" );

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get the processor targets
                TargetHandleList procList;
                getProcTargets( procList );

                if( ( 0 == procList.size() ) ||
                    ( NULL == procList[0] ) )
                {
                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdInvalidBufferSize() - No Proc Targets "
                               "found!" );

                     continue;
                }

                // Use the first Proc in the list
                theTarget = procList[0];

                // check to see if the target is functional
                if
                    (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {

                    TRACFCOMP( g_trac_mvpd,
                               "testMvpdInvalidBufferSize() - Proc Target [0] "
                               "non functional!" );

                    continue;  // add continue because target is non functional
                }

                uint8_t * theData = new uint8_t[1];
                size_t theSize = 0;

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS( CRP0,
                                                       DD ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testMvpdInvalidBufferSize() - Error was expected "
                             "for an invalid size of 0x0 for a MVPD read!" );
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

            TRACFCOMP( g_trac_mvpd,
                       "testMvpdInvalidBufferSize - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test the numerical order of the mvpdRecords
         *      and mvpdKeywords structures.
         */
        void testMvpdCheckStructOrder ( void )
        {
            uint64_t fails = 0x0;
            mvpdRecord prevRecord = MVPD_FIRST_RECORD;
            mvpdKeyword prevKeyword = MVPD_FIRST_KEYWORD;

            TRACFCOMP( g_trac_mvpd,
                       ENTER_MRK"testMvpdCheckStructOrder()" );

            // Check the mvpdRecords structure for proper order
            uint32_t entry = 0x0;
            for( entry = 0;
                 entry < (sizeof(mvpdRecords)/sizeof(mvpdRecords[0]));
                 entry++ )
            {
                if( !(mvpdRecords[entry].record >= prevRecord) )
                {
                    fails++;
                    TS_FAIL( "testMvpdCheckStructOrder() - Record table out of "
                             "order! Cur Record: 0x%04x, Prev Record: 0x%04x",
                             mvpdRecords[entry].record,
                             prevRecord );
                }
                prevRecord = mvpdRecords[entry].record;
            }

            // Check the mvpdKeywords structure for proper order
            for( entry = 0;
                 entry < (sizeof(mvpdKeywords)/sizeof(mvpdKeywords[0]));
                 entry++ )
            {
                if( !(mvpdKeywords[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testMvpdCheckStructOrder() - Keyword table out of "
                             "order! Cur Keyword: 0x%04x, Prev Keyword: 0x%04x",
                             mvpdKeywords[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = mvpdKeywords[entry].keyword;
            }

            TRACFCOMP( g_trac_mvpd,
                       "testMvpdCheckStructOrder - %d fails",
                       fails );
        }

};

#endif
