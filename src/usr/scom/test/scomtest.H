/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/test/scomtest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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

#include <devicefw/driverif.H>


extern trace_desc_t* g_trac_scom;

namespace SCOM
{
extern errlHndl_t scomTranslate(TARGETING::Target* &i_target,
                         uint64_t &io_addr,
                         TARGETING::Target* io_target_SW);
}
class ScomTest: public CxxTest::TestSuite
{
public:

  /**
   * @brief SCOM test via FSISCOM to Venice
   *
   */
  void test_FSISCOMreadWrite_proc(void)
  {

      TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> Start" );

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
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
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
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
          }
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_proc> ERROR : Data miss-match between read and expected data" );
              fails++;
          }
      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> %d/%d fails", fails, total );

  }

  /**
   * @brief SCOM test via FSISCOM to Centaur
   *
   */
  void test_FSISCOMreadWrite_centaur(void)
  {
      TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> Start" );
      //FIXME: RTC 129630
/*      uint64_t fails = 0;
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
          else if((TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == scom_targets[x]) ||
                  (scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom) ||
                  (scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useInbandScom))
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> Target %d is the MASTER Sentinal or is set to use Xscom or Inband Scom, exiting test", x );
              scom_targets[x] = NULL; //remove from our list
          }
          else if(0 == scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> useFsiScom set to zero on target %d", x );
              scom_targets[x] = NULL; //remove from our list
          }
          else if (scom_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
          {
              TRACDCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> Target %d is not functional", x );
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
*/
  }


  /**
   * @brief SCOM test Indirect SCOM
   *
   */
