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
#include <fsi/fsiif.H>
#include <fsi/fsi_reasoncodes.H>
#include <sys/time.h>

extern trace_desc_t* g_trac_fsi;


class FsiDDTest : public CxxTest::TestSuite
{
  public:
    /**
     * @brief FSI DD test - Initialization
     *        Test FSI Master/Slave Initialization
     */
    void test_init(void)
    {
        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_init> Start" );
        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_init> Skipping due to simics issues" ); return;
        uint64_t fails = 0;
        uint64_t total = 0; 
        errlHndl_t l_err = NULL;

        total++;
        l_err = FSI::initializeHardware();
        if( l_err )
        {
            fails++;
            TRACFCOMP(g_trac_fsi, "FsiDDTest::test_init> Error from device : RC=%X", l_err->reasonCode() );
            TS_FAIL( "FsiDDTest::test_init> ERROR : Unexpected error log from initMaster" );
            errlCommit(l_err);
            delete l_err;
        }

        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_init> %d/%d fails", fails, total );
    };


    /**
     * @brief FSI DD test - Read/Write
     *        Perform basic read/write operations
     */
    void test_readWrite(void)
    {
        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_readWrite> Start" );        
        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_init> Skipping due to simics issues" ); return;
        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = NULL;

        // Setup some targets to use
        enum {
            PROC0,
            PROC1,
            CENTAUR0,
            NULL_TARGET,
            SENTINEL,
            NUM_TARGETS
        };
        TARGETING::Target* fsi_targets[NUM_TARGETS];
        for( uint64_t x = 0; x < NUM_TARGETS; x++ )
        {
            fsi_targets[x] = NULL;
        }

        TARGETING::Target* fsi_target = NULL;

        // master processor target
        TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
        epath.addLast(TARGETING::TYPE_SYS,0);
        epath.addLast(TARGETING::TYPE_NODE,0);
        epath.addLast(TARGETING::TYPE_PROC,0);
        fsi_target = TARGETING::targetService().toTarget(epath);
        fsi_targets[PROC0] = fsi_target;

        // other (wrap) processor target (physical:sys-0/node-0/proc-1)
        epath.removeLast();
        epath.addLast(TARGETING::TYPE_PROC,1);
        fsi_target = TARGETING::targetService().toTarget(epath);
        fsi_targets[PROC1] = fsi_target;

        // centaur target (physical:sys-0/node-0/membuf-0)
        epath.removeLast();
        epath.addLast(TARGETING::TYPE_MEMBUF,0);
        fsi_target = TARGETING::targetService().toTarget(epath);
        fsi_targets[CENTAUR0] = fsi_target;

        

        // scratch data to use
        struct {
            int fsitarget;
            uint64_t addr;
            uint32_t data;
            bool writeable;
        } test_data[] = {
            //** Master Control Space
            // version number
            { PROC0, 0x003074, 0x91010800, false }, //CMFSI MVER
            { PROC0, 0x003474, 0x91010800, false }, //MFSI MVER

            // clock rate delay for ports 32-63 (unused ports)
            { PROC0, 0x00340C, 0x11111111, true }, //MFSI MCRSP32
            { PROC0, 0x00300C, 0x22222222, true }, //CMFSI MCRSP32

            // port static levels
            { PROC0, 0x003418, 0x80000000, false }, //MFSI MLEVP32 (port0 present)
            { PROC0, 0x00341C, 0x00000000, false }, //MFSI MLEVP32
            { PROC0, 0x003018, 0x80000000, false }, //CMFSI MLEVP0
            { PROC0, 0x00301C, 0x00000000, false }, //CMFSI MLEVP32

            //** Slave Regs (cheating)
            { PROC0, 0x080000, 0xC0010EA0, false }, //Config Table entry for slave0 off MFSI-0 
            { PROC0, 0x081000, 0x12345678, true }, //DATA_0 from FSI2PIB off MFSI-0 
            //@fixme-simics { PROC0, 0x041000, 0x88776655, true }, //DATA_0 from FSI2PIB off cMFSI-0 

            //** Slave Regs
            { PROC1, 0x000000, 0xC0010EA0, false }, //Config Table entry for slave0 off MFSI-0 
            { PROC1, 0x001000, 0x12345678, false }, //DATA_0 from FSI2PIB off MFSI-0 
            { PROC1, 0x001004, 0xA5A5A5A5, true }, //DATA_1 from FSI2PIB off MFSI-0
            { PROC1, 0x001028, 0x120EA049, false }, //CHIPID from FSI2PIB off MFSI-0 

            //** Slave Regs
            { CENTAUR0, 0x000000, 0xC31CEE9C, false }, //Config Table entry for slave0 off cMFSI-0 
            //@fixme-simics { CENTAUR0, 0x001000, 0x88776655, false }, //DATA_0 from FSI2PIB off cMFSI-0 
            //@fixme-simics { CENTAUR0, 0x001004, 0xB0B0B0B0, true }, //DATA_1 from FSI2PIB off cMFSI-0
            { CENTAUR0, 0x001028, 0xC6EE9049 /*@fixme-simics 0x160E9049*/, true }, //CHIPID from FSI2PIB off cMFSI-0
            { CENTAUR0, 0x000C08, 0x12344321, true }, //FEL from SHIFT off cMFSI-0
        };
        const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

        // allocate some space to play with
        uint32_t read_data[NUM_ADDRS];
        size_t op_size = sizeof(uint32_t);


        // read address X,Y,Z
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            op_size = sizeof(uint32_t);

            if( (NULL == fsi_targets[test_data[x].fsitarget])
                || (test_data[x].addr >= 0x040000) )
            {
                TARGETING::EntityPath syspath(TARGETING::EntityPath::PATH_PHYSICAL);
                syspath.addLast(TARGETING::TYPE_SYS,0);
                TARGETING::Target* sys = TARGETING::targetService().toTarget(syspath);
                uint8_t vpo_mode = 0;
                if( sys
                    && sys->tryGetAttr<TARGETING::ATTR_VPO_MODE>(vpo_mode)
                    && (vpo_mode == 1) )
                {
                    // skip targets that aren't part of the VPO configs
                    continue;
                }
            }

            total++;
            l_err = DeviceFW::deviceRead( fsi_targets[test_data[x].fsitarget], 
                                          &(read_data[x]),
                                          op_size,
                                          DEVICE_FSI_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : [%d] addr=0x%X, RC=%X", x, test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from read1" );
                fails++;
                errlCommit(l_err);
                delete l_err;
            }

