/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/test/fsiddtest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
#include <limits.h>
#include <devicefw/driverif.H>
#include <fsi/fsiif.H>
#include <fsi/fsi_reasoncodes.H>
#include <sys/time.h>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>

extern trace_desc_t* g_trac_fsi;

using namespace TARGETING;

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

        // Setup some targets to use
        enum {
            PROC0,
            PROCWRAP,
            PROC1,
            PROC2,
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

        // other processor target (physical:sys-0/node-0/proc-1)
        epath.removeLast();
        epath.addLast(TARGETING::TYPE_PROC,1);
        fsi_target = TARGETING::targetService().toTarget(epath);
        fsi_targets[PROC1] = fsi_target;

        // alt-master processor target (physical:sys-0/node-0/proc-2)
        epath.removeLast();
        epath.addLast(TARGETING::TYPE_PROC,2);
        fsi_target = TARGETING::targetService().toTarget(epath);
        fsi_targets[PROC2] = fsi_target;

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
            //MFSI MVER
            { PROC0, 0x003474, 0x92010800, false, true },

            //** Slave Regs (via absolute address)
            //DATA_0 from FSI2PIB off MFSI-0
            { PROC0, 0x081000, 0x12345678, true, false },

            //** Slave Regs
            //DATA_0 from FSI2PIB off MFSI-0
            { PROCWRAP, 0x001000, 0x12345678, false, false },
            //DATA_1 from FSI2PIB off MFSI-0
            { PROCWRAP, 0x001004, 0xA5A5A5A5, true, false },

            //** Slave Regs
            //FEL from SHIFT off MFSI-1
            { PROC1, 0x001000, 0x88776655, true, false },

            //** Slave Regs
            //FEL from SHIFT off MFSI-2
            { PROC2, 0x001000, 0x12345678, true, false },
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
                    && (fsi_targets[PROCWRAP] != NULL)
                    && (fsi_targets[PROCWRAP]->
                        getAttr<TARGETING::ATTR_HWAS_STATE>().functional))
                {
                    test_data[x].present = true;
                }
                else if( ((0xFF0000 & test_data[x].addr) == 0x100000)
                         && (fsi_targets[PROC2] != NULL)
                         && (fsi_targets[PROC2]->
                             getAttr<TARGETING::ATTR_HWAS_STATE>().functional))
                {
                    test_data[x].present = true;
                }
            }
            // otherwise only talk to chips that we see
            else if (( fsi_targets[test_data[x].fsitarget] != NULL)   &&
                     (fsi_targets[test_data[x].fsitarget]->
                      getAttr<TARGETING::ATTR_HWAS_STATE>().functional))
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
            l_err = DeviceFW::deviceRead(
                              fsi_targets[test_data[x].fsitarget],
                              &(read_data[x]),
                              op_size,
                              DEVICE_FSI_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : [%d] addr=0x%X, RC=%X", x, test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from read1" );
                fails++;
                errlCommit(l_err,FSI_COMP_ID);
            }
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
                l_err = DeviceFW::deviceWrite(
                                  fsi_targets[test_data[x].fsitarget],
                                  &(test_data[x].data),
                                  op_size,
                                  DEVICE_FSI_ADDRESS(test_data[x].addr) );
                if( l_err )
                {
                    TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : [%d] addr=0x%X, RC=%X", x, test_data[x].addr, l_err->reasonCode() );
                    TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from write1" );
                    fails++;
                    errlCommit(l_err,FSI_COMP_ID);
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
            l_err = DeviceFW::deviceRead(
                              fsi_targets[test_data[x].fsitarget],
                              &(read_data[x]),
                              op_size,
                              DEVICE_FSI_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : [%d] addr=0x%X, RC=%X", x, test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from read2" );
                fails++;
                errlCommit(l_err,FSI_COMP_ID);
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

        // put the original data back
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )
        {
            op_size = sizeof(uint32_t);

            if( !test_data[x].present )
            {
                continue;
            }

            if( test_data[x].writeable )
            {
                total++;
                l_err = DeviceFW::deviceWrite(
                                  fsi_targets[test_data[x].fsitarget],
                                  &(test_data[x].data),
                                  op_size,
                                  DEVICE_FSI_ADDRESS(test_data[x].addr) );
                if( l_err )
                {
                    TRACFCOMP(g_trac_fsi, "FsiDDTest::test_readWrite> Error from device : addr=0x%X, RC=%X", test_data[x].addr, l_err->reasonCode() );
                    TS_FAIL( "FsiDDTest::test_readWrite> ERROR : Unexpected error log from write1" );
                    fails++;
                    errlCommit(l_err,FSI_COMP_ID);
                }
            }
        }

        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_readWrite> %d/%d fails (patterns=%.16X)", fails, total, patterns_to_run );
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
        l_err = DeviceFW::deviceRead(
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
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

    /**
     * @brief FSI DD test - FSI Link Info
     *        Spot check getFsiLinkInfo results
     */
    void test_getFsiLinkInfo(void)
    {
        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_getFsiLinkInfo> Start" );

        enum {
            PROC0,
            NUM_TARGETS
        };
        TARGETING::Target* fsi_targets[NUM_TARGETS];
        for( size_t x = 0; x < NUM_TARGETS; x++ )
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

        // loop through all of the targets we defined to
        //  check the data
        for( size_t x = 0; x < NUM_TARGETS; x++ )
        {
            if( fsi_targets[x] == NULL )
            {
                continue;
            }

            // Get the FSI port info for this target
            TARGETING::FSI_MASTER_TYPE type =
              fsi_targets[x]->getAttr<TARGETING::ATTR_FSI_MASTER_TYPE>();
            uint8_t slave_port =
              fsi_targets[x]->getAttr<TARGETING::ATTR_FSI_MASTER_PORT>();
            TARGETING::EntityPath masterpath =
              fsi_targets[x]->getAttr<TARGETING::ATTR_FSI_MASTER_CHIP>();
            TARGETING::Target* master =
              TARGETING::targetService().toTarget(masterpath);
            uint8_t master_port = 0;
            if( type != TARGETING::FSI_MASTER_TYPE_NO_MASTER )
            {
                master_port =
                  master->getAttr<TARGETING::ATTR_FSI_MASTER_PORT>()+1;
            }

            TRACFCOMP( g_trac_fsi, "sport=%d, mport=%d, master=%.8X, type=%d",slave_port,master_port, TARGETING::get_huid(master), master_port);
            // Compute the offset
            //   CMFSI ports start at 0x040000 and increment by 0x008000
            //   MFSI ports start at 0x080000 and increment by 0x080000
            //    (local CMFSI ports have no MFSI offset)
            uint32_t offset = (master_port * 0x080000);
            if( type == TARGETING::FSI_MASTER_TYPE_CMFSI )
            {
                offset += ((slave_port * 0x008000) + 0x040000);
            }

            // Now call the interface we want to test
            FSI::FsiLinkInfo_t linkinfo;
            FSI::getFsiLinkInfo( fsi_targets[x], linkinfo );

            // Compare the results
            TRACFCOMP( g_trac_fsi, "FsiDDTest::test_getFsiLinkInfo> Data for %.8X: exp=%.6X, act=%.6X", TARGETING::get_huid(fsi_targets[x]), offset, linkinfo.baseAddr );
            if( linkinfo.baseAddr != offset )
            {
                TS_FAIL( "FsiDDTest::test_getFsiLinkInfo> Mismatch for %.8X: exp=%.6X, act=%.6X", TARGETING::get_huid(fsi_targets[x]), offset, linkinfo.baseAddr );
            }
        }

        TRACFCOMP( g_trac_fsi, "FsiDDTest::test_getFsiLinkInfo> End" );
    }
};


#endif