// @TODO RTC 142928 Enable Indirect Scoms in Simics
//   void _test_IndirectScom(void)
//   {
//       TRACFCOMP( g_trac_scom, "ScomTest::test_IndirectScomReadWrite> Start" );
//
//       uint64_t fails = 0;
//       uint64_t total = 0;
//       errlHndl_t l_err = NULL;
//
//       //@VBU workaround - Disable Indirect SCOM test case o
//       //Test case read/writes to valid addresses and is
//       //potentially destructive on VBU
//       if (TARGETING::is_vpo())
//       {
//            return;
//       }
//
//       // Setup some targets to use
//       enum {
//           myPROC0,
//           NUM_TARGETS
//       };
//       TARGETING::Target* scom_targets[NUM_TARGETS];
//       for( uint64_t x = 0; x < NUM_TARGETS; x++ )
//       {
//           scom_targets[x] = NULL;
//       }
//
//
//       // Target Proc 9 - the FSI wrap-back connection in simics
//       TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
//       epath.addLast(TARGETING::TYPE_SYS,0);
//       epath.addLast(TARGETING::TYPE_NODE,0);
//       epath.addLast(TARGETING::TYPE_PROC,0);
//
//       scom_targets[myPROC0] = TARGETING::targetService().toTarget(epath);
//
//       for( uint64_t x = 0; x < NUM_TARGETS; x++ )
//       {
//           //only run if the target exists
//           if(scom_targets[x] == NULL)
//           {
//               TRACDCOMP( g_trac_scom, "ScomTest - TARGET = NULL - 1 x = %d", x);
//               continue;
//           }
//           else if ((scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom == 0) &&
//                    (scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom == 0))
//           {
//               // If both FSI and XSCOM are not enabled.. then ignore..
//               TRACDCOMP(g_trac_scom, "INDIRECT SCOM>> SKIPPING ");
//               scom_targets[x] = NULL; //remove from our list
//           }
//           else if (scom_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
//           {
//               TRACDCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> Target %d is not functional", x );
//               scom_targets[x] = NULL; //remove from our list
//           }
//
//
//       }
//
//       // scratch data to use
//       //@fixme: Need to either fabricate some fake registers to use or save off data before modifying SCOMs to avoid
//       //   corrupting the HW.
//
//       struct {
//           TARGETING::Target* target;
//           uint64_t addr;
//           uint64_t data;
//       } test_data[] = {
//           { scom_targets[myPROC0], 0x8000F06002011E3F ,0x1234432112344321},
//           { scom_targets[myPROC0], 0x8000086002011E3F, 0x123443211234ABAB},
//       };
//       const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);
//
//
//       size_t op_size = sizeof(uint32_t);
//
//       // write all the test registers
//       for( uint64_t x = 0; x < NUM_ADDRS; x++ )
//       {
//           //only run if the target exists
//           if(test_data[x].target == NULL)
//           {
//               continue;
//           }
//
//           op_size = sizeof(uint64_t);
//
//           total++;
//           l_err = deviceWrite( test_data[x].target,
//                                &(test_data[x].data),
//                                op_size,
//                                DEVICE_SCOM_ADDRESS(test_data[x].addr) );
//           if( l_err )
//           {
//               TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScom_proc> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
//               TS_FAIL( "ScomTest::test_IndirectScom_proc> ERROR : Unexpected error log from write1" );
//               fails++;
//               errlCommit(l_err,SCOM_COMP_ID);
//           }
//       }
//
//       // allocate space for read data
//       uint64_t read_data[NUM_ADDRS];
//
//       memset(read_data, 0, sizeof read_data);
//
//       // read all the test registers
//       for( uint64_t x = 0; x < NUM_ADDRS; x++ )
//       {
//           //only run if the target exists
//           if(test_data[x].target == NULL)
//           {
//               continue;
//           }
//
//           op_size = sizeof(uint64_t);
//
//           total++;
//           l_err = deviceRead( test_data[x].target,
//                               &(read_data[x]),
//                               op_size,
//                               DEVICE_SCOM_ADDRESS(test_data[x].addr) );
//
//           if( l_err )
//           {
//               TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomreadWrite_proc> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
//               TS_FAIL( "ScomTest::test_IndirectScomreadWrite_proc> ERROR : Unexpected error log from write1" );
//               fails++;
//               errlCommit(l_err,SCOM_COMP_ID);
//           }
//           else if((read_data[x] & 0x000000000000FFFF) != (test_data[x].data & 0x000000000000FFFF))
//           {
//               TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomreadWrite_proc> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
//               TS_FAIL( "ScomTest::test_IndirectScomreadWrite_proc> ERROR : Data miss-match between read and expected data" );
//               fails++;
//           }
//
//       }
//
//       TRACFCOMP( g_trac_scom, "ScomTest::test_IndirectScomreadWrite_proc> %d/%d fails", fails, total );
//
//   }

  void test_P9_ScomTranslations(void)
{
    TRACFCOMP( g_trac_scom, "ScomTest::test_P9_ScomTranslations> Start" );

    uint64_t fails = 0;
    uint64_t total = 0;
    errlHndl_t l_err = NULL;

    // Setup some targets to use
    enum {
        myEX0,
        myEX1,
        myCORE0,
        myCORE1,
        myEQ0,
        myEQ5,
        myMCS0,
        myMCS3,
        myXBUS1,
        myMCBIST0,
        myMCBIST1,
        myMCA0,
        myMCA1,
        myPERV1,
        myPERV32,
        myPEC0,
        myPEC1,
        myPHB0,
        myPHB5,
        myOBUS0,
        myOBUS3,
        myNV0,
        myNV1,
        myPPE0,
        myPPE1,
        myOCC0,
        myOCC1,
        mySBE0,
        mySBE1,
        NUM_TARGETS
    };


    TARGETING::Target* scom_targets[NUM_TARGETS];
    for( uint64_t x = 0; x < NUM_TARGETS; x++ )
    {
        scom_targets[x] = NULL;
    }


    /////////////////////////////////////////////////////////////////
    // Set up targets
    /////////////////////////////////////////////////////////////////

    // Target Proc 0
    TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
    epath.addLast(TARGETING::TYPE_SYS,0);
    epath.addLast(TARGETING::TYPE_NODE,0);
    epath.addLast(TARGETING::TYPE_PROC,0);

    epath.addLast(TARGETING::TYPE_EQ,0);
    scom_targets[myEQ0] = TARGETING::targetService().toTarget(epath);

    //add EX0 target
    epath.addLast(TARGETING::TYPE_EX,0);
    scom_targets[myEX0] = TARGETING::targetService().toTarget(epath);

    //add CORE0 target
    epath.addLast(TARGETING::TYPE_CORE,0);
    scom_targets[myCORE0] = TARGETING::targetService().toTarget(epath);

    // remove CORE0 target
    epath.removeLast();

    // add CORE1 target.
    epath.addLast(TARGETING::TYPE_CORE,1);
    scom_targets[myCORE1] = TARGETING::targetService().toTarget(epath);

    // remove CORE1 target
    epath.removeLast();

    // remove EX0 target
    epath.removeLast();

    // add EX1 target.
    epath.addLast(TARGETING::TYPE_EX,1);
    scom_targets[myEX1] = TARGETING::targetService().toTarget(epath);

    // remove EX1 target
    epath.removeLast();

    // remove EQ0 target
    epath.removeLast();

    // add EQ5 target.
    epath.addLast(TARGETING::TYPE_EQ,5);
    scom_targets[myEQ5] = TARGETING::targetService().toTarget(epath);

    // remove EQ5 target
    epath.removeLast();

    //add MCS0 target
    epath.addLast(TARGETING::TYPE_MCS,0);
    scom_targets[myMCS0] = TARGETING::targetService().toTarget(epath);

    //add MCA0 target
    epath.addLast(TARGETING::TYPE_MCA,0);
    scom_targets[myMCA0] = TARGETING::targetService().toTarget(epath);

    // remove MCA0 target
    epath.removeLast();

    // add MCA1 target.
    epath.addLast(TARGETING::TYPE_MCA,1);
    scom_targets[myMCA1] = TARGETING::targetService().toTarget(epath);

    // remove MCA1 target
    epath.removeLast();

    // remove MCS0 target
    epath.removeLast();

    // add MCS3 target.
    epath.addLast(TARGETING::TYPE_MCS,3);
    scom_targets[myMCS3] = TARGETING::targetService().toTarget(epath);

    // remove MCS3 target
    epath.removeLast();

    //add XBUS1 target
    epath.addLast(TARGETING::TYPE_XBUS,0);
    scom_targets[myXBUS1] = TARGETING::targetService().toTarget(epath);

    // remove XBUS1 target
    epath.removeLast();

    //add MCBIST0 target
    epath.addLast(TARGETING::TYPE_MCBIST,0);
    scom_targets[myMCBIST0] = TARGETING::targetService().toTarget(epath);

    // remove MCBIST0 target
    epath.removeLast();

    // add MCBIST1 target.
    epath.addLast(TARGETING::TYPE_MCBIST,1);
    scom_targets[myMCBIST1] = TARGETING::targetService().toTarget(epath);

    // remove MCBIST1 target
    epath.removeLast();

    //add PERV1 target
    epath.addLast(TARGETING::TYPE_PERV,1);
    scom_targets[myPERV1] = TARGETING::targetService().toTarget(epath);

    // remove PERV1 target
    epath.removeLast();

    // add PERV32 target.
    epath.addLast(TARGETING::TYPE_PERV,32);
    scom_targets[myPERV32] = TARGETING::targetService().toTarget(epath);

    // remove PERV32 target
    epath.removeLast();

    //add PEC0 target
    epath.addLast(TARGETING::TYPE_PEC,0);
    scom_targets[myPEC0] = TARGETING::targetService().toTarget(epath);

    //add PHB0 target
    epath.addLast(TARGETING::TYPE_PHB,0);
    scom_targets[myPHB0] = TARGETING::targetService().toTarget(epath);

    // remove PHB0 target
    epath.removeLast();

    // add PHB5 target.
    epath.addLast(TARGETING::TYPE_PHB,5);
    scom_targets[myPHB5] = TARGETING::targetService().toTarget(epath);

    // remove PHB5 target
    epath.removeLast();

    // remove PEC0 target
    epath.removeLast();

    // add PEC1 target.
    epath.addLast(TARGETING::TYPE_PEC,1);
    scom_targets[myPEC1] = TARGETING::targetService().toTarget(epath);

    // remove PEC1 target
    epath.removeLast();

    //add OBUS0 target
    epath.addLast(TARGETING::TYPE_OBUS,0);
    scom_targets[myOBUS0] = TARGETING::targetService().toTarget(epath);

    // remove OBUS0 target
    epath.removeLast();

    // add OBUS3 target.
    epath.addLast(TARGETING::TYPE_OBUS,3);
    scom_targets[myOBUS3] = TARGETING::targetService().toTarget(epath);

    // remove OBUS3 target
    epath.removeLast();

    //add NV0 target
    epath.addLast(TARGETING::TYPE_NV,0);
    scom_targets[myNV0] = TARGETING::targetService().toTarget(epath);

    // remove NV0 target
    epath.removeLast();

    // add NV1 target.
    epath.addLast(TARGETING::TYPE_NV,1);
    scom_targets[myNV1] = TARGETING::targetService().toTarget(epath);

    // remove NV1 target
    epath.removeLast();

    //add PPE0 target
    epath.addLast(TARGETING::TYPE_PPE,0);
    scom_targets[myPPE0] = TARGETING::targetService().toTarget(epath);

    // remove PPE0 target
    epath.removeLast();

    // add PPE1 target.
    epath.addLast(TARGETING::TYPE_PPE,1);
    scom_targets[myPPE1] = TARGETING::targetService().toTarget(epath);

    // remove PPE1 target
    epath.removeLast();

    //add OCC0 target
    epath.addLast(TARGETING::TYPE_OCC,0);
    scom_targets[myOCC0] = TARGETING::targetService().toTarget(epath);

    // remove OCC0 target
    epath.removeLast();

    // add OCC1 target.
    epath.addLast(TARGETING::TYPE_OCC,1);
    scom_targets[myOCC1] = TARGETING::targetService().toTarget(epath);

    // remove OCC1 target
    epath.removeLast();

    //add SBE0 target
    epath.addLast(TARGETING::TYPE_SBE,0);
    scom_targets[mySBE0] = TARGETING::targetService().toTarget(epath);

    // remove SBE0 target
    epath.removeLast();

    // add SBE1 target.
    epath.addLast(TARGETING::TYPE_SBE,1);
    scom_targets[mySBE1] = TARGETING::targetService().toTarget(epath);

    // remove SBE1 target
    epath.removeLast();

    struct {
    TARGETING::Target* target;
    uint64_t initAddr;
    uint64_t expectedAddr;
    bool     expectError;
    } test_data[] = {
      //Target            Address       Expected    error
    { scom_targets[myEX0], 0x21000000 , 0x21000000, false},
    { scom_targets[myEX0], 0x0FFFFFFF, 0x0FFFFFFF, true},
    { scom_targets[myEX1], 0x21000000, 0x23000000, false},
    { scom_targets[myEX1], 0x0FFFFFFF, 0x0FFFFFFF ,true},
    //This address is tricky, it is within EQ0 chip unit but
    //the ring value puts it in the EX1 chip unit space,
    // so you cannot use this address with EX targets
    { scom_targets[myEX1], 0x10012400, 0x10012400, true},
    { scom_targets[myCORE0], 0x20010A46, 0x20010A46, false},
    { scom_targets[myCORE0], 0x0FFFFFFF, 0x0FFFFFFF, true},
    { scom_targets[myCORE1], 0x20010A46, 0x21010A46, false},
    { scom_targets[myCORE1], 0x0FFFFFFF, 0x0FFFFFFF ,true},
    { scom_targets[myCORE0], 0x12012826, 0x12012826, true},
    { scom_targets[myEQ0], 0x10000008 , 0x10000008, false},
    { scom_targets[myEQ0], 0x0FFFFFFF, 0x0FFFFFFF, true},
    { scom_targets[myEQ5], 0x10000008, 0x15000008, false},
    { scom_targets[myEQ5], 0x0FFFFFFF, 0x0FFFFFFF ,true},
    { scom_targets[myEQ5], 0x24030008, 0x24030008, true},
    { scom_targets[myMCS0], 0x05010800 , 0x05010800, false},
    { scom_targets[myMCS0], 0x0FFFFFFF, 0x0FFFFFFF, true},
    { scom_targets[myMCS3], 0x05010800, 0x03010880, false},
    { scom_targets[myMCS3], 0x0FFFFFFF, 0x0FFFFFFF ,true},
    { scom_targets[myMCS0], 0x12012826, 0x12012826, true},
    { scom_targets[myMCS3], 0x24030008, 0x24030008, true},
    { scom_targets[myXBUS1], 0x0FFFFFFFFFFFFFFF , 0x0FFFFFFFFFFFFFFF, true},
    { scom_targets[myXBUS1], 0x12012826, 0x12012826, true},
    { scom_targets[myXBUS1], 0x24030008, 0x24030008, true},
//TODO: RTC 143005 Add MCBIST Targets to scomtest.H
//     { scom_targets[myMCBIST0], 0x07010F15 ,0x07010F15 , false},
//     { scom_targets[myMCBIST0], 0x0FFFFFFF, 0x0FFFFFFF, true},
//     { scom_targets[myMCBIST1], 0x07010F15,0x08010F15 , false},
//     { scom_targets[myMCBIST1], 0x0FFFFFFF, 0x0FFFFFFF ,true},
//     { scom_targets[myMCBIST0], 0x12012826, 0x12012826, true},
//     { scom_targets[myMCBIST1], 0x24030008, 0x24030008, true},
     { scom_targets[myMCA0], 0x07010915, 0x07010915, false},
     { scom_targets[myMCA0], 0x0FFFFFFF, 0x0FFFFFFF, true},
     { scom_targets[myMCA1], 0x07010915, 0x07010955, false},
     { scom_targets[myMCA1], 0x0FFFFFFF, 0x0FFFFFFF ,true},
     { scom_targets[myMCA0], 0x12012826, 0x12012826, true},
     { scom_targets[myMCA1], 0x24030008, 0x24030008, true},
    { scom_targets[myPERV1], 0x00030009, 0x01030009, false},
    { scom_targets[myPERV1], 0x0FF6FFFF, 0x0FF6FFFF, true},
    { scom_targets[myPERV32], 0x00030009, 0x20030009, false},
    { scom_targets[myPERV32], 0x0FF6FFFF, 0x0FF6FFFF ,true},
    { scom_targets[myPERV1], 0x07010A0A, 0x32010A0A, true},
    { scom_targets[myPERV32], 0x0D010400, 0x0D010400, true},
    { scom_targets[myPEC0], 0x04010C03, 0x04010C03, false},
    { scom_targets[myPEC1], 0x04010C03, 0x04011003 ,false},
    { scom_targets[myPEC0], 0x0FFFFFFF, 0x0FFFFFFF, true},
    { scom_targets[myPEC1], 0x0FFFFFFF, 0x0FFFFFFF ,true},
    { scom_targets[myPEC0], 0x12012826, 0x12012826, true},
    { scom_targets[myPEC1], 0x24030008, 0x24030008, true},
    { scom_targets[myPHB0], 0x04010C4E, 0x04010C4E, false},
    { scom_targets[myPHB5], 0x04010C4E, 0x04010C4E ,false},
    { scom_targets[myPHB0], 0x0FFFFFFF, 0x0FFFFFFF, true},
    { scom_targets[myPHB5], 0x0FFFFFFF, 0x0FFFFFFF ,true},
    { scom_targets[myPHB0], 0x12012826, 0x12012826, true},
    { scom_targets[myPHB5], 0x24030008, 0x24030008, true},
    { scom_targets[myOBUS0], 0x09010C55, 0x09010C55, false},
    { scom_targets[myOBUS3], 0x09010C55, 0x0C010C55 ,false},
    { scom_targets[myOBUS0], 0x12012826, 0x12012826, true},
    { scom_targets[myOBUS3], 0x24030008, 0x24030008, true},
    { scom_targets[myNV0], 0x050110D4, 0x050110D4, false},
    { scom_targets[myNV1], 0x050110D4, 0x050110F4,false},
    { scom_targets[myNV0], 0x12012826, 0x12012826, true},
    { scom_targets[myNV1], 0x24030008, 0x24030008, true},
    };

    int numOfAddr = sizeof test_data / sizeof(test_data[0]);

    for (int i = 0; i < numOfAddr; i++)
      {
        if(test_data[i].target != NULL)
        {
            total++;
            uint64_t tempAddr = test_data[i].initAddr;
            l_err  = SCOM::scomTranslate(test_data[i].target,
                    tempAddr,
                    NULL);

            if( l_err && !test_data[i].expectError)
            {
                TRACFCOMP(g_trac_scom, "ScomTest::test_P9_translate_scom> Write: Error from device : addr=0x%X, HUID 0x%X, RC=%X",
                          test_data[i].initAddr,
                          TARGETING::get_huid(test_data[i].target),
                          l_err->reasonCode() );
                TS_FAIL( "ScomTest::test_P9_translate> ERROR : Unexpected error log from write1" );
                fails++;
                errlCommit(l_err,SCOM_COMP_ID);

                delete l_err;
            }
            else if(l_err == NULL && test_data[i].expectError)
            {
                TRACFCOMP(g_trac_scom,  "ScomTest::test_P9_translate> ERROR : Expected an error and did not recieve one for : addr=0x%X, HUID 0x%X",
                          test_data[i].initAddr,
                          TARGETING::get_huid(test_data[i].target))
                TS_FAIL( "ScomTest::test_P9_translate> ERROR : Expected an error and did not recieve one" );
                fails++;
            }
            else if(tempAddr!= test_data[i].expectedAddr &&
                    l_err == NULL && !test_data[i].expectError)
            {
                TRACFCOMP(g_trac_scom, "ScomTest::test_P9_translate_scom> Incorrect translation of: 0x%X produced: 0x%X  expected: 0x%X",
                    test_data[i].initAddr, tempAddr, test_data[i].expectedAddr);
                TS_FAIL( "ScomTest::test_P9_translate> ERROR : Unexpected error log from write1" );
                fails++;
            }
            else if(l_err && test_data[i].expectError)
            {
                delete l_err;
                 TRACFCOMP(g_trac_scom, "ScomTest::test_P9_translate_scom> Previous error expected");
            }
        }
        else
        {
          TRACFCOMP(g_trac_scom, "ScomTest::test_P9_translate_scom> Target %d in the list of targets does not exist in the system", i);
        }
      }
         TRACFCOMP( g_trac_scom, "ScomTest::test_P9_translateScom_SBE> %d/%d fails", fails, total );
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
          else if
          (scom_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
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

  /**
   * Test MBSECCQ bit 16 fix
   * Bit 16 should be on if ATTR_CENTAUR_EC_ENABLE_RCE_WITH_OTHER_ERRORS set
   */
  void test_MBSECCQ(void)
  {
/*
      //FIXME: RTC 129630
      errlHndl_t l_err =  NULL;

      // get an existing membuf
      TARGETING::TargetHandleList targetList;
      getAllChips(targetList,TARGETING::TYPE_MEMBUF);
      if(targetList.size())
      {
          TARGETING::Target * mbuf = targetList[0];
          uint8_t enabled = 0;

          // @todo RTC 101877
          //FAPI_ATTR_GET
          //    (ATTR_CENTAUR_EC_ENABLE_RCE_WITH_OTHER_ERRORS_HW246685,
          //     mbuf,
          //     enabled);
          // Fow now use this:
          if(mbuf->getAttr<TARGETING::ATTR_EC>() >= 0x20)
          {
              enabled = true;
          }

          if(enabled)
          {
              TRACFCOMP(g_trac_scom,"MBSECCQ test run");
              uint64_t data = 0;
              size_t op_size = sizeof(uint64_t);

              l_err = deviceOp(DeviceFW::READ,
                               mbuf,
                               &data,
                               op_size,
                               DEVICE_SCOM_ADDRESS(0x0201144a));

              if(l_err)
              {
                  TS_FAIL("test_MBSECCQ: unexpected error log");
                  errlCommit(l_err,SCOM_COMP_ID);
              }

              if( (data & 0x0000800000000000ull) == 0 )
              {
                  TS_FAIL("test_MBSECCQ: Bit 16 is not set");
              }
          }
      }
*/
  }

};



#endif
