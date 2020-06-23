/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/test/serial/testspiserial.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef __TEST_SPI_SERIAL_H
#define __TEST_SPI_SERIAL_H

#include <cxxtest/TestSuite.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <trace/interface.H>

#include <spi/spi.H>
#include "../../spidd.H"

class SpiTestSerialSuite : public CxxTest::TestSuite
{
public:
   // run serially so the mutex iv_val can be checked
   void testSpiSerialLockProcessor() const
    {
        TS_INFO(ENTER_MRK"testSpiSerialLockProcessor");

        using namespace SPI;

        errlHndl_t errl = nullptr;

        // Grab master proc
        TARGETING::Target* masterProc = nullptr;
        uint8_t engine = 0;

        do {
          errl = TARGETING::targetService().queryMasterProcChipTargetHandle(masterProc);
          if (errl != nullptr)
          {
              TS_FAIL("testSpiSerialLockProcessor: Unable to find master processor");
              errlCommit(errl, CXXTEST_COMP_ID);
              break;
          }

          mutex_t * engine_lock = nullptr;
          bool mutexSuccess = spiGetEngineMutex(masterProc,
                                                engine,
                                                engine_lock);

          if (!mutexSuccess)
          {
              TS_FAIL("testSpiSerialLockProcessor: Unable to find mutex");
              break;
          }
          else
          {
              // test being run serially so lock should be 0
              if (engine_lock->iv_val != 0)
              {
                  TS_FAIL("testSpiSerialLockProcessor: initial lock iv_val %d found for 0x%.08X engine %d",
                    engine_lock->iv_val, TARGETING::get_huid(masterProc), engine);
                  break;
              }
          }


          // lock all engines on the master processor
          errl = spiLockProcessor(masterProc, true);
          if (errl)
          {
              TS_FAIL("testSpiSerialLockProcessor: unable to lock master processor");
              errlCommit(errl, CXXTEST_COMP_ID);
              break;
          }

          // check that the lock count increased
          if (engine_lock->iv_val != 1)
          {
              TS_FAIL("testSpiSerialLockProcessor: found lock iv_val %d for 0x%.08X engine %d",
                engine_lock->iv_val, TARGETING::get_huid(masterProc), engine);
          }
          else
          {
              TS_INFO("testSpiSerialLockProcessor: lock found (%d) for 0x%.08X engine %d",
                engine_lock->iv_val, TARGETING::get_huid(masterProc), engine);
          }

          // unlock master processor
          errl = spiLockProcessor(masterProc, false);
          if (errl)
          {
              TS_FAIL("testSpiSerialLockProcessor: unable to unlock master processor");
              errlCommit(errl, CXXTEST_COMP_ID);
              break;
          }

          // check that the lock count decreased
          if (engine_lock->iv_val != 0)
          {
              TS_FAIL("testSpiSerialLockProcessor: found unlock iv_val %d for 0x%.08X engine %d",
                engine_lock->iv_val, TARGETING::get_huid(masterProc), engine);
          }
          else
          {
              TS_INFO("testSpiSerialLockProcessor: unlock found (%d) for 0x%.08X engine %d",
                engine_lock->iv_val, TARGETING::get_huid(masterProc), engine);
          }
        } while (0);
        TS_INFO(EXIT_MRK"testSpiSerialLockProcessor");
    }

