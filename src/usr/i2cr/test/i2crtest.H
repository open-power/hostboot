/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2cr/test/i2crtest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2024                        */
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
#ifndef __I2CRTEST_H
#define __I2CRTEST_H

/**
 *  @file i2ctest.H
 *
 *  @brief Test cases for I2CR driver
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <i2cr/i2cr_reasoncodes.H>
#include <i2c/i2cif.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>
#include "../i2cr.H"
#include <secureboot/service.H>
#include <utils/chipids.H>

#include <arch/magic.H>
#include <devicefw/driverif.H>
#include <console/consoleif.H>

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

//#define SIMICS_BP   MAGIC_INSTRUCTION(MAGIC_BREAK);
#define SIMICS_BP

#define  FUNCTIONAL  true

using namespace TARGETING;
using namespace I2C;
using namespace I2CR;


constexpr uint8_t I2CR_SCOM_ACCESS      =   0;
constexpr uint8_t I2CR_CFAM_ACCESS      =   1;
constexpr uint8_t DIRECT_CFAM_ACCESS    =   2;
constexpr uint8_t TOTAL_ACCESS_TYPES    =   3;


// The following constant is the number to OCMB chips to exercise.
// It also determines the number of values to be provided to
// exercise each OCMB chip with a unique value.
constexpr uint8_t NUM_OCMB_TARGETS      =   3;

typedef struct structI2crTest
{
    uint8_t accessType;
    uint32_t regAddr;
    size_t   numBytes;
    uint64_t value[NUM_OCMB_TARGETS];
} i2crData_t;

typedef struct structI2crRecovery
{
    uint8_t accessType;
    uint32_t regAddr;
    size_t   numBytes;
    uint64_t writeVal;
    uint64_t readVal;
    bool writeMustPass;
    bool readMustPass;
} i2crRec_t;

class I2CRTest : public CxxTest::TestSuite
{
public:

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

    /**
     * @brief i2cr_op
     *      This function reads or writes from the specified Scom/Cfam register
     * @input i_tgt : target
     * @input i_regaddr : I2CR address to read from or write to
     * @input i_op : operation READ or WRITE
     * @input i_accessType : access type that determines what interface we use
     * @input io_buffer : buffer to return the value read
     * @input i_numbytes : number of bytes to read/write
     */
    errlHndl_t i2cr_op( TARGETING::Target* i_tgt, uint32_t i_regaddr,
                        DeviceFW::OperationType i_op, uint8_t i_accessType,
                        uint8_t *io_buffer, size_t i_numbytes )
    {
        errlHndl_t l_err = nullptr;

        switch (i_accessType)
        {
        case I2CR_SCOM_ACCESS:
            TS_INFO("i2cr_op: I2CR Scom addr: 0x%.16x i_op=%d i_accessType=%d "
                    "target=0x%.8X", i_regaddr, i_op, i_accessType,
                    TARGETING::get_huid(i_tgt));
            l_err = DeviceFW::deviceOp(i_op, i_tgt, io_buffer, i_numbytes,
                                       DEVICE_I2CR_SCOM_ADDRESS(i_regaddr));
            break;

        case I2CR_CFAM_ACCESS:
            // Read as I2CR CFAM
            TS_INFO("i2cr_op: I2CR CFAM addr: 0x%.16x i_op=%d i_accessType=%d "
                    "target=0x%.8X", i_regaddr, i_op, i_accessType,
                    TARGETING::get_huid(i_tgt));
            l_err = DeviceFW::deviceOp(i_op, i_tgt, io_buffer, i_numbytes,
                                       DEVICE_I2CR_CFAM_ADDRESS(i_regaddr));
            break;

        case DIRECT_CFAM_ACCESS:
            // Read as CFAM
            TS_INFO("i2cr_op: CFAM addr: 0x%.16x i_op=%d i_accessType=%d "
                    "target=0x%.8X", i_regaddr, i_op, i_accessType,
                    TARGETING::get_huid(i_tgt));
            l_err = DeviceFW::deviceOp(i_op, i_tgt, io_buffer, i_numbytes,
                                       DEVICE_CFAM_ADDRESS(i_regaddr));
            break;

        default:
            // Invalid test case present. This should not happen.
            TS_INFO("Bad access type:%d target=0x%.8X", i_accessType,
                    TARGETING::get_huid(i_tgt));
            break;
        }

        if (l_err)
        {
            TS_INFO("i2cr_op: Error doing operation:%s @ 0x%x",
                    ((i_op == DeviceFW::READ) ? "Read":"Write"), i_regaddr);
        }
        else
        {
            TS_INFO("i2cr_op: Tgt:0x%.8X Operation:%s @0x%.8X=0x%.16X (%d bytes)",
                      TARGETING::get_huid(i_tgt),
                      ((i_op == DeviceFW::READ) ? "Read":"Write"),
                      i_regaddr, *(reinterpret_cast<uint64_t *>(io_buffer)),
                      i_numbytes);
        }
        return l_err;
    }


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

    /**
     * @brief I2CR Read
     *      This function reads from a known Scom/Cfam register
     */
    void testI2crRead( void )
    {
        static const i2crData_t i2crData[TOTAL_ACCESS_TYPES] =
                     {I2CR_SCOM_ACCESS,   0x000F000F, 8, 0x160C004900000000, 0x0, 0x0,
                      I2CR_CFAM_ACCESS,   0x100A,     4, 0x160C004900000000, 0x0, 0x0,
                      DIRECT_CFAM_ACCESS, 0x100A,     4, 0x160C004900000000, 0x0, 0x0};

        int l_count = NUM_OCMB_TARGETS; // Number of OCMB chips to exercise
        int l_tests = l_count * TOTAL_ACCESS_TYPES;
        uint8_t  l_fails= 0;
        uint8_t  l_buffer[8] = { 0 };
        errlHndl_t l_err = nullptr;

        TS_INFO("testI2crRead - Start");

        // Get all the OCMB chips and pick the first l_count number of chips/targets
        // to do the reads and save them.
        TARGETING::TargetHandleList allchips;
        TARGETING::getAllChips( allchips, TARGETING::TYPE_OCMB_CHIP, FUNCTIONAL );

        for( TARGETING::TargetHandleList::iterator tgt = allchips.begin();
             (tgt != allchips.end()) && (l_count>0);
              ++tgt )
        {
            // Ensure we are dealing with Odyssey Chip and not Explorer
            TARGETING::ATTR_CHIP_ID_type l_chipId = (*tgt)->getAttr<ATTR_CHIP_ID>();
            if (l_chipId != POWER_CHIPID::ODYSSEY_16)
            {
                TS_INFO("testI2crRead: Not an Odyssey Chip!");
                continue;
            }

            // For each target, go thru all the access types and test using the data
            for (const auto & tc : i2crData)
            {
                TS_INFO("testI2crRead: READ Tgt:0x%.8X Addr: 0x%x", get_huid(*tgt), tc.regAddr);
                l_err = I2CRTest::i2cr_op(*tgt, tc.regAddr, DeviceFW::READ,
                                          tc.accessType, l_buffer, tc.numBytes);
                if( l_err )
                {
                    TS_FAIL("testI2crRead: failed for %d[0x%.16X]: Failure from driver!!!",
                             tc.accessType, tc.regAddr);
                    l_fails++;
                    errlCommit( l_err,I2CR_COMP_ID );
                }
                else
                {
                    // Check the value to see if it is what we expect
                    if (memcmp(l_buffer, &tc.value[0], tc.numBytes))
                    {
                        TS_FAIL( "testI2crRead: failed: Value is different [0x%llX Vs 0x%llX]!!",
                                 tc.value[0], *reinterpret_cast<uint64_t *>(l_buffer));
                        l_fails++;
                    }
                    else
                    {
                       TS_INFO("testI2crRead: Matched 0x%llx and 0x%llx",
                                *(reinterpret_cast<uint64_t *>(l_buffer)), tc.value[0]);
                    }
                }
            } // end of for loop

            --l_count; // Decrement the target count
        } // end of for loop

        TS_INFO("testI2crRead - End: Test count=%d fails=%d", l_tests, l_fails);
    }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

    /**
     * @brief I2CR Write
     *      This function writes to Scom/Cfam register and verifies it by
     *      reading back the data and comparing with the expected value.
     */
    void testI2crWrite( void )
    {
        static const i2crData_t i2crData[TOTAL_ACCESS_TYPES] =
        {I2CR_SCOM_ACCESS,  0x50039, 8, 0x123456789000ABCD, 0xFFFFFFFFFFFFFFFF, 0xA5A5A5A50FF00FF0,
         I2CR_CFAM_ACCESS,   0x2838, 4, 0xABCDDCBA00000000, 0xFFFFFFFF00000000, 0xBADC0FFE00000000,
         DIRECT_CFAM_ACCESS, 0x283A, 4, 0xDAD4C00100000000, 0xFFFFFFFF00000000, 0xF0F0F0F000000000};

        int l_tests = TOTAL_ACCESS_TYPES * NUM_OCMB_TARGETS;
        uint8_t  l_fails= 0;
        uint64_t l_buffer = 0x0ULL;
        uint8_t  l_readbuf[8] = { 0 };
        errlHndl_t l_err = nullptr;
        uint8_t  l_index = 0;

        TS_INFO("testI2crWrite - Start");

        // Get all the OCMB chips but just pick the first l_count number of chips/targets
        // to do the writes.
        TARGETING::TargetHandleList allchips;
        TARGETING::getAllChips( allchips, TARGETING::TYPE_OCMB_CHIP, FUNCTIONAL );

        for( TARGETING::TargetHandleList::iterator tgt = allchips.begin();
             (tgt != allchips.end()) && (l_index < NUM_OCMB_TARGETS);
              ++tgt )
        {
            // Ensure we are dealing with Odyssey Chip and not Explorer
            TARGETING::ATTR_CHIP_ID_type l_chipId = (*tgt)->getAttr<ATTR_CHIP_ID>();
            if (l_chipId != POWER_CHIPID::ODYSSEY_16)
            {
                TS_INFO("testI2crWrite: Not an Odyssey Chip!");
                continue;
            }

            TS_INFO("testI2crWrite: Writing to Tgt OCMB chip=0x%x, (0x%.8X)",
                       *tgt, TARGETING::get_huid(*tgt));

            // For each target, go thru all the access types and test using the data
            for (const auto & tc : i2crData)
            {
                // Initialize the buffer with a value for testing
                // We are using a different value for each target
                l_buffer = tc.value[l_index];

                TS_INFO("testI2crWrite: WRITE TEST: (tgt:0x%x-%d) 0x%.16X : 0x%x",
                        get_huid(*tgt), l_index, l_buffer, tc.regAddr);
                l_err = I2CRTest::i2cr_op(*tgt, tc.regAddr, DeviceFW::WRITE,
                                          tc.accessType,
                                          reinterpret_cast<uint8_t *>(&l_buffer), tc.numBytes);
                if( l_err )
                {
                    TS_FAIL("testI2crWrite: Write failed for %d[0x%.16X]: Failure from driver!!!",
                             tc.accessType, tc.regAddr);
                    l_fails++;
                    errlCommit( l_err,I2CR_COMP_ID );
                    continue;
                }

            } // end of for loop

            TS_INFO("testI2crWrite: Reading from Tgt OCMB chip=0x%x", get_huid(*tgt));

            // Read back all the registers for this target
            for (const auto & tc : i2crData)
            {
                    memset(l_readbuf, 0, sizeof(l_readbuf));

                    TS_INFO("testI2crWrite: Reading back value @: 0x%x", tc.regAddr);
                    l_err = I2CRTest::i2cr_op(*tgt, tc.regAddr, DeviceFW::READ,
                                               tc.accessType, l_readbuf, tc.numBytes);
                    if( l_err )
                    {
                        TS_FAIL("testI2crWrite: Reading Back failed for %d[0x%.16X]:"
                                " Failure from driver!!!", tc.accessType, tc.regAddr);
                        l_fails++;
                        errlCommit( l_err,I2CR_COMP_ID );
                        continue;
                    }

                    // Now compare the values
                    if (memcmp(l_readbuf, &tc.value[l_index], tc.numBytes))
                    {
                        TS_FAIL("testI2crWrite: Read:0x%llX Exp:0x%llX",
                                 *reinterpret_cast<uint64_t *>(l_readbuf), tc.value[l_index]);
                        l_fails++;
                    }
                    else
                    {
                       TS_INFO("testI2crWrite: Matched 0x%llx and 0x%llx",
                                *(reinterpret_cast<uint64_t *>(l_readbuf)), tc.value[l_index]);
                    }
            } // end of for loop

            l_index++; // next target and for new value

        } // end of for loop

        TS_INFO("testI2crWrite - End: Test count=%d fails=%d", l_tests, l_fails);
    }



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

    /**
     * @brief testI2crRecovery
     *      This function writes to a Scom/CFAM readonly register (which is
     *      expected to fail) and then writes to a valid register. This
     *      write should succeed and test that I2CR has recovered from errors.
     *      There are three access types supported and for each access type
     *      the following exercises are done:
     *      1. Write to an invalid address
     *      2. Write to a read only register
     *      3. Write to a valid register, but the value written is ALL_ONES
     *      4. Write to a valid register
     */
    void testI2crRecovery( void )
    {
        static const i2crRec_t i2crData[TOTAL_ACCESS_TYPES * 4] =
        {
         I2CR_SCOM_ACCESS, 0x50099, 8, 0xAAAABBBBCCCCDDDD, 0xAAAABBBBCCCCDDDD, false, false,
         I2CR_SCOM_ACCESS, 0xF000F, 8, 0x12345678DCBAABCD, 0x160C004900000000, false, true,
         I2CR_SCOM_ACCESS, 0x5003B, 8, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, true, true,
         I2CR_SCOM_ACCESS, 0x50039, 8, 0xAAAABBBBCCCCDDDD, 0xAAAABBBBCCCCDDDD, true, true,
         I2CR_CFAM_ACCESS, 0x9000,  4, 0xABCDEF1200000000, 0xABCDEF1200000000, false, false,
         I2CR_CFAM_ACCESS, 0x100A,  4, 0xFFFF111100000000, 0x160C004900000000, false, true,
         I2CR_CFAM_ACCESS, 0x2838,  4, 0xFFFFFFFF00000000, 0xFFFFFFFF00000000, true, true,
         I2CR_CFAM_ACCESS, 0x283C,  4, 0xABCDEF1200000000, 0xABCDEF1200000000, true, true,
         DIRECT_CFAM_ACCESS, 0x8000,  4, 0xBADC0FFE00000000, 0xBADC0FFE00000000, false, false,
         DIRECT_CFAM_ACCESS, 0x100A,  4, 0xABABABAB00000000, 0x160C004900000000, false, true,
         DIRECT_CFAM_ACCESS, 0x283A,  4, 0xFFFFFFFF00000000, 0xFFFFFFFF00000000, true, true,
        };

        int l_tests = TOTAL_ACCESS_TYPES * 4;
        uint8_t  l_fails= 0;
        uint64_t l_buffer = 0x0ULL;
        uint8_t  l_readbuf[8] = { 0 };
        errlHndl_t l_err = nullptr;
        uint8_t  l_index = 0;

        TS_INFO("testI2cRecovery - Start");

        // Get all the OCMB chips but just pick the first OCMB target
        // to do the tests for all types of accesses.
        TARGETING::TargetHandleList allchips;
        TARGETING::getAllChips( allchips, TARGETING::TYPE_OCMB_CHIP, FUNCTIONAL );

        for( TARGETING::TargetHandleList::iterator tgt = allchips.begin();
             (tgt != allchips.end()) && (l_index < 1);
              ++tgt )
        {
            // Ensure we are dealing with Odyssey Chip and not Explorer
            TARGETING::ATTR_CHIP_ID_type l_chipId = (*tgt)->getAttr<ATTR_CHIP_ID>();
            if (l_chipId != POWER_CHIPID::ODYSSEY_16)
            {
                TS_INFO("testI2crRecovery: Not an Odyssey Chip!");
                continue;
            }

            TS_INFO("testI2crRecovery: Writing to Tgt OCMB chip=0x%x, (0x%.8X)",
                       *tgt, TARGETING::get_huid(*tgt));

            // For each target, go thru all the access types and test using the data
            for (const auto & tc : i2crData)
            {
                // Initialize the buffer with a value for testing
                l_buffer = tc.writeVal;

                TS_INFO("testI2crRecovery: WRITE TEST: (tgt:0x%x-%d) 0x%.16X @:0x%x",
                        get_huid(*tgt), l_index, l_buffer, tc.regAddr);
                l_err = I2CRTest::i2cr_op(*tgt, tc.regAddr, DeviceFW::WRITE,
                                          tc.accessType,
                                          reinterpret_cast<uint8_t *>(&l_buffer), tc.numBytes);
                if( l_err )
                {
                    // We have a failure. Check if we expect it to fail or not...
                    if (tc.writeMustPass)
                    {
                        // Testcase should have passed, instead got a failure!
                        TS_FAIL( "testI2crRecovery: Recovery Failed!!: A:0%x V:0x%llx",
                                  tc.regAddr, l_buffer );
                        l_fails++;
                        errlCommit( l_err,I2CR_COMP_ID );
                    }
                    else
                    {
                        TS_INFO("testI2crRecovery: failed as expected");
                        delete l_err;
                        l_err = nullptr;
                    }
                }
            } // end of for loop

            TS_INFO("testI2crRecovery: Reading from Tgt OCMB chip=0x%x", get_huid(*tgt));

            // Read back all the registers for this target
            for (const auto & tc : i2crData)
            {
                    memset(l_readbuf, 0, sizeof(l_readbuf));

                    TS_INFO("testI2crRecovery: Reading back value @: 0x%x", tc.regAddr);
                    l_err = I2CRTest::i2cr_op(*tgt, tc.regAddr, DeviceFW::READ,
                                               tc.accessType, l_readbuf, tc.numBytes);

                    if( l_err )
                    {
                        // We have a failure. Check if we expect it to fail or not...
                        if (tc.readMustPass)
                        {
                            TS_FAIL("testI2crRecovery: Reading Back failed for %d[0x%.16X]:"
                                    " Failure from driver!!!", tc.accessType, tc.regAddr);
                            l_fails++;
                            errlCommit( l_err,I2CR_COMP_ID );
                        }
                        else
                        {
                             TS_INFO("testI2crRecovery: failed as expected");
                             delete l_err;
                             l_err = nullptr;
                         }

                         // The read has failed, so no point comparing the value.
                         // Just go to the next testcase.
                         continue;
                    }

                    // Skip compares if we expect both read & writes to fail
                    if ((!tc.readMustPass) && (!tc.writeMustPass))
                    {
                        // Just go to the next testcase.
                        continue;
                    }

                    // Now compare the values
                    TS_INFO("testI2crRecovery: Comparing 0x%llx with 0x%llx",
                            *reinterpret_cast<uint64_t *>(l_readbuf), tc.readVal);

                    if (memcmp(l_readbuf, &tc.readVal, tc.numBytes))
                    {
                        TS_FAIL("testI2crRecovery: Read:0x%llX Exp:0x%llX",
                                 *reinterpret_cast<uint64_t *>(l_readbuf), tc.readVal);
                        l_fails++;
                    }
                    else
                    {
                       TS_INFO("testI2crRecovery: Matched 0x%llx and 0x%llx",
                                *(reinterpret_cast<uint64_t *>(l_readbuf)), tc.readVal);
                    }
            } // end of for loop

            l_index++; // next target

        } // end of for loop

        TS_INFO("testI2crRecovery - End: Test count=%d fails=%d", l_tests, l_fails);
    }


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


    /**
     * @brief I2CR Invalid Target
     *      This function reads from an invalid target
     */
    void testI2crInvalidTarget( void )
    {
        i2crData_t i2crData[TOTAL_ACCESS_TYPES] =
              {I2CR_SCOM_ACCESS,   0x000F000F, 8, 0x160C004900000000, 0x0, 0x0,
               I2CR_CFAM_ACCESS,   0x100A,     4, 0x160C0049, 0x0, 0x0,
               DIRECT_CFAM_ACCESS, 0x100A,     4, 0x160C0049, 0x0, 0x0};
        int l_count = 1; // Number of targets to exercise
        int l_tests = l_count * TOTAL_ACCESS_TYPES;
        uint8_t  l_fails= 0;
        uint8_t  l_buffer[8] = { 0 };
        errlHndl_t l_err = nullptr;

        TS_INFO("testI2crInvalidTarget - Start" );

        // Get all the PHB types and pick the first l_count number of chips/targets
        // to do the reads.
        TARGETING::TargetHandleList allchips;
        TARGETING::getAllChips( allchips, TARGETING::TYPE_PHB, FUNCTIONAL );

        for( TARGETING::TargetHandleList::iterator tgt = allchips.begin();
             (tgt != allchips.end()) && (l_count>0);
             ++tgt, --l_count )
        {
            // For each target, go thru all the access types and test using the data
            for (const auto & tc : i2crData)
            {
                TS_INFO("testI2crInvalidTarget: Addr: 0x%x", tc.regAddr);
                l_err = I2CRTest::i2cr_op(*tgt, tc.regAddr, DeviceFW::READ,
                                          tc.accessType, l_buffer, tc.numBytes);
                if( l_err )
                {
                    TS_INFO("testI2crInvalidTarget: failed as expected");
                    delete l_err;
                    l_err = nullptr;
                }
                else
                {
                    // We did not get a failure!!
                    TS_FAIL("testI2crInvalidTarget: Testcase did not fail!!");
                    l_fails++;
                    errlCommit( l_err,I2CR_COMP_ID );
                }
            } // end of for loop
        } // end of for loop

        TS_INFO("testI2crInvalidTarget - End: Test count=%d fails=%d", l_tests, l_fails);
    }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

    /**
     * @brief I2CR Bad Address
     *      This function tries to read from an address that is invalid.
     *      The address used here is of invalid length.
     */
    void testI2crBadAddress( void )
    {
        uint8_t  l_buffer[8] = { 0 };
        uint8_t  l_fails= 0;
        size_t   l_sz = 8;
        int l_count = 1; // Number of OCMB chips to exercise
        int l_tests = l_count;
        errlHndl_t l_err = nullptr;

        TS_INFO("testI2crBadAddress - Start");

        // Get all the OCMB chips and pick the first l_count number of chips/targets
        // to do the reads.
        TARGETING::TargetHandleList allchips;
        TARGETING::getAllChips( allchips, TARGETING::TYPE_OCMB_CHIP, FUNCTIONAL );

        for( TARGETING::TargetHandleList::iterator tgt = allchips.begin();
             (tgt != allchips.end()) && (l_count>0);
              ++tgt )
        {
            // Ensure we are dealing with Odyssey Chip and not Explorer
            TARGETING::ATTR_CHIP_ID_type l_chipId = (*tgt)->getAttr<ATTR_CHIP_ID>();
            if (l_chipId != POWER_CHIPID::ODYSSEY_16)
            {
                TS_INFO("testI2crBadAddress: Not an Odyssey Chip!");
                continue;
            }

            TS_INFO("testI2crBadAddress: Read addr: 0x1111222233334444");
            l_err = DeviceFW::deviceOp(DeviceFW::READ, *tgt, l_buffer, l_sz,
                                       DEVICE_I2CR_SCOM_ADDRESS(0x1111222233334444));
            if( l_err )
            {
                TS_INFO("testI2crBadAddress: failed as expected");
                delete l_err;
                l_err = nullptr;
            }
            else
            {
                // We did not get a failure!!
                TS_FAIL( "testI2crBadAddress: Testcase did not fail!!");
                l_fails++;
                errlCommit( l_err,I2CR_COMP_ID );
            }
            --l_count; // update the target count
        } // end of for loop

        TS_INFO("testI2crBadAddress - End: Test count=%d fails=%d", l_tests, l_fails);
    }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


    /**
     * @brief I2CR Read Regs
     *      This function is to check if we can read from the I2CR
     *      status/error/config registers
     */
    void testI2crReadRegs( void )
    {
        static const i2crData_t i2crData[4] =
                   {I2CR_SCOM_ACCESS,   0x30000, 8, 0x0, 0x0, 0x0,
                    I2CR_SCOM_ACCESS,   0x30001, 8, 0x0, 0x0, 0x0,
                    I2CR_SCOM_ACCESS,   0x30002, 8, 0x0, 0x0, 0x0,
                    I2CR_SCOM_ACCESS,   0x30004, 8, 0x0, 0x0, 0x0};
        int l_count = 1; // Number of OCMB chips to exercise
        int l_tests = l_count * 4;
        uint8_t  l_fails= 0;
        uint8_t  l_buffer[8] = { 0 };
        errlHndl_t l_err = nullptr;

        TS_INFO("testI2crReadRegs - Start");

        // Get all the OCMB chips and pick the first l_count number of chips/targets
        // to do the reads and save them.
        TARGETING::TargetHandleList allchips;
        TARGETING::getAllChips( allchips, TARGETING::TYPE_OCMB_CHIP, FUNCTIONAL );

        for( TARGETING::TargetHandleList::iterator tgt = allchips.begin();
             (tgt != allchips.end()) && (l_count>0);
              ++tgt )
        {
            // Ensure we are dealing with Odyssey Chip and not Explorer
            TARGETING::ATTR_CHIP_ID_type l_chipId = (*tgt)->getAttr<ATTR_CHIP_ID>();
            if (l_chipId != POWER_CHIPID::ODYSSEY_16)
            {
                TS_INFO("testI2crReadRegs: Not an Odyssey Chip!");
                continue;
            }

            // For each target, go thru all the access types and test using the data
            for (const auto & tc : i2crData)
            {
                TS_INFO("testI2crReadRegs: Reading register: 0x%x", tc.regAddr);
                l_err = I2CRTest::i2cr_op(*tgt, tc.regAddr, DeviceFW::READ,
                                          tc.accessType, l_buffer, tc.numBytes);
                if( l_err )
                {
                    TS_FAIL("testI2crReadReg: failed for %d[0x%.16X]: Failure from driver!!!",
                             tc.accessType, tc.regAddr);
                    l_fails++;
                    errlCommit( l_err,I2CR_COMP_ID );
                }
                else
                {
                    TS_INFO( "testI2crReadRegs:  Value @0x%x = 0x%.16X !!",
                             tc.regAddr, *(reinterpret_cast<uint64_t *>(l_buffer)));
                }
            } // end of for loop

            --l_count; // update the target count
        } // end of for loop

        TS_INFO("testI2crReadRegs - End: Test count=%d fails=%d", l_tests, l_fails);
    }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

};

#endif

