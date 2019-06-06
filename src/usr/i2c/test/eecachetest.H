/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/eecachetest.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
#ifndef __EECACHETEST_H
#define __EECACHETEST_H

/**
 *  @file eepromtest.H
 *
 *  @brief Test cases for the eeprom cache code
 */

#include <cxxtest/TestSuite.H>
#include "../eepromCache.H"

extern trace_desc_t* g_trac_eeprom;

using namespace TARGETING;
using namespace EEPROM;

class EECACHETest: public CxxTest::TestSuite
{
    public:

      /**
      * @brief Verify we can mark a cache as invalid then mark it valid again
      */
      void test_invalidateCache( void )
      {
          uint8_t l_numTests = 0;
          uint8_t l_numFails = 0;

          TRACFCOMP( g_trac_eeprom, ENTER_MRK"test_invalidateCache" );

          do{
              // Uncomment to verify manually
              //printTableOfContents();

              // Get a processor Target
              TARGETING::TargetService& tS = TARGETING::targetService();
              TARGETING::Target* testTarget = NULL;
              tS.masterProcChipTargetHandle( testTarget );
              assert(testTarget != NULL);

              // Create dummy eeprom info w/ VPD_PRIMARY set
              const EEPROM_ROLE l_eepromRole = EEPROM::VPD_PRIMARY;

              eeprom_addr_t l_primaryVpdEeprom;
              l_primaryVpdEeprom.eepromRole = l_eepromRole;

              eepromRecordHeader l_eepromRecordHeader_forLookup;
              eepromRecordHeader * l_eepromRecordHeader_realPnor;

              buildEepromRecordHeader( testTarget,
                                      l_primaryVpdEeprom,
                                      l_eepromRecordHeader_forLookup);

              l_eepromRecordHeader_realPnor = reinterpret_cast<eepromRecordHeader *>(lookupEepromHeaderAddr(l_eepromRecordHeader_forLookup));

              l_numTests++;
              if(l_eepromRecordHeader_realPnor->completeRecord.cached_copy_valid != 1)
              {
                  TS_FAIL("test_invalidateCache Master Proc VPD EECACHE is expected to be valid at start of test!");
                  l_numFails++;
                  break;
              }

              // Invalidate the cache entry
              setIsValidCacheEntry(testTarget, l_eepromRole, 0);

              l_numTests++;
              if(l_eepromRecordHeader_realPnor->completeRecord.cached_copy_valid != 0)
              {
                  TS_FAIL("test_invalidateCache Master Proc VPD EECACHE is expected to be invalid after setIsValidCacheEntry(invalid) is called!");
                  l_numFails++;
                  break;
              }

              // Re-validate the cache entry
              setIsValidCacheEntry(testTarget, l_eepromRole, 1);

              l_numTests++;
              if(l_eepromRecordHeader_realPnor->completeRecord.cached_copy_valid != 1)
              {
                  TS_FAIL("test_invalidateCache Master Proc VPD EECACHE is expected to be invalid after setIsValidCacheEntry(valid) is called!");
                  l_numFails++;
                  break;
              }

              // Uncomment to verify manually
              // printTableOfContents();

          }while(0);

          TRACFCOMP( g_trac_eeprom, EXIT_MRK"test_getEEPROMs  numTests = %d  / num fails = %d", l_numTests, l_numFails );
      }

};

#endif