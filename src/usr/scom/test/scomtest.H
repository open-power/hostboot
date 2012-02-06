//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/scom/test/scomtest.H $
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
#include    <sys/time.h>  //mc99 remove


extern trace_desc_t* g_trac_scom;


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
          PROCWRAP,
          PROC1,
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
      epath.addLast(TARGETING::TYPE_PROC,9);
      scom_targets[PROCWRAP] = TARGETING::targetService().toTarget(epath);

      // other processor target (physical:sys-0/node-0/proc-1)
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
          // skip the sentinel or if it Xscom is enabled
          else if((TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == scom_targets[x]) ||
                  (scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom))
          {
              TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> Target %d is the MASTER Sentinal or is set to use Xscom, exiting test", x );
              scom_targets[x] = NULL; //remove from our list
          }
          // skip if fsi scom is not enabled
          else if(0 == scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom)
          {
              TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> useFsiScom set to zero on target %d", x );
              scom_targets[x] = NULL; //remove from our list
          }
          else if( !FSI::isSlavePresent(scom_targets[x]) )
          {
              TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_proc> Target %d is not present", x );
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
          { scom_targets[PROCWRAP], 0x120F0000 ,0xFEEDB0B000001234},
          { scom_targets[PROCWRAP], 0x120F0166, 0xFEDCBA9876543210},
          { scom_targets[PROCWRAP], 0x00040005, 0x0000000000000000},
          { scom_targets[PROCWRAP], 0x02040004, 0xFFFFFFFFFFFFFFFF},
          { scom_targets[PROC1],    0x00040005, 0x1234567887654321},
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
              delete l_err;
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
              delete l_err;
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
      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      // Setup some targets to use
      enum {
          CENTAUR0, //local
          CENTAUR8, //remote (off PROC1)
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
              TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> Target %d is the MASTER Sentinal or is set to use Xscom or Inband Scom, exiting test", x );
              scom_targets[x] = NULL; //remove from our list
          }
          else if(0 == scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom)
          {
              TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> useFsiScom set to zero on target %d", x );
              scom_targets[x] = NULL; //remove from our list
          }
          else if( !FSI::isSlavePresent(scom_targets[x]) )
          {
              TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> Target %d is not present", x );
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
          { scom_targets[CENTAUR0], 0x02011403 , 0x123456789ABCDEF0 },
          { scom_targets[CENTAUR0], 0x02011672 , 0x1122334455667788 },
          { scom_targets[CENTAUR8], 0x02011672 , 0x9E9E9E9E9E9E9E9E },
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
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_centaur> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
              delete l_err;
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
              TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite_centaur> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_FSISCOMreadWrite_centaur> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
              delete l_err;
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


  /**
   * @brief SCOM test Indirect SCOM
   *
   */

  void test_IndirectScom(void)
  {
      TRACFCOMP( g_trac_scom, "ScomTest::test_IndirectScomReadWrite> Start" );

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      //@VBU workaround - Disable Indirect SCOM test case o
      //Test case read/writes to valid addresses and is
      //potentially destructive on VBU
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


      // Setup some targets to use
      enum {
          myPROC9,
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
      epath.addLast(TARGETING::TYPE_PROC,9);

      scom_targets[myPROC9] = TARGETING::targetService().toTarget(epath);

      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists
          if(scom_targets[x] == NULL)
          {
              TRACFCOMP( g_trac_scom, "ScomTest - TARGET = NULL - 1 x = %d", x);
              continue;
          }
          else if ((scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom == 0) &&
                   (scom_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom == 0))
	  {
            // If both FSI and XSCOM are not enabled.. then ignore..
            TRACFCOMP(g_trac_scom, "INDIRECT SCOM>> SKIPPING ");
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
          { scom_targets[myPROC9], 0x80040C0102011A3F ,0x1234432112344321},
          { scom_targets[myPROC9], 0x800C140002011E3F, 0x123443211234ABAB},
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
          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScom_proc> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_IndirectScom_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
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

          op_size = sizeof(uint64_t);

          total++;
          l_err = deviceRead( test_data[x].target,
                              &(read_data[x]),
                              op_size,
                              DEVICE_SCOM_ADDRESS(test_data[x].addr) );

          if( l_err )
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomreadWrite_proc> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_IndirectScomreadWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
              delete l_err;
          }
          else if((read_data[x] & 0x000000000000FFFF) != (test_data[x].data & 0x000000000000FFFF))
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_IndirectScomreadWrite_proc> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_IndirectScomreadWrite_proc> ERROR : Data miss-match between read and expected data" );
              fails++;
          }

      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_IndirectScomreadWrite_proc> %d/%d fails", fails, total );

  }





 void test_TranslateScom_EX(void)
  {

      TRACFCOMP( g_trac_scom, "ScomTest::test_TranslateScom> Start" );

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;


      //@VBU workaround - Disable Indirect SCOM test case o
      //Test case read/writes to valid addresses and is
      //potentially destructive on VBU
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

      scom_targets[myProc0] = TARGETING::targetService().toTarget(epath);

      // Only check the Proc or Membuf targets to look at the SCOM attributes
      if ((scom_targets[myProc0] != NULL) &&
          (scom_targets[myProc0]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom == 0) &&
          (scom_targets[myProc0]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom == 0))
      {
            // If both FSI and XSCOM are not enabled.. then ignore..
            TRACFCOMP(g_trac_scom, "TRANSLATE SCOM>> SKIPPING ");
            scom_targets[myProc0] = NULL; //remove from our list
      }


      if (scom_targets[myProc0] != NULL)
      {
          // Add the Ex1 to the path and  create new target
          epath.addLast(TARGETING::TYPE_EX,1);
          scom_targets[myEX1] = TARGETING::targetService().toTarget(epath);

          // remote EX1 target (off of sys-0/node-0/proc-0/EX1)
          epath.removeLast();

          // add EX5 target.
          epath.addLast(TARGETING::TYPE_EX,5);
          scom_targets[myEX5] = TARGETING::targetService().toTarget(epath);
      }
      // scratch data to use
      //@fixme: Need to either fabricate some fake registers to use or save off data before modifying SCOMs to avoid
      //   corrupting the HW.

      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[myEX1], 0x100F0120 ,0x7676767676767676},
          { scom_targets[myEX5], 0x100F0166, 0x9191919191919191},
          { scom_targets[myEX5], 0x130F0166, 0xabcdabcdabcdabcd},   // invalid unit 0 address
          { scom_targets[myEX1], 0x000F0166, 0xabcdabcdabcdabcd},   // invalid address range for target
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
          if( l_err )
          {
            // last 2 writes have expected failure conditions.
            if ((x == NUM_ADDRS-1) || (x == NUM_ADDRS-2))
	    {
                TRACDCOMP( g_trac_scom, "ScomTest::test_translate_EX.. Expected Error log returned> " );
            }
            else
            {
              TRACFCOMP(g_trac_scom, "ScomTest::test_translate_scom_EX> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_translate_EX> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
             }

              delete l_err;
          }
      }

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];

      memset(read_data, 0, sizeof (read_data));


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
              TRACFCOMP(g_trac_scom, "ScomTest::test_translate_scom_EX> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_translate_scom_EX> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
              delete l_err;
          }
          else if((read_data[x]) != (test_data[x].data))
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_translate_scom_EX> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_translate_scom_EX> ERROR : Data miss-match between read and expected data" );
              fails++;
          }

      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_translateScom_EX> %d/%d fails", fails, total );

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

      // Setup some targets to use
      enum {
          myProc0,
          myMCS1,
          myMCS2,
          myMCS7,
          myMCS4,
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

      // Only check the Proc or Membuf targets to look at the SCOM attributes
      if ((scom_targets[myProc0] != NULL) &&
          (scom_targets[myProc0]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom == 0) &&
          (scom_targets[myProc0]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom == 0))
      {
            // If both FSI and XSCOM are not enabled.. then ignore..
            TRACFCOMP(g_trac_scom, "TRANSLATE_SCOM_MCS>> SKIPPING ");
            scom_targets[myProc0] = NULL; //remove from our list
      }


      if (scom_targets[myProc0] != NULL)
      {
          // Add the MCS(1) to the path and  create new target
          epath.addLast(TARGETING::TYPE_MCS,1);
          scom_targets[myMCS1] = TARGETING::targetService().toTarget(epath);

          // remote MCS(1) (off of sys-0/node-0/proc-0/MCS1)
          epath.removeLast();

          // add MCS4 target.
          epath.addLast(TARGETING::TYPE_MCS,4);
          scom_targets[myMCS4] = TARGETING::targetService().toTarget(epath);

          // remote MCS4 target (off of sys-0/node-0/proc-0/MCS4)
          epath.removeLast();

          // add MCS2 target.
          epath.addLast(TARGETING::TYPE_MCS,2);
          scom_targets[myMCS2] = TARGETING::targetService().toTarget(epath);

          // remove MCS2 target (off of sys-0/node-0/proc-0/MCS4)
          epath.removeLast();

          // add MCS7 target.
          epath.addLast(TARGETING::TYPE_MCS,7);
          scom_targets[myMCS7] = TARGETING::targetService().toTarget(epath);
      }

      // scratch data to use
      //@fixme: Need to either fabricate some fake registers to use or save off data before modifying SCOMs to avoid
      //   corrupting the HW.
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[myMCS1], 0x0201184A ,0x1111111122222222},
          { scom_targets[myMCS4], 0x0201184A, 0x3333333344444444},
          { scom_targets[myMCS2], 0x0201184A, 0x5555555566666666},
          { scom_targets[myMCS7], 0x0201184A, 0x7777777788888888},
