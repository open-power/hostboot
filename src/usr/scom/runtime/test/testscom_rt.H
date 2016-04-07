/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/runtime/test/testscom_rt.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#include <hw_access_def.H>
#include <devicefw/driverif.H>


extern trace_desc_t* g_trac_scom;


class ScomTestRt: public CxxTest::TestSuite
{
public:

  /**
   * @brief runtime SCOM test
   *
   */
  void test_SCOMreadWrite_proc(void)
  {

      TRACFCOMP( g_trac_scom, "ScomTest::test_SCOMreadWrite_proc> Start" );

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      // Setup some targets to use
      enum {
          PROC0,
          PROC1,
          NUM_TARGETS
      };
      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = NULL;
      }

      // Target Proc 0
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_PROC,0);
      scom_targets[PROC0] = TARGETING::targetService().toTarget(epath);

      // Target Proc 1
      epath.removeLast();
      epath.addLast(TARGETING::TYPE_PROC,1);
      scom_targets[PROC1] = TARGETING::targetService().toTarget(epath);

      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists
          if(scom_targets[x] == NULL)
          {
              continue;
          }
          else if (scom_targets[x]->
                getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_SCOMreadWrite_proc> Target %d is not functional", x );
              scom_targets[x] = NULL; //remove from our list
          }
      }

      // scratch data to use
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[PROC0], 0x040110C4 ,0xFEEDB0B000001234},
          { scom_targets[PROC0], 0x02040008, 0xFEDCBA9876543210},
          { scom_targets[PROC1], 0x040110C4, 0x1234567887654321},
          { scom_targets[PROC1], 0x02040008, 0x1122334455667788},
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
              TRACFCOMP(g_trac_scom, "ScomTest::test_SCOMreadWrite_proc> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_SCOMreadWrite_proc> ERROR : Unexpected error log from write1" );
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
              TRACFCOMP(g_trac_scom, "ScomTest::test_SCOMreadWrite_proc> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_SCOMreadWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_SCOMreadWrite_proc> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_SCOMreadWrite_proc> ERROR : Data miss-match between read and expected data" );
              fails++;
          }
      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_SCOMreadWrite_proc> %d/%d fails", fails, total );

  }

  /**
   * @brief SCOM test via FSISCOM to Centaur
   *
   */
  void test_FSISCOMreadWrite_centaur(void)
  {
      TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> Start" );
      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      // Setup some targets to use
      enum {
          CENTAUR0, //local
          CENTAUR1, //local
          CENTAUR2, //local
          CENTAUR3, //local
          CENTAUR4, //local
          CENTAUR5, //local
          CENTAUR6, //local
          CENTAUR7, //local
          CENTAUR8, //remote (off PROC1)
          CENTAUR9, //remote (off PROC1)
          NUM_TARGETS
      };
      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = NULL;
      }

      // Target Centaur0 - the local centaur
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_MEMBUF,0);
      scom_targets[CENTAUR0] = TARGETING::targetService().toTarget(epath);

      // remote centaur target (off of sys-0/node-0/proc-1)
      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,8);
      scom_targets[CENTAUR8] = TARGETING::targetService().toTarget(epath);

      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,1);
      scom_targets[CENTAUR1] = TARGETING::targetService().toTarget(epath);
      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,2);
      scom_targets[CENTAUR2] = TARGETING::targetService().toTarget(epath);
      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,3);
      scom_targets[CENTAUR3] = TARGETING::targetService().toTarget(epath);
      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,4);
      scom_targets[CENTAUR4] = TARGETING::targetService().toTarget(epath);
      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,5);
      scom_targets[CENTAUR5] = TARGETING::targetService().toTarget(epath);
      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,6);
      scom_targets[CENTAUR6] = TARGETING::targetService().toTarget(epath);
      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,7);
      scom_targets[CENTAUR7] = TARGETING::targetService().toTarget(epath);
      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,9);
      scom_targets[CENTAUR9] = TARGETING::targetService().toTarget(epath);

      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists and has FSI enabled.
          if(scom_targets[x] == NULL)
          {
              continue;
          }
          else if (scom_targets[x]->
                getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> Target %d is not functional", x );
              scom_targets[x] = NULL; //remove from our list
          }
      }

      // scratch data to use
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[CENTAUR0], 0x02011403 , 0x1234567800000000 },
          { scom_targets[CENTAUR0], 0x02011672 , 0x1122334455667788 },
          { scom_targets[CENTAUR8], 0x02011672 , 0x9E9E9E9E9E9E9E9E },

          { scom_targets[CENTAUR0], 0x030104E0 , 0x00000000f0f0f0f0 },
          { scom_targets[CENTAUR1], 0x030104E1 , 0x1111111100000000 },
          { scom_targets[CENTAUR2], 0x030104E2 , 0x2222222200000000 },
          { scom_targets[CENTAUR3], 0x030104E3 , 0x3333333300000000 },
          { scom_targets[CENTAUR4], 0x030104E4 , 0x4444444400000000 },
          { scom_targets[CENTAUR5], 0x030104E5 , 0x5555555500000000 },
          { scom_targets[CENTAUR6], 0x030104E6 , 0x6666666600000000 },
          { scom_targets[CENTAUR7], 0x030104E7 , 0x7777777700000000 },
          { scom_targets[CENTAUR8], 0x030104E8 , 0x8888888800000000 },
          { scom_targets[CENTAUR9], 0x030104E9 , 0x9999999900000000 },
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];
      size_t op_size = sizeof(uint32_t);

      // write all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          TRACDCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> x=%d, addr=%.8X, target=%p", x,  test_data[x].addr, test_data[x].target );

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
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_centaur> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
      }

      // read all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          TRACDCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> x=%d, addr=%.8X, target=%p", x,  test_data[x].addr, test_data[x].target );

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
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_centaur> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_centaur> ERROR : Data miss-match between read and expected data" );
              fails++;
          }
      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> %d/%d fails", fails, total );

  }


