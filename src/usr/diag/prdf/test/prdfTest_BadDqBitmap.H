/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_BadDqBitmap.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
            TargetHandle_t memport = getConnectedChild(ocmb, TYPE_MEM_PORT, 0);

            // Make arbitrary initial data
            MemRank rank( 0 );
            const uint8_t initialBitmap[DQ_BITMAP::BITMAP_SIZE] =
                { 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab };

            // Set with the initial data
            MemDqBitmap setBitmap( memport, rank, initialBitmap );
            rc = setBadDqBitmap<TYPE_MEM_PORT>( memport, rank, setBitmap );
            if ( SUCCESS != rc )
            {
                TS_FAIL( "ERROR: setBadDqBitmap failed " );
            }

            // Read the data back
            MemDqBitmap getBitmap;
            rc = getBadDqBitmap<TYPE_MEM_PORT>( memport, rank, getBitmap );
            if ( SUCCESS != rc )
            {
                TS_FAIL( "ERROR: getBadDqBitmap failed" );
            }

            uint8_t newData[DQ_BITMAP::BITMAP_SIZE];
            memcpy(newData, getBitmap.getData(), sizeof(newData));

            const uint8_t SPARE_BYTE = 5;

            // Compare the read data to the initial data. The spare byte is not
            // compared.
            for ( uint8_t n = 0; n < (DQ_BITMAP::BITMAP_SIZE); n++ )
            {
                if ( SPARE_BYTE == n )
                {
                    if ( newData[n] != 0xff )
                    {
                        TS_FAIL( "TestP10ReadWriteBadDqBitmap: Spare Byte "
                                 "incorrectly set. newData[%d]=0x%x expected "
                                 "0xff", n, newData[n] );
                    }
                }
                else if ( newData[n] != initialBitmap[n] )
                {
                    TS_FAIL( "TestP10ReadWriteBadDqBitmap: Incorrect data "
                             "found. newData[%d]=0x%x initialBitmap[%d]=0x%x",
                             n, newData[n], n, initialBitmap[n] );
                }
            }

            // Clear the vpd just in case
            rc = clearBadDqBitmap<TYPE_MEM_PORT>( memport, rank );
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
