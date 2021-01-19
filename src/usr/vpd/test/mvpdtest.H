/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/test/mvpdtest.H $                                 */
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

#include <vpd/mvpdenums.H>
#include <vpd/vpdreasoncodes.H>
#include "../mvpd.H"
#include "../ipvpd.H"


extern trace_desc_t* g_trac_vpd;

using namespace TARGETING;

/**
 * @brief Structure to define record/keyword pairs for MVPD tests.
 */
struct mvpdTestData
{
    VPD::vpdRecord record;
    VPD::vpdRecord keyword;
};

/**
 * @brief Data sample to be used for MVPD testing.
 *      NOTE: By reading this entire list, it also validates that the records
 *      and keywords that we expect to be there are actually there...
 */
mvpdTestData mvpdData[] =
{
    { MVPD::CRP0, MVPD::VD },
    { MVPD::CRP0, MVPD::ED },
    { MVPD::CRP0, MVPD::TE },
    { MVPD::CRP0, MVPD::DD },
    { MVPD::CRP0, MVPD::DN },
    { MVPD::CRP0, MVPD::pdV },
    { MVPD::CRP0, MVPD::IQ },
    { MVPD::CRP0, MVPD::pdW },
    { MVPD::CRP0, MVPD::RT },
    { MVPD::CRP0, MVPD::CI },
    { MVPD::CP00, MVPD::VD },
    { MVPD::CP00, MVPD::PG },
    { MVPD::CP00, MVPD::pdR },
    { MVPD::CP00, MVPD::SB },
    { MVPD::CP00, MVPD::pdG },
    { MVPD::CP00, MVPD::PZ },
    { MVPD::CP00, MVPD::RT },
    { MVPD::CP00, MVPD::AW },
    { MVPD::VINI, MVPD::DR },
    { MVPD::VINI, MVPD::VZ },
    { MVPD::VINI, MVPD::CC },
    { MVPD::VINI, MVPD::CE },
    { MVPD::VINI, MVPD::FN },
    { MVPD::VINI, MVPD::PN },
    { MVPD::VINI, MVPD::SN },
    { MVPD::VINI, MVPD::PR },
    { MVPD::VINI, MVPD::HE },
    { MVPD::VINI, MVPD::CT },
    { MVPD::VINI, MVPD::HW },
    { MVPD::VINI, MVPD::RT },
    { MVPD::LRP0, MVPD::VD },
    { MVPD::LRP0, MVPD::RT },
    { MVPD::LRP1, MVPD::VD },
    { MVPD::LRP1, MVPD::RT },
    { MVPD::LRP2, MVPD::VD },
    { MVPD::LRP2, MVPD::RT },
    { MVPD::LRP3, MVPD::VD },
    { MVPD::LRP3, MVPD::RT },
    { MVPD::LRP4, MVPD::VD },
    { MVPD::LRP4, MVPD::RT },
    { MVPD::LRP5, MVPD::VD },
    { MVPD::LRP5, MVPD::RT },
    { MVPD::LWP0, MVPD::VD },
    { MVPD::LWP0, MVPD::n20 },
    { MVPD::LWP0, MVPD::n21 },
    { MVPD::LWP0, MVPD::n30 },
    { MVPD::LWP0, MVPD::n31 },
    { MVPD::LWP0, MVPD::RT },
    { MVPD::LWP1, MVPD::VD },
    { MVPD::LWP1, MVPD::n20 },
    { MVPD::LWP1, MVPD::n21 },
    { MVPD::LWP1, MVPD::n30 },
    { MVPD::LWP1, MVPD::n31 },
    { MVPD::LWP1, MVPD::RT },
    { MVPD::LWP2, MVPD::VD },
    { MVPD::LWP2, MVPD::n20 },
    { MVPD::LWP2, MVPD::n21 },
    { MVPD::LWP2, MVPD::n30 },
    { MVPD::LWP2, MVPD::n31 },
    { MVPD::LWP2, MVPD::RT },
    { MVPD::LWP3, MVPD::VD },
    { MVPD::LWP3, MVPD::n20 },
    { MVPD::LWP3, MVPD::n21 },
    { MVPD::LWP3, MVPD::n30 },
    { MVPD::LWP3, MVPD::n31 },
    { MVPD::LWP3, MVPD::RT },
    { MVPD::LWP4, MVPD::VD },
    { MVPD::LWP4, MVPD::n20 },
    { MVPD::LWP4, MVPD::n21 },
    { MVPD::LWP4, MVPD::n30 },
    { MVPD::LWP4, MVPD::n31 },
    { MVPD::LWP4, MVPD::RT },
    { MVPD::LWP5, MVPD::VD },
    { MVPD::LWP5, MVPD::n20 },
    { MVPD::LWP5, MVPD::n21 },
    { MVPD::LWP5, MVPD::n30 },
    { MVPD::LWP5, MVPD::n31 },
    { MVPD::LWP5, MVPD::RT },
    { MVPD::VRML, MVPD::VD },
    { MVPD::VRML, MVPD::PN },
    { MVPD::VRML, MVPD::SN },
    { MVPD::VRML, MVPD::RT },
    { MVPD::VWML, MVPD::VD },
    { MVPD::VWML, MVPD::pdI },
    { MVPD::VWML, MVPD::RT },
    { MVPD::VER0, MVPD::VD },
    { MVPD::VER0, MVPD::pdI },
    { MVPD::VER0, MVPD::RT },
    { MVPD::MER0, MVPD::VD },
    { MVPD::MER0, MVPD::pdI },
    { MVPD::MER0, MVPD::RT },
};

