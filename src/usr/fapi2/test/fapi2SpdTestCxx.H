/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2SpdTestCxx.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
            size_t l_size = 0;
            uint8_t * l_blobData = NULL;

            FAPI_INF( "testGetSPD - Enter" );

            do
            {
                TARGETING::Target * i_pTarget = NULL;

                // Get DIMM Targets
                TargetHandleList dimmList;
                getDIMMTargets( dimmList );

                // Should get atleast one
                if( ( 0 == dimmList.size() ) ||
                    ( NULL == dimmList[0] ) )
                {
                    FAPI_INF( "testGetSPD- No DIMMs found!");
                    break;
                }

                // Work on the first DIMM target
                i_pTarget = dimmList[0];

                // convert to fapi2 target
                fapi2::Target<fapi2::TARGET_TYPE_DIMM> fapi2_Target(i_pTarget);

                // SPD interface call with NULL blob to get size data
                l_rc = fapi2::getSPD(fapi2_Target, NULL, l_size);

                // Expect to return the size or non failure
                if( !l_size || (l_rc != fapi2::FAPI2_RC_SUCCESS) )
                {
                    TS_FAIL("testGetSPD: Failed getting the size of the mem buffer");
                    break;
                }

                //  allocate the blob data of mem size length to hold data
                l_blobData = reinterpret_cast<uint8_t *>(malloc(l_size));
                memset(l_blobData,0,l_size);

                l_rc = fapi2::getSPD(fapi2_Target,l_blobData, l_size);
                if ( l_rc != fapi2::FAPI2_RC_SUCCESS )
                {
                    TS_FAIL( "testGetSPD- Failed to read data from DIMM with HUID= 0x%x",
                              TARGETING::get_huid(i_pTarget));
                    break;
                }

                uint8_t l_memModule = 0x0;
                size_t l_memSize = sizeof(uint8_t);

                auto l_errl = deviceRead(i_pTarget,
                                         (void *)&l_memModule,
                                         l_memSize,
                                         DEVICE_SPD_ADDRESS(SPD::MODULE_TYPE));

                if ( l_errl )
                {
                    TS_FAIL( "testGetSPD- Failed to deviceRead with HUID= 0x%x",
                              TARGETING::get_huid(i_pTarget));
                    break;
                }

                uint8_t l_memGen = 0x0;
                l_errl = deviceRead(i_pTarget,
                                         (void *)&l_memGen,
                                         l_memSize,
                                         DEVICE_SPD_ADDRESS(SPD::BASIC_MEMORY_TYPE));

                if ( l_errl )
                {
                    TS_FAIL( "testGetSPD- Failed to deviceRead with HUID= 0x%x",
                              TARGETING::get_huid(i_pTarget));
                    break;
                }

                auto l_chipModel = i_pTarget->getAttr<TARGETING::ATTR_MODEL>();

                if( l_chipModel == TARGETING::MODEL_AXONE )
                {
                    // Assumes Axone is strictly DDR4, so not taking into
                    // account DDR3 or any other DRAM generation
                    if( l_memModule == SPD::MEM_DDIMM )
                    {
                        if ( l_size != SPD::DDIMM_DDR4_SPD_SIZE )
                        {
                            TS_FAIL( "testGetSPD- expected size %d != actual size %d with HUID= 0x%x",
                                     SPD::DDIMM_DDR4_SPD_SIZE,
                                     l_size,
                                     TARGETING::get_huid(i_pTarget));
                            break;
                        }
                    }
                    else
                    {
                        if ( l_size != SPD::DDR4_SPD_SIZE )
                        {
                            TS_FAIL( "testGetSPD- expected size %d != actual size %d with HUID= 0x%x",
                                     SPD::DDR4_SPD_SIZE,
                                     l_size,
                                     TARGETING::get_huid(i_pTarget));
                            break;
                        }
                    }
                }
                else if ( l_chipModel == TARGETING::MODEL_NIMBUS )
                {
                    // Nimbus only suppported DDR4 and SPD size was
                    // DIMM BASE_MODULE_TYPE agnostic.
                    if ( l_size != SPD::DDR4_SPD_SIZE )
                    {
                            TS_FAIL( "testGetSPD- expected size %d != actual size %d with HUID= 0x%x",
                                     SPD::DDR4_SPD_SIZE,
                                     l_size,
                                     TARGETING::get_huid(i_pTarget));
                            break;
                    }
                }
                else if( l_chipModel == TARGETING::MODEL_CUMULUS )
                {
                    // BASE_MODULE_TYPE (RDIMM, LRDIMM, etc) isn't being
                    // taken into account because the SPD size isn't dependent
                    // on it for Cumulus.
                    if( l_memGen == SPD::MEM_DDR4 )
                    {
                        if ( l_size != SPD::DDR4_SPD_SIZE )
                        {
                                TS_FAIL( "testGetSPD- expected size %d != actual size %d with HUID= 0x%x",
                                         SPD::DDR4_SPD_SIZE,
                                         l_size,
                                         TARGETING::get_huid(i_pTarget));
                                break;
                        }
                    }
                    else
                    {
                        if ( l_size != SPD::DDR3_SPD_SIZE )
                        {
                                TS_FAIL( "testGetSPD- expected size %d != actual size %d with HUID= 0x%x",
                                         SPD::DDR3_SPD_SIZE,
                                         l_size,
                                         TARGETING::get_huid(i_pTarget));
                                break;
                        }
                    }
                }

                FAPI_DBG("getSPD: SPD data for DIMM with HUID=0x%.8X Size %d Blob %d",
                          TARGETING::get_huid(i_pTarget),
                          l_size,
                          l_blobData);

            } while(0);

            if( NULL != l_blobData )
            {
                free( l_blobData );
                l_blobData = NULL;
            }

            FAPI_INF( "testGetSPD - Exit" );
        }

};

#endif
