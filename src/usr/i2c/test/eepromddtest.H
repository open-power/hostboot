//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/i2c/test/eepromddtest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#ifndef __EEPROMTEST_H
#define __EEPROMTEST_H

/**
 *  @file eepromtest.H
 *
 *  @brief Test cases for the eeprom dd code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <devicefw/driverif.H>
#include <i2c/eepromddreasoncodes.H>
#include <targeting/predicates/predicatectm.H>
#include <targeting/predicates/predicatepostfixexpr.H>

extern trace_desc_t* g_trac_eeprom;

using namespace TARGETING;

class EEPROMTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief EEPROM Read/Write Test
         *      This test will test a variety of reads/writes and lengths
         *      across slave devices.
         */
        void testEEPROMReadWrite ( void )
        {
            errlHndl_t err = NULL;
            int fails = 0;
            int num_ops = 0;

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMReadWrite - Start" );

            struct
            {
                uint64_t addr;      // Slave Device Address to access
                uint64_t chip;      // Which EEPROM chip hung off of the target to access
                uint64_t data;      // Data to write or compare to
                size_t   size;      // Number of bytes to read/write
                bool     rnw;       // Read (true), Write (false)
            } testData[] =
            {
                { 0x1111, 0x0, 0xfedcba9876543210, 8, false },    // Write data
                { 0x1111, 0x0, 0xfedcba9876543210, 8, true  },    // Read data
                { 0x2222, 0x0, 0xaabb000000000000, 2, false },
                { 0x2222, 0x0, 0xaabb000000000000, 2, true  },
                { 0x1122, 0x0, 0x1122334400000000, 4, false },
                { 0x1122, 0x0, 0x1122334400000000, 4, true  },
            };

            const uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);

            //@TODO
            //@VBU workaround - Disable I2C test case on fake target
            //Test case use fake targets, which will fail when running
            //on VBU.  Need to fix this.
            TARGETING::EntityPath syspath(TARGETING::EntityPath::PATH_PHYSICAL);
            syspath.addLast(TARGETING::TYPE_SYS,0);
            TARGETING::Target* sys = TARGETING::targetService().toTarget(syspath);
            uint8_t vpo_mode = 0;
            if( sys
                && sys->tryGetAttr<TARGETING::ATTR_IS_SIMULATION>(vpo_mode)
                && (vpo_mode == 1) )
            {
                return;
            }

            do
            {
                // Get a processor Target
                TARGETING::TargetService& l_targetService = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                l_targetService.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);
                TargetHandleList fullList;
                fullList.push_back( testTarget );

                // TODO - The following is what I want to use...  BUT, since we
                // can't target DIMMs yet, and only Proc 0 has a slave device
                // hung off of it, we can't do that yet.  Uncomment the following
                // when it is supported.
//                TARGETING::TargetService& tS = TARGETING::targetService();
//                TARGETING::Target * sysTarget = NULL;
//                TargetHandleList fullList;

//                // Get top level system target
//                tS.getTopLevelTarget( sysTarget );
//                assert( sysTarget != NULL );

//                // Predicate for the Procs
//                TARGETING::PredicateCTM predProc( TARGETING::CLASS_CHIP,
//                                                  TARGETING::TYPE_PROC );

//                // Predicate for the DIMMs
//                TARGETING::PredicateCTM predDimm( TARGETING::CLASS_CARD,
//                                                  TARGETING::TYPE_DIMM );

//                // Expression to get both Procs and DIMMs.
//                PredicatePostfixExpr query;
//                query.push( &predProc ).push( &predDimm ).Or();
//                tS.getAssociated( fullList,
//                                  sysTarget,
//                                  TARGETING::TargetService::CHILD,
//                                  TARGETING::TargetService::ALL,
//                                  &query );
//                assert( 0 != fullList.size() );

                // Number of total operations
                num_ops = fullList.size() * NUM_CMDS;

                for( uint32_t j = 0; j < fullList.size(); j++ )
                {
                    for( uint32_t i = 0; i < NUM_CMDS; i++ )
                    {
                        uint64_t data;

                        // if a read, initialize data, else, set data to write
                        if( testData[i].rnw )
                        {
                            data = 0x0ull;
                        }
                        else
                        {
                            data = testData[i].data;
                        }

                        // do the operation
                        err = deviceOp( (testData[i].rnw ? DeviceFW::READ : DeviceFW::WRITE),
                                        fullList[j],
                                        &data,
                                        testData[i].size,
                                        DEVICE_EEPROM_ADDRESS( testData[i].addr,
                                                               testData[i].chip ) );

                        if( err )
                        {
                            TS_FAIL( "testEEPROMReadWrite - fail on cmd %d out of %d",
                                     i, NUM_CMDS );
                            errlCommit( err,
                                        EEPROM_COMP_ID );
                            delete err;
                            fails++;
                            continue;
                        }

                        // compare data for the read
                        if( testData[i].rnw )
                        {
                            if( data != testData[i].data )
                            {
                                TRACFCOMP( g_trac_eeprom,
                                           "testEEPROMReadWrite - cmd: %d/%d, Data read: %016llx, "
                                           "expected: %016llx",
                                           i, NUM_CMDS, data, testData[i].data );
                                TS_FAIL( "testEEPROMReadWrite - Failure comparing read data!" );
                                fails++;
                                continue;
                            }
                        }
                    }
                }
            } while( 0 );

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMReadWrite - %d/%d fails",
                       fails, num_ops );
        }

        /**
         * @brief EEPROM Invalid Operation Test
         *      This test will pass in an invalid Operation type.  It
         *      is expected that an error log is to be returned.
         */
        void testEEPROMInvalidOperation ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 8;

            do
            {
                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                num_ops++;
                err = deviceOp( DeviceFW::LAST_OP_TYPE,
                                testTarget,
                                &data,
                                dataSize,
                                DEVICE_EEPROM_ADDRESS( 0x0,
                                                       0x0 ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "Error should've resulted in Operation type of LAST_OP_TYPE!" );
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );
            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMInvalidOperation - %d/%d fails",
                       fails, num_ops );
        }

        /**
         * @brief EEPROM Invalid Chip Test
         *      This test will pass in an invalid chip identifier which should
         *      result in an error being returned back from
         */
        void testEEPROMInvalidChip ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 8;

            const int64_t CHIP_NUM = 20;

            do
            {
                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                num_ops++;
                err = deviceOp( DeviceFW::WRITE,
                                testTarget,
                                &data,
                                dataSize,
                                DEVICE_EEPROM_ADDRESS( 0x0,
                                                       CHIP_NUM ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "Error should've resulted in using EEPROM chip %d!",
                             CHIP_NUM );
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMInvalidChip - %d/%d fails",
                       fails, num_ops );
        }

};

#endif