// Currently this test can only be verified manually by looking at the traces
// There is no way to tell if the requested deviceRead/deviceWrite followed the
// opMode. For example you cannot know if the core skipped the wakeup when the
// DO_NOT_DO_WAKEUP opMode is set unless you look at the traces to see if there
// is traces from the wakeup code path. In the future when the wakeup is
// implemented we may have the ability to know if a core has tried to wake or not.
// @TODO RTC: 132413

 void test_opModes(void)
  {

      TRACFCOMP( g_trac_scom, "ScomTest::test_opModes> Start" );

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;


      // Setup some targets to use
      enum {
          myProc0,
          myEX1,
          myEX5,
          NUM_TARGETS
      };

      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = NULL;
      }

      // Target Proc 0 - to make sure we have XSCOM and FSISCOM attributes
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_PROC,0);
      epath.addLast(TARGETING::TYPE_EQ,0);

      scom_targets[myProc0] = TARGETING::targetService().toTarget(epath);


      if (scom_targets[myProc0] != NULL)
      {
          // Add the Ex1 to the path and  create new target
          epath.addLast(TARGETING::TYPE_EX,1);
          scom_targets[myEX1] = TARGETING::targetService().toTarget(epath);

          // remove EX1 target (off of sys-0/node-0/proc-0/eq-0/EX1)
          epath.removeLast();
          // remove eq0 target (off of sys-0/node-0/proc-0/eq-0)
          epath.removeLast();

          // add eq2 target.
          epath.addLast(TARGETING::TYPE_EQ,2);
          // add EX5 target.
          epath.addLast(TARGETING::TYPE_EX,5);
          scom_targets[myEX5] = TARGETING::targetService().toTarget(epath);
      }
      // scratch data to use

      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
          fapi2::OpModes mode;
          bool     expectErr;
      } test_data[] = {
          { scom_targets[myEX1], 0x21000000 ,0x7676767676767676,  fapi2::NORMAL, false},  // pervasive addr does not req wakeup
          { scom_targets[myEX5], 0x20010A02, 0x9191919191919191,  fapi2::NORMAL, false},
          { scom_targets[myEX5], 0x13040002, 0xabcdabcdabcdabcd,  fapi2::NORMAL, true},   // invalid unit 0 address
          { scom_targets[myEX1], 0x000F0166, 0xabcdabcdabcdabcd,  fapi2::NORMAL, true},   // invalid address range for target
          { scom_targets[myEX1], 0x21000000 ,0x7676767676767676,  fapi2::IGNORE_HW_ERROR, false},  // pervasive addr does not req wakeup
          { scom_targets[myEX5], 0x20010A02, 0x9191919191919191,  fapi2::IGNORE_HW_ERROR, false},
          { scom_targets[myEX5], 0x2E010010, 0xabcdabcdabcdabcd,  fapi2::IGNORE_HW_ERROR, true},   // invalid unit 0 address
          { scom_targets[myEX1], 0x2E010009, 0xabcdabcdabcdabcd,  fapi2::IGNORE_HW_ERROR, true},   // invalid address range for target
          { scom_targets[myEX1], 0x21000000 ,0x7676767676767676,  fapi2::DO_NOT_DO_WAKEUP, false}, // pervasive addr does not req wakeup
          { scom_targets[myEX5], 0x20010A02, 0x9191919191919191,  fapi2::DO_NOT_DO_WAKEUP, false},
          { scom_targets[myEX5], 0x13040002, 0xabcdabcdabcdabcd,  fapi2::DO_NOT_DO_WAKEUP, true},   // invalid unit 0 address
          { scom_targets[myEX1], 0x000F0166, 0xabcdabcdabcdabcd,  fapi2::DO_NOT_DO_WAKEUP, true},   // invalid address range for target
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      size_t op_size = sizeof(uint32_t);

      // write all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              TRACFCOMP( g_trac_scom, "ScomTest::test_opModes> test target is null, continuing" );
              continue;
          }
          // check to see if the target is functional.. if not.. skip this target
          else if (test_data[x].target->
              getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACFCOMP( g_trac_scom, "ScomTest::test_opModes> Target %d is not functional", x );
              continue;
          }
          if(test_data[x].expectErr)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_opModes> Writing 0x%X to the addr: 0x%X with opMode: 0x%X and an error is expected",
                        test_data[x].data,test_data[x].addr,test_data[x].mode);
          }
          else
          {
            TRACFCOMP(g_trac_scom, "ScomTest::test_opModes> Writing 0x%X to the addr: 0x%X with opMode: 0x%X and an error is NOT expected",
                      test_data[x].data,test_data[x].addr,test_data[x].mode);
          }
          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceWrite( test_data[x].target,
                               &(test_data[x].data),
                               op_size,
                               DEVICE_SCOM_ADDRESS(test_data[x].addr, test_data[x].mode)
                               );

          if (!test_data[x].expectErr)
          {
              if( l_err )
              {
                  TRACFCOMP(g_trac_scom, "ScomTest::test_opModes> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
                  TS_FAIL( "ScomTest::test_opModes> ERROR : Unexpected error log from deviceWrite" );
                  fails++;
                  errlCommit(l_err,SCOM_COMP_ID);
              }
          }
          else
          {
              if( l_err )
              {
                  TRACFCOMP( g_trac_scom, "ScomTest::test_opModes.. Expected Error log returned> " );
              }
              else
              {
                  TRACFCOMP( g_trac_scom, "ScomTest::test_opModes.. Expected an error log and did not get one for addr 0x%X " ,test_data[x].addr );
                  TS_FAIL( "ScomTest::test_opModes> ERROR : Expected an Error log and did not get one" );
                  fails++;
              }
          }
          delete l_err;
      }

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];

      memset(read_data, 0, sizeof (read_data));


      // read all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
            TRACFCOMP( g_trac_scom, "ScomTest::test_opModes> test target is null, continueing" );
              continue;
          }

          op_size = sizeof(uint64_t);

          if(test_data[x].expectErr)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_opModes> Reading from the addr: 0x%X with opMode: 0x%X and an error is expected",
                        test_data[x].data,test_data[x].addr, test_data[x].mode);
          }
          else
          {
            TRACFCOMP(g_trac_scom, "ScomTest::test_opModes> Reading from the addr: 0x%X with opMode: 0x%X and an error is not expected",
                      test_data[x].data,test_data[x].addr, test_data[x].mode);
          }

          total++;
          l_err = deviceRead( test_data[x].target,
                              &(read_data[x]),
                              op_size,
                              DEVICE_SCOM_ADDRESS(test_data[x].addr, test_data[x].mode));
          if (!test_data[x].expectErr)
          {
              if( l_err )
              {
                  TRACFCOMP(g_trac_scom, "ScomTest::test_opModes> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
                  TS_FAIL( "ScomTest::test_opModes> ERROR : Unexpected error log from deviceRead" );
                  fails++;
                  errlCommit(l_err,SCOM_COMP_ID);
              }
              else if((read_data[x]) != (test_data[x].data))
              {
                  TRACFCOMP(g_trac_scom, "ScomTest::test_opModes> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
                  TS_FAIL( "ScomTest::test_opModes> ERROR : Data miss-match between read and expected data" );
                  fails++;
              }
          }
          else
          {
              if( l_err )
              {
                  TRACFCOMP( g_trac_scom, "ScomTest::test_opModes.. Expected Error log returned> " );
              }
              else
              {
                  TRACFCOMP( g_trac_scom, "ScomTest::test_opModes.. Expected Error log and did not get one for addr 0x%X " ,test_data[x].addr );
                  TS_FAIL( "ScomTest::test_opModes> ERROR : Expected Error log and did not get one" );
                  fails++;
              }
          }
          delete l_err;
      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_opModes> %d/%d fails", fails, total );

 }


 void test_TranslateScom_MCS(void)
  {

      TRACFCOMP( g_trac_scom, "ScomTest::test_TranslateScom_MCS Start" );
      errlHndl_t l_err = NULL;

      uint64_t fails = 0;
      uint64_t total = 0;



      //@VBU workaround - Disable Indirect SCOM test case o
      //Test case read/writes to valid addresses and is
      //potentially destructive on VBU
      if (TARGETING::is_vpo())
      {
           return;
      }

      // Setup some targets to use
      enum {
          myProc0,
          myMCS0,
          myMCS3,
          NUM_TARGETS
      };

      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = NULL;
      }

      // Target Proc 0 - to make sure we have XSCOM and FSISCOM attributes
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_PROC,0);

      scom_targets[myProc0] = TARGETING::targetService().toTarget(epath);

      if (scom_targets[myProc0] != NULL)
      {
          // Add the MCS(0) to the path and  create new target
          epath.addLast(TARGETING::TYPE_MCS,0);
          scom_targets[myMCS0] = TARGETING::targetService().toTarget(epath);

          // remote MCS(0) (off of sys-0/node-0/proc-0/MCS0)
          epath.removeLast();

          // add MCS3 target.
          epath.addLast(TARGETING::TYPE_MCS,3);
          scom_targets[myMCS3] = TARGETING::targetService().toTarget(epath);
      }

      // scratch data to use
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[myMCS0], 0x05010800 ,0x1111111122222222},
          { scom_targets[myMCS3], 0x05010800, 0x3333333344444444},
          { scom_targets[myMCS0], 0x0601184A, 0x0101010101010101}, // invalid
          { scom_targets[myMCS0], 0x0200184A, 0x2323232323232323}, // invalid
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
          // check to see if the target is functional.. if not skip this target
          else if (test_data[x].target->
              getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_TranslateScom_MCS> Target %d is not functional", x );
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
              if ((x == NUM_ADDRS-1) || (x==NUM_ADDRS-2))
              {
                  TRACDCOMP( g_trac_scom, "ScomTest::test_TranslateScom_MCS.. Expected Error log returned> x = %d", x );
              }
              else
              {
                  TRACFCOMP(g_trac_scom, "ScomTest::test_TranslateScom_MCS> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
                  TS_FAIL( "ScomTest::test_TranslateScom_MCS> ERROR : Unexpected error log from write1" );
                  fails++;
                  errlCommit(l_err,SCOM_COMP_ID);
              }

              delete l_err;
          }
      }

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];

      memset(read_data, 0, sizeof read_data);

      // read all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS-2; x++ )
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
              TRACFCOMP(g_trac_scom, "ScomTest::test_TranslateScom_MCS> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_TranslateScom_MCS> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if((read_data[x]) != (test_data[x].data))
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_TranslateScom_MCS> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);

              //temp workaround for MCSs that have been turned off
              // (RTC Issue 84907)
              if (read_data[x] != 0x0)
              {
                   TS_FAIL( "ScomTest::test_TranslateScom_MCS> ERROR : Data miss-match between read and expected data" );
                   fails++;
              }
          }

      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_TranslateScom_MCS> %d/%d fails", fails, total );

 }



 void test_TranslateScom_MBA_MBS(void)
  {
      TRACFCOMP( g_trac_scom, "ScomTest::test_TranslateScom_MBA_MBS Start" );

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
          myMembuf0,
          myMBA0,
          myMBA1,
          NUM_TARGETS
      };


      TARGETING::Target* scom_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scom_targets[x] = NULL;
      }

      // Target Proc 0 - to make sure we have XSCOM and FSISCOM attributes
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_MEMBUF,0);

      scom_targets[myMembuf0] = TARGETING::targetService().toTarget(epath);

      if(scom_targets[myMembuf0] != NULL)
      {

          // add MBA0 target.
          epath.addLast(TARGETING::TYPE_MBA,0);
          scom_targets[myMBA0] = TARGETING::targetService().toTarget(epath);

          // remote MBA0 target (off of sys-0/node-0/membuf-0/MBA0)
          epath.removeLast();

          // Add MBA1 to the path and  create new target
          epath.addLast(TARGETING::TYPE_MBA,1);
          scom_targets[myMBA1] = TARGETING::targetService().toTarget(epath);
      }
      // scratch data to use
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[myMBA0], 0x03010655 ,0x111111111111DDDD},
          { scom_targets[myMBA1], 0x03010655, 0x333333334444EEEE},
          { scom_targets[myMBA0], 0x8000C0140301143F,0x1111111111111212},
          { scom_targets[myMBA1], 0x8000C0140301143F, 0x333333334444abcd},
          { scom_targets[myMBA0], 0x8000C0140301183F,0x111111111111ccee}, // invalid non zero indirect address
          { scom_targets[myMBA0], 0x03010E55, 0x010101010101CCCC},  // invalid passing in a non-0 unit address
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

          // check to see if the target is functional.. if not.. skip this target
          else if (test_data[x].target->
              getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_translate_scom_MBA_MBS> Target %d is not functional", x );
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
            // checking the read of NUM_ADDRs - 1 because the last entry written above failed as expected.
            if ((x == NUM_ADDRS-1) || (x==NUM_ADDRS-2))
            {
                TRACDCOMP( g_trac_scom, "ScomTest::test_translate MBA_MBS.. Expected Errorlog Returned> x = %d", x );
            }
            else
            {
              TRACFCOMP(g_trac_scom, "ScomTest::test_translate_Scom_MBA_MBS> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_Translate_SCOM_MBA_MBS> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
             }

              delete l_err;
          }
      }

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];

      // read all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS-2; x++ )
      {
          memset(read_data, 0, sizeof read_data);

          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              continue;
          }
          // check to see if the target is functional.. if not.. skip this target
          else if (test_data[x].target->
              getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_translate_scom_MBA_MBS> Target %d is not functional", x );
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
              TRACFCOMP(g_trac_scom, "ScomTest::test_TranslateScom_MBA_MBS> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_TranslateScom_MBA_MBS> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if ((x == 2) || (x==3))
          {
              if((read_data[x] & 0x000000000000FFFF) != (test_data[x].data & 0x000000000000FFFF))

              {
                  TRACFCOMP(g_trac_scom, "ScomTest::test_TranslateScom_ABUS> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
                  TS_FAIL( "ScomTest::test_TranslateScom_ABUS> ERROR : Data miss-match between read and expected data" );
                  fails++;
              }
          }
          else if((read_data[x]) != (test_data[x].data))
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_TranslateScom_MBA_MBS> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_TranslateScom_MBA_MBS> ERROR : Data miss-match between read and expected data" );
              fails++;
          }

      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_translateScom_MBA_MBS> %d/%d fails", fails, total );

 }

  //@todo - write tests to verify connection between XSCOM and FSISCOM

  //@todo - write error path testcase for FSI scom using bad address





  /**
   * @brief multi chip SCOM test
   *
   */
  void test_MultiChipSCOMreadWrite_proc(void)
  {

      TRACFCOMP( g_trac_scom, "ScomTest::test_MultiChipSCOMreadWrite_proc> Start" );

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
          else if (scom_targets[x]->
              getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_SCOMreadWrite_proc> Target %d is not functional", x );
              scom_targets[x] = NULL; //remove from our list
          }
      }
      // scratch data to use
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[PROC1],    0x01010803, 0x1234567887654321},
          { scom_targets[PROC1],    0x02040004, 0x1122334455667788},
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

          l_err = deviceOp(    DeviceFW::WRITE,
                               test_data[x].target,
                               &(test_data[x].data),
                               op_size,
                               DEVICE_XSCOM_ADDRESS(test_data[x].addr) );

          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_MultiChipScomWrite_proc> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test__MultiChipScomWrite_proc> ERROR : Unexpected error log from write1" );
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

          // read the data back using XSCOM
          l_err = deviceOp(    DeviceFW::READ,
                               test_data[x].target,
                               &(read_data[x]),
                               op_size,
                               DEVICE_XSCOM_ADDRESS(test_data[x].addr) );

          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test__MultiChipScomWrite_proc> [%d] XSCOM Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test__MultiChipScomWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test__MultiChipScomWrite_proc> [%d] XSCOM Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test__MultiChipScomWrite_proc> ERROR : Data miss-match between read and expected data" );
              fails++;
          }

          // Read the data back using FSIscom to make sure the data is the same.
          l_err = deviceOp(    DeviceFW::READ,
                               test_data[x].target,
                               &(read_data[x]),
                               op_size,
                               DEVICE_FSISCOM_ADDRESS(test_data[x].addr) );


          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test__MultiChipScomWrite_proc> [%d] FSISCOM Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test__MultiChipScomWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test__MultiChipScomWrite_proc> [%d] FSISCOM Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test__MultiChipScomWrite_proc> ERROR : Data miss-match between read and expected data" );
              fails++;
          }

      }

      TRACFCOMP( g_trac_scom, "ScomTest::test__MultiChipScomWrite_proc> %d/%d fails", fails, total );

  }

};



#endif