    void testSpiSerialSetAccessModeFailure() const
    {
        using namespace SPI;
        errlHndl_t errl = nullptr;

        TS_INFO(ENTER_MRK"testSpiSerialSetAccessModeFailure");

        // Grab master proc
        TARGETING::Target* masterProc = nullptr;
        errl = TARGETING::targetService().queryMasterProcChipTargetHandle(masterProc);
        if (errl != nullptr)
        {
            TS_FAIL("testSpiSerialSetAccessModeFailure: Unable to find master processor");
            errlCommit(errl, CXXTEST_COMP_ID);
        }
        else
        {
            TS_INFO("testSpiSerialSetAccessModeFailure: set SPI access for 0x%.08X target",
                TARGETING::get_huid(masterProc));
            errl = spiSetAccessMode(masterProc, FSI_ACCESS);
            if (errl)
            {
                // Master Proc should not be allowed access via FSI2SPI
                // E>spiSetAccessMode(): An error occurred from p10_spi_init_fsi HWP call, RC=0x907
                TS_INFO("testSpiSerialSetAccessModeFailure: FSI_ACCESS not allowed on master processor");
                delete errl;
            }
            else
            {
                // FSI_ACCESS setting should fail for masterProc
                TS_FAIL("testSpiSerialSetAccessModeFailure: master proc FSI_ACCESS should not be allowed");

                // try to restore PIB_ACCESS for so future tests pass
                errl = spiSetAccessMode(masterProc, PIB_ACCESS);
                if (errl)
                {
                    TS_FAIL("testSpiSerialSetAccessModeFailure: master proc PIB_ACCESS failed");
                    errlCommit(errl, CXXTEST_COMP_ID);
                }
            }

            // Check attr switches for PIB_ACCESS settings
            auto spiSwitch = masterProc->getAttr<TARGETING::ATTR_SPI_SWITCHES>();
            if (!spiSwitch.usePibSPI)
            {
                TS_FAIL("testSpiSerialSetAccessModeFailure: ATTR_SPI_SWITCHES should still have PIB_ACCESS");
            }

            auto scomSwitch = masterProc->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
            if (scomSwitch.useSpiFsiScom)
            {
                TS_FAIL("testSpiSerialSetAccessModeFailure: ATTR_SCOM_SWITCHES should not have SPI FSI ACCESS");
            }
        }

        TS_INFO(EXIT_MRK"testSpiSerialSetAccessModeFailure");
    }

    // run serially to prevent another test from using SPI in wrong mode
    void testSpiSerialSetAccessMode() const
    {
        using namespace SPI;
        errlHndl_t errl = nullptr;

        TS_INFO(ENTER_MRK"testSpiSerialSetAccessMode");

        // Grab master proc
        TARGETING::Target* masterProc = nullptr;
        errl = TARGETING::targetService().queryMasterProcChipTargetHandle(masterProc);
        if (errl != nullptr)
        {
            TS_FAIL("testSpiSerialSetAccessMode: Unable to find master processor");
            errlCommit(errl, CXXTEST_COMP_ID);
        }
        else
        {
            // Use targeting code to get a list of all processors
            TARGETING::TargetHandleList l_procChips;
            TARGETING::getAllChips( l_procChips, TARGETING::TYPE_PROC );

            for (const auto & l_procChip: l_procChips)
            {
                // master proc not allowed to switch modes
                if (l_procChip == masterProc)
                {
                    continue;
                }

                TS_INFO("testSpiSerialSetAccessMode: set SPI access for 0x%.08X target",
                    TARGETING::get_huid(l_procChip));
                errl = spiSetAccessMode(l_procChip, FSI_ACCESS);
                if (errl)
                {
                    TS_FAIL("testSpiSerialSetAccessMode: unable to set FSI_ACCESS for 0x%.08X target",
                        TARGETING::get_huid(l_procChip));
                    errlCommit(errl, CXXTEST_COMP_ID);
                }

                // NOTE: SPI operation could sneak in here if this test is run
                // in multithread mode

                // Check attr switch for FSI_ACCESS
                auto spiSwitch = l_procChip->getAttr<TARGETING::ATTR_SPI_SWITCHES>();
                if (!spiSwitch.useFsiSPI)
                {
                    TS_FAIL("testSpiSerialSetAccessMode: ATTR_SPI_SWITCHES not updated to FSI_ACCESS");
                }

                auto scomSwitch = l_procChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
                if (!scomSwitch.useSpiFsiScom)
                {
                    TS_FAIL("testSpiSerialSetAccessMode: ATTR_SCOM_SWITCHES not updated to SPI FSI_ACCESS");
                }

                errl = spiSetAccessMode(l_procChip, PIB_ACCESS);
                if (errl)
                {
                    TS_FAIL("testSpiSerialSetAccessMode: unable to set PIB_ACCESS for 0x%.08X target",
                        TARGETING::get_huid(l_procChip));
                    errlCommit(errl, CXXTEST_COMP_ID);
                }

                // Check attr switch for PIB_ACCESS
                spiSwitch = l_procChip->getAttr<TARGETING::ATTR_SPI_SWITCHES>();
                if (!spiSwitch.usePibSPI)
                {
                    TS_FAIL("testSpiSerialSetAccessMode: ATTR_SPI_SWITCHES not updated to PIB_ACCESS");
                }

                scomSwitch = l_procChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
                if (scomSwitch.useSpiFsiScom)
                {
                    TS_FAIL("testSpiSerialSetAccessMode: ATTR_SCOM_SWITCHES not clearing SPI FSI ACCESS");
                }
            } // end processor loop
        }

        TS_INFO(EXIT_MRK"testSpiSerialSetAccessMode");
    }
};


#endif
