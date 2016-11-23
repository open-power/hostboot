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
#include <util/utilbyte.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbeio/sbe_ffdc_parser.H>

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"ffdcParserTest: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

class SbeFFDCTest : public CxxTest::TestSuite
{
  public:

      /**
       *  @brief Test with zero data
       */
      void testSBEFFDC1(void)
      {
           uint8_t l_num = 0;
           uint8_t data[16] = {
               0, 0,             // magic byte
               0, 0,             // package length
               0, 0,             // arbitrary sequence ID
               0, 0,             // arbitrary command class and commamd
               0, 0, 0, 0,       // return code
               0, 0, 0, 0        // arbitrary data
           };

           TS_TRACE("ffdcParserTest test 1 - no data");

           SBEIO::SbeFFDCParser * l_ffdc_parser = new SBEIO::SbeFFDCParser();
           l_ffdc_parser->parseFFDCData(&data);

           l_num = l_ffdc_parser->getTotalPackages();
           if(l_num != 0)
           {
               TS_FAIL("ffdcParserTest test 1 FAILED: 0 expected, got %d", l_num);
           }
           else
           {
               SBE_TRACF("package test 1 PASSED: 0 expected, got %d", l_num);
           }

           delete l_ffdc_parser;

           TS_TRACE("ffdcParserTest test 1 - no data PASSED");
      }

      /**
       *  @brief Test with valid magic byte, 1 package, 1 word data
       */
      void testSBEFFDC2(void)
      {
           uint8_t i;
           uint8_t l_num = 0;
           uint8_t data[16] = {
               0xff, 0xdc,       // magic byte
               0, 4,             // package length of
               0, 1,             // arbitrary sequence ID
               1, 1,             // arbitrary command class and commamd
               0x00, 0x01, 0x02, 0x03, // return code
               1, 1, 1, 1        // arbitrary data
           };

           TS_TRACE("ffdcParserTest test 2 - 1 package, 1 word data");

           SBEIO::SbeFFDCParser * l_ffdc_parser = new SBEIO::SbeFFDCParser();
           l_ffdc_parser->parseFFDCData(&data);

           l_num = l_ffdc_parser->getTotalPackages();
           if(l_num != 1)
           {
               TS_FAIL("ffdcParserTest test 2 FAILED: 1 expected, got %d", l_num);
           }
           else
           {
               SBE_TRACF("package test 2 PASSED: 1 expected, got %d", l_num);
               for(i=0; i<l_num; i++)
               {
                   uint32_t l_rc = l_ffdc_parser->getPackageRC(i);
                   if(l_rc != 66051)
                   {
                       TS_FAIL("ffdcParserTest test 2 FAILED RC: expected 66051, got %d", l_rc);
                   }
                   else
                   {
                       SBE_TRACF("RC test 2 PASSED: 66051 expected, got %d", l_rc);
                   }
               }
           }

           delete l_ffdc_parser;
           TS_TRACE("ffdcParserTest test 2 - 1 package, 1 word data PASSED");
      }

      /**
       *  @brief Test with valid magic byte, 1 package, 2 word data
       */
      void testSBEFFDC3(void)
      {
           uint8_t i;
           uint8_t l_num = 0;
           uint8_t data[20] = {
               0xff, 0xdc,      // magic byte
               0, 5,            // package length
               0, 2,            // arbitrary sequence ID
               1, 1,            // arbitrary command class and commamd
               0x01, 0x02, 0x03, 0x04, // return code
               1, 1, 1, 1,      // arbitrary data
               1, 1, 1, 1       // arbitrary data
           };

           TS_TRACE("ffdcParserTest test 3 - 1 package, 2 word data");

           SBEIO::SbeFFDCParser * l_ffdc_parser = new SBEIO::SbeFFDCParser();
           l_ffdc_parser->parseFFDCData(&data);

           l_num = l_ffdc_parser->getTotalPackages();
           if(l_num != 1)
           {
               TS_FAIL("ffdcParserTest test 3 FAILED: 1 expected, got %d", l_num);
           }
           else
           {
               SBE_TRACF("package test 3 PASSED: 1 expected, got %d", l_num);
               for(i=0; i<l_num; i++)
               {
                   uint32_t l_rc = l_ffdc_parser->getPackageRC(i);
                   if(l_rc != 16909060)
                   {
                       TS_FAIL("ffdcParserTest test 3 FAILED RC: expect 16909060, got %d", l_rc);
                   }
                   else
                   {
                       SBE_TRACF("RC test 3 PASSED: 16909060 expected, got %d", l_rc);
                   }
               }
           }

           delete l_ffdc_parser;
           TS_TRACE("ffdcParserTest test 3 - 1 package, 2 word data PASSED");
      }

