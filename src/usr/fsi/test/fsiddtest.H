//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/fsi/test/fsiddtest.H $
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
#ifndef __FSIDDTEST_H
#define __FSIDDTEST_H

/**
 *  @file fsiddtest.H
 *
 *  @brief Test cases for FSI Device Driver
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <limits.h>
#include <devicefw/driverif.H>
#include "../fsidd.H"

extern trace_desc_t* g_trac_fsi;


class FsiDDTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief FSI DD test - Read/Write
     *        Perform basic read/write operations
     */
    void test_readWrite(void)
    {
        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_readWrite> Start" );        
        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = NULL;

        // scratch data to use
        struct {
            uint64_t addr;
            uint32_t data;
            bool writeable;
        } test_data[] = {
            //** Master Control Space
            // version number
            { FsiDD::CMFSI_CONTROL_REG | 0x000074, 0x91010800, false }, 
            { FsiDD::MFSI_CONTROL_REG | 0x000074, 0x91010800, false }, 

            // clock rate delay for ports 32-63 (unused ports)
            { FsiDD::MFSI_CONTROL_REG | 0x00000C, 0x11111111, true }, 
            { FsiDD::CMFSI_CONTROL_REG | 0x00000C, 0x22222222, true }, 

            // port static level
            { FsiDD::MFSI_CONTROL_REG | 0x000018, 0x80000000, false }, //port0
            { FsiDD::MFSI_CONTROL_REG | 0x00001C, 0x00000000, false }, 
            { FsiDD::CMFSI_CONTROL_REG | 0x000018, 0x00000000, false }, 
            { FsiDD::CMFSI_CONTROL_REG | 0x00001C, 0x00000000, false }, 

            //** Master Control Regs in Port space
            //{ FsiDD::MFSI_PORT_0 | 0x000000, 0x91010800, false }, //Slave Config Table
        };
        const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

        // allocate some space to play with
        uint32_t read_data[NUM_ADDRS];
        size_t op_size = sizeof(uint32_t);

        // target the master processor
        TARGETING::TargetService& targetService = TARGETING::targetService();
        TARGETING::Target* fsi_target = NULL;
        targetService.masterProcChipTargetHandle( fsi_target );

        // read address X,Y,Z
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            total++;
            TRACFCOMP( g_trac_fsi, "FsiDDTest::test_readWrite> Reading %llX", test_data[x].addr );
	    l_err = DeviceFW::deviceOp( DeviceFW::READ,
					fsi_target, 
					&(read_data[x]),
					op_size,
					DEVICE_FSI_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : addr=0x%X, RC=%X", test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from read1" );
                fails++;
                errlCommit(l_err);
                delete l_err;
            }

            TRACFCOMP( g_trac_fsi, "READ Reg 0x%X = 0x%X", test_data[x].addr, read_data[x] );

            //@todo - check op_size
        }

        // write X=A, Y=B, Z=C
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            if( test_data[x].writeable )
            {
                total++;
                l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                            fsi_target, 
                                            &(test_data[x].data),
                                            op_size,
                                            DEVICE_FSI_ADDRESS(test_data[x].addr) );
                if( l_err )
                {
                    TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : addr=0x%X, RC=%X", test_data[x].addr, l_err->reasonCode() );
                    TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from write1" );
                    fails++;
                    errlCommit(l_err);
                    delete l_err;
                }

                //@todo - check op_size
            }
        }

        // read X,Y,Z
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            total++;
	    l_err = DeviceFW::deviceOp( DeviceFW::READ,
					fsi_target, 
					&(read_data[x]),
					op_size,
					DEVICE_FSI_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : addr=0x%X, RC=%X", test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from read2" );
                fails++;
                errlCommit(l_err);
                delete l_err;
            }

            //@todo - check op_size
        }

        // verify X==A, Y==B, Z==C
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            total++;
            if( read_data[x] != test_data[x].data )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Data mismatch : addr=0x%X, exp=0x%X, act=0x%X", test_data[x].addr, test_data[x].data, read_data[x] );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Data mismatch" );
                fails++;                
            }
        }

        //@todo - repeat for each address space
        
        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_readWrite> %d/%d fails", fails, total );
    };

    /**
     * @brief FSI DD test - verifyAddressRange
     *        Test output of verifyAddressRange
     */
    void test_verifyAddressRange(void)
    {
        TRACFCOMP( g_trac_fsi, "FsiDDTest::verifyAddressRange> Start" );
        uint64_t fails = 0;
        uint64_t total = 0;

        //@todo
        // values to try:
        // -address 0
        // -valid address at the beginning (if not 0)
        // -valid address and size in the middle
        // -valid address and size that hit the end of the range
        // -valid address and size that exceeds range
        // -address beyond range
        // -address before beginning (if not 0)

        
        TRACFCOMP( g_trac_fsi, "FsiDDTest::verifyAddressRange> %d/%d fails", fails, total );
    };

};     


#endif
