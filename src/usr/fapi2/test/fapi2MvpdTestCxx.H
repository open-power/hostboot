/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2MvpdTestCxx.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef __MVPDTEST_H__
#define __MVPDTEST_H__

/**
 *  @file MvpdTestCxx.H
 *
 *  @brief Test case for MVPD code
 */

#include <stdio.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <vpd/mvpdenums.H>
#include <mvpd_access.H>
#include <mvpd_access_defs.H>
#include "../plat_mvpd_access.C"
#include <fapi2.H>
#include <devicefw/userif.H>
#include <p9_pm_get_poundv_bucket.H>
#include <utilFilter.H>
#include <vpd/mvpdenums.H>

using   namespace   TARGETING;

class MVPDTest: public CxxTest::TestSuite
{
public:

  /**
    * @brief Test basic 1x1 FAPI2 and HB record mapping check
    *
    */
  void testMvpdRecordCheck (void)
  {
      MVPD::mvpdRecord l_hbRecord =  MVPD::MVPD_INVALID_RECORD;
      uint8_t l_fapi_check=0xFF;
      fapi2::ReturnCode l_rc;

      FAPI_INF("testMvpdRecordCheck: ENTER");

      // TBD : The fapi2 records enum comes from EKB. Latter add the
      // end of list value to enumeration. For now MVPD_RECORD_MER0
      // is the last entry.
      for ( size_t l_fapi2Index = MvpdRecord::MVPD_RECORD_FIRST;
            l_fapi2Index < MvpdRecord::MVPD_RECORD_LAST; ++l_fapi2Index)
      {
          // Translate the FAPI record to a Hostboot record.
          // This returns the MVPD record and the corresponding
          // fapi2 record index of it.
          // Ex Table: {MVPD::CRP0, fapi2::MVPD_RECORD_CRP0},
          l_rc = fapi2::MvpdRecordXlate((fapi2::MvpdRecord)l_fapi2Index,
                  l_hbRecord,
                  l_fapi_check);

          FAPI_INF("testMvpdRecordCheck() - FAPI2 Record: "
                  "0x%04x, - [ HB Record: 0x%04x, Index: 0x%04x ]",
                  l_fapi2Index,
                  l_hbRecord,
                  l_fapi_check);


          if ( l_rc )
          {
              errlHndl_t l_errl = fapi2::rcToErrl(l_rc);
              if(l_errl->reasonCode() != fapi2::RC_INVALID_RECORD)
              {
                  TS_FAIL("testMvpdRecordCheck: Exceeded max index while searching for record MVPDRecord::0x%x", l_fapi2Index);
              }
          }

          if( l_fapi2Index != l_fapi_check )
          {
              TS_FAIL("testMvpdRecordCheck:Record enumeration order changed, Actual = 0x%x    Expected = 0x%x", l_fapi2Index, l_fapi_check );
          }

      }

      FAPI_INF("testMvpdRecordCheck: EXIT !!");

  } // testMvpdRecordCheck

  /**
    * @brief Test basic 1x1 FAPI2 and HB keyword mapping check
    *
    */
  void testMvpdKeywordCheck (void)
  {
      MVPD::mvpdKeyword l_hbKeyword = MVPD::INVALID_MVPD_KEYWORD;
      uint8_t l_fapi_check=0xFF;
      fapi2::ReturnCode l_rc;

      FAPI_INF("testMvpdKeywordCheck: ENTER ");
      for ( size_t l_fapi2Index = MvpdRecord::MVPD_RECORD_FIRST;
            l_fapi2Index < MvpdRecord::MVPD_RECORD_LAST; ++l_fapi2Index)
      {
          // Translate the FAPI record to a Hostboot record.
          // This returns the MVPD record and the corresponding
          // fapi2 keyword index of it.
          l_rc = fapi2::MvpdKeywordXlate((fapi2::MvpdKeyword)l_fapi2Index,
                  l_hbKeyword,
                  l_fapi_check);

          FAPI_INF("testMvpdKeywordCheck() - FAPI2 Keyword: "
                  "0x%04x, - [ HB Keyword: 0x%04x, Index: 0x%04x ]",
                  l_fapi2Index,
                  l_hbKeyword,
                  l_fapi_check);

          if ( l_rc )
          {
              errlHndl_t l_errl = fapi2::rcToErrl(l_rc);
              if(l_errl->reasonCode() != fapi2::RC_INVALID_KEYWORD)
              {
                  TS_FAIL("testMvpdKeywordCheck: Exceeded max index while searching for MVPDKeyword::0x%x", l_fapi2Index);
              }
          }

          if( l_fapi2Index != l_fapi_check )
          {
              TS_FAIL("testMvpdKeywordCheck:Keyword enumeration order changed, Actual = 0x%x    Expected = 0x%x", l_fapi2Index, l_fapi_check );
          }

      }

      FAPI_INF("testMvpdKeywordCheck: EXIT !!");

  } // testMvpdKeywordCheck

