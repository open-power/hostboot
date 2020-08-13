/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_BadDqBitmap.H $               */
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

#ifndef __TEST_PRDFBADDQBITMAP_H
#define __TEST_PRDFBADDQBITMAP_H

/**
 *  @file prdfTest_BadDqBitmap.H
 *
 *  @brief prdf testing reading and writing the BAD_DQ_BITMAP attribute
 */

#ifdef __HOSTBOOT_MODULE
  #include <cxxtest/TestSuite.H>
  #include <errl/errlentry.H>
  #include <errl/errlmanager.H>
#else
  #include <cxxtest/TestSuite.h>
  #include <fsp/FipsGlobalFixture.H>
  #include <errlentry.H>
#endif

#include <prdfTrace.H>
#include <prdfMain.H>
#include "prdfsimMacros.H"
#include <prdfMemDqBitmap.H>
#include <prdfPlatServices.H>
#include <prdfTargetServices.H>
#include <targeting/common/utilFilter.H>

class WriteBadDqBitmap: public CxxTest::TestSuite
{

public:

    void TestP10ReadWriteBadDqBitmap(void)
    {
        using namespace PRDF;
        using namespace TARGETING;
        using namespace PlatServices;

        TargetHandle_t masterProc = nullptr;
        targetService().masterProcChipTargetHandle(masterProc);

        if ( MODEL_POWER10 == masterProc->getAttr<ATTR_MODEL>() )
        {
            TS_INFO("- TestP10ReadWriteBadDqBitmap - Start -");

            uint32_t rc = SUCCESS;

            // Get an OCMB
            TargetHandleList ocmbList;
            getAllChips( ocmbList, TYPE_OCMB_CHIP );
            if ( ocmbList.empty() )
            {
                TS_FAIL( "ERROR: Failed to get OCMB" );
            }
            TargetHandle_t ocmb = ocmbList[0];

            // Make arbitrary initial data
            MemRank rank( 0 );
            const uint8_t initialBitmap[DQ_BITMAP::BITMAP_SIZE] =
                { 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab };
            BitmapData initialData;
            memcpy( initialData[0].bitmap, initialBitmap,
                    sizeof(initialData[0].bitmap) );

            // Set with the initial data
            MemDqBitmap setBitmap( ocmb, rank, initialData );
            rc = setBadDqBitmap( ocmb, rank, setBitmap );
            if ( SUCCESS != rc )
            {
                TS_FAIL( "ERROR: setBadDqBitmap failed " );
            }

            // Read the data back
            MemDqBitmap getBitmap;
            rc = getBadDqBitmap( ocmb, rank, getBitmap );
            if ( SUCCESS != rc )
            {
                TS_FAIL( "ERROR: getBadDqBitmap failed" );
            }

            BitmapData newData = getBitmap.getData();

            const uint8_t SPARE_BYTE = 5;

            // Compare the read data to the initial data. The last byte (byte 9)
            // is for spares so we won't worry about comparing that.
            for ( uint8_t n = 0; n < (DQ_BITMAP::BITMAP_SIZE); n++ )
            {
                if ( SPARE_BYTE == n )
                {
                    if ( newData.at(0).bitmap[n] != 0xff )
                    {
                        TS_FAIL( "TestAxoneReadWriteBadDqBitmap: Spare Byte "
                                 "incorrectly set. newData[%d]=0x%x expected "
                                 "0xff", n, newData.at(0).bitmap[n] );
                    }
                }
                else if ( newData.at(0).bitmap[n] != initialBitmap[n] )
                {
                    TS_FAIL( "TestP10ReadWriteBadDqBitmap: Incorrect data "
                             "found. newData[%d]=0x%x initialBitmap[%d]=0x%x",
                             n, newData.at(0).bitmap[n], n, initialBitmap[n] );
                }
            }

            // Clear the vpd just in case
            rc = clearBadDqBitmap( ocmb, rank );
            if ( SUCCESS != rc )
            {
                TS_FAIL( "ERROR: clearBadDqBitmap failed" );
            }

            TS_INFO("- TestP10ReadWriteBadDqBitmap - End -");

        }

    }

//------------------------------------------------------------------------------

};
#endif
