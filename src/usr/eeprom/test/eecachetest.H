/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/test/eecachetest.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#include <errl/errlmanager.H>
#include <errl/errlentry.H>

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
              //printTableOfContentsFromPnor(true);
              //printTableOfContentsFromGlobalMemory(true);

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

              // Uncomment to verify manually
              //printTableOfContentsFromPnor(false);

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
              //printTableOfContentsFromPnor(true);
              //printTableOfContentsFromGlobalMemory(true);

          }while(0);

          TRACFCOMP( g_trac_eeprom, EXIT_MRK"test_invalidateCache  numTests = %d  / num fails = %d", l_numTests, l_numFails );
      }

      // Grab the address of the eecache header with the given target and eeprom role
      errlHndl_t getEecacheHeaderFromPnor(TARGETING::Target * i_target, const EEPROM_ROLE i_eepromRole, uint64_t & o_addr)
      {
          o_addr = 0;
          errlHndl_t l_errl = nullptr;

          eeprom_addr_t l_eeprom_addr;
          l_eeprom_addr.eepromRole = i_eepromRole;
          eepromRecordHeader l_eepromRecordHeader_forLookup;

          l_errl = buildEepromRecordHeader( i_target,
                                            l_eeprom_addr,
                                            l_eepromRecordHeader_forLookup);
          if (l_errl == nullptr)
          {
              o_addr = lookupEepromHeaderAddr(l_eepromRecordHeader_forLookup);
          }
          return l_errl;
      }

      /**
       * @brief Test clear eecache with ancillary roles
       */
      void test_clearEecache()
      {
          TRACFCOMP( g_trac_eeprom, ENTER_MRK"test_clearEecache" );
          errlHndl_t l_errl = nullptr;
          eepromRecordHeader * l_backupVpdRecordHeader_realPnor = nullptr;
          eepromRecordHeader * l_spareTestRecordHeader_realPnor = nullptr;

          uint8_t l_numTests = 0;
          uint8_t l_numFails = 0;

          do{
              // Get a processor Target
              TARGETING::TargetService& tS = TARGETING::targetService();
              TARGETING::Target* testTarget = NULL;
              tS.masterProcChipTargetHandle( testTarget );
              assert(testTarget != NULL);

              // populate backup vpd and spare test
              size_t presentSize;
              bool present = true;
              TRACFCOMP(g_trac_eeprom,"Reading EEPROMs for target 0x%.8X, eeprom cache = %d VPD_BACKUP , target present = %d , eeprom type = %d",
                        TARGETING::get_huid(testTarget), DEVICE_CACHE_EEPROM_ADDRESS(present, EEPROM::VPD_BACKUP));
              presentSize = sizeof(present);
              l_errl = deviceRead(testTarget, &present, presentSize,
                              DEVICE_CACHE_EEPROM_ADDRESS(present, EEPROM::VPD_BACKUP));
              if (l_errl != nullptr)
              {
                  TRACFCOMP(g_trac_eeprom, "pTarget %.8X - failed reading backup VPD eeprom",
                      TARGETING::get_huid(testTarget));
                  break;
              }

              TRACFCOMP(g_trac_eeprom,"Reading EEPROMs for target 0x%.8X, eeprom cache = %d SPARE_TEST , target present = %d , eeprom type = %d",
                        TARGETING::get_huid(testTarget), DEVICE_CACHE_EEPROM_ADDRESS(present, EEPROM::SPARE_TEST));
              l_errl = deviceRead(testTarget, &present, presentSize,
                              DEVICE_CACHE_EEPROM_ADDRESS(present, EEPROM::SPARE_TEST));
              if (l_errl != nullptr)
              {
                  TRACFCOMP(g_trac_eeprom, "pTarget %.8X - failed reading SPARE_TEST vpd",
                      TARGETING::get_huid(testTarget));
                  break;
              }

              // Uncomment to verify manually
              //printTableOfContentsFromPnor(false);

              uint64_t l_addr = 0;

              // Grab the SPARE_TEST eeprom record header first
              l_numTests++;
              l_errl = getEecacheHeaderFromPnor(testTarget, EEPROM::SPARE_TEST, l_addr);
              if (l_errl || l_addr == 0)
              {
                  l_numFails++;
                  TS_FAIL("test_clearEecache(): Unable to find eecache header for %.8X with eeprom_role %d - SPARE_TEST",
                      TARGETING::get_huid(testTarget), EEPROM::SPARE_TEST);
                  break;
              }
              l_spareTestRecordHeader_realPnor = reinterpret_cast<eepromRecordHeader *>(l_addr);

              l_numTests++;
              if(l_spareTestRecordHeader_realPnor->completeRecord.cached_copy_valid != 1)
              {
                  TS_FAIL("test_clearEecache(): Master Proc SPARE_TEST EECACHE is expected to be valid at start of test!");
                  l_numFails++;
                  break;
              }

              // Grab the BACKUP_VPD eeprom record header
              l_numTests++;
              l_addr = 0;
              l_errl = getEecacheHeaderFromPnor(testTarget, EEPROM::VPD_BACKUP, l_addr);
              if (l_errl || l_addr == 0)
              {
                  l_numFails++;
                  TS_FAIL("test_clearEecache(): Unable to find eecache header for %.8X with eeprom_role %d - BACKUP_VPD",
                      TARGETING::get_huid(testTarget), EEPROM::VPD_BACKUP);
                  break;
              }
              l_backupVpdRecordHeader_realPnor = reinterpret_cast<eepromRecordHeader *>(l_addr);

              l_numTests++;
              if(l_backupVpdRecordHeader_realPnor->completeRecord.cached_copy_valid != 1)
              {
                  TS_FAIL("test_clearEecache(): Master Proc VPD_BACKUP EECACHE is expected to be valid at start of test!");
                  l_numFails++;
                  break;
              }

              // Grab the pointer to the EECACHE
              PNOR::SectionInfo_t l_sectionInfo;
              l_errl = PNOR::getSectionInfo(PNOR::EECACHE, l_sectionInfo);
              if(l_errl)
              {
                  TS_FAIL("test_clearEecache(): unable to grab PNOR::EECACHE");
                  l_numFails++;
                  break;
              }
              eecacheSectionHeader * l_eecacheSectionHeaderPtr = reinterpret_cast<eecacheSectionHeader*>(l_sectionInfo.vaddr);

              // now clear out the eecache with backupVpd and spareTest
              l_numTests++;
              l_errl = clearEecache(l_eecacheSectionHeaderPtr, *l_spareTestRecordHeader_realPnor);
              if(l_errl)
              {
                  TS_FAIL("test_clearEecache(): clearEecache returned an error.  rc=%X, plid=%X",
                      ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl));
                  l_numFails++;
                  break;
              }

              // Now verify the clear worked
              l_numTests++;
              if(l_backupVpdRecordHeader_realPnor->completeRecord.cached_copy_valid != 0)
              {
                  TS_FAIL("test_clearEecache() Master Proc BACKUP VPD EECACHE is expected to be invalid after clearEecache is called!");
                  l_numFails++;
                  break;
              }

              l_numTests++;
              if(l_spareTestRecordHeader_realPnor->completeRecord.cached_copy_valid != 0)
              {
                  TS_FAIL("test_clearEecache() Master Proc SPARE_TEST EECACHE is expected to be invalid after clearEecache is called!");
                  l_numFails++;
                  break;
              }

              // Uncomment to verify manually
              //printTableOfContentsFromPnor(false);
              //printTableOfContentsFromGlobalMemory(false);

              // Try to lookup record
              uint64_t addr = lookupEepromCacheAddr(*l_spareTestRecordHeader_realPnor);
              l_numTests++;
              if (addr != 0)
              {
                  TS_FAIL("test_clearEecache() - found eeprom cache address for spare test at 0x%.8X", addr);
                  l_numFails++;
              }

              addr = lookupEepromCacheAddr(*l_backupVpdRecordHeader_realPnor);
              l_numTests++;
              if (addr != 0)
              {
                  TS_FAIL("test_clearEecache() - found eeprom cache address for backup vpd at 0x%.8X", addr);
                  l_numFails++;
              }

              // Re-validate the cache entry
              setIsValidCacheEntry(testTarget, EEPROM::VPD_BACKUP, true);
              setIsValidCacheEntry(testTarget, EEPROM::SPARE_TEST, true);

              TRACFCOMP(g_trac_eeprom,"Verify PNOR updated for VPD_BACKUP and SPARE_TEST");
              printTableOfContentsFromPnor(false);

          }while(0);

          if (l_errl)
          {
              ERRORLOG::errlCommit(l_errl, CXXTEST_COMP_ID);
          }
          TRACFCOMP( g_trac_eeprom, EXIT_MRK"test_clearEecache()  numTests = %d  / num fails = %d", l_numTests, l_numFails );
      }

};

#endif
