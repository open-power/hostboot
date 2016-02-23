/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_WriteHomerFir.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#ifndef __TEST_PRDFWRITEHOMERFIR_H
#define __TEST_PRDFWRITEHOMERFIR_H

/**
 *  @file prdfTest_WriteHomerFir.H
 *
 *  @brief prdf testing writeHomerFirData()
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
#include <homerData_common.h>
#include <prdfWriteHomerFirData.H>
#include <prdfParserEnums.H>

namespace PRDF
{
// these functions from prdfWriteHomerFirData.C are needed for the
// fakeWriteHomerFirData() function
errlHndl_t getHwConfig( HOMER_Data_t & o_data, const HwInitialized_t i_curHw );
errlHndl_t writeData( uint8_t * i_hBuf, size_t i_hBufSize,
                      const HwInitialized_t i_curHw, HOMER_Data_t & o_data );
};

class WriteHomerFir: public CxxTest::TestSuite
{
private:

    //faked getPnorInfo() function to accommodate unsupported getSectioninfo()
    void fakeGetPnorInfo( HOMER_Data_t & o_data )
    {
        o_data.pnorInfo.pnorOffset     = 0;
        o_data.pnorInfo.pnorSize       = 0;
        o_data.pnorInfo.mmioOffset     = 0;
        o_data.pnorInfo.norWorkarounds = 0;
    }

//------------------------------------------------------------------------------

    // faked writeHomerFirData() function since getSectionInfo() in
    // getPnorInfo() is unsupported during CxxTest cases
    errlHndl_t fakeWriteHomerFirData( uint8_t * i_hBuf, size_t i_hBufSize,
                                      const PRDF::HwInitialized_t i_curHw )
    {
        using namespace PRDF;

        errlHndl_t errl = NULL;

        do
        {
            HOMER_Data_t data = HOMER_getData(); // Initializes data

            // Get the PNOR information, faked function
            fakeGetPnorInfo( data );

            // Get the hardware configuration
            errl = getHwConfig( data, i_curHw );
            if ( NULL != errl )
            {
                TS_FAIL("getHwConfig() failed");
                break;
            }

            // Write the HOMER data
            errl = writeData( i_hBuf, i_hBufSize, i_curHw, data );
            if ( NULL != errl )
            {
                TS_FAIL("writeData() failed");
                break;
            }

        } while (0);

        if ( NULL != errl )
        {
            errl->collectTrace( PRDF_COMP_NAME, 512 );
        }

        return errl;
    }

//------------------------------------------------------------------------------

    // check if data exists in HOMER when it should not
    void checkHomerData(HOMER_Data_t d, const PRDF::HwInitialized_t i_curHw)
    {
        using namespace PRDF;

        if (MASTER_PROC_CORE == i_curHw || ALL_PROC_MASTER_CORE == i_curHw)
        {
            // check if mcs, membuf, or mba data is available
            for (uint32_t i = 0; i < PRDF::MAX_PROC_PER_NODE; i++)
            {
                // mcs
                if (d.mcsMasks[i] != 0)
                {
                    TS_FAIL("ERROR: MCS should not be available. "
                            "(MCS: 0x%02x)", d.mcsMasks[i]);
                    break;
                }

                // membuf
                if (d.membMasks[i] != 0)
                {
                    TS_FAIL("ERROR: MEMBUF should not be available. "
                            "(MEMBUF: 0x%02x)", d.membMasks[i]);
                    break;
                }

                // mba
                if (d.mbaMasks[i] != 0)
                {
                    TS_FAIL("ERROR: MBA should not be available. "
                            "(MBA: 0x%02x)", d.mbaMasks[i]);
                    break;
                }
            }
        }
    }

//------------------------------------------------------------------------------

public:

    uint8_t hBuf[3072];

    // called at the beginning of each test
    void setUp()
    {
        memset(hBuf, 0x00, sizeof(hBuf));
    }

//------------------------------------------------------------------------------

    // test when the master processor and core are the configured hw
    void TestWriteHomerMasterProcCore(void)
    {
        using namespace PRDF;

        TS_TRACE("- Write Homer Test 1 - Master Proc Core - Start -");

        errlHndl_t errl = fakeWriteHomerFirData(hBuf, sizeof(hBuf),
                                                MASTER_PROC_CORE);
        if (NULL != errl)
        {
            TS_FAIL("ERROR: writeHomerFirData failed.");
        }

        HOMER_Data_t * d = reinterpret_cast<HOMER_Data_t *>(hBuf);
        checkHomerData(*d, MASTER_PROC_CORE);

        TS_TRACE("- Write Homer Test 1 - Master Proc Core - End-");
    }

//------------------------------------------------------------------------------

    // test when all processors and the master core are the configured hw
    void TestWriteHomerAllProcMasterCore(void)
    {
        using namespace PRDF;

        TS_TRACE("- Write Homer Test 2 - All Proc Master Core - Start -");

        errlHndl_t errl = fakeWriteHomerFirData(hBuf, sizeof(hBuf),
                                                ALL_PROC_MASTER_CORE);
        if (NULL != errl)
        {
            TS_FAIL("ERROR: writeHomerFirData failed.");
        }

        HOMER_Data_t * d = reinterpret_cast<HOMER_Data_t *>(hBuf);
        checkHomerData(*d, ALL_PROC_MASTER_CORE);

        TS_TRACE("- Write Homer Test 2 - All Proc Master Core - End-");

    }

//------------------------------------------------------------------------------

    // test when all processors, all memory, master core are the configured hw
    void TestWriteHomerAllProcMemMasterCore(void)
    {
        using namespace PRDF;

        TS_TRACE("- Write Homer Test 3 - All Proc Mem Master Core - Start -");

        errlHndl_t errl = fakeWriteHomerFirData(hBuf, sizeof(hBuf),
                                                ALL_PROC_MEM_MASTER_CORE);
        if (NULL != errl)
        {
            TS_FAIL("ERROR: writeHomerFirData failed.");
        }

        HOMER_Data_t * d = reinterpret_cast<HOMER_Data_t *>(hBuf);
        checkHomerData(*d, ALL_PROC_MEM_MASTER_CORE);

        TS_TRACE("- Write Homer Test 3 - All Proc Mem Master Core - End-");

    }

//------------------------------------------------------------------------------

    // test when all hardware is configured
    void TestWriteHomerAllHardware(void)
    {
        using namespace PRDF;

        TS_TRACE("- Write Homer Test 4 - All Hardware - Start -");

        errlHndl_t errl = fakeWriteHomerFirData(hBuf, sizeof(hBuf),
                                                ALL_HARDWARE);
        if (NULL != errl)
        {
            TS_FAIL("ERROR: writeHomerFirData failed.");
        }

        HOMER_Data_t * d = reinterpret_cast<HOMER_Data_t *>(hBuf);
        checkHomerData(*d, ALL_HARDWARE);

        TS_TRACE("- Write Homer Test 4 - All Hardware - End-");

    }

//------------------------------------------------------------------------------

};
#endif