            TRACDCOMP( g_trac_fsi, "READ Reg 0x%X = 0x%X", test_data[x].addr, read_data[x] );
        }

        // write X=A, Y=B, Z=C
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            op_size = sizeof(uint32_t);

            if( test_data[x].writeable )
            {
                total++;
                l_err = DeviceFW::deviceWrite( fsi_targets[test_data[x].fsitarget], 
                                               &(test_data[x].data),
                                               op_size,
                                               DEVICE_FSI_ADDRESS(test_data[x].addr) );
                if( l_err )
                {
                    TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : [%d] addr=0x%X, RC=%X", x, test_data[x].addr, l_err->reasonCode() );
                    TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from write1" );
                    fails++;
                    errlCommit(l_err);
                    delete l_err;
                }
            }
        }

        // read X,Y,Z
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            op_size = sizeof(uint32_t);

            total++;
            l_err = DeviceFW::deviceRead( fsi_targets[test_data[x].fsitarget], 
                                          &(read_data[x]),
                                          op_size,
                                          DEVICE_FSI_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : [%d] addr=0x%X, RC=%X", x, test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from read2" );
                fails++;
                errlCommit(l_err);
                delete l_err;
            }
        }

        // verify X==A, Y==B, Z==C
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            total++;
            if( read_data[x] != test_data[x].data )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Data mismatch : [%d] addr=0x%X, exp=0x%X, act=0x%X", x,  test_data[x].addr, test_data[x].data, read_data[x] );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Data mismatch" );
                fails++;                
            }
        }

#if 0
        // put the original data back
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            op_size = sizeof(uint32_t);

            if( test_data[x].writeable )
            {
                total++;
                l_err = DeviceFW::deviceWrite( fsi_targets[test_data[x].fsitarget], 
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
            }
        }
#endif


        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_readWrite> %d/%d fails", fails, total );
    };

    /**
     * @brief FSI DD test - bad targets
     *        Verify that we catch bad targets
     */
    void test_badTargets(void)
    {
        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_badTargets> Start" );
        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = NULL;
        uint32_t regdata = 0;

        // master sentinel should fail
        total++;
        size_t op_size = sizeof(uint32_t);       
        l_err = DeviceFW::deviceRead( TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL, 
                                      &regdata,
                                      op_size,
                                      DEVICE_FSI_ADDRESS(0x111111) );
        if( l_err && (l_err->reasonCode() == FSI::RC_MASTER_TARGET) )
        {
            delete l_err;
        }
        else
        {
            TRACFCOMP(g_trac_fsi, "FsiDDTest::test_badTargets> ERROR : Sentinel target did not fail as expected" );
            TS_FAIL( "FsiDDTest::test_badTargets> ERROR : Sentinel target did not fail as expected" );
            fails++;

            if( l_err )
            {
                errlCommit(l_err);
                delete l_err;
            }
        }

        // NULL target should fail
        total++;
        op_size = sizeof(uint32_t);       
        l_err = DeviceFW::deviceRead( NULL, 
                                      &regdata,
                                      op_size,
                                      DEVICE_FSI_ADDRESS(0x111111) );
        if( l_err )
        {
            delete l_err;
        }
        else
        {
            TRACFCOMP(g_trac_fsi, "FsiDDTest::test_badTargets> ERROR : NULL target did not fail as expected" );
            TS_FAIL( "FsiDDTest::test_badTargets> ERROR : NULL target did not fail as expected" );
            fails++;
        }

        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_badTargets> %d/%d fails", fails, total );
    };

};     


#endif
