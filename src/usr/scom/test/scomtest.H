/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/test/scomtest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
#ifndef __SCOMTEST_H
#define __SCOMTEST_H

/**
 *  @file scomtest.H
 *
 *  @brief Test case for SCOM code
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <fsi/fsiif.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <scom/scomif.H>
#include <devicefw/driverif.H>


extern trace_desc_t* g_trac_scom;


class ScomTest: public CxxTest::TestSuite
{
public:

  /**
   * @brief SCOM test via FSISCOM
   *
   */
  void test_FSISCOMreadWrite_proc(void)
  {

      TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> Start" );
#ifdef __HOSTBOOT_RUNTIME
      TRACFCOMP( g_trac_scom, "Not valid at runtime" );
      return;
#endif

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      // Setup some targets to use
      enum {
          PROC1,
          NUM_TARGETS
      };
      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = NULL;
      }

      // processor target (physical:sys-0/node-0/proc-1)
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_PROC,1);
      scom_targets[PROC1] = TARGETING::targetService().toTarget(epath);

      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists
          if(scom_targets[x] == NULL)
          {
              continue;
          }
          // skip the sentinel or if it Xscom is enabled
          else if((TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == scom_targets[x]) ||
                  (scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom))
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> Target %d is the MASTER Sentinal or is set to use Xscom, exiting test", x );
              scom_targets[x] = NULL; //remove from our list
          }
          // skip if fsi scom is not enabled
          else if(0 == scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> useFsiScom set to zero on target %d", x );
              scom_targets[x] = NULL; //remove from our list
          }
          else if (scom_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> Target %d is not functional", x );
              scom_targets[x] = NULL; //remove from our list
          }
      }

      // scratch data to use
      //@fixme: Need to either fabricate some fake registers to use or save off data before modifying SCOMs to avoid
      //   corrupting the HW.
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[PROC1],    0x040110C4, 0x1234567887654321},
          { scom_targets[PROC1],    0x02040008, 0x1122334455667788},
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];
      size_t op_size = sizeof(uint32_t);

      // write all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              continue;
          }

          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceWrite( test_data[x].target,
                               &(test_data[x].data),
                               op_size,
                               DEVICE_SCOM_ADDRESS(test_data[x].addr) );
          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> [%d] Write: Error from device : addr=0x%.8X, RC=%.4X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
      }

      // read all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              continue;
          }

          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceRead( test_data[x].target,
                              &(read_data[x]),
                              op_size,
                              DEVICE_SCOM_ADDRESS(test_data[x].addr) );
          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> [%d] Read: Error from device : addr=0x%.8X, RC=%.4X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_proc> ERROR : Unexpected error log from read1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> [%d] Read: Data miss-match : addr=0x%.8X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_proc> ERROR : Data mis-match between read and expected data" );
              fails++;
          }
      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> %d/%d fails", fails, total );

  }

  /**
   * @brief SCOM test Indirect SCOM
   *
   */
  void test_IndirectScom(void)
  {
      TRACFCOMP( g_trac_scom, "ScomTest::test_IndirectScom> Start" );

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      //@VBU workaround - Disable Indirect SCOM test case o
      //Test case read/writes to valid addresses and is
      //potentially destructive on VBU
      if (TARGETING::is_vpo())
      {
           return;
      }

      // Setup some targets to use
      enum {
          myPROC0,
          NUM_TARGETS
      };
      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = NULL;
      }

      // Target Proc 9 - the FSI wrap-back connection in simics
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_PROC,0);

      scom_targets[myPROC0] = TARGETING::targetService().toTarget(epath);

      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists
          if(scom_targets[x] == NULL)
          {
              TRACDCOMP( g_trac_scom, "ScomTest - TARGET = NULL - 1 x = %d", x);
              continue;
          }
          else if ((scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom == 0) &&
                   (scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom == 0))
          {
              // If both FSI and XSCOM are not enabled.. then ignore..
              TRACDCOMP(g_trac_scom, "INDIRECT SCOM>> SKIPPING ");
              scom_targets[x] = NULL; //remove from our list
          }
          else if (scom_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_IndirectScom> Target %d is not functional", x );
              scom_targets[x] = NULL; //remove from our list
          }


      }

      // scratch data to use

      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
          bool     isFail;
          TARGETING::ATTR_MODEL_type model;
      } test_data[] = {
          { scom_targets[myPROC0], 0x800C940010012C3F, 0x1234432112344328, false, TARGETING::MODEL_POWER10 },
          { scom_targets[myPROC0], 0x8FFFFFFFFFFFFFFF, 0x123443211234ABAB, true,  TARGETING::MODEL_POWER10 },
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      size_t op_size = sizeof(uint32_t);

      // write all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              continue;
          }

          // only run if this is the right kind of target
          auto l_model = test_data[x].target->getAttr<TARGETING::ATTR_MODEL>();
          if( (TARGETING::MODEL_POWER10 != test_data[x].model)
              && (l_model != test_data[x].model) )
          {
              continue;
          }

          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceWrite( test_data[x].target,
                               &(test_data[x].data),
                               op_size,
                               DEVICE_SCOM_ADDRESS(test_data[x].addr) );
          if(!test_data[x].isFail && l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScom> [%d] Write: Error from device : addr=0x%.8X, RC=%.4X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_IndirectScom> ERROR : Unexpected error log from device write: addr=0x%.8X, RC=%.4X ",  test_data[x].addr, l_err->reasonCode() );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
              l_err = NULL;
          }
          else if(test_data[x].isFail && !l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScom> [%d] Write: Expected an Error from device write: addr=0x%.8X", x,  test_data[x].addr );
              TS_FAIL( "ScomTest::test_IndirectScom> ERROR : Expected an error log from device write and did not get one : addr=0x%.8X",  test_data[x].addr );
              fails++;
          }
          else if(l_err)
          {
              //delete expected errors
              delete l_err;
          }
      }

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];

      memset(read_data, 0, sizeof read_data);

      // read all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              continue;
          }

          // only run if this is the right kind of target
          auto l_model = test_data[x].target->getAttr<TARGETING::ATTR_MODEL>();
          if( (TARGETING::MODEL_POWER10 != test_data[x].model)
              && (l_model != test_data[x].model) )
          {
              continue;
          }

          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceRead( test_data[x].target,
                              &(read_data[x]),
                              op_size,
                              DEVICE_SCOM_ADDRESS(test_data[x].addr) );

          if(!test_data[x].isFail && l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomreadWrite> [%d] Read: Error from device : addr=0x%.8X, RC=%.4X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_IndirectScomreadWrite> ERROR : Unexpected error log from read device : addr=0x%.8X, RC=%.4X", test_data[x].addr, l_err->reasonCode() );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
              l_err = NULL;
          }
          else if(test_data[x].isFail && !l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScom> [%d] Read: Expected an Error from device read : addr=0x%.8X", x,  test_data[x].addr );
              TS_FAIL( "ScomTest::test_IndirectScom> ERROR : Expected an error log from device read and did not get one : addr=0x%.8X",  test_data[x].addr );
              fails++;
          }
          else if(!test_data[x].isFail &&
                    ((read_data[x] & 0x000000000000FFFF) !=
                    (test_data[x].data & 0x000000000000FFFF))
                )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomreadWrite> [%d] Read: Data miss-match : addr=0x%.8X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_IndirectScomreadWrite> ERROR : Data miss-match between read and expected data  read_data" );
              fails++;
          }
          else if(l_err)
          {
              //delete expected errors
              delete l_err;
          }

      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_IndirectScomreadWrite> %d/%d fails", fails, total );
  }

  /**
   * @brief SCOM test Indirect SCOM form 1
   *
   */
  void test_IndirectScomForm1(void)
  {
      TRACFCOMP( g_trac_scom, "ScomTest::test_IndirectScomForm1ReadWrite> Start" );
/*
 * TODO RTC 158024 - Enable form 1  test case

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      //@VBU workaround - Disable Indirect SCOM test case o
      //Test case read/writes to valid addresses and is
      //potentially destructive on VBU
      if (TARGETING::is_vpo())
      {
           return;
      }

      // Setup some targets to use
      enum {
          myPROC0,
          NUM_TARGETS
      };
      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = NULL;
      }

      // Target Proc 9 - the FSI wrap-back connection in simics
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_PROC,0);

      scom_targets[myPROC0] = TARGETING::targetService().toTarget(epath);

      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists
          if(scom_targets[x] == NULL)
          {
              TRACDCOMP( g_trac_scom, "ScomTestForm1 - TARGET = NULL - 1 x = %d", x);
              continue;
          }
          else if ((scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom == 0) &&
                   (scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom == 0))
          {
              // If both FSI and XSCOM are not enabled.. then ignore..
              TRACDCOMP(g_trac_scom, "INDIRECT SCOMForm1>> SKIPPING ");
              scom_targets[x] = NULL; //remove from our list
          }
          else if (scom_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWriteForm1 > Target %d is not functional", x );
              scom_targets[x] = NULL; //remove from our list
          }
      }

      // scratch data to use

      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
          bool     isFail;
      } test_data[] = {
          { scom_targets[myPROC0], 0x900003210D010BEE, 0x0004432112344321, false}, // Form 1
          { scom_targets[myPROC0], 0x9000012307011BEE, 0x000443211234ABAB, false }, // Form 1
          { scom_targets[myPROC0], 0x9000000007011BEE, 0x123443211234ABAB, true }, // Form 1
          { scom_targets[myPROC0], 0x9FEEDB0B0DEADBEE, 0x000443211234ABAB, true }, // Form 1
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      size_t op_size = sizeof(uint32_t);

      // write all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              continue;
          }

          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceWrite( test_data[x].target,
                               &(test_data[x].data),
                               op_size,
                               DEVICE_SCOM_ADDRESS(test_data[x].addr) );

          if(!test_data[x].isFail && l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomForm1_proc> [%d] Write: Error from device : addr=0x%.8X, RC=%.4X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_IndirectScomForm1_proc> ERROR : Unexpected error log from device write: addr=0x%.8X, RC=%.4X ",  test_data[x].addr, l_err->reasonCode() );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
              l_err = NULL;
          }
          else if(test_data[x].isFail && !l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomForm1_proc> [%d] Write: Expected an Error from device write: addr=0x%.8X", x,  test_data[x].addr );
              TS_FAIL( "ScomTest::test_IndirectScomForm1_proc> ERROR : Expected an error log from device write and did not get one : addr=0x%.8X",  test_data[x].addr );
              fails++;
          }
          else if(l_err)
          {
              //delete expected errors
              delete l_err;
          }
      }
          // Now lets make sure the data is correct
          // Form 1 doesn't support read. Simics action is set up to write to
          // a regigster whcih will we scom
          // allocate space for read data
      struct {
          TARGETING::Target* target;
          uint64_t addr;
      } read_addresses[] = {
          { scom_targets[myPROC0], 0x0D010123 }, // Form 1
          { scom_targets[myPROC0], 0x07011123 }, // Form 1
      };
      const uint64_t READ_ADDRS = sizeof(read_addresses)/sizeof(read_addresses[0]);
      uint64_t read_form1data[READ_ADDRS];

      memset(read_form1data, 0, sizeof read_form1data);

      // read all the read registers
      for( uint64_t x = 0; x < READ_ADDRS; x++ )
      {
          //only run if the target exists
          if(read_addresses[x].target == NULL)
          {
              continue;
          }

          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceRead( read_addresses[x].target,
                              &(read_form1data[x]),
                              op_size,
                              DEVICE_SCOM_ADDRESS(read_addresses[x].addr) );

          if(l_err)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomreadWriteForm1_proc> [%d] read written data: Unxpected Error from device : addr=0x%.8X, RC=%.4X", x,  read_addresses[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_IndirectScomreadWriteForm1_proc> ERROR : Unxpected Error on reading written data : addr=0x%.8X, RC=%.4X", read_addresses[x].addr, l_err->reasonCode() );
              fails++;
          }
          if((read_form1data[x] & 0x000000000000FFFF) !=
                (test_data[x].data & 0x000000000000FFFF))
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomreadWriteForm1_proc> [%d] Read: Data miss-match : addr=0x%.8X, read_form1data=0x%llx, write_data=0x%llx", x, read_addresses[x].addr, read_form1data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_IndirectScomreadWriteForm1_proc> ERROR : Data miss-match between read and expected data" );
              fails++;
          }
      }

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];

      memset(read_data, 0, sizeof read_data);

      // read all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              continue;
          }

          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceRead( test_data[x].target,
                              &(read_data[x]),
                              op_size,
                              DEVICE_SCOM_ADDRESS(test_data[x].addr) );

          // Form1 doesn't support read so if we don't get an error back, that's bad
          if(!l_err)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomreadWriteForm1_proc> [%d] Read: Expected Error from device : addr=0x%.8X, RC=%.4X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_IndirectScomreadWriteForm1_proc> ERROR : Expected Error on READ : addr=0x%.8X, RC=%.4X", test_data[x].addr, l_err->reasonCode() );
              fails++;
          }
          // else, if we are form1 and DO get an error back on read, that's expected.
          else
          {
              //delete expected errors
              delete l_err;
          }
      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_IndirectScomreadWriteForm1_proc> %d/%d fails", fails, total );
*/
  }


  void test_P10_ScomTranslations(void)
  {
    TRACFCOMP( g_trac_scom, "ScomTest::test_P10_ScomTranslations> Start" );

    uint64_t fails = 0;
    uint64_t total = 0;
    errlHndl_t l_err = nullptr;

    // Setup some targets to use
    enum myTarget_t {
        myCORE0,
        myCORE1,
        myEQ0,
        myEQ5,
        myPERV2,
        myPERV32,
        myPEC0,
        myPEC1,
        myPHB0,
        myPHB2,
        myMC0,
        myMC1,
        myMI0,
        myMI1,
        myMCC0,
        myMCC1,
        myOMI0,
        myOMI1,
        myOMIC0,
        myOMIC1,
        myNMMU0,
        myNMMU1,
        myIOHS0,
        myIOHS2,
        NUM_TARGETS
    };

    /////////////////////////////////////////////////////////////////
    // Set up targets
    /////////////////////////////////////////////////////////////////

    using namespace TARGETING;

    Target* scom_targets[NUM_TARGETS] = { };

    EntityPath sys0node0proc0(EntityPath::PATH_PHYSICAL);

    // Start at /sys0/node0/proc0/
    sys0node0proc0.addLast(TYPE_SYS, 0);
    sys0node0proc0.addLast(TYPE_NODE, 0);
    sys0node0proc0.addLast(TYPE_PROC, 0);

    { // Begin locating targets for SCOM access tests

    // This struct holds a path from a PROC to the target corresponding to one
    // of the myTarget_t enumeration values
    struct TestTargetPath
    {
        myTarget_t my_type;

        struct TargetInfo
        {
            TYPE target_type;
            int instance;
        };

        const std::vector<TargetInfo> path;
    };

    // This array holds the paths to all the targets we want to test SCOM ops on
    const TestTargetPath target_paths[] =
    {
        { myCORE0,  {{ TYPE_EQ, 0    }, { TYPE_FC, 0   }, { TYPE_CORE, 0 }} },
        { myCORE1,  {{ TYPE_EQ, 0    }, { TYPE_FC, 0   }, { TYPE_CORE, 1 }} },
        { myEQ0,    {{ TYPE_EQ, 0    }} },
        { myEQ5,    {{ TYPE_EQ, 5    }} },
        { myPERV2,  {{ TYPE_PERV, 2  }} },
        { myPERV32, {{ TYPE_PERV, 32 }} },
        { myPEC0,   {{ TYPE_PEC, 0   }} },
        { myPEC1,   {{ TYPE_PEC, 1   }} },
        { myPHB0,   {{ TYPE_PEC, 0   }, { TYPE_PHB, 0  }} },
        { myPHB2,   {{ TYPE_PEC, 1   }, { TYPE_PHB, 2  }} },
        { myMC0,    {{ TYPE_MC, 0    }} },
        { myMC1,    {{ TYPE_MC, 1    }} },
        { myMI0,    {{ TYPE_MC, 0    }, { TYPE_MI, 0   }} },
        { myMI1,    {{ TYPE_MC, 1    }, { TYPE_MI, 0   }} },
        { myMCC0,   {{ TYPE_MC, 0    }, { TYPE_MI, 0   }, { TYPE_MCC, 0  }} },
        { myMCC1,   {{ TYPE_MC, 1    }, { TYPE_MI, 0   }, { TYPE_MCC, 1  }} },
        { myOMI0,   {{ TYPE_MC, 0    }, { TYPE_MI, 0   }, { TYPE_MCC, 0  }, { TYPE_OMI, 0 }} },
        { myOMI1,   {{ TYPE_MC, 1    }, { TYPE_MI, 0   }, { TYPE_MCC, 1  }, { TYPE_OMI, 1 }} },
        { myOMIC0,  {{ TYPE_MC, 0    }, { TYPE_OMIC, 0 }} },
        { myOMIC1,  {{ TYPE_MC, 1    }, { TYPE_OMIC, 1 }} },
        { myNMMU0,  {{ TYPE_NMMU, 0  }} },
        { myNMMU1,  {{ TYPE_NMMU, 1  }} },
        { myIOHS0,  {{ TYPE_PAUC, 0  }, { TYPE_IOHS, 0 }} },
        { myIOHS2,  {{ TYPE_PAUC, 2  }, { TYPE_IOHS, 1 }} },
    };

    static_assert(sizeof(target_paths) / sizeof(*target_paths) == NUM_TARGETS,
                  "Missing test case in SCOM TRANSLATE test");

    for (int i = 0; i < NUM_TARGETS; ++i)
    {
        EntityPath epath = sys0node0proc0;

        // Descend the target hierarchy to find the target we want
        for (const auto path_component : target_paths[i].path)
        {
            epath.addLast(path_component.target_type, path_component.instance);
        }

        // Make sure we don't overwrite something we've already found
        assert(scom_targets[i] == nullptr);

        // Save the target at this path into scom_targets
        scom_targets[i] = targetService().toTarget(epath);

        // Make sure we found our target
        assert(scom_targets[i]);
    }

    } // End locating targets for SCOM access tests

    const auto l_systemModel = targetService().toTarget(sys0node0proc0)->getAttr<ATTR_MODEL>();

    struct {
        Target* target;
        uint64_t initAddr;
        uint64_t expectedAddr;
        bool     expectError;
        ATTR_MODEL_type model;
    } test_data[] = {
        //Target                   Address      Expected     error   model
        { scom_targets[myCORE0],   0x20018652,  0x20018652,  false,  MODEL_POWER10 },
        { scom_targets[myCORE0],   0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myCORE1],   0x20018652,  0x20014652,  false,  MODEL_POWER10 },
        { scom_targets[myCORE1],   0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myCORE0],   0x12012826,  0x12012826,  true,   MODEL_POWER10 },

        { scom_targets[myEQ0],     0x20000020,  0x20000020,  false,  MODEL_POWER10 },
        { scom_targets[myEQ0],     0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myEQ5],     0x20000020,  0x25000020,  false,  MODEL_POWER10 },
        { scom_targets[myEQ5],     0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myEQ5],     0x24030008,  0x24030008,  true,   MODEL_POWER10 },

        { scom_targets[myPERV2],   0x000F0001,  0x020F0001,  false,  MODEL_POWER10 },
        { scom_targets[myPERV2],   0x0FF6FFFF,  0x0FF6FFFF,  true,   MODEL_POWER10 },
        { scom_targets[myPERV2],   0x07010A0A,  0x32010A0A,  true,   MODEL_POWER10 },
        { scom_targets[myPERV32],  0x000F0001,  0x200F0001,  false,  MODEL_POWER10 },
        { scom_targets[myPERV32],  0x0FF6FFFF,  0x0FF6FFFF,  true,   MODEL_POWER10 },
        { scom_targets[myPERV32],  0x0D010400,  0x0D010400,  true,   MODEL_POWER10 },

        { scom_targets[myPEC0],    0x08010002,  0x08010002,  false,  MODEL_POWER10 },
        { scom_targets[myPEC0],    0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myPEC0],    0x12012826,  0x12012826,  true,   MODEL_POWER10 },
        { scom_targets[myPEC1],    0x08010002,  0x09010002,  false,  MODEL_POWER10 },
        { scom_targets[myPEC1],    0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myPEC1],    0x24030008,  0x24030008,  true,   MODEL_POWER10 },

        { scom_targets[myPHB0],    0x08010900,  0x08010900,  false,  MODEL_POWER10 },
        { scom_targets[myPHB0],    0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myPHB0],    0x12012826,  0x12012826,  true,   MODEL_POWER10 },
        { scom_targets[myPHB2],    0x08010900,  0x09010980,  false,  MODEL_POWER10 },
        { scom_targets[myPHB2],    0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myPHB2],    0x24030008,  0x24030008,  true,   MODEL_POWER10 },

        { scom_targets[myMC0],     0x0C000008,  0x0C000008,  false,  MODEL_POWER10 },
        { scom_targets[myMC0],     0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myMC1],     0x0C000008,  0x0D000008,  false,  MODEL_POWER10 },
        { scom_targets[myMC1],     0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },

        { scom_targets[myMI0],     0x0C000008,  0x0C000008,  false,  MODEL_POWER10 },
        { scom_targets[myMI0],     0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myMI1],     0x0C000008,  0x0D000008,  false,  MODEL_POWER10 },
        { scom_targets[myMI1],     0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },

        { scom_targets[myMCC0],    0x0C010D02,  0x0C010D02,  false,  MODEL_POWER10 },
        { scom_targets[myMCC0],    0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myMCC1],    0x0C010D02,  0x0D010D42,  false,  MODEL_POWER10 },
        { scom_targets[myMCC1],    0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },

        { scom_targets[myOMI0],    0x0C011410,  0x0C011410,  false,  MODEL_POWER10 },
        { scom_targets[myOMI1],    0x0C011410,  0x0D011820,  false,  MODEL_POWER10 },
        { scom_targets[myOMI0],    0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myOMI1],    0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },

        { scom_targets[myOMIC0],   0x0C011400,  0x0C011400,  false,  MODEL_POWER10 },
        { scom_targets[myOMIC1],   0x0C011400,  0x0D011800,  false,  MODEL_POWER10 },
        { scom_targets[myOMIC0],   0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
        { scom_targets[myOMIC1],   0x0FFFFFFF,  0x0FFFFFFF,  true,   MODEL_POWER10 },
    };

    int numOfAddr = sizeof test_data / sizeof(test_data[0]);

    for (int i = 0; i < numOfAddr; i++)
      {
        if(test_data[i].target != NULL && test_data[i].model == l_systemModel)
        {
            total++;
            uint64_t tempAddr = test_data[i].initAddr;
            bool needsWakeup = false;
            l_err  = SCOM::scomTranslate(test_data[i].target,
                    tempAddr,
                    needsWakeup);

            if( l_err && !test_data[i].expectError)
            {
                TS_FAIL( "ScomTest::test_P10_translate> ERROR : Unexpected error log from translating addr=0x%.8X for HUID 0x%X", test_data[i].initAddr,
                          get_huid(test_data[i].target)) ;
                errlCommit(l_err,SCOM_COMP_ID);
                fails++;
            }
            else if(l_err == NULL && test_data[i].expectError)
            {
                TS_FAIL( "ScomTest::test_P10_translate> ERROR : Expected an error and did not recieve one after translating addr=0x%.8X for HUID 0x%X",
                        test_data[i].initAddr, get_huid(test_data[i].target)) ;
                fails++;
            }
            else if(tempAddr!= test_data[i].expectedAddr &&
                    l_err == NULL && !test_data[i].expectError)
            {
                TS_FAIL("ScomTest::test_P10_translate_scom> Incorrect translation of: 0x%X produced: 0x%X  expected: 0x%X",
                    test_data[i].initAddr, tempAddr, test_data[i].expectedAddr);
                fails++;
            }
            else if(l_err && test_data[i].expectError)
            {
                delete l_err;
                TRACFCOMP(g_trac_scom, "ScomTest::test_P10_translate_scom> Previous error expected");
            }
        }
        else
        {
          TRACFCOMP(g_trac_scom, "ScomTest::test_P10_translate_scom> Target %d in the list of targets does not exist in the system", i);
        }
      }
         TRACFCOMP( g_trac_scom, "ScomTest::test_P10_translate_scom> %d/%d fails", fails, total );
  }

  /**
   * @brief multi chip SCOM test
   *
   */
  void test_MultiChipSCOMreadWrite_proc(void)
  {

      TRACFCOMP( g_trac_scom, "ScomTest::test_MultiChipSCOMreadWrite_proc> Start" );

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = nullptr;

      // Setup some targets to use
      enum {
          PROC1,
          NUM_TARGETS,
      };
      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = nullptr;
      }

      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_PROC,1);
      scom_targets[PROC1] = TARGETING::targetService().toTarget(epath);

      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists
          if(scom_targets[x] == nullptr)
          {
              continue;
          }
          else if
          (scom_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom,
                         "ScomTest::test_MultiChipSCOMreadWrite_proc> Target %d, "
                         "HUID 0x%08X, is not functional",
                         x, get_huid(scom_targets[x]) );
              scom_targets[x] = nullptr; //remove from our list
          }
      }
      // scratch data to use
      //@fixme: Need to either fabricate some fake registers to use or save off data before modifying SCOMs to avoid
      //   corrupting the HW.
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[PROC1], 0x03050019, 0x1234567887654321},
          { scom_targets[PROC1], 0x02050019, 0x1122334455667788},
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];
      size_t op_size = sizeof(uint64_t);

      // write all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == nullptr)
          {
              continue;
          }

          total++;

          l_err = deviceOp(DeviceFW::WRITE,
                           test_data[x].target,
                           &(test_data[x].data),
                           op_size,
                           DEVICE_XSCOM_ADDRESS(test_data[x].addr) );

          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_MultiChipSCOMreadWrite_proc> [cmd %d] "
                  "Write: Error from device : HUID 0x%08X, addr=0x%08X, data=0x%08X, RC=0x%04X",
                  x, get_huid(test_data[x].target), test_data[x].addr, test_data[x].data, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_MultiChipSCOMreadWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
      }

      // read all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == nullptr)
          {
              continue;
          }

          total++;

          // read the data back using XSCOM
          l_err = deviceOp(DeviceFW::READ,
                           test_data[x].target,
                           &(read_data[x]),
                           op_size,
                           DEVICE_XSCOM_ADDRESS(test_data[x].addr) );

          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_MultiChipSCOMreadWrite_proc> [cmd %d] "
                        "XSCOM Read: Error from device : HUID 0x%08X, addr=0x%08X, data=0x%08X, RC=0x%04X",
                        x, get_huid(test_data[x].target), test_data[x].addr, test_data[x].data, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_MultiChipSCOMreadWrite_proc> ERROR : Unexpected error log from read1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_MultiChipSCOMreadWrite_proc> [cmd %d] "
                        "XSCOM Read: Data miss-match : HUID 0x%08X, addr=0x%08X, read_data=0x%llX, write_data=0x%llX",
                        x, get_huid(test_data[x].target), test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_MultiChipSCOMreadWrite_proc> ERROR : Data miss-match between read and expected data" );
              fails++;
          }


