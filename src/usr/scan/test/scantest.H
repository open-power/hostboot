/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scan/test/scantest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
/*
      //FIXME: RTC 129630
      TRACFCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> Start" );

      uint64_t fails = 0;
      uint64_t total = 0;
      errlHndl_t l_err = NULL;

      // Setup some targets to use
      enum {
          myPROC0,
          memBuf0,
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
      // target membuf 0
      epath.addLast(TARGETING::TYPE_MEMBUF,4);
      scan_targets[memBuf0] = TARGETING::targetService().toTarget(epath);

      //printk("Scan Proc target functional state %X present %X \n",
      //scan_targets[myPROC0]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional,scan_targets[myPROC0]->getAttr<TARGETING::ATTR_HWAS_STATE>().present );

      TARGETING::HwasState  l_hwasState;
      l_hwasState = scan_targets[myPROC0]->getAttr<TARGETING::ATTR_HWAS_STATE>();

      l_hwasState.functional = true;
      scan_targets[myPROC0]->setAttr<TARGETING::ATTR_HWAS_STATE>(l_hwasState);

      //printk("Scan Proc target functional state after updating is %X present %X \n",
      //scan_targets[myPROC0]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional,scan_targets[myPROC0]->getAttr<TARGETING::ATTR_HWAS_STATE>().present );


      for( uint64_t x = 0; x < NUM_TARGETS; x++ )
      {
          //only run if the target exists
          if(scan_targets[x] == NULL)
          {
              TRACFCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> scan target is null %d", x );
              scan_targets[x] = NULL; //remove from our list
              continue;
          }
          else if ((scan_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom == 0) &&
                   (scan_targets[x]->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom== 0))
          {
              TRACFCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> Target %lX cannot use FSI or Xscom", TARGETING::get_huid(scan_targets[x]));
              scan_targets[x] = NULL; //remove from our list

          }
          else if (scan_targets[x]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true) 
          {
              TRACFCOMP( g_trac_scandd,"scanTest::test_SCANreadWrite_proc> Target %lX is not functional\n",TARGETING::get_huid(scan_targets[x]) );
              scan_targets[x] = NULL; //remove from our list
          } 
      }

      // Scan data .. 
      struct {
          TARGETING::Target* target;
          uint32_t data[8];
          uint64_t ring;
          uint64_t length;
          uint64_t flag;  // used for header check..
      } test_data[] = {
          { scan_targets[myPROC0],
          {0x12121212, 0x12341234, 0x12341234, 0x12341234, 0x12341234,
          0x12341234,0x12341234, 0x00000000}, 0x15030082, 223, 0x0},
          { scan_targets[memBuf0],
          {0x34343434, 0xaaaaaaaa, 0xbbbbbbbb, 0xb0000000, 0x00000000,
          0x00000000, 0x00000000, 0x00000000}, 0x01034001, 100, 0x2},
      };
      const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

      // allocate space for read data
      uint32_t read_data[8];

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

          //printk("Before a write for TARGET %X\n", TARGETING::get_huid(test_data[x].target));
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



      // read all the scan data
      for( uint64_t x = 0; x < NUM_ADDRS; x++ )
      {
          for (int j = 0; j<8;j++)
          {
              read_data[j] = 0;
          }

          //only run if the target exists
          if(test_data[x].target == NULL)
          {
              continue;
          }

          size_t op_size = test_data[x].length;

          total++;
          l_err = deviceRead( test_data[x].target,
                              &(read_data),
                              op_size,
                              DEVICE_SCAN_ADDRESS(test_data[x].ring,
                                                  test_data[x].length,
                                                  test_data[x].flag) );

          if( l_err )
          {
              TRACFCOMP(g_trac_scandd, "scanTest::SCANreadWrite_proc> [%d] Read: Error from device : ring=0x%X, RC=%X", x,  test_data[x].ring, l_err->reasonCode() );
              TS_FAIL( "scanTest::test_SCANreadWrite_proc> ERROR : Unexpected error log from write1" );
              fails++;
              errlCommit(l_err,SCAN_COMP_ID);
          }
          else // read and verify each word read back from the scan read.
          {
              // dont need to check the first word.. that is the header.
              for (uint64_t y=1;y < (test_data[x].length/32 + 1);y++)
              {

                  //printk("scanTest::test_SCANreadWrite_proc> [%ld] Read: Data : ring=0x%lX, read_data=0x%.8x, //write_data=0x%.8x\n", x, test_data[x].ring, read_data[y], test_data[x].data[y]);

                  if(read_data[y] != test_data[x].data[y])
                  {
                      TRACFCOMP(g_trac_scandd, "scanTest::test_SCANreadWrite_proc> [%d] Read: UNEXPECTED Data miss-match : ring=0x%X, read_data=0x%.8x, write_data=0x%llx", x, test_data[x].ring, read_data[y], test_data[x].data[y]);
                      TS_FAIL("scanTest::test_SCANreadWrite_proc> ERROR : Data miss-match between read and expected data" );
                      fails++;
                  }
              }
          }
      }

      TRACFCOMP( g_trac_scandd, "scanTest::test_SCANreadWrite_proc> %d/%d fails", fails, total );
*/
  }


};

#endif