      /**
       *  @brief Test with valid magic byte, 2 package
       */
      void testSBEFFDC4(void)
      {
           uint8_t i;
           uint8_t l_num = 0;
           uint8_t data[36] = {
               0xff, 0xdc,       // magic byte
               0, 5,             // package length
               0, 2,             // arbitrary sequence ID
               1, 1,             // arbitrary command class and commamd
               0x02, 0x03, 0x04, 0x05, // return code
               1, 1, 1, 1,       // arbitrary data
               1, 1, 1, 1,
               0xff, 0xdc,       // package 2
               0, 4,             // length of 1 word + 6
               0, 2,             // arbitrary sequence ID
               1, 1,             // arbitrary command class and commamd
               0x02, 0x03, 0x04, 0x05, // return code
               2, 2, 2, 2
           };

           TS_TRACE("ffdcParserTest test 4 - 2 packages, 2 word data");

           SBEIO::SbeFFDCParser * l_ffdc_parser = new SBEIO::SbeFFDCParser();
           l_ffdc_parser->parseFFDCData(&data);

           l_num = l_ffdc_parser->getTotalPackages();
           if(l_num != 2)
           {
               TS_FAIL("ffdcParserTest test 4 FAILED: 2 expected, got %d", l_num);
           }
           else
           {
               SBE_TRACF("package test 4 PASSED: 2 expected, got %d", l_num);
               for(i=0; i<l_num; i++)
               {
                   uint32_t l_rc = l_ffdc_parser->getPackageRC(i);
                   if(l_rc != 33752069)
                   {
                       TS_FAIL("ffdcParserTest test 4 FAILED RC: expect 33752069, got %d", l_rc);
                   }
                   else
                   {
                       SBE_TRACF("RC test 4 PASSED: 33752069 expected, got %d", l_rc);
                   }
               }
           }

           delete l_ffdc_parser;
           TS_TRACE("ffdcParserTest test 4 - 2 packages, 2 word data PASSED");
      }
      /**
       *  @brief Test with valid magic byte, 2 package, 2nd magic byte is bad
       */
      void testSBEFFDC5(void)
      {
           uint8_t i;
           uint8_t l_num = 0;
           uint8_t data[40] = {
               0xff, 0xdc,        // magic byte
               0, 6,              // package length
               0, 2,              // arbitrary sequence ID
               1, 1,              // arbitrary command class and commamd
               0x04, 0x05, 0x06, 0x07, // return code
               1, 1, 1, 1,        // arbitrary data
               1, 1, 1, 1,
               1, 1, 1, 1,
               0xdc, 0xdc,        // package 2 - bad magic byte
               0, 7,              // length of 1 word + 6
               0, 2,              // arbitrary sequence ID
               1, 1,              // arbitrary command class and commamd
               0x05, 0x06, 0x07, 0x08, // return code
               1, 1, 1, 1         // arbitrary data
           };

           TS_TRACE("ffdcParserTest test 5 - 2 packages, bad 2nd magic byte");

           SBEIO::SbeFFDCParser * l_ffdc_parser = new SBEIO::SbeFFDCParser();
           l_ffdc_parser->parseFFDCData(&data);
           l_num = l_ffdc_parser->getTotalPackages();
           if(l_num != 1)
           {
               TS_FAIL("ffdcParserTest test 5 FAILED: 1 expected, got %d", l_num);
           }
           else
           {
               SBE_TRACF("package test 5 PASSED: 1 expected, got %d", l_num);
               for(i=0; i<l_num; i++)
               {
                   uint32_t l_rc = l_ffdc_parser->getPackageRC(i);
                   if(l_rc != 67438087)
                   {
                       TS_FAIL("ffdcParserTest test 5 FAIL RC: 67438087, got %d", l_rc);
                   }
                   else
                   {
                       SBE_TRACF("RC test 5 PASSED: 67438087 expected, got %d", l_rc);
                   }
               }
           }

           delete l_ffdc_parser;
           TS_TRACE("ffdcParserTest test 5 -\
                    2 packages, bad 2nd magic byte PASSED");
      }
};

#endif
