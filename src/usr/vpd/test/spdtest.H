/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/test/spdtest.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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

#include <vpd/vpdreasoncodes.H>
#include <vpd/spdenums.H>
#include "../spdDDR3.H"
#include "../spdDDR4.H"
#include "../spdDDR4_DDIMM.H"
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

errlHndl_t getMemType( TARGETING::Target * i_target,
                 uint8_t & i_memType )
{
    errlHndl_t err = NULL;
    size_t theSize = 0x1;
    err = deviceRead( i_target,
                      &i_memType,
                      theSize,
                      DEVICE_SPD_ADDRESS( SPD::BASIC_MEMORY_TYPE ) );

    return err;
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
            uint8_t * theData = NULL;

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
                size_t theSize = 0;
                uint32_t entry = 0x0;

                // Get the DDR revision
                uint8_t memType = 0x0;
                err = getMemType( theTarget,
                                  memType );
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdRead- Failure reading Basic memory type!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType,
                                 VPD::AUTOSELECT);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdRead- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }


                for( uint64_t keyword = SPD::SPD_FIRST_NORM_KEYWORD;
                     keyword <= SPD::SPD_LAST_NORM_KEYWORD; keyword++ )
                {
                    cmds++;
                    if( NULL != theData )
                    {
                        free( theData );
                        theData = NULL;
                    }

                    // Get the required size of the buffer
                    theSize = 0;
                    if( SPD_DDR3_TYPE == memType )
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
                    else if( SPD_DDR4_TYPE == memType )
                    {
                        size_t dataSize = (modType == DDIMM)
                            ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                            : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                        for( entry = 0;
                             entry < dataSize;
                             entry++ )
                        {
                            if (modType == DDIMM)
                            {
                                if( keyword == ddr4DDIMMData[entry].keyword )
                                {
                                    theSize = ddr4DDIMMData[entry].length;
                                    break;
                                }
                            }
                            else
                            {
                                if( keyword == ddr4Data[entry].keyword )
                                {
                                    theSize = ddr4Data[entry].length;
                                    break;
                                }
                            }
                        }
                    }

                    if( 0 == theSize )
                    {
                        // memType not supported or Keyword not supported on
                        // this memType
                        cmds--;
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
                                    VPD_COMP_ID );
                        continue;
                    }

                    // Read was successful, print out the data read
                    if (theSize == 1)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdRead - kwd: 0x%04x, val: 0x%02x, size: 1",
                                   keyword, theData[0] );
                    }
                    else if (theSize == 2)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdRead - kwd: 0x%04x, val: 0x%04x, size: 2",
                                   keyword,
                                   reinterpret_cast<uint16_t *>(theData)[0] );
                    }
                    else if (theSize == 3)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdRead - kwd: 0x%04x, val: 0x%02x%02x%02x, size: 3",
                                   keyword, theData[0], theData[1], theData[2],
                                   theSize );
                    }
                    else
                    {
                        // For 4 bytes or larger, just print the first 4 bytes
                        TRACFCOMP( g_trac_spd,
                                   "testSpdRead - kwd: 0x%04x, val: 0x%08x, size: %d",
                                   keyword,
                                   reinterpret_cast<uint32_t *>(theData)[0],
                                   theSize );
                    }

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

            if( NULL != theData )
            {
                free( theData );
                theData = NULL;
            }

            if( cmds == 0 )
            {
                TRACFCOMP(g_trac_spd,
                          "testSpdRead - No tests ran, something is wrong..." );
            }

            TRACFCOMP( g_trac_spd,
                       "testSpdRead - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief Test a SPD Write
         */
        void testSpdWriteDQ ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * testData = NULL;
            uint8_t * origData = NULL;
            uint8_t * verifyData = NULL;

            TS_INFO("testSpdWriteDQ Entry");

            do
            {
                TARGETING::Target * theTarget = NULL;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                TS_INFO( "testSpdWriteDQ dimmList.size()=%d", dimmList.size() );
                if( ( 0 == dimmList.size() ) ||
                    ( NULL == dimmList[0] ) )
                {
                    TS_FAIL("testSpdWriteDQ - No DIMMs found! Why not?");
                    break;
                }

                // Operate on first DIMM
                cmds++;
                theTarget = dimmList[0];
                size_t theSize = 0;

                // Get Memory Type
                uint8_t memType = 0x0;
                err = getMemType( theTarget,
                                  memType );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - failed to read memtype!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType,
                                 VPD::AUTOSELECT);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdRead- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the size
                if( SPD_DDR3_TYPE == memType )
                {
                    TS_INFO("testSpdWriteDQ SPD_DDR3_TYPE");
                    for( uint32_t entry = 0;
                         entry < (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
                         entry++ )
                    {
                        if( SPD::DIMM_BAD_DQ_DATA == ddr3Data[entry].keyword )
                        {
                            theSize = ddr3Data[entry].length;
                            break;
                        }
                    }
                }
                else if( SPD_DDR4_TYPE == memType )
                {
                    TS_INFO("testSpdWriteDQ SPD_DDR4_TYPE");
                    size_t dataSize = (modType == DDIMM)
                        ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                        : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                    for( uint32_t entry = 0;
                         entry < dataSize;
                         entry++ )
                    {
                        if (modType == DDIMM)
                        {
                            if( SPD::DIMM_BAD_DQ_DATA == ddr4DDIMMData[entry].keyword )
                            {
                                theSize = ddr4DDIMMData[entry].length;
                                break;
                            }
                        }
                        else
                        {
                            if( SPD::DIMM_BAD_DQ_DATA == ddr4Data[entry].keyword )
                            {
                                theSize = ddr4Data[entry].length;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - Unsupported memory type: 0x%04x", memType );
                    errlCommit( err, VPD_COMP_ID);
                    break;
                }

                if( 0 == theSize )
                {
                    // memType or Keyword not supported
                    TS_INFO("testSpdWriteDQ memType Keyword not supported, but we tried...");
                    cmds++;
                    break;
                }

                // Allocate data buffer
                origData = static_cast<uint8_t*>(malloc( theSize ));

                // Read the data out first
                err = deviceRead( theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( DIMM_BAD_DQ_DATA ) );
                TS_INFO( "testSpdWriteDQ - ORIGINAL DIMM Bad DQ data" );
                TRACFBIN( g_trac_spd, "original read=", origData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - failed to read ORIGINAL DIMM Bad DQ data!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // fill it up with some dummy data
                testData = static_cast<uint8_t*>(malloc( theSize ));
                for( size_t x=0; x<theSize; x++ )
                {
                    testData[x] = x;
                }

                // Write the test data in
                err = deviceWrite( theTarget,
                                   testData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( DIMM_BAD_DQ_DATA ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - Error writing data to DIMM Bad DQ data" );
                    break;
                }

                // Read the data out again to check it
                verifyData = static_cast<uint8_t*>(malloc( theSize ));
                err = deviceRead( theTarget,
                                  verifyData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( DIMM_BAD_DQ_DATA ) );
                TS_INFO( "testSpdWriteDQ - DUMMY DIMM Bad DQ data" );
                TRACFBIN( g_trac_spd, "dummy data read=", verifyData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - failed to read DUMMY DIMM Bad DQ data!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                if( memcmp( testData, verifyData, theSize ) )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - DIMM Bad DQ data does not match what we wrote!" );
                    TRACFBIN( g_trac_spd, "MISMATCH PROBLEM wrote=", testData, theSize );
                    TRACFBIN( g_trac_spd, "MISMATCH PROBLEM read=", verifyData, theSize );
                }
                else
                {
                    TS_INFO( "testSpdWriteDQ - DIMM Bad DQ data written successfully!" );
                    TRACFBIN( g_trac_spd, "wrote=", testData, theSize );
                    TRACFBIN( g_trac_spd, "read=", verifyData, theSize );
                }

                // put the original data back to be a good citizen
                err = deviceWrite( theTarget,
                                   origData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( DIMM_BAD_DQ_DATA ) );
                TS_INFO( "testSpdWriteDQ - deviceWrite Restoring ORIGINAL DIMM Bad DQ" );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - Error writing original data back to DIMM Bad DQ data, things may be corrupted!");
                    break;
                }
                else
                {
                    TS_INFO("testSpdWriteDQ - Successfully restored original DIMM Bad DQ theSize=0x%X", theSize);
                }


            } while( 0 );

            if( NULL != testData )
            {
                delete testData;
                testData = NULL;
            }

            if( NULL != origData )
            {
                delete origData;
                origData = NULL;
            }

            if( NULL != verifyData )
            {
                delete verifyData;
                verifyData = NULL;
            }

            if( cmds == 0 )
            {
                TS_FAIL("testSpdWriteDQ - No tests ran, something is wrong...");
            }

            TS_INFO("testSpdWriteDQ Exit - %d/%d fails", fails, cmds);
        }

        /**
         * @brief Test a SPD Write to a value that is less than 1 byte
         *
         * Note - There are no writable keywords that fit this criteria
         *   so this test is disabled by default.  To enable, modify the
         *   table in spdDDR3.H to make something writable.
         */
        void _testSpdWriteSmall ( void )
        {
#ifndef __HOSTBOOT_RUNTIME
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t* testData = NULL;
            uint8_t* origData = NULL;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdWriteSmall()" );

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
                               "testSpdWriteSmall - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM
                cmds++;
                theTarget = dimmList[0];

                // Get Memory Type
                uint8_t memType = 0x0;
                err = getMemType( theTarget,
                                  memType );
                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteSmall - failed to read memtype!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the size
                size_t theSize = 0;
                uint16_t theKeyword = INVALID_SPD_KEYWORD;
                if( SPD_DDR3_TYPE == memType )
                {
                    for( uint32_t entry = 0;
                         entry < (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
                         entry++ )
                    {
                        if( ddr3Data[entry].writable
                            && ddr3Data[entry].bitMask )
                        {
                            theSize = ddr3Data[entry].length;
                            theKeyword = ddr3Data[entry].keyword;
                            TRACFCOMP( g_trac_spd,
                                       "testSpdWriteSmall - Using DDR3 keyword 0x%04x",
                                       theKeyword );
                            break;
                        }
                    }
                }
                else if( SPD_DDR4_TYPE == memType )
                {
                    for( uint32_t entry = 0;
                         entry < (sizeof(ddr4Data)/sizeof(ddr4Data[0]));
                         entry++ )
                    {
                        if( ddr4Data[entry].writable
                            && ddr4Data[entry].bitMask )
                        {
                            theSize = ddr4Data[entry].length;
                            theKeyword = ddr4Data[entry].keyword;
                            TRACFCOMP( g_trac_spd,
                                       "testSpdWriteSmall - Using DDR4 keyword 0x%04x",
                                       theKeyword );
                            break;
                        }
                    }
                }
                else
                {
                    fails++;
                    TRACFCOMP( g_trac_spd,
                               "testSpdWriteSmall - memory type: 0x%04x",
                               memType );
                    TS_FAIL( "testSpdWriteSmall - Unsupported Memory Type!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                cmds++;
                if( theKeyword == INVALID_SPD_KEYWORD )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteSmall - Could not find a keyword to work with!" );
                    break;
                }

                // Read the data out
                cmds++;
                origData = new uint8_t[theSize];
                err = deviceRead( theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( theKeyword ) );
                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteSmall - failed to read keyword!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // fill test array up with some dummy data
                testData = new uint8_t[theSize];
                for( size_t x=0; x<theSize; x++ )
                {
                    testData[x] = 0x55;
                }

                // Write the test data
                cmds++;
                err = deviceWrite( theTarget,
                                   testData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( theKeyword ) );
                if( !err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteSmall - Did not get expected error writing data" );

                    // Put the original data back to be a good citizen
                    cmds++;
                    err = deviceWrite( theTarget,
                                       origData,
                                       theSize,
                                       DEVICE_SPD_ADDRESS( theKeyword ) );
                    if( err )
                    {
                        fails++;
                        TS_FAIL( "testSpdWriteSmall - Error writing original data back" );
                    }

                    break;
                }
                else
                {
                    cmds++;
                    if( err->reasonCode() != VPD::VPD_UNSUPPORTED_WRITE )
                    {
                        fails++;
                        TRACFCOMP( g_trac_spd,
                                   "testSpdWriteSmall - RC from write = 0x%04x",
                                   err->reasonCode() );
                        TS_FAIL( "testSpdWriteSmall - Did not get VPD_UNSUPPORTED_WRITE error writing data" );
                    }

                    delete err;
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

            if( cmds == 0 )
            {
                TS_FAIL( "testSpdWriteSmall - No tests ran, something is wrong..." );
            }

            TRACFCOMP( g_trac_spd,
                       "testSpdWriteSmall - %d/%d fails",
                       fails, cmds );
#endif  // #ifndef __HOSTBOOT_RUNTIME
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
                //If theData is NULL, deviceRead will return the size
                // need to give this an arbitrary size so test is still valid
                uint8_t * theData = static_cast<uint8_t*>(malloc( 0x1 ));
                size_t theSize = 0x0;   // Invalid size of 0x0

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( SPD::SPD_FIRST_NORM_KEYWORD ) );

                // clean up the data
                if( NULL != theData )
                {
                    delete theData;
                    theData = NULL;
                }
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
         */
        void testSpdInvalidWrite ( void )
        {
#ifndef __HOSTBOOT_RUNTIME
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdInvalidWrite()" );

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
                size_t theSize = 0x10;
                uint8_t * theData = static_cast<uint8_t*>(malloc( theSize ));

                cmds++;
                err = deviceWrite( theTarget,
                                   theData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( SPD::SPD_FIRST_NORM_KEYWORD ) );

                // clean up the data
                if( NULL != theData )
                {
                    delete theData;
                    theData = NULL;
                }

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "No failure for Invalid Write attempt to "
                             "SPD_FIRST_NORM_KEYWORD" );
                    break;
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_spd,
                       "testSpdInvalidWrite - %d/%d fails",
                       fails, cmds );
#endif  // #ifndef __HOSTBOOT_RUNTIME
        }

        /**
         * @brief This test will test reading the Module specific keywords.
         */
        void testspdModSpecKwds( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t memType = 0x0;
            uint8_t * theData = NULL;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testspdModSpecKwds()" );

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
                               "testspdModSpecKwds - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM.
                theTarget = dimmList[0];
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
                    TS_FAIL( "testspdModSpecKwds- Failure reading Basic "
                             "memory type!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType,
                                 VPD::AUTOSELECT);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdRead- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // The real Keyword read testing
                for( uint64_t keyword = SPD::SPD_FIRST_MOD_SPEC;
                     keyword <= SPD::SPD_LAST_MOD_SPEC; keyword++ )
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
                    if( SPD_DDR3_TYPE == memType )
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
                    }
                    else if( SPD_DDR4_TYPE == memType )
                    {
                        size_t dataSize = (modType == DDIMM)
                            ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                            : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                        for( entry = 0;
                             entry < dataSize;
                             entry++ )
                        {
                            if (modType == DDIMM)
                            {
                                if( keyword == ddr4DDIMMData[entry].keyword )
                                {
                                    kwdData = ddr4DDIMMData[entry];
                                    theSize = ddr4DDIMMData[entry].length;
                                    break;
                                }
                            }
                            else
                            {
                                if( keyword == ddr4Data[entry].keyword )
                                {
                                    kwdData = ddr4Data[entry];
                                    theSize = ddr4Data[entry].length;
                                    break;
                                }
                            }
                        }
                    }

                    if( 0 == theSize )
                    {
                        // memType not supported or Keyword not supported on
                        // this memType
                        cmds--;
                        continue;
                    }

                    // Check that the module type supports this keyword
                    TRACFCOMP( g_trac_spd,
                               INFO_MRK"SPD Error traces will follow!!!  "
                               "Not all module specific keywords will be "
                               "valid for all types of modules.  IGNORE!!" );
                    err = checkModSpecificKeyword( kwdData,
                                                   memType,
                                                   theTarget,
                                                   VPD::AUTOSELECT );
                    if( err )
                    {
                        // This keyword isn't supported with this module type
                        cmds--;
                        delete err;
                        err = NULL;
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
                        TS_FAIL( "testspdModSpecKwds - Failure on keyword: %04x",
                                 keyword );
                        errlCommit( err,
                                    VPD_COMP_ID );
                        continue;
                    }

                    // Read was successful, print out the data read
                    if (theSize == 1)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testspdModSpecKwds - kwd: 0x%04x, val: 0x%02x, size: 1",
                                   keyword, theData[0] );
                    }
                    else if (theSize == 2)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testspdModSpecKwds - kwd: 0x%04x, val: 0x%04x, size: 2",
                                   keyword,
                                   reinterpret_cast<uint16_t *>(theData)[0] );
                    }
                    else if (theSize == 3)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testspdModSpecKwds - kwd: 0x%04x, val: 0x%02x%02x%02x, size: 3",
                                   keyword, theData[0], theData[1], theData[2],
                                   theSize );
                    }
                    else
                    {
                        // For 4 bytes or larger, just print the first 4 bytes
                        TRACFCOMP( g_trac_spd,
                                   "testspdModSpecKwds - kwd: 0x%04x, val: 0x%08x, size: %d",
                                   keyword,
                                   reinterpret_cast<uint32_t *>(theData)[0],
                                   theSize );
                    }

                    if( NULL != theData )
                    {
                        free( theData );
                        theData = NULL;
                    }
                }
            } while( 0 );

            if( NULL != theData )
            {
                free( theData );
                theData = NULL;
            }

            TRACFCOMP( g_trac_spd,
                       "testspdModSpecKwds - %d/%d fails",
                       fails, cmds );
        }


        /**
         * @brief This test will ensure that the DDR3 lookup table is in a sorted
         *      order, according to the keyword enumeration, to enable the search
         *      algorithm to work correctly.
         */
        void testspdDDR3TableOrder ( void )
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

        /**
         * @brief This test will ensure that the DDR4 lookup table is in a
         *        sorted order, according to the keyword enumeration, to enable
         *        the search algorithm to work correctly.
         */
        void testspdDDR4TableOrder ( void )
        {
            uint64_t prevKeyword = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testspdDDR4TableOrder()" );

            for( uint32_t entry = 0;
                 entry < (sizeof(ddr4Data)/sizeof(ddr4Data[0]));
                 entry++ )
            {
                if( !(ddr4Data[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testspdDDR4TableOrder - DDR4 table out of order!  Cur kwd: "
                             "0x%04x, Pre kwd: 0x%04x",
                             ddr4Data[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = ddr4Data[entry].keyword;
            }

            TRACFCOMP( g_trac_spd,
                       EXIT_MRK"testspdDDR4TableOrder() - fails: %d",
                       fails );
        }
};

#endif