  /**
    * @brief Test to Read using MVPD HB interface and verify
    *
    */
  void testMvpdValidate (void)
  {
      errlHndl_t l_errl = NULL;
      fapi2::ReturnCode   l_rc;
      uint8_t             *l_fieldData = NULL;
      uint32_t            l_fieldBuffer = 0;
      uint32_t            testPassCount = 0;

      FAPI_INF("testMvpdValidate: ENTER ");

      // list of MVPD records to test
      struct testMVPDRecords {
          MvpdRecord record;
          MvpdKeyword keyword;
      };

      // Build the record, let it test both successful and failure
      // use cases.
      struct testMVPDRecords l_mvpdRecords[] = {
          // Records to use
          { MVPD_RECORD_CRP0, MVPD_KEYWORD_VD},
          { MVPD_RECORD_CP00, MVPD_KEYWORD_ED},
          { MVPD_RECORD_VINI, MVPD_KEYWORD_TE},
          { MVPD_RECORD_LRP0, MVPD_KEYWORD_DD},
          { MVPD_RECORD_LRP1, MVPD_KEYWORD_DN},
          { MVPD_RECORD_LRP2, MVPD_KEYWORD_PG},
          { MVPD_RECORD_LRP3, MVPD_KEYWORD_PK},
          { MVPD_RECORD_LRP4, MVPD_KEYWORD_PDR},
          { MVPD_RECORD_LRP5, MVPD_KEYWORD_PDV},
          { MVPD_RECORD_LWP0, MVPD_KEYWORD_PN},
          { MVPD_RECORD_LWP1, MVPD_KEYWORD_SN},
          { MVPD_RECORD_LWP2, MVPD_KEYWORD_PR},
          { MVPD_RECORD_LWP3, MVPD_KEYWORD_HE},
          { MVPD_RECORD_LWP4, MVPD_KEYWORD_CT},
          { MVPD_RECORD_LWP5, MVPD_KEYWORD_HW},
      };

      TARGETING::TargetHandleList l_chipList;

      // Get a list of all of the proc chips
      TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

      // Loop through the record
      FAPI_INF( "testMvpdValidate l_chipList.size()= 0x%x ",
              l_chipList.size() );

      // loop thru all the cpu's
      for (TargetHandleList::iterator l_cpu_iter = l_chipList.begin();
              l_cpu_iter != l_chipList.end();
              ++l_cpu_iter)
      {
          // Local place holder for CPU target
          TARGETING::Target* l_cpu_target = *l_cpu_iter;

          FAPI_INF("target HUID %.8X", TARGETING::get_huid(l_cpu_target));

          // Call the interface
          // loop through mvpd records prepared
          const uint32_t numRecords =
              sizeof(l_mvpdRecords)/sizeof(l_mvpdRecords[0]);
          for (uint8_t i=0;i<numRecords;i++) {

              FAPI_INF( "record = 0x%x keyword = 0x%x",
                      l_mvpdRecords[i].record,
                      l_mvpdRecords[i].keyword);

              //  call getMvpdField once with a NULL pointer to get the
              //  buffer size should return the size
              l_rc = getMvpdField(l_mvpdRecords[i].record,
                      l_mvpdRecords[i].keyword,
                      l_cpu_target,
                      NULL,
                      l_fieldBuffer );
              if ( l_rc != fapi2::FAPI2_RC_SUCCESS )
              {
                  FAPI_ERR("getMvpdField:  Failed getting Record buffer size");
                  continue;
              }

              FAPI_INF( "getMvpdField: size of record = 0x%x",
                      l_fieldBuffer );

              // Validate the Records
                l_fieldData = reinterpret_cast<uint8_t *>
                              (malloc(l_fieldBuffer) );

              //  call getMvpdField once with a valid buffer
              l_rc = getMvpdField(l_mvpdRecords[i].record,
                      l_mvpdRecords[i].keyword,
                      l_cpu_target,
                      l_fieldData,
                      l_fieldBuffer );
              if ( l_rc != fapi2::FAPI2_RC_SUCCESS )
              {
                  FAPI_ERR( "getMvpdField:  Error Getting the Record" );
                  free(  l_fieldData );
                  continue;
              }

              //*** Validate using Device Read **
              // The size length is already fetched in above using the
              // interface. Use the Buffer length and fetch the data
              // via device read.
              size_t l_fieldLen = l_fieldBuffer;
              uint8_t* l_devData = NULL;
              l_devData = reinterpret_cast<uint8_t *>
                          (malloc(l_fieldBuffer));

              l_errl = deviceRead(
                              l_cpu_target,
                              l_devData,
                              l_fieldLen,
                              DEVICE_MVPD_ADDRESS(l_mvpdRecords[i].record,
                                                  l_mvpdRecords[i].keyword
                                                  )
                              );
              if (l_errl)
              {
                  FAPI_ERR("deviceRead: ERROR: errorlog PLID=0x%x",
                          l_errl->plid());
                  FAPI_INF( "deviceRead:  Error Getting the Record" );
                  free( l_devData );
                  continue;
              }

              // Interface vs device read fetched record data
              if ( !memcmp(l_fieldData,l_devData,sizeof(l_fieldBuffer)))
              {
                  FAPI_INF( "getMvpdField: Record fetch success:PASSED" );
                  testPassCount++;
              }
              else
              {
                  FAPI_INF( "getMvpdField:  Record fetch are different" );
                  FAPI_ERR( "Error: Fetch record = 0x%x :"
                              "device read record = 0x%x",
                              l_fieldData,l_devData );
              }

              // clean up memory if we are here
              free( l_fieldData );
              free( l_devData );

          }// Loop through the records

      } // Loop target list

      // Allowing to run through the table both valid and invalid entries
      // so that it test both the successful and failure use cases.
      if (testPassCount)
      {
          FAPI_INF(" testMvpdValidate : Test Passed = %d",testPassCount);
      }
      else
      {
          TS_FAIL(" testMvpdValidate : All Tests FAILED");
      }

      FAPI_INF("testMvpdValidate: EXIT !!");

  } //testMvpdValidate