//	  { scom_targets[myMCS4], 0x02011C4A, 0x0101010101010101},  // invalid
                                                                    // Unit for
                                                                    // the
                                                                    // target
	  { scom_targets[myMCS4], 0x0601184A, 0x0101010101010101},  // invalid address range
	  { scom_targets[myMCS4], 0x0200184A, 0x2323232323232323},  // Invalid address range for target
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
          if( l_err )
          {
            if ((x == NUM_ADDRS-1) || (x==NUM_ADDRS-2))
            {
                TRACDCOMP( g_trac_scom, "ScomTest::test_translate MCS.. Expected Error log returned> x = %d", x );
            }
            else
            {
              TRACFCOMP(g_trac_scom, "ScomTest::test_translate_Scom_MCS> [%d] Write: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_Translate_SCOM_mcs> ERROR : Unexpected error log from write1" );
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
              delete l_err;
          }
          else if((read_data[x]) != (test_data[x].data))
          {
              TRACFCOMP(g_trac_scom, "ScomTest::test_TranslateScom_MCS> [%d] Read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].addr, read_data[x], test_data[x].data);
              TS_FAIL( "ScomTest::test_TranslateScom_MCS> ERROR : Data miss-match between read and expected data" );
              fails++;
          }

      }

      TRACFCOMP( g_trac_scom, "ScomTest::test_translateScom_MCS> %d/%d fails", fails, total );

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

      // Setup some targets to use
      enum {
          myMembuf0,
          myMBS,
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

      if ( (scom_targets[myMembuf0] != NULL) &&
          (scom_targets[myMembuf0]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom == 0) &&
          (scom_targets[myMembuf0]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom == 0))
      {
            // If both FSI and XSCOM are not enabled.. then ignore..
            TRACFCOMP(g_trac_scom, "TRANSLATE_SCOM_MBA_MBS>> SKIPPING ");
            scom_targets[myMembuf0] = NULL; //remove from our list
      }

      if(scom_targets[myMembuf0] != NULL)
      {
          // add MBS target.
          epath.addLast(TARGETING::TYPE_MBS,0);
          scom_targets[myMBS] = TARGETING::targetService().toTarget(epath);

          // add MBA0 target.
          epath.addLast(TARGETING::TYPE_MBA,0);
          scom_targets[myMBA0] = TARGETING::targetService().toTarget(epath);

          // remote MBA0 target (off of sys-0/node-0/membuf-0/MBS-0/MBA0)
          epath.removeLast();

          // Add MBA1 to the path and  create new target
          epath.addLast(TARGETING::TYPE_MBA,1);
          scom_targets[myMBA1] = TARGETING::targetService().toTarget(epath);
      }
      // scratch data to use
      //@fixme: Need to either fabricate some fake registers to use or save off data before modifying SCOMs to avoid
      //   corrupting the HW.
      struct {
          TARGETING::Target* target;
          uint64_t addr;
          uint64_t data;
      } test_data[] = {
          { scom_targets[myMBA0], 0x03010655 ,0x1111111122222222},
          { scom_targets[myMBA1], 0x03010655, 0x3333333344444444},
          { scom_targets[myMBS],  0x02011417, 0x1231231231231231},
	  { scom_targets[myMBA0], 0x03010E55, 0x0101010101010101},  // invalid passing in a non-0 unit address
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      size_t op_size = sizeof(uint32_t);

      // write all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              TRACFCOMP( g_trac_scom, "MBA_MBS ScomTest before device write- TARGET = NULL x = %d", x);

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
            if (x == (NUM_ADDRS-1))
            {
                TRACDCOMP( g_trac_scom, "ScomTest::test_translate MCS.. Expected Errorlog Returned> x = %d", x );
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
      for( uint64_t x = 0; x < NUM_ADDRS-1; x++ )
      {
          memset(read_data, 0, sizeof read_data);

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
              TRACFCOMP(g_trac_scom, "ScomTest::test_TranslateScom_MBA_MBS> [%d] Read: Error from device : addr=0x%X, RC=%X", x,  test_data[x].addr, l_err->reasonCode() );
              TS_FAIL( "ScomTest::test_TranslateScom_MBA_MBS> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCOM_COMP_ID);
              delete l_err;
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



  //@todo - address translation

};

#endif
