/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_ffdctest.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#ifndef __SBE_FFDCTEST_H
#define __SBE_FFDCTEST_H

/**
 *  @file sbe_ffdctest.H
 *
 *  @brief Test cases for sbe/hb ffdc package exchange
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbeio/sbe_psudd.H>

extern trace_desc_t* g_trac_sbeio;

class SbeFFDCTest : public CxxTest::TestSuite, public SBEIO::SbePsu
{
  public:

      /**
       *  @brief Test with zero data
       */
      void testSBEFFDC1(void)
      {
           TS_TRACE(ENTER_MRK "sbeioTestFFDC test 1: no data");

           errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                   0,
                   0,
                   0,
                   0);

           if(!SBEIO::SbePsu::handleFFDCError(l_errl))
           {
               TS_FAIL(EXIT_MRK "sbeioTestFFDC test 1 failed.");
           }

           delete l_errl;
           TS_TRACE(EXIT_MRK "sbeioTestFFDC test 1: no data");
      }

      /**
       *  @brief Test with valid magic byte, 1 package, 1 word data
       */
      void testSBEFFDC2(void)
      {
           uint8_t data[16] = {
               255, 220,         // magic byte
               0, 7,             // length of 1 word + 6
               0, 1,             // arbitrary sequence ID
               1, 1,             // arbitrary command class and commamd
               0, 1, 0, 1,       // arbitrary return code
               1, 1, 1, 1        // arbitrary data
           };

           TS_TRACE(ENTER_MRK "sbeioTestFFDC test 2: 1 package, 1 word data");

           errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                   0,
                   0,
                   0,
                   0);

           SBEIO::SbePsu::writeFFDCBuffer(&data, 16);
           if(!SBEIO::SbePsu::handleFFDCError(l_errl))
           {
               TS_FAIL(EXIT_MRK "sbeioTestFFDC test 2 failed.");
           }

           delete l_errl;
           TS_TRACE(EXIT_MRK "sbeioTestFFDC test 2: 1 package, 1 word data");
      }

      /**
       *  @brief Test with valid magic byte, 1 package, 2 word data
       */
      void testSBEFFDC3(void)
      {

           uint8_t data[20] = {
               255, 220,        // magic byte
               0, 8,            // length of 2 word + 6
               0, 2,            // arbitrary sequence ID
               1, 1,            // arbitrary command class and commamd
               0, 1, 0, 1,      // arbitrary return code
               1, 1, 1, 1,      // arbitrary data
               1, 1, 1, 1       // arbitrary data
           };

           errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                   0,
                   0,
                   0,
                   0);
           TS_TRACE(ENTER_MRK "sbeioTestFFDC test 3: 1 package, 2 word data");

           SBEIO::SbePsu::writeFFDCBuffer(&data, 20);
           if(!SBEIO::SbePsu::handleFFDCError(l_errl))
           {
               TS_FAIL(EXIT_MRK "sbeioTestFFDC test 3 failed.");
           }

           delete l_errl;
           TS_TRACE(EXIT_MRK "sbeioTestFFDC test 3: 1 package, 2 word data");

      }

      /**
       *  @brief Test with valid magic byte, 2 package
       */
      void testSBEFFDC4(void)
      {

           uint8_t data[36] = {
               255, 220,         // magic byte
               0, 8,             // length of 1 word + 6
               0, 2,             // arbitrary sequence ID
               1, 1,             // arbitrary command class and commamd
               0, 1, 0, 1,       // arbitrary return code
               1, 1, 1, 1,       // arbitrary data
               1, 1, 1, 1,
               255, 220,         // package 2
               0, 7,             // length of 1 word + 6
               0, 2,             // arbitrary sequence ID
               1, 1,             // arbitrary command class and commamd
               0, 1, 0, 1,       // arbitrary return code
               2, 2, 2, 2
           };

           TS_TRACE(ENTER_MRK "sbeioTestFFDC test 4: 2 packages, 2 word data");

           errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                   0,
                   0,
                   0,
                   0);
           SBEIO::SbePsu::writeFFDCBuffer(&data, 36);
           if(!SBEIO::SbePsu::handleFFDCError(l_errl))
           {
               TS_FAIL(EXIT_MRK "sbeioTestFFDC test 4 failed.");
           }

           delete l_errl;
           TS_TRACE(EXIT_MRK "sbeioTestFFDC test 4: 2 packages, 2 word data");

      }
      /**
       *  @brief Test with valid magic byte, 2 package, 2nd magic byte is bad
       */
      void testSBEFFDC5(void)
      {

           uint8_t data[40] = {
               255, 220,          // magic byte
               0, 8,              // length of 1 word + 6
               0, 2,              // arbitrary sequence ID
               1, 1,              // arbitrary command class and commamd
               0, 1, 0, 1,        // arbitrary return code
               1, 1, 1, 1,        // arbitrary data
               1, 1, 1, 1,
               220, 220,          // package 2 - bad magic byte
               0, 7,              // length of 1 word + 6
               0, 2,              // arbitrary sequence ID
               1, 1,              // arbitrary command class and commamd
               0, 1, 0, 1,        // arbitrary return code
               1, 1, 1, 1,        // arbitrary data
               2, 2, 2, 2
           };

           TS_TRACE(ENTER_MRK"sbeioTestFFDC test 5:\
                   2 packages, bad 2nd magic byte");

           errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                   0,
                   0,
                   0,
                   0);
           SBEIO::SbePsu::writeFFDCBuffer(&data, 40);
           if(!SBEIO::SbePsu::handleFFDCError(l_errl))
           {
               TS_FAIL(EXIT_MRK "sbeioTestFFDC test 5 failed.");
           }

           delete l_errl;
           TS_TRACE(EXIT_MRK"sbeioTestFFDC test 5:\
                   2 packages, bad 2nd magic byte");

      }
};

#endif
