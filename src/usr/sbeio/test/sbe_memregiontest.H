/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_memregiontest.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef __SBE_MEMREGIONTEST_H
#define __SBE_MEMREGIONTEST_H

/**
 *  @file sbe_memregiontest.H
 *
 *  @brief Test cases for Opening/Closing SBE/HB Memory Regions
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbeioreasoncodes.H>
#include <vmmconst.h>
#include <sys/mm.h>

#include "../sbe_memRegionMgr.H"

#define SBE_TRACD_MRT(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"memRegionTest: " printf_string,##args)
#define SBE_TRACF_MRT(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"memRegionTest: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

class SbeMemRegionTest : public CxxTest::TestSuite
{
  public:

      /**
       *  @brief Open and Close Overlapping Unsecure Memory Regions
       */
      void testSBEMemRegion1(void)
      {
          TS_TRACE(ENTER_MRK"memRegionTest1: Opening and Closing Unsecure Memory Regions");

          errlHndl_t errl = nullptr;

          // Reserve and Open Random Overlapping Memory Regions to force
          // MemRegionMgr to update regions around each other

          // Reserve the Physical Memory set aside in vmmconst.h to use
          // for this test so that the SBEIO commands will work
          uint32_t mem_buf_size = UNSECURE_MEM_REGION_SIZE_TEST;
          uint64_t mem_buf_start_addr = UNSECURE_MEM_REGION_ADDR_TEST;
          void * tmp_virtual_addr = mm_block_map(
                                        reinterpret_cast<void*>
                                           (UNSECURE_MEM_REGION_ADDR_TEST),
                                        UNSECURE_MEM_REGION_SIZE_TEST);
          assert(tmp_virtual_addr!=nullptr, "memRegionTest1: tmp_virtual_addr is nullptr");

          do
          {

          // Loop Test: Open MAX+1 to force a fail
          for (size_t i = 1; i<=SBEIO_MAX_UNSECURE_MEMORY_REGIONS+1 ; i++)
          {
              errl = SBEIO::openUnsecureMemRegion(mem_buf_start_addr +
                                                      ((i-1)*32),
                                                  16,
                                                  true); //true=Read-Write

              if (i <= SBEIO_MAX_UNSECURE_MEMORY_REGIONS)
              {
                  // Expect the open to succeed
                  if (errl)
                  {
                      TS_FAIL("memRegionTest1: Loop Test-%d: SBEIO::openUnsecureMemRegion() Failed: rc=0x%X, plid=0x%X",
                              i, ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
                      break;
                  }
                  else
                  {
                      SBE_TRACD_MRT("memRegionTest1: Loop Test-%d: SBEIO::openUnsecureMemRegion() SUCCESSFUL", i);
                  }
              }
              else // i = SBEIO_MAX_UNSECURE_MEMORY_REGIONS + 1
              {
                  // Expect the open to fail with the return code
                  // SBEIO_EXCEEDS_MAXIMUM_MEM_REGIONS
                  if (ERRL_GETRC_SAFE(errl)==SBEIO::SBEIO_EXCEEDS_MAXIMUM_MEM_REGIONS)
                  {
                      SBE_TRACF_MRT("memRegionTest1: Loop Test-%d: SBEIO::openUnsecureMemRegion() Returned Expected Fail: rc=0x%X, plid=0x%X",
                              i, ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
                      delete errl;
                      errl = nullptr;
                  }
                  else
                  {
                      TS_FAIL("memRegionTest1: Loop Test-%d: SBEIO::openUnsecureMemRegion() Did NOT Return Expected Fail rc=0x%X: got rc=0x%X, plid=0x%X",
                              i, SBEIO::SBEIO_EXCEEDS_MAXIMUM_MEM_REGIONS,
                              ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
                      break;
                  }
              }
          }

          // Skip the rest of the testcase if we already have an error log
          if(errl)
          {
              break;
          }

          // Test 1: Open Read-Write region for front half of memory buffer
          errl = SBEIO::openUnsecureMemRegion(mem_buf_start_addr,
                                              mem_buf_size/2,
                                              true); //true=Read-Write
          if (errl)
          {
              TS_FAIL("memRegionTest1: T1: SBEIO::openUnsecureMemRegion() Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
              break;
          }
          else
          {
              SBE_TRACD_MRT("memRegionTest1: T1: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
          }

          // Test 2: Open Overlapping Read-Only region for middle chunk of
          //   memory buffer
          errl = SBEIO::openUnsecureMemRegion(mem_buf_start_addr+mem_buf_size/4,
                                              mem_buf_size/2,
                                              false); //false=Read-Only
          if (errl)
          {
              TS_FAIL("memRegionTest1: T2: SBEIO::openUnsecureMemRegion() Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
              break;
          }
          else
          {
              SBE_TRACD_MRT("memRegionTest1: T2: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
          }

          // Test 3: Open Overlapping Read-Write region completely enclosed by
          //   existing region
          errl = SBEIO::openUnsecureMemRegion(mem_buf_start_addr+mem_buf_size/2,
                                              mem_buf_size/8,
                                              true); //true=Read-Write
          if (errl)
          {
              TS_FAIL("memRegionTest1: T3: SBEIO::openUnsecureMemRegion() Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
              break;
          }
          else
          {
              SBE_TRACD_MRT("memRegionTest1: T3: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
          }

          // Test 4: Open Overlapping Read-Write region that completely encloses
          //   existing regions
          errl = SBEIO::openUnsecureMemRegion(mem_buf_start_addr+mem_buf_size/8,
                                              (mem_buf_size/4) * 3,
                                              true); //true=Read-Write
          if (errl)
          {
              TS_FAIL("memRegionTest1: T4: SBEIO::openUnsecureMemRegion() Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
              break;
          }
          else
          {
              SBE_TRACD_MRT("memRegionTest1: T4: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
          }

          // Test 5: Open Non-Overlapping Read-Only Region at the end
          //   existing regions
          errl = SBEIO::openUnsecureMemRegion(mem_buf_start_addr+(mem_buf_size/8)*7,
                                              mem_buf_size/8,
                                              false); //false=Read-Only
          if (errl)
          {
              TS_FAIL("memRegionTest1: T5: SBEIO::openUnsecureMemRegion() Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
              break;
          }
          else
          {
              SBE_TRACD_MRT("memRegionTest1: T5: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
          }

          // Test 6: Close Single Region That Exists
          errl = SBEIO::closeUnsecureMemRegion(mem_buf_start_addr+(mem_buf_size/8)*7);
          if (errl)
          {
              TS_FAIL("memRegionTest1: T6: SBEIO::closeUnsecureMemRegion() Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
              break;
          }
          else
          {
              SBE_TRACD_MRT("memRegionTest1: T6: SBEIO::closeUnsecureMemRegion() SUCCESSFUL");
          }

          // Test 7: Re-Close Single Region and look for expected fail
          errl = SBEIO::closeUnsecureMemRegion(mem_buf_start_addr+(mem_buf_size/8)*7);
          if (ERRL_GETRC_SAFE(errl) == SBEIO::SBEIO_MEM_REGION_DOES_NOT_EXIST)
          {
              SBE_TRACF_MRT("memRegionTest1: T7: SBEIO::closeUnsecureMemRegion() Returned Expected Fail: rc=0x%X, plid=0x%X",
                            ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
              delete errl;
              errl = nullptr;
          }
          else
          {
              TS_FAIL("memRegionTest1: T7: SBEIO::closeUnsecureMemRegion() Did NOT Return Expected Fail rc=0x%X: got rc=0x%X, plid=0x%X",
                      SBEIO::SBEIO_MEM_REGION_DOES_NOT_EXIST,
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
              break;
          }

          // Test 99: Close all Memory Regions
          errl = SBEIO::closeAllUnsecureMemRegions();
          if (errl)
          {
              TS_FAIL("memRegionTest1: T99: SBEIO::closeAllUnsecureMemRegions Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
              break;
          }
          else
          {
              SBE_TRACF_MRT("memRegionTest1: T99: Closing All Memory Regions SUCCESSFUL");
          }

          }while(0);

          // Commit any unexpected error logs
          if (errl)
          {
              errlCommit(errl, SBEIO_COMP_ID);
          }

          // Unmap the reserved memory using the virtual address
          int rc = mm_block_unmap(tmp_virtual_addr);

          if (rc)
          {
              TS_FAIL("memRegionTest1: mm_block_unmap failed with rc=%d", rc);
          }

          TS_TRACE(EXIT_MRK"memRegionTest1");
      }

};

#endif
