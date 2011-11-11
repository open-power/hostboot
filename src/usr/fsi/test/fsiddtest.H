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

using namespace TARGETING;

class FsiDDTest : public CxxTest::TestSuite
{
  public:
    /**
     * @brief FSI DD test - Initialization
     *        Test FSI Master/Slave Initialization
     */
    void test_init(void)
    {
#if 0  //istep is calling this now
        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_init> Start" );
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
            errlCommit(l_err,FSI_COMP_ID);
            delete l_err;
        }

        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_init> %d/%d fails", fails, total );
#endif
    };


    //testcode for Simics verification
    void test_blah(void)
    {
#if 0 
        return;
        errlHndl_t l_err = NULL;
        TARGETING::Target* fsi_target = NULL;

        // master processor target
        TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
        epath.addLast(TARGETING::TYPE_SYS,0);
        epath.addLast(TARGETING::TYPE_NODE,0);
        epath.addLast(TARGETING::TYPE_PROC,0);
        fsi_target = TARGETING::targetService().toTarget(epath);

        uint32_t read_data = 0;
        size_t op_size = sizeof(read_data);

        while(1)
        {
            nanosleep( 1, 0 );
            op_size = sizeof(read_data);
            l_err = DeviceFW::deviceRead( fsi_target, 
                                          &read_data,
                                          op_size,
                                          DEVICE_FSI_ADDRESS(0x3418) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_blah> Error from device : RC=%X", l_err->reasonCode() );
                delete l_err;
            }
        }
#endif
    };

    /**
     * @brief FSI DD test - Read/Write
     *        Perform basic read/write operations
     */
    void test_readWrite(void)
    {
        //@todo
        //@VBU workaround - Disable test case
        //Temporarily disable this test case in VBU because of
        //an MFSI/CFSI XSCOM hardware bug.
        TARGETING::EntityPath syspath(TARGETING::EntityPath::PATH_PHYSICAL);
        syspath.addLast(TARGETING::TYPE_SYS,0);
        TARGETING::Target* sys = TARGETING::targetService().toTarget(syspath);
        uint8_t vpo_mode = 0;
        if( sys
            && sys->tryGetAttr<TARGETING::ATTR_VPO_MODE>(vpo_mode)
            && (vpo_mode == 1) )
        {
            return;
        }

        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_readWrite> Start" );
        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = NULL;

        // Setup some targets to use
        enum {
            PROC0,
            PROCWRAP,
            PROC2,
            CENTAUR0,
            CENTAUR8,
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

        // other (wrap) processor target (physical:sys-0/node-0/proc-9)
        epath.removeLast();
        epath.addLast(TARGETING::TYPE_PROC,9);
        fsi_target = TARGETING::targetService().toTarget(epath);
        fsi_targets[PROCWRAP] = fsi_target;

        // other (wrap) processor target (physical:sys-0/node-0/proc-2)
        epath.removeLast();
        epath.addLast(TARGETING::TYPE_PROC,2);
        fsi_target = TARGETING::targetService().toTarget(epath);
        fsi_targets[PROC2] = fsi_target;

        // centaur target (physical:sys-0/node-0/membuf-0)
        epath.removeLast();
        epath.addLast(TARGETING::TYPE_MEMBUF,0);
        fsi_target = TARGETING::targetService().toTarget(epath);
        fsi_targets[CENTAUR0] = fsi_target;

        // centaur target (physical:sys-0/node-0/membuf-8)
        epath.removeLast();
        epath.addLast(TARGETING::TYPE_MEMBUF,8);
        fsi_target = TARGETING::targetService().toTarget(epath);
        fsi_targets[CENTAUR8] = fsi_target;

        

        // scratch data to use
        struct {
            int fsitarget;
            uint64_t addr;
            uint32_t data;
            bool writeable;
            bool present;
        } test_data[] = {
            //** Master Control Space
            // version number
            { PROC0, 0x003074, 0x91010800, false, true }, //CMFSI MVER
            { PROC0, 0x003474, 0x91010800, false, true }, //MFSI MVER

            // clock rate delay for ports 32-63 (unused ports)
            { PROC0, 0x00340C, 0x11111111, true, true }, //MFSI MCRSP32
            { PROC0, 0x00300C, 0x22222222, true, true }, //CMFSI MCRSP32

            //** Slave Regs (cheating)
            { PROC0, 0x080000, 0xC0010EA0, false, false }, //Config Table entry for slave0 off MFSI-0 
            { PROC0, 0x081000, 0x12345678, true, false }, //DATA_0 from FSI2PIB off MFSI-0 
            { PROC0, 0x041028, 0xC6EE9049 /*fixme 0x160E9049*/, false, false }, //CHIPID from SHIFT off cMFSI-0
            { PROC0, 0x103074, 0x91010800, false, false }, //CMFSI MVER from Proc off MFSI-2

            //** Slave Regs
            { PROCWRAP, 0x000000, 0xC0010EA0, false, false }, //Config Table entry for slave0 off MFSI-0 
            { PROCWRAP, 0x001000, 0x12345678, false, false }, //DATA_0 from FSI2PIB off MFSI-0 
            { PROCWRAP, 0x001004, 0xA5A5A5A5, true, false }, //DATA_1 from FSI2PIB off MFSI-0
            //SW106529 { PROCWRAP, 0x001028, 0x120EA049, false, false }, //CHIPID from FSI2PIB off MFSI-0 

            //** Slave Regs
            { PROC2, 0x000000, 0xC0010EA0, false, false }, //Config Table entry for slave0 off MFSI-2
            { PROC2, 0x001000, 0x12345678, true, false }, //FEL from SHIFT off MFSI-2
            { PROC2, 0x001028, 0x120EA049, false, false }, //CHIPID from FSI2PIB off MFSI-2

            //** Slave Regs
            { CENTAUR0, 0x000000, 0xC31CEE9C, false, false }, //Config Table entry for slave0 off cMFSI-0 
            { CENTAUR0, 0x001028, 0xC6EE9049 /*fixme 0x160E9049*/, false, false }, //CHIPID from FSI2PIB off cMFSI-0
            { CENTAUR0, 0x000C08, 0x12344321, true, false }, //FEL from SHIFT off cMFSI-0

            //** Slave Regs
            { CENTAUR8, 0x001000, 0x33333333, true, false }, //FEL from SHIFT off cMFSI-0 of MFSI-7
            { CENTAUR8, 0x001028, /*0xC6EE9049*/ 0x160E9049, false, false }, //CHIPID from FSI2PIB off cMFSI-0 of MFSI-7
        };
        const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

        // allocate some space to play with
        uint32_t read_data[NUM_ADDRS];
        size_t op_size = sizeof(uint32_t);

        // figure out which ports are valid to test in the current config
        uint64_t patterns_to_run = 0;
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            // direct writes to slave regs
            if( test_data[x].fsitarget == PROC0 )
            {
                if( ((0xFF0000 & test_data[x].addr) == 0x080000)
                    && FSI::isSlavePresent(fsi_targets[PROCWRAP]) )
                {
                    test_data[x].present = true;
                }
                else if( ((0xFF0000 & test_data[x].addr) == 0x040000)
                         && FSI::isSlavePresent(fsi_targets[CENTAUR0]) )
                {
                    test_data[x].present = true;
                }
                else if( ((0xFF0000 & test_data[x].addr) == 0x100000)
                         && FSI::isSlavePresent(fsi_targets[PROC2]) )
                {
                    test_data[x].present = true;
                }
            }
            // otherwise only talk to chips that we see
            else if( FSI::isSlavePresent(fsi_targets[test_data[x].fsitarget]) )
            {
                test_data[x].present = true;
            }
            else
            {
                test_data[x].present = false;
            }

            if( test_data[x].present )
            {
                patterns_to_run |= (0x8000000000000000 >> x);
            }
        }

        // read address X,Y,Z
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            if( !test_data[x].present )
            {
                continue;
            }

            total++;
            op_size = sizeof(uint32_t);
            l_err = DeviceFW::deviceRead( fsi_targets[test_data[x].fsitarget], 
                                          &(read_data[x]),
                                          op_size,
                                          DEVICE_FSI_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : [%d] addr=0x%X, RC=%X", x, test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from read1" );
                fails++;
                errlCommit(l_err,FSI_COMP_ID);
                delete l_err;
            }

            TRACDCOMP( g_trac_fsi, "READ Reg 0x%X = 0x%X", test_data[x].addr, read_data[x] );
        }

        // write X=A, Y=B, Z=C
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            if( !test_data[x].present )
            {
                continue;
            }

            if( test_data[x].writeable )
            {
                total++;
                op_size = sizeof(uint32_t);
                l_err = DeviceFW::deviceWrite( fsi_targets[test_data[x].fsitarget], 
                                               &(test_data[x].data),
                                               op_size,
                                               DEVICE_FSI_ADDRESS(test_data[x].addr) );
                if( l_err )
                {
                    TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : [%d] addr=0x%X, RC=%X", x, test_data[x].addr, l_err->reasonCode() );
                    TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from write1" );
                    fails++;
                    errlCommit(l_err,FSI_COMP_ID);
                    delete l_err;
                }
            }
        }

        // read X,Y,Z
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            if( !test_data[x].present )
            {
                continue;
            }

            total++;
            op_size = sizeof(uint32_t);
            l_err = DeviceFW::deviceRead( fsi_targets[test_data[x].fsitarget], 
                                          &(read_data[x]),
                                          op_size,
                                          DEVICE_FSI_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : [%d] addr=0x%X, RC=%X", x, test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from read2" );
                fails++;
                errlCommit(l_err,FSI_COMP_ID);
                delete l_err;
            }
        }

        // verify X==A, Y==B, Z==C
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            if( !test_data[x].present )
            {
                continue;
            }

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
                    errlCommit(l_err,FSI_COMP_ID);
                    delete l_err;
                }
            }
        }
#endif


        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_readWrite> %d/%d fails (patterns=%.16X)", fails, total, patterns_to_run );
    };

    /**
     * @brief FSI DD test - bad targets
     *        Verify that we catch bad targets
     */
    void test_badTargets(void)
    {

        //@todo
        //@VBU workaround - Disable test case
        //Temporarily disable this test case in VBU because of
        //an MFSI/CFSI XSCOM hardware bug.
        TARGETING::EntityPath syspath(TARGETING::EntityPath::PATH_PHYSICAL);
        syspath.addLast(TARGETING::TYPE_SYS,0);
        TARGETING::Target* sys = TARGETING::targetService().toTarget(syspath);
        uint8_t vpo_mode = 0;
        if( sys
            && sys->tryGetAttr<TARGETING::ATTR_VPO_MODE>(vpo_mode)
            && (vpo_mode == 1) )
        {
            return;
        }


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
                errlCommit(l_err,FSI_COMP_ID);
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
