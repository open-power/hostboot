/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_psucommandstest.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef __SBE_PSUCOMMANDSTEST_H
#define __SBE_PSUCOMMANDSTEST_H

/**
 *  @file sbe_psucommandstest.H
 *
 *  @brief Test cases for Sending PSU Commands
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbeioreasoncodes.H>

#define SBE_TRACD_PCT(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"psuCommandTest: " printf_string,##args)
#define SBE_TRACF_PCT(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"psuCommandTest: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

class SbePsuCommandTest : public CxxTest::TestSuite
{
  public:

      /**
       *  @brief Send Deadman Timer Commands to start/stop the timer
       */
      void testSBEPsuDeadmanTimer1(void)
      {
          errlHndl_t l_errl = nullptr;

          do
          {

          TS_TRACE(ENTER_MRK"SBEPsuDeadmanTimer1: Send Start + Stop Deadman Timer commands to the SBE");

          TS_TRACE(ENTER_MRK"ATTENTION: Skipping Deadman timer test");
/*
          uint64_t waitTime = 10000; // wait time is 10 sec

          TS_TRACE(ENTER_MRK"ATTENTION: Skipping Deadman timer test");

          l_errl = SBEIO::startDeadmanLoop(waitTime);
          if (l_errl)
          {
              TS_FAIL("sbePsuDeadmanTimer1: Starting Deadman Timer Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl));
              break;
          }

          //Sleep for 2 seconds (setup timer for 10 seconds)
          nanosleep(2,0);

          l_errl = SBEIO::stopDeadmanLoop();
          if ( l_errl )
          {
              TS_FAIL("sbePsuDeadmanTimer1: Stopping Deadman Timer Failed: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl));
              break;
          }
**/

          } while(0);

          // Commit any unexpected error logs
          if (l_errl)
          {
              errlCommit(l_errl, SBEIO_COMP_ID);
          }


          TS_TRACE(EXIT_MRK"SBEPsuDeadmanTimer1");
      }
};

#endif