#ifdef __HOSTBOOT_RUNTIME
          TRACFCOMP( g_trac_scom, "Skipping alternative scom compare at runtime" );
#else
          // Read the data back using FSIscom to make sure the data is the same.
          l_err = deviceOp(DeviceFW::READ,
                           test_data[x].target,
                           &(read_data[x]),
                           op_size,
                           DEVICE_SBESCOM_ADDRESS(test_data[x].addr) );


          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_MultiChipSCOMreadWrite_proc> [cmd %d] "
                        "SBEFIFOSCOM Read: Error from device : HUID 0x%08X, addr=0x%08X, RC=0x%04X",
                        x, get_huid(test_data[x].target), test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_MultiChipSCOMreadWrite_proc> ERROR : Unexpected error log from read2" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_MultiChipSCOMreadWrite_proc> [cmd %d] "
                        "SBEFIFOSCOM Read: Data miss-match : HUID 0x%08X, addr=0x%08X, read_data=0x%llX, write_data=0x%llX",
                        x, get_huid(test_data[x].target), test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_MultiChipSCOMreadWrite_proc> ERROR : Data miss-match between read and expected data" );
              fails++;
          }
#endif //__HOSTBOOT_RUNTIME

      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_MultiChipSCOMreadWrite_proc> %d/%d fails", fails, total );

  }

  /**
   * @brief SCOM test via SBEFIFOSCOM
   *
   */
  void test_SBEFIFOSCOMreadWrite_proc(void)
  {
      TRACFCOMP( g_trac_scom, "ScomTest::test_SBEFIFOSCOMreadWrite_proc> Start" );
#ifdef __HOSTBOOT_RUNTIME
      TRACFCOMP( g_trac_scom, "Not valid at runtime" );
      return;
#endif

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      // Setup some targets to use
      enum {
          PROC1,
          NUM_TARGETS
      };
      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = NULL;
      }

      // processor target (physical:sys-0/node-0/proc-1)
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_PROC,1);
      scom_targets[PROC1] = TARGETING::targetService().toTarget(epath);

      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists
          if(scom_targets[x] == NULL)
          {
              TRACFCOMP(g_trac_scom, "test_SBEFIFOSCOMreadWrite_proc> Target %d does NOT exist to read", x);
              continue;
          }
          // skip the sentinel
          else if((TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == scom_targets[x]))
          {
              TRACFCOMP( g_trac_scom, "ScomTest::test_SBEFIFOSCOMreadWrite_proc> Target %d is the MASTER Sentinal, exiting test", x );
              scom_targets[x] = NULL; //remove from our list
          }
          // skip if sbe scom is not enabled
          else if(0 == scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useSbeScom)
          {
              TRACFCOMP( g_trac_scom, "ScomTest::test_SBEFIFOSCOMreadWrite_proc> useSbeScom set to zero on target %d", x );
              scom_targets[x] = NULL; //remove from our list
          }
          else if (scom_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              // NIMBUS model falls through here
              TRACDCOMP( g_trac_scom, "ScomTest::test_SBEFIFOSCOMreadWrite_proc> Target %d is not functional", x );
              scom_targets[x] = NULL; //remove from our list
          }
      }

      // scratch data to use
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
          bool write;
          bool read;
      } test_data[] = {
          { scom_targets[PROC1], 0x02010803, 0x1234567887654321, 1, 1}, // addr: CXA FIR Mask Register
          { scom_targets[PROC1], 0x02011083, 0x1122334455667788, 1, 1}, // addr: PBI CQ FIR Mask Register
          { scom_targets[PROC1], 0x20010A89, 0x1000000000000000, 1, 0}, // addr: Scratch reg 3
          { scom_targets[PROC1], 0x20110A89, 0x0200000000000000, 1, 0}, // addr: Scratch reg 3
          { scom_targets[PROC1], 0x20210A89, 0x0030000000000000, 1, 0}, // addr: Scratch reg 3
          { scom_targets[PROC1], 0x20310A89, 0x0004000000000000, 1, 0}, // addr: Scratch reg 3
          { scom_targets[PROC1], 0x10040018, 0x1000000000000000, 1, 0}, // addr: Local checkstop chipletID 0x10
          { scom_targets[PROC1], 0x20040018, 0x1000000000000000, 1, 0}, // addr: Local checkstop chipletID 0x20
          { scom_targets[PROC1], 0x41010a89, 0x1234000000000000, 0, 1}, // addr: Scratch reg 3 multicast read   (OR type)
          { scom_targets[PROC1], 0x50040018, 0x0000800080000000, 0, 1}, // addr: Local checkstop multicast read (BITWISE type)
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];
      size_t op_size = sizeof(uint32_t);

      // write all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              TRACFCOMP(g_trac_scom, "test_SBEFIFOSCOMreadWrite_proc> Target %d does NOT exist to write", x);
              continue;
          }

          //only run if write is specified
          if(test_data[x].write == false)
          {
              continue;
          }

          op_size = sizeof(uint64_t);

          total++;

          l_err = deviceWrite( test_data[x].target,
                               &(test_data[x].data),
                               op_size,
                               DEVICE_SCOM_ADDRESS(test_data[x].addr) );//fixme-change this to SBE
          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_SBEFIFOSCOMreadWrite_proc> [%d] Write: Error from device : addr=0x%.8X, RC=%.4X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_SBEFIFOSCOMreadWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
      }

      // read all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              continue;
          }

          //only run if read is specified
          if(test_data[x].read == false)
          {
              continue;
          }

          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceRead( test_data[x].target,
                              &(read_data[x]),
                              op_size,
                              DEVICE_SCOM_ADDRESS(test_data[x].addr) );
          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_SBEFIFOSCOMreadWrite_proc> [%d] Read: Error from device : addr=0x%.8X, RC=%.4X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_SBEFIFOSCOMreadWrite_proc> ERROR : Unexpected error log from read1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_SBEFIFOSCOMreadWrite_proc> [%d] Read: Data miss-match : addr=0x%.8X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_SBEFIFOSCOMreadWrite_proc> ERROR : Data miss-match between read and expected data" );
              fails++;
          }
      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_SBEFIFOSCOMreadWrite_proc> %d/%d fails", fails, total );
  }

};



#endif
