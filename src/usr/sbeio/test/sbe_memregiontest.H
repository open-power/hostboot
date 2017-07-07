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
#ifndef __SBE_MEMREGION_H
#define __SBE_MEMREGION_H

/**
 *  @file sbe_ffdctest.H
 *
 *  @brief Test cases for Opening/Closing SBE/HB Memory Regions
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>

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

          // Malloc memory buffer to play with
          // @TODO RTC 174970 - reserve a buffer of Physical Memory and use
          //   Physical addresses so that SBEIO commands will be successful
          uint32_t mem_buf_size = 256;
          void * mem_buf = malloc(mem_buf_size);
          uint64_t mem_buf_start_addr =
                       reinterpret_cast<uint64_t>(mem_buf);

          do
          {

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
              SBE_TRACF_MRT("memRegionTest1: T1: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
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
              SBE_TRACF_MRT("memRegionTest1: T2: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
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
              SBE_TRACF_MRT("memRegionTest1: T3: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
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
              SBE_TRACF_MRT("memRegionTest1: T4: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
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
              SBE_TRACF_MRT("memRegionTest1: T5: SBEIO::openUnsecureMemRegion() SUCCESSFUL");
          }

          // @TODO RTC 174970 Add testcases for open/close fail scenarios

          // Test 99: Close all Memory Regions
          errl = SBEIO::closeAllUnsecureMemRegions();
          if (errl)
          {
              TS_FAIL("memRegionTest1: T99: SBEIO::closeAllUnsecureMemRegions Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
          }
          else
          {
              SBE_TRACF_MRT("memRegionTest1: T99: Closing All Memory Regions SUCCESSFUL");
          }

          }while(0);

          free (mem_buf);
          mem_buf = nullptr;

          if (errl)
          {
                errlCommit(errl, SBEIO_COMP_ID);
          }

          TS_TRACE(EXIT_MRK"memRegionTest1");
      }

};

#endif
