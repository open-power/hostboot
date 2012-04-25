/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/spd/test/spdtest.H $
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
#ifndef __SPDTEST_H
#define __SPDTEST_H

/**
 *  @file spdtest.H
 *
 *  @brief Test cases for SPD code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/utilFilter.H>

#include <spd/spdreasoncodes.H>
#include <spd/spdenums.H>
#include "../spdDDR3.H"
#include "../spd.H"

extern trace_desc_t* g_trac_spd;

using namespace TARGETING;
using namespace SPD;

void getDIMMTargets ( TargetHandleList & o_dimmList )
{
    // Get Dimm list.
    getAllLogicalCards( o_dimmList,
                        TARGETING::TYPE_DIMM );
    TRACDCOMP( g_trac_spd,
               "getDIMMTargets() - found %d DIMMs",
               o_dimmList.size() );
    return;
}

class SPDTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief This test reads all of the keywords for all of the
         *      DIMMs found.
         */
        void testSpdRead ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdRead()" );

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
                               "testSpdRead - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM.
                theTarget = dimmList[0];
                uint8_t * theData = NULL;
                size_t theSize = 0;
                uint32_t entry = 0x0;

                // Get the DDR revision
                uint8_t memType = 0x0;
                size_t memTypeSize = 0x1;
                err = deviceRead( theTarget,
                                  &memType,
                                  memTypeSize,
                                  DEVICE_SPD_ADDRESS( SPD::BASIC_MEMORY_TYPE ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdRead- Failure reading Basic memory type!" );
                    errlCommit( err,
                                SPD_COMP_ID );
                    break;;
                }

                for( uint64_t keyword = SPD::SPD_FIRST_NORM_KEYWORD;
                     keyword < SPD::SPD_LAST_NORM_KEYWORD; keyword++ )
                {
                    cmds++;
                    if( NULL != theData )
                    {
                        free( theData );
                        theData = NULL;
                    }

                    // Get the required size of the buffer
                    theSize = 0;
                    if( SPD_DDR3 == memType )
                    {
                        for( entry = 0;
                             entry < (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
                             entry++ )
                        {
                            if( keyword == ddr3Data[entry].keyword )
                            {
                                theSize = ddr3Data[entry].length;
                                break;
                            }
                        }
                    }
                    else
                    {
                        // Nothing else supported yet!
                        // Not really a fail, just not supported
                        cmds--;
                        continue;
                    }

                    if( 0x0 == theSize )
                    {
                        fails++;
                        TS_FAIL( "testSpdRead - Keyword (0x%04x) size = 0x0",
                                 entry );
                        continue;
                    }

                    // Allocate the buffer
                    theData = static_cast<uint8_t*>(malloc( theSize ));

                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_SPD_ADDRESS( keyword ) );

                    if( err )
                    {
                        fails++;
                        TS_FAIL( "testSpdRead - Failure on keyword: %04x",
                                 keyword );
                        errlCommit( err,
                                    SPD_COMP_ID );
                        continue;
                    }

                    // Read was successful, print out first byte of data read
                    TRACFCOMP( g_trac_spd,
                               "testSpdRead - kwd: 0x%04x, val: %02x, size: %d",
                               keyword, theData[0], theSize );

                    if( NULL != theData )
                    {
                        free( theData );
                        theData = NULL;
                    }
                }

                if( err )
                {
                    break;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testSpdRead - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief Test a SPD Write
         */
        void testSpdWrite ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdWrite()" );

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
                               "testSpdWrite - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM
                theTarget = dimmList[0];
                uint8_t * theData = NULL;
                size_t theSize = 0;

                cmds++;
                err = deviceWrite( theTarget,
                                   theData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( SPD_FIRST_NORM_KEYWORD ) );

                if( NULL == err )
                {
                    // No error returned, failure
                    fails++;
                    TS_FAIL( "testSpdWrite - No error returned from deviceWrite()" );
                    break;
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testSpdWrite - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief Test an invalid Keyword to a DIMM target.
         */
        void testSpdInvalidKeyword ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdInvalidKeyword()" );

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
                               "testSpdInvalidKeyword - No DIMMs found!" );
                    break;
                }

                // Test on first DIMM only.
                theTarget = dimmList[0];
                uint8_t * theData = NULL;
                size_t theSize = 0x0;

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( SPD::INVALID_SPD_KEYWORD ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testSpdInvalidKeyword - No error returned!" );
                    break;
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testSpdInvalidKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief Test an invalid size for an SPD read.
         */
        void testSpdInvalidSize ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdInvalidSize()" );

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
                               "testSpdInvalidSize - No DIMMs found!" );
                    break;
                }

                // Test on first DIMM only.
                theTarget = dimmList[0];
                uint8_t * theData = NULL;
                size_t theSize = 0x0;   // Invalid size of 0x0

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( SPD::SPD_FIRST_NORM_KEYWORD ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testSpdInvalidSize - No error for invalid size!" );
                    break;
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testSpdInvalidSize - %d/%d fails",
                       fails, cmds );
        }


        /**
         * @brief This test will test reading the Module specific keywords.
         */
        void testspdDDR3ModSpecKwds( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t memType = 0x0;
            uint8_t modType = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testspdDDR3ModSpecKwds()" );

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
                               "testspdDDR3ModSpecKwds - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM.
                theTarget = dimmList[0];
                uint8_t * theData = NULL;
                size_t theSize = 0;
                uint32_t entry = 0x0;

                // Get the DDR revision
                size_t tmpSize = 0x1;
                err = deviceRead( theTarget,
                                  &memType,
                                  tmpSize,
                                  DEVICE_SPD_ADDRESS( SPD::BASIC_MEMORY_TYPE ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testspdDDR3ModSpecKwds- Failure reading Basic "
                             "memory type!" );
                    errlCommit( err,
                                SPD_COMP_ID );
                    break;
                }

                // Get the Module Type
                err = deviceRead( theTarget,
                                  &modType,
                                  tmpSize,
                                  DEVICE_SPD_ADDRESS( SPD::MODULE_TYPE ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testspdDDR3ModSpecKwds - Failure reading Module "
                             "type" );
                    errlCommit( err,
                                SPD_COMP_ID );
                    break;
                }

                // The real Keyword read testing
                for( uint64_t keyword = SPD::SPD_FIRST_MOD_SPEC;
                     keyword < SPD::SPD_LAST_MOD_SPEC; keyword++ )
                {
                    cmds++;
                    if( NULL != theData )
                    {
                        free( theData );
                        theData = NULL;
                    }

                    // Get the required size of the buffer
                    theSize = 0;
                    KeywordData kwdData;
                    if( SPD_DDR3 == memType )
                    {
                        for( entry = 0;
                             entry < (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
                             entry++ )
                        {
                            if( keyword == ddr3Data[entry].keyword )
                            {
                                kwdData = ddr3Data[entry];
                                theSize = ddr3Data[entry].length;
                                break;
                            }
                        }

                        // Check type of module.
                        TRACFCOMP( g_trac_spd,
                                   INFO_MRK"SPD Error traces will follow!!!  "
                                   "Not all module specific keywords will be "
                                   "valid for all types of modules.  IGNORE!!" );
                        err = checkModSpecificKeyword( kwdData,
                                                       memType,
                                                       theTarget );

                        if( err )
                        {
                            // This keyword isn't supported with this module
                            // type
                            cmds--;
                            delete err;
                            err = NULL;
                            continue;
                        }
                    }
                    else
                    {
                        // Nothing else supported yet!
                        // Not really a fail, just not supported
                        cmds--;
                        continue;
                    }

                    if( 0x0 == theSize )
                    {
                        fails++;
                        TS_FAIL( "testspdDDR3ModSpecKwds - Keyword (0x%04x) "
                                 "size = 0x0",
                                 entry );
                        continue;
                    }

                    // Allocate the buffer
                    theData = static_cast<uint8_t*>(malloc( theSize ));
                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_SPD_ADDRESS( keyword ) );

                    if( err )
                    {
                        fails++;
                        TS_FAIL( "testspdDDR3ModSpecKwds - Failure on keywor"
                                 "d: %04x",
                                 keyword );
                        errlCommit( err,
                                    SPD_COMP_ID );
                        continue;
                    }

                    // Read was successful, print out first 2 bytes of data read
                    TRACFCOMP( g_trac_spd,
                               "testspdDDR3ModSpecKwds - kwd: 0x%04x, val: "
                               "%02x, size: %d",
                               keyword, theData[0], theSize );

                    if( NULL != theData )
                    {
                        free( theData );
                        theData = NULL;
                    }
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testspdDDR3ModSpecKwds - %d/%d fails",
                       fails, cmds );
        }


        /**
         * @brief This test will ensure that the DDR3 lookup table is in a sorted
         *      order, according to the keyword enumeration, to enable the search
         *      algorithm to work correctly.
         */
        void testspdDDR3TableOrder( void )
        {
            uint64_t prevKeyword = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testspdDDR3TableOrder()" );

            for( uint32_t entry = 0;
                 entry < (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
                 entry++ )
            {
                if( !(ddr3Data[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testspdDDR3TableOrder - DDR3 table out of order!  Cur kwd: "
                             "0x%04x, Pre kwd: 0x%04x",
                             ddr3Data[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = ddr3Data[entry].keyword;
            }

            TRACFCOMP( g_trac_spd,
                       EXIT_MRK"testspdDDR3TableOrder() - fails: %d",
                       fails );
        }


};

#endif