  void testMvpdGetPoundVBucket(void)
  {
      int numTests = 0;
      int numFails = 0;
      fapi2::ReturnCode   l_rc;
      FAPI_INF("MvpdGetPoundVBucket Test entry... ");

      // Create a vector of TARGETING::Target pointers
      TARGETING::TargetHandleList l_chipletList;

      // Get a list of all of the EQ chips
      TARGETING::getChipletResources(l_chipletList,
                                    TARGETING::TYPE_EQ,
                                    TARGETING::UTIL_FILTER_PRESENT);
      fapi2::voltageBucketData_t voltageData;

      for(const auto & eqChiplet : l_chipletList )
      {
          fapi2::Target<TARGET_TYPE_EQ>
          l_fapi_eq_target(eqChiplet);
          l_rc = p9_pm_get_poundv_bucket(l_fapi_eq_target, voltageData);


          //Set up a char array to hold the bucket data from an attr read
          fapi2::ATTR_POUNDV_BUCKET_DATA_Type l_bucketAttr;

          //Perform an ATTR_GET for POUNDV_BUCKET data on the EQ target
          FAPI_ATTR_GET(fapi2::ATTR_POUNDV_BUCKET_DATA,
                                l_fapi_eq_target,
                                l_bucketAttr);

          uint32_t l_huid = TARGETING::get_huid(l_fapi_eq_target);
          uint32_t l_pos = eqChiplet->getAttr<TARGETING::ATTR_CHIP_UNIT>();

          //PROC0EQ1 has an override set in nimbus's standalone xml, this branch checks it
          if(l_pos == 1)
          {

              numTests++;
              if(voltageData.bucketId != 2)
              {
                  numFails++;
                  TS_FAIL("Error:p9_pm_get_poundv_bucket with EQ with HUID = 0x%X should have returned bucket ID 2, not %d",l_huid, voltageData.bucketId);
              }

              numTests++;
              if(*l_bucketAttr != 2)
              {
                  numFails++;
                  TS_FAIL("Error:FAPI_ATTR_GET(fapi2::ATTR_POUNDV_BUCKET_DATA EQ with HUID = 0x%X should have bucket ID 1, not %d",l_huid, voltageData.bucketId);
              }

              if(l_rc)
              {
                  numFails++;
                  TS_FAIL("Error: Error occured while trying to read voltage data from mvpd");
                  continue;
              }
              continue;
          }
          numTests++;
          if(voltageData.bucketId != 1)
          {
              numFails++;
              TS_FAIL("Error:p9_pm_get_poundv_bucket with EQ with HUID = 0x%X should have returned bucket ID 1, not %d",l_huid, voltageData.bucketId);
              continue;
          }
          numTests++;
          if(*l_bucketAttr != 1)
          {
              numFails++;
              TS_FAIL("Error:FAPI_ATTR_GET(fapi2::ATTR_POUNDV_BUCKET_DATA EQ with HUID = 0x%X should have bucket ID 1, not %d",l_huid, voltageData.bucketId);
          }

          if(l_rc)
          {
              numFails++;
              TS_FAIL("Error: Error occured while trying to read voltage data from mvpd");
              continue;
          }
          FAPI_INF("Bucket for HUID: 0x%X is = %d", l_huid, voltageData.bucketId);
      }

      FAPI_INF("MvpdGetPoundVBucket:: Test Complete. %d/%d fails",  numFails , numTests);
      FAPI_INF("MvpdGetPoundVBucket Test exit... ");
  }
};

#endif
