//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/mvpd/test/mvpdtest.H $
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

    // NOTE: current sizes will be based off of dummy data that we have
    // now plus approximately 10% as a buffer for future growth.  These
    // may need to be tweaked later.
    size_t size;
};

/**
 * @brief Data sample to be used for MVPD testing.
 *      NOTE: By reading this entire list, it also validates that the records
 *      and keywords that we expect to be there are actually there...
 */
mvpdTestData mvpdData[] =
{
    { CRP0, VD,     0x04 },
    { CRP0, ED,     0x23 },
    { CRP0, TE,     0x13 },
    { CRP0, DD,     0x07 },
    { CRP0, pdP,    0x150 },
    { CRP0, ST,     0x05 },
//    { CRP0, DN,     0x03 }, // TODO - This doesn't match documentation,
//                                      pulling out for now
    { CP00, VD,     0x04 },
    { CP00, PG,     0x44 },
    { CP00, PK,     0x45 },
    { CP00, pdR,    0x5f90 },
    { CP00, pdV,    0x130 },
    { CP00, pdH,    0x190 },
    { CP00, pdP,    0x1c0 },
    { CP00, SB,     0x15 },
    { LRP0, VD,     0x04 },
    { LRP0, pdV,    0x150 },
    { LRP0, pdP,    0x380 },
    { LRP0, pdM,    0x220},
    { LRP1, VD,     0x04 },
    { LRP1, pdV,    0x150 },
    { LRP1, pdP,    0x380 },
    { LRP1, pdM,    0x220},
    { LRP2, VD,     0x04 },
    { LRP2, pdV,    0x150 },
    { LRP2, pdP,    0x380 },
    { LRP2, pdM,    0x220},
    { LRP3, VD,     0x04 },
    { LRP3, pdV,    0x150 },
    { LRP3, pdP,    0x380 },
    { LRP3, pdM,    0x220},
    { LRP4, VD,     0x04 },
    { LRP4, pdV,    0x150 },
    { LRP4, pdP,    0x380 },
    { LRP4, pdM,    0x220},
    { LRP5, VD,     0x04 },
    { LRP5, pdV,    0x150 },
    { LRP5, pdP,    0x380 },
    { LRP5, pdM,    0x220},
    { LRP6, VD,     0x04 },
    { LRP6, pdV,    0x150 },
    { LRP6, pdP,    0x380 },
    { LRP6, pdM,    0x220},
    { LRP7, VD,     0x04 },
    { LRP7, pdV,    0x150 },
    { LRP7, pdP,    0x380 },
    { LRP7, pdM,    0x220},
    { LRP8, VD,     0x04 },
    { LRP8, pdV,    0x150 },
    { LRP8, pdP,    0x380 },
    { LRP8, pdM,    0x220},
    { LRP9, VD,     0x04 },
    { LRP9, pdV,    0x150 },
    { LRP9, pdP,    0x380 },
    { LRP9, pdM,    0x220},
    { LRPA, VD,     0x04 },
    { LRPA, pdV,    0x150 },
    { LRPA, pdP,    0x380 },
    { LRPA, pdM,    0x220},
    { LRPB, VD,     0x04 },
    { LRPB, pdV,    0x150 },
    { LRPB, pdP,    0x380 },
    { LRPB, pdM,    0x220},
    { LWP0, VD,     0x04 },
    { LWP0, pd2,    0x60 },
    { LWP0, pd3,    0x60 },
    { LWP0, IN,     0x19 },
    { LWP1, VD,     0x04 },
    { LWP1, pd2,    0x60 },
    { LWP1, pd3,    0x60 },
    { LWP1, IN,     0x19 },
    { LWP2, VD,     0x04 },
    { LWP2, pd2,    0x60 },
    { LWP2, pd3,    0x60 },
    { LWP2, IN,     0x19 },
    { LWP3, VD,     0x04 },
    { LWP3, pd2,    0x60 },
    { LWP3, pd3,    0x60 },
    { LWP3, IN,     0x19 },
    { LWP4, VD,     0x04 },
    { LWP4, pd2,    0x60 },
    { LWP4, pd3,    0x60 },
    { LWP4, IN,     0x19 },
    { LWP5, VD,     0x04 },
    { LWP5, pd2,    0x60 },
    { LWP5, pd3,    0x60 },
    { LWP5, IN,     0x19 },
    { LWP6, VD,     0x04 },
    { LWP6, pd2,    0x60 },
    { LWP6, pd3,    0x60 },
    { LWP6, IN,     0x19 },
    { LWP7, VD,     0x04 },
    { LWP7, pd2,    0x60 },
    { LWP7, pd3,    0x60 },
    { LWP7, IN,     0x19 },
    { LWP8, VD,     0x04 },
    { LWP8, pd2,    0x60 },
    { LWP8, pd3,    0x60 },
    { LWP8, IN,     0x19 },
    { LWP9, VD,     0x04 },
    { LWP9, pd2,    0x60 },
    { LWP9, pd3,    0x60 },
    { LWP9, IN,     0x19 },
    { LWPA, VD,     0x04 },
    { LWPA, pd2,    0x60 },
    { LWPA, pd3,    0x60 },
    { LWPA, IN,     0x19 },
    { LWPB, VD,     0x04 },
    { LWPB, pd2,    0x60 },
    { LWPB, pd3,    0x60 },
    { LWPB, IN,     0x19 },
    { VINI, DR,     0x12 },
    { VINI, VZ,     0x04 },
    { VINI, CC,     0x06 },
    { VINI, CE,     0x03 },
    { VINI, FN,     0x09 },
    { VINI, PN,     0x09 },
    { VINI, SN,     0x0f },
    { VINI, PR,     0x0a },
    { VINI, HE,     0x06 },
    { VINI, CT,     0x06 },
    { VINI, HW,     0x04 },
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
                    theSize = mvpdData[curCmd].size;
                    theData = static_cast<uint8_t*>(malloc( theSize ));

                    // Read record/keyword pair
                    cmds++;
                    theRecord = (uint64_t)mvpdData[curCmd].record;
                    theKeyword = (uint64_t)mvpdData[curCmd].keyword;
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
                                   mvpdData[curCmd].record,
                                   mvpdData[curCmd].keyword,
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
                               "testMvpdRead() - Proc Target [0] non functional!" );

                    continue;  // add continue because target is non functional
                } 

                uint8_t * theData = NULL;
                size_t theSize = 0;

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
                               "testMvpdRead() - Proc Target [0] non functional!" );

                    continue;  // add continue because target is non functional
                } 

                uint8_t * theData = NULL;
                size_t theSize = 0;

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
                               "testMvpdRead() - Proc Target [0] non functional!" );

                    continue;  // add continue because target is non functional
                } 

                uint8_t * theData = NULL;
                size_t theSize = 0;

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
                               "testMvpdRead() - Proc Target [0] non functional!" );

                    continue;  // add continue because target is non functional
                } 

                uint8_t * theData = NULL;
                size_t theSize = 0;

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
                               "testMvpdRead() - Proc Target [0] non functional!" );

                    continue;  // add continue because target is non functional
                } 

                uint8_t * theData = NULL;
                size_t theSize = 0;

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
                               "testMvpdRead() - Proc Target [0] non functional!" );

                    continue;  // add continue because target is non functional
                } 

                uint8_t * theData = NULL;
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
