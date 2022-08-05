/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/test/spdtest.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include "../spd_planar.H"
#include "../spd.H"

#include <arch/magic.H>

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
    errlHndl_t err = nullptr;
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
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * theData = nullptr;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdRead() DIMM" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdRead - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM.
                theTarget = dimmList[0];
                size_t theSize = 0;
                bool writeable = false;
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
                                 memType);
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
                    writeable = false;
                    if( nullptr != theData )
                    {
                        free( theData );
                        theData = nullptr;
                    }

                    // Get the required size of the buffer
                    theSize = 0;
                    if( SPD_DDR4_TYPE == memType )
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
                                    writeable = ddr4DDIMMData[entry].writable;
                                    break;
                                }
                            }
                            else
                            {
                                if( keyword == ddr4Data[entry].keyword )
                                {
                                    theSize = ddr4Data[entry].length;
                                    writeable = ddr4Data[entry].writable;
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
                    theData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

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

                    if (writeable)
                    {
                        // Currently only the following two keywords are writeable
                        // other tests will explicitly do writes to validate these two
                        if ((keyword == SPD::DIMM_BAD_DQ_DATA) ||
                            (keyword == SPD::EXPLORER_FW_VERSION))
                        {
                            TS_INFO( "testspdRead - CONFIRMED PASS on keyword: %04x, "
                                     "NORM keyword table defines as WRITEABLE",
                                     keyword );
                        }
                        else
                        {
                            fails++;
                            TS_FAIL("testspdRead NORM keyword=%04x table defines as "
                                    "WRITEABLE but should only be READABLE", keyword);
                        }

                    }
                    else
                    {
                        // Keyword is -NOT- writeable, so attempt the write which should fail
                        err = deviceWrite( theTarget,
                                           theData,
                                           theSize,
                                           DEVICE_SPD_ADDRESS( keyword ) );
                        if (theData != nullptr)
                        {
                            free( theData );
                            theData = nullptr;
                        }
                        if (err == nullptr)
                        {
                            fails++;
                            TS_FAIL("testspdRead We should have failed writing "
                                    "to a READ ONLY keyword=0x%X", keyword);
                            break;
                        }
                        else
                        {
                            if ( ERRL_GETRC_SAFE(err) != VPD::VPD_KEYWORD_NOT_WRITABLE)
                            {
                                fails++;
                                TS_FAIL("testspdRead BAD RESULT - We DID -NOT- FAIL writing "
                                    "as expected to a READ ONLY keyword=0x%X RC=0x%X", keyword,
                                    ERRL_GETRC_SAFE(err));
                                break;
                            }
                            else
                            {
                                TS_INFO("testspdRead GOOD RESULT - We DID FAIL writing "
                                    "to a READ ONLY keyword=0x%X RC=0x%X", keyword,
                                    ERRL_GETRC_SAFE(err));
                                delete err;
                                err = nullptr;
                            }
                        }
                    }
                } // end for

                if( err )
                {
                    break;
                }
            } while( 0 );

            if( nullptr != theData )
            {
                free( theData );
                theData = nullptr;
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
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * testData = nullptr;
            uint8_t * origData = nullptr;
            uint8_t * verifyData = nullptr;

            TS_INFO("testSpdWriteDQ Entry");

            // TODO: PFHB-23
            // This test case will crash while preforming a page switch
            // when attemping to write test data to ONE_BYTE_ADDR_PAGESELECT
            // eeproms during runtime.
            if (MAGIC_IS_BONITO())
            {
                TS_INFO("Skipping testSpdWriteDQ for bonito config due to "
                        "page switching not being supported for eeprom devices "
                        "durring runtime" );
                return;
            }

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                TS_INFO( "testSpdWriteDQ dimmList.size()=%d", dimmList.size() );
                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
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
                    errlCommit( err, VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType);

                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdRead- Failure reading memory module type!");
                    errlCommit( err, VPD_COMP_ID );
                    break;
                }

                // Get the size
                if( SPD_DDR4_TYPE == memType )
                {
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
                    TS_FAIL( "testSpdWriteDQ - Unsupported memory type: 0x%04X", memType );
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
                origData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                // Read the data out first
                err = deviceRead( theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( DIMM_BAD_DQ_DATA ) );

                TRACFBIN( g_trac_spd, "testSpdWriteDQ ORIGINAL DIMM BAD DQ DATA read=", origData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - failed to read ORIGINAL DIMM BAD DQ DATA!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // fill it up with some dummy data
                testData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                for( size_t x=0; x<theSize; x++ )
                {
                    testData[x] = x;
                }

                // Write the test data in
                TS_INFO( "testSpdWriteDQ - Write the test data in" );
                err = deviceWrite( theTarget,
                                   testData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( DIMM_BAD_DQ_DATA ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - Error writing data to DIMM BAD DQ DATA" );
                    break;
                }

                // Read the data out again to check it
                TS_INFO( "testSpdWriteDQ - Read the data out again to check it" );
                verifyData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                err = deviceRead( theTarget,
                                  verifyData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( DIMM_BAD_DQ_DATA ) );

                TRACFBIN( g_trac_spd, "testSpdWriteDQ TEST DATA read=", verifyData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - failed to read DUMMY DIMM BAD DQ DATA!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                if( memcmp( testData, verifyData, theSize ) )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - DIMM BAD DQ DATA does not match what we wrote!" );
                    TRACFBIN( g_trac_spd, "PROBLEM DIMM BAD DQ DATA MISMATCH wrote=", testData, theSize );
                    TRACFBIN( g_trac_spd, "PROBLEM DIMM BAD DQ DATA MISMATCH read=", verifyData, theSize );
                }
                else
                {
                    TS_INFO( "testSpdWriteDQ - DIMM BAD DQ DATA written successfully!" );
                    TRACFBIN( g_trac_spd, "CONFIRMED DIMM BAD DQ DATA wrote=", testData, theSize );
                    TRACFBIN( g_trac_spd, "CONFIRMED DIMM BAD DQ DATA read=", verifyData, theSize );
                }

                // put the original data back to be a good citizen
                TS_INFO( "testSpdWriteDQ - deviceWrite Restoring ORIGINAL DIMM BAD DQ DATA" );
                err = deviceWrite( theTarget,
                                   origData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( DIMM_BAD_DQ_DATA ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteDQ - Error writing original data back to "
                             "DIMM BAD DQ DATA, things may be corrupted!");
                    break;
                }
                else
                {
                    TS_INFO("testSpdWriteDQ - Successfully restored original "
                            "DIMM BAD DQ DATA theSize=0x%X", theSize);
                }


            } while( 0 );

            if( nullptr != testData )
            {
                free( testData );
                testData = nullptr;
            }

            if( nullptr != origData )
            {
                free( origData );
                origData = nullptr;
            }

            if( nullptr != verifyData )
            {
                free( verifyData );
                verifyData = nullptr;
            }

            if( cmds == 0 )
            {
                TS_FAIL("testSpdWriteDQ - No tests ran, something is wrong...");
            }

            TS_INFO("testSpdWriteDQ Exit - %d/%d fails", fails, cmds);
        }

        /**
         * @brief Test a SPD Write EXPLORER_FW_VERSION
         */
        void testSpdWriteFW ( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * testData = nullptr;
            uint8_t * origData = nullptr;
            uint8_t * verifyData = nullptr;

            TS_INFO("testSpdWriteFW Entry");

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                TS_INFO( "testSpdWriteFW dimmList.size()=%d", dimmList.size() );
                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TS_FAIL("testSpdWriteFW - No DIMMs found! Why not?");
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
                    TS_FAIL( "testSpdWriteFW - failed to read memtype!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdWriteFW- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the size
                if( SPD_DDR4_TYPE == memType )
                {
                    size_t dataSize = (modType == DDIMM)
                        ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                        : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                    for( uint32_t entry = 0;
                         entry < dataSize;
                         entry++ )
                    {
                        if (modType == DDIMM)
                        {
                            if( SPD::EXPLORER_FW_VERSION == ddr4DDIMMData[entry].keyword )
                            {
                                theSize = ddr4DDIMMData[entry].length;
                                break;
                            }
                        }
                        else
                        {
                            if( SPD::EXPLORER_FW_VERSION == ddr4Data[entry].keyword )
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
                    TS_FAIL( "testSpdWriteFW - Unsupported memory type: 0x%04x", memType );
                    errlCommit( err, VPD_COMP_ID);
                    break;
                }

                if( 0 == theSize )
                {
                    // memType or Keyword not supported
                    TS_INFO("testSpdWriteFW memType Keyword not supported, but we tried...");
                    cmds++;
                    break;
                }

                // Allocate data buffer
                origData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                // Read the data out first
                err = deviceRead( theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( EXPLORER_FW_VERSION ) );
                TRACFBIN( g_trac_spd, "testSpdWriteFW ORIGINAL EXPLORER_FW_VERSION read=",
                            origData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - failed to read ORIGINAL EXPLORER_FW_VERSION!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // fill it up with some dummy data
                testData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                for( size_t x=0; x<theSize; x++ )
                {
                    testData[x] = x;
                }

                // Write the test data in
                err = deviceWrite( theTarget,
                                   testData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( EXPLORER_FW_VERSION ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - Error writing data to EXPLORER_FW_VERSION" );
                    break;
                }

                // Read the data out again to check it
                verifyData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                err = deviceRead( theTarget,
                                  verifyData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( EXPLORER_FW_VERSION ) );
                TRACFBIN( g_trac_spd, "testSpdWriteFW TEST DATA EXPLORER_FW_VERSION data read=",
                            verifyData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - failed to read TEST DATA for EXPLORER_FW_VERSION!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                if( memcmp( testData, verifyData, theSize ) )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - PROBLEM DIMM EXPLORER_FW_VERSION "
                             "data does not match what we wrote!" );
                    TRACFBIN( g_trac_spd, "PROBLEM EXPLORER_FW_VERSION MISMATCH wrote=",
                                testData, theSize );
                    TRACFBIN( g_trac_spd, "PROBLEM EXPLORER_FW_VERSION MISMATCH read=",
                                verifyData, theSize );
                }
                else
                {
                    TS_INFO( "testSpdWriteFW - CONFIRMED DIMM EXPLORER_FW_VERSION "
                             "data written successfully!" );
                    TRACFBIN( g_trac_spd, "CONFIRMED EXPLORER_FW_VERSION wrote=",
                                testData, theSize );
                    TRACFBIN( g_trac_spd, "CONFIRMED EXPLORER_FW_VERSION read=",
                                verifyData, theSize );
                }

                // put the original data back to be a good citizen
                err = deviceWrite( theTarget,
                                   origData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( EXPLORER_FW_VERSION ) );
                TS_INFO( "testSpdWriteFW - deviceWrite Restoring ORIGINAL "
                         "DIMM EXPLORER_FW_VERSION" );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFW - Error writing original data back to "
                             "DIMM EXPLORER_FW_VERSION data, things may be corrupted!");
                    break;
                }
                else
                {
                    TS_INFO("testSpdWriteFW - Successfully restored original "
                            "DIMM EXPLORER_FW_VERSION theSize=0x%X", theSize);
                }


            } while( 0 );

            if( nullptr != testData )
            {
                free( testData );
                testData = nullptr;
            }

            if( nullptr != origData )
            {
                free( origData );
                origData = nullptr;
            }

            if( nullptr != verifyData )
            {
                free( verifyData );
                verifyData = nullptr;
            }

            if( cmds == 0 )
            {
                TS_FAIL("testSpdWriteFW - No tests ran, something is wrong...");
            }

            TS_INFO("testSpdWriteFW Exit - %d/%d fails", fails, cmds);
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
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t* testData = nullptr;
            uint8_t* origData = nullptr;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdWriteSmall()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
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

            if( nullptr != testData )
            {
                delete[] testData;
                testData = nullptr;
            }

            if( nullptr != origData )
            {
                delete[] origData;
                origData = nullptr;
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
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdInvalidKeyword()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdInvalidKeyword - No DIMMs found!" );
                    break;
                }

                // Test on first DIMM only.
                theTarget = dimmList[0];
                uint8_t * theData = nullptr;
                size_t theSize = 0x0;

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( SPD::INVALID_SPD_KEYWORD ) );

                if( nullptr == err )
                {
                    fails++;
                    TS_FAIL( "testSpdInvalidKeyword - No error returned!" );
                    break;
                }
                else
                {
                    delete err;
                    err = nullptr;
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
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdInvalidSize()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdInvalidSize - No DIMMs found!" );
                    break;
                }

                // Test on first DIMM only.
                theTarget = dimmList[0];
                //If theData is nullptr, deviceRead will return the size
                // need to give this an arbitrary size so test is still valid
                uint8_t * theData = static_cast<uint8_t*>(calloc( 1,sizeof(uint8_t) ));
                size_t theSize = 0x0;   // Invalid size of 0x0

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_SPD_ADDRESS( SPD::SPD_FIRST_NORM_KEYWORD ) );

                // clean up the data
                if( nullptr != theData )
                {
                    free( theData );
                    theData = nullptr;
                }
                if( nullptr == err )
                {
                    fails++;
                    TS_FAIL( "testSpdInvalidSize - No error for invalid size!" );
                    break;
                }
                else
                {
                    delete err;
                    err = nullptr;
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
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdInvalidWrite()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdInvalidSize - No DIMMs found!" );
                    break;
                }

                // Test on first DIMM only.
                theTarget = dimmList[0];
                size_t theSize = 0x10;
                uint8_t * theData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                cmds++;
                // This fails since SPD_FIRST_NORM_KEYWORD is not writable
                err = deviceWrite( theTarget,
                                   theData,
                                   theSize,
                                   DEVICE_SPD_ADDRESS( SPD::SPD_FIRST_NORM_KEYWORD ) );

                // clean up the data
                if( nullptr != theData )
                {
                    free( theData );
                    theData = nullptr;
                }

                if( nullptr == err )
                {
                    fails++;
                    TS_FAIL( "No failure for Invalid Write attempt to "
                             "SPD_FIRST_NORM_KEYWORD" );
                    break;
                }
                else
                {
                    delete err;
                    err = nullptr;
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
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t memType = 0x0;
            uint8_t * theData = nullptr;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testspdModSpecKwds()" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testspdModSpecKwds - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM.
                theTarget = dimmList[0];
                size_t theSize = 0;
                bool writeable = false;
                uint32_t entry = 0x0;

                // Get the DDR revision
                size_t tmpSize = 0x1;
                TS_INFO("testspdModSpecKwds WORKING on FIRST DIMM HUID=0x%X",
                        TARGETING::get_huid(theTarget));
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
                                 memType);
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
                    // Keep track of writeable to check later
                    writeable = false;
                    if( nullptr != theData )
                    {
                        free( theData );
                        theData = nullptr;
                    }

                    // Get the required size of the buffer
                    theSize = 0;
                    KeywordData kwdData;
                    if( SPD_DDR4_TYPE == memType )
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
                                    writeable = ddr4DDIMMData[entry].writable;
                                    break;
                                }
                            }
                            else
                            {
                                if( keyword == ddr4Data[entry].keyword )
                                {
                                    kwdData = ddr4Data[entry];
                                    theSize = ddr4Data[entry].length;
                                    writeable = ddr4Data[entry].writable;
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
                    TS_INFO("SPD Error traces MAY follow!!!  "
                               "Not all module specific keywords will be "
                               "valid for all types of modules.  IGNORE!!" );
                    err = checkModSpecificKeyword( kwdData,
                                                   memType,
                                                   theTarget );
                    if( err )
                    {
                        // This keyword isn't supported with this module type
                        cmds--;
                        delete err;
                        err = nullptr;
                        continue;
                    }

                    // Allocate the buffer
                    theData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
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

                    if( nullptr != theData )
                    {
                        free( theData );
                        theData = nullptr;
                    }
                    // At this time only ONE MOD SPEC Keyword is WRITEABLE
                    // so fail if keyword is something not expected as WRITEABLE
                    if (writeable)
                    {
                        if (keyword != SPD::EXPLORER_FW_VERSION)
                        {
                            fails++;
                            TS_FAIL("testspdModSpecKwds MOD SPEC keyword=%04x table defines "
                                    "as WRITEABLE but should only be READABLE", keyword);
                        }
                    }
                }
            } while( 0 );

            if( nullptr != theData )
            {
                free( theData );
                theData = nullptr;
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

            TRACFCOMP( g_trac_spd, ENTER_MRK"testspdDDR3TableOrder()" );

            for( uint32_t entry = 0;
                 entry < (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
                 entry++ )
            {
                if( !(ddr3Data[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testspdDDR3TableOrder - DDR3 table out of order! Cur kwd: "
                             "0x%04X, Pre kwd: 0x%04X",
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

            TRACFCOMP( g_trac_spd, ENTER_MRK"testspdDDR4TableOrder()" );

            for( uint32_t entry = 0;
                 entry < (sizeof(ddr4Data)/sizeof(ddr4Data[0]));
                 entry++ )
            {
                if( !(ddr4Data[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testspdDDR4TableOrder - DDR4 table out of order! Cur kwd: "
                             "0x%04X, Pre kwd: 0x%04X",
                             ddr4Data[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = ddr4Data[entry].keyword;
            }

            TRACFCOMP( g_trac_spd,
                       EXIT_MRK"testspdDDR4TableOrder() - fails: %d",
                       fails );
        }

        /**
         * @brief This test will ensure that the Planar lookup table is in a
         *        sorted order, according to the keyword enumeration, to enable
         *        the search algorithm to work correctly.
         */
        void testspdPlanarTableOrder ( void )
        {
            uint64_t prevKeyword = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_spd, ENTER_MRK"testspdPlanarTableOrder()" );

            for( uint32_t entry = 0;
                 entry < (sizeof(planarEepromData)/sizeof(planarEepromData[0]));
                 entry++ )
            {
                if( !(planarEepromData[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testspdPlanarTableOrder - Planar table out of order! Cur kwd: "
                             "0x%04X, Pre kwd: 0x%04X",
                             planarEepromData[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = planarEepromData[entry].keyword;
            }

            TRACFCOMP( g_trac_spd,
                       EXIT_MRK"testspdPlanarTableOrder() - fails: %d",
                       fails );
        }

        /**
         * @brief This test reads all of the keywords for all of the
         *      DIMMs found using the generic VPD driver interface.
         */
        void testSpdReadGeneric ( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * theData = nullptr;

            TRACFCOMP( g_trac_spd,
                       ENTER_MRK"testSpdReadGeneric() DIMM" );

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TRACFCOMP( g_trac_spd,
                               "testSpdReadGeneric - No DIMMs found!" );
                    break;
                }

                // Operate on first DIMM.
                theTarget = dimmList[0];
                size_t theSize = 0;
                bool writeable = false;
                uint32_t entry = 0x0;

                // Get the DDR revision
                uint8_t memType = 0x0;
                err = getMemType( theTarget,
                                  memType );
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdReadGeneric- Failure reading Basic memory type!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdReadGeneric- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }


                for( uint64_t keyword = SPD::SPD_FIRST_NORM_KEYWORD;
                     keyword <= SPD::SPD_LAST_NORM_KEYWORD; keyword++ )
                {
                    cmds++;
                    writeable = false;
                    if( nullptr != theData )
                    {
                        free( theData );
                        theData = nullptr;
                    }

                    // Get the required size of the buffer
                    theSize = 0;
                    if( SPD_DDR4_TYPE == memType )
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
                                    writeable = ddr4DDIMMData[entry].writable;
                                    break;
                                }
                            }
                            else
                            {
                                if( keyword == ddr4Data[entry].keyword )
                                {
                                    theSize = ddr4Data[entry].length;
                                    writeable = ddr4Data[entry].writable;
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
                    theData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_VPD_ADDRESS( SPD::NO_RECORD, keyword ) );

                    if( err )
                    {
                        fails++;
                        TS_FAIL( "testSpdReadGeneric - Failure on keyword: %04x",
                                 keyword );
                        errlCommit( err,
                                    VPD_COMP_ID );
                        continue;
                    }

                    // Read was successful, print out the data read
                    if (theSize == 1)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdReadGeneric - kwd: 0x%04x, val: 0x%02x, size: 1",
                                   keyword, theData[0] );
                    }
                    else if (theSize == 2)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdReadGeneric - kwd: 0x%04x, val: 0x%04x, size: 2",
                                   keyword,
                                   reinterpret_cast<uint16_t *>(theData)[0] );
                    }
                    else if (theSize == 3)
                    {
                        TRACFCOMP( g_trac_spd,
                                   "testSpdReadGeneric - kwd: 0x%04x, val: 0x%02x%02x%02x, size: 3",
                                   keyword, theData[0], theData[1], theData[2],
                                   theSize );
                    }
                    else
                    {
                        // For 4 bytes or larger, just print the first 4 bytes
                        TRACFCOMP( g_trac_spd,
                                   "testSpdReadGeneric - kwd: 0x%04x, val: 0x%08x, size: %d",
                                   keyword,
                                   reinterpret_cast<uint32_t *>(theData)[0],
                                   theSize );
                    }

                    if (writeable)
                    {
                        // Currently only the following two keywords are writeable
                        // other tests will explicitly do writes to validate these two
                        if ((keyword == SPD::DIMM_BAD_DQ_DATA) ||
                            (keyword == SPD::EXPLORER_FW_VERSION))
                        {
                            TS_INFO( "testSpdReadGeneric - CONFIRMED PASS on keyword: %04x, "
                                     "NORM keyword table defines as WRITEABLE",
                                     keyword );
                        }
                        else
                        {
                            fails++;
                            TS_FAIL("testSpdReadGeneric NORM keyword=%04x table defines as "
                                    "WRITEABLE but should only be READABLE", keyword);
                        }

                    }
                    else
                    {
                        // Keyword is -NOT- writeable, so attempt the write which should fail
                        err = deviceWrite( theTarget,
                                           theData,
                                           theSize,
                                           DEVICE_VPD_ADDRESS( SPD::NO_RECORD, keyword ) );
                        if (theData != nullptr)
                        {
                            free(theData);
                            theData = nullptr;
                        }
                        if (err == nullptr)
                        {
                            fails++;
                            TS_FAIL("testSpdReadGeneric We should have failed writing "
                                    "to a READ ONLY keyword=0x%X", keyword);
                            break;
                        }
                        else
                        {
                            if ( ERRL_GETRC_SAFE(err) != VPD::VPD_KEYWORD_NOT_WRITABLE)
                            {
                                fails++;
                                TS_FAIL("testSpdReadGeneric BAD RESULT - We DID -NOT- FAIL writing "
                                    "as expected to a READ ONLY keyword=0x%X RC=0x%X", keyword,
                                    ERRL_GETRC_SAFE(err));
                                break;
                            }
                            else
                            {
                                TS_INFO("testSpdReadGeneric GOOD RESULT - We DID FAIL writing "
                                    "to a READ ONLY keyword=0x%X RC=0x%X", keyword,
                                    ERRL_GETRC_SAFE(err));
                                delete err;
                                err = nullptr;
                            }
                        }
                    }
                } // end for

                if( err )
                {
                    break;
                }
            } while( 0 );

            if( nullptr != theData )
            {
                free( theData );
                theData = nullptr;
            }

            if( cmds == 0 )
            {
                TRACFCOMP(g_trac_spd,
                          "testSpdReadGeneric - No tests ran, something is wrong..." );
            }

            TRACFCOMP( g_trac_spd,
                       "testSpdReadGeneric - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief Test a SPD Write EXPLORER_FW_VERSION using Generic VPD.
         */
        void testSpdWriteFWGeneric ( void )
        {
            errlHndl_t err = nullptr;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t * testData = nullptr;
            uint8_t * origData = nullptr;
            uint8_t * verifyData = nullptr;

            TS_INFO("testSpdWriteFWGeneric Entry");

            do
            {
                TARGETING::Target * theTarget = nullptr;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                TS_INFO( "testSpdWriteFWGeneric dimmList.size()=%d", dimmList.size() );
                if( ( 0 == dimmList.size() ) ||
                    ( nullptr == dimmList[0] ) )
                {
                    TS_FAIL("testSpdWriteFWGeneric - No DIMMs found! Why not?");
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
                    TS_FAIL( "testSpdWriteFWGeneric - failed to read memtype!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the module type.
                modSpecTypes_t modType = NA;
                err = getModType(modType,
                                 theTarget,
                                 memType);
                if( err )
                {
                    fails++;
                    TS_FAIL("testSpdWriteFWGeneric- Failure reading memory module type!");
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // Get the size
                if( SPD_DDR4_TYPE == memType )
                {
                    size_t dataSize = (modType == DDIMM)
                        ? (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]))
                        : (sizeof(ddr4Data)/sizeof(ddr4Data[0]));

                    for( uint32_t entry = 0;
                         entry < dataSize;
                         entry++ )
                    {
                        if (modType == DDIMM)
                        {
                            if( SPD::EXPLORER_FW_VERSION == ddr4DDIMMData[entry].keyword )
                            {
                                theSize = ddr4DDIMMData[entry].length;
                                break;
                            }
                        }
                        else
                        {
                            if( SPD::EXPLORER_FW_VERSION == ddr4Data[entry].keyword )
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
                    TS_FAIL( "testSpdWriteFWGeneric - Unsupported memory type: 0x%04x", memType );
                    errlCommit( err, VPD_COMP_ID);
                    break;
                }

                if( 0 == theSize )
                {
                    // memType or Keyword not supported
                    TS_INFO("testSpdWriteFWGeneric memType Keyword not supported, but we tried...");
                    cmds++;
                    break;
                }

                // Allocate data buffer
                origData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));

                // Read the data out first
                err = deviceRead( theTarget,
                                  origData,
                                  theSize,
                                  DEVICE_VPD_ADDRESS( SPD::NO_RECORD, EXPLORER_FW_VERSION ) );
                TRACFBIN( g_trac_spd, "testSpdWriteFWGeneric ORIGINAL EXPLORER_FW_VERSION read=",
                            origData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - failed to read ORIGINAL EXPLORER_FW_VERSION!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                // fill it up with some dummy data
                testData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                for( size_t x=0; x<theSize; x++ )
                {
                    testData[x] = x;
                }

                // Write the test data in
                err = deviceWrite( theTarget,
                                   testData,
                                   theSize,
                                   DEVICE_VPD_ADDRESS( SPD::NO_RECORD, EXPLORER_FW_VERSION ) );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - Error writing data to EXPLORER_FW_VERSION" );
                    break;
                }

                // Read the data out again to check it
                verifyData = static_cast<uint8_t*>(calloc( theSize,sizeof(uint8_t) ));
                err = deviceRead( theTarget,
                                  verifyData,
                                  theSize,
                                  DEVICE_VPD_ADDRESS( SPD::NO_RECORD, EXPLORER_FW_VERSION ) );
                TRACFBIN( g_trac_spd, "testSpdWriteFWGeneric TEST DATA EXPLORER_FW_VERSION data read=",
                            verifyData, theSize );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - failed to read TEST DATA for EXPLORER_FW_VERSION!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    break;
                }

                if( memcmp( testData, verifyData, theSize ) )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - PROBLEM DIMM EXPLORER_FW_VERSION "
                             "data does not match what we wrote!" );
                    TRACFBIN( g_trac_spd, "PROBLEM EXPLORER_FW_VERSION MISMATCH wrote=",
                                testData, theSize );
                    TRACFBIN( g_trac_spd, "PROBLEM EXPLORER_FW_VERSION MISMATCH read=",
                                verifyData, theSize );
                }
                else
                {
                    TS_INFO( "testSpdWriteFWGeneric - CONFIRMED DIMM EXPLORER_FW_VERSION "
                             "data written successfully!" );
                    TRACFBIN( g_trac_spd, "CONFIRMED EXPLORER_FW_VERSION wrote=",
                                testData, theSize );
                    TRACFBIN( g_trac_spd, "CONFIRMED EXPLORER_FW_VERSION read=",
                                verifyData, theSize );
                }

                // put the original data back to be a good citizen
                err = deviceWrite( theTarget,
                                   origData,
                                   theSize,
                                   DEVICE_VPD_ADDRESS( SPD::NO_RECORD, EXPLORER_FW_VERSION ) );
                TS_INFO( "testSpdWriteFWGeneric - deviceWrite Restoring ORIGINAL "
                         "DIMM EXPLORER_FW_VERSION" );

                if( err )
                {
                    fails++;
                    TS_FAIL( "testSpdWriteFWGeneric - Error writing original data back to "
                             "DIMM EXPLORER_FW_VERSION data, things may be corrupted!");
                    break;
                }
                else
                {
                    TS_INFO("testSpdWriteFWGeneric - Successfully restored original "
                            "DIMM EXPLORER_FW_VERSION theSize=0x%X", theSize);
                }


            } while( 0 );

            if( nullptr != testData )
            {
                free(testData);
                testData = nullptr;
            }

            if( nullptr != origData )
            {
                free(origData);
                origData = nullptr;
            }

            if( nullptr != verifyData )
            {
                free(verifyData);
                verifyData = nullptr;
            }

            if( cmds == 0 )
            {
                TS_FAIL("testSpdWriteFWGeneric - No tests ran, something is wrong...");
            }

            TS_INFO("testSpdWriteFWGeneric Exit - %d/%d fails", fails, cmds);
        }

};

#endif
