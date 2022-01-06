/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2SpdTestCxx.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
#ifndef __SPDTEST_H
#define __SPDTEST_H

/**
 *  @file spdtest.H
 *
 *  @brief Test cases for SPD code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <fapi2_spd_access.H>
#include <vpd/spdenums.H>
#include <vpd/spd.H>

using namespace TARGETING;

void getDIMMTargets ( TargetHandleList & o_dimmList )
{
    // Get Dimm list.
    getAllLogicalCards( o_dimmList,
                        TARGETING::TYPE_DIMM );
    return;
}

class SPDTest: public CxxTest::TestSuite
{
    public:

      /**
       * @brief Test SPD get Interface DIMMs.
       */
      void testGetSPD ( void )
      {
          fapi2::ReturnCode l_rc;
          size_t l_spdSize = 0;
          uint8_t * l_blobData = NULL;

          FAPI_INF( "testGetSPD - Enter" );

          // Get DIMM Targets
          TargetHandleList dimmList;
          getDIMMTargets( dimmList );

          // Should get atleast one
          if( ( 0 == dimmList.size() ) ||
              ( NULL == dimmList[0] ) )
          {
              TS_FAIL( "testGetSPD- No DIMMs found!");
          }

          for( auto l_tDimm : dimmList )
          {

              // convert to fapi2 target
              fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_fDimm(l_tDimm);

              // SPD interface call with NULL blob to get size data
              l_rc = fapi2::getSPD(l_fDimm, NULL, l_spdSize);

              // Expect to return the size or non failure
              if( !l_spdSize || (l_rc != fapi2::FAPI2_RC_SUCCESS) )
              {
                  FAPI_ERR("fapi2::getSPD(l_fDim, NULL, l_spdSize) returned %d",
                           l_rc);

                  auto errl = fapi2::rcToErrl(l_rc);
                  errlCommit(errl, CXXTEST_COMP_ID);
                  TS_FAIL("testGetSPD: Failed getting the size of the mem buffer - Dimm %.8X", TARGETING::get_huid(l_tDimm));
                  continue;
              }

              //  allocate the blob data of mem size length to hold data
              l_blobData = reinterpret_cast<uint8_t *>(malloc(l_spdSize));
              memset(l_blobData,0,l_spdSize);

              l_rc = fapi2::getSPD(l_fDimm,l_blobData, l_spdSize);
              if ( l_rc != fapi2::FAPI2_RC_SUCCESS )
              {
                  FAPI_ERR("fapi2::getSPD(l_fDim, l_blobData, l_spdSize) returned %d",
                           l_rc);

                  auto errl = fapi2::rcToErrl(l_rc);
                  errlCommit(errl, CXXTEST_COMP_ID);
                  TS_FAIL( "testGetSPD- Failed to read data from DIMM with HUID= 0x%x",
                           TARGETING::get_huid(l_tDimm));
                  continue;
              }

              uint8_t l_memModule = 0x0;
              size_t l_memSize = sizeof(uint8_t);

              auto l_errl = deviceRead(l_tDimm,
                                       (void *)&l_memModule,
                                       l_memSize,
                                       DEVICE_SPD_ADDRESS(SPD::MODULE_TYPE));

              if ( l_errl )
              {
                  TS_FAIL( "testGetSPD- Failed to deviceRead with HUID= 0x%x",
                           TARGETING::get_huid(l_tDimm));
                  continue;
              }

              uint8_t l_memGen = 0x0;
              l_errl = deviceRead(l_tDimm,
                                  (void *)&l_memGen,
                                  l_memSize,
                                  DEVICE_SPD_ADDRESS(SPD::BASIC_MEMORY_TYPE));

              if ( l_errl )
              {
                  TS_FAIL( "testGetSPD- Failed to deviceRead with HUID= 0x%x",
                           TARGETING::get_huid(l_tDimm));
                  continue;
              }

              // figure out the expected size based on the memory type
              size_t l_compareSize = 0;
              if( (l_memModule == SPD::MOD_TYPE_DDIMM) && (l_memGen == SPD::MEM_DDR4) )
              {
                  l_compareSize = SPD::OCMB_SPD_EFD_COMBINED_SIZE;
              }
              else if( (l_memModule != SPD::MOD_TYPE_DDIMM) && (l_memGen == SPD::MEM_DDR4) )
              {
                  l_compareSize = SPD::DDR4_SPD_SIZE;
              }
              else
              {
                  TS_FAIL( "testGetSPD - Unknown memory type for %.8X : module=0x%X, gen=0x%X",
                           TARGETING::get_huid(l_tDimm), l_memModule, l_memGen );
                  continue;
              }

              if( l_compareSize != l_spdSize )
              {
                  TS_FAIL( "testGetSPD - Wrong SPD size for %.8X : module=0x%X, gen=0x%X, exp=%d, act=%d",
                           TARGETING::get_huid(l_tDimm), l_memModule, l_memGen,
                           l_compareSize, l_spdSize);
                  continue;
              }

              FAPI_DBG("getSPD: SPD data for DIMM with HUID=0x%.8X Size %d Blob %d",
                       TARGETING::get_huid(l_tDimm),
                       l_spdSize,
                       l_blobData);
          }

          if( NULL != l_blobData )
          {
              free( l_blobData );
              l_blobData = NULL;
          }

          FAPI_INF( "testGetSPD - Exit" );
      }

};

#endif