VPD::vpdRecord mvpdRecordData[] =
{
    MVPD::CP00,
    MVPD::CRP0,
    MVPD::LRP0,
    MVPD::LRP1,
    MVPD::LRP2,
    MVPD::LRP3,
    MVPD::LRP4,
    MVPD::LRP5,
    MVPD::LWP0,
    MVPD::LWP1,
    MVPD::LWP2,
    MVPD::LWP3,
    MVPD::LWP4,
    MVPD::LWP5,
    MVPD::MER0,
    MVPD::VER0,
    MVPD::VINI,
    MVPD::VRML,
    MVPD::VWML,
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

    TRACDCOMP( g_trac_vpd,
               "getProcTargets() - found %d Processors",
               o_procList.size() );

    return;
}

TARGETING::Target* getFunctionalProcTarget()
{
    TARGETING::Target * theTarget = NULL;
    TRACDCOMP( g_trac_vpd,
               "getFunctionalProcTarget() - Finding a processor" );

    do {
        // Get the Processor targets
        TargetHandleList procList;
        getProcTargets( procList );

        if( ( 0 == procList.size() ) ||
            ( NULL == procList[0] ) )
        {
            continue;  // add continue because have no Proc targets
        }

        for(uint32_t i=0; i<procList.size(); i++)
        {
            if(procList[i]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
            {
                theTarget = procList[i];
                break;
            }
        }
    }while(0);

    return theTarget;

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

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testMvpdRead()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalProcTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testMvpdRead() - No Functional Targets found!");
                    break;
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
                        TRACFCOMP( g_trac_vpd,
                                   ERR_MRK"testMvpdRead() - failure reading "
                                   "keyword size!!  rec: 0x%04x, kwd: 0x%04x",
                                   theRecord,
                                   theKeyword );
                        TS_FAIL("testMvpdRead() -Failure reading keyword size!");
                        errlCommit( err,
                                    VPD_COMP_ID );
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
                        TRACFCOMP( g_trac_vpd,
                                   ERR_MRK"testMvpdRead() - Failure on Record: "
                                   "0x%04x, keyword: 0x%04x, of size: 0x%04x "
                                   "- test %d",
                                   theRecord,
                                   theKeyword,
                                   theSize, curCmd );
                        TS_FAIL( "testMvpdRead() - Failure during MVPD read!" );
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
                               INFO_MRK"testMvpdRead Results:" );
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
                       "testMvpdRead - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test MVPD reads.
         */
        void testMvpdReadRecords ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint64_t theRecord = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testMvpdReadRecords()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalProcTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testMvpdReadRecords() - No Functional Targets found!");
                    break;
                }

                uint8_t * theData = NULL;
                size_t theSize = 0;
                const uint32_t numCmds =
                              sizeof(mvpdRecordData)/sizeof(mvpdRecordData[0]);
                for( uint32_t curCmd = 0; curCmd < numCmds; curCmd++ )
                {
                    cmds++;
                    theRecord = (uint64_t)mvpdRecordData[curCmd];
                    err = deviceRead( theTarget,
                                      NULL,
                                      theSize,
                                      DEVICE_MVPD_ADDRESS( theRecord,
                                                        MVPD::FULL_RECORD ));

                    if( err )
                    {
                        fails++;
                        TRACFCOMP( g_trac_vpd,
                                   ERR_MRK"testMvpdReadRecords() - failure"
                                   " reading record size!!  rec: 0x%04x",
                                   theRecord);
                        TS_FAIL("testMvpdReadRecords() -Failure reading record size!");
                        errlCommit( err,
                                    VPD_COMP_ID );
                        continue;
                    }

                    //Check for zero size, don't have a reliable way to check for too big
                    if( 0 == theSize  )
                    {
                        fails++;
                        TRACFCOMP( g_trac_vpd,
                                   ERR_MRK"testMvpdReadRecords() - failure"
                                   " reading record 0x%04x had size of zero!",
                                   theRecord);
                        TS_FAIL("testMvpdReadRecords() -Failure on record size of zero!");
                        continue;
                    }

                    theData = static_cast<uint8_t*>(malloc( theSize ));

                    // Read record/keyword pair
                    err = deviceRead( theTarget,
                                      theData,
                                      theSize,
                                      DEVICE_MVPD_ADDRESS( theRecord,
                                                        MVPD::FULL_RECORD ));

                    if( err )
                    {
                        fails++;
                        TRACFCOMP( g_trac_vpd,
                                   ERR_MRK"testMvpdReadRecords() - Failure on"
                                   " Record: 0x%04x of size: 0x%04x - test %d",
                                   theRecord,
                                   theSize, curCmd );
                        TS_FAIL( "testMvpdReadRecords() - Failure during MVPD read!" );
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
                               INFO_MRK"testMvpdRead Results:" );
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
                       "testMvpdReadRecords - %d/%d fails",
                       fails, cmds );
        }


        /**
         * @brief This function will test MVPD writes.
         */
        void testMvpdWrite ( void )
        {
            auto l_record  = MVPD::VWML;
            auto l_keyword = MVPD::pdI;

            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;
            uint8_t* testData = NULL;
            uint8_t* origData = NULL;
            uint8_t* verifyData = NULL;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testMvpdWrite()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalProcTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testMvpdWrite() - No Functional Targets found!");
                    break;
                }

                // first figure out how big the keyword is
                cmds++;
                size_t theSize = 0;
                err = deviceRead( theTarget,
                                  testData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS(l_record, l_keyword) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testMvpdWrite() - failure getting size of VWML/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testMvpdWrite() - Failure calling deviceRead!" );
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
                                  DEVICE_MVPD_ADDRESS(l_record, l_keyword) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testMvpdWrite() - failure reading VWML/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testMvpdWrite() - Failure calling deviceRead!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
                }
                TRACFBIN( g_trac_vpd, "testMvpdWrite() - orig=",
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
                                   DEVICE_MVPD_ADDRESS(l_record, l_keyword) );

                if( err )
                {
#ifndef __HOSTBOOT_RUNTIME
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testMvpdWrite() - failure writing VWML/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testMvpdWrite() - Failure calling deviceWrite!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
#else
                TRACFCOMP( g_trac_vpd, "testMvpdWrite() - GOOD PATH Expected err from deviceWrite, -NOT- supported in HBRT");
                delete err;
                err = NULL;
#endif
                }
                else
                {
                    // no err so make sure its proper
#ifdef __HOSTBOOT_RUNTIME
                    fails++;
                    TRACFCOMP( g_trac_vpd, "testMvpdWrite() - Expected err from deviceWrite in HBRT");
                    TS_FAIL( "testMvpdWrite() - Unexpected, we should have received err from HBRT from calling deviceWrite!" );
                    continue;
#else
                    TRACFCOMP( g_trac_vpd, "testMvpdWrite() - GOOD PATH results from deviceWrite");
#endif
                }

                // verify the data got written
                cmds++;
                verifyData = new uint8_t[theSize];
                err = deviceRead( theTarget,
                                  verifyData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS(l_record, l_keyword) );
                if( err )
                {
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testMvpdWrite() - failure reading VWML/#I to verify, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testMvpdWrite() - Failure calling deviceRead!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
                }
                TRACFBIN( g_trac_vpd, "testMvpdWrite() - verify=",
                          verifyData, theSize );

                // compare what we read to what we wrote
