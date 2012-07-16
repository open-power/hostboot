/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scan/test/scantest.H $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __SCANTEST_H
#define __SCANTEST_H

/**
 *  @file scomtest.H
 *
 *  @brief Test case for scan code
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <targeting/common/util.H>


extern trace_desc_t* g_trac_scandd;


class ScanTest: public CxxTest::TestSuite
{
public:

  /**
   * @brief SCAN test
   *
   */

   void test_SCANreadWrite_proc(void)
  {


  }

// Skipping the real scan test for now because the SCOM regs are not defined and simics
// is broken for the actions required.

   void skip_SCANreadWrite_proc(void)
//  void test_SCANreadWrite_proc(void)
  {

      TRACFCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> Start" );

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      // Setup some targets to use
      enum {
          myPROC0,
          centaur0,
          NUM_TARGETS
      };
      TARGETING::Target* scan_targets[NUM_TARGETS];
      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          scan_targets[x] = NULL;
      }

      // Target Proc 0
      TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
      epath.addLast(TARGETING::TYPE_SYS,0);
      epath.addLast(TARGETING::TYPE_NODE,0);
      epath.addLast(TARGETING::TYPE_PROC,0);
      scan_targets[myPROC0] = TARGETING::targetService().toTarget(epath);

      epath.removeLast();
      epath.addLast(TARGETING::TYPE_MEMBUF,0);
      scan_targets[centaur0] = TARGETING::targetService().toTarget(epath);

      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists
          if(scan_targets[x] == NULL)
          {
              TRACFCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> scan target is null %d", x );
              continue;
          }
/*          else if (scan_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true) 
          {
              TRACFCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> Target %d is not functional", x );
              scan_targets[x] = NULL; //remove from our list
          } */
      }

      // scratch data to use
      //@fixme: Need to either fabricate some fake registers to use or save off data before modifying scans to avoid
      //   corrupting the HW.
      struct {
          TARGETING::Target* target;
          uint64_t data;
          uint64_t ring;
          uint64_t length;
          uint64_t flag;  // Set to zero now until simics works or the header will fail
      } test_data[] = {
          { scan_targets[myPROC0],    0x1234123456785678, 0x1103400A, 96, 0x0},
          { scan_targets[centaur0],    0xaaaaaaaaaaaaaaaa, 0x00030088, 436, 0x0},
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      // allocate space for read data
      uint64_t read_data[NUM_ADDRS];

      // write all the test registers
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              TRACDCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> TARGEt does not exist 2 %d", x );

              continue;
          }

          size_t op_size = test_data[x].length;

          TRACDCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> Before Device Write  2>>> " );
          total++;
          l_err = deviceWrite( test_data[x].target,
                               &(test_data[x].data),
                               op_size,
                               DEVICE_SCAN_ADDRESS(test_data[x].ring,
                                                   test_data[x].length,
                                                   test_data[x].flag) );

          if( l_err )
          {
              TRACFCOMP(g_trac_scandd, "scanTest::test_SCANreadWrite_proc> [%d] Write: Error from device : ring=0x%X, RC=%X", x,  test_data[x].ring, l_err->reasonCode() );
              TS_FAIL( "scanTest::test_SCANreadWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCAN_COMP_ID);
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

          size_t op_size = test_data[x].length;

          total++;
          l_err = deviceRead( test_data[x].target,
                              &(read_data[x]),
                              op_size,
                              DEVICE_SCAN_ADDRESS(test_data[x].ring, test_data[x].length,test_data[x].flag) );
          if( l_err )
          {
              TRACFCOMP(g_trac_scandd, "scanTest::SCANreadWrite_proc> [%d] Read: Error from device : ring=0x%X, RC=%X", x,  test_data[x].ring, l_err->reasonCode() );
              TS_FAIL( "scanTest::test_SCANreadWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCAN_COMP_ID);
          }
// NOTE:: currently expect fails
          else if(read_data[x] != test_data[x].data)
          {
              TRACFCOMP(g_trac_scandd, "scanTest::test_SCANreadWrite_proc> [%d] Read: EXPECTED Data miss-match : ring=0x%X, read_data=0x%llx, write_data=0x%llx", x, test_data[x].ring, read_data[x], test_data[x].data);
              //TS_FAIL( "scanTest::test_SCANreadWrite_proc> ERROR : Data miss-match between read and expected data" );
              //fails++;
          }
      }

      TRACFCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> %d/%d fails", fails, total );

  }






};

#endif
