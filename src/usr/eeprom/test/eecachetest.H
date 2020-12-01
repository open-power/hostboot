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
#include <conversions.H>

extern trace_desc_t* g_trac_eeprom;

using namespace TARGETING;
using namespace EEPROM;

// Bring in updateEecacheContents(...) and updateEecacheHeader(...) to be used in tests without
// making the API available through a header file
namespace EEPROM
{
    errlHndl_t updateEecacheContents(TARGETING::Target*            i_target,
                                       EEPROM::EEPROM_ROLE const   i_eepromType,
                                       void        const * const   i_eepromBuffer,
                                       size_t              const   i_eepromBuflen,
                                       eepromRecordHeader  const & i_recordHeader);

    errlHndl_t updateEecacheHeader(eepromRecordHeader   const & i_completeRecordHeader,
                                   eepromRecordHeader * const & io_pnorRecordToUpdate);
}

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
       * @brief Test clear eecache with cached data from SEEPROM 3
       *
       * This test uses the clearEecache() function to delete the cached data from SEEPROM 3.
       * At the end of the test, these items are manually placed back into the EECACHE.
       */
      void test_clearEecache()
      {
          TRACFCOMP( g_trac_eeprom, ENTER_MRK"test_clearEecache" );
          errlHndl_t l_errl = nullptr;

          // Will be used as pointers to the actual headers in PNOR EECACHE section
          eepromRecordHeader * l_mvpdRecordHeader_realPnor      = nullptr;
          eepromRecordHeader * l_spareTestRecordHeader_realPnor = nullptr;
          eepromRecordHeader * l_wofRecordHeader_realPnor       = nullptr;

          // eepromRecordHeader copies that will be used to restore the header entries in the EECACHE
          eepromRecordHeader l_spareRecordHeader_copy;
          eepromRecordHeader l_wofRecordHeader_copy;

          // Will be used to store data currently in the EECACHE and restore it after tests are done
          uint8_t * l_mvpdData  = nullptr;
          uint8_t * l_spareData = nullptr;
          uint8_t * l_wofData  = nullptr;

          // Flag to mark if data was stored successfully
          bool l_didStoreSpare = false;
          bool l_didStoreWof = false;

          uint8_t l_numTests = 0;
          uint8_t l_numFails = 0;

          // Get a processor Target
          TARGETING::TargetService& tS = TARGETING::targetService();
          TARGETING::Target* testTarget = NULL;
          tS.masterProcChipTargetHandle( testTarget );
          assert(testTarget != NULL);

          do{
              /* Store MVPD, WOF, and Spare data from EECACHE */

              const size_t l_offset = 0; // Read each VPD from its 0-offset

              // Store MVPD
              SpiMvpdPrimaryInfo l_mvpdInfo = testTarget->getAttr<ATTR_SPI_MVPD_PRIMARY_INFO>();
              size_t l_mvpdSize = l_mvpdInfo.dataSizeKB * CONVERSIONS::BYTES_PER_KB;
              l_mvpdData = new uint8_t[l_mvpdSize]();
              TRACFCOMP(g_trac_eeprom,"Reading cached VPD_PRIMARY from SEEPROM of target 0x%.8X, "
                        "record size = %d bytes", TARGETING::get_huid(testTarget), l_mvpdSize);
              l_errl = deviceRead(testTarget, l_mvpdData, l_mvpdSize,
                                DEVICE_EEPROM_ADDRESS(EEPROM::VPD_PRIMARY, l_offset, EEPROM::CACHE));
              if (l_errl != nullptr)
              {
                  TS_FAIL("pTarget %.8X - failed reading primary VPD eeprom", TARGETING::get_huid(testTarget));
                  break;
              }

              // Store Spare
              // Spare was not cached previously, so must be cached here for the first time, then
              // data is read out

              // Cache Spare
              bool present = true;
              size_t presentSize = sizeof(present);
              l_errl = deviceRead(testTarget, &present, presentSize,
                                  DEVICE_CACHE_EEPROM_ADDRESS(present, EEPROM::SPARE_TEST));
              if (l_errl != nullptr)
              {
                  TS_FAIL("pTarget %.8X - failed caching SPARE_TEST", TARGETING::get_huid(testTarget));
                  break;
              }

              // Store Spare
              SpiEepromSpareInfo l_spareInfo = testTarget->getAttr<ATTR_SPI_EEPROM_SPARE_INFO>();
              size_t l_spareSize = l_spareInfo.dataSizeKB * CONVERSIONS::BYTES_PER_KB;
              l_spareData = new uint8_t[l_spareSize]();
              TRACFCOMP(g_trac_eeprom,"Reading cached SPARE_TEST from SEEPROM of target 0x%.8X, "
                        "record size = %d bytes", TARGETING::get_huid(testTarget), l_spareSize);
              l_errl = deviceRead(testTarget, l_spareData, l_spareSize,
                                DEVICE_EEPROM_ADDRESS(EEPROM::SPARE_TEST, l_offset, EEPROM::CACHE));
              if (l_errl != nullptr)
              {
                  TS_FAIL("pTarget %.8X - failed reading SPARE_TEST", TARGETING::get_huid(testTarget));
                  break;
              }
              else
              {
                  l_didStoreSpare = true;
              }

              // Store WOF
              SpiWofDataInfo l_wofInfo = testTarget->getAttr<ATTR_SPI_WOF_DATA_INFO>();
              size_t l_wofSize = l_wofInfo.dataSizeKB * CONVERSIONS::BYTES_PER_KB;
              l_wofData = new uint8_t[l_wofSize]();
              TRACFCOMP(g_trac_eeprom,"Reading cached WOF_DATA from SEEPROM of target 0x%.8X, "
                        "record size = %d bytes", TARGETING::get_huid(testTarget), l_wofSize);
              l_errl = deviceRead(testTarget, l_wofData, l_wofSize,
                                  DEVICE_EEPROM_ADDRESS(EEPROM::WOF_DATA, l_offset, EEPROM::CACHE));
              if (l_errl != nullptr)
              {
                  TS_FAIL("pTarget %.8X - failed reading WOF_DATA", TARGETING::get_huid(testTarget));
                  break;
              }
              else
              {
                  l_didStoreWof = true;
              }

              // Uncomment to verify manually
              //printTableOfContentsFromPnor(false);


              /* Test getting (and storing) valid eepromRecordHeaders for MVPD, WOF, and Spare */

              uint64_t l_addr = 0;

              // Grab the SPARE_TEST eeprom record header
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
              // Save off header
              l_spareRecordHeader_copy = *l_spareTestRecordHeader_realPnor;

              l_numTests++;
              if(l_spareTestRecordHeader_realPnor->completeRecord.cached_copy_valid != 1)
              {
                  TS_FAIL("test_clearEecache(): Master Proc SPARE_TEST EECACHE is expected to be valid at start of test!");
                  l_numFails++;
                  break;
              }

              // Grab the MVPD eeprom record header
              l_numTests++;
              l_addr = 0;
              l_errl = getEecacheHeaderFromPnor(testTarget, EEPROM::VPD_PRIMARY, l_addr);
              if (l_errl || l_addr == 0)
              {
                  l_numFails++;
                  TS_FAIL("test_clearEecache(): Unable to find eecache header for %.8X with eeprom_role %d - PRIMARY_VPD",
                      TARGETING::get_huid(testTarget), EEPROM::VPD_PRIMARY);
                  break;
              }
              l_mvpdRecordHeader_realPnor = reinterpret_cast<eepromRecordHeader *>(l_addr);

              l_numTests++;
              if(l_mvpdRecordHeader_realPnor->completeRecord.cached_copy_valid != 1)
              {
                  TS_FAIL("test_clearEecache(): Master Proc VPD_PRIMARY EECACHE is expected to be valid at start of test!");
                  l_numFails++;
                  break;
              }

              // Grab the WOF eeprom record header
              l_numTests++;
              l_addr = 0;
              l_errl = getEecacheHeaderFromPnor(testTarget, EEPROM::WOF_DATA, l_addr);
              if (l_errl || l_addr == 0)
              {
                  l_numFails++;
                  TS_FAIL("test_clearEecache(): Unable to find eecache header for %.8X with eeprom_role %d - WOF_DATA",
                      TARGETING::get_huid(testTarget), EEPROM::WOF_DATA);
                  break;
              }
              l_wofRecordHeader_realPnor = reinterpret_cast<eepromRecordHeader *>(l_addr);
              // Save off header
              l_wofRecordHeader_copy = *l_wofRecordHeader_realPnor;

              l_numTests++;
              if(l_wofRecordHeader_realPnor->completeRecord.cached_copy_valid != 1)
              {
                  TS_FAIL("test_clearEecache(): Master Proc WOF_DATA EECACHE is expected to be valid at start of test!");
                  l_numFails++;
                  break;
              }


              /* Delete content and verify it was cleared */

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

              // now clear out the eecache of Spare and WOF from SEEPROM 3
              l_numTests++;
              l_errl = clearEecache(l_eecacheSectionHeaderPtr, *l_spareTestRecordHeader_realPnor);
              if(l_errl)
              {
                  TS_FAIL("test_clearEecache(): clearEecache for SEEPROM 3 returned an error.  rc=%X, plid=%X",
                      ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl));
                  l_numFails++;
                  break;
              }

              // Now verify the clear worked (MVPD should not have been cleared)
              l_numTests++;
              if(l_mvpdRecordHeader_realPnor->completeRecord.cached_copy_valid != 1)
              {
                  TS_FAIL("test_clearEecache() Master Proc PRIMARY VPD EECACHE is expected to be valid after clearEecache is called!");
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

              l_numTests++;
              if(l_wofRecordHeader_realPnor->completeRecord.cached_copy_valid != 0)
              {
                  TS_FAIL("test_clearEecache() Master Proc WOF_DATA EECACHE is expected to be invalid after clearEecache is called!");
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

              addr = lookupEepromCacheAddr(*l_mvpdRecordHeader_realPnor);
              l_numTests++;
              if (addr == 0)
              {
                  TS_FAIL("test_clearEecache() - could not find eeprom cache address for primary vpd at 0x%.8X", addr);
                  l_numFails++;
              }

              addr = lookupEepromCacheAddr(*l_wofRecordHeader_realPnor);
              l_numTests++;
              if (addr != 0)
              {
                  TS_FAIL("test_clearEecache() - found eeprom cache address for wof at 0x%.8X", addr);
                  l_numFails++;
              }

              // Re-validate the cache entry
              setIsValidCacheEntry(testTarget, EEPROM::VPD_PRIMARY, true);
              setIsValidCacheEntry(testTarget, EEPROM::SPARE_TEST, true);
              setIsValidCacheEntry(testTarget, EEPROM::WOF_DATA, true);

              TRACFCOMP(g_trac_eeprom,"Verify PNOR updated for VPD_PRIMARY, SPARE_TEST and WOF_DATA");
              printTableOfContentsFromPnor(false);

          }while(0);

          if (l_errl)
          {
              ERRORLOG::errlCommit(l_errl, CXXTEST_COMP_ID);
          }

          // Place back EECACHE data that was saved off:
          // This is done in a second while-loop as it may fail in many places, and it cannot be
          // done at the end of the above while-loop as that is not guaranteed to end successfully.
          l_errl = nullptr;
          do{
              if (l_didStoreSpare)
              {
                  l_errl = updateEecacheHeader(l_spareRecordHeader_copy, l_spareTestRecordHeader_realPnor);
                  if (l_errl != nullptr)
                  {
                      TS_FAIL("test_clearEecache() - Failed to update header for EEPROM::SPARE_TEST");
                      break;
                  }

                  l_errl = updateEecacheContents(testTarget, EEPROM::SPARE_TEST, l_spareData,
                            l_spareRecordHeader_copy.completeRecord.cache_copy_size * CONVERSIONS::BYTES_PER_KB,
                            l_spareRecordHeader_copy);
                  if (l_errl != nullptr)
                  {
                      TS_FAIL("test_clearEecache() - Failed to place back cached data for EEPROM::SPARE_TEST");
                      break;
                  }
              }
              if (l_didStoreWof)
              {
                  l_errl = updateEecacheHeader(l_wofRecordHeader_copy, l_wofRecordHeader_realPnor);
                  if (l_errl != nullptr)
                  {
                      TS_FAIL("test_clearEecache() - Failed to update header for EEPROM::WOF_DATA");
                      break;
                  }

                  l_errl = updateEecacheContents(testTarget, EEPROM::WOF_DATA, l_wofData,
                            l_wofRecordHeader_copy.completeRecord.cache_copy_size * CONVERSIONS::BYTES_PER_KB,
                            l_wofRecordHeader_copy);
                  if (l_errl != nullptr)
                  {
                      TS_FAIL("test_clearEecache() - Failed to place back cached data for EEPROM::WOF_DATA");
                      break;
                  }
              }
          } while (0);

          if (l_errl)
          {
              ERRORLOG::errlCommit(l_errl, CXXTEST_COMP_ID);
          }

          // Release non-empty blocks of memory
          if (l_mvpdData ) { delete[] l_mvpdData;  }
          if (l_spareData) { delete[] l_spareData; }
          if (l_wofData  ) { delete[] l_wofData;   }

          TRACFCOMP( g_trac_eeprom, EXIT_MRK"test_clearEecache()  numTests = %d  / num fails = %d", l_numTests, l_numFails );
      }

};

#endif