#ifndef __HOSTBOOT_RUNTIME
                if( memcmp( testData, verifyData, theSize ) )
                {
                    fails++;
                    TS_FAIL( "testMvpdWrite - Data mismatch!" );
                }
#else
                if( memcmp( testData, verifyData, theSize ) )
                {
                    TS_INFO( "testMvpdWrite - Data mismatch! Expected since MVPD Writes during HBRT -NOT- supported" );
                }

#endif
                TRACFBIN( g_trac_vpd, "testMvpdWrite() - wrote=",
                          testData, theSize );
                TRACFBIN( g_trac_vpd, "testMvpdWrite() - read=",
                          verifyData, theSize );

                // put the original data back to be a good citizen
                cmds++;
                err = deviceWrite( theTarget,
                                   origData,
                                   theSize,
                                   DEVICE_MVPD_ADDRESS(l_record, l_keyword) );
                if( err )
                {
#ifndef __HOSTBOOT_RUNTIME
                    fails++;
                    TRACFCOMP( g_trac_vpd,
                               ERR_MRK"testMvpdWrite() - failure writing original data back into VWML/#I, RC=%.4X",
                               err->reasonCode() );
                    TS_FAIL( "testMvpdWrite() - Failure calling deviceRead!" );
                    errlCommit( err,
                                VPD_COMP_ID );
                    continue;
#else
                TRACFCOMP( g_trac_vpd, "testMvpdWrite() - GOOD PATH Expected err from deviceWrite original data, -NOT- supported in HBRT");
                delete err;
                err = NULL;
#endif
                }
                else
                {
                    // no err so make sure its proper
#ifdef __HOSTBOOT_RUNTIME
                    fails++;
                    TRACFCOMP( g_trac_vpd, "testMvpdWrite() - Expected err from deviceWrite in HBRT");
                    TS_FAIL( "testMvpdWrite() - Unexpected, we should have received err from HBRT from calling deviceWrite!" );
                    continue;
#else
                    TRACFCOMP( g_trac_vpd, "testMvpdWrite() - GOOD PATH results from deviceWrite original data");
#endif
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
                TS_FAIL( "testMvpdWrite - No tests ran, something is wrong..." );
            }

            TRACFCOMP( g_trac_vpd,
                       "testMvpdWrite - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a
         *      record is passed in that cannot be found in the structure
         *      that defines the Records string representation.
         */
        void testMvpdInvalidRecord ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testMvpdInvalidRecord()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalProcTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testMvpdInvalidRecord() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS( MVPD::MVPD_LAST_RECORD,
                                                       MVPD::pdR ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testMvpdInvalidRecord() - Error expected with "
                             "record of type MVPD_LAST_RECORD (0x%04x), but "
                             "no error returned!",
                             MVPD::MVPD_LAST_RECORD );
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
                       "testMvpdInvalidRecord - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test for a record which is not in the TOC
         *       of the MVPD area.
         */
        void testMvpdMissingRecord ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testMvpdMissingRecord()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalProcTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testMvpdMissingRecord() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS( MVPD::MVPD_TEST_RECORD,
                                                       MVPD::pdR ) );

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

            TRACFCOMP( g_trac_vpd,
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

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testMvpdMissingKeyword()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalProcTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testMvpdMissingKeyword() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead(theTarget,
                                 theData,
                                 theSize,
                                 DEVICE_MVPD_ADDRESS(MVPD::MVPD_FIRST_RECORD,
                                                     MVPD::MVPD_TEST_KEYWORD));

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL("testMvpdMissingKeyword() - Expected error from "
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
                       "testMvpdMissingKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a
         *      keyword is passed in that cannot be found in the structure
         *      that defines the Keywords string representation.
         */
        void testMvpdInvalidKeyword ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testMvpdInvalidKeyword()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalProcTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testMvpdInvalidKeyword() - No Functional Targets found!");
                    break;
                }

                size_t theSize = 1;
                uint8_t * theData = new uint8_t[theSize];

                cmds++;
                err = deviceRead(theTarget,
                                 theData,
                                 theSize,
                                 DEVICE_MVPD_ADDRESS(MVPD::CRP0,
                                                     MVPD::MVPD_LAST_KEYWORD));

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testMvpdInvalidKeyword() - Error expected with "
                             "keyword of type MVPD_LAST_KEYWORD (0x%04x), but "
                             "no error returned!",
                             MVPD::MVPD_LAST_KEYWORD );
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
                       "testMvpdInvalidKeyword - %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief This function will test that an error is generated when a
         *      buffer that has an insufficient size is passed in to read a
         *      record/keyword.
         */
        void testMvpdInvalidBufferSize ( void )
        {
            errlHndl_t err = NULL;
            uint64_t cmds = 0x0;
            uint64_t fails = 0x0;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testMvpdInvalidBufferSize()" );

            do
            {
                TARGETING::Target * theTarget = getFunctionalProcTarget();
                if(theTarget == NULL)
                {
                    TS_FAIL("testMvpdInvalidBufferSize() - No Functional Targets found!");
                    break;
                }

                uint8_t * theData = new uint8_t[1];
                size_t theSize = 0;

                cmds++;
                err = deviceRead( theTarget,
                                  theData,
                                  theSize,
                                  DEVICE_MVPD_ADDRESS( MVPD::CRP0,
                                                       MVPD::DD ) );

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

            TRACFCOMP( g_trac_vpd,
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
            VPD::vpdRecord prevRecord = MVPD::MVPD_FIRST_RECORD;
            VPD::vpdKeyword prevKeyword = MVPD::MVPD_FIRST_KEYWORD;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testMvpdCheckStructOrder()" );

            // Check the mvpdRecords structure for proper order
            uint32_t entry = 0x0;
            for( entry = 0;
                 entry < (sizeof(MVPD::mvpdRecords)/
                          sizeof(MVPD::mvpdRecords[0]));
                 entry++ )
            {
                if( !(MVPD::mvpdRecords[entry].record >= prevRecord) )
                {
                    fails++;
                    TS_FAIL( "testMvpdCheckStructOrder() - Record table out of "
                             "order! Cur Record: 0x%04x, Prev Record: 0x%04x",
                             MVPD::mvpdRecords[entry].record,
                             prevRecord );
                }
                prevRecord = MVPD::mvpdRecords[entry].record;
            }

            // Check the mvpdKeywords structure for proper order
            for( entry = 0;
                 entry < (sizeof(MVPD::mvpdKeywords)/\
                          sizeof(MVPD::mvpdKeywords[0]));
                 entry++ )
            {
                if( !(MVPD::mvpdKeywords[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL("testMvpdCheckStructOrder() - Keyword table out of "
                            "order! Cur Keyword: 0x%04x, Prev Keyword: 0x%04x",
                            MVPD::mvpdKeywords[entry].keyword,
                            prevKeyword );
                }
                prevKeyword = MVPD::mvpdKeywords[entry].keyword;
            }

            TRACFCOMP( g_trac_vpd,
                       "testMvpdCheckStructOrder - %d fails",
                       fails );
        }
};

#endif
